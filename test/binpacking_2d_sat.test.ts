
import { operations_research } from "../src";
import { BoolVar } from "../src/operations_research/sat/GBoolVar";


test('assignment_groups_mip', () =>
{


  let params = "";

  let FLAGS_max_bins = 0;
  let symmetry_breaking = true;
  let global_area_constraint = false;
  let alternate_model = true;
  let file_name = "D:\\code\\tsortools\\test\\binpacking_2d_sat.test.txt"
  let instance = 1;
  let parser = new operations_research.packing.BinPacking2dParser();

  if (!parser.Load2BPFile(file_name, instance))
  {
    console.log("Cannot read instance " + instance + " from file '" + file_name + "'");
  }
  let problem = parser.problem();
  console.log("Successfully loaded instance " + instance + " from file '" + file_name + "'");
  console.log("Instance has " + problem.items_size() + " items");

  const box_dimensions = problem.box_shape().dimensions();
  const num_dimensions = box_dimensions.size();
  const num_items = problem.items_size();

  const area_of_one_bin = box_dimensions.operator_get(0) * box_dimensions.operator_get(1);
  let sum_of_items_area = 0;

  for (const item of problem.items())
  {
    expect(item.shapes_size()).toBe(1);
    const shape = item.shapes(0);
    expect(shape.dimensions_size()).toBe(2);
    sum_of_items_area += shape.dimensions(0) * shape.dimensions(1);

  }

  let trivial_lb = Math.ceil(sum_of_items_area / area_of_one_bin);
  console.log("Trivial lower bound of the number of bins = " + trivial_lb);

  let max_bins = FLAGS_max_bins == 0 ? trivial_lb * 2 : FLAGS_max_bins;
  if (FLAGS_max_bins == 0)
  {
    console.log("Setting max_bins to " + max_bins);
  }

  const cp_model = new operations_research.sat.CpModelBuilder();

  // We do not support multiple shapes per item.
  for (let item = 0; item < num_items; ++item)
  {
    const num_shapes = problem.items(item).shapes_size();
    expect(num_shapes).toBe(1);
  }

  // Create one Boolean variable per item and per bin.
  const item_to_bin: BoolVar[][] = new Array(num_items);
  for (let item = 0; item < num_items; ++item)
  {
    item_to_bin[item] = new Array(max_bins);
    for (let b = 0; b < max_bins; ++b)
    {
      item_to_bin[item][b] = cp_model.NewBoolVar();
    }
  }

  for (let item = 0; item < num_items; ++item)
  {
    cp_model.AddEquality(operations_research.sat.LinearExpr.Sum(item_to_bin[item]), 1);
  }

  // Manages positions and sizes for each item.
  const interval_by_item_bin_dimension = new Array(num_items);
  for (let item = 0; item < num_items; ++item)
  {
    interval_by_item_bin_dimension[item] = new Array(max_bins);
    for (let b = 0; b < max_bins; ++b)
    {
      interval_by_item_bin_dimension[item][b] = new Array(2);
      for (let dim = 0; dim < num_dimensions; ++dim)
      {
        const dimension = box_dimensions.operator_get(dim);
        const size = problem.items(item).shapes(0).dimensions(dim);
        const start = cp_model.NewIntVar(new operations_research.Domain(0, dimension - size));
        interval_by_item_bin_dimension[item][b][dim] = cp_model.NewOptionalFixedSizeIntervalVar(start, size, item_to_bin[item][b]);

      }
    }
  }

  // Non overlapping.
  if (num_dimensions == 1)
  {
    console.log("One dimension is not supported.");
  }
  else if (num_dimensions == 2)
  {
    console.log("Box size: " + box_dimensions.operator_get(0) + "*" + box_dimensions.operator_get(1));
    for (let b = 0; b < max_bins; ++b)
    {
      const no_overlap_2d = cp_model.AddNoOverlap2D();
      for (let item = 0; item < num_items; ++item)
      {
        no_overlap_2d.AddRectangle(interval_by_item_bin_dimension[item][b][0], interval_by_item_bin_dimension[item][b][1]);
      }
    }
  }
  else
  {
    console.log(num_dimensions + " dimensions not supported.");
  }

  // Redundant constraint.
  // The sum of areas in each bin is the sum of all items area.
  if (global_area_constraint)
  {
    const sum_of_areas = new operations_research.sat.LinearExpr();
    for (let item = 0; item < num_items; ++item)
    {
      const item_area = problem.items(item).shapes(0).dimensions(0) * problem.items(item).shapes(0).dimensions(1);
      for (let b = 0; b < max_bins; ++b)
      {
        sum_of_areas.operator_plus_equals(
          operations_research.sat.operator_times(item_to_bin[item][b], item_area));
      }
    }
    cp_model.AddEquality(sum_of_areas, sum_of_items_area);
  }

  if (alternate_model)
  {
    const obj = cp_model.NewIntVar(new operations_research.Domain(trivial_lb, max_bins));
    cp_model.Minimize(obj);
    for (let b = trivial_lb; b < max_bins; ++b)
    {
      for (let item = 0; item < num_items; ++item)
      {
        cp_model.AddGreaterOrEqual(obj, b + 1).OnlyEnforceIf(item_to_bin[item][b]);
      }
    }
  }
  else
  {
    // Maintain one Boolean variable per bin that indicates if the bin is used or not.
    const bin_is_used = new Array(max_bins);
    for (let b = 0; b < max_bins; ++b)
    {
      bin_is_used[b] = cp_model.NewBoolVar();
      // Link bin_is_used[i] with the items in bin i.
      const all_items_in_bin = new Array(num_items);
      for (let item = 0; item < num_items; ++item)
      {
        cp_model.AddImplication(item_to_bin[item][b], bin_is_used[b]);
        all_items_in_bin[item] = item_to_bin[item][b];
      }
      cp_model.AddBoolOr(all_items_in_bin).OnlyEnforceIf(bin_is_used[b]);
    }

    // Symmetry breaking.
    if (symmetry_breaking)
    {
      // Forces the number of items per bin to decrease.
      const num_items_in_bin = new Array(max_bins);
      for (let b = 0; b < max_bins; ++b)
      {
        num_items_in_bin[b] = cp_model.NewIntVar(new operations_research.Domain(0, num_items));
        const items_in_bins = new Array(num_items);
        for (let item = 0; item < num_items; ++item)
        {
          items_in_bins[item] = item_to_bin[item][b];
        }
        cp_model.AddEquality(num_items_in_bin[b], operations_research.sat.LinearExpr.Sum(items_in_bins));
      }
      for (let b = 1; b < max_bins; ++b)
      {
        cp_model.AddGreaterOrEqual(num_items_in_bin[b - 1], num_items_in_bin[b]);
      }
    }

    // Objective.
    cp_model.Minimize(operations_research.sat.LinearExpr.Sum(bin_is_used));
  }

  let  parameters = new operations_research.sat.SatParameters();




  //         // Setup parameters.
  //         SatParameters parameters;
  //         parameters.set_log_search_progress( true );
  //         parameters.set_use_timetabling_in_no_overlap_2d( true );
  //         parameters.set_use_energetic_reasoning_in_no_overlap_2d( true );

  //         // Parse the --params flag.
  //         if ( !absl::GetFlag( FLAGS_params ).empty() )
  //         {
  //             CHECK( google::protobuf::TextFormat::MergeFromString(
  //                 absl::GetFlag( FLAGS_params ), &parameters ) )
  //                 << absl::GetFlag( FLAGS_params );
  //         }
  //         // We rely on the solver default logging to log the number of bins.
  //         const CpSolverResponse response =
  //             SolveWithParameters( cp_model.Build(), parameters );
  //     }

  // }  // namespace sat
  // }  // namespace operations_research

  // int main( int argc, char** argv )
  // {
  //     absl::SetFlag( &FLAGS_stderrthreshold, 0 );
  //     InitGoogle( argv[ 0 ], &argc, &argv, true );
  //     if ( absl::GetFlag( FLAGS_input ).empty() )
  //     {
  //         LOG( FATAL ) << "Please supply a data file with --input=";
  //     }
  //     if ( absl::GetFlag( FLAGS_instance ) == -1 )
  //     {
  //         LOG( FATAL ) << "Please supply a valid instance number with --instance=";
  //     }

  //     operations_research::sat::LoadAndSolve( absl::GetFlag( FLAGS_input ),
  //                                             absl::GetFlag( FLAGS_instance ) );
  //     return EXIT_SUCCESS;
  // }



});
