import { MPSolver as operations_research_MPSolver } from './operations_research/MPSolver'
import { MPVariable as operations_research_MPVariable } from './operations_research/MPVariable'
import { LinearExpr as operations_research_LinearExpr } from './operations_research/LinearExpr'
import { MPConstraint as operations_research_MPConstraint } from './operations_research/MPConstraint'
import { LinearRange as operations_research_LinearRange } from './operations_research/LinearRange'
import { MPObjective as operations_research_MPObjective } from './operations_research/MPObjective'
import
{
    operator_eq as operations_research_operator_eq,
    operator_le as operations_research_operator_le,
    operator_ge as operations_research_operator_ge,
} from './operations_research/FuncInit'


declare module operations_research
{
    export
    {
        operations_research_MPSolver as MPSolver,
        operations_research_MPVariable as MPVariable,
        operations_research_LinearExpr as LinearExpr,
        operations_research_MPConstraint as MPConstraint,
        operations_research_LinearRange as LinearRange,
        operations_research_MPObjective as MPObjective,
        operations_research_operator_eq as operator_eq,
        operations_research_operator_le as operator_le,
        operations_research_operator_ge as operator_ge,
    }
};
