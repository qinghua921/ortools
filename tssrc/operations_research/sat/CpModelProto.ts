import { ortools } from "../../fuzhu"

export interface CpModelProto
{
    DebugString(): string
}
export const CpModelProto: {} = ortools.operations_research.sat.CpModelProto
