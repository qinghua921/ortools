#pragma once

#include "napi.h"
#include "ortools/constraint_solver/constraint_solver.h"

namespace operations_research
{
class GDecisionBuilder : public Napi::ObjectWrap<GDecisionBuilder>
{
  public:
    static inline Napi::FunctionReference constructor;
    DecisionBuilder *pDecisionBuilder = nullptr;

    GDecisionBuilder(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GDecisionBuilder>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external    = info[0].As<Napi::External<DecisionBuilder>>();
            pDecisionBuilder = dynamic_cast<DecisionBuilder *>(external.Data());
            if (pDecisionBuilder) return;
        }

        Napi::TypeError::New(env, "operations_research::GDecisionBuilder::GDecisionBuilder : Invalid arguments").ThrowAsJavaScriptException();
    };

    ~GDecisionBuilder()
    {
        if (pDecisionBuilder) delete pDecisionBuilder;
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);
        Napi::Function func = DefineClass(
            env, "DecisionBuilder", {}
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "DecisionBuilder"), func);
        return exports;
    };
};

}; // namespace operations_research