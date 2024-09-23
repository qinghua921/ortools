
import { operations_research } from "../src";

test('ts-ortools', () =>
{
    const cp_model = new operations_research.sat.CpModelBuilder();


    const x = cp_model.NewBoolVar();

    const y = cp_model.NewBoolVar();
    cp_model.AddBoolOr([x, y.Not()]);

});