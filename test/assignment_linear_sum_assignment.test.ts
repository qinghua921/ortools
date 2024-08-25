import { SimpleLinearSumAssignment, Status } from "../src/operations_research/GSimpleLinearSumAssignment";

test("assignment_groups_sat", () =>
{
    let assignment = new SimpleLinearSumAssignment();
    let num_workers = 4;
    let all_workers = Array.from({ length: num_workers }, (_, i) => i);

    let num_tasks = 4;
    let all_tasks = Array.from({ length: num_tasks }, (_, i) => i);

    let costs = [
        [90, 76, 75, 70],
        [35, 85, 55, 65],
        [125, 95, 90, 105],
        [45, 110, 95, 115]
    ];

    for (let w of all_workers)
    {
        for (let t of all_tasks)
        {
            if (costs[w][t])
            {
                assignment.AddArcWithCost(w, t, costs[w][t]);
            }
        }
    }

    let status = assignment.Solve();
    expect(status).toBe(Status.OPTIMAL);

});