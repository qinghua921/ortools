import { ortools } from '../addon'
import { GMPVariable } from './GMPVariable';

/**
 * The class for constraints of a Mathematical Programming (MP) model.
 *
 * A constraint is represented as a linear equation or inequality.
 */
export interface GMPConstraint
{
    /**
     * Sets the coefficient of the variable on the constraint.
     *
     * If the variable does not belong to the solver, the function just returns,
     * or crashes in non-opt mode.
     */
    SetCoefficient(var_: GMPVariable, coeff: number): void;
}

export const GMPConstraint:
    {

    } = ortools.operations_research.MPConstraint;