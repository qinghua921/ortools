import { MPSolver as operations_research_MPSolver } from './operations_research/MPSolver'

declare module operations_research
{
    export
    {
        operations_research_MPSolver as MPSolver
    }
};
