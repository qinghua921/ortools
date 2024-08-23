import { ortools } from '../addon'
import { MPVariable } from './GMPVariable';

// A class to express a linear objective.
export interface MPObjective
{
    /**
     * Sets the coefficient of the variable in the objective.
     *
     * If the variable does not belong to the solver, the function just returns,
     * or crashes in non-opt mode.
     */
    SetCoefficient(var_: MPVariable, coeff: number): void;

    // Sets the optimization direction to maximize.
    SetMaximization(): void;
    /**
     *  Clears the offset, all variables and coefficients, and the optimization
     * direction.
     */
    Clear(): void;

    // Gets the constant term in the objective.
    offset(): number;

    // Sets the optimization direction to minimize.
    SetMinimization(): void;

    // Sets the constant term in the objective.
    SetOffset(value: number): void;


    /**
     * Returns the objective value of the best solution found so far.
     *
     * It is the optimal objective value if the problem has been solved to
     * optimality.
     *
     * Note: the objective value may be slightly different than what you could
     * compute yourself using \c MPVariable::solution_value(); please use the
     * --verify_solution flag to gain confidence about the numerical stability of
     * your solution.
     */
    Value(): number;
}

export const MPObjective: {} = ortools.operations_research.MPObjective