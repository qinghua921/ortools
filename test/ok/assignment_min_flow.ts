import { operations_research as op } from '../../src'


function test()
{
    let min_cost_flow = new op.SimpleMinCostFlow();
    let start_nodes = [0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 6, 7, 8];
    let end_nodes = [1, 2, 3, 4, 5, 6, 7, 8, 5, 6, 7, 8, 5, 6, 7, 8, 5, 6, 7, 8, 9, 9, 9, 9];
    let capacities = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1];
    let unit_costs = [0, 0, 0, 0, 90, 76, 75, 70, 35, 85, 55, 65, 125, 95, 90, 105, 45, 110, 95, 115, 0, 0, 0, 0];
    let source = 0;
    let sink = 9;
    let tasks = 4;
    let supplies = [tasks, 0, 0, 0, 0, 0, 0, 0, 0, -tasks];
    for (let i = 0; i < start_nodes.length; ++i)
    {
        let arc = min_cost_flow.AddArcWithCapacityAndUnitCost(
            start_nodes[i], end_nodes[i], capacities[i], unit_costs[i]
        );
        if (arc != i) console.log("Internal error");
    }

    for (let i = 0; i < supplies.length; ++i)
    {
        min_cost_flow.SetNodeSupply(i, supplies[i]);
    }

    let status = min_cost_flow.Solve();

    if (status == op.SimpleMinCostFlow.Status.OPTIMAL)
    {
        console.log("Total cost: " + min_cost_flow.OptimalCost());
        console.log("");
        for (let i = 0; i < min_cost_flow.NumArcs(); ++i)
        {
            if (min_cost_flow.Tail(i) != source && min_cost_flow.Head(i) != sink)
            {
                if (min_cost_flow.Flow(i) > 0)
                {
                    console.log("Worker " + min_cost_flow.Tail(i)
                        + " assigned to task " + min_cost_flow.Head(i)
                        + " Cost: " + min_cost_flow.UnitCost(i));
                }
            }
        }
    }
}

test();
