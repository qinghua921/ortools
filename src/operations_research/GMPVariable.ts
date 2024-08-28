import { ortools } from '../addon'

// The class for variables of a Mathematical Programming (MP) model.
export interface GMPVariable
{
    // Returns the name of the variable.
    name(): string;
}

export const GMPVariable:
    {

    } = ortools.operations_research.MPVariable