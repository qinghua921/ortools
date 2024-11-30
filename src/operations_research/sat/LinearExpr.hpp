#pragma once

#include "BoolVar.hpp"
#include "IntVar.hpp"
#include "napi.h"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
class GLinearExpr : public Napi::ObjectWrap<GLinearExpr>
{
  public:
    static inline Napi::FunctionReference constructor;
    LinearExpr *pLinearExpr = nullptr;

    GLinearExpr(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GLinearExpr>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external = info[0].As<Napi::External<LinearExpr>>();
            pLinearExpr   = dynamic_cast<LinearExpr *>(external.Data());
            if (pLinearExpr) return;
        }

        if (info.Length() == 0)
        {
            pLinearExpr = new LinearExpr();
            return;
        }

        Napi::TypeError::New(env, "operations_research::GLinearExpr::GLinearExpr : Invalid arguments").ThrowAsJavaScriptException();
    };

    ~GLinearExpr()
    {
        if (pLinearExpr) delete pLinearExpr;
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);
        Napi::Function func = DefineClass(
            env,
            "LinearExpr",
            {
                InstanceMethod("operator_plus_eq", &GLinearExpr::operator_plus_eq),
                InstanceMethod("operator_times_eq", &GLinearExpr::operator_times_eq),
                StaticMethod("Sum", &GLinearExpr::Sum),
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "LinearExpr"), func);
        return exports;
    };
    //  static LinearExpr Sum(absl::Span<const IntVar> vars);
    static Napi::Value Sum(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        std::vector<IntVar> vars;
        if (info.Length() == 1 && info[0].IsArray())
        {
            Napi::Array arr = info[0].As<Napi::Array>();

            for (uint32_t i = 0; i < arr.Length(); i++)
            {
                if (arr.Get(i).IsObject() && arr.Get(i).As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()))
                {
                    vars.push_back(*GIntVar::Unwrap(arr.Get(i).As<Napi::Object>())->pIntVar);
                    continue;
                }
            }

            if (vars.size() == 0)
            {
                for (uint32_t i = 0; i < arr.Length(); i++)
                {
                    if (arr.Get(i).IsObject() && arr.Get(i).As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
                    {
                        vars.push_back(*GIntVar::Unwrap(arr.Get(i).As<Napi::Object>())->pIntVar);
                        continue;
                    }
                }
            }
            
            if (vars.size() > 0)
            {
                return GLinearExpr::constructor.New({Napi::External<LinearExpr>::New(env, new LinearExpr(LinearExpr::Sum(vars)))});
            }
        }

        Napi::TypeError::New(env, "operations_research::GLinearExpr::Sum : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    //  LinearExpr &operator*=(int64_t factor);
    Napi::Value operator_times_eq(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsNumber())
        {
            int64_t factor = info[0].As<Napi::Number>().Int64Value();
            *pLinearExpr *= factor;
            return this->Value();
        }

        Napi::TypeError::New(env, "operations_research::GLinearExpr::operator*= : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    //  LinearExpr &operator+=(const LinearExpr &other);
    Napi::Value operator_plus_eq(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        LinearExpr other;
        if (info.Length() == 1 && ToLinearExpr(info[0], other))
        {
            *pLinearExpr += other;
            return this->Value();
        }

        Napi::TypeError::New(env, "operations_research::GLinearExpr::operator+= : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    bool static ToLinearExpr(const Napi::Value &value, LinearExpr &expr)
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
};
}; // namespace sat
}; // namespace operations_research