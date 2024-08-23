import { ortools } from '../addon'
import { MPVariable } from './GMPVariable';

/**
 * The class for constraints of a Mathematical Programming (MP) model.
 *
 * A constraint is represented as a linear equation or inequality.
 */
export interface MPConstraint
{
    /**
     * Sets the coefficient of the variable on the constraint.
     *
     * If the variable does not belong to the solver, the function just returns,
     * or crashes in non-opt mode.
     */
    SetCoefficient(var_: MPVariable, coeff: number): void;
}

export const MPConstraint:
    {

    } = ortools.operations_research.MPConstraint;