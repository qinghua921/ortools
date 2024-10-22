import { operations_research } from '../src'

function CpSatExample()
{

    //CpModelBuilder cp_model;

    //int64_t var_upper_bound = std::max({50, 45, 37});
    //const Domain domain(0, var_upper_bound);
    //const IntVar x = cp_model.NewIntVar(domain).WithName("x");
    //const IntVar y = cp_model.NewIntVar(domain).WithName("y");
    //const IntVar z = cp_model.NewIntVar(domain).WithName("z");

    //cp_model.AddLessOrEqual(2 * x + 7 * y + 3 * z, 50);
    //cp_model.AddLessOrEqual(3 * x - 5 * y + 7 * z, 45);
    //cp_model.AddLessOrEqual(5 * x + 2 * y - 6 * z, 37);

    //cp_model.Maximize(2 * x + 2 * y + 3 * z);

    //const CpSolverResponse response = Solve(cp_model.Build());

    //if (response.status() == CpSolverStatus::OPTIMAL ||
    //    response.status() == CpSolverStatus::FEASIBLE)
    //{

    //    LOG(INFO) << "Maximum of objective function: "
    //              << response.objective_value();
    //    LOG(INFO) << "x = " << SolutionIntegerValue(response, x);
    //    LOG(INFO) << "y = " << SolutionIntegerValue(response, y);
    //    LOG(INFO) << "z = " << SolutionIntegerValue(response, z);
    //}
    //else
    //{
    //    LOG(INFO) << "No solution found.";
    //}

    //LOG(INFO) << "Statistics";
    //LOG(INFO) << CpSolverResponseStats(response);

    const cp_model = new operations_research.sat.CpModelBuilder();
    const var_upper_bound = Math.max(50, 45, 37);
    const domain = new operations_research.Domain(0, var_upper_bound);
    const x = cp_model.NewIntVar(domain).WithName("x");
    const y = cp_model.NewIntVar(domain).WithName("y");
    const z = cp_model.NewIntVar(domain).WithName("z");

    cp_model.AddLessOrEqual(2 * x + 7 * y + 3 * z, 50);
    cp_model.AddLessOrEqual(3 * x - 5 * y + 7 * z, 45);
    cp_model.AddLessOrEqual(5 * x + 2 * y - 6 * z, 37);

    cp_model.Maximize(2 * x + 2 * y + 3 * z);

    const response = operations_research.sat.Solve(cp_model.Build());
}

CpSatExample();
