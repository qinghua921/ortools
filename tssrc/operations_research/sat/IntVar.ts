import { ortools } from "../../fuzhu"
import { Domain } from "../Domain"


/**
 * 整型变量.
 *
 * 封装 IntegerVariableProto, 只能用 CpModelBuilder.NewIntVar() 创建.
 */
export interface IntVar
{
    /**
     * 设置名称
     */
    WithName(name: string): IntVar

    // Human-readable description of the memory layout. Useful for debugging.
    // Slow.
    //
    //   // char[5], 3 bytes of padding, int[3], 4 bytes of padding, followed
    //   // by an unknown number of doubles.
    //   auto x = Layout<char, int, double>::Partial(5, 3);
    //   assert(x.DebugString() ==
    //          "@0<char>(1)[5]; @8<int>(4)[3]; @24<double>(8)");
    //
    // Each field is in the following format: @offset<type>(sizeof)[size] (<type>
    // may be missing depending on the target platform). For example,
    // @8<int>(4)[3] means that at offset 8 we have an array of ints, where each
    // int is 4 bytes, and we have 3 of those ints. The size of the last field may
    // be missing (as in the example above). Only fields with known offsets are
    // described. Type names may differ across platforms: one compiler might
    // produce "unsigned*" where another produces "unsigned int *".
    DebugString(): string

    /**
     * Returns the domain of the variable.
     * Note that we keep the fully qualified return type as compilation fails with
     * gcc otherwise.
     */
    Domain(): Domain

    /**
     * Returns the index of the variable in the model. This will be non-negative.
     */
    index(): number
}
export const IntVar: {} = ortools.operations_research.sat.IntVar
