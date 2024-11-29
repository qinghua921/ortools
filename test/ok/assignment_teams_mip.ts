import { operations_research as op } from '../../src'

function test()
{
    let costs = [
        [90, 76, 75, 70],
        [35, 85, 55, 65],
        [125, 95, 90, 105],
        [45, 110, 95, 115],
        [60, 105, 80, 75],
        [45, 65, 110, 95],
    ];
    let num_workers = costs.length;
    let all_workers = Array.from({ length: num_workers }, (_, i) => i);
    let num_tasks = costs[0].length;
    let all_tasks = Array.from({ length: num_tasks }, (_, i) => i);
    let team1 = [0, 2, 4];
    let team2 = [1, 3, 5];
    let team_max = 2;
    let solver = op.MPSolver.CreateSolver("SCIP");
    if (!solver)
    {
        console.log("SCIP solver unavailable.");
        return;
    }
    let x = Array.from(
        { length: num_workers },
        (_, worker) => Array.from(
            { length: num_tasks },
            (_, task) => solver.MakeBoolVar(`x[${worker},${task}]`)));
    for (let worker of all_workers)
    {
        let worker_sum = new op.LinearExpr();
        for (let task of all_tasks)
        {
            worker_sum.operator_plus_eq(x[worker][task])
        }
        solver.MakeRowConstraint(op.operator_le(worker_sum, 1.0));
    }
    for (let task of all_tasks)
    {
        let task_sum = new op.LinearExpr();
        for (let worker of all_workers)
        {
            task_sum.operator_plus_eq(x[worker][task])
        }
        solver.MakeRowConstraint(op.operator_eq(task_sum, 1.0));
    }
    let team1_tasks = new op.LinearExpr();
    for (let worker of team1)
    {
        for (let task of all_tasks)
        {
            team1_tasks.operator_plus_eq(x[worker][task])
        }
    }
    solver.MakeRowConstraint(op.operator_le(team1_tasks, team_max));
    let team2_tasks = new op.LinearExpr();
    for (let worker of team2)
    {
        for (let task of all_tasks)
        {
            team2_tasks.operator_plus_eq(x[worker][task])
        }
    }
    solver.MakeRowConstraint(op.operator_le(team2_tasks, team_max));
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
    if (result_status != op.MPSolver.ResultStatus.OPTIMAL &&
        result_status != op.MPSolver.ResultStatus.FEASIBLE)
    {
        console.log("No solution found.");
    }
    console.log(`Total cost = ${objective.Value()}\n\n`);
    for (let worker of all_workers)
    {
        for (let task of all_tasks)
        {
            if (x[worker][task].solution_value() > 0.5)
            {
                console.log(`Worker ${worker} assigned to task ${task}.  Cost: ${costs[worker][task]}`);
            }
        }
    }
}

test();
