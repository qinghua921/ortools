#pragma once

#include <napi.h>
#include <ortools/linear_solver/linear_solver.h>

namespace operations_research
{
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
    // Napi::Value variable(const Napi::CallbackInfo &info);
    // Napi::Value LookupVariableOrNull(const Napi::CallbackInfo &info);
    // Napi::Value MakeVar(const Napi::CallbackInfo &info);
    // Napi::Value MakeNumVar(const Napi::CallbackInfo &info);
    // Napi::Value MakeIntVar(const Napi::CallbackInfo &info);
    // Napi::Value MakeBoolVar(const Napi::CallbackInfo &info);
    // Napi::Value MakeVarArray(const Napi::CallbackInfo &info);
    // Napi::Value MakeNumVarArray(const Napi::CallbackInfo &info);
    // Napi::Value MakeIntVarArray(const Napi::CallbackInfo &info);
    // Napi::Value MakeBoolVarArray(const Napi::CallbackInfo &info);
    // Napi::Value NumConstraints(const Napi::CallbackInfo &info);
    // Napi::Value constraints(const Napi::CallbackInfo &info);
    // Napi::Value constraint(const Napi::CallbackInfo &info);
    // Napi::Value LookupConstraintOrNull(const Napi::CallbackInfo &info);
    // Napi::Value MakeRowConstraint(const Napi::CallbackInfo &info);
    // Napi::Value MakeRowConstraint(const Napi::CallbackInfo &info);
    // Napi::Value MakeRowConstraint(const Napi::CallbackInfo &info);
    // Napi::Value MakeRowConstraint(const Napi::CallbackInfo &info);
    // Napi::Value MakeRowConstraint(const Napi::CallbackInfo &info);
    // Napi::Value Objective(const Napi::CallbackInfo &info);
    // Napi::Value MutableObjective(const Napi::CallbackInfo &info);
    // Napi::Value Solve(const Napi::CallbackInfo &info);
    // Napi::Value Solve(const Napi::CallbackInfo &info);
    // Napi::Value Write(const Napi::CallbackInfo &info);
    // Napi::Value ComputeConstraintActivities(const Napi::CallbackInfo &info);
    // Napi::Value VerifySolution(const Napi::CallbackInfo &info);
    // Napi::Value Reset(const Napi::CallbackInfo &info);
    // Napi::Value InterruptSolve(const Napi::CallbackInfo &info);
    // Napi::Value LoadModelFromProto(const Napi::CallbackInfo &info);
    // Napi::Value LoadModelFromProtoWithUniqueNamesOrDie(const Napi::CallbackInfo &info);
    // Napi::Value FillSolutionResponseProto(const Napi::CallbackInfo &info);
    // Napi::Value SolveWithProto(const Napi::CallbackInfo &info);
    // Napi::Value SolveLazyMutableRequest(const Napi::CallbackInfo &info);
    // Napi::Value SolverTypeSupportsInterruption(const Napi::CallbackInfo &info);
    // Napi::Value ExportModelToProto(const Napi::CallbackInfo &info);
    // Napi::Value LoadSolutionFromProto(const Napi::CallbackInfo &info);
    // Napi::Value ClampSolutionWithinBounds(const Napi::CallbackInfo &info);
    // Napi::Value ExportModelAsLpFormat(const Napi::CallbackInfo &info);
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
    ~GMPVariable();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
};
class GMPCallback : public Napi::ObjectWrap<GMPCallback>
{
  public:
    static inline Napi::FunctionReference constructor;
    MPCallback *pMPCallback = nullptr;
    GMPCallback(const Napi::CallbackInfo &info);
    ~GMPCallback();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
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

} // namespace operations_research