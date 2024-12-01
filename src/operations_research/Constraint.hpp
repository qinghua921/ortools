#pragma once

#include "napi.h"
#include "ortools/constraint_solver/constraint_solver.h"

namespace operations_research
{
class GConstraint : public Napi::ObjectWrap<GConstraint>
{
  public:
    static inline Napi::FunctionReference constructor;
    Constraint *pConstraint = nullptr;

    GConstraint(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GConstraint>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external = info[0].As<Napi::External<Constraint>>();
            pConstraint   = dynamic_cast<Constraint *>(external.Data());
            if (pConstraint) return;
        }

        Napi::TypeError::New(env, "operations_research::GConstraint::GConstraint : Invalid arguments").ThrowAsJavaScriptException();
    };

    ~GConstraint()
    {
        if (pConstraint) delete pConstraint;
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);
        Napi::Function func = DefineClass(
            env, "Constraint", {}
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "Constraint"), func);
        return exports;
    };
};

}; // namespace operations_research