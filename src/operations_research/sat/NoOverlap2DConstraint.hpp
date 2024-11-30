#pragma once

#include "napi.h"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
class GNoOverlap2DConstraint : public Napi::ObjectWrap<GNoOverlap2DConstraint>
{
  public:
    static inline Napi::FunctionReference constructor;
    NoOverlap2DConstraint *pNoOverlap2DConstraint = nullptr;

    GNoOverlap2DConstraint(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GNoOverlap2DConstraint>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external          = info[0].As<Napi::External<NoOverlap2DConstraint>>();
            pNoOverlap2DConstraint = dynamic_cast<NoOverlap2DConstraint *>(external.Data());
            if (pNoOverlap2DConstraint) return;
        }

        Napi::TypeError::New(env, "operations_research::GNoOverlap2DConstraint::GNoOverlap2DConstraint : Invalid arguments").ThrowAsJavaScriptException();
    };

    ~GNoOverlap2DConstraint()
    {
        if (pNoOverlap2DConstraint) delete pNoOverlap2DConstraint;
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);
        Napi::Function func = DefineClass(
            env,
            "NoOverlap2DConstraint",
            {
                InstanceMethod("AddRectangle", &GNoOverlap2DConstraint::AddRectangle),
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "NoOverlap2DConstraint"), func);
        return exports;
    };

    //  void AddRectangle(IntervalVar x_coordinate, IntervalVar y_coordinate);
    Napi::Value AddRectangle(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        if (info.Length() == 2 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GIntervalVar::constructor.Value()) && info[1].IsObject() && info[1].As<Napi::Object>().InstanceOf(GIntervalVar::constructor.Value()))
        {
            auto x_coordinate = Napi::ObjectWrap<GIntervalVar>::Unwrap(info[0].As<Napi::Object>());
            auto y_coordinate = Napi::ObjectWrap<GIntervalVar>::Unwrap(info[1].As<Napi::Object>());
            pNoOverlap2DConstraint->AddRectangle(*x_coordinate->pIntervalVar, *y_coordinate->pIntervalVar);
            return env.Null();
        }
        Napi::TypeError::New(env, "operations_research::GNoOverlap2DConstraint::AddRectangle : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };
};
}; // namespace sat
}; // namespace operations_research