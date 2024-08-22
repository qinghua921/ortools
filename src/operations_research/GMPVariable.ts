import { ortools } from '../addon'

// The class for variables of a Mathematical Programming (MP) model.
export interface MPVariable
{
    // Returns the name of the variable.
    name(): string;
}

export const MPVariable:
    {

    } = ortools.operations_research.MPVariable