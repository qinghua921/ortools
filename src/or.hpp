#pragma once

#include <napi.h>
#include <ortools/linear_solver/linear_solver.h>
#include <ortools/util/sorted_interval_list.h>

namespace operations_research
{

Napi::Value Goperator_ge(const Napi::CallbackInfo &info);
Napi::Value Goperator_eq(const Napi::CallbackInfo &info);
Napi::Value Goperator_le(const Napi::CallbackInfo &info);
Napi::Value Goperator_times(const Napi::CallbackInfo &info);
Napi::Object FuncInit(Napi::Env env, Napi::Object exports);

class GMPSolver : public Napi::ObjectWrap<GMPSolver>
{
  public:
    static inline Napi::FunctionReference constructor;
    MPSolver *pMPSolver = nullptr;
    GMPSolver(const Napi::CallbackInfo &info);
    ~GMPSolver();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);

    static Napi::Value CreateSolver(const Napi::CallbackInfo &info);
    static Napi::Value SupportsProblemType(const Napi::CallbackInfo &info);
    static Napi::Value ParseSolverType(const Napi::CallbackInfo &info);
    static Napi::Value ParseSolverTypeOrDie(const Napi::CallbackInfo &info);
    Napi::Value IsMIP(const Napi::CallbackInfo &info);
    Napi::Value Name(const Napi::CallbackInfo &info);
    Napi::Value ProblemType(const Napi::CallbackInfo &info);
    Napi::Value Clear(const Napi::CallbackInfo &info);
    Napi::Value NumVariables(const Napi::CallbackInfo &info);
    Napi::Value variables(const Napi::CallbackInfo &info);
    Napi::Value variable(const Napi::CallbackInfo &info);
    Napi::Value LookupVariableOrNull(const Napi::CallbackInfo &info);
    Napi::Value MakeVar(const Napi::CallbackInfo &info);
    Napi::Value MakeNumVar(const Napi::CallbackInfo &info);
    Napi::Value MakeIntVar(const Napi::CallbackInfo &info);
    Napi::Value MakeBoolVar(const Napi::CallbackInfo &info);
    Napi::Value MakeVarArray(const Napi::CallbackInfo &info);
    Napi::Value MakeNumVarArray(const Napi::CallbackInfo &info);
    Napi::Value MakeIntVarArray(const Napi::CallbackInfo &info);
    Napi::Value MakeBoolVarArray(const Napi::CallbackInfo &info);
    Napi::Value NumConstraints(const Napi::CallbackInfo &info);
    Napi::Value constraints(const Napi::CallbackInfo &info);
    Napi::Value constraint(const Napi::CallbackInfo &info);
    Napi::Value LookupConstraintOrNull(const Napi::CallbackInfo &info);
    Napi::Value MakeRowConstraint(const Napi::CallbackInfo &info);
    Napi::Value MutableObjective(const Napi::CallbackInfo &info);
    Napi::Value Solve(const Napi::CallbackInfo &info);
    Napi::Value Write(const Napi::CallbackInfo &info);
    Napi::Value ComputeConstraintActivities(const Napi::CallbackInfo &info);
    Napi::Value VerifySolution(const Napi::CallbackInfo &info);
    Napi::Value Reset(const Napi::CallbackInfo &info);
    Napi::Value InterruptSolve(const Napi::CallbackInfo &info);
    Napi::Value FillSolutionResponseProto(const Napi::CallbackInfo &info);
    static Napi::Value SolverTypeSupportsInterruption(const Napi::CallbackInfo &info);
    Napi::Value LoadSolutionFromProto(const Napi::CallbackInfo &info);
    Napi::Value ClampSolutionWithinBounds(const Napi::CallbackInfo &info);
    Napi::Value ExportModelAsLpFormat(const Napi::CallbackInfo &info);
    Napi::Value ExportModelAsMpsFormat(const Napi::CallbackInfo &info);
    Napi::Value SetNumThreads(const Napi::CallbackInfo &info);
    Napi::Value GetNumThreads(const Napi::CallbackInfo &info);
    Napi::Value SetSolverSpecificParametersAsString(const Napi::CallbackInfo &info);
    Napi::Value GetSolverSpecificParametersAsString(const Napi::CallbackInfo &info);
    Napi::Value SetHint(const Napi::CallbackInfo &info);
    static Napi::Value GetMPModelRequestLoggingInfo(const Napi::CallbackInfo &info);
    Napi::Value SetStartingLpBasis(const Napi::CallbackInfo &info);
    static Napi::Value infinity(const Napi::CallbackInfo &info);
    Napi::Value solver_infinity(const Napi::CallbackInfo &info);
    Napi::Value OutputIsEnabled(const Napi::CallbackInfo &info);
    Napi::Value EnableOutput(const Napi::CallbackInfo &info);
    Napi::Value SuppressOutput(const Napi::CallbackInfo &info);
    Napi::Value TimeLimit(const Napi::CallbackInfo &info);
    Napi::Value SetTimeLimit(const Napi::CallbackInfo &info);
    Napi::Value DurationSinceConstruction(const Napi::CallbackInfo &info);
    Napi::Value iterations(const Napi::CallbackInfo &info);
    Napi::Value nodes(const Napi::CallbackInfo &info);
    Napi::Value SolverVersion(const Napi::CallbackInfo &info);
    Napi::Value ComputeExactConditionNumber(const Napi::CallbackInfo &info);
    Napi::Value NextSolution(const Napi::CallbackInfo &info);
    Napi::Value SetCallback(const Napi::CallbackInfo &info);
    Napi::Value SupportsCallbacks(const Napi::CallbackInfo &info);
    static Napi::Value global_num_variables(const Napi::CallbackInfo &info);
    static Napi::Value global_num_constraints(const Napi::CallbackInfo &info);
    Napi::Value time_limit(const Napi::CallbackInfo &info);
    Napi::Value set_time_limit(const Napi::CallbackInfo &info);
    Napi::Value time_limit_in_secs(const Napi::CallbackInfo &info);
    Napi::Value wall_time(const Napi::CallbackInfo &info);
    Napi::Value OwnsVariable(const Napi::CallbackInfo &info);
};

class GMPVariable : public Napi::ObjectWrap<GMPVariable>
{
  public:
    static inline Napi::FunctionReference constructor;
    MPVariable *pMPVariable = nullptr;
    GMPVariable(const Napi::CallbackInfo &info);
    static Napi::Object Init(Napi::Env env, Napi::Object exports);

    Napi::Value name(const Napi::CallbackInfo &info);
    Napi::Value SetInteger(const Napi::CallbackInfo &info);
    Napi::Value integer(const Napi::CallbackInfo &info);
    Napi::Value solution_value(const Napi::CallbackInfo &info);
    Napi::Value index(const Napi::CallbackInfo &info);
    Napi::Value lb(const Napi::CallbackInfo &info);
    Napi::Value ub(const Napi::CallbackInfo &info);
    Napi::Value SetLB(const Napi::CallbackInfo &info);
    Napi::Value SetUB(const Napi::CallbackInfo &info);
    Napi::Value SetBounds(const Napi::CallbackInfo &info);
    Napi::Value unrounded_solution_value(const Napi::CallbackInfo &info);
    Napi::Value reduced_cost(const Napi::CallbackInfo &info);
    Napi::Value basis_status(const Napi::CallbackInfo &info);
    Napi::Value branching_priority(const Napi::CallbackInfo &info);
    Napi::Value SetBranchingPriority(const Napi::CallbackInfo &info);
};

class GMPCallback : public Napi::ObjectWrap<GMPCallback>
{
  public:
    static inline Napi::FunctionReference constructor;
    MPCallback *pMPCallback = nullptr;
    GMPCallback(const Napi::CallbackInfo &info);
    ~GMPCallback();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);

    Napi::Value RunCallback(const Napi::CallbackInfo &info);
    Napi::Value might_add_cuts(const Napi::CallbackInfo &info);
    Napi::Value might_add_lazy_constraints(const Napi::CallbackInfo &info);
};

class GMPModelRequest : public Napi::ObjectWrap<GMPModelRequest>
{
  public:
    static inline Napi::FunctionReference constructor;
    MPModelRequest *pMPModelRequest = nullptr;
    GMPModelRequest(const Napi::CallbackInfo &info);
    ~GMPModelRequest();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
};

class GMPSolutionResponse : public Napi::ObjectWrap<GMPSolutionResponse>
{
  public:
    static inline Napi::FunctionReference constructor;
    MPSolutionResponse *pMPSolutionResponse = nullptr;
    GMPSolutionResponse(const Napi::CallbackInfo &info);
    ~GMPSolutionResponse();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
};

class GLinearRange : public Napi::ObjectWrap<GLinearRange>
{
  public:
    static inline Napi::FunctionReference constructor;
    LinearRange *pLinearRange = nullptr;
    GLinearRange(const Napi::CallbackInfo &info);
    ~GLinearRange();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);

    Napi::Value lower_bound(const Napi::CallbackInfo &info);
    Napi::Value linear_expr(const Napi::CallbackInfo &info);
    Napi::Value upper_bound(const Napi::CallbackInfo &info);
};

class GMPConstraint : public Napi::ObjectWrap<GMPConstraint>
{
  public:
    static inline Napi::FunctionReference constructor;
    MPConstraint *pMPConstraint = nullptr;
    GMPConstraint(const Napi::CallbackInfo &info);
    static Napi::Object Init(Napi::Env env, Napi::Object exports);

    Napi::Value name(const Napi::CallbackInfo &info);
    Napi::Value Clear(const Napi::CallbackInfo &info);
    Napi::Value SetCoefficient(const Napi::CallbackInfo &info);
    Napi::Value GetCoefficient(const Napi::CallbackInfo &info);
    Napi::Value terms(const Napi::CallbackInfo &info);
    Napi::Value lb(const Napi::CallbackInfo &info);
    Napi::Value ub(const Napi::CallbackInfo &info);
    Napi::Value SetLB(const Napi::CallbackInfo &info);
    Napi::Value SetUB(const Napi::CallbackInfo &info);
    Napi::Value SetBounds(const Napi::CallbackInfo &info);
    Napi::Value is_lazy(const Napi::CallbackInfo &info);
    Napi::Value set_is_lazy(const Napi::CallbackInfo &info);
    Napi::Value indicator_variable(const Napi::CallbackInfo &info);
    Napi::Value indicator_value(const Napi::CallbackInfo &info);
    Napi::Value index(const Napi::CallbackInfo &info);
    Napi::Value dual_value(const Napi::CallbackInfo &info);
    Napi::Value basis_status(const Napi::CallbackInfo &info);
};

class GMPObjective : public Napi::ObjectWrap<GMPObjective>
{
  public:
    static inline Napi::FunctionReference constructor;
    MPObjective *pMPObjective = nullptr;
    GMPObjective(const Napi::CallbackInfo &info);
    static Napi::Object Init(Napi::Env env, Napi::Object exports);

    Napi::Value Clear(const Napi::CallbackInfo &info);
    Napi::Value SetCoefficient(const Napi::CallbackInfo &info);
    Napi::Value GetCoefficient(const Napi::CallbackInfo &info);
    Napi::Value terms(const Napi::CallbackInfo &info);
    Napi::Value SetOffset(const Napi::CallbackInfo &info);
    Napi::Value offset(const Napi::CallbackInfo &info);
    Napi::Value OptimizeLinearExpr(const Napi::CallbackInfo &info);
    Napi::Value MaximizeLinearExpr(const Napi::CallbackInfo &info);
    Napi::Value MinimizeLinearExpr(const Napi::CallbackInfo &info);
    Napi::Value AddLinearExpr(const Napi::CallbackInfo &info);
    Napi::Value SetOptimizationDirection(const Napi::CallbackInfo &info);
    Napi::Value SetMinimization(const Napi::CallbackInfo &info);
    Napi::Value SetMaximization(const Napi::CallbackInfo &info);
    Napi::Value maximization(const Napi::CallbackInfo &info);
    Napi::Value minimization(const Napi::CallbackInfo &info);
    Napi::Value Value(const Napi::CallbackInfo &info);
    Napi::Value BestBound(const Napi::CallbackInfo &info);
};

class GMPSolverParameters : public Napi::ObjectWrap<GMPSolverParameters>
{
  public:
    static inline Napi::FunctionReference constructor;
    MPSolverParameters *pMPSolverParameters = nullptr;
    GMPSolverParameters(const Napi::CallbackInfo &info);
    ~GMPSolverParameters();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);

    Napi::Value SetDoubleParam(const Napi::CallbackInfo &info);
    Napi::Value SetIntegerParam(const Napi::CallbackInfo &info);
    Napi::Value ResetDoubleParam(const Napi::CallbackInfo &info);
    Napi::Value ResetIntegerParam(const Napi::CallbackInfo &info);
    Napi::Value Reset(const Napi::CallbackInfo &info);
    Napi::Value GetDoubleParam(const Napi::CallbackInfo &info);
    Napi::Value GetIntegerParam(const Napi::CallbackInfo &info);
};

class GMPCallbackContext : public Napi::ObjectWrap<GMPCallbackContext>
{
  public:
    static inline Napi::FunctionReference constructor;
    MPCallbackContext *pMPCallbackContext = nullptr;
    GMPCallbackContext(const Napi::CallbackInfo &info);
    ~GMPCallbackContext();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
};

class GLinearExpr : public Napi::ObjectWrap<GLinearExpr>
{
  public:
    static inline Napi::FunctionReference constructor;
    LinearExpr *pLinearExpr = nullptr;
    GLinearExpr(const Napi::CallbackInfo &info);
    ~GLinearExpr();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    static bool ToLinearExpr(const Napi::Value &value, LinearExpr &expr);

    static Napi::Value NotVar(const Napi::CallbackInfo &info);
    Napi::Value operator_plus_equals(const Napi::CallbackInfo &info);
    Napi::Value operator_minus_equals(const Napi::CallbackInfo &info);
    Napi::Value operator_times_equals(const Napi::CallbackInfo &info);
    Napi::Value operator_divide_equals(const Napi::CallbackInfo &info);
    Napi::Value operator_negate(const Napi::CallbackInfo &info);
    Napi::Value offset(const Napi::CallbackInfo &info);
    Napi::Value terms(const Napi::CallbackInfo &info);
    Napi::Value SolutionValue(const Napi::CallbackInfo &info);
    Napi::Value ToString(const Napi::CallbackInfo &info);
};

class GDomain : public Napi::ObjectWrap<GDomain>
{
  public:
    static inline Napi::FunctionReference constructor;
    Domain *pDomain = nullptr;
    GDomain(const Napi::CallbackInfo &info);
    ~GDomain();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);

    static Napi::Value AllValues(const Napi::CallbackInfo &info);
    static Napi::Value FromValues(const Napi::CallbackInfo &info);
    static Napi::Value FromIntervals(const Napi::CallbackInfo &info);
    static Napi::Value FromFlatSpanOfIntervals(const Napi::CallbackInfo &info);
    static Napi::Value FromVectorIntervals(const Napi::CallbackInfo &info);
    static Napi::Value FromFlatIntervals(const Napi::CallbackInfo &info);
    Napi::Value FlattenedIntervals(const Napi::CallbackInfo &info);
    Napi::Value IsEmpty(const Napi::CallbackInfo &info);
    Napi::Value Size(const Napi::CallbackInfo &info);
    Napi::Value HasTwoValues(const Napi::CallbackInfo &info);
    Napi::Value Min(const Napi::CallbackInfo &info);
    Napi::Value Max(const Napi::CallbackInfo &info);
    Napi::Value SmallestValue(const Napi::CallbackInfo &info);
    Napi::Value ClosestValue(const Napi::CallbackInfo &info);
    Napi::Value ValueAtOrBefore(const Napi::CallbackInfo &info);
    Napi::Value ValueAtOrAfter(const Napi::CallbackInfo &info);
    Napi::Value PartAroundZero(const Napi::CallbackInfo &info);
    Napi::Value IsFixed(const Napi::CallbackInfo &info);
    Napi::Value FixedValue(const Napi::CallbackInfo &info);
    Napi::Value Contains(const Napi::CallbackInfo &info);
    Napi::Value Distance(const Napi::CallbackInfo &info);
    Napi::Value IsIncludedIn(const Napi::CallbackInfo &info);
    Napi::Value Complement(const Napi::CallbackInfo &info);
    Napi::Value Negation(const Napi::CallbackInfo &info);
    Napi::Value IntersectionWith(const Napi::CallbackInfo &info);
    Napi::Value UnionWith(const Napi::CallbackInfo &info);
    Napi::Value AdditionWith(const Napi::CallbackInfo &info);
    Napi::Value MultiplicationBy(const Napi::CallbackInfo &info);
    Napi::Value RelaxIfTooComplex(const Napi::CallbackInfo &info);
    Napi::Value ContinuousMultiplicationBy(const Napi::CallbackInfo &info);
    Napi::Value DivisionBy(const Napi::CallbackInfo &info);
    Napi::Value InverseMultiplicationBy(const Napi::CallbackInfo &info);
    Napi::Value PositiveModuloBySuperset(const Napi::CallbackInfo &info);
    Napi::Value PositiveDivisionBySuperset(const Napi::CallbackInfo &info);
    Napi::Value SquareSuperset(const Napi::CallbackInfo &info);
    Napi::Value SimplifyUsingImpliedDomain(const Napi::CallbackInfo &info);
    Napi::Value ToString(const Napi::CallbackInfo &info);
    Napi::Value operator_lt(const Napi::CallbackInfo &info);
    Napi::Value operator_eq(const Napi::CallbackInfo &info);
    Napi::Value operator_nq(const Napi::CallbackInfo &info);
    Napi::Value NumIntervals(const Napi::CallbackInfo &info);
    Napi::Value operator_brackets(const Napi::CallbackInfo &info);
};

class GClosedInterval : public Napi::ObjectWrap<GClosedInterval>
{
  public:
    static inline Napi::FunctionReference constructor;
    ClosedInterval *pClosedInterval = nullptr;
    GClosedInterval(const Napi::CallbackInfo &info);
    ~GClosedInterval();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
};
} // namespace operations_research