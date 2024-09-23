/**
 * A BinPacking parser.
 * It supports the following file format:
 *  - 2bp:
 *    see http://or.dei.unibo.it/library/two-dimensional-bin-packing-problem
 *  - Binpacking with conflicts:
 *    see http://or.dei.unibo.it/library/bin-packing-problem-conflicts
 *
 * The generated problems have the following characteristics:
 *
 * You have one box with n dimensions. The size of the box is stored in the
 * field box_shape().
 * You need to fit items into this box. Each item has the same number of
 * dimensions and one or more possible shapes (this usually means that
 * you can rotate the item). Each item has a value, and a possible list of
 * conflicts (items you cannot put alongside this item).
 * The objective of the problem is to fit as many items as possible in the box
 * while maximizing the sum of values of selected items. For each item, you need
 * to select the shape and the position of the item in the box.
 * Each item must not overlap (in n dimensions) with any other item.
 */
export class BinPacking2dParser
{
    /**
     * C++ BinPacking2dParser();
     */
    constructor();

    /**
     * Loads the 'instance'th instance of the 2D bin packing problem from the given
     * file. The instance are 1 based (first is 1).
     * Only one call to a Load*() function is supported. All the subsequent
     * calls will do nothing and return false.
     * 
     * C++ bool Load2BPFile( absl::string_view file_name, int instance );
     */
    Load2BPFile(file_name: string, instance: number): boolean;

    /**
     * C++ MultipleDimensionsBinPackingProblem problem() const
     */
    problem(): MultipleDimensionsBinPackingProblem;

};
