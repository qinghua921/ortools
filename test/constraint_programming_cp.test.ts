
// #include "ortools/base/init_google.h"
// #include "ortools/base/logging.h"
// #include "ortools/constraint_solver/constraint_solver.h"

// namespace operations_research
// {
// void RunConstraintProgrammingExample()
// {
//     // Instantiate the solver.
//     Solver        solver( "ConstraintProgrammingExample" );
//     const int64_t numVals = 3;

//     // Define decision variables.
//     IntVar* const x = solver.MakeIntVar( 0, numVals - 1, "x" );
//     IntVar* const y = solver.MakeIntVar( 0, numVals - 1, "y" );
//     IntVar* const z = solver.MakeIntVar( 0, numVals - 1, "z" );

//     // Define constraints.
//     std::vector< IntVar* > xyvars = { x, y };
//     solver.AddConstraint( solver.MakeAllDifferent( xyvars ) );

//     LOG( INFO ) << "Number of constraints: " << solver.constraints();

//     // Create decision builder to search for solutions.
//     std::vector< IntVar* > allvars = { x, y, z };
//     DecisionBuilder* const db      = solver.MakePhase(
//         allvars, Solver::CHOOSE_FIRST_UNBOUND, Solver::ASSIGN_MIN_VALUE );

//     solver.NewSearch( db );
//     while ( solver.NextSolution() )
//     {
//         LOG( INFO ) << "Solution"
//                     << ": x = " << x->Value() << "; y = " << y->Value()
//                     << "; z = " << z->Value();
//     }
//     solver.EndSearch();
//     LOG( INFO ) << "Number of solutions: " << solver.solutions();
//     LOG( INFO ) << "";
//     LOG( INFO ) << "Advanced usage:";
//     LOG( INFO ) << "Problem solved in " << solver.wall_time() << "ms";
//     LOG( INFO ) << "Memory usage: " << Solver::MemoryUsage() << " bytes";
// }
// }  // namespace operations_research

// int main( int argc, char** argv )
// {
//     google::InitGoogleLogging( argv[ 0 ] );
//     absl::SetFlag( &FLAGS_stderrthreshold, 0 );
//     operations_research::RunConstraintProgrammingExample();
//     return EXIT_SUCCESS;
// }
import { operations_research } from "../src";

test('assignment_groups_mip', () =>
{
    let solver = new operations_research.Solver("assignment_groups_mip");
    let num_vals = 3;
    let x = solver.MakeIntVar(0, num_vals - 1, "x");
    let y = solver.MakeIntVar(0, num_vals - 1, "y");
    let z = solver.MakeIntVar(0, num_vals - 1, "z");
    let xyvars = [x, y];
    solver.AddConstraint(solver.MakeAllDifferent(xyvars));
    let allvars = [x, y, z];
    let db = solver.MakePhase_01(allvars,
        operations_research.Solver.IntVarStrategy.CHOOSE_FIRST_UNBOUND,
        operations_research.Solver.IntValueStrategy.ASSIGN_MIN_VALUE);

    solver.NewSearch(db);

    while (solver.NextSolution())
    {
        console.log("Solution");
        console.log("x = " + x.Value() + "; y = " + y.Value() + "; z = " + z.Value());
    }

    solver.EndSearch();
    console.log("Number of solutions: " + solver.solutions());
    console.log("Advanced usage:");
    console.log("Problem solved in " + solver.wall_time() + "ms");
    console.log("Memory usage: " + operations_research.Solver.MemoryUsage() + " bytes");    
    
});