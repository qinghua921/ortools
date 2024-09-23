import { operations_research } from "../src";

test('ts-ortools', () =>
{

  // LOG( INFO ) << "Google OR-Tools version : " << OrToolsVersion::VersionString();

  // // [START solver]
  // // Create the linear solver with the GLOP backend.
  // std::unique_ptr< MPSolver > solver( MPSolver::CreateSolver( "GLOP" ) );
  // if ( !solver )
  // {
  //     LOG( WARNING ) << "Could not create solver GLOP";
  //     return;
  // }
  // // [END solver]

  // // [START variables]
  // // Create the variables x and y.
  // MPVariable* const x = solver->MakeNumVar( 0.0, 1, "x" );
  // MPVariable* const y = solver->MakeNumVar( 0.0, 2, "y" );

  // LOG( INFO ) << "Number of variables = " << solver->NumVariables();
  // // [END variables]

  // // [START constraints]
  // // Create a linear constraint, x + y <= 2.
  // const double        infinity = solver->infinity();
  // MPConstraint* const ct       = solver->MakeRowConstraint( -infinity, 2.0, "ct" );
  // ct->SetCoefficient( x, 1 );
  // ct->SetCoefficient( y, 1 );

  // LOG( INFO ) << "Number of constraints = " << solver->NumConstraints();
  // // [END constraints]

  // // [START objective]
  // // Create the objective function, 3 * x + y.
  // MPObjective* const objective = solver->MutableObjective();
  // objective->SetCoefficient( x, 3 );
  // objective->SetCoefficient( y, 1 );
  // objective->SetMaximization();
  // // [END objective]

  // // [START solve]
  // LOG( INFO ) << "Solving with " << solver->SolverVersion();
  // const MPSolver::ResultStatus result_status = solver->Solve();
  // // [END solve]

  // // [START print_solution]
  // // Check that the problem has an optimal solution.
  // LOG( INFO ) << "Status: " << result_status;
  // if ( result_status != MPSolver::OPTIMAL )
  // {
  //     LOG( INFO ) << "The problem does not have an optimal solution!";
  //     if ( result_status == MPSolver::FEASIBLE )
  //     {
  //         LOG( INFO ) << "A potentially suboptimal solution was found";
  //     }
  //     else
  //     {
  //         LOG( WARNING ) << "The solver could not solve the problem.";
  //         return;
  //     }
  // }

  // LOG( INFO ) << "Solution:";
  // LOG( INFO ) << "Objective value = " << objective->Value();
  // LOG( INFO ) << "x = " << x->solution_value();
  // LOG( INFO ) << "y = " << y->solution_value();
  // // [END print_solution]

  // // [START advanced]
  // LOG( INFO ) << "Advanced usage:";
  // LOG( INFO ) << "Problem solved in " << solver->wall_time() << " milliseconds";
  // LOG( INFO ) << "Problem solved in " << solver->iterations() << " iterations";
  // // [END advanced]

  console.log("Google OR-Tools version : " + operations_research.OrToolsVersion.VersionString())
  // Create the linear solver with the GLOP backend.
  const solver = operations_research.MPSolver.CreateSolver("GLOP");
  if (!solver)
  {
    console.log("Could not create solver GLOP");
    return;
  }

  // Create the variables x and y.
  const x = solver.MakeNumVar(0.0, 1, "x");
  const y = solver.MakeNumVar(0.0, 2, "y");
  console.log("Number of variables = " + solver.NumVariables());
  
  // Create a linear constraint, x + y <= 2.
  const infinity = solver.infinity();
  const ct = solver.MakeRowConstraint(-infinity, 2.0, "ct");
  ct.SetCoefficient(x, 1);
  ct.SetCoefficient(y, 1);
  console.log("Number of constraints = " + solver.NumConstraints());


});