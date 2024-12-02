import { operations_research as op } from '../../src'
function test()
{
    function CostasHard(dim: number)
    {
        let cp_model = new op.sat.CpModelBuilder();
        let vars: op.sat.IntVar[] = [];
        let domain = new op.Domain(1, dim);
        for (let i = 0; i < dim; ++i)
        {
            vars.push(cp_model.NewIntVar(domain).WithName(`var_${i}`));
        }
        cp_model.AddAllDifferent(vars);
        for (let i = 1; i < dim; ++i)
        {
            let subset: op.sat.IntVar[] = [];
            let difference_domain = new op.Domain(-dim, dim);
            for (let j = 0; j < dim - i; ++j)
            {
                let diff = cp_model.NewIntVar(difference_domain);
                subset.push(diff);
                cp_model.AddEquality(diff, op.sat.operator_minus(vars[j + i], vars[j]));
            }
            cp_model.AddAllDifferent(subset);
        }
        let model = new op.sat.Model();
        let response = op.sat.SolveCpModel(cp_model.Build(), model);
        if (response.status() === op.sat.CpSolverStatus.OPTIMAL)
        {
            let costas_matrix: number[] = [];
            let output = "";
            for (let n = 0; n < dim; ++n)
            {
                let v = op.sat.SolutionIntegerValue(response, vars[n]);
                costas_matrix.push(v);
                output += ` ${v}`;
            }
            console.log(output + ` (${response.wall_time()} s)`);
        }
        else
            console.log("No solution found.");
    }
    function CostasBool(dim: number)
    {
        let cp_model = new op.sat.CpModelBuilder();
        let vars: op.sat.BoolVar[][] = [];
        let transposed_vars: op.sat.BoolVar[][] = [];
        for (let i = 0; i < dim; ++i)
        {
            vars[i] = [];
            transposed_vars[i] = [];
        }
        for (let i = 0; i < dim; ++i)
        {
            for (let j = 0; j < dim; ++j)
            {
                let var_ = cp_model.NewBoolVar();
                vars[i].push(var_);
                transposed_vars[j].push(var_);
            }
        }
        for (let i = 0; i < dim; ++i)
        {
            cp_model.AddEquality(op.sat.LinearExpr.Sum(vars[i]), 1);
            cp_model.AddEquality(op.sat.LinearExpr.Sum(transposed_vars[i]), 1);
        }
        for (let step = 1; step < dim; ++step)
        {
            for (let diff = 1; diff < dim - 1; ++diff)
            {
                let positive_diffs: op.sat.BoolVar[] = [];
                let negative_diffs: op.sat.BoolVar[] = [];
                for (let var_ = 0; var_ < dim - step; ++var_)
                {
                    for (let value = 0; value < dim - diff; ++value)
                    {
                        let pos = cp_model.NewBoolVar();
                        let neg = cp_model.NewBoolVar();
                        positive_diffs.push(pos);
                        negative_diffs.push(neg);
                        cp_model.AddBoolOr([
                            vars[var_][value].Not(),
                            vars[var_ + step][value + diff].Not(),
                            pos
                        ]);
                        cp_model.AddBoolOr([
                            vars[var_][value + diff].Not(),
                            vars[var_ + step][value].Not(),
                            neg
                        ]);
                    }
                }
                cp_model.AddLessOrEqual(op.sat.LinearExpr.Sum(positive_diffs), 1);
                cp_model.AddLessOrEqual(op.sat.LinearExpr.Sum(negative_diffs), 1);
            }
        }
        let model = new op.sat.Model();
        let response = op.sat.SolveCpModel(cp_model.Build(), model);
        if (response.status() === op.sat.CpSolverStatus.OPTIMAL)
        {
            let costas_matrix: number[] = [];
            let output = "";
            for (let n = 0; n < dim; ++n)
            {
                for (let v = 0; v < dim; ++v)
                {
                    if (op.sat.SolutionBooleanValue(response, vars[n][v]))
                    {
                        costas_matrix.push(v + 1);
                        output += ` ${v + 1}`;
                        break;
                    }
                }
            }
            console.log(output + ` (${response.wall_time()} s)`);
        }
        else
            console.log("No solution found.");
    }
    function CostasBoolSoft(dim: number)
    {
        let cp_model = new op.sat.CpModelBuilder();
        let vars: op.sat.BoolVar[][] = [];
        let transposed_vars: op.sat.BoolVar[][] = [];
        for (let i = 0; i < dim; ++i)
        {
            vars[i] = [];
            transposed_vars[i] = [];
        }
        for (let i = 0; i < dim; ++i)
        {
            for (let j = 0; j < dim; ++j)
            {
                let var_ = cp_model.NewBoolVar();
                vars[i].push(var_);
                transposed_vars[j].push(var_);
            }
        }
        for (let i = 0; i < dim; ++i)
        {
            cp_model.AddEquality(op.sat.LinearExpr.Sum(vars[i]), 1);
            cp_model.AddEquality(op.sat.LinearExpr.Sum(transposed_vars[i]), 1);
        }
        let all_violations: op.sat.IntVar[] = [];
        for (let step = 1; step < dim; ++step)
        {
            for (let diff = 1; diff < dim - 1; ++diff)
            {
                let positive_diffs: op.sat.BoolVar[] = [];
                let negative_diffs: op.sat.BoolVar[] = [];
                for (let var_ = 0; var_ < dim - step; ++var_)
                {
                    for (let value = 0; value < dim - diff; ++value)
                    {
                        let pos = cp_model.NewBoolVar();
                        let neg = cp_model.NewBoolVar();
                        positive_diffs.push(pos);
                        negative_diffs.push(neg);
                        cp_model.AddBoolOr([
                            vars[var_][value].Not(),
                            vars[var_ + step][value + diff].Not(),
                            pos
                        ]);
                        cp_model.AddBoolOr([
                            vars[var_][value + diff].Not(),
                            vars[var_ + step][value].Not(),
                            neg
                        ]);
                    }
                }
                let pos_var = cp_model.NewIntVar(new op.Domain(0, positive_diffs.length));
                let neg_var = cp_model.NewIntVar(new op.Domain(0, negative_diffs.length));
                cp_model.AddGreaterOrEqual(pos_var, op.sat.operator_minus(op.sat.LinearExpr.Sum(positive_diffs), 1));
                cp_model.AddGreaterOrEqual(neg_var, op.sat.operator_minus(op.sat.LinearExpr.Sum(negative_diffs), 1));
                all_violations.push(pos_var);
                all_violations.push(neg_var);
            }
        }
        console.log("all_violations.length", all_violations.length);
        cp_model.Minimize(op.sat.LinearExpr.Sum(all_violations));
        let model = new op.sat.Model();
        let response = op.sat.SolveCpModel(cp_model.Build(), model);
        if (response.status() === op.sat.CpSolverStatus.OPTIMAL)
        {
            let costas_matrix: number[] = [];
            let output = "";
            for (let n = 0; n < dim; ++n)
            {
                for (let v = 0; v < dim; ++v)
                {
                    if (op.sat.SolutionBooleanValue(response, vars[n][v]))
                    {
                        costas_matrix.push(v + 1);
                        output += ` ${v + 1}`;
                        break;
                    }
                }
            }
            console.log(output + ` (${response.wall_time()} s)`);
        }
        else
            console.log("No solution found.");
    }
    let min = 1;
    let max = 10;
    for (let size = min; size <= max; ++size)
    {
        CostasHard(size);
        CostasBool(size);
        CostasBoolSoft(size);
    }
}
test();
