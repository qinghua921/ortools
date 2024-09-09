
export enum DecisionStrategyProto_VariableSelectionStrategy
{
    // DecisionStrategyProto_VariableSelectionStrategy
    CHOOSE_FIRST = 0,
    CHOOSE_LOWEST_MIN = 1,
    CHOOSE_HIGHEST_MAX = 2,
    CHOOSE_MIN_DOMAIN_SIZE = 3,
    CHOOSE_MAX_DOMAIN_SIZE = 4,
}

export enum DecisionStrategyProto_DomainReductionStrategy
{
    // DecisionStrategyProto_DomainReductionStrategy
    SELECT_MIN_VALUE = 0,
    SELECT_MAX_VALUE = 1,
    SELECT_LOWER_HALF = 2,
    SELECT_UPPER_HALF = 3,
    SELECT_MEDIAN_VALUE = 4,
}

export enum CpSolverStatus  
{
    UNKNOWN = 0,
    MODEL_INVALID = 1,
    FEASIBLE = 2,
    INFEASIBLE = 3,
    OPTIMAL = 4,
}
