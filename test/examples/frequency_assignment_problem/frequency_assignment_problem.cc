





























































































#include <algorithm>
#include <cstdint>
#include <string>
#include <utility>
#include <vector>

#include "absl/container/btree_map.h"
#include "absl/strings/string_view.h"
#include "absl/types/span.h"
#include "examples/cpp/fap_model_printer.h"
#include "examples/cpp/fap_parser.h"
#include "examples/cpp/fap_utilities.h"
#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"
#include "ortools/base/map_util.h"
#include "ortools/constraint_solver/constraint_solver.h"

ABSL_FLAG(std::string, directory, "", "Specifies the directory of the data.");
ABSL_FLAG(std::string, value_evaluator, "",
          "Specifies if a value evaluator will be used by the "
          "decision builder.");
ABSL_FLAG(std::string, variable_evaluator, "",
          "Specifies if a variable evaluator will be used by the "
          "decision builder.");
ABSL_FLAG(int, time_limit_in_ms, 0, "Time limit in ms, <= 0 means no limit.");
ABSL_FLAG(int, choose_next_variable_strategy, 1,
          "Selection strategy for variable: "
          "1 = CHOOSE_FIRST_UNBOUND, "
          "2 = CHOOSE_MIN_SIZE_LOWEST_MIN, "
          "3 = CHOOSE_MIN_SIZE_HIGHEST_MAX, "
          "4 = CHOOSE_RANDOM, ");
ABSL_FLAG(int, restart, -1, "Parameter for constant restart monitor.");
ABSL_FLAG(bool, find_components, false,
          "If possible, split the problem into independent sub-problems.");
ABSL_FLAG(bool, luby, false,
          "Use luby restart monitor instead of constant restart monitor.");
ABSL_FLAG(bool, log_search, true, "Create a search log.");
ABSL_FLAG(bool, soft, false, "Use soft solver instead of hard solver.");
ABSL_FLAG(bool, display_time, true,
          "Print how much time the solving process took.");
ABSL_FLAG(bool, display_results, true,
          "Print the results of the solving process.");

namespace operations_research {





class OrderingDecision : public Decision {
 public:
  OrderingDecision(IntVar* const variable1, IntVar* const variable2, int value,
                   std::string operation)
      : variable1_(variable1),
        variable2_(variable2),
        value_(value),
        operator_(std::move(operation)) {}

  

  OrderingDecision(const OrderingDecision&) = delete;
  OrderingDecision& operator=(const OrderingDecision&) = delete;
  ~OrderingDecision() override = default;

  

  void Apply(Solver* const s) override {
    

    MakeDecision(s, variable1_, variable2_);
  }

  

  void Refute(Solver* const s) override {
    

    MakeDecision(s, variable2_, variable1_);
  }

 private:
  void MakeDecision(Solver* s, IntVar* variable1, IntVar* variable2) {
    if (operator_ == ">") {
      IntExpr* difference = (s->MakeDifference(variable2, variable1));
      s->AddConstraint(s->MakeGreater(difference, value_));
    } else if (operator_ == "=") {
      IntExpr* difference = (s->MakeDifference(variable2, variable1));
      s->AddConstraint(s->MakeEquality(difference, value_));
    } else {
      LOG(FATAL) << "No right operator specified.";
    }
  }

  IntVar* const variable1_;
  IntVar* const variable2_;
  const int value_;
  const std::string operator_;
};





class ConstraintDecision : public Decision {
 public:
  explicit ConstraintDecision(IntVar* const constraint_violation)
      : constraint_violation_(constraint_violation) {}

  

  ConstraintDecision(const ConstraintDecision&) = delete;
  ConstraintDecision& operator=(const ConstraintDecision&) = delete;

  ~ConstraintDecision() override = default;

  

  void Apply(Solver* const) override {
    

    constraint_violation_->SetValue(0);
  }

  

  void Refute(Solver* const) override {
    

    constraint_violation_->SetValue(1);
  }

 private:
  IntVar* const constraint_violation_;
};









class OrderingBuilder : public DecisionBuilder {
 public:
  enum Order { LESS = -1, EQUAL = 0, GREATER = 1 };

  OrderingBuilder(const absl::btree_map<int, FapVariable>& data_variables,
                  const std::vector<FapConstraint>& data_constraints,
                  const std::vector<IntVar*>& variables,
                  const std::vector<IntVar*>& violated_constraints,
                  const absl::btree_map<int, int>& index_from_key)
      : data_variables_(data_variables),
        data_constraints_(data_constraints),
        variables_(variables),
        violated_constraints_(violated_constraints),
        index_from_key_(index_from_key),
        size_(data_constraints.size()),
        iter_(0),
        checked_iter_(0) {
    for (const auto& it : data_variables_) {
      int first_element = (it.second.domain)[0];
      minimum_value_available_.push_back(first_element);
      variable_state_.push_back(EQUAL);
    }
    CHECK_EQ(minimum_value_available_.size(), variables_.size());
    CHECK_EQ(variable_state_.size(), variables_.size());
  }

  

  OrderingBuilder(const OrderingBuilder&) = delete;
  OrderingBuilder& operator=(const OrderingBuilder&) = delete;

  ~OrderingBuilder() override = default;

  Decision* Next(Solver* const s) override {
    if (iter_ < size_) {
      FapConstraint constraint = data_constraints_[iter_];
      const int index1 = gtl::FindOrDie(index_from_key_, constraint.variable1);
      const int index2 = gtl::FindOrDie(index_from_key_, constraint.variable2);
      IntVar* variable1 = variables_[index1];
      IntVar* variable2 = variables_[index2];

      

      

      

      

      if (!checked_iter_ && !constraint.hard) {
        

        ConstraintDecision* constraint_decision =
            new ConstraintDecision(violated_constraints_[iter_]);

        s->SaveAndAdd(&checked_iter_, 1);
        return s->RevAlloc(constraint_decision);
      }

      

      if (violated_constraints_[iter_]->Bound() &&
          violated_constraints_[iter_]->Value() == 0) {
        

        OrderingDecision* ordering_decision;
        Order hint = Hint(constraint);
        if (hint == LESS || hint == EQUAL) {
          ordering_decision = new OrderingDecision(
              variable1, variable2, constraint.value, constraint.operation);
        } else {
          ordering_decision = new OrderingDecision(
              variable2, variable1, constraint.value, constraint.operation);
        }
        

        s->SaveAndAdd(&iter_, 1);
        

        s->SaveAndSetValue(&checked_iter_, 0);
        return s->RevAlloc(ordering_decision);
      } else {
        

        return nullptr;
      }
    } else {
      

      return nullptr;
    }
  }

 private:
  Order Variable1LessVariable2(const int variable1, const int variable2,
                               const int value) {
    minimum_value_available_[variable2] =
        std::max(minimum_value_available_[variable2],
                 minimum_value_available_[variable1] + value);
    return LESS;
  }

  Order Variable1GreaterVariable2(const int variable1, const int variable2,
                                  const int value) {
    minimum_value_available_[variable1] =
        std::max(minimum_value_available_[variable1],
                 minimum_value_available_[variable2] + value);
    return GREATER;
  }
  

  

  

  

  

  

  

  

  

  

  

  

  

  Order Hint(const FapConstraint& constraint) {
    const int id1 = constraint.variable1;
    const int id2 = constraint.variable2;
    const int variable1 = gtl::FindOrDie(index_from_key_, id1);
    const int variable2 = gtl::FindOrDie(index_from_key_, id2);
    const int value = constraint.value;
    CHECK_LT(variable1, variable_state_.size());
    CHECK_LT(variable2, variable_state_.size());
    CHECK_LT(variable1, minimum_value_available_.size());
    CHECK_LT(variable2, minimum_value_available_.size());

    if (variable_state_[variable1] > variable_state_[variable2]) {
      variable_state_[variable1] = GREATER;
      variable_state_[variable2] = LESS;
      return Variable1GreaterVariable2(variable1, variable2, value);
    } else if (variable_state_[variable1] < variable_state_[variable2]) {
      variable_state_[variable1] = LESS;
      variable_state_[variable2] = GREATER;
      return Variable1LessVariable2(variable1, variable2, value);
    } else {
      if (variable_state_[variable1] == 0 && variable_state_[variable2] == 0) {
        variable_state_[variable1] = LESS;
        variable_state_[variable2] = GREATER;
        return Variable1LessVariable2(variable1, variable2, value);
      } else {
        if (minimum_value_available_[variable1] >
            minimum_value_available_[variable2]) {
          return Variable1GreaterVariable2(variable1, variable2, value);
        } else {
          return Variable1LessVariable2(variable1, variable2, value);
        }
      }
    }
  }

  

  const absl::btree_map<int, FapVariable> data_variables_;
  const std::vector<FapConstraint> data_constraints_;
  const std::vector<IntVar*> variables_;
  const std::vector<IntVar*> violated_constraints_;
  const absl::btree_map<int, int> index_from_key_;
  

  const int size_;
  int iter_;
  int checked_iter_;
  

  std::vector<Order> variable_state_;
  std::vector<int> minimum_value_available_;
};



bool ConstraintImpactComparator(FapConstraint constraint1,
                                FapConstraint constraint2) {
  if (constraint1.impact == constraint2.impact) {
    return (constraint1.value > constraint2.value);
  }
  return (constraint1.impact > constraint2.impact);
}

int64_t ValueEvaluator(
    absl::flat_hash_map<int64_t, std::pair<int64_t, int64_t>>*
        value_evaluator_map,
    int64_t variable_index, int64_t value) {
  CHECK(value_evaluator_map != nullptr);
  

  int64_t ranking = -1;
  for (const auto& it : *value_evaluator_map) {
    if ((it.first != variable_index) && (it.second.first == value)) {
      ranking = -2;
      break;
    }
  }

  

  absl::flat_hash_map<int64_t, std::pair<int64_t, int64_t>>::iterator it;
  int64_t new_value = value;
  int64_t new_ranking = ranking;
  if ((it = value_evaluator_map->find(variable_index)) !=
      value_evaluator_map->end()) {
    std::pair<int64_t, int64_t> existing_value_ranking = it->second;
    

    

    if (!(existing_value_ranking.second > ranking ||
          (existing_value_ranking.second == ranking &&
           existing_value_ranking.first > value))) {
      new_value = existing_value_ranking.first;
      new_ranking = existing_value_ranking.second;
    }
  }
  std::pair<int64_t, int64_t> new_value_ranking =
      std::make_pair(new_value, new_ranking);
  value_evaluator_map->insert_or_assign(variable_index, new_value_ranking);

  return new_ranking;
}





int64_t VariableEvaluator(
    absl::Span<const int> key_from_index,
    const absl::btree_map<int, FapVariable>& data_variables,
    int64_t variable_index) {
  FapVariable variable =
      gtl::FindOrDie(data_variables, key_from_index[variable_index]);
  int64_t result = -(variable.degree * 100 / variable.domain_size);
  return result;
}



void CreateModelVariables(
    const absl::btree_map<int, FapVariable>& data_variables, Solver* solver,
    std::vector<IntVar*>* model_variables,
    absl::btree_map<int, int>* index_from_key,
    std::vector<int>* key_from_index) {
  CHECK(solver != nullptr);
  CHECK(model_variables != nullptr);
  CHECK(index_from_key != nullptr);
  CHECK(key_from_index != nullptr);

  const int number_of_variables = static_cast<int>(data_variables.size());
  model_variables->resize(number_of_variables);
  key_from_index->resize(number_of_variables);

  int index = 0;
  for (const auto& it : data_variables) {
    CHECK_LT(index, model_variables->size());
    (*model_variables)[index] = solver->MakeIntVar(it.second.domain);
    index_from_key->insert_or_assign(it.first, index);
    (*key_from_index)[index] = it.first;

    if ((it.second.initial_position != -1) && (it.second.hard)) {
      CHECK_LT(it.second.mobility_cost, 0);
      solver->AddConstraint(solver->MakeEquality((*model_variables)[index],
                                                 it.second.initial_position));
    }
    index++;
  }
}



void CreateModelConstraints(absl::Span<const FapConstraint> data_constraints,
                            const std::vector<IntVar*>& variables,
                            const absl::btree_map<int, int>& index_from_key,
                            Solver* solver) {
  CHECK(solver != nullptr);

  for (const FapConstraint& ct : data_constraints) {
    const int index1 = gtl::FindOrDie(index_from_key, ct.variable1);
    const int index2 = gtl::FindOrDie(index_from_key, ct.variable2);
    CHECK_LT(index1, variables.size());
    CHECK_LT(index2, variables.size());
    IntVar* var1 = variables[index1];
    IntVar* var2 = variables[index2];
    IntVar* absolute_difference =
        solver->MakeAbs(solver->MakeDifference(var1, var2))->Var();
    if (ct.operation == ">") {
      solver->AddConstraint(solver->MakeGreater(absolute_difference, ct.value));
    } else if (ct.operation == "=") {
      solver->AddConstraint(
          solver->MakeEquality(absolute_difference, ct.value));
    } else {
      LOG(FATAL) << "Invalid operator detected.";
      return;
    }
  }
}





void ChooseVariableStrategy(Solver::IntVarStrategy* variable_strategy) {
  CHECK(variable_strategy != nullptr);

  switch (absl::GetFlag(FLAGS_choose_next_variable_strategy)) {
    case 1: {
      *variable_strategy = Solver::CHOOSE_FIRST_UNBOUND;
      LOG(INFO) << "Using Solver::CHOOSE_FIRST_UNBOUND "
                   "for variable selection strategy.";
      break;
    }
    case 2: {
      *variable_strategy = Solver::CHOOSE_MIN_SIZE_LOWEST_MIN;
      LOG(INFO) << "Using Solver::CHOOSE_MIN_SIZE_LOWEST_MIN "
                   "for variable selection strategy.";
      break;
    }
    case 3: {
      *variable_strategy = Solver::CHOOSE_MIN_SIZE_HIGHEST_MAX;
      LOG(INFO) << "Using Solver::CHOOSE_MIN_SIZE_HIGHEST_MAX "
                   "for variable selection strategy.";
      break;
    }
    case 4: {
      *variable_strategy = Solver::CHOOSE_RANDOM;
      LOG(INFO) << "Using Solver::CHOOSE_RANDOM "
                   "for variable selection strategy.";
      break;
    }
    default: {
      LOG(FATAL) << "Should not be here";
      return;
    }
  }
}





void CreateAdditionalMonitors(OptimizeVar* const objective, Solver* solver,
                              std::vector<SearchMonitor*>* monitors) {
  CHECK(solver != nullptr);
  CHECK(monitors != nullptr);

  

  if (absl::GetFlag(FLAGS_log_search)) {
    SearchMonitor* const log = solver->MakeSearchLog(100000, objective);
    monitors->push_back(log);
  }

  

  if (absl::GetFlag(FLAGS_time_limit_in_ms) != 0) {
    LOG(INFO) << "Adding time limit of "
              << absl::GetFlag(FLAGS_time_limit_in_ms) << " ms.";
    SearchLimit* const limit = solver->MakeTimeLimit(
        absl::Milliseconds(absl::GetFlag(FLAGS_time_limit_in_ms)));
    monitors->push_back(limit);
  }

  

  SearchMonitor* const restart =
      absl::GetFlag(FLAGS_restart) != -1
          ? (absl::GetFlag(FLAGS_luby)
                 ? solver->MakeLubyRestart(absl::GetFlag(FLAGS_restart))
                 : solver->MakeConstantRestart(absl::GetFlag(FLAGS_restart)))
          : nullptr;
  if (restart) {
    monitors->push_back(restart);
  }
}









void HardFapSolver(const absl::btree_map<int, FapVariable>& data_variables,
                   const std::vector<FapConstraint>& data_constraints,
                   absl::string_view data_objective,
                   const std::vector<int>& values) {
  Solver solver("HardFapSolver");
  std::vector<SearchMonitor*> monitors;

  

  std::vector<IntVar*> variables;
  absl::btree_map<int, int> index_from_key;
  std::vector<int> key_from_index;
  CreateModelVariables(data_variables, &solver, &variables, &index_from_key,
                       &key_from_index);

  

  CreateModelConstraints(data_constraints, variables, index_from_key, &solver);

  

  std::vector<FapConstraint> ordered_constraints(data_constraints);
  std::sort(ordered_constraints.begin(), ordered_constraints.end(),
            ConstraintImpactComparator);

  std::vector<IntVar*> violated_constraints;
  solver.MakeIntVarArray(ordered_constraints.size(), 0, 0,
                         &violated_constraints);

  

  

  

  IntVar* objective_var;
  OptimizeVar* objective;
  if (data_objective == "Minimize the largest assigned value.") {
    LOG(INFO) << "Minimize the largest assigned value.";
    

    

    objective_var = solver.MakeMax(variables)->Var();
    objective = solver.MakeMinimize(objective_var, 1);
  } else if (data_objective == "Minimize the number of assigned values.") {
    LOG(INFO) << "Minimize the number of assigned values.";

    std::vector<IntVar*> cardinality;
    solver.MakeIntVarArray(static_cast<int>(values.size()), 0,
                           static_cast<int>(variables.size()), &cardinality);
    solver.AddConstraint(solver.MakeDistribute(variables, values, cardinality));
    std::vector<IntVar*> value_not_assigned;
    for (int val = 0; val < values.size(); ++val) {
      value_not_assigned.push_back(
          solver.MakeIsEqualCstVar(cardinality[val], 0));
    }
    CHECK(!value_not_assigned.empty());
    

    

    objective_var = solver.MakeSum(value_not_assigned)->Var();
    objective = solver.MakeMaximize(objective_var, 1);
  } else {
    LOG(FATAL) << "No right objective specified.";
    return;
  }
  monitors.push_back(objective);

  

  OrderingBuilder* ob = solver.RevAlloc(
      new OrderingBuilder(data_variables, ordered_constraints, variables,
                          violated_constraints, index_from_key));

  

  

  Solver::IntVarStrategy variable_strategy;
  ChooseVariableStrategy(&variable_strategy);
  

  DecisionBuilder* db;
  absl::flat_hash_map<int64_t, std::pair<int64_t, int64_t>> history;
  if (absl::GetFlag(FLAGS_value_evaluator) == "value_evaluator") {
    LOG(INFO) << "Using ValueEvaluator for value selection strategy.";
    Solver::IndexEvaluator2 index_evaluator2 = [&history](int64_t var,
                                                          int64_t value) {
      return ValueEvaluator(&history, var, value);
    };
    LOG(INFO) << "Using ValueEvaluator for value selection strategy.";
    db = solver.MakePhase(variables, variable_strategy, index_evaluator2);
  } else {
    LOG(INFO) << "Using Solver::ASSIGN_MIN_VALUE for value selection strategy.";
    db = solver.MakePhase(variables, variable_strategy,
                          Solver::ASSIGN_MIN_VALUE);
  }

  DecisionBuilder* final_db = solver.Compose(ob, db);

  

  CreateAdditionalMonitors(objective, &solver, &monitors);

  

  SolutionCollector* const collector = solver.MakeLastSolutionCollector();
  collector->Add(variables);
  collector->Add(objective_var);
  monitors.push_back(collector);

  

  LOG(INFO) << "Solving...";
  const int64_t time1 = solver.wall_time();
  solver.Solve(final_db, monitors);
  const int64_t time2 = solver.wall_time();

  

  if (absl::GetFlag(FLAGS_display_time)) {
    PrintElapsedTime(time1, time2);
  }
  

  if (absl::GetFlag(FLAGS_display_results)) {
    PrintResultsHard(collector, variables, objective_var, data_variables,
                     data_constraints, index_from_key, key_from_index);
  }
}



void SplitVariablesHardSoft(
    const absl::btree_map<int, FapVariable>& data_variables,
    absl::btree_map<int, FapVariable>* hard_variables,
    absl::btree_map<int, FapVariable>* soft_variables) {
  for (const auto& it : data_variables) {
    if (it.second.initial_position != -1) {
      if (it.second.hard) {
        CHECK_LT(it.second.mobility_cost, 0);
        hard_variables->insert_or_assign(it.first, it.second);
      } else {
        CHECK_GE(it.second.mobility_cost, 0);
        soft_variables->insert_or_assign(it.first, it.second);
      }
    }
  }
}



void SplitConstraintHardSoft(absl::Span<const FapConstraint> data_constraints,
                             std::vector<FapConstraint>* hard_constraints,
                             std::vector<FapConstraint>* soft_constraints) {
  for (const FapConstraint& ct : data_constraints) {
    if (ct.hard) {
      CHECK_LT(ct.weight_cost, 0);
      hard_constraints->push_back(ct);
    } else {
      CHECK_GE(ct.weight_cost, 0);
      soft_constraints->push_back(ct);
    }
  }
}





void PenalizeVariablesViolation(
    const absl::btree_map<int, FapVariable>& soft_variables,
    const absl::btree_map<int, int>& index_from_key,
    const std::vector<IntVar*>& variables, std::vector<IntVar*>* cost,
    Solver* solver) {
  for (const auto& it : soft_variables) {
    const int index = gtl::FindOrDie(index_from_key, it.first);
    CHECK_LT(index, variables.size());
    IntVar* const displaced = solver->MakeIsDifferentCstVar(
        variables[index], it.second.initial_position);
    IntVar* const weight =
        solver->MakeProd(displaced, it.second.mobility_cost)->Var();
    cost->push_back(weight);
  }
}



void PenalizeConstraintsViolation(
    absl::Span<const FapConstraint> constraints,
    absl::Span<const FapConstraint> soft_constraints,
    const absl::btree_map<int, int>& index_from_key,
    const std::vector<IntVar*>& variables, std::vector<IntVar*>* cost,
    std::vector<IntVar*>* violated_constraints, Solver* solver) {
  int violated_constraints_index = 0;
  for (const FapConstraint& ct : constraints) {
    CHECK_LT(violated_constraints_index, violated_constraints->size());
    if (!ct.hard) {
      

      break;
    }
    IntVar* const hard_violation = solver->MakeIntVar(0, 0);
    (*violated_constraints)[violated_constraints_index] = hard_violation;
    violated_constraints_index++;
  }

  for (const FapConstraint& ct : soft_constraints) {
    const int index1 = gtl::FindOrDie(index_from_key, ct.variable1);
    const int index2 = gtl::FindOrDie(index_from_key, ct.variable2);
    CHECK_LT(index1, variables.size());
    CHECK_LT(index2, variables.size());
    IntVar* const absolute_difference =
        solver
            ->MakeAbs(
                solver->MakeDifference(variables[index1], variables[index2]))
            ->Var();
    IntVar* violation = nullptr;
    if (ct.operation == ">") {
      violation = solver->MakeIsLessCstVar(absolute_difference, ct.value);
    } else if (ct.operation == "=") {
      violation = solver->MakeIsDifferentCstVar(absolute_difference, ct.value);
    } else {
      LOG(FATAL) << "Invalid operator detected.";
    }
    IntVar* const weight = solver->MakeProd(violation, ct.weight_cost)->Var();
    cost->push_back(weight);
    CHECK_LT(violated_constraints_index, violated_constraints->size());
    (*violated_constraints)[violated_constraints_index] = violation;
    violated_constraints_index++;
  }
  CHECK_EQ(violated_constraints->size(), constraints.size());
}







int SoftFapSolver(const absl::btree_map<int, FapVariable>& data_variables,
                  const std::vector<FapConstraint>& data_constraints,
                  absl::string_view 
,
                  absl::Span<const int> 
) {
  Solver solver("SoftFapSolver");
  std::vector<SearchMonitor*> monitors;

  

  absl::btree_map<int, FapVariable> hard_variables;
  absl::btree_map<int, FapVariable> soft_variables;
  SplitVariablesHardSoft(data_variables, &hard_variables, &soft_variables);

  

  

  std::vector<FapConstraint> ordered_constraints(data_constraints);
  std::sort(ordered_constraints.begin(), ordered_constraints.end(),
            ConstraintImpactComparator);
  std::vector<FapConstraint> hard_constraints;
  std::vector<FapConstraint> soft_constraints;
  SplitConstraintHardSoft(ordered_constraints, &hard_constraints,
                          &soft_constraints);

  

  std::vector<IntVar*> variables;
  absl::btree_map<int, int> index_from_key;
  std::vector<int> key_from_index;
  CreateModelVariables(data_variables, &solver, &variables, &index_from_key,
                       &key_from_index);

  

  CreateModelConstraints(hard_constraints, variables, index_from_key, &solver);

  

  std::vector<IntVar*> cost;
  std::vector<IntVar*> violated_constraints(ordered_constraints.size(),
                                            nullptr);
  PenalizeVariablesViolation(soft_variables, index_from_key, variables, &cost,
                             &solver);
  PenalizeConstraintsViolation(ordered_constraints, soft_constraints,
                               index_from_key, variables, &cost,
                               &violated_constraints, &solver);

  

  

  IntVar* objective_var = solver.MakeSum(cost)->Var();
  OptimizeVar* objective = solver.MakeMinimize(objective_var, 1);
  monitors.push_back(objective);

  

  OrderingBuilder* ob = solver.RevAlloc(
      new OrderingBuilder(data_variables, ordered_constraints, variables,
                          violated_constraints, index_from_key));

  

  

  DecisionBuilder* db;
  if (absl::GetFlag(FLAGS_variable_evaluator) == "variable_evaluator") {
    LOG(INFO) << "Using VariableEvaluator for variable selection strategy and "
                 "Solver::ASSIGN_MIN_VALUE for value selection strategy.";
    Solver::IndexEvaluator1 var_evaluator = [&key_from_index,
                                             &data_variables](int64_t index) {
      return VariableEvaluator(key_from_index, data_variables, index);
    };
    db = solver.MakePhase(variables, var_evaluator, Solver::ASSIGN_MIN_VALUE);
  } else {
    LOG(INFO) << "Using Solver::CHOOSE_FIRST_UNBOUND for variable selection "
                 "strategy and Solver::ASSIGN_MIN_VALUE for value selection "
                 "strategy.";
    db = solver.MakePhase(variables, Solver::CHOOSE_FIRST_UNBOUND,
                          Solver::ASSIGN_MIN_VALUE);
  }
  DecisionBuilder* final_db = solver.Compose(ob, db);

  

  CreateAdditionalMonitors(objective, &solver, &monitors);

  

  SolutionCollector* const collector = solver.MakeLastSolutionCollector();
  collector->Add(variables);
  collector->Add(objective_var);
  monitors.push_back(collector);

  

  LOG(INFO) << "Solving...";
  const int64_t time1 = solver.wall_time();
  solver.Solve(final_db, monitors);
  const int64_t time2 = solver.wall_time();

  int violation_sum =
      collector->Value(collector->solution_count() - 1, objective_var);
  

  if (absl::GetFlag(FLAGS_display_time)) {
    PrintElapsedTime(time1, time2);
  }
  

  if (absl::GetFlag(FLAGS_display_results)) {
    PrintResultsSoft(collector, variables, objective_var, hard_variables,
                     hard_constraints, soft_variables, soft_constraints,
                     index_from_key, key_from_index);
  }

  return violation_sum;
}

void SolveProblem(const absl::btree_map<int, FapVariable>& variables,
                  const std::vector<FapConstraint>& constraints,
                  absl::string_view objective, const std::vector<int>& values,
                  bool soft) {
  

  FapModelPrinter model_printer(variables, constraints, objective, values);
  model_printer.PrintFapObjective();
  model_printer.PrintFapVariables();
  model_printer.PrintFapConstraints();
  model_printer.PrintFapValues();
  

  if (!soft) {
    LOG(INFO) << "Running HardFapSolver";
    HardFapSolver(variables, constraints, objective, values);
  } else {
    LOG(INFO) << "Running SoftFapSolver";
    int violation = SoftFapSolver(variables, constraints, objective, values);
    if (violation == 0) {
      LOG(INFO) << "The instance is feasible. "
                   "Now the HardFapSolver will be executed.";
      LOG(INFO) << "Running HardFapSolver";
      HardFapSolver(variables, constraints, objective, values);
    }
  }
}

}  


int main(int argc, char** argv) {
  InitGoogle(argv[0], &argc, &argv, true);

  CHECK(!absl::GetFlag(FLAGS_directory).empty())
      << "Requires --directory=<directory name>";

  LOG(INFO) << "Solving instance in directory  "
            << absl::GetFlag(FLAGS_directory);
  

  absl::btree_map<int, operations_research::FapVariable> variables;
  std::vector<operations_research::FapConstraint> constraints;
  std::string objective;
  std::vector<int> values;
  absl::flat_hash_map<int, operations_research::FapComponent> components;
  operations_research::ParseInstance(
      absl::GetFlag(FLAGS_directory), absl::GetFlag(FLAGS_find_components),
      &variables, &constraints, &objective, &values, &components);
  if (!absl::GetFlag(FLAGS_find_components)) {
    operations_research::SolveProblem(variables, constraints, objective, values,
                                      absl::GetFlag(FLAGS_soft));
  } else {
    int component_id = 1;
    LOG(INFO) << "Number of components in the RLFAP graph "
              << components.size();
    for (const auto& component : components) {
      LOG(INFO) << "Solving Component " << component_id;
      operations_research::SolveProblem(component.second.variables,
                                        component.second.constraints, objective,
                                        values, absl::GetFlag(FLAGS_soft));
      component_id++;
    }
  }
  return EXIT_SUCCESS;
}
