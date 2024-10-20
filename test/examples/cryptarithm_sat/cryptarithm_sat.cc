



























#include "ortools/sat/cp_model.h"

namespace operations_research {
namespace sat {

void SendMoreMoney() {
  CpModelBuilder cp_model;

  

  Domain all_digits(0, 9);
  Domain non_zero_digits(1, 9);
  

  

  const IntVar s = cp_model.NewIntVar(non_zero_digits);
  const IntVar e = cp_model.NewIntVar(all_digits);
  const IntVar n = cp_model.NewIntVar(all_digits);
  const IntVar d = cp_model.NewIntVar(all_digits);
  

  const IntVar m = cp_model.NewIntVar(non_zero_digits);
  const IntVar o = cp_model.NewIntVar(all_digits);
  const IntVar r = cp_model.NewIntVar(all_digits);
  const IntVar y = cp_model.NewIntVar(all_digits);

  

  

  const BoolVar c0 = cp_model.NewBoolVar();
  const BoolVar c1 = cp_model.NewBoolVar();
  const BoolVar c2 = cp_model.NewBoolVar();
  const BoolVar c3 = cp_model.NewBoolVar();

  

  cp_model.AddAllDifferent({s, e, n, d, m, o, r, y});

  

  cp_model.AddEquality(c0, m);

  

  cp_model.AddEquality(c1 + s + m, o + 10 * c0);

  

  cp_model.AddEquality(c2 + e + o, n + 10 * c1);

  

  cp_model.AddEquality(c3 + n + r, e + 10 * c2);

  

  cp_model.AddEquality(d + e, y + 10 * c3);

  

  const CpSolverResponse response = Solve(cp_model.Build());
  LOG(INFO) << CpSolverResponseStats(response);
  LOG(INFO) << "s: " << SolutionIntegerValue(response, s);
  LOG(INFO) << "e: " << SolutionIntegerValue(response, e);
  LOG(INFO) << "n: " << SolutionIntegerValue(response, n);
  LOG(INFO) << "d: " << SolutionIntegerValue(response, d);
  LOG(INFO) << "m: " << SolutionIntegerValue(response, m);
  LOG(INFO) << "o: " << SolutionIntegerValue(response, o);
  LOG(INFO) << "r: " << SolutionIntegerValue(response, r);
  LOG(INFO) << "y: " << SolutionIntegerValue(response, y);
}

}  

}  


int main() {
  operations_research::sat::SendMoreMoney();
  return EXIT_SUCCESS;
}
