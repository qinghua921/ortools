import { ortools } from "../nodeaddon"

export const OrToolsVersion:
    {
        /**
         * Returns the major version of OR-Tools.
         */
        MajorNumber(): number;

        /**
         * Returns the minor version of OR-Tools.
         */
        MinorNumber(): number;

        /**
         * Returns the patch version of OR-Tools.
         */
        PatchNumber(): number;

        /**
         * Returns the string version of OR-Tools.
         */
        VersionString(): string;

    } = ortools.operations_research.OrToolsVersion
