import { operations_research } from "../../src";


test('ts-ortools', () =>
{
  let assignment = new operations_research.SimpleLinearSumAssignment();

  let num_workers = 4;
  let all_workers = [0, 1, 2, 3];

  let num_tasks = 4;
  let all_tasks = [0, 1, 2, 3];

  let costs = [
    [90, 76, 75, 70],
    [35, 85, 55, 65],
    [125, 95, 90, 105],
    [45, 110, 95, 115]
  ];

  for (let w = 0; w < num_workers; w++)
  {
    for (let t = 0; t < num_tasks; t++)
    {
      if (costs[w][t])
      {
        assignment.AddArcWithCost(w, t, costs[w][t]);
      }
    }
  }
  let status = assignment.Solve();
  expect(status).toBe(operations_research.SimpleLinearSumAssignment.Status.OPTIMAL);
});
