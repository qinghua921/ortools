import { MultipleDimensionsBinPackingProblem } from "./MultipleDimensionsBinPackingProblem";

export class BinPacking2dParser
{
    constructor();
    Load2BPFile(file_name: string, instance: number): boolean;
    problem(): MultipleDimensionsBinPackingProblem;
};
