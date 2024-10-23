#include "or_sat.hpp"
namespace operations_research
{
namespace sat
{

#pragma region Functions

// inline LinearExpr operator-(LinearExpr expr)
Napi::Value Goperator_nagate(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr expr;
    if (info.Length() == 1 && GLinearExpr::ToLinearExpr(info[0], expr))
    {
        auto result   = -expr;
        auto external = Napi::External<LinearExpr>::New(env, new LinearExpr(result));
        return GLinearExpr::constructor.New({external});
    }

    Napi::TypeError::New(env, "Goperator_nagate : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// inline LinearExpr operator+(const LinearExpr[] exprs)
Napi::Value Goperator_plus(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    std::vector<LinearExpr> exprs;
    if (info.Length() == 1 && info[0].IsArray())
    {
        Napi::Array arr = info[0].As<Napi::Array>();
        for (uint32_t i = 0; i < arr.Length(); i++)
        {
            LinearExpr expr;
            if (GLinearExpr::ToLinearExpr(arr[i], expr))
            {
                exprs.push_back(expr);
                continue;
            }
            Napi::TypeError::New(env, "Goperator_plus : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }

        LinearExpr result = 0;
        for (const auto &expr : exprs) result += expr;
        auto external = Napi::External<LinearExpr>::New(env, new LinearExpr(result));
        return GLinearExpr::constructor.New({external});
    }

    Napi::TypeError::New(env, "Goperator_plus : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// inline LinearExpr operator-(const LinearExpr &lhs, const LinearExpr &rhs)
Napi::Value Goperator_minus(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr lhs, rhs;
    if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], lhs) && GLinearExpr::ToLinearExpr(info[1], rhs))
    {
        auto result   = lhs - rhs;
        auto external = Napi::External<LinearExpr>::New(env, new LinearExpr(result));
        return GLinearExpr::constructor.New({external});
    }

    Napi::TypeError::New(env, "Goperator_minus : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

Napi::Value Goperator_times(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr expr;

    // inline LinearExpr operator*(LinearExpr expr, int64_t factor)
    if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], expr) && info[1].IsNumber())
    {
        int64_t factor = info[1].As<Napi::Number>().Int64Value();
        auto result    = factor * expr;
        auto external  = Napi::External<LinearExpr>::New(env, new LinearExpr(result));
        return GLinearExpr::constructor.New({external});
    }

    // inline LinearExpr operator*(int64_t factor, LinearExpr expr)
    if (info.Length() == 2 && info[0].IsNumber() && GLinearExpr::ToLinearExpr(info[1], expr))
    {
        int64_t factor = info[0].As<Napi::Number>().Int64Value();
        auto result    = factor * expr;
        auto external  = Napi::External<LinearExpr>::New(env, new LinearExpr(result));
        return GLinearExpr::constructor.New({external});
    }

    Napi::TypeError::New(env, "Goperator_times : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// CpSolverResponse Solve(const CpModelProto &model_proto);
Napi::Value GSolve(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GCpModelProto::constructor.Value()))
    {
        auto model_proto = GCpModelProto::Unwrap(info[0].As<Napi::Object>());
        auto response    = Solve(*model_proto->pCpModelProto);
        auto external    = Napi::External<CpSolverResponse>::New(env, new CpSolverResponse(response));
        return GCpSolverResponse::constructor.New({external});
    }

    Napi::TypeError::New(env, "GSolve : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// int64_t SolutionIntegerValue(const CpSolverResponse &r, const LinearExpr &expr);
Napi::Value GSolutionIntegerValue(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr expr;
    if (info.Length() == 2 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GCpSolverResponse::constructor.Value()) && GLinearExpr::ToLinearExpr(info[1], expr))
    {
        auto response = GCpSolverResponse::Unwrap(info[0].As<Napi::Object>());
        return Napi::Number::New(env, SolutionIntegerValue(*response->pCpSolverResponse, expr));
    }

    Napi::TypeError::New(env, "GSolutionIntegerValue : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// std::string CpSolverResponseStats(const CpSolverResponse &response, bool has_objective = true);
Napi::Value GCpSolverResponseStats(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GCpSolverResponse::constructor.Value()))
    {
        auto response = GCpSolverResponse::Unwrap(info[0].As<Napi::Object>());
        return Napi::String::New(env, CpSolverResponseStats(*response->pCpSolverResponse));
    }

    if (info.Length() == 2 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GCpSolverResponse::constructor.Value()) && info[1].IsBoolean())
    {
        auto response      = GCpSolverResponse::Unwrap(info[0].As<Napi::Object>());
        bool has_objective = info[1].As<Napi::Boolean>().Value();
        return Napi::String::New(env, CpSolverResponseStats(*response->pCpSolverResponse, has_objective));
    }

    Napi::TypeError::New(env, "GCpSolverResponseStats : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

Napi::Object SatInit(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);

    exports.Set("operator_nagate", Napi::Function::New(env, Goperator_nagate));
    exports.Set("operator_plus", Napi::Function::New(env, Goperator_plus));
    exports.Set("operator_minus", Napi::Function::New(env, Goperator_minus));
    exports.Set("operator_times", Napi::Function::New(env, Goperator_times));
    exports.Set("Solve", Napi::Function::New(env, GSolve));
    exports.Set("SolutionIntegerValue", Napi::Function::New(env, GSolutionIntegerValue));
    exports.Set("CpSolverResponseStats", Napi::Function::New(env, GCpSolverResponseStats));

    auto enumCpSolverStatus = Napi::Object::New(env);
    enumCpSolverStatus.Set("UNKNOWN", static_cast<int>(CpSolverStatus::UNKNOWN));
    enumCpSolverStatus.Set("MODEL_INVALID", static_cast<int>(CpSolverStatus::MODEL_INVALID));
    enumCpSolverStatus.Set("FEASIBLE", static_cast<int>(CpSolverStatus::FEASIBLE));
    enumCpSolverStatus.Set("INFEASIBLE", static_cast<int>(CpSolverStatus::INFEASIBLE));
    enumCpSolverStatus.Set("OPTIMAL", static_cast<int>(CpSolverStatus::OPTIMAL));
    exports.Set("CpSolverStatus", enumCpSolverStatus);

    return exports;
}

#pragma endregion

GCpModelBuilder::GCpModelBuilder(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GCpModelBuilder>(info)
{
    Napi::Env env = info.Env();

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external   = info[0].As<Napi::External<CpModelBuilder>>();
        pCpModelBuilder = dynamic_cast<CpModelBuilder *>(external.Data());
        if (pCpModelBuilder) return;
    }

    if (info.Length() == 0)
    {
        pCpModelBuilder = new CpModelBuilder();
        return;
    }

    Napi::TypeError::New(env, "GCpModelBuilder::GCpModelBuilder : Invalid arguments").ThrowAsJavaScriptException();
}

GCpModelBuilder::~GCpModelBuilder()
{
    if (pCpModelBuilder) delete pCpModelBuilder;
}

Napi::Object GCpModelBuilder::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "CpModelBuilder",
        {
            InstanceMethod("SetName", &GCpModelBuilder::SetName),
            InstanceMethod("NewIntVar", &GCpModelBuilder::NewIntVar),
            InstanceMethod("NewBoolVar", &GCpModelBuilder::NewBoolVar),
            InstanceMethod("NewConstant", &GCpModelBuilder::NewConstant),
            InstanceMethod("TrueVar", &GCpModelBuilder::TrueVar),
            InstanceMethod("FalseVar", &GCpModelBuilder::FalseVar),
            InstanceMethod("NewIntervalVar", &GCpModelBuilder::NewIntervalVar),
            InstanceMethod("NewFixedSizeIntervalVar", &GCpModelBuilder::NewFixedSizeIntervalVar),
            InstanceMethod("NewOptionalIntervalVar", &GCpModelBuilder::NewOptionalIntervalVar),
            InstanceMethod("NewOptionalFixedSizeIntervalVar", &GCpModelBuilder::NewOptionalFixedSizeIntervalVar),
            InstanceMethod("FixVariable", &GCpModelBuilder::FixVariable),
            InstanceMethod("AddBoolOr", &GCpModelBuilder::AddBoolOr),
            InstanceMethod("AddAtLeastOne", &GCpModelBuilder::AddAtLeastOne),
            InstanceMethod("AddAtMostOne", &GCpModelBuilder::AddAtMostOne),
            InstanceMethod("AddExactlyOne", &GCpModelBuilder::AddExactlyOne),
            InstanceMethod("AddBoolAnd", &GCpModelBuilder::AddBoolAnd),
            InstanceMethod("AddBoolXor", &GCpModelBuilder::AddBoolXor),
            InstanceMethod("AddImplication", &GCpModelBuilder::AddImplication),
            InstanceMethod("AddEquality", &GCpModelBuilder::AddEquality),
            InstanceMethod("AddGreaterOrEqual", &GCpModelBuilder::AddGreaterOrEqual),
            InstanceMethod("AddGreaterThan", &GCpModelBuilder::AddGreaterThan),
            InstanceMethod("AddLessOrEqual", &GCpModelBuilder::AddLessOrEqual),
            InstanceMethod("AddLessThan", &GCpModelBuilder::AddLessThan),
            InstanceMethod("AddLinearConstraint", &GCpModelBuilder::AddLinearConstraint),
            InstanceMethod("AddNotEqual", &GCpModelBuilder::AddNotEqual),
            InstanceMethod("AddAllDifferent", &GCpModelBuilder::AddAllDifferent),
            InstanceMethod("AddVariableElement", &GCpModelBuilder::AddVariableElement),
            InstanceMethod("AddElement", &GCpModelBuilder::AddElement),
            InstanceMethod("AddCircuitConstraint", &GCpModelBuilder::AddCircuitConstraint),
            InstanceMethod("AddMultipleCircuitConstraint", &GCpModelBuilder::AddMultipleCircuitConstraint),
            InstanceMethod("AddAllowedAssignments", &GCpModelBuilder::AddAllowedAssignments),
            InstanceMethod("AddForbiddenAssignments", &GCpModelBuilder::AddForbiddenAssignments),
            InstanceMethod("AddInverseConstraint", &GCpModelBuilder::AddInverseConstraint),
            InstanceMethod("AddReservoirConstraint", &GCpModelBuilder::AddReservoirConstraint),
            InstanceMethod("AddAutomaton", &GCpModelBuilder::AddAutomaton),
            InstanceMethod("AddMinEquality", &GCpModelBuilder::AddMinEquality),
            InstanceMethod("AddMaxEquality", &GCpModelBuilder::AddMaxEquality),
            InstanceMethod("AddDivisionEquality", &GCpModelBuilder::AddDivisionEquality),
            InstanceMethod("AddAbsEquality", &GCpModelBuilder::AddAbsEquality),
            InstanceMethod("AddModuloEquality", &GCpModelBuilder::AddModuloEquality),
            InstanceMethod("AddMultiplicationEquality", &GCpModelBuilder::AddMultiplicationEquality),
            InstanceMethod("AddNoOverlap", &GCpModelBuilder::AddNoOverlap),
            InstanceMethod("AddNoOverlap2D", &GCpModelBuilder::AddNoOverlap2D),
            InstanceMethod("AddCumulative", &GCpModelBuilder::AddCumulative),
            InstanceMethod("Minimize", &GCpModelBuilder::Minimize),
            InstanceMethod("Maximize", &GCpModelBuilder::Maximize),
            InstanceMethod("ClearObjective", &GCpModelBuilder::ClearObjective),
            InstanceMethod("HasObjective", &GCpModelBuilder::HasObjective),
            InstanceMethod("AddDecisionStrategy", &GCpModelBuilder::AddDecisionStrategy),
            InstanceMethod("AddHint", &GCpModelBuilder::AddHint),
            InstanceMethod("ClearHints", &GCpModelBuilder::ClearHints),
            InstanceMethod("AddAssumption", &GCpModelBuilder::AddAssumption),
            InstanceMethod("AddAssumptions", &GCpModelBuilder::AddAssumptions),
            InstanceMethod("ClearAssumptions", &GCpModelBuilder::ClearAssumptions),
            InstanceMethod("Build", &GCpModelBuilder::Build),
            InstanceMethod("Proto", &GCpModelBuilder::Proto),
            InstanceMethod("MutableProto", &GCpModelBuilder::MutableProto),
            InstanceMethod("ExportToFile", &GCpModelBuilder::ExportToFile),
            InstanceMethod("Clone", &GCpModelBuilder::Clone),
            InstanceMethod("GetBoolVarFromProtoIndex", &GCpModelBuilder::GetBoolVarFromProtoIndex),
            InstanceMethod("GetIntVarFromProtoIndex", &GCpModelBuilder::GetIntVarFromProtoIndex),
            InstanceMethod("GetIntervalVarFromProtoIndex", &GCpModelBuilder::GetIntervalVarFromProtoIndex),
        }
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set(Napi::String::New(env, "CpModelBuilder"), func);
    return exports;
}

// void SetName(absl::string_view name);
Napi::Value GCpModelBuilder::SetName(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsString())
    {
        std::string name = info[0].As<Napi::String>().Utf8Value();
        pCpModelBuilder->SetName(name);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GCpModelBuilder::SetName : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// IntVar NewIntVar(const Domain &domain);
Napi::Value GCpModelBuilder::NewIntVar(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GDomain::constructor.Value()))
    {
        auto domain     = info[0].As<Napi::Object>();
        Domain *pDomain = GDomain::Unwrap(domain)->pDomain;
        IntVar var      = pCpModelBuilder->NewIntVar(*pDomain);
        auto external   = Napi::External<IntVar>::New(env, new IntVar(var));
        return GIntVar::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::NewIntVar : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// BoolVar NewBoolVar();
Napi::Value GCpModelBuilder::NewBoolVar(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        BoolVar var   = pCpModelBuilder->NewBoolVar();
        auto external = Napi::External<BoolVar>::New(env, new BoolVar(var));
        return GBoolVar::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::NewBoolVar : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// IntVar NewConstant(int64_t value);
Napi::Value GCpModelBuilder::NewConstant(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        int64_t value = info[0].As<Napi::Number>().Int64Value();
        IntVar var    = pCpModelBuilder->NewConstant(value);
        auto external = Napi::External<IntVar>::New(env, new IntVar(var));
        return GIntVar::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::NewConstant : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// BoolVar TrueVar();
Napi::Value GCpModelBuilder::TrueVar(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        BoolVar var   = pCpModelBuilder->TrueVar();
        auto external = Napi::External<BoolVar>::New(env, new BoolVar(var));
        return GBoolVar::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::TrueVar : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// BoolVar FalseVar();
Napi::Value GCpModelBuilder::FalseVar(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        BoolVar var   = pCpModelBuilder->FalseVar();
        auto external = Napi::External<BoolVar>::New(env, new BoolVar(var));
        return GBoolVar::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::FalseVar : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// IntervalVar NewIntervalVar(const LinearExpr &start, const LinearExpr &size, const LinearExpr &end);
Napi::Value GCpModelBuilder::NewIntervalVar(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr start;
    LinearExpr size;
    LinearExpr end;
    if (info.Length() == 3 && GLinearExpr::ToLinearExpr(info[0], start) && GLinearExpr::ToLinearExpr(info[1], size) && GLinearExpr::ToLinearExpr(info[2], end))
    {
        IntervalVar var = pCpModelBuilder->NewIntervalVar(start, size, end);
        auto external   = Napi::External<IntervalVar>::New(env, new IntervalVar(var));
        return GIntervalVar::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::NewIntervalVar : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// IntervalVar NewFixedSizeIntervalVar(const LinearExpr &start, int64_t size);
Napi::Value GCpModelBuilder::NewFixedSizeIntervalVar(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr start;
    if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], start) && info[1].IsNumber())
    {
        int64_t size    = info[1].As<Napi::Number>().Int64Value();
        IntervalVar var = pCpModelBuilder->NewFixedSizeIntervalVar(start, size);
        auto external   = Napi::External<IntervalVar>::New(env, new IntervalVar(var));
        return GIntervalVar::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::NewFixedSizeIntervalVar : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// IntervalVar NewOptionalIntervalVar(const LinearExpr &start, const LinearExpr &size, const LinearExpr &end, BoolVar presence);
Napi::Value GCpModelBuilder::NewOptionalIntervalVar(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr start;
    LinearExpr size;
    LinearExpr end;
    if (info.Length() == 4 && GLinearExpr::ToLinearExpr(info[0], start) && GLinearExpr::ToLinearExpr(info[1], size) && GLinearExpr::ToLinearExpr(info[2], end) &&
        info[3].IsObject() && info[3].As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
    {
        auto presence      = info[3].As<Napi::Object>();
        BoolVar *pPresence = GBoolVar::Unwrap(presence)->pBoolVar;
        IntervalVar var    = pCpModelBuilder->NewOptionalIntervalVar(start, size, end, *pPresence);
        auto external      = Napi::External<IntervalVar>::New(env, new IntervalVar(var));
        return GIntervalVar::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::NewOptionalIntervalVar : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// IntervalVar NewOptionalFixedSizeIntervalVar(const LinearExpr &start, int64_t size, BoolVar presence);
Napi::Value GCpModelBuilder::NewOptionalFixedSizeIntervalVar(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr start;
    if (info.Length() == 3 && GLinearExpr::ToLinearExpr(info[0], start) && info[1].IsNumber() &&
        info[2].IsObject() && info[2].As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
    {
        int64_t size    = info[1].As<Napi::Number>().Int64Value();
        auto presence   = info[2].As<Napi::Object>();
        BoolVar *pVar   = GBoolVar::Unwrap(presence)->pBoolVar;
        IntervalVar var = pCpModelBuilder->NewOptionalFixedSizeIntervalVar(start, size, *pVar);
        auto external   = Napi::External<IntervalVar>::New(env, new IntervalVar(var));
        return GIntervalVar::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::NewOptionalFixedSizeIntervalVar : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

Napi::Value GCpModelBuilder::FixVariable(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    // void FixVariable(IntVar var, int64_t value);
    if (info.Length() == 2 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()) &&
        info[1].IsNumber())
    {
        auto var      = info[0].As<Napi::Object>();
        int64_t value = info[1].As<Napi::Number>().Int64Value();
        IntVar *pVar  = GIntVar::Unwrap(var)->pIntVar;
        pCpModelBuilder->FixVariable(*pVar, value);
        return env.Undefined();
    }

    // void FixVariable(BoolVar var, bool value);
    if (info.Length() == 2 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()) &&
        info[1].IsBoolean())
    {
        auto var      = info[0].As<Napi::Object>();
        bool value    = info[1].As<Napi::Boolean>();
        BoolVar *pVar = GBoolVar::Unwrap(var)->pBoolVar;
        pCpModelBuilder->FixVariable(*pVar, value);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GCpModelBuilder::FixVariable : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// Constraint AddBoolOr(absl::Span<const BoolVar> literals);
Napi::Value GCpModelBuilder::AddBoolOr(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsArray())
    {
        Napi::Array literals = info[0].As<Napi::Array>();
        std::vector<BoolVar> vec;
        for (uint32_t i = 0; i < literals.Length(); i++)
        {
            auto literal = literals.Get(i);
            if (literal.IsObject() && literal.As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
            {
                auto var      = literal.As<Napi::Object>();
                BoolVar *pVar = GBoolVar::Unwrap(var)->pBoolVar;
                vec.push_back(*pVar);
                continue;
            }

            Napi::TypeError::New(env, "GCpModelBuilder::AddBoolOr : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        Constraint ct = pCpModelBuilder->AddBoolOr(vec);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddBoolOr : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// Constraint AddAtLeastOne(absl::Span<const BoolVar> literals);
Napi::Value GCpModelBuilder::AddAtLeastOne(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsArray())
    {
        Napi::Array literals = info[0].As<Napi::Array>();
        std::vector<BoolVar> vec;
        for (uint32_t i = 0; i < literals.Length(); i++)
        {
            auto literal = literals.Get(i);
            if (literal.IsObject() && literal.As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
            {
                auto var      = literal.As<Napi::Object>();
                BoolVar *pVar = GBoolVar::Unwrap(var)->pBoolVar;
                vec.push_back(*pVar);
                continue;
            }

            Napi::TypeError::New(env, "GCpModelBuilder::AddAtLeastOne : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        Constraint ct = pCpModelBuilder->AddAtLeastOne(vec);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddAtLeastOne : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// Constraint AddAtMostOne(absl::Span<const BoolVar> literals);
Napi::Value GCpModelBuilder::AddAtMostOne(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsArray())
    {
        Napi::Array literals = info[0].As<Napi::Array>();
        std::vector<BoolVar> vec;
        for (uint32_t i = 0; i < literals.Length(); i++)
        {
            auto literal = literals.Get(i);
            if (literal.IsObject() && literal.As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
            {
                auto var      = literal.As<Napi::Object>();
                BoolVar *pVar = GBoolVar::Unwrap(var)->pBoolVar;
                vec.push_back(*pVar);
                continue;
            }

            Napi::TypeError::New(env, "GCpModelBuilder::AddAtMostOne : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        Constraint ct = pCpModelBuilder->AddAtMostOne(vec);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddAtMostOne : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// Constraint AddExactlyOne(absl::Span<const BoolVar> literals);
Napi::Value GCpModelBuilder::AddExactlyOne(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsArray())
    {
        Napi::Array literals = info[0].As<Napi::Array>();
        std::vector<BoolVar> vec;
        for (uint32_t i = 0; i < literals.Length(); i++)
        {
            auto literal = literals.Get(i);
            if (literal.IsObject() && literal.As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
            {
                auto var      = literal.As<Napi::Object>();
                BoolVar *pVar = GBoolVar::Unwrap(var)->pBoolVar;
                vec.push_back(*pVar);
                continue;
            }

            Napi::TypeError::New(env, "GCpModelBuilder::AddExactlyOne : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        Constraint ct = pCpModelBuilder->AddExactlyOne(vec);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddExactlyOne : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// Constraint AddBoolAnd(absl::Span<const BoolVar> literals);
Napi::Value GCpModelBuilder::AddBoolAnd(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsArray())
    {
        Napi::Array literals = info[0].As<Napi::Array>();
        std::vector<BoolVar> vec;
        for (uint32_t i = 0; i < literals.Length(); i++)
        {
            auto literal = literals.Get(i);
            if (literal.IsObject() && literal.As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
            {
                auto var      = literal.As<Napi::Object>();
                BoolVar *pVar = GBoolVar::Unwrap(var)->pBoolVar;
                vec.push_back(*pVar);
                continue;
            }

            Napi::TypeError::New(env, "GCpModelBuilder::AddBoolAnd : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        Constraint ct = pCpModelBuilder->AddBoolAnd(vec);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddBoolAnd : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// Constraint AddBoolXor(absl::Span<const BoolVar> literals);
Napi::Value GCpModelBuilder::AddBoolXor(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsArray())
    {
        Napi::Array literals = info[0].As<Napi::Array>();
        std::vector<BoolVar> vec;
        for (uint32_t i = 0; i < literals.Length(); i++)
        {
            auto literal = literals.Get(i);
            if (literal.IsObject() && literal.As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
            {
                auto var      = literal.As<Napi::Object>();
                BoolVar *pVar = GBoolVar::Unwrap(var)->pBoolVar;
                vec.push_back(*pVar);
                continue;
            }

            Napi::TypeError::New(env, "GCpModelBuilder::AddBoolXor : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        Constraint ct = pCpModelBuilder->AddBoolXor(vec);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddBoolXor : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
Napi::Value GCpModelBuilder::AddImplication(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    // Constraint AddImplication(BoolVar a, BoolVar b);
    if (info.Length() == 2 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()) &&
        info[1].IsObject() && info[1].As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
    {
        auto a        = info[0].As<Napi::Object>();
        auto b        = info[1].As<Napi::Object>();
        BoolVar *pA   = GBoolVar::Unwrap(a)->pBoolVar;
        BoolVar *pB   = GBoolVar::Unwrap(b)->pBoolVar;
        Constraint ct = pCpModelBuilder->AddImplication(*pA, *pB);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    // Constraint AddImplication(absl::Span<const BoolVar> lhs, absl::Span<const BoolVar> rhs);
    if (info.Length() == 2 && info[0].IsArray() && info[1].IsArray())
    {
        Napi::Array lhs = info[0].As<Napi::Array>();
        Napi::Array rhs = info[1].As<Napi::Array>();
        std::vector<BoolVar> vecA;
        std::vector<BoolVar> vecB;
        for (uint32_t i = 0; i < lhs.Length(); i++)
        {
            auto literal = lhs.Get(i);
            if (literal.IsObject() && literal.As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
            {
                auto var      = literal.As<Napi::Object>();
                BoolVar *pVar = GBoolVar::Unwrap(var)->pBoolVar;
                vecA.push_back(*pVar);
                continue;
            }

            Napi::TypeError::New(env, "GCpModelBuilder::AddImplication : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        for (uint32_t i = 0; i < rhs.Length(); i++)
        {
            auto literal = rhs.Get(i);
            if (literal.IsObject() && literal.As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
            {
                auto var      = literal.As<Napi::Object>();
                BoolVar *pVar = GBoolVar::Unwrap(var)->pBoolVar;
                vecB.push_back(*pVar);
                continue;
            }

            Napi::TypeError::New(env, "GCpModelBuilder::AddImplication : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        Constraint ct = pCpModelBuilder->AddImplication(vecA, vecB);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddImplication : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// Constraint AddEquality(const LinearExpr &left, const LinearExpr &right);
Napi::Value GCpModelBuilder::AddEquality(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr left;
    LinearExpr right;
    if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], left) && GLinearExpr::ToLinearExpr(info[1], right))
    {
        Constraint ct = pCpModelBuilder->AddEquality(left, right);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddEquality : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// Constraint AddGreaterOrEqual(const LinearExpr &left, const LinearExpr &right);
Napi::Value GCpModelBuilder::AddGreaterOrEqual(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr left;
    LinearExpr right;
    if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], left) && GLinearExpr::ToLinearExpr(info[1], right))
    {
        Constraint ct = pCpModelBuilder->AddGreaterOrEqual(left, right);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddGreaterOrEqual : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// Constraint AddGreaterThan(const LinearExpr &left, const LinearExpr &right);
Napi::Value GCpModelBuilder::AddGreaterThan(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr left;
    LinearExpr right;
    if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], left) && GLinearExpr::ToLinearExpr(info[1], right))
    {
        Constraint ct = pCpModelBuilder->AddGreaterThan(left, right);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddGreaterThan : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// Constraint AddLessOrEqual(const LinearExpr &left, const LinearExpr &right);
Napi::Value GCpModelBuilder::AddLessOrEqual(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr left;
    LinearExpr right;
    if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], left) && GLinearExpr::ToLinearExpr(info[1], right))
    {
        Constraint ct = pCpModelBuilder->AddLessOrEqual(left, right);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddLessOrEqual : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// Constraint AddLessThan(const LinearExpr &left, const LinearExpr &right);
Napi::Value GCpModelBuilder::AddLessThan(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr left;
    LinearExpr right;
    if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], left) && GLinearExpr::ToLinearExpr(info[1], right))
    {
        Constraint ct = pCpModelBuilder->AddLessThan(left, right);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddLessThan : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// Constraint AddLinearConstraint(const LinearExpr &expr, const Domain &domain);
Napi::Value GCpModelBuilder::AddLinearConstraint(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr expr;
    if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], expr) && info[1].IsObject() && info[1].As<Napi::Object>().InstanceOf(GDomain::constructor.Value()))
    {
        auto domain   = GDomain::Unwrap(info[1].As<Napi::Object>())->pDomain;
        Constraint ct = pCpModelBuilder->AddLinearConstraint(expr, *domain);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddLinearConstraint : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// Constraint AddNotEqual(const LinearExpr &left, const LinearExpr &right);
Napi::Value GCpModelBuilder::AddNotEqual(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr left;
    LinearExpr right;
    if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], left) && GLinearExpr::ToLinearExpr(info[1], right))
    {
        Constraint ct = pCpModelBuilder->AddNotEqual(left, right);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddNotEqual : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// Constraint AddAllDifferent(absl::Span<const IntVar> vars);
// Constraint AddAllDifferent(absl::Span<const LinearExpr> exprs);
// Constraint AddAllDifferent(std::initializer_list<LinearExpr> exprs);
Napi::Value GCpModelBuilder::AddAllDifferent(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsArray())
    {
        Napi::Array exprs = info[0].As<Napi::Array>();
        std::vector<LinearExpr> vec;
        for (uint32_t i = 0; i < exprs.Length(); i++)
        {
            auto expr = exprs.Get(i);
            LinearExpr linearExpr;
            if (GLinearExpr::ToLinearExpr(expr, linearExpr))
            {
                vec.push_back(linearExpr);
                continue;
            }

            Napi::TypeError::New(env, "GCpModelBuilder::AddAllDifferent : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }

        Constraint ct = pCpModelBuilder->AddAllDifferent(vec);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddAllDifferent : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// Constraint AddVariableElement(IntVar index, absl::Span<const IntVar> variables, IntVar target);
Napi::Value GCpModelBuilder::AddVariableElement(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 3 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()) &&
        info[1].IsArray() && info[2].IsObject() && info[2].As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()))
    {
        auto index            = GIntVar::Unwrap(info[0].As<Napi::Object>())->pIntVar;
        Napi::Array variables = info[1].As<Napi::Array>();
        std::vector<IntVar> vec;
        for (uint32_t i = 0; i < variables.Length(); i++)
        {
            auto var = variables.Get(i);
            if (var.IsObject() && var.As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()))
            {
                auto pVar = GIntVar::Unwrap(var.As<Napi::Object>())->pIntVar;
                vec.push_back(*pVar);
                continue;
            }

            Napi::TypeError::New(env, "GCpModelBuilder::AddVariableElement : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        auto target   = GIntVar::Unwrap(info[2].As<Napi::Object>())->pIntVar;
        Constraint ct = pCpModelBuilder->AddVariableElement(*index, vec, *target);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddVariableElement : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// Constraint AddElement(IntVar index, absl::Span<const int64_t> values, IntVar target);
Napi::Value GCpModelBuilder::AddElement(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 3 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()) &&
        info[1].IsArray() && info[2].IsObject() && info[2].As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()))
    {
        auto index         = GIntVar::Unwrap(info[0].As<Napi::Object>())->pIntVar;
        Napi::Array values = info[1].As<Napi::Array>();
        std::vector<int64_t> vec;
        for (uint32_t i = 0; i < values.Length(); i++)
        {
            auto value = values.Get(i);
            if (value.IsNumber())
            {
                vec.push_back(value.As<Napi::Number>().Int64Value());
                continue;
            }

            Napi::TypeError::New(env, "GCpModelBuilder::AddElement : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        auto target   = GIntVar::Unwrap(info[2].As<Napi::Object>())->pIntVar;
        Constraint ct = pCpModelBuilder->AddElement(*index, vec, *target);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddElement : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// CircuitConstraint AddCircuitConstraint();
Napi::Value GCpModelBuilder::AddCircuitConstraint(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        CircuitConstraint ct = pCpModelBuilder->AddCircuitConstraint();
        auto external        = Napi::External<CircuitConstraint>::New(env, new CircuitConstraint(ct));
        return GCircuitConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddCircuitConstraint : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// MultipleCircuitConstraint AddMultipleCircuitConstraint();
Napi::Value GCpModelBuilder::AddMultipleCircuitConstraint(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        MultipleCircuitConstraint ct = pCpModelBuilder->AddMultipleCircuitConstraint();
        auto external                = Napi::External<MultipleCircuitConstraint>::New(env, new MultipleCircuitConstraint(ct));
        return GMultipleCircuitConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddMultipleCircuitConstraint : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// TableConstraint AddAllowedAssignments(absl::Span<const IntVar> vars);
Napi::Value GCpModelBuilder::AddAllowedAssignments(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsArray())
    {
        Napi::Array vars = info[0].As<Napi::Array>();
        std::vector<IntVar> vec;
        for (uint32_t i = 0; i < vars.Length(); i++)
        {
            auto var = vars.Get(i);
            if (var.IsObject() && var.As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()))
            {
                auto pVar = GIntVar::Unwrap(var.As<Napi::Object>())->pIntVar;
                vec.push_back(*pVar);
                continue;
            }

            Napi::TypeError::New(env, "GCpModelBuilder::AddAllowedAssignments : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        TableConstraint ct = pCpModelBuilder->AddAllowedAssignments(vec);
        auto external      = Napi::External<TableConstraint>::New(env, new TableConstraint(ct));
        return GTableConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddAllowedAssignments : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// TableConstraint AddForbiddenAssignments(absl::Span<const IntVar> vars);
Napi::Value GCpModelBuilder::AddForbiddenAssignments(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsArray())
    {
        Napi::Array vars = info[0].As<Napi::Array>();
        std::vector<IntVar> vec;
        for (uint32_t i = 0; i < vars.Length(); i++)
        {
            auto var = vars.Get(i);
            if (var.IsObject() && var.As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()))
            {
                auto pVar = GIntVar::Unwrap(var.As<Napi::Object>())->pIntVar;
                vec.push_back(*pVar);
                continue;
            }

            Napi::TypeError::New(env, "GCpModelBuilder::AddForbiddenAssignments : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        TableConstraint ct = pCpModelBuilder->AddForbiddenAssignments(vec);
        auto external      = Napi::External<TableConstraint>::New(env, new TableConstraint(ct));
        return GTableConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddForbiddenAssignments : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// Constraint AddInverseConstraint(absl::Span<const IntVar> variables, absl::Span<const IntVar> inverse_variables);
Napi::Value GCpModelBuilder::AddInverseConstraint(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 2 && info[0].IsArray() && info[1].IsArray())
    {
        Napi::Array variables         = info[0].As<Napi::Array>();
        Napi::Array inverse_variables = info[1].As<Napi::Array>();
        std::vector<IntVar> vec1;
        std::vector<IntVar> vec2;
        for (uint32_t i = 0; i < variables.Length(); i++)
        {
            auto var = variables.Get(i);
            if (var.IsObject() && var.As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()))
            {
                auto pVar = GIntVar::Unwrap(var.As<Napi::Object>())->pIntVar;
                vec1.push_back(*pVar);
                continue;
            }

            Napi::TypeError::New(env, "GCpModelBuilder::AddInverseConstraint : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        for (uint32_t i = 0; i < inverse_variables.Length(); i++)
        {
            auto var = inverse_variables.Get(i);
            if (var.IsObject() && var.As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()))
            {
                auto pVar = GIntVar::Unwrap(var.As<Napi::Object>())->pIntVar;
                vec2.push_back(*pVar);
                continue;
            }

            Napi::TypeError::New(env, "GCpModelBuilder::AddInverseConstraint : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        Constraint ct = pCpModelBuilder->AddInverseConstraint(vec1, vec2);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddInverseConstraint : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// ReservoirConstraint AddReservoirConstraint(int64_t min_level, int64_t max_level);
Napi::Value GCpModelBuilder::AddReservoirConstraint(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 2 && info[0].IsNumber() && info[1].IsNumber())
    {
        int64_t min_level      = info[0].As<Napi::Number>().Int64Value();
        int64_t max_level      = info[1].As<Napi::Number>().Int64Value();
        ReservoirConstraint ct = pCpModelBuilder->AddReservoirConstraint(min_level, max_level);
        auto external          = Napi::External<ReservoirConstraint>::New(env, new ReservoirConstraint(ct));
        return GReservoirConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddReservoirConstraint : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// AutomatonConstraint AddAutomaton(absl::Span<const IntVar> transition_variables, int starting_state, absl::Span<const int> final_states);
Napi::Value GCpModelBuilder::AddAutomaton(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 3 && info[0].IsArray() && info[1].IsNumber() && info[2].IsArray())
    {
        Napi::Array transition_variables = info[0].As<Napi::Array>();
        int starting_state               = info[1].As<Napi::Number>().Int32Value();
        Napi::Array final_states         = info[2].As<Napi::Array>();
        std::vector<IntVar> vec1;
        for (uint32_t i = 0; i < transition_variables.Length(); i++)
        {
            auto var = transition_variables.Get(i);
            if (var.IsObject() && var.As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()))
            {
                auto pVar = GIntVar::Unwrap(var.As<Napi::Object>())->pIntVar;
                vec1.push_back(*pVar);
                continue;
            }

            Napi::TypeError::New(env, "GCpModelBuilder::AddAutomaton : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        std::vector<int> vec2;
        for (uint32_t i = 0; i < final_states.Length(); i++)
        {
            auto value = final_states.Get(i);
            if (value.IsNumber())
            {
                vec2.push_back(value.As<Napi::Number>().Int32Value());
                continue;
            }

            Napi::TypeError::New(env, "GCpModelBuilder::AddAutomaton : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        AutomatonConstraint ct = pCpModelBuilder->AddAutomaton(vec1, starting_state, vec2);
        auto external          = Napi::External<AutomatonConstraint>::New(env, new AutomatonConstraint(ct));
        return GAutomatonConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddAutomaton : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// Constraint AddMinEquality(const LinearExpr &target, absl::Span<const IntVar> vars);
// Constraint AddMinEquality(const LinearExpr &target, absl::Span<const LinearExpr> exprs);
// Constraint AddMinEquality(const LinearExpr &target, std::initializer_list<LinearExpr> exprs);
Napi::Value GCpModelBuilder::AddMinEquality(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 2 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GLinearExpr::constructor.Value()) && info[1].IsArray())
    {
        auto target      = GLinearExpr::Unwrap(info[0].As<Napi::Object>())->pLinearExpr;
        Napi::Array vars = info[1].As<Napi::Array>();
        std::vector<LinearExpr> vec;
        for (uint32_t i = 0; i < vars.Length(); i++)
        {
            auto var = vars.Get(i);
            LinearExpr linearExpr;
            if (GLinearExpr::ToLinearExpr(var, linearExpr))
            {
                vec.push_back(linearExpr);
                continue;
            }

            Napi::TypeError::New(env, "GCpModelBuilder::AddMinEquality : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        Constraint ct = pCpModelBuilder->AddMinEquality(*target, vec);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddMinEquality : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// Constraint AddMaxEquality(const LinearExpr &target, absl::Span<const IntVar> vars);
// Constraint AddMaxEquality(const LinearExpr &target, absl::Span<const LinearExpr> exprs);
// Constraint AddMaxEquality(const LinearExpr &target, std::initializer_list<LinearExpr> exprs);
Napi::Value GCpModelBuilder::AddMaxEquality(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 2 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GLinearExpr::constructor.Value()) && info[1].IsArray())
    {
        auto target      = GLinearExpr::Unwrap(info[0].As<Napi::Object>())->pLinearExpr;
        Napi::Array vars = info[1].As<Napi::Array>();
        std::vector<LinearExpr> vec;
        for (uint32_t i = 0; i < vars.Length(); i++)
        {
            auto var = vars.Get(i);
            LinearExpr linearExpr;
            if (GLinearExpr::ToLinearExpr(var, linearExpr))
            {
                vec.push_back(linearExpr);
                continue;
            }

            Napi::TypeError::New(env, "GCpModelBuilder::AddMaxEquality : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        Constraint ct = pCpModelBuilder->AddMaxEquality(*target, vec);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddMaxEquality : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// Constraint AddDivisionEquality(const LinearExpr &target, const LinearExpr &numerator, const LinearExpr &denominator);
Napi::Value GCpModelBuilder::AddDivisionEquality(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr target, numerator, denominator;
    if (info.Length() == 3 && GLinearExpr::ToLinearExpr(info[0], target) && GLinearExpr::ToLinearExpr(info[1], numerator) && GLinearExpr::ToLinearExpr(info[2], denominator))
    {
        Constraint ct = pCpModelBuilder->AddDivisionEquality(target, numerator, denominator);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddDivisionEquality : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// Constraint AddAbsEquality(const LinearExpr &target, const LinearExpr &expr);
Napi::Value GCpModelBuilder::AddAbsEquality(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr target, expr;
    if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], target) && GLinearExpr::ToLinearExpr(info[1], expr))
    {
        Constraint ct = pCpModelBuilder->AddAbsEquality(target, expr);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddAbsEquality : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// Constraint AddModuloEquality(const LinearExpr &target, const LinearExpr &var, const LinearExpr &mod);
Napi::Value GCpModelBuilder::AddModuloEquality(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr target, var, mod;
    if (info.Length() == 3 && GLinearExpr::ToLinearExpr(info[0], target) && GLinearExpr::ToLinearExpr(info[1], var) && GLinearExpr::ToLinearExpr(info[2], mod))
    {
        Constraint ct = pCpModelBuilder->AddModuloEquality(target, var, mod);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddModuloEquality : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
Napi::Value GCpModelBuilder::AddMultiplicationEquality(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    // Constraint AddMultiplicationEquality(const LinearExpr &target, absl::Span<const LinearExpr> exprs);
    // Constraint AddMultiplicationEquality(const LinearExpr &target, absl::Span<const IntVar> vars);
    // Constraint AddMultiplicationEquality(const LinearExpr &target, std::initializer_list<LinearExpr> exprs);
    LinearExpr target;
    if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], target) && info[1].IsArray())
    {
        Napi::Array exprs = info[1].As<Napi::Array>();
        std::vector<LinearExpr> vec;
        for (uint32_t i = 0; i < exprs.Length(); i++)
        {
            auto var = exprs.Get(i);
            LinearExpr linearExpr;
            if (GLinearExpr::ToLinearExpr(var, linearExpr))
            {
                vec.push_back(linearExpr);
                continue;
            }
            Napi::TypeError::New(env, "GCpModelBuilder::AddMultiplicationEquality : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        Constraint ct = pCpModelBuilder->AddMultiplicationEquality(target, vec);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    // Constraint AddMultiplicationEquality(const LinearExpr &target, const LinearExpr &left, const LinearExpr &right);

    Napi::TypeError::New(env, "GCpModelBuilder::AddMultiplicationEquality : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// Constraint AddNoOverlap(absl::Span<const IntervalVar> vars);
Napi::Value GCpModelBuilder::AddNoOverlap(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsArray())
    {
        Napi::Array vars = info[0].As<Napi::Array>();
        std::vector<IntervalVar> vec;
        for (uint32_t i = 0; i < vars.Length(); i++)
        {
            auto var = vars.Get(i);
            if (var.IsObject() && var.As<Napi::Object>().InstanceOf(GIntervalVar::constructor.Value()))
            {
                auto pVar = GIntervalVar::Unwrap(var.As<Napi::Object>())->pIntervalVar;
                vec.push_back(*pVar);
                continue;
            }

            Napi::TypeError::New(env, "GCpModelBuilder::AddNoOverlap : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        Constraint ct = pCpModelBuilder->AddNoOverlap(vec);
        auto external = Napi::External<Constraint>::New(env, new Constraint(ct));
        return GConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddNoOverlap : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// NoOverlap2DConstraint AddNoOverlap2D();
Napi::Value GCpModelBuilder::AddNoOverlap2D(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        NoOverlap2DConstraint ct = pCpModelBuilder->AddNoOverlap2D();
        auto external            = Napi::External<NoOverlap2DConstraint>::New(env, new NoOverlap2DConstraint(ct));
        return GNoOverlap2DConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddNoOverlap2D : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// CumulativeConstraint AddCumulative(LinearExpr capacity);
Napi::Value GCpModelBuilder::AddCumulative(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GLinearExpr::constructor.Value()))
    {
        auto capacity           = GLinearExpr::Unwrap(info[0].As<Napi::Object>())->pLinearExpr;
        CumulativeConstraint ct = pCpModelBuilder->AddCumulative(*capacity);
        auto external           = Napi::External<CumulativeConstraint>::New(env, new CumulativeConstraint(ct));
        return GCumulativeConstraint::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddCumulative : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

Napi::Value GCpModelBuilder::Minimize(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    // void Minimize(const LinearExpr &expr);
    LinearExpr expr;
    if (info.Length() == 1 && GLinearExpr::ToLinearExpr(info[0], expr))
    {
        pCpModelBuilder->Minimize(expr);
        return env.Undefined();
    }

    // void Minimize(const DoubleLinearExpr &expr);

    Napi::TypeError::New(env, "GCpModelBuilder::Minimize : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

Napi::Value GCpModelBuilder::Maximize(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    // void Maximize(const LinearExpr &expr);
    LinearExpr expr;
    if (info.Length() == 1 && GLinearExpr::ToLinearExpr(info[0], expr))
    {
        pCpModelBuilder->Maximize(expr);
        return env.Undefined();
    }

    // void Maximize(const DoubleLinearExpr &expr);

    Napi::TypeError::New(env, "GCpModelBuilder::Maximize : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void ClearObjective();
Napi::Value GCpModelBuilder::ClearObjective(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        pCpModelBuilder->ClearObjective();
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GCpModelBuilder::ClearObjective : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// bool HasObjective() const;
Napi::Value GCpModelBuilder::HasObjective(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        return Napi::Boolean::New(env, pCpModelBuilder->HasObjective());
    }

    Napi::TypeError::New(env, "GCpModelBuilder::HasObjective : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void AddDecisionStrategy(absl::Span<const IntVar> variables, DecisionStrategyProto::VariableSelectionStrategy var_strategy, DecisionStrategyProto::DomainReductionStrategy domain_strategy);
// void AddDecisionStrategy(absl::Span<const BoolVar> variables, DecisionStrategyProto::VariableSelectionStrategy var_strategy, DecisionStrategyProto::DomainReductionStrategy domain_strategy);
// void AddDecisionStrategy(absl::Span<const LinearExpr> expressions, DecisionStrategyProto::VariableSelectionStrategy var_strategy, DecisionStrategyProto::DomainReductionStrategy domain_strategy);
// void AddDecisionStrategy(std::initializer_list<LinearExpr> expressions, DecisionStrategyProto::VariableSelectionStrategy var_strategy, DecisionStrategyProto::DomainReductionStrategy domain_strategy);
Napi::Value GCpModelBuilder::AddDecisionStrategy(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 3 && info[0].IsArray() && info[1].IsNumber() && info[2].IsNumber())
    {
        Napi::Array variables                                          = info[0].As<Napi::Array>();
        DecisionStrategyProto::VariableSelectionStrategy var_strategy  = static_cast<DecisionStrategyProto::VariableSelectionStrategy>(info[1].As<Napi::Number>().Int32Value());
        DecisionStrategyProto::DomainReductionStrategy domain_strategy = static_cast<DecisionStrategyProto::DomainReductionStrategy>(info[2].As<Napi::Number>().Int32Value());
        std::vector<LinearExpr> vec;
        for (uint32_t i = 0; i < variables.Length(); i++)
        {
            auto var = variables.Get(i);
            LinearExpr linearExpr;
            if (GLinearExpr::ToLinearExpr(var, linearExpr))
            {
                vec.push_back(linearExpr);
                continue;
            }
            Napi::TypeError::New(env, "GCpModelBuilder::AddDecisionStrategy : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        pCpModelBuilder->AddDecisionStrategy(vec, var_strategy, domain_strategy);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddDecisionStrategy : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

Napi::Value GCpModelBuilder::AddHint(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    // void AddHint(IntVar var, int64_t value);
    if (info.Length() == 2 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()) && info[1].IsNumber())
    {
        auto var      = GIntVar::Unwrap(info[0].As<Napi::Object>())->pIntVar;
        int64_t value = info[1].As<Napi::Number>().Int64Value();
        pCpModelBuilder->AddHint(*var, value);
        return env.Undefined();
    }

    // void AddHint(BoolVar var, bool value);
    if (info.Length() == 2 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()) && info[1].IsBoolean())
    {
        auto var   = GBoolVar::Unwrap(info[0].As<Napi::Object>())->pBoolVar;
        bool value = info[1].As<Napi::Boolean>().Value();
        pCpModelBuilder->AddHint(*var, value);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddHint : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// void ClearHints();
Napi::Value GCpModelBuilder::ClearHints(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        pCpModelBuilder->ClearHints();
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GCpModelBuilder::ClearHints : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void AddAssumption(BoolVar lit);
Napi::Value GCpModelBuilder::AddAssumption(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
    {
        auto lit = GBoolVar::Unwrap(info[0].As<Napi::Object>())->pBoolVar;
        pCpModelBuilder->AddAssumption(*lit);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddAssumption : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void AddAssumptions(absl::Span<const BoolVar> literals);
Napi::Value GCpModelBuilder::AddAssumptions(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsArray())
    {
        Napi::Array literals = info[0].As<Napi::Array>();
        std::vector<BoolVar> vec;
        for (uint32_t i = 0; i < literals.Length(); i++)
        {
            auto lit = literals.Get(i);
            if (lit.IsObject() && lit.As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
            {
                auto pLit = GBoolVar::Unwrap(lit.As<Napi::Object>())->pBoolVar;
                vec.push_back(*pLit);
                continue;
            }
            Napi::TypeError::New(env, "GCpModelBuilder::AddAssumptions : Invalid arguments").ThrowAsJavaScriptException();
            return env.Null();
        }
        pCpModelBuilder->AddAssumptions(vec);
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GCpModelBuilder::AddAssumptions : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// void ClearAssumptions();
Napi::Value GCpModelBuilder::ClearAssumptions(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        pCpModelBuilder->ClearAssumptions();
        return env.Undefined();
    }

    Napi::TypeError::New(env, "GCpModelBuilder::ClearAssumptions : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// const CpModelProto &Build() const;
Napi::Value GCpModelBuilder::Build(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        auto &proto   = pCpModelBuilder->Build();
        auto external = Napi::External<CpModelProto>::New(env, new CpModelProto(proto));
        return GCpModelProto::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::Build : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// const CpModelProto &Proto() const;
Napi::Value GCpModelBuilder::Proto(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        auto &proto   = pCpModelBuilder->Proto();
        // TODO CpModelProto is not copyable and should not be wrapped in an external
        auto external = Napi::External<CpModelProto>::New(env, new CpModelProto(proto));
        return GCpModelProto::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::Proto : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// CpModelProto *MutableProto();
Napi::Value GCpModelBuilder::MutableProto(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        auto proto    = pCpModelBuilder->MutableProto();
        auto external = Napi::External<CpModelProto>::New(env, proto);
        return GCpModelProto::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::MutableProto : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// bool ExportToFile(absl::string_view filename) const;
Napi::Value GCpModelBuilder::ExportToFile(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsString())
    {
        std::string filename = info[0].As<Napi::String>().Utf8Value();
        bool success         = pCpModelBuilder->ExportToFile(filename);
        return Napi::Boolean::New(env, success);
    }

    Napi::TypeError::New(env, "GCpModelBuilder::ExportToFile : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// CpModelBuilder Clone() const;
Napi::Value GCpModelBuilder::Clone(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        auto builder  = pCpModelBuilder->Clone();
        auto external = Napi::External<CpModelBuilder>::New(env, new CpModelBuilder(builder));
        return GCpModelBuilder::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::Clone : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// BoolVar GetBoolVarFromProtoIndex(int index);
Napi::Value GCpModelBuilder::GetBoolVarFromProtoIndex(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        int index     = info[0].As<Napi::Number>().Int32Value();
        auto var      = pCpModelBuilder->GetBoolVarFromProtoIndex(index);
        auto external = Napi::External<BoolVar>::New(env, new BoolVar(var));
        return GBoolVar::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::GetBoolVarFromProtoIndex : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// IntVar GetIntVarFromProtoIndex(int index);
Napi::Value GCpModelBuilder::GetIntVarFromProtoIndex(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        int index     = info[0].As<Napi::Number>().Int32Value();
        auto var      = pCpModelBuilder->GetIntVarFromProtoIndex(index);
        auto external = Napi::External<IntVar>::New(env, new IntVar(var));
        return GIntVar::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::GetIntVarFromProtoIndex : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// IntervalVar GetIntervalVarFromProtoIndex(int index);
Napi::Value GCpModelBuilder::GetIntervalVarFromProtoIndex(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsNumber())
    {
        int index     = info[0].As<Napi::Number>().Int32Value();
        auto var      = pCpModelBuilder->GetIntervalVarFromProtoIndex(index);
        auto external = Napi::External<IntervalVar>::New(env, new IntervalVar(var));
        return GIntervalVar::constructor.New({external});
    }

    Napi::TypeError::New(env, "GCpModelBuilder::GetIntervalVarFromProtoIndex : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

bool GLinearExpr::ToLinearExpr(const Napi::Value &value, LinearExpr &expr)
{
    if (value.IsObject() && value.As<Napi::Object>().InstanceOf(GLinearExpr::constructor.Value()))
        expr = *GLinearExpr::Unwrap(value.As<Napi::Object>())->pLinearExpr;
    else if (value.IsNumber())
        expr = value.As<Napi::Number>().DoubleValue();
    else if (value.IsObject() && value.As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
        expr = *GBoolVar::Unwrap(value.As<Napi::Object>())->pBoolVar;
    else if (value.IsObject() && value.As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()))
        expr = *GIntVar::Unwrap(value.As<Napi::Object>())->pIntVar;
    else
        return false;

    return true;
}

GIntVar::GIntVar(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GIntVar>(info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external = info[0].As<Napi::External<IntVar>>();
        pIntVar       = dynamic_cast<IntVar *>(external.Data());
        if (pIntVar) return;
    }

    // IntVar() = default;
    if (info.Length() == 0)
    {
        pIntVar = new IntVar();
        return;
    }

    // explicit IntVar(const BoolVar &var);
    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
    {
        auto var = GBoolVar::Unwrap(info[0].As<Napi::Object>())->pBoolVar;
        pIntVar  = new IntVar(*var);
        return;
    }

    Napi::TypeError::New(env, "GIntVar::GIntVar : Invalid arguments").ThrowAsJavaScriptException();
}

GIntVar::~GIntVar()
{
    if (pIntVar) delete pIntVar;
}

Napi::Object GIntVar::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "IntVar",
        {
            InstanceMethod("ToBoolVar", &GIntVar::ToBoolVar),
            InstanceMethod("WithName", &GIntVar::WithName),
            InstanceMethod("Name", &GIntVar::Name),
            InstanceMethod("Domain", &GIntVar::Domain),
            InstanceMethod("DebugString", &GIntVar::DebugString),
            InstanceMethod("index", &GIntVar::index),
            InstanceMethod("operator_eq", &GIntVar::operator_eq),
            InstanceMethod("operator_nq", &GIntVar::operator_nq),
        }
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("IntVar", func);
    return exports;
}

// BoolVar ToBoolVar() const;
Napi::Value GIntVar::ToBoolVar(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        auto var      = pIntVar->ToBoolVar();
        auto external = Napi::External<BoolVar>::New(env, new BoolVar(var));
        return GBoolVar::constructor.New({external});
    }

    Napi::TypeError::New(env, "GIntVar::ToBoolVar : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// IntVar WithName(absl::string_view name);
Napi::Value GIntVar::WithName(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsString())
    {
        std::string name = info[0].As<Napi::String>().Utf8Value();
        auto var         = pIntVar->WithName(name);
        auto external    = Napi::External<IntVar>::New(env, new IntVar(var));
        return GIntVar::constructor.New({external});
    }

    Napi::TypeError::New(env, "GIntVar::WithName : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// std::string Name() const;
Napi::Value GIntVar::Name(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        std::string name = pIntVar->Name();
        return Napi::String::New(env, name);
    }

    Napi::TypeError::New(env, "GIntVar::Name : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// bool operator==(const IntVar &other) const;
Napi::Value GIntVar::operator_eq(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()))
    {
        auto other = GIntVar::Unwrap(info[0].As<Napi::Object>())->pIntVar;
        return Napi::Boolean::New(env, *pIntVar == *other);
    }

    Napi::TypeError::New(env, "GIntVar::operator_eq : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// bool operator!=(const IntVar &other) const;
Napi::Value GIntVar::operator_nq(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()))
    {
        auto other = GIntVar::Unwrap(info[0].As<Napi::Object>())->pIntVar;
        return Napi::Boolean::New(env, *pIntVar != *other);
    }

    Napi::TypeError::New(env, "GIntVar::operator_nq : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
//::operations_research::Domain Domain() const;
Napi::Value GIntVar::Domain(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        auto domain   = pIntVar->Domain();
        auto external = Napi::External<operations_research::Domain>::New(env, new operations_research::Domain(domain));
        return GDomain::constructor.New({external});
    }

    Napi::TypeError::New(env, "GIntVar::Domain : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// std::string DebugString() const;
Napi::Value GIntVar::DebugString(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        std::string debugString = pIntVar->DebugString();
        return Napi::String::New(env, debugString);
    }

    Napi::TypeError::New(env, "GIntVar::DebugString : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// int index() const;
Napi::Value GIntVar::index(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        int index = pIntVar->index();
        return Napi::Number::New(env, index);
    }

    Napi::TypeError::New(env, "GIntVar::index : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

GIntervalVar::GIntervalVar(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GIntervalVar>(info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external = info[0].As<Napi::External<IntervalVar>>();
        pIntervalVar  = dynamic_cast<IntervalVar *>(external.Data());
        if (pIntervalVar) return;
    }

    Napi::TypeError::New(env, "GIntervalVar::GIntervalVar : Invalid arguments").ThrowAsJavaScriptException();
}

GIntervalVar::~GIntervalVar()
{
    if (pIntervalVar) delete pIntervalVar;
}

Napi::Object GIntervalVar::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "IntervalVar",
        {}
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("IntervalVar", func);
    return exports;
}

GCpModelProto::GCpModelProto(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GCpModelProto>(info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external = info[0].As<Napi::External<CpModelProto>>();
        pCpModelProto = dynamic_cast<CpModelProto *>(external.Data());
        if (pCpModelProto) return;
    }

    Napi::TypeError::New(env, "GCpModelProto::GCpModelProto : Invalid arguments").ThrowAsJavaScriptException();
}

GCpModelProto::~GCpModelProto()
{
    if (pCpModelProto) delete pCpModelProto;
}
Napi::Object GCpModelProto::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "CpModelProto",
        {}
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("CpModelProto", func);
    return exports;
}

GBoolVar::GBoolVar(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GBoolVar>(info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external = info[0].As<Napi::External<BoolVar>>();
        pBoolVar      = dynamic_cast<BoolVar *>(external.Data());
        if (pBoolVar) return;
    }

    Napi::TypeError::New(env, "GBoolVar::GBoolVar : Invalid arguments").ThrowAsJavaScriptException();
}

GBoolVar::~GBoolVar()
{
    if (pBoolVar) delete pBoolVar;
}
Napi::Object GBoolVar::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "BoolVar",
        {}
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("BoolVar", func);
    return exports;
}

GConstraint::GConstraint(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GConstraint>(info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external = info[0].As<Napi::External<Constraint>>();
        pConstraint   = dynamic_cast<Constraint *>(external.Data());
        if (pConstraint) return;
    }

    Napi::TypeError::New(env, "GConstraint::GConstraint : Invalid arguments").ThrowAsJavaScriptException();
}

GConstraint::~GConstraint()
{
    if (pConstraint) delete pConstraint;
}
Napi::Object GConstraint::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "Constraint",
        {}
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("Constraint", func);
    return exports;
}

GLinearExpr::GLinearExpr(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GLinearExpr>(info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external = info[0].As<Napi::External<LinearExpr>>();
        pLinearExpr   = dynamic_cast<LinearExpr *>(external.Data());
        if (pLinearExpr) return;
    }

    if (info.Length() ==0)
    {
        pLinearExpr = new LinearExpr();
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
        {}
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("LinearExpr", func);
    return exports;
}

GCpSolverResponse::GCpSolverResponse(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GCpSolverResponse>(info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external     = info[0].As<Napi::External<CpSolverResponse>>();
        pCpSolverResponse = dynamic_cast<CpSolverResponse *>(external.Data());
        if (pCpSolverResponse) return;
    }

    Napi::TypeError::New(env, "GCpSolverResponse::GCpSolverResponse : Invalid arguments").ThrowAsJavaScriptException();
}

GCpSolverResponse::~GCpSolverResponse()
{
    if (pCpSolverResponse) delete pCpSolverResponse;
}

Napi::Object GCpSolverResponse::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "CpSolverResponse",
        {
            InstanceMethod("status", &GCpSolverResponse::status),
            InstanceMethod("objective_value", &GCpSolverResponse::objective_value),
        }
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("CpSolverResponse", func);
    return exports;
}

// double objective_value() const
Napi::Value GCpSolverResponse::objective_value(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        double objective_value = pCpSolverResponse->objective_value();
        return Napi::Number::New(env, objective_value);
    }

    Napi::TypeError::New(env, "GCpSolverResponse::objective_value : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// CpSolverStatus  status()
Napi::Value GCpSolverResponse::status(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 0)
    {
        auto status = pCpSolverResponse->status();
        return Napi::Number::New(env, status);
    }

    Napi::TypeError::New(env, "GCpSolverResponse::status : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

GCircuitConstraint::GCircuitConstraint(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GCircuitConstraint>(info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external      = info[0].As<Napi::External<CircuitConstraint>>();
        pCircuitConstraint = dynamic_cast<CircuitConstraint *>(external.Data());
        if (pCircuitConstraint) return;
    }

    Napi::TypeError::New(env, "GCircuitConstraint::GCircuitConstraint : Invalid arguments").ThrowAsJavaScriptException();
}

GCircuitConstraint::~GCircuitConstraint()
{
    if (pCircuitConstraint) delete pCircuitConstraint;
}

Napi::Object GCircuitConstraint::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "CircuitConstraint",
        {}
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("CircuitConstraint", func);
    return exports;
}

GMultipleCircuitConstraint::GMultipleCircuitConstraint(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GMultipleCircuitConstraint>(info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external              = info[0].As<Napi::External<MultipleCircuitConstraint>>();
        pMultipleCircuitConstraint = dynamic_cast<MultipleCircuitConstraint *>(external.Data());
        if (pMultipleCircuitConstraint) return;
    }

    Napi::TypeError::New(env, "GMultipleCircuitConstraint::GMultipleCircuitConstraint : Invalid arguments").ThrowAsJavaScriptException();
}

GMultipleCircuitConstraint::~GMultipleCircuitConstraint()
{
    if (pMultipleCircuitConstraint) delete pMultipleCircuitConstraint;
}

Napi::Object GMultipleCircuitConstraint::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "MultipleCircuitConstraint",
        {}
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("MultipleCircuitConstraint", func);
    return exports;
}

GTableConstraint::GTableConstraint(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GTableConstraint>(info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external    = info[0].As<Napi::External<TableConstraint>>();
        pTableConstraint = dynamic_cast<TableConstraint *>(external.Data());
        if (pTableConstraint) return;
    }

    Napi::TypeError::New(env, "GTableConstraint::GTableConstraint : Invalid arguments").ThrowAsJavaScriptException();
}

GTableConstraint::~GTableConstraint()
{
    if (pTableConstraint) delete pTableConstraint;
}

Napi::Object GTableConstraint::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "TableConstraint",
        {}
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("TableConstraint", func);
    return exports;
}

GAutomatonConstraint::GAutomatonConstraint(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GAutomatonConstraint>(info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external        = info[0].As<Napi::External<AutomatonConstraint>>();
        pAutomatonConstraint = dynamic_cast<AutomatonConstraint *>(external.Data());
        if (pAutomatonConstraint) return;
    }

    Napi::TypeError::New(env, "GAutomatonConstraint::GAutomatonConstraint : Invalid arguments").ThrowAsJavaScriptException();
}

GAutomatonConstraint::~GAutomatonConstraint()
{
    if (pAutomatonConstraint) delete pAutomatonConstraint;
}

Napi::Object GAutomatonConstraint::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "AutomatonConstraint",
        {}
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("AutomatonConstraint", func);
    return exports;
}

GNoOverlap2DConstraint::GNoOverlap2DConstraint(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GNoOverlap2DConstraint>(info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external          = info[0].As<Napi::External<NoOverlap2DConstraint>>();
        pNoOverlap2DConstraint = dynamic_cast<NoOverlap2DConstraint *>(external.Data());
        if (pNoOverlap2DConstraint) return;
    }

    Napi::TypeError::New(env, "GNoOverlap2DConstraint::GNoOverlap2DConstraint : Invalid arguments").ThrowAsJavaScriptException();
}
GNoOverlap2DConstraint::~GNoOverlap2DConstraint()
{
    if (pNoOverlap2DConstraint) delete pNoOverlap2DConstraint;
}

Napi::Object GNoOverlap2DConstraint::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "NoOverlap2DConstraint",
        {}
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("NoOverlap2DConstraint", func);
    return exports;
}

GCumulativeConstraint::GCumulativeConstraint(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GCumulativeConstraint>(info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external         = info[0].As<Napi::External<CumulativeConstraint>>();
        pCumulativeConstraint = dynamic_cast<CumulativeConstraint *>(external.Data());
        if (pCumulativeConstraint) return;
    }

    Napi::TypeError::New(env, "GCumulativeConstraint::GCumulativeConstraint : Invalid arguments").ThrowAsJavaScriptException();
}

GCumulativeConstraint::~GCumulativeConstraint()
{
    if (pCumulativeConstraint) delete pCumulativeConstraint;
}

Napi::Object GCumulativeConstraint::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "CumulativeConstraint",
        {}
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("CumulativeConstraint", func);
    return exports;
}

GReservoirConstraint::GReservoirConstraint(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<GReservoirConstraint>(info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsExternal())
    {
        auto external        = info[0].As<Napi::External<ReservoirConstraint>>();
        pReservoirConstraint = dynamic_cast<ReservoirConstraint *>(external.Data());
        if (pReservoirConstraint) return;
    }

    Napi::TypeError::New(env, "GReservoirConstraint::GReservoirConstraint : Invalid arguments").ThrowAsJavaScriptException();
}

GReservoirConstraint::~GReservoirConstraint()
{
    if (pReservoirConstraint) delete pReservoirConstraint;
}
Napi::Object GReservoirConstraint::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function func = DefineClass(
        env,
        "ReservoirConstraint",
        {}
    );
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct();
    exports.Set("ReservoirConstraint", func);
    return exports;
}

} // namespace sat
} // namespace operations_research