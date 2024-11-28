#pragma once

#include "napi.h"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
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

    ~GIntVar()
    {
        if (pIntVar) delete pIntVar;
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);
        Napi::Function func = DefineClass(
            env, "IntVar", {}
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "IntVar"), func);
        return exports;
    };
};
}; // namespace sat
}; // namespace operations_research