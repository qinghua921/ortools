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

// CpSolverResponse Solve( const CpModelProto& model_proto );
export function Solve(model_proto: CpModelProto): Promise<CpSolverResponse>;

// int64_t SolutionIntegerValue( const CpSolverResponse& r, const LinearExpr& expr );
export function SolutionIntegerValue(r: CpSolverResponse, expr: CanAsLinearExpr): number;

/// Evaluates the value of a Boolean literal in a solver response.
// bool SolutionBooleanValue( const CpSolverResponse& r, BoolVar x );
export function SolutionBooleanValue(r: CpSolverResponse, x: BoolVar): boolean;

// std::string CpSolverResponseStats( const CpSolverResponse& response, bool has_objective = true );
export function CpSolverResponseStats(response: CpSolverResponse, has_objective: boolean = true): string;

// CpSolverResponse SolveWithParameters(const CpModelProto& model_proto, const SatParameters& params);
export function SolveWithParameters(model_proto: CpModelProto, params: SatParameters): CpSolverResponse;

// BoolVar Not(BoolVar x);
export function Not(x: BoolVar): BoolVar;

// std::function<SatParameters(Model*)> NewSatParameters( const SatParameters& parameters);
export function NewSatParameters(parameters: SatParameters): (model: Model) => SatParameters;
// std::function<SatParameters(Model*)> NewSatParameters( const std::string& params);
export function NewSatParameters(params: string): (model: Model) => SatParameters;

// CpSolverResponse SolveCpModel(const CpModelProto& model_proto, Model* model);
export function SolveCpModel(model_proto: CpModelProto, model: Model): Promise<CpSolverResponse>;

// std::function<void(Model*)> NewFeasibleSolutionObserver( const std::function<void(const CpSolverResponse& response)>& observer);
export function NewFeasibleSolutionObserver(observer: (response: CpSolverResponse) => void): (model: Model) => void;
