#pragma once

#include "napi.h"
#include "ortools/constraint_solver/constraint_solver.h"

namespace operations_research
{
class GIntVar : public Napi::ObjectWrap<GIntVar>
{
  public:
    static inline Napi::FunctionReference constructor;
    IntVar *pIntVar = nullptr;

    GIntVar(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GIntVar>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external = info[0].As<Napi::External<IntVar>>();
            pIntVar       = dynamic_cast<IntVar *>(external.Data());
            if (pIntVar) return;
        }

        Napi::TypeError::New(env, "operations_research::GIntVar::GIntVar : Invalid arguments").ThrowAsJavaScriptException();
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);
        Napi::Function func = DefineClass(
            env,
            "IntVar",
            {
                InstanceMethod("Value", &GIntVar::Value),
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "IntVar"), func);
        return exports;
    };

    //      virtual int64_t Value() const = 0;
    Napi::Value Value(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            return Napi::Number::New(env, pIntVar->Value());
        }

        Napi::TypeError::New(env, "operations_research::GIntVar::Value : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };
};

}; // namespace operations_research