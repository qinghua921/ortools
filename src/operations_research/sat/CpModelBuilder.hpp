#pragma once

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
            env, "CpModelBuilder", {}
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "CpModelBuilder"), func);
        return exports;
    };
};
}; // namespace sat
}; // namespace operations_research