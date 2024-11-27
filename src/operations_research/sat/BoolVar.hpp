#pragma once

#include "napi.h"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
class GBoolVar : public Napi::ObjectWrap<GBoolVar>
{
  public:
    static inline Napi::FunctionReference constructor;
    BoolVar *pBoolVar = nullptr;

    GBoolVar(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GBoolVar>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external = info[0].As<Napi::External<BoolVar>>();
            pBoolVar      = dynamic_cast<BoolVar *>(external.Data());
            if (pBoolVar) return;
        }

        Napi::TypeError::New(env, "operations_research::GBoolVar::GBoolVar : Invalid arguments").ThrowAsJavaScriptException();
    };

    ~GBoolVar()
    {
        if (pBoolVar) delete pBoolVar;
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);
        Napi::Function func = DefineClass(
            env,
            "BoolVar",
            {
                InstanceMethod("WithName", &GBoolVar::WithName),
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "BoolVar"), func);
        return exports;
    };

    //  BoolVar WithName(absl::string_view name);
    Napi::Value WithName(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi ::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsString())
        {
            Napi::String name = info[0].As<Napi::String>();
            pBoolVar->WithName(name.Utf8Value());
            return this->Value();
        }

        Napi::TypeError::New(env, "operations_research::GBoolVar::WithName : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };
};
}; // namespace sat
}; // namespace operations_research