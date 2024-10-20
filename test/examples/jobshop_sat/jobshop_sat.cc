
























#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <limits>
#include <string>
#include <vector>

#include "absl/container/flat_hash_map.h"
#include "absl/container/flat_hash_set.h"
#include "absl/flags/flag.h"
#include "absl/log/check.h"
#include "absl/strings/str_join.h"
#include "absl/types/span.h"
#include "google/protobuf/text_format.h"
#include "google/protobuf/wrappers.pb.h"
#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"
#include "ortools/graph/connected_components.h"
#include "ortools/sat/cp_model.h"
#include "ortools/sat/cp_model.pb.h"
#include "ortools/sat/cp_model_solver.h"
#include "ortools/sat/sat_parameters.pb.h"
#include "ortools/scheduling/jobshop_scheduling.pb.h"
#include "ortools/scheduling/jobshop_scheduling_parser.h"
#include "ortools/util/sorted_interval_list.h"

ABSL_FLAG(std::string, input, "", "Jobshop data file name.");
ABSL_FLAG(std::string, params, "", "Sat parameters in text proto format.");
ABSL_FLAG(bool, use_optional_variables, false,
          "Whether we use optional variables for bounds of an optional "
          "interval or not.");
ABSL_FLAG(bool, use_interval_makespan, false,
          "Whether we encode the makespan using an interval or not.");
ABSL_FLAG(bool, use_variable_duration_to_encode_transition, false,
          "Whether we move the transition cost to the alternative duration.");
ABSL_FLAG(
    bool, use_cumulative_relaxation, true,
    "Whether we regroup multiple machines to create a cumulative relaxation.");
ABSL_FLAG(bool, display_model, false, "Display jobshop proto before solving.");
ABSL_FLAG(bool, display_sat_model, false, "Display sat proto before solving.");
ABSL_FLAG(int, horizon, -1, "Override horizon computation.");

using operations_research::scheduling::jssp::Job;
using operations_research::scheduling::jssp::JobPrecedence;
using operations_research::scheduling::jssp::JsspInputProblem;
using operations_research::scheduling::jssp::Machine;
using operations_research::scheduling::jssp::Task;
using operations_research::scheduling::jssp::TransitionTimeMatrix;

namespace operations_research {
namespace sat {



int64_t ComputeHorizon(const JsspInputProblem& problem) {
  int64_t sum_of_durations = 0;
  int64_t max_latest_end = 0;
  int64_t max_earliest_start = 0;
  for (const Job& job : problem.jobs()) {
    if (job.has_latest_end()) {
      max_latest_end = std::max(max_latest_end, job.latest_end().value());
    } else {
      max_latest_end = std::numeric_limits<int64_t>::max();
    }
    if (job.has_earliest_start()) {
      max_earliest_start =
          std::max(max_earliest_start, job.earliest_start().value());
    }
    for (const Task& task : job.tasks()) {
      int64_t max_duration = 0;
      for (int64_t d : task.duration()) {
        max_duration = std::max(max_duration, d);
      }
      sum_of_durations += max_duration;
    }
  }

  const int num_jobs = problem.jobs_size();
  int64_t sum_of_transitions = 0;
  for (const Machine& machine : problem.machines()) {
    if (!machine.has_transition_time_matrix()) continue;
    const TransitionTimeMatrix& matrix = machine.transition_time_matrix();
    for (int i = 0; i < num_jobs; ++i) {
      int64_t max_transition = 0;
      for (int j = 0; j < num_jobs; ++j) {
        max_transition =
            std::max(max_transition, matrix.transition_time(i * num_jobs + j));
      }
      sum_of_transitions += max_transition;
    }
  }
  return std::min(max_latest_end,
                  sum_of_durations + sum_of_transitions + max_earliest_start);
}





struct JobTaskData {
  IntervalVar interval;
  LinearExpr start;
  LinearExpr duration;
  LinearExpr end;
};





void CreateJobs(const JsspInputProblem& problem, int64_t horizon,
                std::vector<std::vector<JobTaskData>>& job_to_tasks,
                CpModelBuilder& cp_model) {
  const int num_jobs = problem.jobs_size();

  for (int j = 0; j < num_jobs; ++j) {
    const Job& job = problem.jobs(j);
    const int num_tasks_in_job = job.tasks_size();
    std::vector<JobTaskData>& task_data = job_to_tasks[j];

    const int64_t hard_start =
        job.has_earliest_start() ? job.earliest_start().value() : 0L;
    const int64_t hard_end =
        job.has_latest_end() ? job.latest_end().value() : horizon;

    for (int t = 0; t < num_tasks_in_job; ++t) {
      const Task& task = job.tasks(t);
      const int num_alternatives = task.machine_size();
      CHECK_EQ(num_alternatives, task.duration_size());

      

      std::vector<int64_t> durations;
      int64_t min_duration = task.duration(0);
      int64_t max_duration = task.duration(0);
      durations.push_back(task.duration(0));
      for (int a = 1; a < num_alternatives; ++a) {
        min_duration = std::min(min_duration, task.duration(a));
        max_duration = std::max(max_duration, task.duration(a));
        durations.push_back(task.duration(a));
      }

      

      

      

      

      

      

      

      

      

      

      

      const IntVar start = cp_model.NewIntVar(Domain(
          hard_start,
          job.has_latest_end() || problem.makespan_cost_per_time_unit() == 0
              ? hard_end
              : hard_end - max_duration));
      if (min_duration == max_duration) {
        const IntervalVar interval =
            cp_model.NewFixedSizeIntervalVar(start, min_duration);
        task_data.push_back(
            {interval, start, min_duration, start + min_duration});
      } else {
        const IntVar duration =
            cp_model.NewIntVar(Domain::FromValues(durations));
        const IntVar end = cp_model.NewIntVar(Domain(hard_start, hard_end));
        const IntervalVar interval =
            cp_model.NewIntervalVar(start, duration, end);
        task_data.push_back({interval, start, duration, end});
      }

      

      if (t > 0) {
        cp_model.AddLessOrEqual(task_data[t - 1].end, task_data[t].start);
      }
    }
  }
}







struct AlternativeTaskData {
  int machine;
  IntervalVar interval;
  BoolVar presence;
};





void CreateAlternativeTasks(
    const JsspInputProblem& problem,
    absl::Span<const std::vector<JobTaskData>> job_to_tasks, int64_t horizon,
    std::vector<std::vector<std::vector<AlternativeTaskData>>>&
        job_task_to_alternatives,
    CpModelBuilder& cp_model) {
  const int num_jobs = problem.jobs_size();
  const BoolVar true_var = cp_model.TrueVar();

  for (int j = 0; j < num_jobs; ++j) {
    const Job& job = problem.jobs(j);
    const int num_tasks_in_job = job.tasks_size();
    job_task_to_alternatives[j].resize(num_tasks_in_job);
    const std::vector<JobTaskData>& tasks = job_to_tasks[j];

    const int64_t hard_start =
        job.has_earliest_start() ? job.earliest_start().value() : 0L;
    const int64_t hard_end =
        job.has_latest_end() ? job.latest_end().value() : horizon;

    for (int t = 0; t < num_tasks_in_job; ++t) {
      const Task& task = job.tasks(t);
      const int num_alternatives = task.machine_size();
      CHECK_EQ(num_alternatives, task.duration_size());
      std::vector<AlternativeTaskData>& alternatives =
          job_task_to_alternatives[j][t];

      if (num_alternatives == 1) {
        if (absl::GetFlag(FLAGS_use_variable_duration_to_encode_transition) &&
            problem.machines(task.machine(0)).has_transition_time_matrix()) {
          const IntVar variable_duration = cp_model.NewIntVar(
              Domain(task.duration(0), hard_end - hard_start));
          const IntVar alt_end =
              cp_model.NewIntVar(Domain(hard_start, hard_end));
          const IntervalVar alt_interval = cp_model.NewIntervalVar(
              tasks[t].start, variable_duration, alt_end);
          alternatives.push_back({task.machine(0), alt_interval, true_var});
        } else {
          alternatives.push_back(
              {task.machine(0), tasks[t].interval, true_var});
        }
      } else {
        for (int a = 0; a < num_alternatives; ++a) {
          const BoolVar alt_presence = cp_model.NewBoolVar();
          const int64_t alt_duration = task.duration(a);
          const int alt_machine = task.machine(a);
          DCHECK_GE(hard_end - hard_start, alt_duration);
          const LinearExpr alt_start =
              absl::GetFlag(FLAGS_use_optional_variables)
                  ? cp_model.NewIntVar(
                        Domain(hard_start, hard_end - alt_duration))
                  : tasks[t].start;
          IntervalVar alt_interval;
          if (absl::GetFlag(FLAGS_use_variable_duration_to_encode_transition) &&
              problem.machines(alt_machine).has_transition_time_matrix()) {
            const IntVar variable_duration =
                cp_model.NewIntVar(Domain(alt_duration, hard_end - hard_start));
            const IntVar alt_end =
                cp_model.NewIntVar(Domain(hard_start, hard_end));
            alt_interval = cp_model.NewOptionalIntervalVar(
                alt_start, variable_duration, alt_end, alt_presence);
          } else {
            alt_interval = cp_model.NewOptionalFixedSizeIntervalVar(
                alt_start, alt_duration, alt_presence);
            if (!tasks[t].duration.IsConstant()) {
              cp_model.AddEquality(tasks[t].duration, alt_duration)
                  .OnlyEnforceIf(alt_presence);
            }
          }

          

          if (absl::GetFlag(FLAGS_use_optional_variables)) {
            cp_model.AddEquality(tasks[t].start, alt_start)
                .OnlyEnforceIf(alt_presence);
          }

          alternatives.push_back({alt_machine, alt_interval, alt_presence});
        }

        

        std::vector<BoolVar> interval_presences;
        for (const AlternativeTaskData& alternative : alternatives) {
          interval_presences.push_back(alternative.presence);
        }
        cp_model.AddExactlyOne(interval_presences);
      }
    }
  }
}







struct MachineTaskData {
  int job;
  IntervalVar interval;
  int64_t fixed_duration;
};

std::vector<std::vector<MachineTaskData>> GetDataPerMachine(
    const JsspInputProblem& problem,
    absl::Span<const std::vector<std::vector<AlternativeTaskData>>>
        job_task_to_alternatives) {
  const int num_jobs = problem.jobs_size();
  const int num_machines = problem.machines_size();
  std::vector<std::vector<MachineTaskData>> machine_to_tasks(num_machines);
  for (int j = 0; j < num_jobs; ++j) {
    const Job& job = problem.jobs(j);
    const int num_tasks_in_job = job.tasks_size();
    for (int t = 0; t < num_tasks_in_job; ++t) {
      const Task& task = job.tasks(t);
      const int num_alternatives = task.machine_size();
      CHECK_EQ(num_alternatives, task.duration_size());
      const std::vector<AlternativeTaskData>& alt_data =
          job_task_to_alternatives[j][t];
      for (int a = 0; a < num_alternatives; ++a) {
        machine_to_tasks[task.machine(a)].push_back(
            {j, alt_data[a].interval, task.duration(a)});
      }
    }
  }
  return machine_to_tasks;
}

void CreateMachines(
    const JsspInputProblem& problem,
    absl::Span<const std::vector<std::vector<AlternativeTaskData>>>
        job_task_to_alternatives,
    IntervalVar makespan_interval, CpModelBuilder& cp_model) {
  const int num_jobs = problem.jobs_size();
  const int num_machines = problem.machines_size();
  const std::vector<std::vector<MachineTaskData>> machine_to_tasks =
      GetDataPerMachine(problem, job_task_to_alternatives);

  

  for (int m = 0; m < num_machines; ++m) {
    std::vector<IntervalVar> intervals;
    for (const MachineTaskData& task : machine_to_tasks[m]) {
      intervals.push_back(task.interval);
    }
    if (absl::GetFlag(FLAGS_use_interval_makespan) &&
        problem.makespan_cost_per_time_unit() != 0L) {
      intervals.push_back(makespan_interval);
    }
    cp_model.AddNoOverlap(intervals);
  }

  

  

  

  

  

  for (int m = 0; m < num_machines; ++m) {
    if (!problem.machines(m).has_transition_time_matrix()) continue;

    int64_t num_non_zero_transitions = 0;
    const int num_intervals = machine_to_tasks[m].size();
    const TransitionTimeMatrix& machine_transitions =
        problem.machines(m).transition_time_matrix();

    

    

    CircuitConstraint circuit = cp_model.AddCircuitConstraint();

    

    

    BoolVar empty_circuit = cp_model.NewBoolVar();
    circuit.AddArc(0, 0, empty_circuit);

    for (int i = 0; i < num_intervals; ++i) {
      const int job_i = machine_to_tasks[m][i].job;
      const MachineTaskData& tail = machine_to_tasks[m][i];

      

      CHECK_EQ(i, job_i);

      

      circuit.AddArc(0, i + 1, cp_model.NewBoolVar());
      

      circuit.AddArc(i + 1, 0, cp_model.NewBoolVar());

      

      cp_model.AddImplication(empty_circuit, ~tail.interval.PresenceBoolVar());

      

      std::vector<BoolVar> literals;
      std::vector<int64_t> transitions;

      

      for (int j = 0; j < num_intervals; ++j) {
        if (i == j) {
          circuit.AddArc(i + 1, i + 1, ~tail.interval.PresenceBoolVar());
        } else {
          const MachineTaskData& head = machine_to_tasks[m][j];
          const int job_j = head.job;

          

          CHECK_EQ(j, job_j);
          const int64_t transition =
              machine_transitions.transition_time(job_i * num_jobs + job_j);
          if (transition != 0) ++num_non_zero_transitions;

          const BoolVar lit = cp_model.NewBoolVar();
          circuit.AddArc(i + 1, j + 1, lit);

          if (absl::GetFlag(FLAGS_use_variable_duration_to_encode_transition)) {
            

            

            literals.push_back(lit);
            transitions.push_back(transition);
            

            

            cp_model
                .AddEquality(tail.interval.SizeExpr(),
                             tail.fixed_duration + transition)
                .OnlyEnforceIf(lit);
          }

          

          

          

          cp_model
              .AddLessOrEqual(
                  tail.interval.StartExpr() + tail.fixed_duration + transition,
                  head.interval.StartExpr())
              .OnlyEnforceIf(lit);
        }
      }

      

      if (absl::GetFlag(FLAGS_use_variable_duration_to_encode_transition)) {
        cp_model.AddEquality(tail.interval.SizeExpr(),
                             LinearExpr::WeightedSum(literals, transitions) +
                                 tail.fixed_duration);
      }
    }
    LOG(INFO) << "Machine " << m
              << ": #non_zero_transitions: " << num_non_zero_transitions << "/"
              << num_intervals * (num_intervals - 1)
              << ", #intervals: " << num_intervals;
  }
}



void CreateObjective(
    const JsspInputProblem& problem,
    absl::Span<const std::vector<JobTaskData>> job_to_tasks,
    absl::Span<const std::vector<std::vector<AlternativeTaskData>>>
        job_task_to_alternatives,
    int64_t horizon, IntVar makespan, CpModelBuilder& cp_model) {
  LinearExpr objective;
  const int num_jobs = problem.jobs_size();
  for (int j = 0; j < num_jobs; ++j) {
    const Job& job = problem.jobs(j);
    const int num_tasks_in_job = job.tasks_size();

    

    for (int t = 0; t < num_tasks_in_job; ++t) {
      const Task& task = job.tasks(t);
      const int num_alternatives = task.machine_size();

      for (int a = 0; a < num_alternatives; ++a) {
        

        if (task.cost_size() > 0) {
          objective +=
              job_task_to_alternatives[j][t][a].presence * task.cost(a);
        }
      }
    }

    

    const int64_t lateness_penalty = job.lateness_cost_per_time_unit();
    if (lateness_penalty != 0L) {
      const int64_t due_date = job.late_due_date();
      const LinearExpr job_end = job_to_tasks[j].back().end;
      if (due_date == 0) {
        objective += job_end * lateness_penalty;
      } else {
        const IntVar lateness_var = cp_model.NewIntVar(Domain(0, horizon));
        cp_model.AddMaxEquality(lateness_var, {0, job_end - due_date});
        objective += lateness_var * lateness_penalty;
      }
    }

    

    const int64_t earliness_penalty = job.earliness_cost_per_time_unit();
    if (earliness_penalty != 0L) {
      const int64_t due_date = job.early_due_date();
      const LinearExpr job_end = job_to_tasks[j].back().end;

      if (due_date > 0) {
        const IntVar earliness_var = cp_model.NewIntVar(Domain(0, horizon));
        cp_model.AddMaxEquality(earliness_var, {0, due_date - job_end});
        objective += earliness_var * earliness_penalty;
      }
    }
  }

  

  if (problem.makespan_cost_per_time_unit() != 0L) {
    objective += makespan * problem.makespan_cost_per_time_unit();
  }

  

  cp_model.Minimize(objective);
  if (problem.has_scaling_factor()) {
    

    cp_model.MutableProto()->mutable_objective()->set_scaling_factor(
        1.0 / problem.scaling_factor().value());
  }
}





void AddCumulativeRelaxation(
    const JsspInputProblem& problem,
    absl::Span<const std::vector<JobTaskData>> job_to_tasks,
    IntervalVar makespan_interval, CpModelBuilder& cp_model) {
  const int num_jobs = problem.jobs_size();
  const int num_machines = problem.machines_size();

  

  

  int num_tasks = 0;
  std::vector<absl::flat_hash_set<int>> neighbors(num_machines);
  for (int j = 0; j < num_jobs; ++j) {
    const Job& job = problem.jobs(j);
    const int num_tasks_in_job = job.tasks_size();
    num_tasks += num_tasks_in_job;
    for (int t = 0; t < num_tasks_in_job; ++t) {
      const Task& task = job.tasks(t);
      for (int a = 1; a < task.machine_size(); ++a) {
        neighbors[task.machine(0)].insert(task.machine(a));
      }
    }
  }

  

  std::vector<int> components =
      util::GetConnectedComponents(num_machines, neighbors);
  absl::flat_hash_map<int, std::vector<int>> machines_per_component;
  for (int c = 0; c < components.size(); ++c) {
    machines_per_component[components[c]].push_back(c);
  }
  LOG(INFO) << "Found " << machines_per_component.size()
            << " connected machine components";

  for (const auto& it : machines_per_component) {
    absl::flat_hash_set<int> component(it.second.begin(), it.second.end());
    std::vector<IntervalVar> connected_intervals;
    for (int j = 0; j < num_jobs; ++j) {
      const Job& job = problem.jobs(j);
      const int num_tasks_in_job = job.tasks_size();
      for (int t = 0; t < num_tasks_in_job; ++t) {
        const Task& task = job.tasks(t);
        for (const int m : task.machine()) {
          if (component.contains(m)) {
            connected_intervals.push_back(job_to_tasks[j][t].interval);
            break;
          }
        }
      }
    }

    

    

    if (connected_intervals.size() <= 1 || component.size() <= 1 ||
        component.size() == num_tasks) {
      continue;
    }

    LOG(INFO) << "Interesting machine connected component: ["
              << absl::StrJoin(it.second, ", ") << "] with "
              << connected_intervals.size() << " intervals";

    CumulativeConstraint cumul = cp_model.AddCumulative(component.size());
    for (const IntervalVar& interval : connected_intervals) {
      cumul.AddDemand(interval, 1);
    }
    if (absl::GetFlag(FLAGS_use_interval_makespan)) {
      cumul.AddDemand(makespan_interval, component.size());
    }
  }
}





void AddMakespanRedundantConstraints(
    const JsspInputProblem& problem,
    absl::Span<const std::vector<JobTaskData>> job_to_tasks, IntVar makespan,
    CpModelBuilder& cp_model) {
  const int num_machines = problem.machines_size();

  

  LinearExpr sum_of_duration;
  for (const std::vector<JobTaskData>& tasks : job_to_tasks) {
    for (const JobTaskData& task : tasks) {
      sum_of_duration += task.duration;
    }
  }
  cp_model.AddLessOrEqual(sum_of_duration, makespan * num_machines);
}

void DisplayJobStatistics(
    const JsspInputProblem& problem, int64_t horizon,
    absl::Span<const std::vector<JobTaskData>> job_to_tasks,
    absl::Span<const std::vector<std::vector<AlternativeTaskData>>>
        job_task_to_alternatives) {
  const int num_jobs = job_to_tasks.size();
  int num_tasks = 0;
  int num_tasks_with_variable_duration = 0;
  int num_tasks_with_alternatives = 0;
  for (const std::vector<JobTaskData>& job : job_to_tasks) {
    num_tasks += job.size();
    for (const JobTaskData& task : job) {
      if (!task.duration.IsConstant()) {
        num_tasks_with_variable_duration++;
      }
    }
  }
  for (const std::vector<std::vector<AlternativeTaskData>>&
           task_to_alternatives : job_task_to_alternatives) {
    for (const std::vector<AlternativeTaskData>& alternatives :
         task_to_alternatives) {
      if (alternatives.size() > 1) num_tasks_with_alternatives++;
    }
  }

  LOG(INFO) << "#machines:" << problem.machines_size();
  LOG(INFO) << "#jobs:" << num_jobs;
  LOG(INFO) << "horizon:" << horizon;
  LOG(INFO) << "#tasks: " << num_tasks;
  LOG(INFO) << "#tasks with alternative: " << num_tasks_with_alternatives;
  LOG(INFO) << "#tasks with variable duration: "
            << num_tasks_with_variable_duration;
}



void Solve(const JsspInputProblem& problem) {
  if (absl::GetFlag(FLAGS_display_model)) {
    LOG(INFO) << problem;
  }

  CpModelBuilder cp_model;
  if (!problem.name().empty()) {
    cp_model.SetName(problem.name());
  }

  

  const int64_t horizon = absl::GetFlag(FLAGS_horizon) != -1
                              ? absl::GetFlag(FLAGS_horizon)
                              : ComputeHorizon(problem);

  

  const int num_jobs = problem.jobs_size();
  std::vector<std::vector<JobTaskData>> job_to_tasks(num_jobs);
  CreateJobs(problem, horizon, job_to_tasks, cp_model);

  

  

  std::vector<std::vector<std::vector<AlternativeTaskData>>>
      job_task_to_alternatives(num_jobs);
  CreateAlternativeTasks(problem, job_to_tasks, horizon,
                         job_task_to_alternatives, cp_model);

  

  

  

  

  

  

  

  

  

  

  

  const IntVar makespan = cp_model.NewIntVar(Domain(0, horizon));
  IntervalVar makespan_interval;
  if (problem.makespan_cost_per_time_unit() != 0L) {
    if (absl::GetFlag(FLAGS_use_interval_makespan)) {
      makespan_interval = cp_model.NewIntervalVar(
          
makespan,
          
cp_model.NewIntVar(Domain(1, horizon)),
          
cp_model.NewIntVar(Domain(horizon + 1)));
    }
    for (int j = 0; j < num_jobs; ++j) {
      

      cp_model.AddLessOrEqual(job_to_tasks[j].back().end, makespan);
    }
  }

  

  

  DisplayJobStatistics(problem, horizon, job_to_tasks,
                       job_task_to_alternatives);

  

  CreateMachines(problem, job_task_to_alternatives, makespan_interval,
                 cp_model);

  

  

  

  if (absl::GetFlag(FLAGS_use_cumulative_relaxation) &&
      problem.makespan_cost_per_time_unit() != 0) {
    AddCumulativeRelaxation(problem, job_to_tasks, makespan_interval, cp_model);
  }

  

  

  if (problem.makespan_cost_per_time_unit() != 0L) {
    AddMakespanRedundantConstraints(problem, job_to_tasks, makespan, cp_model);
  }

  

  for (const JobPrecedence& precedence : problem.precedences()) {
    const LinearExpr start =
        job_to_tasks[precedence.second_job_index()].front().start;
    const LinearExpr end =
        job_to_tasks[precedence.first_job_index()].back().end;
    cp_model.AddLessOrEqual(end + precedence.min_delay(), start);
  }

  

  CreateObjective(problem, job_to_tasks, job_task_to_alternatives, horizon,
                  makespan, cp_model);

  

  


  if (absl::GetFlag(FLAGS_display_sat_model)) {
    LOG(INFO) << cp_model.Proto();
  }

  

  SatParameters parameters;
  parameters.set_log_search_progress(true);

  

  if (parameters.num_workers() >= 16 && parameters.num_workers() < 24) {
    parameters.add_ignore_subsolvers("objective_lb_search");
    parameters.add_extra_subsolvers("objective_shaving_search");
  }

  

  

  parameters.set_push_all_tasks_toward_start(true);
  parameters.set_use_dynamic_precedence_in_disjunctive(true);

  

  if (!absl::GetFlag(FLAGS_params).empty()) {
    CHECK(google::protobuf::TextFormat::MergeFromString(
        absl::GetFlag(FLAGS_params), &parameters))
        << absl::GetFlag(FLAGS_params);
  }

  const CpSolverResponse response =
      SolveWithParameters(cp_model.Build(), parameters);

  

  if (response.status() != CpSolverStatus::OPTIMAL &&
      response.status() != CpSolverStatus::FEASIBLE)
    return;

  

  {
    const int num_machines = problem.machines_size();
    const std::vector<std::vector<MachineTaskData>> machine_to_tasks =
        GetDataPerMachine(problem, job_task_to_alternatives);
    for (int m = 0; m < num_machines; ++m) {
      if (!problem.machines(m).has_transition_time_matrix()) continue;

      struct Data {
        int job;
        int64_t fixed_duration;
        int64_t start;
        int64_t end;
      };
      std::vector<Data> schedule;
      for (const MachineTaskData& d : machine_to_tasks[m]) {
        if (!SolutionBooleanValue(response, d.interval.PresenceBoolVar())) {
          continue;
        }
        schedule.push_back(
            {d.job, d.fixed_duration,
             SolutionIntegerValue(response, d.interval.StartExpr()),
             SolutionIntegerValue(response, d.interval.EndExpr())});
      }
      std::sort(schedule.begin(), schedule.end(),
                [](const Data& a, const Data& b) { return a.start < b.start; });

      const TransitionTimeMatrix& transitions =
          problem.machines(m).transition_time_matrix();

      int last_job = -1;
      int64_t last_start = std::numeric_limits<int64_t>::min();
      int64_t last_duration;
      for (const Data& d : schedule) {
        const int64_t transition =
            last_job == -1
                ? 0
                : transitions.transition_time(last_job * num_jobs + d.job);
        CHECK_LE(last_start + last_duration + transition, d.start);
        last_job = d.job;
        last_start = d.start;
        last_duration = d.fixed_duration;
      }
    }
  }

  

  int64_t final_cost = 0;
  if (problem.makespan_cost_per_time_unit() != 0) {
    int64_t makespan = 0;
    for (const std::vector<JobTaskData>& tasks : job_to_tasks) {
      const LinearExpr job_end = tasks.back().end;
      makespan = std::max(makespan, SolutionIntegerValue(response, job_end));
    }
    final_cost += makespan * problem.makespan_cost_per_time_unit();
  }

  for (int j = 0; j < num_jobs; ++j) {
    const int64_t early_due_date = problem.jobs(j).early_due_date();
    const int64_t late_due_date = problem.jobs(j).late_due_date();
    const int64_t early_penalty =
        problem.jobs(j).earliness_cost_per_time_unit();
    const int64_t late_penalty = problem.jobs(j).lateness_cost_per_time_unit();
    const int64_t end =
        SolutionIntegerValue(response, job_to_tasks[j].back().end);
    if (end < early_due_date && early_penalty != 0) {
      final_cost += (early_due_date - end) * early_penalty;
    }
    if (end > late_due_date && late_penalty != 0) {
      final_cost += (end - late_due_date) * late_penalty;
    }
  }

  

  

  

  

  

  

  const double tolerance = 1e-6;
  DCHECK_GE(response.objective_value(), final_cost - tolerance);
  DCHECK_LE(response.objective_value(), final_cost + tolerance);
}

}  

}  


int main(int argc, char** argv) {
  absl::SetFlag(&FLAGS_stderrthreshold, 0);
  InitGoogle(argv[0], &argc, &argv, true);

  if (absl::GetFlag(FLAGS_input).empty()) {
    LOG(FATAL) << "Please supply a data file with --input=";
  }

  operations_research::scheduling::jssp::JsspParser parser;
  CHECK(parser.ParseFile(absl::GetFlag(FLAGS_input)));
  operations_research::sat::Solve(parser.problem());
  return EXIT_SUCCESS;
}
