








































#include <stdlib.h>

#include <cstdint>

#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"
#include "ortools/sat/cp_model.pb.h"
#include "ortools/sat/cp_model_solver.h"
#include "ortools/sat/model.h"
#include "ortools/sat/sat_parameters.pb.h"
#include "ortools/util/sorted_interval_list.h"



namespace operations_research {
namespace sat {

void CPIsFunSat() {
  

  

  CpModelBuilder cp_model;
  


  

  const int64_t kBase = 10;

  

  Domain digit(0, kBase - 1);
  Domain non_zero_digit(1, kBase - 1);

  IntVar c = cp_model.NewIntVar(non_zero_digit).WithName("C");
  IntVar p = cp_model.NewIntVar(digit).WithName("P");
  IntVar i = cp_model.NewIntVar(non_zero_digit).WithName("I");
  IntVar s = cp_model.NewIntVar(digit).WithName("S");
  IntVar f = cp_model.NewIntVar(non_zero_digit).WithName("F");
  IntVar u = cp_model.NewIntVar(digit).WithName("U");
  IntVar n = cp_model.NewIntVar(digit).WithName("N");
  IntVar t = cp_model.NewIntVar(non_zero_digit).WithName("T");
  IntVar r = cp_model.NewIntVar(digit).WithName("R");
  IntVar e = cp_model.NewIntVar(digit).WithName("E");
  


  

  

  cp_model.AddAllDifferent({c, p, i, s, f, u, n, t, r, e});

  

  cp_model.AddEquality(
      c * kBase + p + i * kBase + s + f * kBase * kBase + u * kBase + n,
      kBase * kBase * kBase * t + kBase * kBase * r + kBase * u + e);
  


  

  Model model;
  int num_solutions = 0;
  model.Add(NewFeasibleSolutionObserver([&](const CpSolverResponse& response) {
    LOG(INFO) << "Solution " << num_solutions;
    LOG(INFO) << "C=" << SolutionIntegerValue(response, c) << " "
              << "P=" << SolutionIntegerValue(response, p) << " "
              << "I=" << SolutionIntegerValue(response, i) << " "
              << "S=" << SolutionIntegerValue(response, s) << " "
              << "F=" << SolutionIntegerValue(response, f) << " "
              << "U=" << SolutionIntegerValue(response, u) << " "
              << "N=" << SolutionIntegerValue(response, n) << " "
              << "T=" << SolutionIntegerValue(response, t) << " "
              << "R=" << SolutionIntegerValue(response, r) << " "
              << "E=" << SolutionIntegerValue(response, e);
    num_solutions++;
  }));
  


  

  

  SatParameters parameters;
  parameters.set_enumerate_all_solutions(true);
  model.Add(NewSatParameters(parameters));

  const CpSolverResponse response = SolveCpModel(cp_model.Build(), &model);
  LOG(INFO) << "Number of solutions found: " << num_solutions;
  


  

  

  LOG(INFO) << "Statistics";
  LOG(INFO) << CpSolverResponseStats(response);
  

}

}  

}  


int main(int argc, char** argv) {
  operations_research::sat::CPIsFunSat();
  return EXIT_SUCCESS;
}


