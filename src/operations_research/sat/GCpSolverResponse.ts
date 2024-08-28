import { ortools } from "../../addon";
import { CpSolverStatus } from "./GEnum";

export interface CpSolverResponse 
{
    //         ::operations_research::sat::CpSolverStatus status() const;
    status(): CpSolverStatus;

}

export const CpSolverResponseStatus: {} = ortools.operations_research.sat.CpSolverResponseStatus;