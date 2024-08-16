import { ortools } from "../../fuzhu"


export interface SatParameters
{
    set_enumerate_all_solutions(value: boolean): void
}
export const SatParameters:
    {
        new(): SatParameters
    } = ortools.operations_research.sat.SatParameters

