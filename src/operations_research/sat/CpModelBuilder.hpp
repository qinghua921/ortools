#pragma once

#include "./BoolVar.hpp"
#include "./Constraint.hpp"
#include "./CpModelProto.hpp"
#include "./IntVar.hpp"
#include "./LinearExpr.hpp"
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
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "CpModelBuilder"), func);
        return exports;
    };
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