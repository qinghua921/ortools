#pragma once

#include "napi.h"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
class GSatParameters : public Napi::ObjectWrap<GSatParameters>
{
  public:
    static inline Napi::FunctionReference constructor;
    SatParameters *pSatParameters = nullptr;

    GSatParameters(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GSatParameters>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external  = info[0].As<Napi::External<SatParameters>>();
            pSatParameters = dynamic_cast<SatParameters *>(external.Data());
            if (pSatParameters) return;
        }

        Napi::TypeError::New(env, "operations_research::GSatParameters::GSatParameters : Invalid arguments").ThrowAsJavaScriptException();
    };

    ~GSatParameters()
    {
        if (pSatParameters) delete pSatParameters;
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);
        Napi::Function func = DefineClass(
            env,
            "SatParameters",
            {
                InstanceMethod("set_log_search_progress", &GSatParameters::set_log_search_progress),
                InstanceMethod("num_workers", &GSatParameters::num_workers),
                InstanceMethod("add_ignore_subsolvers", &GSatParameters::add_ignore_subsolvers),
                InstanceMethod("add_extra_subsolvers", &GSatParameters::add_extra_subsolvers),
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "SatParameters"), func);
        return exports;
    };
    Napi::Value add_extra_subsolvers(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        //   void add_extra_subsolvers(const std::string& value);
        if (info.Length() == 1 && info[0].IsString())
        {
            std::string value = info[0].As<Napi::String>();
            pSatParameters->add_extra_subsolvers(value);
            return env.Null();
        }

        Napi::TypeError::New(env, "add_extra_subsolvers : Invalid arguments").ThrowAsJavaScriptException();
        return Napi::Boolean::New(env, false);
    };
    Napi::Value add_ignore_subsolvers(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        //   void add_ignore_subsolvers(const std::string& value);
        if (info.Length() == 1 && info[0].IsString())
        {
            std::string value = info[0].As<Napi::String>();
            pSatParameters->add_ignore_subsolvers(value);
            return env.Null();
        }

        Napi::TypeError::New(env, "add_ignore_subsolvers : Invalid arguments").ThrowAsJavaScriptException();
        return Napi::Boolean::New(env, false);
    };

    //   ::int32_t num_workers() const;
    Napi::Value num_workers(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            return Napi::Number::New(env, pSatParameters->num_workers());
        }

        Napi::TypeError::New(env, "num_workers : Invalid arguments").ThrowAsJavaScriptException();
        return Napi::Number::New(env, 0);
    };

    //   void set_log_search_progress(bool value);
    Napi::Value set_log_search_progress(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsBoolean())
        {
            bool value = info[0].As<Napi::Boolean>();
            pSatParameters->set_log_search_progress(value);
            return Napi::Boolean::New(env, true);
        }

        Napi::TypeError::New(env, "set_log_search_progress : Invalid arguments").ThrowAsJavaScriptException();
        return Napi::Boolean::New(env, false);
    };
};
}; // namespace sat
}; // namespace operations_research