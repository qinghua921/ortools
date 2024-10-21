#include <absl/flags/flag.h>
#include <absl/log/flags.h>
#include <napi.h>
#include <ortools/base/init_google.h>
#include <ortools/base/logging.h>
#include <ortools/init/init.h>

#include "index.hpp"

namespace operations_research
{

#pragma region Functions

// LinearRange operator>=( const LinearExpr& lhs, const LinearExpr& rhs );
Napi::Value Goperator_ge(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr lhs, rhs;
    if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], lhs) && GLinearExpr::ToLinearExpr(info[1], rhs))
    {
        auto result   = lhs >= rhs;
        auto external = Napi::External<LinearRange>::New(env, new LinearRange(result));
        return GLinearRange::constructor.New({external});
    }

    Napi::TypeError::New(env, "operations_research::operator_ge : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
};

// LinearRange operator==( const LinearExpr& lhs, const LinearExpr& rhs );
Napi::Value Goperator_eq(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr lhs, rhs;
    if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], lhs) && GLinearExpr::ToLinearExpr(info[1], rhs))
    {
        auto result   = lhs == rhs;
        auto external = Napi::External<LinearRange>::New(env, new LinearRange(result));
        return GLinearRange::constructor.New({external});
    }

    Napi::TypeError::New(env, "operations_research::operator_eq : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
};

// LinearRange operator<=( const LinearExpr& lhs, const LinearExpr& rhs );
Napi::Value Goperator_le(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr lhs, rhs;
    if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], lhs) && GLinearExpr::ToLinearExpr(info[1], rhs))
    {
        auto result   = lhs <= rhs;
        auto external = Napi::External<LinearRange>::New(env, new LinearRange(result));
        return GLinearRange::constructor.New({external});
    }

    Napi::TypeError::New(env, "operations_research::operator_le : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
};

Napi::Value Goperator_times(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    // LinearExpr operator*( LinearExpr lhs, double rhs );
    LinearExpr lhs;
    if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], lhs) && info[1].IsNumber())
    {
        double rhs  = info[1].As<Napi::Number>().DoubleValue();
        auto result = lhs * rhs;
        return GLinearExpr::constructor.New({Napi::External<LinearExpr>::New(env, new LinearExpr(result))});
    }

    // LinearExpr operator*( double lhs, LinearExpr rhs );
    LinearExpr rhs;
    if (info.Length() == 2 && info[0].IsNumber() && GLinearExpr::ToLinearExpr(info[1], rhs))
    {
        double lhs  = info[0].As<Napi::Number>().DoubleValue();
        auto result = lhs * rhs;
        return GLinearExpr::constructor.New({Napi::External<LinearExpr>::New(env, new LinearExpr(result))});
    }

    Napi::TypeError::New(env, "operations_research::operator_times : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
};

Napi::Object FuncInit(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);

    exports.Set("operator_ge", Napi::Function::New(env, Goperator_ge));
    exports.Set("operator_eq", Napi::Function::New(env, Goperator_eq));
    exports.Set("operator_le", Napi::Function::New(env, Goperator_le));
    exports.Set("operator_times", Napi::Function::New(env, Goperator_times));

    return exports;
};

#pragma endregion

GMPSolver::GMPSolver(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GMPSolver>(info)
{
    Napi::Env env = info.Env();

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external = info[0].As<Napi::External<MPSolver>>();
        pMPSolver     = dynamic_cast<MPSolver *>(external.Data());
        if (pMPSolver) return;
    }

    // MPSolver( const std::string& name, OptimizationProblemType problem_type );
    if (info.Length() == 2 && info[0].IsString() && info[1].IsNumber())
    {
        std::string name = info[0].As<Napi::String>().Utf8Value();
        int problem_type = info[1].As<Napi::Number>().Int32Value();
        pMPSolver        = new MPSolver(name, static_cast<MPSolver::OptimizationProblemType>(problem_type));
        return;
    }

    Napi::TypeError::New(env, "GMPSolver::GMPSolver : Invalid arguments").ThrowAsJavaScriptException();
}

GMPSolver::~GMPSolver()
{
    if (pMPSolver) delete pMPSolver;
}

Napi::Object GMPSolver::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);

    auto enumOptimizationProblemType = Napi::Object::New(env);
    enumOptimizationProblemType.Set("CLP_LINEAR_PROGRAMMING", static_cast<int>(MPSolver::OptimizationProblemType::CLP_LINEAR_PROGRAMMING));
    enumOptimizationProblemType.Set("GLPK_LINEAR_PROGRAMMING", static_cast<int>(MPSolver::OptimizationProblemType::GLPK_LINEAR_PROGRAMMING));
    enumOptimizationProblemType.Set("GLOP_LINEAR_PROGRAMMING", static_cast<int>(MPSolver::OptimizationProblemType::GLOP_LINEAR_PROGRAMMING));
    enumOptimizationProblemType.Set("PDLP_LINEAR_PROGRAMMING", static_cast<int>(MPSolver::OptimizationProblemType::PDLP_LINEAR_PROGRAMMING));
    enumOptimizationProblemType.Set("HIGHS_LINEAR_PROGRAMMING", static_cast<int>(MPSolver::OptimizationProblemType::HIGHS_LINEAR_PROGRAMMING));
    enumOptimizationProblemType.Set("SCIP_MIXED_INTEGER_PROGRAMMING", static_cast<int>(MPSolver::OptimizationProblemType::SCIP_MIXED_INTEGER_PROGRAMMING));
    enumOptimizationProblemType.Set("GLPK_MIXED_INTEGER_PROGRAMMING", static_cast<int>(MPSolver::OptimizationProblemType::GLPK_MIXED_INTEGER_PROGRAMMING));
    enumOptimizationProblemType.Set("CBC_MIXED_INTEGER_PROGRAMMING", static_cast<int>(MPSolver::OptimizationProblemType::CBC_MIXED_INTEGER_PROGRAMMING));
    enumOptimizationProblemType.Set("HIGHS_MIXED_INTEGER_PROGRAMMING", static_cast<int>(MPSolver::OptimizationProblemType::HIGHS_MIXED_INTEGER_PROGRAMMING));
    enumOptimizationProblemType.Set("BOP_INTEGER_PROGRAMMING", static_cast<int>(MPSolver::OptimizationProblemType::BOP_INTEGER_PROGRAMMING));
    enumOptimizationProblemType.Set("SAT_INTEGER_PROGRAMMING", static_cast<int>(MPSolver::OptimizationProblemType::SAT_INTEGER_PROGRAMMING));
    enumOptimizationProblemType.Set("KNAPSACK_MIXED_INTEGER_PROGRAMMING", static_cast<int>(MPSolver::OptimizationProblemType::KNAPSACK_MIXED_INTEGER_PROGRAMMING));
    enumOptimizationProblemType.Set("GUROBI_LINEAR_PROGRAMMING", static_cast<int>(MPSolver::OptimizationProblemType::GUROBI_LINEAR_PROGRAMMING));
    enumOptimizationProblemType.Set("GUROBI_MIXED_INTEGER_PROGRAMMING", static_cast<int>(MPSolver::OptimizationProblemType::GUROBI_MIXED_INTEGER_PROGRAMMING));
    enumOptimizationProblemType.Set("CPLEX_LINEAR_PROGRAMMING", static_cast<int>(MPSolver::OptimizationProblemType::CPLEX_LINEAR_PROGRAMMING));
    enumOptimizationProblemType.Set("CPLEX_MIXED_INTEGER_PROGRAMMING", static_cast<int>(MPSolver::OptimizationProblemType::CPLEX_MIXED_INTEGER_PROGRAMMING));
    enumOptimizationProblemType.Set("XPRESS_LINEAR_PROGRAMMING", static_cast<int>(MPSolver::OptimizationProblemType::XPRESS_LINEAR_PROGRAMMING));
    enumOptimizationProblemType.Set("XPRESS_MIXED_INTEGER_PROGRAMMING", static_cast<int>(MPSolver::OptimizationProblemType::XPRESS_MIXED_INTEGER_PROGRAMMING));
    enumOptimizationProblemType.Set("COPT_LINEAR_PROGRAMMING", static_cast<int>(MPSolver::OptimizationProblemType::COPT_LINEAR_PROGRAMMING));
    enumOptimizationProblemType.Set("COPT_MIXED_INTEGER_PROGRAMMING", static_cast<int>(MPSolver::OptimizationProblemType::COPT_MIXED_INTEGER_PROGRAMMING));

    auto enumResultStatus = Napi::Object::New(env);
    enumResultStatus.Set("OPTIMAL", static_cast<int>(MPSolver::ResultStatus::OPTIMAL));
    enumResultStatus.Set("FEASIBLE", static_cast<int>(MPSolver::ResultStatus::FEASIBLE));
    enumResultStatus.Set("INFEASIBLE", static_cast<int>(MPSolver::ResultStatus::INFEASIBLE));
    enumResultStatus.Set("UNBOUNDED", static_cast<int>(MPSolver::ResultStatus::UNBOUNDED));
    enumResultStatus.Set("ABNORMAL", static_cast<int>(MPSolver::ResultStatus::ABNORMAL));
    enumResultStatus.Set("MODEL_INVALID", static_cast<int>(MPSolver::ResultStatus::MODEL_INVALID));
    enumResultStatus.Set("NOT_SOLVED", static_cast<int>(MPSolver::ResultStatus::NOT_SOLVED));

    auto enumBasisStatus = Napi::Object::New(env);
    enumBasisStatus.Set("FREE", static_cast<int>(MPSolver::BasisStatus::FREE));
    enumBasisStatus.Set("AT_LOWER_BOUND", static_cast<int>(MPSolver::BasisStatus::AT_LOWER_BOUND));
    enumBasisStatus.Set("AT_UPPER_BOUND", static_cast<int>(MPSolver::BasisStatus::AT_UPPER_BOUND));
    enumBasisStatus.Set("FIXED_VALUE", static_cast<int>(MPSolver::BasisStatus::FIXED_VALUE));

    Napi::Function func = DefineClass(
        env,
        "MPSolver",
        {
            StaticValue("OptimizationProblemType", enumOptimizationProblemType),
            StaticValue("ResultStatus", enumResultStatus),
            StaticValue("BasisStatus", enumBasisStatus),

            StaticMethod("CreateSolver", &GMPSolver::CreateSolver),
            StaticMethod("SupportsProblemType", &GMPSolver::SupportsProblemType),
            StaticMethod("ParseSolverType", &GMPSolver::ParseSolverType),
            StaticMethod("ParseSolverTypeOrDie", &GMPSolver::ParseSolverTypeOrDie),
            InstanceMethod("IsMIP", &GMPSolver::IsMIP),
            InstanceMethod("Name", &GMPSolver::Name),
            InstanceMethod("ProblemType", &GMPSolver::ProblemType),
            InstanceMethod("Clear", &GMPSolver::Clear),
            InstanceMethod("NumVariables", &GMPSolver::NumVariables),
            InstanceMethod("variables", &GMPSolver::variables),
            InstanceMethod("variable", &GMPSolver::variable),
            InstanceMethod("LookupVariableOrNull", &GMPSolver::LookupVariableOrNull),
            InstanceMethod("MakeVar", &GMPSolver::MakeVar),
            InstanceMethod("MakeNumVar", &GMPSolver::MakeNumVar),
            InstanceMethod("MakeIntVar", &GMPSolver::MakeIntVar),
            InstanceMethod("MakeBoolVar", &GMPSolver::MakeBoolVar),
            InstanceMethod("MakeVarArray", &GMPSolver::MakeVarArray),
            InstanceMethod("MakeNumVarArray", &GMPSolver::MakeNumVarArray),
            InstanceMethod("MakeIntVarArray", &GMPSolver::MakeIntVarArray),
            InstanceMethod("MakeBoolVarArray", &GMPSolver::MakeBoolVarArray),
            InstanceMethod("NumConstraints", &GMPSolver::NumConstraints),
            InstanceMethod("constraints", &GMPSolver::constraints),
            InstanceMethod("constraint", &GMPSolver::constraint),
            InstanceMethod("LookupConstraintOrNull", &GMPSolver::LookupConstraintOrNull),
            InstanceMethod("MakeRowConstraint", &GMPSolver::MakeRowConstraint),
            InstanceMethod("MutableObjective", &GMPSolver::MutableObjective),
            InstanceMethod("Solve", &GMPSolver::Solve),
            InstanceMethod("Write", &GMPSolver::Write),
            InstanceMethod("ComputeConstraintActivities", &GMPSolver::ComputeConstraintActivities),
            InstanceMethod("VerifySolution", &GMPSolver::VerifySolution),
            InstanceMethod("Reset", &GMPSolver::Reset),
            InstanceMethod("InterruptSolve", &GMPSolver::InterruptSolve),
            InstanceMethod("FillSolutionResponseProto", &GMPSolver::FillSolutionResponseProto),
            StaticMethod("SolverTypeSupportsInterruption", &GMPSolver::SolverTypeSupportsInterruption),
            InstanceMethod("LoadSolutionFromProto", &GMPSolver::LoadSolutionFromProto),
            InstanceMethod("ClampSolutionWithinBounds", &GMPSolver::ClampSolutionWithinBounds),
            InstanceMethod("ExportModelAsLpFormat", &GMPSolver::ExportModelAsLpFormat),
            InstanceMethod("ExportModelAsMpsFormat", &GMPSolver::ExportModelAsMpsFormat),
            InstanceMethod("SetNumThreads", &GMPSolver::SetNumThreads),
            InstanceMethod("GetNumThreads", &GMPSolver::GetNumThreads),
            InstanceMethod("SetSolverSpecificParametersAsString", &GMPSolver::SetSolverSpecificParametersAsString),
            InstanceMethod("GetSolverSpecificParametersAsString", &GMPSolver::GetSolverSpecificParametersAsString),
            InstanceMethod("SetHint", &GMPSolver::SetHint),
            StaticMethod("GetMPModelRequestLoggingInfo", &GMPSolver::GetMPModelRequestLoggingInfo),
            InstanceMethod("SetStartingLpBasis", &GMPSolver::SetStartingLpBasis),
            StaticMethod("infinity", &GMPSolver::infinity),
            InstanceMethod("solver_infinity", &GMPSolver::solver_infinity),
            InstanceMethod("OutputIsEnabled", &GMPSolver::OutputIsEnabled),
            InstanceMethod("EnableOutput", &GMPSolver::EnableOutput),
            InstanceMethod("SuppressOutput", &GMPSolver::SuppressOutput),
            InstanceMethod("TimeLimit", &GMPSolver::TimeLimit),
            InstanceMethod("SetTimeLimit", &GMPSolver::SetTimeLimit),
            InstanceMethod("DurationSinceConstruction", &GMPSolver::DurationSinceConstruction),
            InstanceMethod("iterations", &GMPSolver::iterations),
            InstanceMethod("nodes", &GMPSolver::nodes),
            InstanceMethod("SolverVersion", &GMPSolver::SolverVersion),
            InstanceMethod("ComputeExactConditionNumber", &GMPSolver::ComputeExactConditionNumber),
            InstanceMethod("NextSolution", &GMPSolver::NextSolution),
            InstanceMethod("SetCallback", &GMPSolver::SetCallback),
            InstanceMethod("SupportsCallbacks", &GMPSolver::SupportsCallbacks),
            StaticMethod("global_num_variables", &GMPSolver::global_num_variables),
            StaticMethod("global_num_constraints", &GMPSolver::global_num_constraints),
            InstanceMethod("time_limit", &GMPSolver::time_limit),
            InstanceMethod("set_time_limit", &GMPSolver::set_time_limit),
            InstanceMethod("time_limit_in_secs", &GMPSolver::time_limit_in_secs),
            InstanceMethod("wall_time", &GMPSolver::wall_time),
            InstanceMethod("OwnsVariable", &GMPSolver::OwnsVariable),

        }
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set(Napi::String::New(env, "MPSolver"), func);
    return exports;
}

// static MPSolver *CreateSolver(const std::string &solver_id);
Napi::Value GMPSolver::CreateSolver(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsString())
    {
        std::string solver_id = info[0].As<Napi::String>().Utf8Value();
        MPSolver *pMPSolver   = MPSolver::CreateSolver(solver_id);
        auto external         = Napi::External<MPSolver>::New(env, pMPSolver);
        return GMPSolver::constructor.New({external});
    }

    Napi::TypeError::New(env, "GMPSolver::CreateSolver : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// static bool SupportsProblemType(OptimizationProblemType problem_type);
Napi::Value GMPSolver::SupportsProblemType(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        int problem_type = info[0].As<Napi::Number>().Int32Value();
        bool supported   = MPSolver::SupportsProblemType(static_cast<MPSolver::OptimizationProblemType>(problem_type));
        return Napi::Boolean::New(env, supported);
    }

    Napi::TypeError::New(env, "GMPSolver::SupportsProblemType : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// static bool ParseSolverType(absl::string_view solver_id, OptimizationProblemType *type);
Napi::Value GMPSolver::ParseSolverType(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsString())
    {
        std::string solver_id = info[0].As<Napi::String>().Utf8Value();
        MPSolver::OptimizationProblemType problem_type;
        bool success = MPSolver::ParseSolverType(solver_id, &problem_type);
        auto ret     = Napi::Object::New(env);
        ret.Set("return", Napi::Boolean::New(env, success));
        ret.Set("type", Napi::Number::New(env, static_cast<int>(problem_type)));
        return ret;
    }

    Napi::TypeError::New(env, "GMPSolver::ParseSolverType : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// static OptimizationProblemType ParseSolverTypeOrDie(const std::string &solver_id);
Napi::Value GMPSolver::ParseSolverTypeOrDie(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsString())
    {
        std::string solver_id                          = info[0].As<Napi::String>().Utf8Value();
        MPSolver::OptimizationProblemType problem_type = MPSolver::ParseSolverTypeOrDie(solver_id);
        return Napi::Number::New(env, static_cast<int>(problem_type));
    }

    Napi::TypeError::New(env, "GMPSolver::ParseSolverTypeOrDie : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// bool IsMIP() const;
Napi::Value GMPSolver::IsMIP(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        bool is_mip = this->pMPSolver->IsMIP();
        return Napi::Boolean::New(env, is_mip);
    }

    Napi::TypeError::New(env, "GMPSolver::IsMIP : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// const std::string &Name() const;
Napi::Value GMPSolver::Name(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        std::string name = this->pMPSolver->Name();
        return Napi::String::New(env, name);
    }

    Napi::TypeError::New(env, "GMPSolver::Name : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// virtual OptimizationProblemType ProblemType() const;
Napi::Value GMPSolver::ProblemType(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        MPSolver::OptimizationProblemType problem_type = this->pMPSolver->ProblemType();
        return Napi::Number::New(env, static_cast<int>(problem_type));
    }

    Napi::TypeError::New(env, "GMPSolver::ProblemType : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void Clear();
Napi::Value GMPSolver::Clear(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        this->pMPSolver->Clear();
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPSolver::Clear : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// int NumVariables() const;
Napi::Value GMPSolver::NumVariables(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        int num_variables = this->pMPSolver->NumVariables();
        return Napi::Number::New(env, num_variables);
    }

    Napi::TypeError::New(env, "GMPSolver::NumVariables : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// const std::vector<MPVariable *> &variables() const;
Napi::Value GMPSolver::variables(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        const std::vector<MPVariable *> &variables = this->pMPSolver->variables();
        Napi::Array ret                            = Napi::Array::New(env, variables.size());
        for (int i = 0; i < variables.size(); i++)
        {
            auto external = Napi::External<MPVariable>::New(env, variables[i]);
            ret.Set(i, GMPVariable::constructor.New({external}));
        }
        return ret;
    }

    Napi::TypeError::New(env, "GMPSolver::variables : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// MPVariable *variable(int index) const;
Napi::Value GMPSolver::variable(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        int index            = info[0].As<Napi::Number>().Int32Value();
        MPVariable *variable = this->pMPSolver->variable(index);
        if (variable == nullptr) return env.Null();
        auto external = Napi::External<MPVariable>::New(env, variable);
        return GMPVariable::constructor.New({external});
    }

    Napi::TypeError::New(env, "GMPSolver::variable : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// MPVariable *LookupVariableOrNull(const std::string &var_name) const;
Napi::Value GMPSolver::LookupVariableOrNull(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsString())
    {
        std::string var_name = info[0].As<Napi::String>().Utf8Value();
        MPVariable *variable = this->pMPSolver->LookupVariableOrNull(var_name);
        if (variable == nullptr) return env.Null();
        auto external = Napi::External<MPVariable>::New(env, variable);
        return GMPVariable::constructor.New({external});
    }

    Napi::TypeError::New(env, "GMPSolver::LookupVariableOrNull : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// MPVariable *MakeVar(double lb, double ub, bool integer, const std::string &name);
Napi::Value GMPSolver::MakeVar(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 4 && info[0].IsNumber() && info[1].IsNumber() && info[2].IsBoolean() && info[3].IsString())
    {
        double lb            = info[0].As<Napi::Number>().DoubleValue();
        double ub            = info[1].As<Napi::Number>().DoubleValue();
        bool integer         = info[2].As<Napi::Boolean>().Value();
        std::string name     = info[3].As<Napi::String>().Utf8Value();
        MPVariable *variable = this->pMPSolver->MakeVar(lb, ub, integer, name);
        auto external        = Napi::External<MPVariable>::New(env, variable);
        return GMPVariable::constructor.New({external});
    }

    Napi::TypeError::New(env, "GMPSolver::MakeVar : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// MPVariable *MakeNumVar(double lb, double ub, const std::string &name);
Napi::Value GMPSolver::MakeNumVar(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 3 && info[0].IsNumber() && info[1].IsNumber() && info[2].IsString())
    {
        double lb            = info[0].As<Napi::Number>().DoubleValue();
        double ub            = info[1].As<Napi::Number>().DoubleValue();
        std::string name     = info[2].As<Napi::String>().Utf8Value();
        MPVariable *variable = this->pMPSolver->MakeNumVar(lb, ub, name);
        auto external        = Napi::External<MPVariable>::New(env, variable);
        return GMPVariable::constructor.New({external});
    }

    Napi::TypeError::New(env, "GMPSolver::MakeNumVar : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// MPVariable *MakeIntVar(double lb, double ub, const std::string &name);
Napi::Value GMPSolver::MakeIntVar(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 3 && info[0].IsNumber() && info[1].IsNumber() && info[2].IsString())
    {
        double lb            = info[0].As<Napi::Number>().DoubleValue();
        double ub            = info[1].As<Napi::Number>().DoubleValue();
        std::string name     = info[2].As<Napi::String>().Utf8Value();
        MPVariable *variable = this->pMPSolver->MakeIntVar(lb, ub, name);
        auto external        = Napi::External<MPVariable>::New(env, variable);
        return GMPVariable::constructor.New({external});
    }

    Napi::TypeError::New(env, "GMPSolver::MakeIntVar : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// MPVariable *MakeBoolVar(const std::string &name);
Napi::Value GMPSolver::MakeBoolVar(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsString())
    {
        std::string name     = info[0].As<Napi::String>().Utf8Value();
        MPVariable *variable = this->pMPSolver->MakeBoolVar(name);
        auto external        = Napi::External<MPVariable>::New(env, variable);
        return GMPVariable::constructor.New({external});
    }

    Napi::TypeError::New(env, "GMPSolver::MakeBoolVar : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void MakeVarArray(int nb, double lb, double ub, bool integer, const std::string &name_prefix, std::vector<MPVariable *> *vars);
Napi::Value GMPSolver::MakeVarArray(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 5 && info[0].IsNumber() && info[1].IsNumber() && info[2].IsNumber() && info[3].IsBoolean() && info[4].IsString())
    {
        int nb                  = info[0].As<Napi::Number>().Int32Value();
        double lb               = info[1].As<Napi::Number>().DoubleValue();
        double ub               = info[2].As<Napi::Number>().DoubleValue();
        bool integer            = info[3].As<Napi::Boolean>().Value();
        std::string name_prefix = info[4].As<Napi::String>().Utf8Value();
        std::vector<MPVariable *> vars(nb);
        this->pMPSolver->MakeVarArray(nb, lb, ub, integer, name_prefix, &vars);
        Napi::Array ret = Napi::Array::New(env, nb);
        for (int i = 0; i < nb; i++)
        {
            auto external = Napi::External<MPVariable>::New(env, vars[i]);
            ret.Set(i, GMPVariable::constructor.New({external}));
        }
        return ret;
    }

    Napi::TypeError::New(env, "GMPSolver::MakeVarArray : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void MakeNumVarArray(int nb, double lb, double ub, const std::string &name, std::vector<MPVariable *> *vars);
Napi::Value GMPSolver::MakeNumVarArray(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 4 && info[0].IsNumber() && info[1].IsNumber() && info[2].IsNumber() && info[3].IsString())
    {
        int nb                  = info[0].As<Napi::Number>().Int32Value();
        double lb               = info[1].As<Napi::Number>().DoubleValue();
        double ub               = info[2].As<Napi::Number>().DoubleValue();
        std::string name_prefix = info[3].As<Napi::String>().Utf8Value();
        std::vector<MPVariable *> vars(nb);
        this->pMPSolver->MakeNumVarArray(nb, lb, ub, name_prefix, &vars);
        Napi::Array ret = Napi::Array::New(env, nb);
        for (int i = 0; i < nb; i++)
        {
            auto external = Napi::External<MPVariable>::New(env, vars[i]);
            ret.Set(i, GMPVariable::constructor.New({external}));
        }
        return ret;
    }

    Napi::TypeError::New(env, "GMPSolver::MakeNumVarArray : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void MakeIntVarArray(int nb, double lb, double ub, const std::string &name, std::vector<MPVariable *> *vars);
Napi::Value GMPSolver::MakeIntVarArray(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 4 && info[0].IsNumber() && info[1].IsNumber() && info[2].IsNumber() && info[3].IsString())
    {
        int nb                  = info[0].As<Napi::Number>().Int32Value();
        double lb               = info[1].As<Napi::Number>().DoubleValue();
        double ub               = info[2].As<Napi::Number>().DoubleValue();
        std::string name_prefix = info[3].As<Napi::String>().Utf8Value();
        std::vector<MPVariable *> vars(nb);
        this->pMPSolver->MakeIntVarArray(nb, lb, ub, name_prefix, &vars);
        Napi::Array ret = Napi::Array::New(env, nb);
        for (int i = 0; i < nb; i++)
        {
            auto external = Napi::External<MPVariable>::New(env, vars[i]);
            ret.Set(i, GMPVariable::constructor.New({external}));
        }
        return ret;
    }

    Napi::TypeError::New(env, "GMPSolver::MakeIntVarArray : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void MakeBoolVarArray(int nb, const std::string &name, std::vector<MPVariable *> *vars);
Napi::Value GMPSolver::MakeBoolVarArray(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 2 && info[0].IsNumber() && info[1].IsString())
    {
        int nb                  = info[0].As<Napi::Number>().Int32Value();
        std::string name_prefix = info[1].As<Napi::String>().Utf8Value();
        std::vector<MPVariable *> vars(nb);
        this->pMPSolver->MakeBoolVarArray(nb, name_prefix, &vars);
        Napi::Array ret = Napi::Array::New(env, nb);
        for (int i = 0; i < nb; i++)
        {
            auto external = Napi::External<MPVariable>::New(env, vars[i]);
            ret.Set(i, GMPVariable::constructor.New({external}));
        }
        return ret;
    }

    Napi::TypeError::New(env, "GMPSolver::MakeBoolVarArray : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// int NumConstraints() const;
Napi::Value GMPSolver::NumConstraints(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        int num_constraints = this->pMPSolver->NumConstraints();
        return Napi::Number::New(env, num_constraints);
    }

    Napi::TypeError::New(env, "GMPSolver::NumConstraints : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// const std::vector<MPConstraint *> &constraints() const;
Napi::Value GMPSolver::constraints(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        const std::vector<MPConstraint *> &constraints = this->pMPSolver->constraints();
        Napi::Array ret                                = Napi::Array::New(env, constraints.size());
        for (int i = 0; i < constraints.size(); i++)
        {
            auto external = Napi::External<MPConstraint>::New(env, constraints[i]);
            ret.Set(i, GMPConstraint::constructor.New({external}));
        }
        return ret;
    }

    Napi::TypeError::New(env, "GMPSolver::constraints : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// MPConstraint *constraint(int index) const;
Napi::Value GMPSolver::constraint(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        int index                = info[0].As<Napi::Number>().Int32Value();
        MPConstraint *constraint = this->pMPSolver->constraint(index);
        if (constraint == nullptr) return env.Null();
        auto external = Napi::External<MPConstraint>::New(env, constraint);
        return GMPConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GMPSolver::constraint : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// MPConstraint *LookupConstraintOrNull(const std::string &constraint_name) const;
Napi::Value GMPSolver::LookupConstraintOrNull(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsString())
    {
        std::string constraint_name = info[0].As<Napi::String>().Utf8Value();
        MPConstraint *constraint    = this->pMPSolver->LookupConstraintOrNull(constraint_name);
        if (constraint == nullptr) return env.Null();
        auto external = Napi::External<MPConstraint>::New(env, constraint);
        return GMPConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GMPSolver::LookupConstraintOrNull : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

Napi::Value GMPSolver::MakeRowConstraint(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    // MPConstraint *MakeRowConstraint(double lb, double ub);
    if (info.Length() == 2 && info[0].IsNumber() && info[1].IsNumber())
    {
        double lb                = info[0].As<Napi::Number>().DoubleValue();
        double ub                = info[1].As<Napi::Number>().DoubleValue();
        MPConstraint *constraint = this->pMPSolver->MakeRowConstraint(lb, ub);
        auto external            = Napi::External<MPConstraint>::New(env, constraint);
        return GMPConstraint::constructor.New({external});
    }

    // MPConstraint *MakeRowConstraint();
    if (info.Length() == 0)
    {
        MPConstraint *constraint = this->pMPSolver->MakeRowConstraint();
        auto external            = Napi::External<MPConstraint>::New(env, constraint);
        return GMPConstraint::constructor.New({external});
    }

    // MPConstraint *MakeRowConstraint(double lb, double ub, const std::string &name);
    if (info.Length() == 3 && info[0].IsNumber() && info[1].IsNumber() && info[2].IsString())
    {
        double lb                = info[0].As<Napi::Number>().DoubleValue();
        double ub                = info[1].As<Napi::Number>().DoubleValue();
        std::string name         = info[2].As<Napi::String>().Utf8Value();
        MPConstraint *constraint = this->pMPSolver->MakeRowConstraint(lb, ub, name);
        auto external            = Napi::External<MPConstraint>::New(env, constraint);
        return GMPConstraint::constructor.New({external});
    }

    // MPConstraint *MakeRowConstraint(const std::string &name);
    if (info.Length() == 1 && info[0].IsString())
    {
        std::string name         = info[0].As<Napi::String>().Utf8Value();
        MPConstraint *constraint = this->pMPSolver->MakeRowConstraint(name);
        auto external            = Napi::External<MPConstraint>::New(env, constraint);
        return GMPConstraint::constructor.New({external});
    }

    // MPConstraint *MakeRowConstraint(const LinearRange &range);
    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GLinearRange::constructor.Value()))
    {
        GLinearRange *range      = Napi::ObjectWrap<GLinearRange>::Unwrap(info[0].As<Napi::Object>());
        MPConstraint *constraint = this->pMPSolver->MakeRowConstraint(*range->pLinearRange);
        auto external            = Napi::External<MPConstraint>::New(env, constraint);
        return GMPConstraint::constructor.New({external});
    }

    // MPConstraint *MakeRowConstraint(const LinearRange &range, const std::string &name);
    if (info.Length() == 2 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GLinearRange::constructor.Value()) && info[1].IsString())
    {
        GLinearRange *range      = Napi::ObjectWrap<GLinearRange>::Unwrap(info[0].As<Napi::Object>());
        std::string name         = info[1].As<Napi::String>().Utf8Value();
        MPConstraint *constraint = this->pMPSolver->MakeRowConstraint(*range->pLinearRange, name);
        auto external            = Napi::External<MPConstraint>::New(env, constraint);
        return GMPConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GMPSolver::MakeRowConstraint : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// MPObjective *MutableObjective();
Napi::Value GMPSolver::MutableObjective(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        MPObjective *objective = this->pMPSolver->MutableObjective();
        auto external          = Napi::External<MPObjective>::New(env, objective);
        return GMPObjective::constructor.New({external});
    }

    Napi::TypeError::New(env, "GMPSolver::MutableObjective : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

Napi::Value GMPSolver::Solve(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    // ResultStatus Solve();
    if (info.Length() == 0)
    {
        MPSolver::ResultStatus status = this->pMPSolver->Solve();
        return Napi::Number::New(env, static_cast<int>(status));
    }

    // ResultStatus Solve(const MPSolverParameters &param);
    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GMPSolverParameters::constructor.Value()))
    {
        GMPSolverParameters *param    = Napi::ObjectWrap<GMPSolverParameters>::Unwrap(info[0].As<Napi::Object>());
        MPSolver::ResultStatus status = this->pMPSolver->Solve(*param->pMPSolverParameters);
        return Napi::Number::New(env, static_cast<int>(status));
    }

    Napi::TypeError::New(env, "GMPSolver::Solve : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void Write(const std::string &file_name);
Napi::Value GMPSolver::Write(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsString())
    {
        std::string file_name = info[0].As<Napi::String>().Utf8Value();
        this->pMPSolver->Write(file_name);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPSolver::Write : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// std::vector<double> ComputeConstraintActivities() const;
Napi::Value GMPSolver::ComputeConstraintActivities(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        std::vector<double> activities = this->pMPSolver->ComputeConstraintActivities();
        Napi::Array ret                = Napi::Array::New(env, activities.size());
        for (int i = 0; i < activities.size(); i++)
        {
            ret.Set(i, Napi::Number::New(env, activities[i]));
        }
        return ret;
    }

    Napi::TypeError::New(env, "GMPSolver::ComputeConstraintActivities : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// bool VerifySolution(double tolerance, bool log_errors) const;
Napi::Value GMPSolver::VerifySolution(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 2 && info[0].IsNumber() && info[1].IsBoolean())
    {
        double tolerance = info[0].As<Napi::Number>().DoubleValue();
        bool log_errors  = info[1].As<Napi::Boolean>().Value();
        bool success     = this->pMPSolver->VerifySolution(tolerance, log_errors);
        return Napi::Boolean::New(env, success);
    }

    Napi::TypeError::New(env, "GMPSolver::VerifySolution : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void Reset();
Napi::Value GMPSolver::Reset(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        this->pMPSolver->Reset();
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPSolver::Reset : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// bool InterruptSolve();
Napi::Value GMPSolver::InterruptSolve(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        bool success = this->pMPSolver->InterruptSolve();
        return Napi::Boolean::New(env, success);
    }

    Napi::TypeError::New(env, "GMPSolver::InterruptSolve : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void FillSolutionResponseProto(MPSolutionResponse *response) const;
Napi::Value GMPSolver::FillSolutionResponseProto(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GMPSolutionResponse::constructor.Value()))
    {
        GMPSolutionResponse *response = Napi::ObjectWrap<GMPSolutionResponse>::Unwrap(info[0].As<Napi::Object>());
        this->pMPSolver->FillSolutionResponseProto(response->pMPSolutionResponse);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPSolver::FillSolutionResponseProto : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// static bool SolverTypeSupportsInterruption(const MPModelRequest::SolverType solver);
Napi::Value GMPSolver::SolverTypeSupportsInterruption(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        int solver_type = info[0].As<Napi::Number>().Int32Value();
        bool supported  = MPSolver::SolverTypeSupportsInterruption(static_cast<MPModelRequest::SolverType>(solver_type));
        return Napi::Boolean::New(env, supported);
    }

    Napi::TypeError::New(env, "GMPSolver::SolverTypeSupportsInterruption : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// absl::Status LoadSolutionFromProto(const MPSolutionResponse &response, double tolerance = std::numeric_limits<double>::infinity());
Napi::Value GMPSolver::LoadSolutionFromProto(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 2 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GMPSolutionResponse::constructor.Value()) && info[1].IsNumber())
    {
        GMPSolutionResponse *response = Napi::ObjectWrap<GMPSolutionResponse>::Unwrap(info[0].As<Napi::Object>());
        double tolerance              = info[1].As<Napi::Number>().DoubleValue();
        auto status                   = this->pMPSolver->LoadSolutionFromProto(*response->pMPSolutionResponse, tolerance);
        return Napi::Boolean::New(env, status.ok());
    }

    Napi::TypeError::New(env, "GMPSolver::LoadSolutionFromProto : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// absl::Status ClampSolutionWithinBounds();
Napi::Value GMPSolver::ClampSolutionWithinBounds(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        auto status = this->pMPSolver->ClampSolutionWithinBounds();
        return Napi::Boolean::New(env, status.ok());
    }

    Napi::TypeError::New(env, "GMPSolver::ClampSolutionWithinBounds : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// bool ExportModelAsLpFormat(bool obfuscate, std::string *model_str) const;
Napi::Value GMPSolver::ExportModelAsLpFormat(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsBoolean())
    {
        bool obfuscate = info[0].As<Napi::Boolean>().Value();
        std::string model_str;
        bool success = this->pMPSolver->ExportModelAsLpFormat(obfuscate, &model_str);
        auto ret     = Napi::Object::New(env);
        ret.Set("return", Napi::Boolean::New(env, success));
        ret.Set("model_str", Napi::String::New(env, model_str));
        return ret;
    }

    Napi::TypeError::New(env, "GMPSolver::ExportModelAsLpFormat : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// bool ExportModelAsMpsFormat(bool fixed_format, bool obfuscate, std::string *model_str) const;
Napi::Value GMPSolver::ExportModelAsMpsFormat(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 2 && info[0].IsBoolean() && info[1].IsBoolean())
    {
        bool fixed_format = info[0].As<Napi::Boolean>().Value();
        bool obfuscate    = info[1].As<Napi::Boolean>().Value();
        std::string model_str;
        bool success = this->pMPSolver->ExportModelAsMpsFormat(fixed_format, obfuscate, &model_str);
        auto ret     = Napi::Object::New(env);
        ret.Set("return", Napi::Boolean::New(env, success));
        ret.Set("model_str", Napi::String::New(env, model_str));
        return ret;
    }

    Napi::TypeError::New(env, "GMPSolver::ExportModelAsLpFormat : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// absl::Status SetNumThreads(int num_threads);
Napi::Value GMPSolver::SetNumThreads(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        int num_threads = info[0].As<Napi::Number>().Int32Value();
        auto success    = this->pMPSolver->SetNumThreads(num_threads);
        return Napi::Boolean::New(env, success.ok());
    }

    Napi::TypeError::New(env, "GMPSolver::SetNumThreads : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// int GetNumThreads() const;
Napi::Value GMPSolver::GetNumThreads(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        int num_threads = this->pMPSolver->GetNumThreads();
        return Napi::Number::New(env, num_threads);
    }

    Napi::TypeError::New(env, "GMPSolver::GetNumThreads : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// bool SetSolverSpecificParametersAsString(const std::string &parameters);
Napi::Value GMPSolver::SetSolverSpecificParametersAsString(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsString())
    {
        std::string parameters = info[0].As<Napi::String>().Utf8Value();
        bool success           = this->pMPSolver->SetSolverSpecificParametersAsString(parameters);
        return Napi::Boolean::New(env, success);
    }

    Napi::TypeError::New(env, "GMPSolver::SetSolverSpecificParametersAsString : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// std::string GetSolverSpecificParametersAsString() const;
Napi::Value GMPSolver::GetSolverSpecificParametersAsString(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        std::string parameters = this->pMPSolver->GetSolverSpecificParametersAsString();
        return Napi::String::New(env, parameters);
    }

    Napi::TypeError::New(env, "GMPSolver::GetSolverSpecificParametersAsString : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void SetHint(std::vector<std::pair<const MPVariable *, double>> hint);
Napi::Value GMPSolver::SetHint(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsArray())
    {
        Napi::Array hint_array = info[0].As<Napi::Array>();
        std::vector<std::pair<const MPVariable *, double>> hint;
        for (int i = 0; i < hint_array.Length(); i++)
        {
            Napi::Array hint_array_inner = hint_array.Get(i).As<Napi::Array>();
            if (hint_array_inner.Length() != 2)
            {
                Napi::TypeError::New(env, "GMPSolver::SetHint : Invalid hint array").ThrowAsJavaScriptException();
                return env.Null();
            }
            Napi::Object variable_object = hint_array_inner.Get(static_cast<uint32_t>(0)).As<Napi::Object>();
            if (!variable_object.InstanceOf(GMPVariable::constructor.Value()))
            {
                Napi::TypeError::New(env, "GMPSolver::SetHint : Invalid hint array").ThrowAsJavaScriptException();
                return env.Null();
            }
            GMPVariable *variable = Napi::ObjectWrap<GMPVariable>::Unwrap(variable_object);
            double value          = hint_array_inner.Get(1).As<Napi::Number>().DoubleValue();
            hint.push_back(std::make_pair(variable->pMPVariable, value));
        }
        this->pMPSolver->SetHint(hint);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPSolver::SetHint : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// static std::string GetMPModelRequestLoggingInfo(const MPModelRequest &request);
Napi::Value GMPSolver::GetMPModelRequestLoggingInfo(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GMPModelRequest::constructor.Value()))
    {
        Napi::Object request_object = info[0].As<Napi::Object>();
        GMPModelRequest *request    = Napi::ObjectWrap<GMPModelRequest>::Unwrap(request_object);
        std::string logging_info    = MPSolver::GetMPModelRequestLoggingInfo(*request->pMPModelRequest);
        return Napi::String::New(env, logging_info);
    }

    Napi::TypeError::New(env, "GMPSolver::GetMPModelRequestLoggingInfo : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void SetStartingLpBasis(const std::vector<MPSolver::BasisStatus> &variable_statuses, const std::vector<MPSolver::BasisStatus> &constraint_statuses);
Napi::Value GMPSolver::SetStartingLpBasis(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 2 && info[0].IsArray() && info[1].IsArray())
    {
        Napi::Array variable_statuses_array   = info[0].As<Napi::Array>();
        Napi::Array constraint_statuses_array = info[1].As<Napi::Array>();
        std::vector<MPSolver::BasisStatus> variable_statuses;
        std::vector<MPSolver::BasisStatus> constraint_statuses;
        for (int i = 0; i < variable_statuses_array.Length(); i++)
        {
            int status = variable_statuses_array.Get(i).As<Napi::Number>().Int32Value();
            variable_statuses.push_back(static_cast<MPSolver::BasisStatus>(status));
        }
        for (int i = 0; i < constraint_statuses_array.Length(); i++)
        {
            int status = constraint_statuses_array.Get(i).As<Napi::Number>().Int32Value();
            constraint_statuses.push_back(static_cast<MPSolver::BasisStatus>(status));
        }
        this->pMPSolver->SetStartingLpBasis(variable_statuses, constraint_statuses);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPSolver::SetStartingLpBasis : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// static double infinity();
Napi::Value GMPSolver::infinity(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        double infinity = MPSolver::infinity();
        return Napi::Number::New(env, infinity);
    }

    Napi::TypeError::New(env, "GMPSolver::infinity : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// double solver_infinity();
Napi::Value GMPSolver::solver_infinity(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        double solver_infinity = this->pMPSolver->solver_infinity();
        return Napi::Number::New(env, solver_infinity);
    }

    Napi::TypeError::New(env, "GMPSolver::solver_infinity : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// bool OutputIsEnabled() const;
Napi::Value GMPSolver::OutputIsEnabled(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        bool output_is_enabled = this->pMPSolver->OutputIsEnabled();
        return Napi::Boolean::New(env, output_is_enabled);
    }

    Napi::TypeError::New(env, "GMPSolver::OutputIsEnabled : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void EnableOutput();
Napi::Value GMPSolver::EnableOutput(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        this->pMPSolver->EnableOutput();
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPSolver::EnableOutput : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void SuppressOutput();
Napi::Value GMPSolver::SuppressOutput(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        this->pMPSolver->SuppressOutput();
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPSolver::SuppressOutput : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// absl::Duration TimeLimit() const;
Napi::Value GMPSolver::TimeLimit(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        absl::Duration time_limit = this->pMPSolver->TimeLimit();
        return Napi::Number::New(env, absl::ToInt64Milliseconds(time_limit));
    }

    Napi::TypeError::New(env, "GMPSolver::TimeLimit : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void SetTimeLimit(absl::Duration time_limit);
Napi::Value GMPSolver::SetTimeLimit(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        int64_t time_limit_in_milliseconds = info[0].As<Napi::Number>().Int64Value();
        absl::Duration time_limit          = absl::Milliseconds(time_limit_in_milliseconds);
        this->pMPSolver->SetTimeLimit(time_limit);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPSolver::SetTimeLimit : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// absl::Duration DurationSinceConstruction() const;
Napi::Value GMPSolver::DurationSinceConstruction(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        absl::Duration duration_since_construction = this->pMPSolver->DurationSinceConstruction();
        return Napi::Number::New(env, absl::ToInt64Milliseconds(duration_since_construction));
    }

    Napi::TypeError::New(env, "GMPSolver::DurationSinceConstruction : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// int64_t iterations() const;
Napi::Value GMPSolver::iterations(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        int64_t iterations = this->pMPSolver->iterations();
        return Napi::Number::New(env, iterations);
    }

    Napi::TypeError::New(env, "GMPSolver::iterations : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// int64_t nodes() const;
Napi::Value GMPSolver::nodes(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        int64_t nodes = this->pMPSolver->nodes();
        return Napi::Number::New(env, nodes);
    }

    Napi::TypeError::New(env, "GMPSolver::nodes : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// std::string SolverVersion() const;
Napi::Value GMPSolver::SolverVersion(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        std::string solver_version = this->pMPSolver->SolverVersion();
        return Napi::String::New(env, solver_version);
    }

    Napi::TypeError::New(env, "GMPSolver::SolverVersion : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// double ComputeExactConditionNumber() const;
Napi::Value GMPSolver::ComputeExactConditionNumber(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        double condition_number = this->pMPSolver->ComputeExactConditionNumber();
        return Napi::Number::New(env, condition_number);
    }

    Napi::TypeError::New(env, "GMPSolver::ComputeExactConditionNumber : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// ABSL_MUST_USE_RESULT bool NextSolution();
Napi::Value GMPSolver::NextSolution(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        bool has_next_solution = this->pMPSolver->NextSolution();
        return Napi::Boolean::New(env, has_next_solution);
    }

    Napi::TypeError::New(env, "GMPSolver::NextSolution : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void SetCallback(MPCallback *mp_callback);
Napi::Value GMPSolver::SetCallback(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GMPCallback::constructor.Value()))
    {
        auto mp_callback = GMPCallback::Unwrap(info[0].As<Napi::Object>());
        this->pMPSolver->SetCallback(mp_callback->pMPCallback);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPSolver::SetCallback : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// bool SupportsCallbacks() const;
Napi::Value GMPSolver::SupportsCallbacks(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        bool supports_callbacks = this->pMPSolver->SupportsCallbacks();
        return Napi::Boolean::New(env, supports_callbacks);
    }

    Napi::TypeError::New(env, "GMPSolver::SupportsCallbacks : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// static int64_t global_num_variables();
Napi::Value GMPSolver::global_num_variables(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        int64_t global_num_variables = MPSolver::global_num_variables();
        return Napi::Number::New(env, global_num_variables);
    }

    Napi::TypeError::New(env, "GMPSolver::global_num_variables : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// static int64_t global_num_constraints();
Napi::Value GMPSolver::global_num_constraints(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        int64_t global_num_variables = MPSolver::global_num_variables();
        return Napi::Number::New(env, global_num_variables);
    }

    Napi::TypeError::New(env, "GMPSolver::global_num_variables : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// int64_t time_limit() const;
Napi::Value GMPSolver::time_limit(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        int64_t time_limit = this->pMPSolver->time_limit();
        return Napi::Number::New(env, time_limit);
    }

    Napi::TypeError::New(env, "GMPSolver::time_limit : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void set_time_limit(int64_t time_limit_milliseconds);
Napi::Value GMPSolver::set_time_limit(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        int64_t time_limit_milliseconds = info[0].As<Napi::Number>().Int64Value();
        this->pMPSolver->set_time_limit(time_limit_milliseconds);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPSolver::set_time_limit : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// double time_limit_in_secs() const;
Napi::Value GMPSolver::time_limit_in_secs(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        double time_limit_in_secs = this->pMPSolver->time_limit_in_secs();
        return Napi::Number::New(env, time_limit_in_secs);
    }

    Napi::TypeError::New(env, "GMPSolver::time_limit_in_secs : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// int64_t wall_time() const;
Napi::Value GMPSolver::wall_time(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        int64_t wall_time = this->pMPSolver->wall_time();
        return Napi::Number::New(env, wall_time);
    }

    Napi::TypeError::New(env, "GMPSolver::wall_time : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// bool OwnsVariable(const MPVariable *var) const;
Napi::Value GMPSolver::OwnsVariable(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GMPVariable::constructor.Value()))
    {
        auto var      = GMPVariable::Unwrap(info[0].As<Napi::Object>());
        bool owns_var = this->pMPSolver->OwnsVariable(var->pMPVariable);
        return Napi::Boolean::New(env, owns_var);
    }

    Napi::TypeError::New(env, "GMPSolver::OwnsVariable : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

GMPVariable::GMPVariable(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GMPVariable>(info)
{
    Napi::Env env = info.Env();

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external = info[0].As<Napi::External<MPVariable>>();
        pMPVariable   = dynamic_cast<MPVariable *>(external.Data());
        if (pMPVariable) return;
    }

    Napi::TypeError::New(env, "GMPVariable::GMPVariable : Invalid arguments").ThrowAsJavaScriptException();
}

Napi::Object GMPVariable::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "MPVariable",
        {
            InstanceMethod("name", &GMPVariable::name),
            InstanceMethod("SetInteger", &GMPVariable::SetInteger),
            InstanceMethod("integer", &GMPVariable::integer),
            InstanceMethod("solution_value", &GMPVariable::solution_value),
            InstanceMethod("index", &GMPVariable::index),
            InstanceMethod("lb", &GMPVariable::lb),
            InstanceMethod("ub", &GMPVariable::ub),
            InstanceMethod("SetLB", &GMPVariable::SetLB),
            InstanceMethod("SetUB", &GMPVariable::SetUB),
            InstanceMethod("SetBounds", &GMPVariable::SetBounds),
            InstanceMethod("unrounded_solution_value", &GMPVariable::unrounded_solution_value),
            InstanceMethod("reduced_cost", &GMPVariable::reduced_cost),
            InstanceMethod("basis_status", &GMPVariable::basis_status),
            InstanceMethod("branching_priority", &GMPVariable::branching_priority),
            InstanceMethod("SetBranchingPriority", &GMPVariable::SetBranchingPriority),
        }
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set(Napi::String::New(env, "MPVariable"), func);
    return exports;
}

// const std::string &name() const;
Napi::Value GMPVariable::name(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        const std::string &name = this->pMPVariable->name();
        return Napi::String::New(env, name);
    }

    Napi::TypeError::New(env, "GMPVariable::name : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void SetInteger(bool integer);
Napi::Value GMPVariable::SetInteger(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsBoolean())
    {
        bool integer = info[0].As<Napi::Boolean>().Value();
        this->pMPVariable->SetInteger(integer);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPVariable::SetInteger : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// bool integer() const;
Napi::Value GMPVariable::integer(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        bool integer = this->pMPVariable->integer();
        return Napi::Boolean::New(env, integer);
    }

    Napi::TypeError::New(env, "GMPVariable::integer : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// double solution_value() const;
Napi::Value GMPVariable::solution_value(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        double solution_value = this->pMPVariable->solution_value();
        return Napi::Number::New(env, solution_value);
    }

    Napi::TypeError::New(env, "GMPVariable::solution_value : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// int index() const;
Napi::Value GMPVariable::index(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        int index = this->pMPVariable->index();
        return Napi::Number::New(env, index);
    }

    Napi::TypeError::New(env, "GMPVariable::index : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// double lb() const;
Napi::Value GMPVariable::lb(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        double lb = this->pMPVariable->lb();
        return Napi::Number::New(env, lb);
    }

    Napi::TypeError::New(env, "GMPVariable::lb : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// double ub() const;
Napi::Value GMPVariable::ub(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        double ub = this->pMPVariable->ub();
        return Napi::Number::New(env, ub);
    }

    Napi::TypeError::New(env, "GMPVariable::ub : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void SetLB(double lb);
Napi::Value GMPVariable::SetLB(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        double lb = info[0].As<Napi::Number>().DoubleValue();
        this->pMPVariable->SetLB(lb);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPVariable::SetLB : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void SetUB(double ub);
Napi::Value GMPVariable::SetUB(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        double ub = info[0].As<Napi::Number>().DoubleValue();
        this->pMPVariable->SetUB(ub);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPVariable::SetUB : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void SetBounds(double lb, double ub);
Napi::Value GMPVariable::SetBounds(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 2 && info[0].IsNumber() && info[1].IsNumber())
    {
        double lb = info[0].As<Napi::Number>().DoubleValue();
        double ub = info[1].As<Napi::Number>().DoubleValue();
        this->pMPVariable->SetBounds(lb, ub);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPVariable::SetBounds : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// double unrounded_solution_value() const;
Napi::Value GMPVariable::unrounded_solution_value(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        double unrounded_solution_value = this->pMPVariable->unrounded_solution_value();
        return Napi::Number::New(env, unrounded_solution_value);
    }

    Napi::TypeError::New(env, "GMPVariable::unrounded_solution_value : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// double reduced_cost() const;
Napi::Value GMPVariable::reduced_cost(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        double reduced_cost = this->pMPVariable->reduced_cost();
        return Napi::Number::New(env, reduced_cost);
    }

    Napi::TypeError::New(env, "GMPVariable::reduced_cost : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// MPSolver::BasisStatus basis_status() const;
Napi::Value GMPVariable::basis_status(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        MPSolver::BasisStatus status = this->pMPVariable->basis_status();
        return Napi::Number::New(env, static_cast<int>(status));
    }

    Napi::TypeError::New(env, "GMPVariable::basis_status : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// int branching_priority() const;
Napi::Value GMPVariable::branching_priority(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        int priority = this->pMPVariable->branching_priority();
        return Napi::Number::New(env, priority);
    }

    Napi::TypeError::New(env, "GMPVariable::branching_priority : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void SetBranchingPriority(int priority);
Napi::Value GMPVariable::SetBranchingPriority(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        int priority = info[0].As<Napi::Number>().Int32Value();
        this->pMPVariable->SetBranchingPriority(priority);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPVariable::SetBranchingPriority : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

GMPCallback::GMPCallback(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GMPCallback>(info)
{
    Napi::Env env = info.Env();

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external = info[0].As<Napi::External<MPCallback>>();
        pMPCallback   = dynamic_cast<MPCallback *>(external.Data());
        if (pMPCallback) return;
    }

    Napi::TypeError::New(env, "GMPCallback::GMPCallback : Invalid arguments").ThrowAsJavaScriptException();
}

GMPCallback::~GMPCallback()
{
    if (pMPCallback) delete pMPCallback;
}

Napi::Object GMPCallback::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "MPCallback",
        {
            InstanceMethod("RunCallback", &GMPCallback::RunCallback),
            InstanceMethod("might_add_cuts", &GMPCallback::might_add_cuts),
            InstanceMethod("might_add_lazy_constraints", &GMPCallback::might_add_lazy_constraints),
        }
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set(Napi::String::New(env, "MPCallback"), func);
    return exports;
}

// virtual void RunCallback(MPCallbackContext *callback_context) = 0;
Napi::Value GMPCallback::RunCallback(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GMPCallbackContext::constructor.Value()))
    {
        GMPCallbackContext *callback_context = Napi::ObjectWrap<GMPCallbackContext>::Unwrap(info[0].As<Napi::Object>());
        this->pMPCallback->RunCallback(callback_context->pMPCallbackContext);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPCallback::RunCallback : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// bool might_add_cuts() const;
Napi::Value GMPCallback::might_add_cuts(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        bool might_add_cuts = this->pMPCallback->might_add_cuts();
        return Napi::Boolean::New(env, might_add_cuts);
    }

    Napi::TypeError::New(env, "GMPCallback::might_add_cuts : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// bool might_add_lazy_constraints() const;
Napi::Value GMPCallback::might_add_lazy_constraints(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        bool might_add_lazy_constraints = this->pMPCallback->might_add_lazy_constraints();
        return Napi::Boolean::New(env, might_add_lazy_constraints);
    }

    Napi::TypeError::New(env, "GMPCallback::might_add_lazy_constraints : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

GMPModelRequest::GMPModelRequest(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GMPModelRequest>(info)
{
    Napi::Env env = info.Env();

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external   = info[0].As<Napi::External<MPModelRequest>>();
        pMPModelRequest = dynamic_cast<MPModelRequest *>(external.Data());
        if (pMPModelRequest) return;
    }

    Napi::TypeError::New(env, "GMPModelRequest::GMPModelRequest : Invalid arguments").ThrowAsJavaScriptException();
}

GMPModelRequest::~GMPModelRequest()
{
    if (pMPModelRequest) delete pMPModelRequest;
}

Napi::Object GMPModelRequest::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "MPModelRequest",
        {}
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set(Napi::String::New(env, "MPModelRequest"), func);
    return exports;
}

GMPSolutionResponse::GMPSolutionResponse(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GMPSolutionResponse>(info)
{
    Napi::Env env = info.Env();

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external       = info[0].As<Napi::External<MPSolutionResponse>>();
        pMPSolutionResponse = dynamic_cast<MPSolutionResponse *>(external.Data());
        if (pMPSolutionResponse) return;
    }

    Napi::TypeError::New(env, "GMPSolutionResponse::GMPSolutionResponse : Invalid arguments").ThrowAsJavaScriptException();
}

GMPSolutionResponse::~GMPSolutionResponse()
{
    if (pMPSolutionResponse) delete pMPSolutionResponse;
}

Napi::Object GMPSolutionResponse::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "MPSolutionResponse",
        {}
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set(Napi::String::New(env, "MPSolutionResponse"), func);
    return exports;
}

GLinearRange::GLinearRange(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GLinearRange>(info)
{
    Napi::Env env = info.Env();

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external = info[0].As<Napi::External<LinearRange>>();
        pLinearRange  = dynamic_cast<LinearRange *>(external.Data());
        if (pLinearRange) return;
    }

    // LinearRange()
    if (info.Length() == 0)
    {
        pLinearRange = new LinearRange();
        return;
    }

    // LinearRange(double lower_bound, const LinearExpr &linear_expr, double upper_bound);
    if (info.Length() == 3 && info[0].IsNumber() && info[1].IsObject() && info[1].As<Napi::Object>().InstanceOf(GLinearExpr::constructor.Value()) && info[2].IsNumber())
    {
        double lower_bound       = info[0].As<Napi::Number>().DoubleValue();
        GLinearExpr *linear_expr = Napi::ObjectWrap<GLinearExpr>::Unwrap(info[1].As<Napi::Object>());
        double upper_bound       = info[2].As<Napi::Number>().DoubleValue();
        pLinearRange             = new LinearRange(lower_bound, *linear_expr->pLinearExpr, upper_bound);
        return;
    }

    Napi::TypeError::New(env, "GLinearRange::GLinearRange : Invalid arguments").ThrowAsJavaScriptException();
}

GLinearRange::~GLinearRange()
{
    if (pLinearRange) delete pLinearRange;
}

Napi::Object GLinearRange::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "LinearRange",
        {
            InstanceMethod("lower_bound", &GLinearRange::lower_bound),
            InstanceMethod("linear_expr", &GLinearRange::linear_expr),
            InstanceMethod("upper_bound", &GLinearRange::upper_bound),
        }
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set(Napi::String::New(env, "LinearRange"), func);
    return exports;
}

// double lower_bound() const;
Napi::Value GLinearRange::lower_bound(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        double lower_bound = this->pLinearRange->lower_bound();
        return Napi::Number::New(env, lower_bound);
    }

    Napi::TypeError::New(env, "GLinearRange::lower_bound : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// const LinearExpr &linear_expr() const;
Napi::Value GLinearRange::linear_expr(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        auto &linear_expr = this->pLinearRange->linear_expr();
        auto external     = Napi::External<LinearExpr>::New(env, new LinearExpr(linear_expr));
        return GLinearExpr::constructor.New({external});
    }

    Napi::TypeError::New(env, "GLinearRange::linear_expr : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// double upper_bound() const;
Napi::Value GLinearRange::upper_bound(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        double upper_bound = this->pLinearRange->upper_bound();
        return Napi::Number::New(env, upper_bound);
    }

    Napi::TypeError::New(env, "GLinearRange::upper_bound : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

GMPConstraint::GMPConstraint(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GMPConstraint>(info)
{
    Napi::Env env = info.Env();

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external = info[0].As<Napi::External<MPConstraint>>();
        pMPConstraint = dynamic_cast<MPConstraint *>(external.Data());
        if (pMPConstraint) return;
    }

    Napi::TypeError::New(env, "GMPConstraint::GMPConstraint : Invalid arguments").ThrowAsJavaScriptException();
}

Napi::Object GMPConstraint::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "MPConstraint",
        {
            InstanceMethod("name", &GMPConstraint::name),
            InstanceMethod("Clear", &GMPConstraint::Clear),
            InstanceMethod("SetCoefficient", &GMPConstraint::SetCoefficient),
            InstanceMethod("GetCoefficient", &GMPConstraint::GetCoefficient),
            InstanceMethod("terms", &GMPConstraint::terms),
            InstanceMethod("lb", &GMPConstraint::lb),
            InstanceMethod("ub", &GMPConstraint::ub),
            InstanceMethod("SetLB", &GMPConstraint::SetLB),
            InstanceMethod("SetUB", &GMPConstraint::SetUB),
            InstanceMethod("SetBounds", &GMPConstraint::SetBounds),
            InstanceMethod("is_lazy", &GMPConstraint::is_lazy),
            InstanceMethod("set_is_lazy", &GMPConstraint::set_is_lazy),
            InstanceMethod("indicator_variable", &GMPConstraint::indicator_variable),
            InstanceMethod("indicator_value", &GMPConstraint::indicator_value),
            InstanceMethod("index", &GMPConstraint::index),
            InstanceMethod("dual_value", &GMPConstraint::dual_value),
            InstanceMethod("basis_status", &GMPConstraint::basis_status),
        }
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set(Napi::String::New(env, "MPConstraint"), func);
    return exports;
}

// const std::string &name() const;
Napi::Value GMPConstraint::name(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        const std::string &name = this->pMPConstraint->name();
        return Napi::String::New(env, name);
    }

    Napi::TypeError::New(env, "GMPConstraint::name : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void Clear();
Napi::Value GMPConstraint::Clear(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        this->pMPConstraint->Clear();
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPConstraint::Clear : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void SetCoefficient(const MPVariable *var, double coeff);
Napi::Value GMPConstraint::SetCoefficient(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 2 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GMPVariable::constructor.Value()) && info[1].IsNumber())
    {
        GMPVariable *var = Napi::ObjectWrap<GMPVariable>::Unwrap(info[0].As<Napi::Object>());
        double coeff     = info[1].As<Napi::Number>().DoubleValue();
        this->pMPConstraint->SetCoefficient(var->pMPVariable, coeff);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPConstraint::SetCoefficient : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// double GetCoefficient(const MPVariable *var) const;
Napi::Value GMPConstraint::GetCoefficient(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GMPVariable::constructor.Value()))
    {
        GMPVariable *var = Napi::ObjectWrap<GMPVariable>::Unwrap(info[0].As<Napi::Object>());
        double coeff     = this->pMPConstraint->GetCoefficient(var->pMPVariable);
        return Napi::Number::New(env, coeff);
    }

    Napi::TypeError::New(env, "GMPConstraint::GetCoefficient : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// const absl::flat_hash_map<const MPVariable *, double> &terms() const;
Napi::Value GMPConstraint::terms(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        const auto &terms = this->pMPConstraint->terms();
        Napi::Object obj  = Napi::Object::New(env);
        for (const auto &term : terms)
        {
            obj.Set(Napi::String::New(env, term.first->name()), Napi::Number::New(env, term.second));
        }
        return obj;
    }

    Napi::TypeError::New(env, "GMPConstraint::terms : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// double lb() const;
Napi::Value GMPConstraint::lb(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        double lb = this->pMPConstraint->lb();
        return Napi::Number::New(env, lb);
    }

    Napi::TypeError::New(env, "GMPConstraint::lb : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// double ub() const;
Napi::Value GMPConstraint::ub(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        double ub = this->pMPConstraint->ub();
        return Napi::Number::New(env, ub);
    }

    Napi::TypeError::New(env, "GMPConstraint::ub : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void SetLB(double lb);
Napi::Value GMPConstraint::SetLB(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        double lb = info[0].As<Napi::Number>().DoubleValue();
        this->pMPConstraint->SetLB(lb);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPConstraint::SetLB : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void SetUB(double ub);
Napi::Value GMPConstraint::SetUB(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        double ub = info[0].As<Napi::Number>().DoubleValue();
        this->pMPConstraint->SetUB(ub);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPConstraint::SetUB : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void SetBounds(double lb, double ub);
Napi::Value GMPConstraint::SetBounds(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 2 && info[0].IsNumber() && info[1].IsNumber())
    {
        double lb = info[0].As<Napi::Number>().DoubleValue();
        double ub = info[1].As<Napi::Number>().DoubleValue();
        this->pMPConstraint->SetBounds(lb, ub);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPConstraint::SetBounds : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// bool is_lazy() const;
Napi::Value GMPConstraint::is_lazy(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        bool is_lazy = this->pMPConstraint->is_lazy();
        return Napi::Boolean::New(env, is_lazy);
    }

    Napi::TypeError::New(env, "GMPConstraint::is_lazy : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void set_is_lazy(bool laziness);
Napi::Value GMPConstraint::set_is_lazy(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsBoolean())
    {
        bool laziness = info[0].As<Napi::Boolean>().Value();
        this->pMPConstraint->set_is_lazy(laziness);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPConstraint::set_is_lazy : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// const MPVariable *indicator_variable() const;
Napi::Value GMPConstraint::indicator_variable(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        const MPVariable *indicator_variable = this->pMPConstraint->indicator_variable();
        if (indicator_variable)
        {
            auto external = Napi::External<MPVariable>::New(env, const_cast<MPVariable *>(indicator_variable));
            return GMPVariable::constructor.New({external});
        }
        return env.Null();
    }

    Napi::TypeError::New(env, "GMPConstraint::indicator_variable : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// bool indicator_value() const;
Napi::Value GMPConstraint::indicator_value(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        bool indicator_value = this->pMPConstraint->indicator_value();
        return Napi::Boolean::New(env, indicator_value);
    }

    Napi::TypeError::New(env, "GMPConstraint::indicator_value : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// int index() const；
Napi::Value GMPConstraint::index(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        int index = this->pMPConstraint->index();
        return Napi::Number::New(env, index);
    }

    Napi::TypeError::New(env, "GMPConstraint::index : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// double dual_value() const;
Napi::Value GMPConstraint::dual_value(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        double dual_value = this->pMPConstraint->dual_value();
        return Napi::Number::New(env, dual_value);
    }

    Napi::TypeError::New(env, "GMPConstraint::dual_value : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// MPSolver::BasisStatus basis_status() const;
Napi::Value GMPConstraint::basis_status(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        MPSolver::BasisStatus basis_status = this->pMPConstraint->basis_status();
        return Napi::Number::New(env, basis_status);
    }

    Napi::TypeError::New(env, "GMPConstraint::basis_status : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

GMPObjective::GMPObjective(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GMPObjective>(info)
{
    Napi::Env env = info.Env();

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external = info[0].As<Napi::External<MPObjective>>();
        pMPObjective  = dynamic_cast<MPObjective *>(external.Data());
        if (pMPObjective) return;
    }

    Napi::TypeError::New(env, "GMPObjective::GMPObjective : Invalid arguments").ThrowAsJavaScriptException();
}

Napi::Object GMPObjective::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "MPObjective",
        {
            InstanceMethod("Clear", &GMPObjective::Clear),
            InstanceMethod("SetCoefficient", &GMPObjective::SetCoefficient),
            InstanceMethod("GetCoefficient", &GMPObjective::GetCoefficient),
            InstanceMethod("terms", &GMPObjective::terms),
            InstanceMethod("SetOffset", &GMPObjective::SetOffset),
            InstanceMethod("offset", &GMPObjective::offset),
            InstanceMethod("OptimizeLinearExpr", &GMPObjective::OptimizeLinearExpr),
            InstanceMethod("MaximizeLinearExpr", &GMPObjective::MaximizeLinearExpr),
            InstanceMethod("MinimizeLinearExpr", &GMPObjective::MinimizeLinearExpr),
            InstanceMethod("AddLinearExpr", &GMPObjective::AddLinearExpr),
            InstanceMethod("SetOptimizationDirection", &GMPObjective::SetOptimizationDirection),
            InstanceMethod("SetMinimization", &GMPObjective::SetMinimization),
            InstanceMethod("SetMaximization", &GMPObjective::SetMaximization),
            InstanceMethod("maximization", &GMPObjective::maximization),
            InstanceMethod("minimization", &GMPObjective::minimization),
            InstanceMethod("Value", &GMPObjective::Value),
            InstanceMethod("BestBound", &GMPObjective::BestBound),
        }
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set(Napi::String::New(env, "MPObjective"), func);
    return exports;
}

// void Clear();
Napi::Value GMPObjective::Clear(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        this->pMPObjective->Clear();
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPObjective::Clear : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void SetCoefficient(const MPVariable *var, double coeff);
Napi::Value GMPObjective::SetCoefficient(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 2 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GMPVariable::constructor.Value()) && info[1].IsNumber())
    {
        GMPVariable *var = Napi::ObjectWrap<GMPVariable>::Unwrap(info[0].As<Napi::Object>());
        double coeff     = info[1].As<Napi::Number>().DoubleValue();
        this->pMPObjective->SetCoefficient(var->pMPVariable, coeff);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPObjective::SetCoefficient : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// double GetCoefficient(const MPVariable *var) const;
Napi::Value GMPObjective::GetCoefficient(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GMPVariable::constructor.Value()))
    {
        GMPVariable *var = Napi::ObjectWrap<GMPVariable>::Unwrap(info[0].As<Napi::Object>());
        double coeff     = this->pMPObjective->GetCoefficient(var->pMPVariable);
        return Napi::Number::New(env, coeff);
    }

    Napi::TypeError::New(env, "GMPObjective::GetCoefficient : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// const absl::flat_hash_map<const MPVariable *, double> &terms() const;
Napi::Value GMPObjective::terms(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        auto &terms = this->pMPObjective->terms();
        auto ret    = Napi::Object::New(env);
        for (const auto &term : terms)
        {
            ret.Set(Napi::String::New(env, term.first->name()), Napi::Number::New(env, term.second));
        }
        return ret;
    }

    Napi::TypeError::New(env, "GMPObjective::terms : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void SetOffset(double value);
Napi::Value GMPObjective::SetOffset(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        double value = info[0].As<Napi::Number>().DoubleValue();
        this->pMPObjective->SetOffset(value);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPObjective::SetOffset : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// double offset() const;
Napi::Value GMPObjective::offset(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        double offset = this->pMPObjective->offset();
        return Napi::Number::New(env, offset);
    }

    Napi::TypeError::New(env, "GMPObjective::offset : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void OptimizeLinearExpr(const LinearExpr &linear_expr, bool is_maximization);
Napi::Value GMPObjective::OptimizeLinearExpr(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 2 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GLinearExpr::constructor.Value()) && info[1].IsBoolean())
    {
        GLinearExpr *linear_expr = Napi::ObjectWrap<GLinearExpr>::Unwrap(info[0].As<Napi::Object>());
        bool is_maximization     = info[1].As<Napi::Boolean>().Value();
        this->pMPObjective->OptimizeLinearExpr(*linear_expr->pLinearExpr, is_maximization);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPObjective::OptimizeLinearExpr : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void MaximizeLinearExpr(const LinearExpr &linear_expr);
Napi::Value GMPObjective::MaximizeLinearExpr(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GLinearExpr::constructor.Value()))
    {
        GLinearExpr *linear_expr = Napi::ObjectWrap<GLinearExpr>::Unwrap(info[0].As<Napi::Object>());
        this->pMPObjective->MaximizeLinearExpr(*linear_expr->pLinearExpr);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPObjective::MaximizeLinearExpr : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void MinimizeLinearExpr(const LinearExpr &linear_expr);
Napi::Value GMPObjective::MinimizeLinearExpr(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GLinearExpr::constructor.Value()))
    {
        GLinearExpr *linear_expr = Napi::ObjectWrap<GLinearExpr>::Unwrap(info[0].As<Napi::Object>());
        this->pMPObjective->MinimizeLinearExpr(*linear_expr->pLinearExpr);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPObjective::MinimizeLinearExpr : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void AddLinearExpr(const LinearExpr &linear_expr);
Napi::Value GMPObjective::AddLinearExpr(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GLinearExpr::constructor.Value()))
    {
        GLinearExpr *linear_expr = Napi::ObjectWrap<GLinearExpr>::Unwrap(info[0].As<Napi::Object>());
        this->pMPObjective->AddLinearExpr(*linear_expr->pLinearExpr);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPObjective::AddLinearExpr : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void SetOptimizationDirection(bool maximize);
Napi::Value GMPObjective::SetOptimizationDirection(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsBoolean())
    {
        bool maximize = info[0].As<Napi::Boolean>().Value();
        this->pMPObjective->SetOptimizationDirection(maximize);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPObjective::SetOptimizationDirection : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void SetMinimization();
Napi::Value GMPObjective::SetMinimization(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        this->pMPObjective->SetMinimization();
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPObjective::SetMinimization : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void SetMaximization();
Napi::Value GMPObjective::SetMaximization(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        this->pMPObjective->SetMaximization();
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPObjective::SetMaximization : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// bool maximization() const;
Napi::Value GMPObjective::maximization(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        bool maximization = this->pMPObjective->maximization();
        return Napi::Boolean::New(env, maximization);
    }

    Napi::TypeError::New(env, "GMPObjective::maximization : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// bool minimization() const;
Napi::Value GMPObjective::minimization(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        bool minimization = this->pMPObjective->minimization();
        return Napi::Boolean::New(env, minimization);
    }

    Napi::TypeError::New(env, "GMPObjective::minimization : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// double Value() const;
Napi::Value GMPObjective::Value(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        double value = this->pMPObjective->Value();
        return Napi::Number::New(env, value);
    }

    Napi::TypeError::New(env, "GMPObjective::Value : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// double BestBound() const;
Napi::Value GMPObjective::BestBound(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        double best_bound = this->pMPObjective->BestBound();
        return Napi::Number::New(env, best_bound);
    }

    Napi::TypeError::New(env, "GMPObjective::BestBound : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

GMPSolverParameters::GMPSolverParameters(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GMPSolverParameters>(info)
{
    Napi::Env env = info.Env();

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external       = info[0].As<Napi::External<MPSolverParameters>>();
        pMPSolverParameters = dynamic_cast<MPSolverParameters *>(external.Data());
        if (pMPSolverParameters) return;
    }

    // MPSolverParameters();
    if (info.Length() == 0)
    {
        pMPSolverParameters = new MPSolverParameters();
        return;
    }

    Napi::TypeError::New(env, "GMPSolverParameters::GMPSolverParameters : Invalid arguments").ThrowAsJavaScriptException();
}

GMPSolverParameters::~GMPSolverParameters()
{
    if (pMPSolverParameters) delete pMPSolverParameters;
}

Napi::Object GMPSolverParameters::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);

    auto enumDoubleParam = Napi::Object::New(env);
    enumDoubleParam.Set(Napi::String::New(env, "RELATIVE_MIP_GAP"), Napi::Number::New(env, MPSolverParameters::DoubleParam::RELATIVE_MIP_GAP));
    enumDoubleParam.Set(Napi::String::New(env, "PRIMAL_TOLERANCE"), Napi::Number::New(env, MPSolverParameters::DoubleParam::PRIMAL_TOLERANCE));
    enumDoubleParam.Set(Napi::String::New(env, "DUAL_TOLERANCE"), Napi::Number::New(env, MPSolverParameters::DoubleParam::DUAL_TOLERANCE));

    auto enumIntegerParam = Napi::Object::New(env);
    enumIntegerParam.Set(Napi::String::New(env, "PRESOLVE"), Napi::Number::New(env, MPSolverParameters::IntegerParam::PRESOLVE));
    enumIntegerParam.Set(Napi::String::New(env, "LP_ALGORITHM"), Napi::Number::New(env, MPSolverParameters::IntegerParam::LP_ALGORITHM));
    enumIntegerParam.Set(Napi::String::New(env, "INCREMENTALITY"), Napi::Number::New(env, MPSolverParameters::IntegerParam::INCREMENTALITY));
    enumIntegerParam.Set(Napi::String::New(env, "SCALING"), Napi::Number::New(env, MPSolverParameters::IntegerParam::SCALING));

    auto enumPresolveValues = Napi::Object::New(env);
    enumPresolveValues.Set(Napi::String::New(env, "PRESOLVE_OFF"), Napi::Number::New(env, MPSolverParameters::PresolveValues::PRESOLVE_OFF));
    enumPresolveValues.Set(Napi::String::New(env, "PRESOLVE_ON"), Napi::Number::New(env, MPSolverParameters::PresolveValues::PRESOLVE_ON));

    auto enumLpAlgorithmValues = Napi::Object::New(env);
    enumLpAlgorithmValues.Set(Napi::String::New(env, "DUAL"), Napi::Number::New(env, MPSolverParameters::LpAlgorithmValues::DUAL));
    enumLpAlgorithmValues.Set(Napi::String::New(env, "PRIMAL"), Napi::Number::New(env, MPSolverParameters::LpAlgorithmValues::PRIMAL));
    enumLpAlgorithmValues.Set(Napi::String::New(env, "BARRIER"), Napi::Number::New(env, MPSolverParameters::LpAlgorithmValues::BARRIER));

    auto enumIncrementalityValues = Napi::Object::New(env);
    enumIncrementalityValues.Set(Napi::String::New(env, "INCREMENTALITY_OFF"), Napi::Number::New(env, MPSolverParameters::IncrementalityValues::INCREMENTALITY_OFF));
    enumIncrementalityValues.Set(Napi::String::New(env, "INCREMENTALITY_ON"), Napi::Number::New(env, MPSolverParameters::IncrementalityValues::INCREMENTALITY_ON));

    auto enumScalingValues = Napi::Object::New(env);
    enumScalingValues.Set(Napi::String::New(env, "SCALING_OFF"), Napi::Number::New(env, MPSolverParameters::ScalingValues::SCALING_OFF));
    enumScalingValues.Set(Napi::String::New(env, "SCALING_ON"), Napi::Number::New(env, MPSolverParameters::ScalingValues::SCALING_ON));

    Napi::Function func = DefineClass(
        env,
        "MPSolverParameters",
        {
            StaticValue("enumDoubleParam", enumDoubleParam),
            StaticValue("enumIntegerParam", enumIntegerParam),
            StaticValue("enumPresolveValues", enumPresolveValues),
            StaticValue("enumLpAlgorithmValues", enumLpAlgorithmValues),
            StaticValue("enumIncrementalityValues", enumIncrementalityValues),
            StaticValue("enumScalingValues", enumScalingValues),

            StaticValue("kDefaultDoubleParamValue", Napi::Number::New(env, MPSolverParameters::kDefaultDoubleParamValue)),
            StaticValue("kDefaultIntegerParamValue", Napi::Number::New(env, MPSolverParameters::kDefaultIntegerParamValue)),
            StaticValue("kUnknownDoubleParamValue", Napi::Number::New(env, MPSolverParameters::kUnknownDoubleParamValue)),
            StaticValue("kUnknownIntegerParamValue", Napi::Number::New(env, MPSolverParameters::kUnknownIntegerParamValue)),
            StaticValue("kDefaultRelativeMipGap", Napi::Number::New(env, MPSolverParameters::kDefaultRelativeMipGap)),
            StaticValue("kDefaultPrimalTolerance", Napi::Number::New(env, MPSolverParameters::kDefaultPrimalTolerance)),
            StaticValue("kDefaultDualTolerance", Napi::Number::New(env, MPSolverParameters::kDefaultDualTolerance)),
            StaticValue("kDefaultPresolve", Napi::Number::New(env, MPSolverParameters::kDefaultPresolve)),
            StaticValue("kDefaultIncrementality", Napi::Number::New(env, MPSolverParameters::kDefaultIncrementality)),

            InstanceMethod("SetDoubleParam", &GMPSolverParameters::SetDoubleParam),
            InstanceMethod("SetIntegerParam", &GMPSolverParameters::SetIntegerParam),
            InstanceMethod("ResetDoubleParam", &GMPSolverParameters::ResetDoubleParam),
            InstanceMethod("ResetIntegerParam", &GMPSolverParameters::ResetIntegerParam),
            InstanceMethod("Reset", &GMPSolverParameters::Reset),
            InstanceMethod("GetDoubleParam", &GMPSolverParameters::GetDoubleParam),
            InstanceMethod("GetIntegerParam", &GMPSolverParameters::GetIntegerParam),
        }
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set(Napi::String::New(env, "MPSolverParameters"), func);
    return exports;
}

// void SetDoubleParam(MPSolverParameters::DoubleParam param, double value);
Napi::Value GMPSolverParameters::SetDoubleParam(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 2 && info[0].IsNumber() && info[1].IsNumber())
    {
        MPSolverParameters::DoubleParam param = static_cast<MPSolverParameters::DoubleParam>(info[0].As<Napi::Number>().Int32Value());
        double value                          = info[1].As<Napi::Number>().DoubleValue();
        this->pMPSolverParameters->SetDoubleParam(param, value);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPSolverParameters::SetDoubleParam : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void SetIntegerParam(MPSolverParameters::IntegerParam param, int value);
Napi::Value GMPSolverParameters::SetIntegerParam(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 2 && info[0].IsNumber() && info[1].IsNumber())
    {
        MPSolverParameters::IntegerParam param = static_cast<MPSolverParameters::IntegerParam>(info[0].As<Napi::Number>().Int32Value());
        int value                              = info[1].As<Napi::Number>().Int32Value();
        this->pMPSolverParameters->SetIntegerParam(param, value);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPSolverParameters::SetIntegerParam : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void ResetDoubleParam(MPSolverParameters::DoubleParam param);
Napi::Value GMPSolverParameters::ResetDoubleParam(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        MPSolverParameters::DoubleParam param = static_cast<MPSolverParameters::DoubleParam>(info[0].As<Napi::Number>().Int32Value());
        this->pMPSolverParameters->ResetDoubleParam(param);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPSolverParameters::ResetDoubleParam : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void ResetIntegerParam(MPSolverParameters::IntegerParam param);
Napi::Value GMPSolverParameters::ResetIntegerParam(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        MPSolverParameters::IntegerParam param = static_cast<MPSolverParameters::IntegerParam>(info[0].As<Napi::Number>().Int32Value());
        this->pMPSolverParameters->ResetIntegerParam(param);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPSolverParameters::ResetIntegerParam : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void Reset();
Napi::Value GMPSolverParameters::Reset(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        this->pMPSolverParameters->Reset();
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GMPSolverParameters::Reset : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// double GetDoubleParam(MPSolverParameters::DoubleParam param) const;
Napi::Value GMPSolverParameters::GetDoubleParam(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        MPSolverParameters::DoubleParam param = static_cast<MPSolverParameters::DoubleParam>(info[0].As<Napi::Number>().Int32Value());
        double value                          = this->pMPSolverParameters->GetDoubleParam(param);
        return Napi::Number::New(env, value);
    }

    Napi::TypeError::New(env, "GMPSolverParameters::GetDoubleParam : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// int GetIntegerParam(MPSolverParameters::IntegerParam param) const;
Napi::Value GMPSolverParameters::GetIntegerParam(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        MPSolverParameters::IntegerParam param = static_cast<MPSolverParameters::IntegerParam>(info[0].As<Napi::Number>().Int32Value());
        int value                              = this->pMPSolverParameters->GetIntegerParam(param);
        return Napi::Number::New(env, value);
    }

    Napi::TypeError::New(env, "GMPSolverParameters::GetIntegerParam : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

GMPCallbackContext::GMPCallbackContext(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GMPCallbackContext>(info)
{
    Napi::Env env = info.Env();

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external      = info[0].As<Napi::External<MPCallbackContext>>();
        pMPCallbackContext = dynamic_cast<MPCallbackContext *>(external.Data());
        if (pMPCallbackContext) return;
    }

    Napi::TypeError::New(env, "GMPCallbackContext::GMPCallbackContext : Invalid arguments").ThrowAsJavaScriptException();
}

GMPCallbackContext::~GMPCallbackContext()
{
    if (pMPCallbackContext) delete pMPCallbackContext;
}

Napi::Object GMPCallbackContext::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "MPCallbackContext",
        {}
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set(Napi::String::New(env, "MPCallbackContext"), func);
    return exports;
}

GLinearExpr::GLinearExpr(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GLinearExpr>(info)
{
    Napi::Env env = info.Env();

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external = info[0].As<Napi::External<LinearExpr>>();
        pLinearExpr   = dynamic_cast<LinearExpr *>(external.Data());
        if (pLinearExpr) return;
    }

    // LinearExpr();
    if (info.Length() == 0)
    {
        pLinearExpr = new LinearExpr();
        return;
    }

    // LinearExpr(double constant);
    if (info.Length() == 1 && info[0].IsNumber())
    {
        double constant = info[0].As<Napi::Number>().DoubleValue();
        pLinearExpr     = new LinearExpr(constant);
        return;
    }

    // LinearExpr(const MPVariable *var);
    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GMPVariable::constructor.Value()))
    {
        auto var    = GMPVariable::Unwrap(info[0].As<Napi::Object>());
        pLinearExpr = new LinearExpr(var->pMPVariable);
        return;
    }

    Napi::TypeError::New(env, "GLinearExpr::GLinearExpr : Invalid arguments").ThrowAsJavaScriptException();
}

GLinearExpr::~GLinearExpr()
{
    if (pLinearExpr) delete pLinearExpr;
}

Napi::Object GLinearExpr::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "LinearExpr",
        {
            StaticMethod("NotVar", &GLinearExpr::NotVar),
            InstanceMethod("operator_plus_equals", &GLinearExpr::operator_plus_equals),
            InstanceMethod("operator_minus_equals", &GLinearExpr::operator_minus_equals),
            InstanceMethod("operator_times_equals", &GLinearExpr::operator_times_equals),
            InstanceMethod("operator_divide_equals", &GLinearExpr::operator_divide_equals),
            InstanceMethod("operator_negate", &GLinearExpr::operator_negate),
            InstanceMethod("offset", &GLinearExpr::offset),
            InstanceMethod("terms", &GLinearExpr::terms),
            InstanceMethod("SolutionValue", &GLinearExpr::SolutionValue),
            InstanceMethod("ToString", &GLinearExpr::ToString),
        }
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set(Napi::String::New(env, "LinearExpr"), func);
    return exports;
}

bool GLinearExpr::ToLinearExpr(const Napi::Value &value, LinearExpr &expr)
{
    if (value.IsObject() && value.As<Napi::Object>().InstanceOf(GLinearExpr::constructor.Value()))
        expr = *GLinearExpr::Unwrap(value.As<Napi::Object>())->pLinearExpr;
    else if (value.IsNumber())
        expr = value.As<Napi::Number>().DoubleValue();
    else if (value.IsObject() && value.As<Napi::Object>().InstanceOf(GMPVariable::constructor.Value()))
        expr = GMPVariable::Unwrap(value.As<Napi::Object>())->pMPVariable;
    else
        return false;

    return true;
}

// static LinearExpr NotVar(LinearExpr var);
Napi::Value GLinearExpr::NotVar(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GLinearExpr::constructor.Value()))
    {
        LinearExpr *pLinearExpr = GLinearExpr::Unwrap(info[0].As<Napi::Object>())->pLinearExpr;
        LinearExpr result       = LinearExpr::NotVar(*pLinearExpr);
        return GLinearExpr::constructor.New({Napi::External<LinearExpr>::New(env, new LinearExpr(result))});
    }

    Napi::TypeError::New(env, "GLinearExpr::NotVar : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// LinearExpr &operator+=(const LinearExpr &rhs);
Napi::Value GLinearExpr::operator_plus_equals(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr rhs;
    if (info.Length() == 1 && ToLinearExpr(info[0], rhs))
    {
        *pLinearExpr += rhs;
        return this->Value();
    }

    Napi::TypeError::New(env, "GLinearExpr::operator+= : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// LinearExpr &operator-=(const LinearExpr &rhs);
Napi::Value GLinearExpr::operator_minus_equals(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr rhs;
    if (info.Length() == 1 && ToLinearExpr(info[0], rhs))
    {
        *pLinearExpr -= rhs;
        return this->Value();
    }

    Napi::TypeError::New(env, "GLinearExpr::operator-= : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// LinearExpr &operator*=(double rhs);
Napi::Value GLinearExpr::operator_times_equals(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        double rhs = info[0].As<Napi::Number>().DoubleValue();
        *pLinearExpr *= rhs;
        return this->Value();
    }

    Napi::TypeError::New(env, "GLinearExpr::operator*= : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// LinearExpr &operator/=(double rhs);
Napi::Value GLinearExpr::operator_divide_equals(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        double rhs = info[0].As<Napi::Number>().DoubleValue();
        *pLinearExpr /= rhs;
        return this->Value();
    }

    Napi::TypeError::New(env, "GLinearExpr::operator/= : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// LinearExpr operator-() const;
Napi::Value GLinearExpr::operator_negate(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        LinearExpr result = -(*pLinearExpr);
        return GLinearExpr::constructor.New({Napi::External<LinearExpr>::New(env, new LinearExpr(result))});
    }

    Napi::TypeError::New(env, "GLinearExpr::operator- : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// double offset() const;
Napi::Value GLinearExpr::offset(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        return Napi::Number::New(env, pLinearExpr->offset());
    }

    Napi::TypeError::New(env, "GLinearExpr::offset : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// const absl::flat_hash_map<const MPVariable *, double> &terms() const;
Napi::Value GLinearExpr::terms(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        Napi::Object result = Napi::Object::New(env);
        for (const auto &term : pLinearExpr->terms())
        {
            result.Set(Napi::String::New(env, term.first->name()), Napi::Number::New(env, term.second));
        }
        return result;
    }

    Napi::TypeError::New(env, "GLinearExpr::terms : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// double SolutionValue() const;
Napi::Value GLinearExpr::SolutionValue(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        return Napi::Number::New(env, pLinearExpr->SolutionValue());
    }

    Napi::TypeError::New(env, "GLinearExpr::SolutionValue : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// std::string ToString() const;
Napi::Value GLinearExpr::ToString(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        return Napi::String::New(env, pLinearExpr->ToString());
    }

    Napi::TypeError::New(env, "GLinearExpr::ToString : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
} // namespace operations_research

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    google::InitGoogleLogging("ortools_binding");
    absl::SetFlag(&FLAGS_stderrthreshold, 0);

    Napi::HandleScope scope(env);

    auto operations_research = Napi::Object::New(env);
    // {
    //     auto packing = Napi::Object::New( env );
    //     operations_research::packing::GBinPacking2dParser::Init( env, packing );
    //     operations_research::packing::GMultipleDimensionsBinPackingItem::Init( env, packing );
    //     operations_research::packing::GMultipleDimensionsBinPackingProblem::Init( env, packing );
    //     operations_research::packing::GMultipleDimensionsBinPackingShape::Init( env, packing );
    //     operations_research.Set( "packing", packing );
    // }
    // {
    //     auto sat = Napi::Object::New( env );
    //     operations_research::sat::GBoolVar::Init( env, sat );
    //     operations_research::sat::GCpModelBuilder::Init( env, sat );
    //     operations_research::sat::GCpModelProto::Init( env, sat );
    //     operations_research::sat::GConstraint::Init( env, sat );
    //     operations_research::sat::GCpSolverResponse::Init( env, sat );
    //     operations_research::sat::EnumInit( env, sat );
    //     operations_research::sat::FuncInit( env, sat );
    //     operations_research::sat::GIntervalVar::Init( env, sat );
    //     operations_research::sat::GIntVar::Init( env, sat );
    //     operations_research::sat::GLinearExpr::Init( env, sat );
    //     operations_research::sat::GNoOverlap2DConstraint::Init( env, sat );
    //     operations_research::sat::GSatParameters::Init( env, sat );
    //     operations_research::sat::GTableConstraint::Init( env, sat );
    //     operations_research.Set( "sat", sat );
    // }
    operations_research::GMPSolver::Init(env, operations_research);
    operations_research::GMPVariable::Init(env, operations_research);
    operations_research::GMPCallback::Init(env, operations_research);
    operations_research::GMPModelRequest::Init(env, operations_research);
    operations_research::GMPSolutionResponse::Init(env, operations_research);
    operations_research::GLinearRange::Init(env, operations_research);
    operations_research::GMPConstraint::Init(env, operations_research);
    operations_research::GMPObjective::Init(env, operations_research);
    operations_research::GMPSolverParameters::Init(env, operations_research);
    operations_research::GMPCallbackContext::Init(env, operations_research);
    operations_research::GLinearExpr::Init(env, operations_research);
    operations_research::FuncInit(env, operations_research);
    exports.Set("operations_research", operations_research);

    return exports;
}

NODE_API_MODULE(ortools_binding, Init);
