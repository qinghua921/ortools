import { operations_research as op } from '../../src'
function MaxSubsetSumSize(sizes: number[], max_size: number): number
{
    let builder = new op.sat.CpModelBuilder();
    let weighed_sum = new op.sat.LinearExpr();
    for (let size of sizes)
    {
        weighed_sum.operator_plus_eq(op.sat.operator_times(size, builder.NewBoolVar()))
    }
    builder.AddLessOrEqual(weighed_sum, max_size);
    builder.Maximize(weighed_sum);
    let response = op.sat.Solve(builder.Build());
    if (response.status() != op.sat.CpSolverStatus.OPTIMAL)
    {
        console.log("Cannot find optimal solution");
        return 0;
    }
    if (response.status() != op.sat.CpSolverStatus.OPTIMAL)
    {
        throw new Error("Cannot find optimal solution");
    }
    return response.objective_value();
}
function ItemsAreIncompatible(problem: op.packing.MultipleDimensionsBinPackingProblem, i1: number, i2: number): boolean
{
    const bin_sizes = problem.box_shape().dimensions();
    const i1_sizes = problem.items(i1).shapes(0).dimensions();
    const i2_sizes = problem.items(i2).shapes(0).dimensions();
    return (i1_sizes[0] + i2_sizes[0] > bin_sizes[0]) &&
        (i1_sizes[1] + i2_sizes[1] > bin_sizes[1]);
}
function FindFixedItems(problem: op.packing.MultipleDimensionsBinPackingProblem): Set<number>
{
    let fixed_items = new Set<number>();
    let num_items = problem.items_size();
    let bin_sizes = problem.box_shape().dimensions();
    for (let i = 0; i < num_items; ++i)
    {
        let item_sizes = problem.items(i).shapes(0).dimensions();
        if (2 * item_sizes[0] > bin_sizes[0] &&
            2 * item_sizes[1] > bin_sizes[1])
        {
            fixed_items.add(i);
        }
    }
    let incompatible_pair_candidates = new Set<number>();
    for (let i = 0; i < num_items; ++i)
    {
        if (fixed_items.has(i))
        {
            continue;
        }
        let incompatible_with_all = true;
        for (let item of fixed_items)
        {
            if (!ItemsAreIncompatible(problem, item, i))
            {
                incompatible_with_all = false;
                break;
            }
        }
        if (incompatible_with_all)
        {
            incompatible_pair_candidates.add(i);
        }
    }
    let found_incompatible_pair = false;
    for (let i1 of incompatible_pair_candidates)
    {
        for (let i2 of incompatible_pair_candidates)
        {
            if (i1 == i2)
            {
                continue;
            }
            if (ItemsAreIncompatible(problem, i1, i2))
            {
                fixed_items.add(i1);
                fixed_items.add(i2);
                found_incompatible_pair = true;
                break;
            }
            if (found_incompatible_pair)
            {
                break;
            }
        }
    }
    if (!found_incompatible_pair && incompatible_pair_candidates.size != 0)
    {
        let min_item = [...incompatible_pair_candidates].reduce((a, b) =>
        {
            let a_sizes = problem.items(a).shapes(0).dimensions();
            let b_sizes = problem.items(b).shapes(0).dimensions();
            return a_sizes[0] * a_sizes[1] > b_sizes[0] * b_sizes[1] ? a : b;
        }, 0);
        fixed_items.add(min_item);
    }
    if (fixed_items.size > 1)
    {
        let message_end = ".";
        if (found_incompatible_pair)
        {
            message_end =
                " (including the extra two that are big in only one "
            "dimensions).";
        }
        else if (incompatible_pair_candidates.size != 0)
        {
            message_end =
                " (including an extra one that is incompatible with all big ones).";
        }
        console.log(fixed_items.size + " items are pairwise incompatible" + message_end);
    }
    return fixed_items;
}
function test()
{
    let file_name = "D:\\Code\\ortools\\test\\binpacking_2d_sat.test.txt";
    let parser = new op.packing.BinPacking2dParser();
    if (!parser.Load2BPFile(file_name, 1))
    {
        console.log(`Cannot read instance 1 from file  ${file_name}`);
        return;
    }
    let problem = parser.problem();
    console.log("Successfully loaded instance 1 from file " + file_name);
    console.log("Instance has " + problem.items_size() + " items");
    let original_bin_sizes = problem.box_shape().dimensions();
    let num_dimensions = original_bin_sizes.length;
    let num_items = problem.items_size();
    if (num_dimensions == 1)
    {
        console.log("One dimension is not supported.");
        return;
    }
    else if (num_dimensions != 2)
    {
        console.log(num_dimensions + " dimensions not supported.");
        return;
    }
    let x_sizes = [];
    let y_sizes = [];
    let sum_of_items_area = 0;
    for (let item of problem.items())
    {
        if (item.shapes_size() != 1)
        {
            console.log("Item has more than one shape");
            return;
        }
        let shape = item.shapes(0);
        if (shape.dimensions_size() != 2)
        {
            console.log("Shape has more than two dimensions");
            return;
        }
        sum_of_items_area += shape.dimensions()[0] * shape.dimensions()[1];
        x_sizes.push(shape.dimensions()[0]);
        y_sizes.push(shape.dimensions()[1]);
    }
    let bin_sizes = [0, 0];
    bin_sizes[0] = MaxSubsetSumSize(x_sizes, original_bin_sizes[0]);
    bin_sizes[1] = MaxSubsetSumSize(y_sizes, original_bin_sizes[1]);
    if (bin_sizes[0] == original_bin_sizes[0] &&
        bin_sizes[1] == original_bin_sizes[1])
    {
        console.log("Box size: [" + bin_sizes[0] + " * " + bin_sizes[1] + "]");
    }
    else
    {
        console.log("Box size: [" + bin_sizes[0] + " * " + bin_sizes[1] + "] reduced from [" + original_bin_sizes[0] + " * " + original_bin_sizes[1] + "]");
    }
    let area_of_one_bin = bin_sizes[0] * bin_sizes[1];
    let trivial_lb = Math.ceil(sum_of_items_area / area_of_one_bin);
    console.log("Trivial lower bound of the number of bins = " + trivial_lb);
    let max_bins = 2 * trivial_lb;
    if (max_bins == 0)
    {
        console.log("Setting max_bins to " + max_bins);
    }
    let cp_model = new op.sat.CpModelBuilder();
    cp_model.SetName("binpacking_2d_" + file_name + "_" + 1);
    for (let item = 0; item < num_items; ++item)
    {
        if (problem.items(item).shapes_size() != 1)
        {
            console.log("Item has more than one shape");
            return;
        }
    }
    let item_to_bin: op.sat.BoolVar[][] = [];
    for (let item = 0; item < num_items; ++item)
    {
        item_to_bin.push([]);
        for (let b = 0; b < max_bins; ++b)
        {
            item_to_bin[item].push(cp_model.NewBoolVar());
        }
    }
    for (let item = 0; item < num_items; ++item)
    {
        cp_model.AddExactlyOne(item_to_bin[item]);
    }
    let fixed_items = FindFixedItems(problem);
    if (fixed_items.size > max_bins)
    {
        console.log("Infeasible problem, increase max_bins");
        return;
    }
    let count = 0;
    for (let item of fixed_items)
    {
        cp_model.FixVariable(item_to_bin[item][count], true);
        ++count;
    }
    let num_incompatible_pairs = 0;
    for (let i1 = 0; i1 + 1 < num_items; ++i1)
    {
        for (let i2 = i1 + 1; i2 < num_items; ++i2)
        {
            if (fixed_items.has(i1) && fixed_items.has(i2))
            {
                continue;
            }
            if (!ItemsAreIncompatible(problem, i1, i2))
            {
                continue;
            }
            num_incompatible_pairs++;
            for (let b = 0; b < max_bins; ++b)
            {
                cp_model.AddAtMostOne([item_to_bin[i1][b], item_to_bin[i2][b]]);
            }
        }
    }
    if (num_incompatible_pairs > 0)
    {
        console.log(num_incompatible_pairs + " incompatible pairs of items");
    }
    let min_sizes_per_dimension = bin_sizes.slice();
    for (let item = 0; item < num_items; ++item)
    {
        for (let dim = 0; dim < num_dimensions; ++dim)
        {
            min_sizes_per_dimension[dim] = Math.min(min_sizes_per_dimension[dim], problem.items(item).shapes(0).dimensions()[dim]);
        }
    }
    let starts_by_dimension: op.sat.IntVar[][] = [];
    let items_exclusive_in_at_least_one_dimension = new Set<number>();
    for (let item = 0; item < num_items; ++item)
    {
        starts_by_dimension.push([]);
        for (let dim = 0; dim < num_dimensions; ++dim)
        {
            let bin_size = bin_sizes[dim];
            let item_size = problem.items(item).shapes(0).dimensions()[dim];
            let start_max = fixed_items.has(item) ? (bin_size - item_size + 1) / 2 : bin_size - item_size;
            starts_by_dimension[item].push(cp_model.NewIntVar(new op.Domain(0, start_max)));
            let size = problem.items(item).shapes(0).dimensions()[dim];
            if (size + min_sizes_per_dimension[dim] > bin_size)
            {
                items_exclusive_in_at_least_one_dimension.add(item);
            }
        }
    }
    let interval_by_item_bin_dimension: op.sat.IntervalVar[][][] = [];
    for (let item = 0; item < num_items; ++item)
    {
        interval_by_item_bin_dimension.push([]);
        for (let b = 0; b < max_bins; ++b)
        {
            interval_by_item_bin_dimension[item].push([]);
            for (let dim = 0; dim < num_dimensions; ++dim)
            {
                let size = problem.items(item).shapes(0).dimensions()[dim];
                let start = starts_by_dimension[item][dim];
                interval_by_item_bin_dimension[item][b].push(cp_model.NewOptionalFixedSizeIntervalVar(start, size, item_to_bin[item][b]));
            }
        }
    }
    if (items_exclusive_in_at_least_one_dimension.size > 0)
    {
        let num_items_fixed_in_corner = 0;
        let num_items_fixed_on_one_border = 0;
        for (let item of items_exclusive_in_at_least_one_dimension)
        {
            for (let dim = 0; dim < num_dimensions; ++dim)
            {
                if (fixed_items.has(item))
                {
                    cp_model.FixVariable(starts_by_dimension[item][dim], 0);
                    if (dim == 0) ++num_items_fixed_in_corner;
                }
                else
                {
                    let bin_size = bin_sizes[dim];
                    let item_size = problem.items(item).shapes(0).dimensions()[dim];
                    if (item_size + min_sizes_per_dimension[dim] > bin_size)
                    {
                        cp_model.FixVariable(starts_by_dimension[item][dim], 0);
                        ++num_items_fixed_on_one_border;
                    }
                }
            }
        }
        console.log(num_items_fixed_in_corner + " items fixed in one corner");
        console.log(num_items_fixed_on_one_border + " items fixed on one border");
    }
    if (true)
    {
        let item_indexes_for_dimensions = new Map<string, number[]>();
        for (let item = 0; item < num_items; ++item)
        {
            let key = problem.items(item).shapes(0).dimensions()[0] + "," + problem.items(item).shapes(0).dimensions()[1];
            if (!item_indexes_for_dimensions.has(key))
            {
                item_indexes_for_dimensions.set(key, []);
            }
            item_indexes_for_dimensions.get(key)!.push(item);
        }
        let num_identical_items = 0;
        for (let [dim, item_indexes] of item_indexes_for_dimensions)
        {
            if (item_indexes.length == 1)
            {
                continue;
            }
            ++num_identical_items;
            for (let i = 1; i < item_indexes.length; ++i)
            {
                let prev_start_x = starts_by_dimension[item_indexes[i - 1]][0];
                let curr_start_x = starts_by_dimension[item_indexes[i]][0];
                let prev_start_y = starts_by_dimension[item_indexes[i - 1]][1];
                let curr_start_y = starts_by_dimension[item_indexes[i]][1];
                cp_model.AddLessOrEqual(
                    op.sat.operator_times(prev_start_x, bin_sizes[1]).operator_plus_eq(prev_start_y),
                    op.sat.operator_times(curr_start_x, bin_sizes[1]).operator_plus_eq(curr_start_y)
                );
            }
            if (num_identical_items > 0)
            {
                console.log(num_identical_items + " identical items");
            }
        }
        for (let b = 0; b < max_bins; ++b)
        {
            let no_overlap_2d = cp_model.AddNoOverlap2D();
            for (let item = 0; item < num_items; ++item)
            {
                no_overlap_2d.AddRectangle(interval_by_item_bin_dimension[item][b][0], interval_by_item_bin_dimension[item][b][1]);
            }
        }
        let obj = cp_model.NewIntVar(new op.Domain(trivial_lb, max_bins));
        if (true)
        {
            if (num_dimensions != 2)
            {
                console.log("Global cumulative is only supported for 2D problems");
            }
            else
            {
                for (let dim = 0; dim < num_dimensions; ++dim)
                {
                    let other_size = bin_sizes[1 - dim];
                    let cumul = cp_model.AddCumulative(op.sat.operator_times(obj, other_size));
                    for (let item = 0; item < num_items; ++item)
                    {
                        let size = problem.items(item).shapes(0).dimensions()[dim];
                        let demand = problem.items(item).shapes(0).dimensions()[1 - dim];
                        cumul.AddDemand(cp_model.NewFixedSizeIntervalVar(starts_by_dimension[item][dim], size), demand);
                    }
                }
            }
        }
        let bin_is_used: op.sat.BoolVar[] = [];
        for (let b = 0; b < max_bins; ++b)
        {
            bin_is_used.push(cp_model.NewBoolVar());
            let all_items_in_bin: op.sat.BoolVar[] = [];
            for (let item = 0; item < num_items; ++item)
            {
                cp_model.AddImplication(item_to_bin[item][b], bin_is_used[b]);
                all_items_in_bin.push(item_to_bin[item][b]);
            }
            cp_model.AddBoolOr(all_items_in_bin).OnlyEnforceIf(bin_is_used[b]);
        }
        cp_model.Minimize(obj);
        if (true)
        {
            let not_placed_items: number[] = [];
            for (let item = 0; item < num_items; ++item)
            {
                if (!fixed_items.has(item))
                {
                    not_placed_items.push(item);
                }
            }
            not_placed_items.sort(function (a, b)
            {
                let a_sizes = problem.items(a).shapes(0).dimensions();
                let b_sizes = problem.items(b).shapes(0).dimensions();
                return a_sizes[0] * a_sizes[1] > b_sizes[0] * b_sizes[1] ? a : b;
            });
            let first_empty_bin = fixed_items.size;
            for (let item of not_placed_items)
            {
                if (first_empty_bin + 1 >= max_bins) break;
                for (let b = first_empty_bin + 1; b < max_bins; ++b)
                {
                    cp_model.FixVariable(item_to_bin[item][b], false);
                }
                ++first_empty_bin;
            }
        }
        let parameters = new op.sat.SatParameters();
        parameters.set_log_search_progress(true);
        if (parameters.num_workers() >= 16 && parameters.num_workers() < 24)
        {
            parameters.add_ignore_subsolvers("objective_lb_search");
            parameters.add_extra_subsolvers("objective_shaving_search");
        }
        let response = op.sat.SolveWithParameters(cp_model.Build(), parameters);
    }
}
test();
