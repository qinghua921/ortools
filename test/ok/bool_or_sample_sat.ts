import { operations_research as op } from '../../src'

function test()
{
    let cp_model = new op.sat.CpModelBuilder();
    let x = cp_model.NewBoolVar();
    let y = cp_model.NewBoolVar();
    cp_model.AddBoolOr([x, y.Not()]);
}
test();
