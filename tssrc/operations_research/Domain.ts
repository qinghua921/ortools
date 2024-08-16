import { ortools } from "../nodeaddon"

/**
* Int64 的子集 [kint64min, kint64max].
*/
export interface Domain
{
    /**  是否包含 value */
    Contains(value: number): boolean

    /**
     * This method returns the flattened list of interval bounds of the domain.
     *
     * Thus the domain {0, 1, 2, 5, 8, 9, 10} will return [0, 2, 5, 5,
     * 8, 10] (as a C++ std::vector<int64_t>, as a java or C# long[], as
     * a python list of integers).
     */
    FlattenedIntervals(): number[]
}

export const Domain:
    {
        /**
         * 集合 [left, right]. 如果 left > right, 为空集合.
         */
        new(left: number, right: number): Domain

        /**  Constructor for the common case of a singleton domain. */
        new(value: number): Domain

        /**
         * 创建包含 values 的集合, values 可以重复
         */
        FromValues(values: number[]): Domain

    } = ortools.operations_research.Domain
