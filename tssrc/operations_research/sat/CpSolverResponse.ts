import { ortools } from "../../nodeaddon"
import { CpSolverStatus } from "./Func"

export interface CpSolverResponse
{
    status(): CpSolverStatus
    objective_value(): number
}

export const CpSolverResponse: {} = ortools.operations_research.sat.CpSolverResponse
