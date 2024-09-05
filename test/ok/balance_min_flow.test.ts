import { operations_research } from "../../src";

test('assignment_groups_mip', () =>
{
  let min_cost_flow = new operations_research.SimpleMinCostFlow();
  let team_A = [1, 3, 5];
  let team_B = [2, 4, 6];
  let start_nodes = [
    0, 0, 11, 11, 11, 12, 12, 12, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3,
    3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 7, 8, 9, 10];
  let end_nodes = [
    11, 12, 1, 3, 5, 2, 4, 6, 7, 8, 9, 10, 7, 8, 9, 10, 7, 8,
    9, 10, 7, 8, 9, 10, 7, 8, 9, 10, 7, 8, 9, 10, 13, 13, 13, 13];
  let capacities = [2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1];

  let unit_costs = [
    0, 0, 0, 0, 0, 0, 0, 0, 90, 76, 75, 70,
    35, 85, 55, 65, 125, 95, 90, 105, 45, 110, 95, 115,
    60, 105, 80, 75, 45, 65, 110, 95, 0, 0, 0, 0]

  let source = 0;
  let sink = 13;
  let tasks = 4;
  let supplies = [tasks, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -tasks];

  for (let i = 0; i < start_nodes.length; i++)
  {
    let arc = min_cost_flow.AddArcWithCapacityAndUnitCost(
      start_nodes[i], end_nodes[i], capacities[i], unit_costs[i]);
    if (arc != i) console.log("Internal error");
  }

  for (let i = 0; i < supplies.length; i++)
  {
    min_cost_flow.SetNodeSupply(i, supplies[i]);
  }

  let status = min_cost_flow.Solve();
  expect(status).toBe(operations_research.SimpleMinCostFlow.Status.OPTIMAL);


})


