import { ortools } from "../../nodeaddon"

export interface CpModelProto
{
    DebugString(): string
}
export const CpModelProto: {} = ortools.operations_research.sat.CpModelProto
