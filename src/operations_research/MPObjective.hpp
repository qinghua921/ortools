#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{
class GMPObjective : public Napi::ObjectWrap<GMPObjective>
{
  public:
    static inline Napi::FunctionReference constructor;
    MPObjective *pMPObjective = nullptr;

    GMPObjective(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GMPObjective>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external = info[0].As<Napi::External<MPObjective>>();
            pMPObjective  = dynamic_cast<MPObjective *>(external.Data());
            if (pMPObjective) return;
        }

        Napi::TypeError::New(env, "operations_research::GMPObjective::GMPObjective : Invalid arguments").ThrowAsJavaScriptException();
    };

    // TODO delete pMPObjective or not ?
    // ~GMPObjective()
    // {
    //     if ( pMPObjective ) delete pMPObjective;
    // };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);
        Napi::Function func = DefineClass(
            env,
            "MPObjective",
            {
                InstanceMethod("Value", &GMPObjective::Value),
                InstanceMethod("SetCoefficient", &GMPObjective::SetCoefficient),
                InstanceMethod("SetMinimization", &GMPObjective::SetMinimization),
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "MPObjective"), func);
        return exports;
    };

    //     double Value() const;
    Napi::Value Value(const Napi::CallbackInfo &info)
    {

        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            return Napi::Number::New(env, pMPObjective->Value());
        }

        Napi::TypeError::New(env, "operations_research::GMPObjective::Value : Invalid arguments").ThrowAsJavaScriptException();
        return env.Undefined();
    }

    //     void SetMinimization()
    Napi::Value SetMinimization(const Napi::CallbackInfo &info)
    {

        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            pMPObjective->SetMinimization();
            return env.Null();
        }

        Napi::TypeError::New(env, "operations_research::GMPObjective::SetMinimization : Invalid arguments").ThrowAsJavaScriptException();
        return env.Undefined();
    };

    //     void SetCoefficient(const MPVariable *var, double coeff);
    Napi::Value SetCoefficient(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 2 && info[0].IsObject() && info[1].IsNumber())
        {
            auto var         = info[0].As<Napi::Object>();
            auto coeff       = info[1].As<Napi::Number>();

            auto pMPVariable = Napi::ObjectWrap<GMPVariable>::Unwrap(var)->pMPVariable;

            pMPObjective->SetCoefficient(pMPVariable, coeff.DoubleValue());

            return env.Null();
        }

        Napi::TypeError::New(env, "operations_research::GMPObjective::SetCoefficient : Invalid arguments").ThrowAsJavaScriptException();
        return env.Undefined();
    };
};

}; // namespace operations_research