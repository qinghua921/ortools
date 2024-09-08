
//   LOG(INFO) << "Trivial lower bound of the number of bins = " << trivial_lb;
//   const int max_bins = absl::GetFlag(FLAGS_max_bins) == 0
//                            ? trivial_lb * 2
//                            : absl::GetFlag(FLAGS_max_bins);
//   if (absl::GetFlag(FLAGS_max_bins) == 0) {
//     LOG(INFO) << "Setting max_bins to " << max_bins;
//   }

//   CpModelBuilder cp_model;

//   // We do not support multiple shapes per item.
//   for (int item = 0; item < num_items; ++item) {
//     const int num_shapes = problem.items(item).shapes_size();
//     CHECK_EQ(1, num_shapes);
//   }

//   // Create one Boolean variable per item and per bin.
//   std::vector<std::vector<BoolVar>> item_to_bin(num_items);
//   for (int item = 0; item < num_items; ++item) {
//     item_to_bin[item].resize(max_bins);
//     for (int b = 0; b < max_bins; ++b) {
//       item_to_bin[item][b] = cp_model.NewBoolVar();
//     }
//   }

//   // Exactly one bin is selected for each item.
//   for (int item = 0; item < num_items; ++item) {
//     cp_model.AddEquality(LinearExpr::Sum(item_to_bin[item]), 1);
//   }

//   // Manages positions and sizes for each item.
//   std::vector<std::vector<std::vector<IntervalVar>>>
//       interval_by_item_bin_dimension(num_items);
//   for (int item = 0; item < num_items; ++item) {
//     interval_by_item_bin_dimension[item].resize(max_bins);
//     for (int b = 0; b < max_bins; ++b) {
//       interval_by_item_bin_dimension[item][b].resize(2);
//       for (int dim = 0; dim < num_dimensions; ++dim) {
//         const int64_t dimension = box_dimensions[dim];
//         const int64_t size = problem.items(item).shapes(0).dimensions(dim);
//         const IntVar start = cp_model.NewIntVar({0, dimension - size});
//         interval_by_item_bin_dimension[item][b][dim] =
//             cp_model.NewOptionalFixedSizeIntervalVar(start, size,
//                                                      item_to_bin[item][b]);
//       }
//     }
//   }

//   // Non overlapping.
//   if (num_dimensions == 1) {
//     LOG(FATAL) << "One dimension is not supported.";
//   } else if (num_dimensions == 2) {
//     LOG(INFO) << "Box size: " << box_dimensions[0] << "*" << box_dimensions[1];
//     for (int b = 0; b < max_bins; ++b) {
//       NoOverlap2DConstraint no_overlap_2d = cp_model.AddNoOverlap2D();
//       for (int item = 0; item < num_items; ++item) {
//         no_overlap_2d.AddRectangle(interval_by_item_bin_dimension[item][b][0],
//                                    interval_by_item_bin_dimension[item][b][1]);
//       }
//     }
//   } else {
//     LOG(FATAL) << num_dimensions << " dimensions not supported.";
//   }

//   // Redundant constraint.
//   // The sum of areas in each bin is the sum of all items area.
//   if (absl::GetFlag(FLAGS_global_area_constraint)) {
//     LinearExpr sum_of_areas;
//     for (int item = 0; item < num_items; ++item) {
//       const int64_t item_area = problem.items(item).shapes(0).dimensions(0) *
//                                 problem.items(item).shapes(0).dimensions(1);
//       for (int b = 0; b < max_bins; ++b) {
//         sum_of_areas += item_to_bin[item][b] * item_area;
//       }
//     }
//     cp_model.AddEquality(sum_of_areas, sum_of_items_area);
//   }

//   if (absl::GetFlag(FLAGS_alternate_model)) {
//     const IntVar obj = cp_model.NewIntVar(Domain(trivial_lb, max_bins));
//     cp_model.Minimize(obj);
//     for (int b = trivial_lb; b < max_bins; ++b) {
//       for (int item = 0; item < num_items; ++item) {
//         cp_model.AddGreaterOrEqual(obj, b + 1)
//             .OnlyEnforceIf(item_to_bin[item][b]);
//       }
//     }
//   } else {
//     // Maintain one Boolean variable per bin that indicates if the bin is used
//     // or not.
//     std::vector<BoolVar> bin_is_used(max_bins);
//     for (int b = 0; b < max_bins; ++b) {
//       bin_is_used[b] = cp_model.NewBoolVar();
//       // Link bin_is_used[i] with the items in bin i.
//       std::vector<BoolVar> all_items_in_bin;
//       for (int item = 0; item < num_items; ++item) {
//         cp_model.AddImplication(item_to_bin[item][b], bin_is_used[b]);
//         all_items_in_bin.push_back(item_to_bin[item][b]);
//       }
//       cp_model.AddBoolOr(all_items_in_bin).OnlyEnforceIf(bin_is_used[b]);
//     }

//     // Symmetry breaking.
//     if (absl::GetFlag(FLAGS_symmetry_breaking)) {
//       // Forces the number of items per bin to decrease.
//       std::vector<IntVar> num_items_in_bin(max_bins);
//       for (int b = 0; b < max_bins; ++b) {
//         num_items_in_bin[b] = cp_model.NewIntVar({0, num_items});
//         std::vector<BoolVar> items_in_bins;
//         for (int item = 0; item < num_items; ++item) {
//           items_in_bins.push_back(item_to_bin[item][b]);
//         }
//         cp_model.AddEquality(num_items_in_bin[b],
//                              LinearExpr::Sum(items_in_bins));
//       }
//       for (int b = 1; b < max_bins; ++b) {
//         cp_model.AddGreaterOrEqual(num_items_in_bin[b - 1],
//                                    num_items_in_bin[b]);
//       }
//     }

//     // Objective.
//     cp_model.Minimize(LinearExpr::Sum(bin_is_used));
//   }

//   // Setup parameters.
//   SatParameters parameters;
//   parameters.set_log_search_progress(true);
//   parameters.set_use_timetabling_in_no_overlap_2d(true);
//   parameters.set_use_energetic_reasoning_in_no_overlap_2d(true);

//   // Parse the --params flag.
//   if (!absl::GetFlag(FLAGS_params).empty()) {
//     CHECK(google::protobuf::TextFormat::MergeFromString(
//         absl::GetFlag(FLAGS_params), &parameters))
//         << absl::GetFlag(FLAGS_params);
//   }
//   // We rely on the solver default logging to log the number of bins.
//   const CpSolverResponse response =
//       SolveWithParameters(cp_model.Build(), parameters);
// }

// }  // namespace sat
// }  // namespace operations_research

// int main(int argc, char** argv) {
//   absl::SetFlag(&FLAGS_stderrthreshold, 0);
//   InitGoogle(argv[0], &argc, &argv, true);
//   if (absl::GetFlag(FLAGS_input).empty()) {
//     LOG(FATAL) << "Please supply a data file with --input=";
//   }
//   if (absl::GetFlag(FLAGS_instance) == -1) {
//     LOG(FATAL) << "Please supply a valid instance number with --instance=";
//   }

//   operations_research::sat::LoadAndSolve(absl::GetFlag(FLAGS_input),
//                                          absl::GetFlag(FLAGS_instance));
//   return EXIT_SUCCESS;
// }

import { operations_research } from "../src";
import { BoolVar } from "../src/operations_research/sat/GBoolVar";

test('assignment_groups_mip', () =>
{
  let parse = new operations_research.packing.BinPacking2dParser();
  if (!parse.Load2BPFile("D:\\code\\tsortools\\test\\binpacking_2d_sat.test.txt", 1))
  {
    console.log("Cannot read instance 1 from file 'D:\\code\\tsortools\\test\\binpacking_2d_sat.test.txt'");
  }

  let problem: operations_research.packing.MultipleDimensionsBinPackingProblem = parse.problem();
  console.log("Successfully loaded instance 1 from file 'D:\\code\\tsortools\\test\\binpacking_2d_sat.test.txt'");
  console.log("Instance has " + problem.items_size() + " items");

  const box_dimensions = problem.box_shape().dimensions();
  const num_dimensions = box_dimensions.size();
  const num_items = problem.items_size();

  const area_of_one_bin = box_dimensions.operator_get(0) * box_dimensions.operator_get(1);
  let sum_of_items_area = 0;
  for (let i = 0; i < num_items; ++i)
  {
    const item = problem.items(i);
    const shape = item.shapes(0);
    const dimensions = shape.dimensions();
    sum_of_items_area += dimensions.operator_get(0) * dimensions.operator_get(1);
  }

  // Take the ceil of the ratio.
  const trivial_lb = (sum_of_items_area + area_of_one_bin - 1) / area_of_one_bin;

  console.log("Trivial lower bound of the number of bins = " + trivial_lb);
  const max_bins = Math.ceil(2 * trivial_lb);
  console.log("Setting max_bins to " + max_bins);

  let cp_model = new operations_research.sat.CpModelBuilder();

  // We do not support multiple shapes per item.
  for (let item = 0; item < num_items; ++item)
  {
    const num_shapes = problem.items(item).shapes_size();
    if (num_shapes != 1)
    {
      console.log("Error: We do not support multiple shapes per item.");
      return;
    }
  }

  // Create one Boolean variable per item and per bin.
  let item_to_bin: BoolVar[][] = new Array(num_items);
  for (let item = 0; item < num_items; ++item)
  {
    item_to_bin[item] = new Array(max_bins);
    for (let b = 0; b < max_bins; ++b)
    {
      item_to_bin[item][b] = cp_model.NewBoolVar();
    }
  }

  // Exactly one bin is selected for each item.
  for (let item = 0; item < num_items; ++item)
  {
    cp_model.AddEquality(operations_research.sat.LinearExpr.Sum(item_to_bin[item]), 1);
  }

  // Manages positions and sizes for each item.
  let interval_by_item_bin_dimension = new Array(num_items);
  for (let item = 0; item < num_items; ++item)
  {
    interval_by_item_bin_dimension[item] = new Array(max_bins);
    for (let b = 0; b < max_bins; ++b)
    {
      interval_by_item_bin_dimension[item][b] = new Array(2);
      for (let dim = 0; dim < num_dimensions; ++dim)
      {
        const dimension = box_dimensions.operator_get(dim);
        const size = problem.items(item).shapes(0).dimensions().operator_get(dim);
        const start = cp_model.NewIntVar(new operations_research.Domain(0, dimension - size));
        interval_by_item_bin_dimension[item][b][dim] =
          cp_model.NewOptionalFixedSizeIntervalVar(start, size, item_to_bin[item][b]);
      }
    }
  }


  if (num_dimensions == 1)
  {
    console.log("One dimension is not supported.");
    return;
  }
  else if (num_dimensions == 2)
  {
    console.log("Box size: " + box_dimensions.operator_get(0) + "*" + box_dimensions.operator_get(1));
    for (let b = 0; b < max_bins; ++b)
    {
      let no_overlap_2d = cp_model.AddNoOverlap2D();
      for (let item = 0; item < num_items; ++item)
      {
        no_overlap_2d.AddRectangle(interval_by_item_bin_dimension[item][b][0],
          interval_by_item_bin_dimension[item][b][1]);
      }
    }
  }
  else
  {
    console.log(num_dimensions + " dimensions not supported.");
  }


});
