#include "ortools001.hpp"

operations_research::GMPSolver::GMPSolver(const Napi::CallbackInfo &info)
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

    Napi::TypeError::New(env, "operations_research::GMPSolver::GMPSolver : Invalid arguments").ThrowAsJavaScriptException();
}

operations_research::GMPSolver::~GMPSolver()
{
    if (pMPSolver) delete pMPSolver;
}

Napi::Object operations_research::GMPSolver::Init(Napi::Env env, Napi::Object exports)
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
            // InstanceMethod("variable", &GMPSolver::variable),
            // InstanceMethod("LookupVariableOrNull", &GMPSolver::LookupVariableOrNull),
            // InstanceMethod("MakeVar", &GMPSolver::MakeVar),
            // InstanceMethod("MakeNumVar", &GMPSolver::MakeNumVar),
            // InstanceMethod("MakeIntVar", &GMPSolver::MakeIntVar),
            // InstanceMethod("MakeBoolVar", &GMPSolver::MakeBoolVar),
            // InstanceMethod("MakeVarArray", &GMPSolver::MakeVarArray),
            // InstanceMethod("MakeNumVarArray", &GMPSolver::MakeNumVarArray),
            // InstanceMethod("MakeIntVarArray", &GMPSolver::MakeIntVarArray),
            // InstanceMethod("MakeBoolVarArray", &GMPSolver::MakeBoolVarArray),
            // InstanceMethod("NumConstraints", &GMPSolver::NumConstraints),
            // InstanceMethod("constraints", &GMPSolver::constraints),
            // InstanceMethod("constraint", &GMPSolver::constraint),
            // InstanceMethod("LookupConstraintOrNull", &GMPSolver::LookupConstraintOrNull),
            // InstanceMethod("MakeRowConstraint", &GMPSolver::MakeRowConstraint),
            // InstanceMethod("MakeRowConstraint", &GMPSolver::MakeRowConstraint),
            // InstanceMethod("MakeRowConstraint", &GMPSolver::MakeRowConstraint),
            // InstanceMethod("MakeRowConstraint", &GMPSolver::MakeRowConstraint),
            // InstanceMethod("MakeRowConstraint", &GMPSolver::MakeRowConstraint),
            // InstanceMethod("Objective", &GMPSolver::Objective),
            // InstanceMethod("MutableObjective", &GMPSolver::MutableObjective),
            // InstanceMethod("Solve", &GMPSolver::Solve),
            // InstanceMethod("Solve", &GMPSolver::Solve),
            // InstanceMethod("Write", &GMPSolver::Write),
            // InstanceMethod("ComputeConstraintActivities", &GMPSolver::ComputeConstraintActivities),
            // InstanceMethod("VerifySolution", &GMPSolver::VerifySolution),
            // InstanceMethod("Reset", &GMPSolver::Reset),
            // InstanceMethod("InterruptSolve", &GMPSolver::InterruptSolve),
            // InstanceMethod("LoadModelFromProto", &GMPSolver::LoadModelFromProto),
            // InstanceMethod("LoadModelFromProtoWithUniqueNamesOrDie", &GMPSolver::LoadModelFromProtoWithUniqueNamesOrDie),
            // InstanceMethod("FillSolutionResponseProto", &GMPSolver::FillSolutionResponseProto),
            // StaticMethod("SolveWithProto", &GMPSolver::SolveWithProto),
            // StaticMethod("SolveLazyMutableRequest", &GMPSolver::SolveLazyMutableRequest),
            // StaticMethod("SolverTypeSupportsInterruption", &GMPSolver::SolverTypeSupportsInterruption),
            // InstanceMethod("ExportModelToProto", &GMPSolver::ExportModelToProto),
            // InstanceMethod("LoadSolutionFromProto", &GMPSolver::LoadSolutionFromProto),
            // InstanceMethod("ClampSolutionWithinBounds", &GMPSolver::ClampSolutionWithinBounds),
            // InstanceMethod("ExportModelAsLpFormat", &GMPSolver::ExportModelAsLpFormat),
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
Napi::Value operations_research::GMPSolver::CreateSolver(const Napi::CallbackInfo &info)
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

    Napi::TypeError::New(env, "operations_research::GMPSolver::CreateSolver : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// static bool SupportsProblemType(OptimizationProblemType problem_type);
Napi::Value operations_research::GMPSolver::SupportsProblemType(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        int problem_type = info[0].As<Napi::Number>().Int32Value();
        bool supported   = MPSolver::SupportsProblemType(static_cast<MPSolver::OptimizationProblemType>(problem_type));
        return Napi::Boolean::New(env, supported);
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::SupportsProblemType : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// static bool ParseSolverType(absl::string_view solver_id, OptimizationProblemType *type);
Napi::Value operations_research::GMPSolver::ParseSolverType(const Napi::CallbackInfo &info)
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

    Napi::TypeError::New(env, "operations_research::GMPSolver::ParseSolverType : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// static OptimizationProblemType ParseSolverTypeOrDie(const std::string &solver_id);
Napi::Value operations_research::GMPSolver::ParseSolverTypeOrDie(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsString())
    {
        std::string solver_id                          = info[0].As<Napi::String>().Utf8Value();
        MPSolver::OptimizationProblemType problem_type = MPSolver::ParseSolverTypeOrDie(solver_id);
        return Napi::Number::New(env, static_cast<int>(problem_type));
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::ParseSolverTypeOrDie : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// bool IsMIP() const;
Napi::Value operations_research::GMPSolver::IsMIP(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        bool is_mip = this->pMPSolver->IsMIP();
        return Napi::Boolean::New(env, is_mip);
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::IsMIP : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// const std::string &Name() const;
Napi::Value operations_research::GMPSolver::Name(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        std::string name = this->pMPSolver->Name();
        return Napi::String::New(env, name);
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::Name : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// virtual OptimizationProblemType ProblemType() const;
Napi::Value operations_research::GMPSolver::ProblemType(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        MPSolver::OptimizationProblemType problem_type = this->pMPSolver->ProblemType();
        return Napi::Number::New(env, static_cast<int>(problem_type));
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::ProblemType : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void Clear();
Napi::Value operations_research::GMPSolver::Clear(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        this->pMPSolver->Clear();
        return env.Undefined();
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::Clear : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// int NumVariables() const;
Napi::Value operations_research::GMPSolver::NumVariables(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        int num_variables = this->pMPSolver->NumVariables();
        return Napi::Number::New(env, num_variables);
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::NumVariables : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// const std::vector<MPVariable *> &variables() const;
Napi::Value operations_research::GMPSolver::variables(const Napi::CallbackInfo &info)
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

    Napi::TypeError::New(env, "operations_research::GMPSolver::variables : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// MPVariable *variable(int index) const;
// MPVariable *LookupVariableOrNull(const std::string &var_name) const;
// MPVariable *MakeVar(double lb, double ub, bool integer, const std::string &name);
// MPVariable *MakeNumVar(double lb, double ub, const std::string &name);
// MPVariable *MakeIntVar(double lb, double ub, const std::string &name);
// MPVariable *MakeBoolVar(const std::string &name);
// void MakeVarArray(int nb, double lb, double ub, bool integer, const std::string &name_prefix, std::vector<MPVariable *> *vars);
// void MakeNumVarArray(int nb, double lb, double ub, const std::string &name, std::vector<MPVariable *> *vars);
// void MakeIntVarArray(int nb, double lb, double ub, const std::string &name, std::vector<MPVariable *> *vars);
// void MakeBoolVarArray(int nb, const std::string &name, std::vector<MPVariable *> *vars);
// int NumConstraints() const;
// const std::vector<MPConstraint *> &constraints() const;
// MPConstraint *constraint(int index) const;
// MPConstraint *LookupConstraintOrNull(const std::string &constraint_name) const;
// MPConstraint *MakeRowConstraint(double lb, double ub);
// MPConstraint *MakeRowConstraint();
// MPConstraint *MakeRowConstraint(double lb, double ub, const std::string &name);
// MPConstraint *MakeRowConstraint(const std::string &name);
// MPConstraint *MakeRowConstraint(const LinearRange &range);
// MPConstraint *MakeRowConstraint(const LinearRange &range, const std::string &name);
// const MPObjective &Objective() const;
// MPObjective *MutableObjective();
// ResultStatus Solve();
// ResultStatus Solve(const MPSolverParameters &param);
// void Write(const std::string &file_name);
// std::vector<double> ComputeConstraintActivities() const;
// bool VerifySolution(double tolerance, bool log_errors) const;
// void Reset();
// bool InterruptSolve();
// MPSolverResponseStatus LoadModelFromProto(const MPModelProto &input_model, std::string *error_message, bool clear_names = true);
// MPSolverResponseStatus LoadModelFromProtoWithUniqueNamesOrDie(const MPModelProto &input_model, std::string *error_message);
// void FillSolutionResponseProto(MPSolutionResponse *response) const;
// static void SolveWithProto(const MPModelRequest &model_request, MPSolutionResponse *response, std::atomic<bool> *interrupt = nullptr);
// static void SolveLazyMutableRequest(LazyMutableCopy<MPModelRequest> request, MPSolutionResponse *response, std::atomic<bool> *interrupt = nullptr);
// static bool SolverTypeSupportsInterruption(const MPModelRequest::SolverType solver);
// void ExportModelToProto(MPModelProto *output_model) const;
// absl::Status LoadSolutionFromProto(const MPSolutionResponse &response, double tolerance = std::numeric_limits<double>::infinity());
// absl::Status ClampSolutionWithinBounds();
// bool ExportModelAsLpFormat(bool obfuscate, std::string *model_str) const;
// bool ExportModelAsMpsFormat(bool fixed_format, bool obfuscate, std::string *model_str) const;
Napi::Value operations_research::GMPSolver::ExportModelAsMpsFormat(const Napi::CallbackInfo &info)
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

    Napi::TypeError::New(env, "operations_research::GMPSolver::ExportModelAsLpFormat : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// absl::Status SetNumThreads(int num_threads);
Napi::Value operations_research::GMPSolver::SetNumThreads(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        int num_threads = info[0].As<Napi::Number>().Int32Value();
        auto success    = this->pMPSolver->SetNumThreads(num_threads);
        return Napi::Boolean::New(env, success.ok());
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::SetNumThreads : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// int GetNumThreads() const;
Napi::Value operations_research::GMPSolver::GetNumThreads(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        int num_threads = this->pMPSolver->GetNumThreads();
        return Napi::Number::New(env, num_threads);
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::GetNumThreads : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// bool SetSolverSpecificParametersAsString(const std::string &parameters);
Napi::Value operations_research::GMPSolver::SetSolverSpecificParametersAsString(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsString())
    {
        std::string parameters = info[0].As<Napi::String>().Utf8Value();
        bool success           = this->pMPSolver->SetSolverSpecificParametersAsString(parameters);
        return Napi::Boolean::New(env, success);
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::SetSolverSpecificParametersAsString : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// std::string GetSolverSpecificParametersAsString() const;
Napi::Value operations_research::GMPSolver::GetSolverSpecificParametersAsString(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        std::string parameters = this->pMPSolver->GetSolverSpecificParametersAsString();
        return Napi::String::New(env, parameters);
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::GetSolverSpecificParametersAsString : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void SetHint(std::vector<std::pair<const MPVariable *, double>> hint);
Napi::Value operations_research::GMPSolver::SetHint(const Napi::CallbackInfo &info)
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
                Napi::TypeError::New(env, "operations_research::GMPSolver::SetHint : Invalid hint array").ThrowAsJavaScriptException();
                return env.Null();
            }
            Napi::Object variable_object = hint_array_inner.Get(static_cast<uint32_t>(0)).As<Napi::Object>();
            if (!variable_object.InstanceOf(GMPVariable::constructor.Value()))
            {
                Napi::TypeError::New(env, "operations_research::GMPSolver::SetHint : Invalid hint array").ThrowAsJavaScriptException();
                return env.Null();
            }
            GMPVariable *variable = Napi::ObjectWrap<GMPVariable>::Unwrap(variable_object);
            double value          = hint_array_inner.Get(1).As<Napi::Number>().DoubleValue();
            hint.push_back(std::make_pair(variable->pMPVariable, value));
        }
        this->pMPSolver->SetHint(hint);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::SetHint : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// static std::string GetMPModelRequestLoggingInfo(const MPModelRequest &request);
Napi::Value operations_research::GMPSolver::GetMPModelRequestLoggingInfo(const Napi::CallbackInfo &info)
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

    Napi::TypeError::New(env, "operations_research::GMPSolver::GetMPModelRequestLoggingInfo : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void SetStartingLpBasis(const std::vector<MPSolver::BasisStatus> &variable_statuses, const std::vector<MPSolver::BasisStatus> &constraint_statuses);
Napi::Value operations_research::GMPSolver::SetStartingLpBasis(const Napi::CallbackInfo &info)
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

    Napi::TypeError::New(env, "operations_research::GMPSolver::SetStartingLpBasis : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// static double infinity();
Napi::Value operations_research::GMPSolver::infinity(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        double infinity = MPSolver::infinity();
        return Napi::Number::New(env, infinity);
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::infinity : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// double solver_infinity();
Napi::Value operations_research::GMPSolver::solver_infinity(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        double solver_infinity = this->pMPSolver->solver_infinity();
        return Napi::Number::New(env, solver_infinity);
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::solver_infinity : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// bool OutputIsEnabled() const;
Napi::Value operations_research::GMPSolver::OutputIsEnabled(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        bool output_is_enabled = this->pMPSolver->OutputIsEnabled();
        return Napi::Boolean::New(env, output_is_enabled);
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::OutputIsEnabled : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void EnableOutput();
Napi::Value operations_research::GMPSolver::EnableOutput(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        this->pMPSolver->EnableOutput();
        return env.Undefined();
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::EnableOutput : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void SuppressOutput();
Napi::Value operations_research::GMPSolver::SuppressOutput(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        this->pMPSolver->SuppressOutput();
        return env.Undefined();
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::SuppressOutput : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// absl::Duration TimeLimit() const;
Napi::Value operations_research::GMPSolver::TimeLimit(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        absl::Duration time_limit = this->pMPSolver->TimeLimit();
        return Napi::Number::New(env, absl::ToInt64Milliseconds(time_limit));
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::TimeLimit : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void SetTimeLimit(absl::Duration time_limit);
Napi::Value operations_research::GMPSolver::SetTimeLimit(const Napi::CallbackInfo &info)
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

    Napi::TypeError::New(env, "operations_research::GMPSolver::SetTimeLimit : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// absl::Duration DurationSinceConstruction() const;
Napi::Value operations_research::GMPSolver::DurationSinceConstruction(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        absl::Duration duration_since_construction = this->pMPSolver->DurationSinceConstruction();
        return Napi::Number::New(env, absl::ToInt64Milliseconds(duration_since_construction));
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::DurationSinceConstruction : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// int64_t iterations() const;
Napi::Value operations_research::GMPSolver::iterations(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        int64_t iterations = this->pMPSolver->iterations();
        return Napi::Number::New(env, iterations);
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::iterations : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// int64_t nodes() const;
Napi::Value operations_research::GMPSolver::nodes(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        int64_t nodes = this->pMPSolver->nodes();
        return Napi::Number::New(env, nodes);
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::nodes : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// std::string SolverVersion() const;
Napi::Value operations_research::GMPSolver::SolverVersion(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        std::string solver_version = this->pMPSolver->SolverVersion();
        return Napi::String::New(env, solver_version);
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::SolverVersion : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// double ComputeExactConditionNumber() const;
Napi::Value operations_research::GMPSolver::ComputeExactConditionNumber(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        double condition_number = this->pMPSolver->ComputeExactConditionNumber();
        return Napi::Number::New(env, condition_number);
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::ComputeExactConditionNumber : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// ABSL_MUST_USE_RESULT bool NextSolution();
Napi::Value operations_research::GMPSolver::NextSolution(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        bool has_next_solution = this->pMPSolver->NextSolution();
        return Napi::Boolean::New(env, has_next_solution);
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::NextSolution : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void SetCallback(MPCallback *mp_callback);
Napi::Value operations_research::GMPSolver::SetCallback(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GMPCallback::constructor.Value()))
    {
        auto mp_callback = GMPCallback::Unwrap(info[0].As<Napi::Object>());
        this->pMPSolver->SetCallback(mp_callback->pMPCallback);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::SetCallback : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// bool SupportsCallbacks() const;
Napi::Value operations_research::GMPSolver::SupportsCallbacks(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        bool supports_callbacks = this->pMPSolver->SupportsCallbacks();
        return Napi::Boolean::New(env, supports_callbacks);
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::SupportsCallbacks : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// static int64_t global_num_variables();
Napi::Value operations_research::GMPSolver::global_num_variables(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        int64_t global_num_variables = MPSolver::global_num_variables();
        return Napi::Number::New(env, global_num_variables);
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::global_num_variables : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// static int64_t global_num_constraints();
Napi::Value operations_research::GMPSolver::global_num_constraints(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        int64_t global_num_variables = MPSolver::global_num_variables();
        return Napi::Number::New(env, global_num_variables);
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::global_num_variables : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// int64_t time_limit() const;
Napi::Value operations_research::GMPSolver::time_limit(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        int64_t time_limit = this->pMPSolver->time_limit();
        return Napi::Number::New(env, time_limit);
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::time_limit : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void set_time_limit(int64_t time_limit_milliseconds);
Napi::Value operations_research::GMPSolver::set_time_limit(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        int64_t time_limit_milliseconds = info[0].As<Napi::Number>().Int64Value();
        this->pMPSolver->set_time_limit(time_limit_milliseconds);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::set_time_limit : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// double time_limit_in_secs() const;
Napi::Value operations_research::GMPSolver::time_limit_in_secs(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        double time_limit_in_secs = this->pMPSolver->time_limit_in_secs();
        return Napi::Number::New(env, time_limit_in_secs);
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::time_limit_in_secs : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// int64_t wall_time() const;
Napi::Value operations_research::GMPSolver::wall_time(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        int64_t wall_time = this->pMPSolver->wall_time();
        return Napi::Number::New(env, wall_time);
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::wall_time : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// bool OwnsVariable(const MPVariable *var) const;
Napi::Value operations_research::GMPSolver::OwnsVariable(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GMPVariable::constructor.Value()))
    {
        auto var      = GMPVariable::Unwrap(info[0].As<Napi::Object>());
        bool owns_var = this->pMPSolver->OwnsVariable(var->pMPVariable);
        return Napi::Boolean::New(env, owns_var);
    }

    Napi::TypeError::New(env, "operations_research::GMPSolver::OwnsVariable : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}