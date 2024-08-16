import { ortools } from "../nodeaddon"

export const OrToolsVersion: {
    VersionString(): string
} = ortools.operations_research.OrToolsVersion
