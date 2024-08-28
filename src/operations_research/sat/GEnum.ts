export enum GCpSolverStatus 
{
    UNKNOWN = 0,
    MODEL_INVALID = 1,
    FEASIBLE = 2,
    INFEASIBLE = 3,
    OPTIMAL = 4,
    // CpSolverStatus_INT_MIN_SENTINEL_DO_NOT_USE_ = std:: numeric_limits<int32_t>:: min(),
    // CpSolverStatus_INT_MAX_SENTINEL_DO_NOT_USE_ = std:: numeric_limits<int32_t>:: max()
};