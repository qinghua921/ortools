import { ortools } from "../../addon";
import { GCpSolverStatus } from "./GEnum";

export interface GCpSolverResponse 
{
    //         ::operations_research::sat::CpSolverStatus status() const;
    status(): GCpSolverStatus;

}

export const GCpSolverResponseStatus: {} = ortools.operations_research.sat.CpSolverResponseStatus;