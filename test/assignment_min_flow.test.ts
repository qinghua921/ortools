import { SimpleMinCostFlow, Status } from "../src/operations_research/GSimpleMinCostFlow";

test("assignment_min_flow", () =>
{
    let min_cost_flow = new SimpleMinCostFlow();
    let start_nodes = [0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2,
        3, 3, 3, 3, 4, 4, 4, 4, 5, 6, 7, 8];
    let end_nodes = [1, 2, 3, 4, 5, 6, 7, 8, 5, 6, 7, 8,
        5, 6, 7, 8, 5, 6, 7, 8, 9, 9, 9, 9];
    let capacities = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1];
    let unit_costs = [0, 0, 0, 0, 90, 76, 75, 70,
        35, 85, 55, 65, 125, 95, 90, 105,
        45, 110, 95, 115, 0, 0, 0, 0];

    let source = 0;
    let sink = 9;
    let tasks = 4;
    let supplies = [tasks, 0, 0, 0, 0, 0, 0, 0, 0, -tasks];

    for (let i = 0; i < start_nodes.length; ++i)
    {
        let arc = min_cost_flow.AddArcWithCapacityAndUnitCost(
            start_nodes[i], end_nodes[i], capacities[i], unit_costs[i]);
        expect(arc).toBe(i);
    }
    for (let i = 0; i < supplies.length; ++i)
    {
        min_cost_flow.SetNodeSupply(i, supplies[i]);
    }
    let status = min_cost_flow.Solve();
    expect(status).toBe(Status.OPTIMAL);
});