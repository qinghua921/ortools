





















































#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "absl/container/btree_set.h"
#include "absl/flags/flag.h"
#include "absl/strings/numbers.h"
#include "absl/strings/str_split.h"
#include "absl/strings/string_view.h"
#include "ortools/base/commandlineflags.h"
#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"
#include "ortools/sat/model.h"
#include "ortools/util/filelineiter.h"

ABSL_FLAG(std::string, input, "", "Input file.");
ABSL_FLAG(std::string, params, "", "Sat parameters in text proto format.");

namespace operations_research {
namespace sat {
class ShiftMinimizationParser {
 public:
  struct Job {
    int start;
    int end;
  };

  struct Assignment {
    int worker_id;
    int job_index;
  };

  ShiftMinimizationParser()
      : load_status_(NOT_STARTED),
        declared_num_jobs_(0),
        declared_num_workers_(0),
        num_workers_read_(0) {}

  const std::vector<Job>& jobs() const { return jobs_; }
  const std::vector<std::vector<int>>& possible_jobs_per_worker() const {
    return possible_jobs_per_worker_;
  }
  const std::vector<std::vector<Assignment>>& possible_assignments_per_job()
      const {
    return possible_assignments_per_job_;
  }

  

  

  

  

  

  

  

  bool LoadFile(const std::string& file_name) {
    if (load_status_ != NOT_STARTED) {
      return false;
    }

    load_status_ = STARTED;

    for (const std::string& line :
         FileLines(file_name, FileLineIterator::REMOVE_LINEFEED |
                                  FileLineIterator::REMOVE_INLINE_CR)) {
      ProcessLine(line);
    }

    LOG(INFO) << "Read file " << file_name << " with " << declared_num_jobs_
              << " jobs, and " << declared_num_workers_ << " workers.";
    return declared_num_jobs_ != 0 && jobs_.size() == declared_num_jobs_ &&
           declared_num_workers_ != 0 &&
           declared_num_workers_ == num_workers_read_;
  }

 private:
  enum LoadStatus { NOT_STARTED, STARTED, JOBS_SEEN, WORKERS_SEEN };

  int strtoint32(absl::string_view word) {
    int result;
    CHECK(absl::SimpleAtoi(word, &result));
    return result;
  }

  void ProcessLine(const std::string& line) {
    if (line.empty() || line[0] == '#') {
      return;
    }

    const std::vector<std::string> words =
        absl::StrSplit(line, absl::ByAnyChar(" :\t"), absl::SkipEmpty());

    switch (load_status_) {
      case NOT_STARTED: {
        LOG(FATAL) << "Wrong status: NOT_STARTED";
        break;
      }
      case STARTED: {
        if (words.size() == 3 && words[0] == "Type") {
          CHECK_EQ(1, strtoint32(words[2]));
        } else if (words.size() == 3 && words[0] == "Jobs") {
          declared_num_jobs_ = strtoint32(words[2]);
          possible_assignments_per_job_.resize(declared_num_jobs_);
          load_status_ = JOBS_SEEN;
        } else {
          LOG(FATAL) << "Wrong state STARTED with line " << line;
        }
        break;
      }
      case JOBS_SEEN: {
        if (words.size() == 2) {
          jobs_.push_back({strtoint32(words[0]), strtoint32(words[1])});
        } else if (words.size() == 3 && words[0] == "Qualifications") {
          declared_num_workers_ = strtoint32(words[2]);
          possible_jobs_per_worker_.resize(declared_num_workers_);
          load_status_ = WORKERS_SEEN;
        } else {
          LOG(FATAL) << "Wrong state JOBS_SEEN with line " << line;
        }
        break;
      }
      case WORKERS_SEEN: {
        CHECK_EQ(strtoint32(words[0]), words.size() - 1);
        for (int i = 1; i < words.size(); ++i) {
          const int job = strtoint32(words[i]);
          const int pos = possible_jobs_per_worker_[num_workers_read_].size();
          possible_jobs_per_worker_[num_workers_read_].push_back(job);
          possible_assignments_per_job_[job].push_back(
              {num_workers_read_, pos});
        }
        num_workers_read_++;
        break;
      }
    }
  }

  std::vector<Job> jobs_;
  std::vector<std::vector<int>> possible_jobs_per_worker_;
  std::vector<std::vector<Assignment>> possible_assignments_per_job_;
  LoadStatus load_status_;
  int declared_num_jobs_;
  int declared_num_workers_;
  int num_workers_read_;
};

bool Overlaps(const ShiftMinimizationParser::Job& j1,
              const ShiftMinimizationParser::Job& j2) {
  

  

  return !(j1.start > j2.end || j2.start > j1.end);
}

void LoadAndSolve(const std::string& file_name) {
  ShiftMinimizationParser parser;
  CHECK(parser.LoadFile(file_name));

  CpModelBuilder cp_model;

  const int num_workers = parser.possible_jobs_per_worker().size();
  const std::vector<ShiftMinimizationParser::Job>& jobs = parser.jobs();
  const int num_jobs = jobs.size();

  std::vector<BoolVar> active_workers(num_workers);
  std::vector<std::vector<BoolVar>> worker_job_vars(num_workers);
  std::vector<std::vector<BoolVar>> possible_workers_per_job(num_jobs);

  for (int w = 0; w < num_workers; ++w) {
    

    active_workers[w] = cp_model.NewBoolVar();

    

    

    const std::vector<int>& possible = parser.possible_jobs_per_worker()[w];
    for (int p : possible) {
      const BoolVar var = cp_model.NewBoolVar();
      worker_job_vars[w].push_back(var);
      possible_workers_per_job[p].push_back(var);
    }

    

    for (int i = 0; i < possible.size() - 1; ++i) {
      for (int j = i + 1; j < possible.size(); ++j) {
        const int job1 = possible[i];
        const int job2 = possible[j];
        if (Overlaps(jobs[job1], jobs[job2])) {
          const BoolVar v1 = worker_job_vars[w][i];
          const BoolVar v2 = worker_job_vars[w][j];
          cp_model.AddBoolOr({~v1, ~v2});
        }
      }
    }

    

    cp_model.AddBoolOr(worker_job_vars[w]).OnlyEnforceIf(active_workers[w]);
    for (const BoolVar& var : worker_job_vars[w]) {
      cp_model.AddImplication(var, active_workers[w]);
    }
  }

  

  for (int j = 0; j < num_jobs; ++j) {
    

    

    

    cp_model.AddBoolOr(possible_workers_per_job[j]);
  }

  

  

  

  

  absl::btree_set<int> time_points;
  absl::btree_set<std::vector<int>> visited_job_lists;

  for (int j = 0; j < num_jobs; ++j) {
    time_points.insert(parser.jobs()[j].start);
    time_points.insert(parser.jobs()[j].end);
  }

  int num_count_constraints = 0;
  int max_intersection_size = 0;

  

  for (int t : time_points) {
    

    std::vector<int> intersecting_jobs;
    for (int j = 0; j < num_jobs; ++j) {
      const ShiftMinimizationParser::Job& job = parser.jobs()[j];
      

      if (t >= job.start && t <= job.end) {
        intersecting_jobs.push_back(j);
      }
    }

    

    if (visited_job_lists.contains(intersecting_jobs)) continue;
    visited_job_lists.insert(intersecting_jobs);

    

    std::vector<BoolVar> overlapping_worker_jobs;
    for (int j : intersecting_jobs) {
      for (const auto& p : parser.possible_assignments_per_job()[j]) {
        const BoolVar var = worker_job_vars[p.worker_id][p.job_index];
        overlapping_worker_jobs.push_back(var);
      }
    }

    

    const int num_jobs = intersecting_jobs.size();
    cp_model.AddEquality(LinearExpr::Sum(overlapping_worker_jobs), num_jobs);
    

    max_intersection_size = std::max(max_intersection_size, num_jobs);
    num_count_constraints++;
  }

  LOG(INFO) << "Added " << num_count_constraints
            << " count constraints while processing " << time_points.size()
            << " time points.";
  LOG(INFO) << "Lower bound = " << max_intersection_size;

  

  const IntVar objective_var =
      cp_model.NewIntVar(Domain(max_intersection_size, num_workers));
  cp_model.AddEquality(LinearExpr::Sum(active_workers), objective_var);
  cp_model.Minimize(objective_var);

  

  Model model;
  model.Add(NewSatParameters(absl::GetFlag(FLAGS_params)));

  const CpSolverResponse response = SolveCpModel(cp_model.Build(), &model);
  LOG(INFO) << CpSolverResponseStats(response);
}
}  

}  


int main(int argc, char** argv) {
  absl::SetFlag(&FLAGS_stderrthreshold, 0);
  InitGoogle(argv[0], &argc, &argv, true);

  if (absl::GetFlag(FLAGS_input).empty()) {
    LOG(FATAL) << "Please supply a data file with --input=";
  }

  operations_research::sat::LoadAndSolve(absl::GetFlag(FLAGS_input));
  return EXIT_SUCCESS;
}
