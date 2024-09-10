import { BoolVar } from './GBoolVar';
import { CpModelProto } from './GCpModelProto';
import { CpSolverResponse } from './GCpSolverResponse';
import { CanAsLinearExpr, LinearExpr } from './GLinearExpr';
import { Model } from './GModel';
import { SatParameters } from './GSatParameters';

// inline LinearExpr operator-( LinearExpr expr )
export function operator_negate(expr: CanAsLinearExpr): LinearExpr;

// inline LinearExpr operator+( LinearExpr&& lhs, const LinearExpr& rhs )
// inline LinearExpr operator+( const LinearExpr& lhs, LinearExpr&& rhs )
// inline LinearExpr operator+( LinearExpr&& lhs, LinearExpr&& rhs )
// inline LinearExpr operator+( const LinearExpr& lhs, const LinearExpr& rhs )
export function operator_plus(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearExpr;

// inline LinearExpr operator-( const LinearExpr& lhs, const LinearExpr& rhs )
// inline LinearExpr operator-( LinearExpr&& lhs, const LinearExpr& rhs )
// inline LinearExpr operator-( const LinearExpr& lhs, LinearExpr&& rhs )
// inline LinearExpr operator-( LinearExpr&& lhs, LinearExpr&& rhs )
export function operator_minus(lhs: CanAsLinearExpr, rhs: CanAsLinearExpr): LinearExpr;

// inline LinearExpr operator*( LinearExpr expr, int64_t factor )
export function operator_times(expr: CanAsLinearExpr, factor: number): LinearExpr;

// inline LinearExpr operator*( int64_t factor, LinearExpr expr )
export function operator_times(factor: number, expr: CanAsLinearExpr): LinearExpr;

/// Solves the given CpModelProto and returns an instance of CpSolverResponse.
// CpSolverResponse Solve( const CpModelProto& model_proto );
export function Solve(model_proto: CpModelProto): CpSolverResponse;

/// Evaluates the value of an linear expression in a solver response.
// int64_t SolutionIntegerValue( const CpSolverResponse& r, const LinearExpr& expr );
export function SolutionIntegerValue(r: CpSolverResponse, expr: CanAsLinearExpr): number;

/// Evaluates the value of a Boolean literal in a solver response.
// bool SolutionBooleanValue( const CpSolverResponse& r, BoolVar x );
export function SolutionBooleanValue(r: CpSolverResponse, x: BoolVar): boolean;

//    /** Returns a string with some statistics on the solver response.
//      *
//      * If the second argument is false, we will just display NA for the objective
//      * value instead of zero. It is not really needed but it makes things a bit
//      * clearer to see that there is no objective.
//      */
//    std::string CpSolverResponseStats( const CpSolverResponse& response,
//     bool                    has_objective = true );
export function CpSolverResponseStats(response: CpSolverResponse, has_objective: boolean = true): string;


// /// Solves the given CpModelProto with the given parameters.
// CpSolverResponse SolveWithParameters(const CpModelProto& model_proto,
//     const SatParameters& params);
export function SolveWithParameters(model_proto: CpModelProto, params: SatParameters): CpSolverResponse;

/**
 * A convenient wrapper so we can write Not(x) instead of x.Not() which is
 * sometimes clearer.
 */
// BoolVar Not(BoolVar x);
export function Not(x: BoolVar): BoolVar;

// std::function<SatParameters(Model*)> NewSatParameters( const SatParameters& parameters);
export function NewSatParameters(parameters: SatParameters): (model: Model) => SatParameters;

/**
 * Solves the given CpModelProto.
 *
 * This advanced API accept a Model* which allows to access more adavanced
 * features by configuring some classes in the Model before solve.
 *
 * For instance:
 * - model->Add(NewSatParameters(parameters_as_string_or_proto));
 * - model->GetOrCreate<TimeLimit>()->RegisterExternalBooleanAsLimit(&stop);
 * - model->Add(NewFeasibleSolutionObserver(observer));
 */
// CpSolverResponse SolveCpModel(const CpModelProto& model_proto, Model* model);
export function SolveCpModel(model_proto: CpModelProto, model: Model): CpSolverResponse;


/**
 * Creates a solution observer with the model with
 *   model.Add(NewFeasibleSolutionObserver([](response){...}));
 *
 * The given function will be called on each improving feasible solution found
 * during the search. For a non-optimization problem, if the option to find all
 * solution was set, then this will be called on each new solution.
 *
 * WARNING: Except when enumerate_all_solution() is true, one shouldn't rely on
 * this to get a set of "diverse" solutions since any future change to the
 * solver might completely kill any diversity in the set of solutions observed.
 *
 * Valid usage of this includes implementing features like:
 *  - Enumerating all solution via enumerate_all_solution(). If only n solutions
 *    are needed, this can also be used to abort when this number is reached.
 *  - Aborting early if a good enough solution is found.
 *  - Displaying log progress.
 *  - etc...
 */
// std::function<void(Model*)> NewFeasibleSolutionObserver(
//     const std::function<void(const CpSolverResponse& response)>& observer);
export function NewFeasibleSolutionObserver(observer: (response: CpSolverResponse) => void): (model: Model) => void;
