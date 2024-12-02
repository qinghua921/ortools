import { operations_research as op } from '../src'


function test()
{
    // CpModelBuilder cp_model;

    // const int64_t kBase = 10;

    // Domain digit(0, kBase - 1);
    // Domain non_zero_digit(1, kBase - 1);

    // IntVar c = cp_model.NewIntVar(non_zero_digit).WithName("C");
    // IntVar p = cp_model.NewIntVar(digit).WithName("P");
    // IntVar i = cp_model.NewIntVar(non_zero_digit).WithName("I");
    // IntVar s = cp_model.NewIntVar(digit).WithName("S");
    // IntVar f = cp_model.NewIntVar(non_zero_digit).WithName("F");
    // IntVar u = cp_model.NewIntVar(digit).WithName("U");
    // IntVar n = cp_model.NewIntVar(digit).WithName("N");
    // IntVar t = cp_model.NewIntVar(non_zero_digit).WithName("T");
    // IntVar r = cp_model.NewIntVar(digit).WithName("R");
    // IntVar e = cp_model.NewIntVar(digit).WithName("E");

    // cp_model.AddAllDifferent({c, p, i, s, f, u, n, t, r, e});

    // cp_model.AddEquality(
    //     c * kBase + p + i * kBase + s + f * kBase * kBase + u * kBase + n,
    //     kBase * kBase * kBase * t + kBase * kBase * r + kBase * u + e
    // );

    // Model model;
    // int num_solutions = 0;
    // model.Add(NewFeasibleSolutionObserver([&](const CpSolverResponse &response)
    //                                       {
    // LOG(INFO) << "Solution " << num_solutions;
    // LOG(INFO) << "C=" << SolutionIntegerValue(response, c) << " "
    //           << "P=" << SolutionIntegerValue(response, p) << " "
    //           << "I=" << SolutionIntegerValue(response, i) << " "
    //           << "S=" << SolutionIntegerValue(response, s) << " "
    //           << "F=" << SolutionIntegerValue(response, f) << " "
    //           << "U=" << SolutionIntegerValue(response, u) << " "
    //           << "N=" << SolutionIntegerValue(response, n) << " "
    //           << "T=" << SolutionIntegerValue(response, t) << " "
    //           << "R=" << SolutionIntegerValue(response, r) << " "
    //           << "E=" << SolutionIntegerValue(response, e);
    // num_solutions++; }));

    // SatParameters parameters;
    // parameters.set_enumerate_all_solutions(true);
    // model.Add(NewSatParameters(parameters));

    // const CpSolverResponse response = SolveCpModel(cp_model.Build(), &model);
    // LOG(INFO) << "Number of solutions found: " << num_solutions;

    // LOG(INFO) << "Statistics";
    // LOG(INFO) << CpSolverResponseStats(response);

    let cp_model = new op.sat.CpModelBuilder();
    let kBase = 10;

    let digit = new op.Domain(0, kBase - 1);
    let non_zero_digit = new op.Domain(1, kBase - 1);

    let c = cp_model.NewIntVar(non_zero_digit).WithName("C");
    let p = cp_model.NewIntVar(digit).WithName("P");
    let i = cp_model.NewIntVar(non_zero_digit).WithName("I");
    let s = cp_model.NewIntVar(digit).WithName("S");
    let f = cp_model.NewIntVar(non_zero_digit).WithName("F");
    let u = cp_model.NewIntVar(digit).WithName("U");
    let n = cp_model.NewIntVar(digit).WithName("N");
    let t = cp_model.NewIntVar(non_zero_digit).WithName("T");
    let r = cp_model.NewIntVar(digit).WithName("R");
    let e = cp_model.NewIntVar(digit).WithName("E");

    cp_model.AddAllDifferent([c, p, i, s, f, u, n, t, r, e]);

    let ls = op.sat.operator_times(c, kBase);
    ls = op.sat.operator_plus(ls, p);
    ls = op.sat.operator_plus(ls, op.sat.operator_times(i, kBase));
    ls = op.sat.operator_plus(ls, s);
    ls = op.sat.operator_plus(ls, op.sat.operator_times(f, kBase * kBase));
    ls = op.sat.operator_plus(ls, op.sat.operator_times(u, kBase));
    ls = op.sat.operator_plus(ls, n);

    let rs = op.sat.operator_times(kBase * kBase * kBase, t);
    rs = op.sat.operator_plus(rs, op.sat.operator_times(kBase * kBase, r));
    rs = op.sat.operator_plus(rs, op.sat.operator_times(kBase, u));
    rs = op.sat.operator_plus(rs, e);
    cp_model.AddEquality(ls, rs);

    let model = new op.sat.Model();
    let num_solutions = 0;
    model.Add(op.sat.NewFeasibleSolutionObserver((response) => 
    {
        console.log("Solution " + num_solutions);
        console.log("C=" + op.sat.SolutionIntegerValue(response, c) + " " +
            "P=" + op.sat.SolutionIntegerValue(response, p) + " " +
            "I=" + op.sat.SolutionIntegerValue(response, i) + " " +
            "S=" + op.sat.SolutionIntegerValue(response, s) + " " +
            "F=" + op.sat.SolutionIntegerValue(response, f) + " " +
            "U=" + op.sat.SolutionIntegerValue(response, u) + " " +
            "N=" + op.sat.SolutionIntegerValue(response, n) + " " +
            "T=" + op.sat.SolutionIntegerValue(response, t) + " " +
            "R=" + op.sat.SolutionIntegerValue(response, r) + " " +
            "E=" + op.sat.SolutionIntegerValue(response, e));
        num_solutions++;
    }));

    let parameters = new op.sat.SatParameters();
    parameters.set_enumerate_all_solutions(true);
    model.Add(op.sat.NewSatParameters(parameters));

    let response = op.sat.SolveCpModel(cp_model.Build(), model);
    console.log("Number of solutions found: " + num_solutions);

    console.log("Statistics");
    console.log(op.sat.CpSolverResponseStats(response));




}
test();
