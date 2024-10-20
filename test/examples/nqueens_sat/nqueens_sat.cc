






























#include <stdlib.h>

#include <sstream>
#include <string>
#include <vector>

#include "absl/strings/numbers.h"
#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"
#include "ortools/sat/cp_model.pb.h"
#include "ortools/sat/cp_model_solver.h"
#include "ortools/sat/model.h"
#include "ortools/sat/sat_parameters.pb.h"
#include "ortools/util/sorted_interval_list.h"



namespace operations_research {
namespace sat {

void NQueensSat(const int board_size) {
  

  

  CpModelBuilder cp_model;
  


  

  

  

  std::vector<IntVar> queens;
  queens.reserve(board_size);
  Domain range(0, board_size - 1);
  for (int i = 0; i < board_size; ++i) {
    queens.push_back(
        cp_model.NewIntVar(range).WithName("x" + std::to_string(i)));
  }
  


  

  

  

  cp_model.AddAllDifferent(queens);

  

  std::vector<LinearExpr> diag_1;
  diag_1.reserve(board_size);
  std::vector<LinearExpr> diag_2;
  diag_2.reserve(board_size);
  for (int i = 0; i < board_size; ++i) {
    diag_1.push_back(queens[i] + i);
    diag_2.push_back(queens[i] - i);
  }
  cp_model.AddAllDifferent(diag_1);
  cp_model.AddAllDifferent(diag_2);
  


  

  int num_solutions = 0;
  Model model;
  model.Add(NewFeasibleSolutionObserver([&](const CpSolverResponse& response) {
    LOG(INFO) << "Solution " << num_solutions;
    for (int i = 0; i < board_size; ++i) {
      std::stringstream ss;
      for (int j = 0; j < board_size; ++j) {
        if (SolutionIntegerValue(response, queens[j]) == i) {
          

          ss << "Q";
        } else {
          ss << "_";
        }
        if (j != board_size - 1) ss << " ";
      }
      LOG(INFO) << ss.str();
    }
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
  int board_size = 8;
  if (argc > 1) {
    if (!absl::SimpleAtoi(argv[1], &board_size)) {
      LOG(INFO) << "Cannot parse '" << argv[1]
                << "', using the default value of 8.";
      board_size = 8;
    }
  }
  operations_research::sat::NQueensSat(board_size);
  return EXIT_SUCCESS;
}


