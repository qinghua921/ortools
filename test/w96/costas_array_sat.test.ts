
// #include <cstdint>
// #include <ctime>
// #include <set>
// #include <string>
// #include <utility>
// #include <vector>

// #include "absl/flags/flag.h"
// #include "absl/strings/str_cat.h"
// #include "absl/strings/str_format.h"
// #include "ortools/base/init_google.h"
// #include "ortools/base/integral_types.h"
// #include "ortools/base/logging.h"
// #include "ortools/sat/cp_model.h"
// #include "ortools/sat/model.h"

// ABSL_FLAG( int, minsize, 0, "Minimum problem size." );
// ABSL_FLAG( int, maxsize, 0, "Maximum problem size." );
// ABSL_FLAG( int, model, 1,
//            "Model type: 1 integer variables hard, 2 boolean variables, 3 "
//            "boolean_variable soft" );
// ABSL_FLAG( std::string, params, "", "Sat parameters." );

// namespace operations_research
// {
// namespace sat
// {



//     // Computes a Costas Array.
//     void CostasHard( const int dim )
//     {
//         CpModelBuilder cp_model;

//         // create the variables
//         std::vector< IntVar > vars;
//         Domain                domain( 1, dim );
//         for ( int i = 0; i < dim; ++i )
//         {
//             vars.push_back(
//                 cp_model.NewIntVar( domain ).WithName( absl::StrCat( "var_", i ) ) );
//         }

//         cp_model.AddAllDifferent( vars );

//         // Check that the pairwise difference is unique
//         for ( int i = 1; i < dim; ++i )
//         {
//             std::vector< IntVar > subset;
//             Domain                difference_domain( -dim, dim );

//             for ( int j = 0; j < dim - i; ++j )
//             {
//                 IntVar diff = cp_model.NewIntVar( difference_domain );
//                 subset.push_back( diff );
//                 cp_model.AddEquality( diff, vars[ j + i ] - vars[ j ] );
//             }

//             cp_model.AddAllDifferent( subset );
//         }

//         Model model;
//         if ( !absl::GetFlag( FLAGS_params ).empty() )
//         {
//             model.Add( NewSatParameters( absl::GetFlag( FLAGS_params ) ) );
//         }
//         const CpSolverResponse response = SolveCpModel( cp_model.Build(), &model );

//         if ( response.status() == CpSolverStatus::OPTIMAL )
//         {
//             std::vector< int64_t > costas_matrix;
//             std::string            output;

//             for ( int n = 0; n < dim; ++n )
//             {
//                 const int64_t v = SolutionIntegerValue( response, vars[ n ] );
//                 costas_matrix.push_back( v );
//                 absl::StrAppendFormat( &output, "%3lld", v );
//             }

//             LOG( INFO ) << output << " (" << response.wall_time() << " s)";

//             CHECK( CheckCostas( costas_matrix ) )
//                 << ": Solution is not a valid Costas Matrix.";
//         }
//         else
//         {
//             LOG( INFO ) << "No solution found.";
//         }
//     }

//     // Computes a Costas Array.
//     void CostasBool( const int dim )
//     {
//         CpModelBuilder cp_model;

//         // create the variables
//         std::vector< std::vector< BoolVar > > vars( dim );
//         std::vector< std::vector< BoolVar > > transposed_vars( dim );
//         for ( int i = 0; i < dim; ++i )
//         {
//             for ( int j = 0; j < dim; ++j )
//             {
//                 const BoolVar var = cp_model.NewBoolVar();
//                 vars[ i ].push_back( var );
//                 transposed_vars[ j ].push_back( var );
//             }
//         }

//         for ( int i = 0; i < dim; ++i )
//         {
//             cp_model.AddEquality( LinearExpr::Sum( vars[ i ] ), 1 );
//             cp_model.AddEquality( LinearExpr::Sum( transposed_vars[ i ] ), 1 );
//         }

//         // Check that the pairwise difference is unique
//         for ( int step = 1; step < dim; ++step )
//         {
//             for ( int diff = 1; diff < dim - 1; ++diff )
//             {
//                 std::vector< BoolVar > positive_diffs;
//                 std::vector< BoolVar > negative_diffs;
//                 for ( int var = 0; var < dim - step; ++var )
//                 {
//                     for ( int value = 0; value < dim - diff; ++value )
//                     {
//                         const BoolVar pos = cp_model.NewBoolVar();
//                         const BoolVar neg = cp_model.NewBoolVar();
//                         positive_diffs.push_back( pos );
//                         negative_diffs.push_back( neg );
//                         cp_model.AddBoolOr( { Not( vars[ var ][ value ] ),
//                                               Not( vars[ var + step ][ value + diff ] ), pos } );
//                         cp_model.AddBoolOr( { Not( vars[ var ][ value + diff ] ),
//                                               Not( vars[ var + step ][ value ] ), neg } );
//                     }
//                 }
//                 cp_model.AddLessOrEqual( LinearExpr::Sum( positive_diffs ), 1 );
//                 cp_model.AddLessOrEqual( LinearExpr::Sum( negative_diffs ), 1 );
//             }
//         }

//         Model model;
//         if ( !absl::GetFlag( FLAGS_params ).empty() )
//         {
//             model.Add( NewSatParameters( absl::GetFlag( FLAGS_params ) ) );
//         }
//         const CpSolverResponse response = SolveCpModel( cp_model.Build(), &model );

//         if ( response.status() == CpSolverStatus::OPTIMAL )
//         {
//             std::vector< int64_t > costas_matrix;
//             std::string            output;

//             for ( int n = 0; n < dim; ++n )
//             {
//                 for ( int v = 0; v < dim; ++v )
//                 {
//                     if ( SolutionBooleanValue( response, vars[ n ][ v ] ) )
//                     {
//                         costas_matrix.push_back( v + 1 );
//                         absl::StrAppendFormat( &output, "%3lld", v + 1 );
//                         break;
//                     }
//                 }
//             }

//             LOG( INFO ) << output << " (" << response.wall_time() << " s)";

//             CHECK( CheckCostas( costas_matrix ) )
//                 << ": Solution is not a valid Costas Matrix.";
//         }
//         else
//         {
//             LOG( INFO ) << "No solution found.";
//         }
//     }

//     // Computes a Costas Array with a minimization objective.
//     void CostasBoolSoft( const int dim )
//     {
//         CpModelBuilder cp_model;

//         // create the variables
//         std::vector< std::vector< BoolVar > > vars( dim );
//         std::vector< std::vector< BoolVar > > transposed_vars( dim );
//         for ( int i = 0; i < dim; ++i )
//         {
//             for ( int j = 0; j < dim; ++j )
//             {
//                 const BoolVar var = cp_model.NewBoolVar();
//                 vars[ i ].push_back( var );
//                 transposed_vars[ j ].push_back( var );
//             }
//         }

//         for ( int i = 0; i < dim; ++i )
//         {
//             cp_model.AddEquality( LinearExpr::Sum( vars[ i ] ), 1 );
//             cp_model.AddEquality( LinearExpr::Sum( transposed_vars[ i ] ), 1 );
//         }

//         std::vector< IntVar > all_violations;
//         // Check that the pairwise difference is unique
//         for ( int step = 1; step < dim; ++step )
//         {
//             for ( int diff = 1; diff < dim - 1; ++diff )
//             {
//                 std::vector< BoolVar > positive_diffs;
//                 std::vector< BoolVar > negative_diffs;
//                 for ( int var = 0; var < dim - step; ++var )
//                 {
//                     for ( int value = 0; value < dim - diff; ++value )
//                     {
//                         const BoolVar pos = cp_model.NewBoolVar();
//                         const BoolVar neg = cp_model.NewBoolVar();
//                         positive_diffs.push_back( pos );
//                         negative_diffs.push_back( neg );
//                         cp_model.AddBoolOr( { Not( vars[ var ][ value ] ),
//                                               Not( vars[ var + step ][ value + diff ] ), pos } );
//                         cp_model.AddBoolOr( { Not( vars[ var ][ value + diff ] ),
//                                               Not( vars[ var + step ][ value ] ), neg } );
//                     }
//                 }
//                 const IntVar pos_var =
//                     cp_model.NewIntVar( Domain( 0, positive_diffs.size() ) );
//                 const IntVar neg_var =
//                     cp_model.NewIntVar( Domain( 0, negative_diffs.size() ) );
//                 cp_model.AddGreaterOrEqual( pos_var, LinearExpr::Sum( positive_diffs ) - 1 );
//                 cp_model.AddGreaterOrEqual( neg_var, LinearExpr::Sum( negative_diffs ) - 1 );
//                 all_violations.push_back( pos_var );
//                 all_violations.push_back( neg_var );
//             }
//         }

//         cp_model.Minimize( LinearExpr::Sum( all_violations ) );

//         Model model;
//         if ( !absl::GetFlag( FLAGS_params ).empty() )
//         {
//             model.Add( NewSatParameters( absl::GetFlag( FLAGS_params ) ) );
//         }
//         const CpSolverResponse response = SolveCpModel( cp_model.Build(), &model );

//         if ( response.status() == CpSolverStatus::OPTIMAL )
//         {
//             std::vector< int64_t > costas_matrix;
//             std::string            output;

//             for ( int n = 0; n < dim; ++n )
//             {
//                 for ( int v = 0; v < dim; ++v )
//                 {
//                     if ( SolutionBooleanValue( response, vars[ n ][ v ] ) )
//                     {
//                         costas_matrix.push_back( v + 1 );
//                         absl::StrAppendFormat( &output, "%3lld", v + 1 );
//                         break;
//                     }
//                 }
//             }

//             LOG( INFO ) << output << " (" << response.wall_time() << " s)";

//             CHECK( CheckCostas( costas_matrix ) )
//                 << ": Solution is not a valid Costas Matrix.";
//         }
//         else
//         {
//             LOG( INFO ) << "No solution found.";
//         }
//     }

// }  // namespace sat
// }  // namespace operations_research

// int main( int argc, char** argv )
// {
//     absl::SetFlag( &FLAGS_stderrthreshold, 0 );
//     InitGoogle( argv[ 0 ], &argc, &argv, true );

//     int min = 1;
//     int max = 10;

//     if ( absl::GetFlag( FLAGS_minsize ) != 0 )
//     {
//         min = absl::GetFlag( FLAGS_minsize );

//         if ( absl::GetFlag( FLAGS_maxsize ) != 0 )
//         {
//             max = absl::GetFlag( FLAGS_maxsize );
//         }
//         else
//         {
//             max = min;
//         }
//     }

//     for ( int size = min; size <= max; ++size )
//     {
//         LOG( INFO ) << "Computing Costas Array for dim = " << size;
//         if ( absl::GetFlag( FLAGS_model ) == 1 )
//         {
//             operations_research::sat::CostasHard( size );
//         }
//         else if ( absl::GetFlag( FLAGS_model ) == 2 )
//         {
//             operations_research::sat::CostasBool( size );
//         }
//         else if ( absl::GetFlag( FLAGS_model ) == 3 )
//         {
//             operations_research::sat::CostasBoolSoft( size );
//         }
//     }

//     return EXIT_SUCCESS;
// }

import { operations_research } from "../../src";

test('ts-ortools', async () =>
{
    let minsize = 0;
    let maxsize = 0;
    let model = 1;
    let params = "";

    function CheckConstraintViolators(vars: number[], violators: number[])
    {
        let dim = vars.length;

        // Check that all indices are unique
        for (let i = 0; i < dim; ++i)
        {
            for (let k = i + 1; k < dim; ++k)
            {
                if (vars[i] == vars[k])
                {
                    violators.push(i);
                    violators.push(k);
                }
            }
        }

        // Check that all differences are unique for each level
        for (let level = 1; level < dim; ++level)
        {
            for (let i = 0; i < dim - level; ++i)
            {
                const difference = vars[i + level] - vars[i];

                for (let j = i + 1; j < dim - level; ++j)
                {
                    if (vars[j + level] - vars[j] == difference)
                    {
                        violators.push(j + level);
                        violators.push(j);
                        violators.push(i + level);
                        violators.push(i);
                    }
                }
            }
        }
    }

    function CheckCostas(vars: number[]): boolean
    {
        let violators: number[] = [];
        CheckConstraintViolators(vars, violators);
        return violators.length == 0;
    }


    async function CostasHard(dim: number)
    {
        const cp_model = new operations_research.sat.CpModelBuilder();
        const vars: operations_research.sat.IntVar[] = [];
        const domain = new operations_research.Domain(1, dim);
        for (let i = 0; i < dim; ++i)
        {
            vars.push(cp_model.NewIntVar(domain).WithName("var_" + i));
        }
        cp_model.AddAllDifferent(vars);

        // Check that the pairwise difference is unique
        for (let i = 1; i < dim; ++i)
        {
            const subset: operations_research.sat.IntVar[] = [];
            const difference_domain = new operations_research.Domain(-dim, dim);

            for (let j = 0; j < dim - i; ++j)
            {
                const diff = cp_model.NewIntVar(difference_domain);
                subset.push(diff);
                cp_model.AddEquality(diff, operations_research.sat.operator_minus(vars[j + i], vars[j]));
            }
            cp_model.AddAllDifferent(subset);
        }

        const model = new operations_research.sat.Model();
        if (params != "")
        {
            model.Add(operations_research.sat.NewSatParameters(params));
        }
        const response = await operations_research.sat.SolveCpModel(cp_model.Build(), model);

        if (response.status() == operations_research.sat.CpSolverStatus.OPTIMAL)
        {
            const costas_matrix: number[] = [];
            let output = "";

            for (let n = 0; n < dim; ++n)
            {
                const v = operations_research.sat.SolutionIntegerValue(response, vars[n]);
                costas_matrix.push(v);
                output += " " + v.toString().padStart(3, "0");
            }

            console.log(output + " (" + response.wall_time().toString() + " s)");

            if (!CheckCostas(costas_matrix))
            {
                console.log("Solution is not a valid Costas Matrix.");
            }
            else
            {
                console.log("Solution is a valid Costas Matrix.");
            }
        }
        else
        {
            console.log("No solution found.");
        }
    }

    async function CostasBool(dim: number)
    {
        const cp_model = new operations_research.sat.CpModelBuilder();
        const vars: operations_research.sat.BoolVar[][] = [];
        const transposed_vars: operations_research.sat.BoolVar[][] = [];
        for (let i = 0; i < dim; ++i)
        {
            const row: operations_research.sat.BoolVar[] = [];
            vars.push(row);
            const transposed_row: operations_research.sat.BoolVar[] = [];
            transposed_vars.push(transposed_row);
            for (let j = 0; j < dim; ++j)
            {
                const var_ = cp_model.NewBoolVar();
                row.push(var_);
                transposed_row.push(var_);
            }
        }

        for (let i = 0; i < dim; ++i)   
        {
            cp_model.AddEquality(operations_research.sat.LinearExpr.Sum(vars[i]), 1);
            cp_model.AddEquality(operations_research.sat.LinearExpr.Sum(transposed_vars[i]), 1);
        }

        // Check that the pairwise difference is unique
        for (let step = 1; step < dim; ++step)
        {
            for (let diff = 1; diff < dim - 1; ++diff)
            {
                const positive_diffs: operations_research.sat.BoolVar[] = [];
                const negative_diffs: operations_research.sat.BoolVar[] = [];
                for (let var_ = 0; var_ < dim - step; ++var_)
                {
                    for (let value = 0; value < dim - diff; ++value)
                    {
                        const pos = cp_model.NewBoolVar();
                        const neg = cp_model.NewBoolVar();
                        positive_diffs.push(pos);
                        negative_diffs.push(neg);
                        cp_model.AddBoolOr([
                            operations_research.sat.Not(vars[var_][value]),
                            operations_research.sat.Not(vars[var_ + step][value + diff]),
                            pos
                        ]);
                        cp_model.AddBoolOr([
                            operations_research.sat.Not(vars[var_][value + diff]),
                            operations_research.sat.Not(vars[var_ + step][value]),
                            neg
                        ]);
                    }
                }
                cp_model.AddLessOrEqual(operations_research.sat.LinearExpr.Sum(positive_diffs), 1);
                cp_model.AddLessOrEqual(operations_research.sat.LinearExpr.Sum(negative_diffs), 1);
            }
        }

        const model = new operations_research.sat.Model();
        if (params != "")
        {
            model.Add(operations_research.sat.NewSatParameters(params));
        }
        const response = await operations_research.sat.SolveCpModel(cp_model.Build(), model);

        if (response.status() == operations_research.sat.CpSolverStatus.OPTIMAL)
        {
            const costas_matrix: number[] = [];
            let output = "";

            for (let n = 0; n < dim; ++n)
            {
                for (let v = 0; v < dim; ++v)
                {
                    if (operations_research.sat.SolutionBooleanValue(response, vars[n][v]))
                    {
                        costas_matrix.push(v + 1);
                        output += " " + (v + 1).toString().padStart(3, "0");
                        break;
                    }
                }
            }

            console.log(output + " (" + response.wall_time().toString() + " s)");

            if (!CheckCostas(costas_matrix))
            {
                console.log("Solution is not a valid Costas Matrix.");
            }
            else
            {
                console.log("Solution is a valid Costas Matrix.");
            }
        }
        else
        {
            console.log("No solution found.");
        }
    }

    async function CostasBoolSoft(dim: number)
    {
        const cp_model = new operations_research.sat.CpModelBuilder();
        const vars: operations_research.sat.BoolVar[][] = [];
        const transposed_vars: operations_research.sat.BoolVar[][] = [];
        for (let i = 0; i < dim; ++i)
        {
            const row: operations_research.sat.BoolVar[] = [];
            vars.push(row);
            const transposed_row: operations_research.sat.BoolVar[] = [];
            transposed_vars.push(transposed_row);
            for (let j = 0; j < dim; ++j)
            {
                const var_ = cp_model.NewBoolVar();
                row.push(var_);
                transposed_row.push(var_);
            }
        }

        for (let i = 0; i < dim; ++i)   
        {
            cp_model.AddEquality(operations_research.sat.LinearExpr.Sum(vars[i]), 1);
            cp_model.AddEquality(operations_research.sat.LinearExpr.Sum(transposed_vars[i]), 1);
        }

        let all_violations: operations_research.sat.IntVar[] = [];
        // Check that the pairwise difference is unique
        for (let step = 1; step < dim; ++step)
        {
            for (let diff = 1; diff < dim - 1; ++diff)
            {
                const positive_diffs: operations_research.sat.BoolVar[] = [];
                const negative_diffs: operations_research.sat.BoolVar[] = [];
                for (let var_ = 0; var_ < dim - step; ++var_)
                {
                    for (let value = 0; value < dim - diff; ++value)
                    {
                        const pos = cp_model.NewBoolVar();
                        const neg = cp_model.NewBoolVar();
                        positive_diffs.push(pos);
                        negative_diffs.push(neg);
                        cp_model.AddBoolOr([
                            operations_research.sat.Not(vars[var_][value]),
                            operations_research.sat.Not(vars[var_ + step][value + diff]),
                            pos
                        ]);
                        cp_model.AddBoolOr([
                            operations_research.sat.Not(vars[var_][value + diff]),
                            operations_research.sat.Not(vars[var_ + step][value]),
                            neg
                        ]);
                    }
                }
                const pos_var = cp_model.NewIntVar(operations_research.Domain.FromFlatIntervals([0, positive_diffs.length]));
                const neg_var = cp_model.NewIntVar(operations_research.Domain.FromFlatIntervals([0, negative_diffs.length]));
                cp_model.AddGreaterOrEqual(pos_var,
                    operations_research.sat.operator_minus(
                        operations_research.sat.LinearExpr.Sum(positive_diffs), 1)
                );
                cp_model.AddGreaterOrEqual(neg_var,
                    operations_research.sat.operator_minus(
                        operations_research.sat.LinearExpr.Sum(negative_diffs), 1)
                );
                all_violations.push(pos_var);
                all_violations.push(neg_var);
            }
        }
        cp_model.Minimize(operations_research.sat.LinearExpr.Sum(all_violations));

        const model = new operations_research.sat.Model();
        if (params != "")
        {
            model.Add(operations_research.sat.NewSatParameters(params));
        }
        const response = await operations_research.sat.SolveCpModel(cp_model.Build(), model);

        if (response.status() == operations_research.sat.CpSolverStatus.OPTIMAL)
        {
            const costas_matrix: number[] = [];
            let output = "";

            for (let n = 0; n < dim; ++n)
            {
                for (let v = 0; v < dim; ++v)
                {
                    if (operations_research.sat.SolutionBooleanValue(response, vars[n][v]))
                    {
                        costas_matrix.push(v + 1);
                        output += " " + (v + 1).toString().padStart(3, "0");
                        break;
                    }
                }
            }

            console.log(output + " (" + response.wall_time().toString() + " s)");

            if (!CheckCostas(costas_matrix))
            {
                console.log("Solution is not a valid Costas Matrix.");
            }
            else
            {
                console.log("Solution is a valid Costas Matrix.");
            }
        }
        else
        {
            console.log("No solution found.");
        }
    }

    let min = 1;
    let max = 10;

    if (minsize != 0)
    {
        min = minsize;

        if (maxsize != 0)
        {
            max = maxsize;
        }
        else
        {
            max = min;
        }
    }

    for (let size = min; size <= max; ++size)
    {
        console.log("Computing Costas Array for dim = " + size);
        if (model == 1)
        {
            await CostasHard(size);
        }
        else if (model == 2)
        {
            CostasBool(size);
        }
        else if (model == 3)
        {
            CostasBoolSoft(size);
        }
    }
});