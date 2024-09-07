# ortools

> Google Or-Tools for TS

This is a TypeScript wrapper for the [Google OR-Tools](https://github.com/google/or-tools) library.
The corresponding version is [v9.6](https://github.com/google/or-tools/releases/tag/v9.6).

The code is still being written, and if you have any questions, you can submit an issue.

## Note

The code is written on Windows; other platforms **may not work**.
You should build the library yourself.

## How to use

Please refer to the C++ usage and examples in `cmake/or-tools_x64_VisualStudio2019_cpp_v9.6.2534/examples`.

I have made its usage similar to C++ style with a few changes to C++ operators.

## How to build

- Download [or-tools_x64_VisualStudio2019_cpp_v9.6.2534.zip](https://github.com/google/or-tools/releases/download/v9.6/or-tools_x64_VisualStudio2019_cpp_v9.6.2534.zip) and unzip it to `./cmake`.
- Download [protoc-21.12-win64.zip](https://github.com/protocolbuffers/protobuf/releases/download/v21.12/protoc-21.12-win64.zip) and [v9.6.zip](https://github.com/google/or-tools/archive/refs/tags/v9.6.zip) (for transforming protobuf files if needed).
- Run `npm run cppbuild`.

## How to contribute

Some C++ classes are not yet implemented, and some classes are not defined. The code is organized according to the namespace of the C++ class. If needed, you can reorganize it accordingly.

I have added a template (`Demo.hpp`, `Demo.d.ts`):

To add a new class (e.g., `Foo`):

- Copy `Demo.hpp` and `Demo.d.ts`.
- Rename them to `Foo.hpp` and `Foo.d.ts`.
- Replace occurrences of `Demo` with `Foo` in `Foo.hpp`.
- Add the C++ code for `Foo` to `Foo.d.ts` and comment out any missing methods.
- Add the declaration of `Foo` in `index.d.ts` and `index.cpp`.

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
- assignment_teams_sat - 🆗
- assumptions_sample_sat - 🆗
- balance_min_flow - 🆗
- basic_example - 🆗
- basic_example_mo - ❌ ( math_opt compiliertor error )
- bin_packing_mip - 🆗
- binpacking_2d_sat
- binpacking_problem_sat
- bool_or_sample_sat
- channeling_sample_sat
- cocktail_hour_mo
- constraint_programming_cp
- copy_model_sample_sat
- costas_array_sat
- course_scheduling
- course_scheduling_run
- cp_is_fun_cp
- cp_is_fun_sat
- cp_sat_example - 🆗
- cryptarithm_sat
- cutting_stock_mo
- cvrp_disjoint_tw
- cvrptw
- cvrptw_soft_capacity
- cvrptw_with_breaks
- cvrptw_with_precedences
- cvrptw_with_refueling
- cvrptw_with_resources
- cvrptw_with_stop_times_and_resources
- cvrptw_with_time_dependent_costs
- dimacs_assignment
- dobble_ls
- earliness_tardiness_cost_sample_sat
- facility_lp_benders_mo
- flow_api
- frequency_assignment_problem
- golomb_sat
- integer_programming
- integer_programming_example
- integer_programming_mo
- interval_sample_sat
- jobshop_sat
- knapsack
- knapsack_2d_sat
- lagrangian_relaxation_mo
- linear_assignment_api
- linear_programming
- linear_programming_example
- linear_programming_mo
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
- tsp_mo
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
