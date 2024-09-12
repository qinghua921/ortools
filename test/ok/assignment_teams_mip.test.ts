import { operations_research } from "../../src";

test('ts-ortools', () =>
{
    let costs =
        [
            [90, 76, 75, 70],
            [35, 85, 55, 65],
            [125, 95, 90, 105],
            [45, 110, 95, 115],
            [60, 105, 80, 75],
            [45, 65, 110, 95]
        ]

    let all_workers = [0, 1, 2, 3, 4, 5];

    let num_tasks = costs[0].length;
    let all_tasks = Array.from({ length: num_tasks }, (_, i) => i);

    // const std::vector< int64_t > team1 = { { 0, 2, 4 } };
    let team1 = [0, 2, 4];
    // const std::vector< int64_t > team2 = { { 1, 3, 5 } };
    let team2 = [1, 3, 5];

    let team_max = 2;

    let solver = operations_research.MPSolver.CreateSolver("SCIP");

    let x = [];
    for (let worker of all_workers)
    {
        let row = [];
        for (let task of all_tasks)
        {
            row.push(solver.MakeBoolVar(
                `x[${worker},${task}]`));
        }
        x.push(row);
    }

    for (let worker of all_workers)
    {
        let worker_sum = new operations_research.LinearExpr();
        for (let task of all_tasks)
        {

            worker_sum.operator_plus_equals(x[worker][task]);

        }
        solver.MakeRowConstraint(operations_research.operator_less_equals(worker_sum, 1.0));
    }
    for (let task of all_tasks)
    {
        let task_sum = new operations_research.LinearExpr();
        for (let worker of all_workers)
        {
            task_sum.operator_plus_equals(x[worker][task]);
        }
        solver.MakeRowConstraint(operations_research.operator_equals(task_sum, 1.0));
    }

    let team1_tasks = new operations_research.LinearExpr();
    for (let worker of team1)
    {
        for (let task of all_tasks)
        {
            team1_tasks.operator_plus_equals(x[worker][task]);
        }
    }
    solver.MakeRowConstraint(operations_research.operator_less_equals(team1_tasks, team_max));

    let team2_tasks = new operations_research.LinearExpr();
    for (let worker of team2)
    {
        for (let task of all_tasks)
        {
            team2_tasks.operator_plus_equals(x[worker][task]);
        }
    }
    solver.MakeRowConstraint(operations_research.operator_less_equals(team2_tasks, team_max));


    let objective = solver.MutableObjective();
    for (let worker of all_workers)
    {
        for (let task of all_tasks)
        {
            objective.SetCoefficient(x[worker][task], costs[worker][task]);
        }
    }
    objective.SetMinimization();


    let result_status = solver.Solve();

    expect(result_status).toBe(operations_research.MPSolver.ResultStatus.OPTIMAL);
}
);