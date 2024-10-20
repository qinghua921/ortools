






























#include <cstdint>
#include <cstdlib>
#include <sstream>
#include <vector>

#include "ortools/base/logging.h"
#include "ortools/constraint_solver/constraint_solver.h"



namespace operations_research {

void NQueensCp(const int board_size) {
  

  

  Solver solver("N-Queens");
  


  

  std::vector<IntVar*> queens;
  queens.reserve(board_size);
  for (int i = 0; i < board_size; ++i) {
    queens.push_back(
        solver.MakeIntVar(0, board_size - 1, absl::StrCat("x", i)));
  }
  


  

  

  

  solver.AddConstraint(solver.MakeAllDifferent(queens));

  

  

  std::vector<IntVar*> diag_1;
  diag_1.reserve(board_size);
  std::vector<IntVar*> diag_2;
  diag_2.reserve(board_size);
  for (int i = 0; i < board_size; ++i) {
    diag_1.push_back(solver.MakeSum(queens[i], i)->Var());
    diag_2.push_back(solver.MakeSum(queens[i], -i)->Var());
  }
  solver.AddConstraint(solver.MakeAllDifferent(diag_1));
  solver.AddConstraint(solver.MakeAllDifferent(diag_2));
  


  

  DecisionBuilder* const db = solver.MakePhase(
      queens, Solver::CHOOSE_FIRST_UNBOUND, Solver::ASSIGN_MIN_VALUE);
  


  

  

  int num_solutions = 0;

  solver.NewSearch(db);
  while (solver.NextSolution()) {
    

    LOG(INFO) << "Solution " << num_solutions;
    for (int i = 0; i < board_size; ++i) {
      std::stringstream ss;
      for (int j = 0; j < board_size; ++j) {
        if (queens[j]->Value() == i) {
          

          ss << "Q";
        } else {
          ss << "_";
        }
        if (j != board_size - 1) ss << " ";
      }
      LOG(INFO) << ss.str();
    }
    num_solutions++;
  }
  solver.EndSearch();
  


  

  

  LOG(INFO) << "Statistics";
  LOG(INFO) << "  failures: " << solver.failures();
  LOG(INFO) << "  branches: " << solver.branches();
  LOG(INFO) << "  wall time: " << solver.wall_time() << " ms";
  LOG(INFO) << "  Solutions found: " << num_solutions;
  

}

}  


int main(int argc, char** argv) {
  int board_size = 8;
  if (argc > 1) {
    board_size = std::atoi(argv[1]);
  }
  operations_research::NQueensCp(board_size);
  return EXIT_SUCCESS;
}


