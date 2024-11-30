#pragma once

#include "./IntervalVar.hpp"
#include "./LinearExpr.hpp"
#include "napi.h"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
class GCumulativeConstraint : public Napi::ObjectWrap<GCumulativeConstraint>
{
  public:
    static inline Napi::FunctionReference constructor;
    CumulativeConstraint *pCumulativeConstraint = nullptr;

    GCumulativeConstraint(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GCumulativeConstraint>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external         = info[0].As<Napi::External<CumulativeConstraint>>();
            pCumulativeConstraint = dynamic_cast<CumulativeConstraint *>(external.Data());
            if (pCumulativeConstraint) return;
        }

        Napi::TypeError::New(env, "operations_research::GCumulativeConstraint::GCumulativeConstraint : Invalid arguments").ThrowAsJavaScriptException();
    };

    ~GCumulativeConstraint()
    {
        if (pCumulativeConstraint) delete pCumulativeConstraint;
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);
        Napi::Function func = DefineClass(
            env,
            "CumulativeConstraint",
            {
                InstanceMethod("AddDemand", &GCumulativeConstraint::AddDemand),
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "CumulativeConstraint"), func);
        return exports;
    };

    //  void AddDemand(IntervalVar interval, LinearExpr demand);
    Napi::Value AddDemand(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        if (info.Length() == 2                                                                                         //
            && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GCumulativeConstraint::constructor.Value()) //
            && info[1].IsObject() && info[1].As<Napi::Object>().InstanceOf(GIntervalVar::constructor.Value())          //
        )
        {
            auto interval = Napi::ObjectWrap<GIntervalVar>::Unwrap(info[1].As<Napi::Object>())->pIntervalVar;
            auto demand   = Napi::ObjectWrap<GLinearExpr>::Unwrap(info[2].As<Napi::Object>())->pLinearExpr;
            pCumulativeConstraint->AddDemand(*interval, *demand);
            return env.Null();
        }
        Napi::TypeError::New(env, "CumulativeConstraint::AddDemand : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };
};
}; // namespace sat
}; // namespace operations_research