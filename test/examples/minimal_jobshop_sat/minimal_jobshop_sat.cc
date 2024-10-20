






























#include <stdlib.h>

#include <algorithm>
#include <cstdint>
#include <map>
#include <numeric>
#include <string>
#include <tuple>
#include <vector>

#include "absl/strings/str_format.h"
#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"
#include "ortools/sat/cp_model.pb.h"
#include "ortools/sat/cp_model_solver.h"



namespace operations_research {
namespace sat {

void MinimalJobshopSat() {
  

  using Task = std::tuple<int64_t, int64_t>;  

  using Job = std::vector<Task>;
  std::vector<Job> jobs_data = {
      {{0, 3}, {1, 2}, {2, 2}},  

      {{0, 2}, {2, 1}, {1, 4}},  

      {{1, 4}, {2, 3}},          

  };

  int64_t num_machines = 0;
  for (const auto& job : jobs_data) {
    for (const auto& [machine, _] : job) {
      num_machines = std::max(num_machines, 1 + machine);
    }
  }

  std::vector<int> all_machines(num_machines);
  std::iota(all_machines.begin(), all_machines.end(), 0);

  

  int64_t horizon = 0;
  for (const auto& job : jobs_data) {
    for (const auto& [_, time] : job) {
      horizon += time;
    }
  }
  


  

  

  CpModelBuilder cp_model;
  


  

  struct TaskType {
    IntVar start;
    IntVar end;
    IntervalVar interval;
  };

  using TaskID = std::tuple<int, int>;  

  std::map<TaskID, TaskType> all_tasks;
  std::map<int64_t, std::vector<IntervalVar>> machine_to_intervals;
  for (int job_id = 0; job_id < jobs_data.size(); ++job_id) {
    const auto& job = jobs_data[job_id];
    for (int task_id = 0; task_id < job.size(); ++task_id) {
      const auto [machine, duration] = job[task_id];
      std::string suffix = absl::StrFormat("_%d_%d", job_id, task_id);
      IntVar start = cp_model.NewIntVar({0, horizon})
                         .WithName(std::string("start") + suffix);
      IntVar end = cp_model.NewIntVar({0, horizon})
                       .WithName(std::string("end") + suffix);
      IntervalVar interval = cp_model.NewIntervalVar(start, duration, end)
                                 .WithName(std::string("interval") + suffix);

      TaskID key = std::make_tuple(job_id, task_id);
      all_tasks.emplace(key, TaskType{
start,
                                      
end,
                                      
interval});
      machine_to_intervals[machine].push_back(interval);
    }
  }
  


  

  

  for (const auto machine : all_machines) {
    cp_model.AddNoOverlap(machine_to_intervals[machine]);
  }

  

  for (int job_id = 0; job_id < jobs_data.size(); ++job_id) {
    const auto& job = jobs_data[job_id];
    for (int task_id = 0; task_id < job.size() - 1; ++task_id) {
      TaskID key = std::make_tuple(job_id, task_id);
      TaskID next_key = std::make_tuple(job_id, task_id + 1);
      cp_model.AddGreaterOrEqual(all_tasks[next_key].start, all_tasks[key].end);
    }
  }
  


  

  

  IntVar obj_var = cp_model.NewIntVar({0, horizon}).WithName("makespan");

  std::vector<IntVar> ends;
  for (int job_id = 0; job_id < jobs_data.size(); ++job_id) {
    const auto& job = jobs_data[job_id];
    TaskID key = std::make_tuple(job_id, job.size() - 1);
    ends.push_back(all_tasks[key].end);
  }
  cp_model.AddMaxEquality(obj_var, ends);
  cp_model.Minimize(obj_var);
  


  

  const CpSolverResponse response = Solve(cp_model.Build());
  


  

  if (response.status() == CpSolverStatus::OPTIMAL ||
      response.status() == CpSolverStatus::FEASIBLE) {
    LOG(INFO) << "Solution:";
    

    struct AssignedTaskType {
      int job_id;
      int task_id;
      int64_t start;
      int64_t duration;

      bool operator<(const AssignedTaskType& rhs) const {
        return std::tie(this->start, this->duration) <
               std::tie(rhs.start, rhs.duration);
      }
    };

    std::map<int64_t, std::vector<AssignedTaskType>> assigned_jobs;
    for (int job_id = 0; job_id < jobs_data.size(); ++job_id) {
      const auto& job = jobs_data[job_id];
      for (int task_id = 0; task_id < job.size(); ++task_id) {
        const auto [machine, duration] = job[task_id];
        TaskID key = std::make_tuple(job_id, task_id);
        int64_t start = SolutionIntegerValue(response, all_tasks[key].start);
        assigned_jobs[machine].push_back(
            AssignedTaskType{
job_id,
                             
task_id,
                             
start,
                             
duration});
      }
    }

    

    std::string output = "";
    for (const auto machine : all_machines) {
      

      std::sort(assigned_jobs[machine].begin(), assigned_jobs[machine].end());
      std::string sol_line_tasks = "Machine " + std::to_string(machine) + ": ";
      std::string sol_line = "           ";

      for (const auto& assigned_task : assigned_jobs[machine]) {
        std::string name = absl::StrFormat(
            "job_%d_task_%d", assigned_task.job_id, assigned_task.task_id);
        

        sol_line_tasks += absl::StrFormat("%-15s", name);

        int64_t start = assigned_task.start;
        int64_t duration = assigned_task.duration;
        std::string sol_tmp =
            absl::StrFormat("[%i,%i]", start, start + duration);
        

        sol_line += absl::StrFormat("%-15s", sol_tmp);
      }
      output += sol_line_tasks + "\n";
      output += sol_line + "\n";
    }
    

    LOG(INFO) << "Optimal Schedule Length: " << response.objective_value();
    LOG(INFO) << "\n" << output;
  } else {
    LOG(INFO) << "No solution found.";
  }
  


  

  

  LOG(INFO) << "Statistics";
  LOG(INFO) << CpSolverResponseStats(response);
  

}

}  

}  


int main() {
  operations_research::sat::MinimalJobshopSat();
  return EXIT_SUCCESS;
}


