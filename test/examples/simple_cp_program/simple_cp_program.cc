




























#include <ostream>
#include <string>

#include "ortools/constraint_solver/constraint_solver.h"



namespace operations_research {

void SimpleCpProgram() {
  

  

  Solver solver("CpSimple");
  


  

  

  const int64_t num_vals = 3;
  IntVar* const x = solver.MakeIntVar(0, num_vals - 1, "x");
  IntVar* const y = solver.MakeIntVar(0, num_vals - 1, "y");
  IntVar* const z = solver.MakeIntVar(0, num_vals - 1, "z");
  


  

  

  solver.AddConstraint(solver.MakeAllDifferent({x, y}));
  LOG(INFO) << "Number of constraints: "
            << std::to_string(solver.constraints());
  


  

  

  DecisionBuilder* const db = solver.MakePhase(
      {x, y, z}, Solver::CHOOSE_FIRST_UNBOUND, Solver::ASSIGN_MIN_VALUE);
  


  

  

  int count = 0;
  solver.NewSearch(db);
  while (solver.NextSolution()) {
    ++count;
    LOG(INFO) << "Solution " << count << ":" << std::endl
              << " x=" << x->Value() << " y=" << y->Value()
              << " z=" << z->Value();
  }
  solver.EndSearch();
  LOG(INFO) << "Number of solutions found: " << solver.solutions();
  


  

  LOG(INFO) << "Advanced usage:" << std::endl
            << "Problem solved in " << std::to_string(solver.wall_time())
            << "ms" << std::endl
            << "Memory usage: " << std::to_string(Solver::MemoryUsage())
            << "bytes";
  

}

}  


int main(int 
, char* 
[]) {
  operations_research::SimpleCpProgram();
  return EXIT_SUCCESS;
}


