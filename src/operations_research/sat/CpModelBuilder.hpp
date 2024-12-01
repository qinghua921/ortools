#pragma once

#include "./BoolVar.hpp"
#include "./Constraint.hpp"
#include "./CpModelProto.hpp"
#include "./CumulativeConstraint.hpp"
#include "./IntVar.hpp"
#include "./LinearExpr.hpp"
#include "./NoOverlap2DConstraint.hpp"
#include "./TableConstraint.hpp"
#include "napi.h"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
class GCpModelBuilder : public Napi::ObjectWrap<GCpModelBuilder>
{
  public:
    static inline Napi::FunctionReference constructor;
    CpModelBuilder *pCpModelBuilder = nullptr;

    GCpModelBuilder(const Napi::CallbackInfo &info)
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

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::GCpModelBuilder : Invalid arguments").ThrowAsJavaScriptException();
    };

    ~GCpModelBuilder()
    {
        if (pCpModelBuilder) delete pCpModelBuilder;
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);
        Napi::Function func = DefineClass(
            env,
            "CpModelBuilder",
            {
                InstanceMethod("AddEquality", &GCpModelBuilder::AddEquality),
                InstanceMethod("AddExactlyOne", &GCpModelBuilder::AddExactlyOne),
                InstanceMethod("AddAtMostOne", &GCpModelBuilder::AddAtMostOne),
                InstanceMethod("NewBoolVar", &GCpModelBuilder::NewBoolVar),
                InstanceMethod("AddAllowedAssignments", &GCpModelBuilder::AddAllowedAssignments),
                InstanceMethod("Minimize", &GCpModelBuilder::Minimize),
                InstanceMethod("Build", &GCpModelBuilder::Build),
                InstanceMethod("AddLessOrEqual", &GCpModelBuilder::AddLessOrEqual),
                InstanceMethod("AddGreaterThan", &GCpModelBuilder::AddGreaterThan),
                InstanceMethod("NewIntVar", &GCpModelBuilder::NewIntVar),
                InstanceMethod("AddAssumptions", &GCpModelBuilder::AddAssumptions),
                InstanceMethod("Maximize", &GCpModelBuilder::Maximize),
                InstanceMethod("SetName", &GCpModelBuilder::SetName),
                InstanceMethod("FixVariable", &GCpModelBuilder::FixVariable),
                InstanceMethod("NewOptionalFixedSizeIntervalVar", &GCpModelBuilder::NewOptionalFixedSizeIntervalVar),
                InstanceMethod("NewFixedSizeIntervalVar", &GCpModelBuilder::NewFixedSizeIntervalVar),
                InstanceMethod("AddImplication", &GCpModelBuilder::AddImplication),
                InstanceMethod("AddBoolOr", &GCpModelBuilder::AddBoolOr),
                InstanceMethod("AddGreaterOrEqual", &GCpModelBuilder::AddGreaterOrEqual),
                InstanceMethod("AddLessThan", &GCpModelBuilder::AddLessThan),
                InstanceMethod("AddDecisionStrategy", &GCpModelBuilder::AddDecisionStrategy),
                InstanceMethod("AddNotEqual", &GCpModelBuilder::AddNotEqual),
                InstanceMethod("Clone", &GCpModelBuilder::Clone),
                InstanceMethod("GetIntVarFromProtoIndex", &GCpModelBuilder::GetIntVarFromProtoIndex),
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "CpModelBuilder"), func);
        return exports;
    };
    //     IntVar GetIntVarFromProtoIndex(int index);
    Napi::Value GetIntVarFromProtoIndex(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsNumber())
        {
            int index   = info[0].As<Napi::Number>().Int32Value();
            auto result = pCpModelBuilder->GetIntVarFromProtoIndex(index);
            return GIntVar::constructor.New({Napi::External<IntVar>::New(env, new IntVar(result))});
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::GetIntVarFromProtoIndex : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    }
    //     CpModelBuilder Clone() const;
    Napi::Value Clone(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            auto result = pCpModelBuilder->Clone();
            return GCpModelBuilder::constructor.New({Napi::External<CpModelBuilder>::New(env, new CpModelBuilder(result))});
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::Clone : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    //     Constraint AddNotEqual(const LinearExpr &left, const LinearExpr &right);
    Napi::Value AddNotEqual(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        LinearExpr left, right;
        if (info.Length() == 2 &&
            GLinearExpr::ToLinearExpr(info[0], left)     //
            && GLinearExpr::ToLinearExpr(info[1], right) //
        )
        {
            auto result = pCpModelBuilder->AddNotEqual(left, right);
            return GConstraint::constructor.New({Napi::External<Constraint>::New(env, new Constraint(result))});
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::AddNotEqual : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    //     void AddDecisionStrategy(
    //         absl::Span<const IntVar> variables,
    //         DecisionStrategyProto::VariableSelectionStrategy var_strategy,
    //         DecisionStrategyProto::DomainReductionStrategy domain_strategy
    //     );
    Napi::Value AddDecisionStrategy(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 3 && info[0].IsArray() && info[1].IsNumber() && info[2].IsNumber())
        {
            std::vector<IntVar> variables;
            auto array = info[0].As<Napi::Array>();
            for (int i = 0; i < array.Length(); i++)
            {
                if (array.Get(i).IsObject() && array.Get(i).As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()))
                {
                    variables.push_back(*Napi::ObjectWrap<GIntVar>::Unwrap(array.Get(i).As<Napi::Object>())->pIntVar);
                    continue;
                }
                Napi::TypeError::New(env, "operations_research::GCpModelBuilder::AddDecisionStrategy : Invalid arguments").ThrowAsJavaScriptException();
                return env.Null();
            }
            auto var_strategy    = static_cast<DecisionStrategyProto::VariableSelectionStrategy>(info[1].As<Napi::Number>().Int32Value());
            auto domain_strategy = static_cast<DecisionStrategyProto::DomainReductionStrategy>(info[2].As<Napi::Number>().Int32Value());
            pCpModelBuilder->AddDecisionStrategy(variables, var_strategy, domain_strategy);
            return env.Null();
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::AddDecisionStrategy : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    //     Constraint AddLessThan(const LinearExpr &left, const LinearExpr &right);
    Napi::Value AddLessThan(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        LinearExpr left, right;
        if (info.Length() == 2 &&
            GLinearExpr::ToLinearExpr(info[0], left)     //
            && GLinearExpr::ToLinearExpr(info[1], right) //
        )
        {
            auto result = pCpModelBuilder->AddLessThan(left, right);
            return GConstraint::constructor.New({Napi::External<Constraint>::New(env, new Constraint(result))});
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::AddLessThan : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    //     Constraint AddGreaterOrEqual(const LinearExpr &left, const LinearExpr &right);
    Napi::Value AddGreaterOrEqual(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        LinearExpr left, right;
        if (info.Length() == 2 &&
            GLinearExpr::ToLinearExpr(info[0], left)     //
            && GLinearExpr::ToLinearExpr(info[1], right) //
        )
        {
            auto result = pCpModelBuilder->AddGreaterOrEqual(left, right);
            return GConstraint::constructor.New({Napi::External<Constraint>::New(env, new Constraint(result))});
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::AddGreaterOrEqual : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    //     Constraint AddBoolOr(absl::Span<const BoolVar> literals);
    Napi::Value AddBoolOr(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsArray())
        {
            std::vector<BoolVar> literals;
            auto array = info[0].As<Napi::Array>();
            for (int i = 0; i < array.As<Napi::Array>().Length(); i++)
            {
                if (array.Get(i).IsObject() && array.Get(i).As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
                {
                    literals.push_back(*Napi::ObjectWrap<GBoolVar>::Unwrap(array.Get(i).As<Napi::Object>())->pBoolVar);
                    continue;
                }
                Napi::TypeError::New(env, "operations_research::GCpModelBuilder::AddBoolOr : Invalid arguments").ThrowAsJavaScriptException();
                return env.Null();
            }
            auto result = pCpModelBuilder->AddBoolOr(literals);
            return GConstraint::constructor.New({Napi::External<Constraint>::New(env, new Constraint(result))});
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::AddBoolOr : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    }
    //     Constraint AddImplication(BoolVar a, BoolVar b)
    Napi::Value AddImplication(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 2 &&
            info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()) //
            && info[1].IsObject() && info[1].As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
        {
            auto a      = Napi::ObjectWrap<GBoolVar>::Unwrap(info[0].As<Napi::Object>())->pBoolVar;
            auto b      = Napi::ObjectWrap<GBoolVar>::Unwrap(info[1].As<Napi::Object>())->pBoolVar;
            auto result = pCpModelBuilder->AddImplication(*a, *b);
            return GConstraint::constructor.New({Napi::External<Constraint>::New(env, new Constraint(result))});
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::AddImplication : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    }
    //     IntervalVar NewFixedSizeIntervalVar(const LinearExpr &start, int64_t size);
    Napi::Value NewFixedSizeIntervalVar(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 2 &&
            info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GLinearExpr::constructor.Value()) //
            && info[1].IsNumber())
        {
            auto start   = Napi::ObjectWrap<GLinearExpr>::Unwrap(info[0].As<Napi::Object>())->pLinearExpr;
            int64_t size = info[1].As<Napi::Number>().Int64Value();
            auto result  = pCpModelBuilder->NewFixedSizeIntervalVar(*start, size);
            return GIntervalVar::constructor.New({Napi::External<IntervalVar>::New(env, new IntervalVar(result))});
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::NewFixedSizeIntervalVar : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    }
    //     CumulativeConstraint AddCumulative(LinearExpr capacity);
    Napi::Value AddCumulative(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GLinearExpr::constructor.Value()))
        {
            auto capacity = Napi::ObjectWrap<GLinearExpr>::Unwrap(info[0].As<Napi::Object>())->pLinearExpr;
            auto result   = pCpModelBuilder->AddCumulative(*capacity);
            return GCumulativeConstraint::constructor.New({Napi::External<CumulativeConstraint>::New(env, new CumulativeConstraint(result))});
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::AddCumulative : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    //     NoOverlap2DConstraint AddNoOverlap2D();
    Napi::Value AddNoOverlap2D(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            auto result = pCpModelBuilder->AddNoOverlap2D();
            return GNoOverlap2DConstraint::constructor.New({Napi::External<NoOverlap2DConstraint>::New(env, new NoOverlap2DConstraint(result))});
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::AddNoOverlap2D : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    //     IntervalVar NewOptionalFixedSizeIntervalVar(const LinearExpr &start, int64_t size, BoolVar presence);
    Napi::Value NewOptionalFixedSizeIntervalVar(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        LinearExpr start;
        if (info.Length() == 3 &&
            GLinearExpr::ToLinearExpr(info[0], start) //
            && info[1].IsNumber()                     //
            && info[2].IsObject() && info[2].As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
        {
            auto start    = Napi::ObjectWrap<GLinearExpr>::Unwrap(info[0].As<Napi::Object>())->pLinearExpr;
            int64_t size  = info[1].As<Napi::Number>().Int64Value();
            auto presence = Napi::ObjectWrap<GBoolVar>::Unwrap(info[2].As<Napi::Object>())->pBoolVar;
            auto result   = pCpModelBuilder->NewOptionalFixedSizeIntervalVar(*start, size, *presence);
            return GIntervalVar::constructor.New({Napi::External<IntervalVar>::New(env, new IntervalVar(result))});
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::NewOptionalFixedSizeIntervalVar : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    Napi::Value FixVariable(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);
        //     void FixVariable(IntVar var, int64_t value);
        if (info.Length() == 2 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()) && info[1].IsNumber())
        {
            auto var      = Napi::ObjectWrap<GIntVar>::Unwrap(info[0].As<Napi::Object>())->pIntVar;
            int64_t value = info[1].As<Napi::Number>().Int64Value();
            pCpModelBuilder->FixVariable(*var, value);
            return env.Undefined();
        }
        //     void FixVariable(BoolVar var, bool value);
        if (info.Length() == 2 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()) && info[1].IsBoolean())
        {
            auto var   = Napi::ObjectWrap<GBoolVar>::Unwrap(info[0].As<Napi::Object>())->pBoolVar;
            bool value = info[1].As<Napi::Boolean>();
            pCpModelBuilder->FixVariable(*var, value);
            return env.Undefined();
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::FixVariable : Invalid arguments").ThrowAsJavaScriptException();
        return env.Undefined();
    }

    //     void SetName(absl::string_view name);
    Napi::Value SetName(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsString())
        {
            std::string name = info[0].As<Napi::String>().Utf8Value();
            pCpModelBuilder->SetName(name);
            return env.Undefined();
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::SetName : Invalid arguments").ThrowAsJavaScriptException();
        return env.Undefined();
    }

    //     void Maximize(const LinearExpr &expr);
    Napi::Value Maximize(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        LinearExpr expr;
        if (info.Length() == 1 && GLinearExpr::ToLinearExpr(info[0], expr))
        {
            pCpModelBuilder->Maximize(expr);
            return env.Undefined();
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::Maximize : Invalid arguments").ThrowAsJavaScriptException();
        return env.Undefined();
    }

    //     void AddAssumptions(absl::Span<const BoolVar> literals);
    Napi::Value AddAssumptions(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsArray())
        {
            Napi::Array array = info[0].As<Napi::Array>();
            int length        = array.Length();
            std::vector<BoolVar> literals;
            literals.reserve(length);
            for (int i = 0; i < length; i++)
            {
                auto pi = array.Get(i);
                if (pi.IsObject() && pi.As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
                {
                    literals.push_back(*Napi::ObjectWrap<GBoolVar>::Unwrap(pi.As<Napi::Object>())->pBoolVar);
                    continue;
                }

                Napi::TypeError::New(env, "operations_research::GCpModelBuilder::AddAssumptions : Invalid arguments").ThrowAsJavaScriptException();
                return env.Undefined();
            }

            pCpModelBuilder->AddAssumptions(literals);
            return env.Undefined();
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::AddAssumptions : Invalid arguments").ThrowAsJavaScriptException();
        return env.Undefined();
    };
    //     IntVar NewIntVar(const Domain &domain);
    Napi::Value NewIntVar(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GDomain::constructor.Value()))
        {
            auto domain = Napi::ObjectWrap<GDomain>::Unwrap(info[0].As<Napi::Object>())->pDomain;
            auto result = pCpModelBuilder->NewIntVar(*domain);
            return GIntVar::constructor.New({Napi::External<IntVar>::New(env, new IntVar(result))});
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::NewIntVar : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //     Constraint AddGreaterThan(const LinearExpr &left, const LinearExpr &right);
    Napi::Value AddGreaterThan(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        LinearExpr left, right;
        if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], left) && GLinearExpr::ToLinearExpr(info[1], right))
        {
            auto result = pCpModelBuilder->AddGreaterThan(left, right);
            return GConstraint::constructor.New({Napi::External<Constraint>::New(env, new Constraint(result))});
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::AddGreaterThan : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //     Constraint AddLessOrEqual(const LinearExpr &left, const LinearExpr &right);
    Napi::Value AddLessOrEqual(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        LinearExpr left, right;
        if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], left) && GLinearExpr::ToLinearExpr(info[1], right))
        {
            auto result = pCpModelBuilder->AddLessOrEqual(left, right);
            return GConstraint::constructor.New({Napi::External<Constraint>::New(env, new Constraint(result))});
        }

        Napi::TypeError::New(env, "operations_research::GCpSolverResponse::AddLessOrEqual : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };
    //     const CpModelProto &Build() const
    Napi::Value Build(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            auto external = Napi::External<CpModelProto>::New(env, new CpModelProto(pCpModelBuilder->Build()));
            return GCpModelProto::constructor.New({external});
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::Build : Invalid arguments").ThrowAsJavaScriptException();
        return env.Undefined();
    }

    //     void Minimize(const LinearExpr &expr);
    Napi::Value Minimize(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GLinearExpr::constructor.Value()))
        {
            auto expr = Napi::ObjectWrap<GLinearExpr>::Unwrap(info[0].As<Napi::Object>())->pLinearExpr;
            pCpModelBuilder->Minimize(*expr);
            return env.Undefined();
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::Minimize : Invalid arguments").ThrowAsJavaScriptException();
        return env.Undefined();
    }

    //     TableConstraint AddAllowedAssignments(absl::Span<const IntVar> vars);
    Napi::Value AddAllowedAssignments(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsArray())
        {
            Napi::Array array = info[0].As<Napi::Array>();
            int length        = array.Length();
            std::vector<IntVar> vars;
            vars.reserve(length);
            for (int i = 0; i < length; i++)
            {
                auto pi = array.Get(i);
                if (pi.IsObject() && pi.As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()))
                {
                    vars.push_back(*Napi::ObjectWrap<GIntVar>::Unwrap(pi.As<Napi::Object>())->pIntVar);
                    continue;
                }

                if (pi.IsObject() && pi.As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
                {
                    vars.push_back(IntVar(*Napi::ObjectWrap<GBoolVar>::Unwrap(pi.As<Napi::Object>())->pBoolVar));
                    continue;
                }

                Napi::TypeError::New(env, "operations_research::GCpModelBuilder::AddAllowedAssignments : Invalid arguments").ThrowAsJavaScriptException();
                return env.Undefined();
            }

            auto external = Napi::External<TableConstraint>::New(env, new TableConstraint(pCpModelBuilder->AddAllowedAssignments(vars)));
            return GTableConstraint::constructor.New({external});
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::AddAllowedAssignments : Invalid arguments").ThrowAsJavaScriptException();
        return env.Undefined();
    }

    //     Constraint AddEquality(const LinearExpr &left, const LinearExpr &right);
    Napi::Value AddEquality(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        LinearExpr left, right;
        if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], left) && GLinearExpr::ToLinearExpr(info[1], right))
        {
            auto external = Napi::External<Constraint>::New(env, new Constraint(pCpModelBuilder->AddEquality(left, right)));
            return GConstraint::constructor.New({external});
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::AddEquality : Invalid arguments").ThrowAsJavaScriptException();
        return env.Undefined();
    }
    //     Constraint AddExactlyOne(absl::Span<const BoolVar> literals);
    Napi::Value AddExactlyOne(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsArray())
        {
            Napi::Array array = info[0].As<Napi::Array>();
            int length        = array.Length();
            std::vector<BoolVar> literals;
            literals.reserve(length);
            for (int i = 0; i < length; i++)
            {
                auto pi = array.Get(i);
                if (!pi.IsObject() || !pi.As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
                {
                    Napi::TypeError::New(env, "operations_research::GCpModelBuilder::AddExactlyOne : Invalid arguments").ThrowAsJavaScriptException();
                    return env.Undefined();
                }

                literals.push_back(*Napi::ObjectWrap<GBoolVar>::Unwrap(pi.As<Napi::Object>())->pBoolVar);
            }

            auto external = Napi::External<Constraint>::New(env, new Constraint(pCpModelBuilder->AddExactlyOne(literals)));
            return GConstraint::constructor.New({external});
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::AddExactlyOne : Invalid arguments").ThrowAsJavaScriptException();
        return env.Undefined();
    }

    //     Constraint AddAtMostOne(absl::Span<const BoolVar> literals);
    Napi::Value AddAtMostOne(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsArray())
        {
            Napi::Array array = info[0].As<Napi::Array>();
            int length        = array.Length();
            std::vector<BoolVar> literals;
            literals.reserve(length);
            for (int i = 0; i < length; i++)
            {
                auto pi = array.Get(i);
                if (!pi.IsObject() || !pi.As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
                {
                    Napi::TypeError::New(env, "operations_research::GCpModelBuilder::AddAtMostOne : Invalid arguments").ThrowAsJavaScriptException();
                    return env.Undefined();
                }
                literals.push_back(*Napi::ObjectWrap<GBoolVar>::Unwrap(pi.As<Napi::Object>())->pBoolVar);
            }

            auto external = Napi::External<Constraint>::New(env, new Constraint(pCpModelBuilder->AddAtMostOne(literals)));
            return GConstraint::constructor.New({external});
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::AddAtMostOne : Invalid arguments").ThrowAsJavaScriptException();
        return env.Undefined();
    }

    //     BoolVar NewBoolVar();
    Napi::Value NewBoolVar(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            auto external = Napi::External<BoolVar>::New(env, new BoolVar(pCpModelBuilder->NewBoolVar()));
            return GBoolVar::constructor.New({external});
        }

        Napi::TypeError::New(env, "operations_research::GCpModelBuilder::NewBoolVar : Invalid arguments").ThrowAsJavaScriptException();
        return env.Undefined();
    };
};
}; // namespace sat
}; // namespace operations_research