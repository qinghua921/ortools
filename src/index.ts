// operations_research/GFunc.ts 
import { operator_EQ, operator_GEQ, operator_LEQ } from "./operations_research/GFunc"
// operations_research/GLinearExpr.ts 
import { LinearExpr } from "./operations_research/GLinearExpr"
// operations_research/GLinearRange.ts 
import { LinearRange } from "./operations_research/GLinearRange"
// operations_research/GMPConstraint.ts 
import { MPConstraint } from "./operations_research/GMPConstraint"
// operations_research/GMPObjective.ts 
import { MPObjective } from "./operations_research/GMPObjective"
// operations_research/GMPSolver.ts 
import { MPSolver } from "./operations_research/GMPSolver"
// operations_research/GMPSolverParameters.ts 
import { DoubleParam } from "./operations_research/GMPSolverParameters"
// operations_research/GMPVariable.ts 
import { MPVariable } from "./operations_research/GMPVariable"
// operations_research/GSimpleLinearSumAssignment.ts 
import { SimpleLinearSumAssignment } from "./operations_research/GSimpleLinearSumAssignment"
// operations_research/GSimpleMinCostFlow.ts
import { SimpleMinCostFlow } from "./operations_research/GSimpleMinCostFlow"


// operations_research/sat/GBoolVar.ts 
import { BoolVar } from "./operations_research/sat/GBoolVar"
// operations_research/sat/GConstraint.ts 
import { Constraint } from "./operations_research/sat/GConstraint"
// operations_research/sat/GCpModelBuilder.ts 
import { CpModelBuilder } from "./operations_research/sat/GCpModelBuilder"
// operations_research/sat/GCpModelProto.ts 
import { CpModelProto } from "./operations_research/sat/GCpModelProto"
// operations_research/sat/GCpSolverResponse.ts 
import { CpSolverResponse } from "./operations_research/sat/GCpSolverResponse"
// operations_research/sat/GDoubleLinearExpr.ts 
import { DoubleLinearExpr } from "./operations_research/sat/GDoubleLinearExpr"
// operations_research/sat/GEnum.ts 
import { CpSolverStatus } from "./operations_research/sat/GEnum"
// operations_research/sat/GFunc.ts 
import { Solve, operator_minus, operator_plus, operator_times, operator_neg } from "./operations_research/sat/GFunc"
// operations_research/sat/GIntVar.ts 
import { IntVar } from "./operations_research/sat/GIntVar"
// operations_research/sat/GLinearExpr.ts 
import { LinearExpr as sat_LinearExpr } from "./operations_research/sat/GLinearExpr"
// operations_research/sat/GTableConstraint.ts
import { TableConstraint } from "./operations_research/sat/GTableConstraint"

export namespace operations_research
{
    operator_EQ;
    operator_GEQ;
    operator_LEQ;
    LinearExpr;
    LinearRange;
    MPConstraint;
    MPObjective;
    MPSolver;
    DoubleParam;
    MPVariable;
    SimpleLinearSumAssignment;
    SimpleMinCostFlow;
    MPSolver

    export namespace sat
    {
        BoolVar;
        Constraint;
        CpModelBuilder;
        CpModelProto;
        DoubleLinearExpr;
        CpSolverStatus;
        Solve;
        operator_minus;
        operator_plus;
        operator_times;
        operator_neg;
        IntVar;
        sat_LinearExpr;
        TableConstraint;
    }
}
