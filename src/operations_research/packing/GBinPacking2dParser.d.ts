
// A BinPacking parser.
// It supports the following file format:
//  - 2bp:
//    see http://or.dei.unibo.it/library/two-dimensional-bin-packing-problem
//  - Binpacking with conflicts:
//    see http://or.dei.unibo.it/library/bin-packing-problem-conflicts
//
// The generated problems have the following characteristics:
//
// You have one box with n dimensions. The size of the box is stored in the
// field box_shape().
// You need to fit items into this box. Each item has the same number of
// dimensions and one or more possible shapes (this usually means that
// you can rotate the item). Each item has a value, and a possible list of
// conflicts (items you cannot put alongside this item).
// The objective of the problem is to fit as many items as possible in the box
// while maximizing the sum of values of selected items. For each item, you need
// to select the shape and the position of the item in the box.
// Each item must not overlap (in n dimensions) with any other item.
export class BinPacking2dParser
{
    //  BinPacking2dParser();
    constructor();

    //  // Loads the 'instance'th instance of the bin packing problem if the given
    //  // file. The instance are 1 based (first is 1).
    //  // Only one call to a Load*() function is supported. All the subsequent
    //  // calls will do nothing and return false.
    //  bool Load2BPFile(const std::string& file_name, int instance);
    Load2BPFile(name: string, instance: number): boolean;

    //  MultipleDimensionsBinPackingProblem problem() const { return problem_; }

    // private:
    //  enum LoadStatus { NOT_STARTED = 0, INSTANCE_FOUND = 1, PARSING_FINISHED = 2 };

    //  void ProcessNew2BpLine(const std::string& line, int instance);

    //  MultipleDimensionsBinPackingProblem problem_;
    //  int num_dimensions_;

    //  // Temporary.
    //  LoadStatus load_status_;
    //  int num_items_;
    //  int instances_seen_;
};
