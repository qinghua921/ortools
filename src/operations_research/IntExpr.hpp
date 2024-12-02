#pragma once

#include "IntVar.hpp"
#include "napi.h"
#include "ortools/constraint_solver/constraint_solver.h"

namespace operations_research
{
class GIntExpr : public Napi::ObjectWrap<GIntExpr>
{
  public:
    static inline Napi::FunctionReference constructor;
    IntExpr *pIntExpr = nullptr;

    GIntExpr(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GIntExpr>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external = info[0].As<Napi::External<IntExpr>>();
            pIntExpr      = dynamic_cast<IntExpr *>(external.Data());
            if (pIntExpr) return;
        }

        Napi::TypeError::New(env, "operations_research::GIntExpr::GIntExpr : Invalid arguments").ThrowAsJavaScriptException();
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);
        Napi::Function func = DefineClass(
            env,
            "IntExpr",
            {
                InstanceMethod("Var", &GIntExpr::Var),
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "IntExpr"), func);
        return exports;
    };

    //      virtual IntVar* Var() = 0;
    Napi::Value Var(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            auto var      = pIntExpr->Var();
            auto external = Napi::External<IntVar>::New(env, var);
            return GIntVar::constructor.New({external});
        }

        Napi::TypeError::New(env, "operations_research::GIntExpr::Var : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    static IntExpr* ToIntExpr(const Napi::Value &value)
    {
        if (!value.IsObject()) return nullptr;

        auto obj = value.As<Napi::Object>();

        if (obj.InstanceOf(GIntExpr::constructor.Value()))
        {
            auto gIntExpr = GIntExpr::Unwrap(obj);
           return gIntExpr->pIntExpr;
        }

        if (obj.InstanceOf(GIntVar::constructor.Value()))
        {
            auto gIntVar = GIntVar::Unwrap(obj);
            return gIntVar->pIntVar;
        }

        return nullptr;
    }
};

}; // namespace operations_research