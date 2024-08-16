
/**
 * 解状态
 */
export enum ResultStatus
{
    /**  最优. */
    OPTIMAL = 0,
    /**  可行解, or stopped by limit. */
    FEASIBLE = 1,
    /**  以证明不可行. */
    INFEASIBLE = 2,
    /**  以证明无边界. */
    UNBOUNDED = 3,
    /**  计算异常. */
    ABNORMAL = 4,
    /**  the model is trivially invalid (NaN coefficients, etc). */
    MODEL_INVALID = 5,
    /**  没有计算完成. */
    NOT_SOLVED = 6
};