# ortools

> Google Or-Tools for TS

This is a TypeScript wrapper for the [Google OR-Tools](https://github.com/google/or-tools) library.
The corresponding version is [v9.11](https://github.com/google/or-tools/releases/tag/v9.11).

## Warning

The code is written on Windows; other platforms **may not work**.
You should build the library yourself.

## How to use

Please refer to the C++ usage.
I have made its usage similar to C++ style with a few changes to C++ operators.

## How to build

- Download [or-tools_x64_VisualStudio2022_cpp_v9.11.4210.zip](https://github.com/google/or-tools/releases/download/v9.11/or-tools_x64_VisualStudio2022_cpp_v9.11.4210.zip) and unzip it to `./cmake`.
- Run `npm run cppbuild`.

## How to contribute

Some C++ classes are not yet implemented, and some classes are not defined. The code is organized according to the namespace of the C++ class. If needed, you can reorganize it accordingly.

## Progress

The codebase is large, and the priority is to implement the code in the examples directory.

- assignment_groups_mip - 🆗
- assignment_groups_sat - 🆗
- assignment_linear_sum_assignment - 🆗
- assignment_min_flow - 🆗
- assignment_mip - 🆗
- assignment_sat - 🆗
- assignment_task_sizes_mip - 🆗
- assignment_task_sizes_sat - 🆗
- assignment_teams_mip - 🆗
- assignment_teams_sat
- assumptions_sample_sat
- balance_min_flow
- basic_example
- bfs_directed
- bfs_one_to_all
- bfs_undirected
- bin_packing_mip
- binpacking_2d_sat
- binpacking_problem_sat
- bool_or_sample_sat
- channeling_sample_sat
- clone_model_sample_sat
- constraint_programming_cp
- costas_array_sat
- course_scheduling
- course_scheduling_run
- cp_is_fun_cp
- cp_is_fun_sat
- cp_sat_example
- cryptarithm_sat
- cvrp_disjoint_tw
- cvrptw
- cvrptw_soft_capacity
- cvrptw_with_breaks
- cvrptw_with_precedences
- cvrptw_with_refueling
- cvrptw_with_resources
- cvrptw_with_stop_times_and_resources
- cvrptw_with_time_dependent_costs
- dag_constrained_shortest_path_sequential
- dag_multiple_shortest_paths_one_to_all
- dag_multiple_shortest_paths_sequential
- dag_shortest_path_one_to_all
- dag_shortest_path_sequential
- dag_simple_constrained_shortest_path
- dag_simple_multiple_shortest_paths
- dag_simple_shortest_path
- dijkstra_all_pairs_shortest_paths
- dijkstra_directed
- dijkstra_one_to_all
- dijkstra_sequential
- dijkstra_undirected
- dimacs_assignment
- dobble_ls
- earliness_tardiness_cost_sample_sat
- flow_api
- frequency_assignment_problem
- golomb_sat
- integer_programming
- integer_programming_example
- interval_sample_sat
- jobshop_sat
- knapsack
- knapsack_2d_sat
- linear_assignment_api
- linear_programming
- linear_programming_example
- linear_solver_protocol_buffers
- literal_sample_sat
- magic_sequence_sat
- magic_square_sat
- max_flow
- min_cost_flow
- minimal_jobshop_cp
- minimal_jobshop_sat
- mip_var_array
- mps_driver
- multi_knapsack_sat
- multiple_knapsack_mip
- multiple_knapsack_sat
- network_design_ilph
- network_design_ilph_main
- network_design_ilph_test
- network_routing_sat
- no_overlap_sample_sat
- non_linear_sat
- nqueens
- nqueens_cp
- nqueens_sat
- nurses_cp
- nurses_sat
- optional_interval_sample_sat
- pdlp_solve
- pdptw
- qap_sat
- rabbits_and_pheasants_cp
- rabbits_and_pheasants_sat
- random_tsp
- ranking_sample_sat
- reified_sample_sat
- root_a_tree
- rooted_tree_paths
- schedule_requests_sat
- search_for_all_solutions_sample_sat
- shift_minimization_sat
- simple_cp_program
- simple_glop_program
- simple_knapsack_program
- simple_lp_program
- simple_ls_program
- simple_max_flow_program
- simple_min_cost_flow_program
- simple_mip_program
- simple_pdlp_program
- simple_routing_program
- simple_sat_program
- slitherlink_sat
- solution_hinting_sample_sat
- solve_and_print_intermediate_solutions_sample_sat
- solve_with_time_limit_sample_sat
- sports_scheduling_sat
- step_function_sample_sat
- stigler_diet
- stop_after_n_solutions_sample_sat
- strawberry_fields_with_column_generation
- tsp
- tsp_circuit_board
- tsp_cities
- tsp_cities_routes
- tsp_distance_matrix
- uncapacitated_facility_location
- variable_intervals_sat
- vector_bin_packing_solver
- vrp
- vrp_breaks
- vrp_capacity
- vrp_drop_nodes
- vrp_global_span
- vrp_initial_routes
- vrp_pickup_delivery
- vrp_pickup_delivery_fifo
- vrp_pickup_delivery_lifo
- vrp_resources
- vrp_routes
- vrp_solution_callback
- vrp_starts_ends
- vrp_time_windows
- vrp_with_time_limit
- vrptw_store_solution_data
- weighted_tardiness_sat
- xpress_use
