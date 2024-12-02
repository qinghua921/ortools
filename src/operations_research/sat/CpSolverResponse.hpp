#pragma once

#include "LinearExpr.hpp"
#include "napi.h"

namespace operations_research
{
namespace sat
{
class GCpSolverResponse : public Napi::ObjectWrap<GCpSolverResponse>
{
  public:
    static inline Napi::FunctionReference constructor;
    CpSolverResponse *pCpSolverResponse = nullptr;

    GCpSolverResponse(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GCpSolverResponse>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external     = info[0].As<Napi::External<CpSolverResponse>>();
            pCpSolverResponse = dynamic_cast<CpSolverResponse *>(external.Data());
            if (pCpSolverResponse) return;
        }

        Napi::TypeError::New(env, "operations_research::GCpSolverResponse::GCpSolverResponse : Invalid arguments").ThrowAsJavaScriptException();
    };

    ~GCpSolverResponse()
    {
        if (pCpSolverResponse) delete pCpSolverResponse;
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);
        Napi::Function func = DefineClass(
            env,
            "CpSolverResponse",
            {
                InstanceMethod("objective_value", &GCpSolverResponse::objective_value),
                InstanceMethod("status", &GCpSolverResponse::status),
                InstanceMethod("sufficient_assumptions_for_infeasibility", &GCpSolverResponse::sufficient_assumptions_for_infeasibility),
                InstanceMethod("wall_time", &GCpSolverResponse::wall_time),
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "CpSolverResponse"), func);
        return exports;
    };
    //  double wall_time() const;
    Napi::Value wall_time(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            return Napi::Number::New(env, pCpSolverResponse->wall_time());
        }

        Napi::TypeError::New(env, "operations_research::GCpSolverResponse::wall_time : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };
    //  ::operations_research::sat::CpSolverStatus status() const;
    Napi::Value status(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            return Napi::Number::New(env, pCpSolverResponse->status());
        }

        Napi::TypeError::New(env, "operations_research::GCpSolverResponse::status : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };
    //  const ::google::protobuf::RepeatedField<::int32_t>& sufficient_assumptions_for_infeasibility() const;
    Napi::Value sufficient_assumptions_for_infeasibility(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            auto vec = pCpSolverResponse->sufficient_assumptions_for_infeasibility();
            auto arr = Napi::Array::New(env, vec.size());
            for (int i = 0; i < vec.size(); i++)
            {
                arr[i] = Napi::Number::New(env, vec[i]);
            }
            return arr;
        }

        Napi::TypeError::New(env, "operations_research::GCpSolverResponse::sufficient_assumptions_for_infeasibility : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //  double objective_value() const;
    Napi::Value objective_value(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            return Napi::Number::New(env, pCpSolverResponse->objective_value());
        }

        Napi::TypeError::New(env, "operations_research::GCpSolverResponse::objective_value : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };
};
}; // namespace sat
}; // namespace operations_research