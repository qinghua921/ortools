#pragma once

#include "napi.h"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
class GDecisionStrategyProto : public Napi::ObjectWrap<GDecisionStrategyProto>
{
  public:
    static inline Napi::FunctionReference constructor;
    DecisionStrategyProto *pDecisionStrategyProto = nullptr;

    GDecisionStrategyProto(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GDecisionStrategyProto>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external          = info[0].As<Napi::External<DecisionStrategyProto>>();
            pDecisionStrategyProto = dynamic_cast<DecisionStrategyProto *>(external.Data());
            if (pDecisionStrategyProto) return;
        }

        Napi::TypeError::New(env, "operations_research::GDecisionStrategyProto::GDecisionStrategyProto : Invalid arguments").ThrowAsJavaScriptException();
    };

    ~GDecisionStrategyProto()
    {
        if (pDecisionStrategyProto) delete pDecisionStrategyProto;
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);
        Napi::Function func = DefineClass(
            env,
            "DecisionStrategyProto",
            {
                StaticValue("CHOOSE_FIRST", Napi::Number::New(env, DecisionStrategyProto::CHOOSE_FIRST)),
                StaticValue("CHOOSE_LOWEST_MIN", Napi::Number::New(env, DecisionStrategyProto::CHOOSE_LOWEST_MIN)),
                StaticValue("CHOOSE_HIGHEST_MAX", Napi::Number::New(env, DecisionStrategyProto::CHOOSE_HIGHEST_MAX)),
                StaticValue("CHOOSE_MIN_DOMAIN_SIZE", Napi::Number::New(env, DecisionStrategyProto::CHOOSE_MIN_DOMAIN_SIZE)),
                StaticValue("CHOOSE_MAX_DOMAIN_SIZE", Napi::Number::New(env, DecisionStrategyProto::CHOOSE_MAX_DOMAIN_SIZE)),

                StaticValue("SELECT_MIN_VALUE", Napi::Number::New(env, DecisionStrategyProto::SELECT_MIN_VALUE)),
                StaticValue("SELECT_MAX_VALUE", Napi::Number::New(env, DecisionStrategyProto::SELECT_MAX_VALUE)),
                StaticValue("SELECT_LOWER_HALF", Napi::Number::New(env, DecisionStrategyProto::SELECT_LOWER_HALF)),
                StaticValue("SELECT_UPPER_HALF", Napi::Number::New(env, DecisionStrategyProto::SELECT_UPPER_HALF)),
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "DecisionStrategyProto"), func);
        return exports;
    };
};
}; // namespace sat
}; // namespace operations_research