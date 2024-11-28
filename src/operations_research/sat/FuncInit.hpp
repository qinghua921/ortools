#pragma once

#include "CpSolverResponse.hpp"
#include "LinearExpr.hpp"
#include "napi.h"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
// inline LinearExpr operator*(LinearExpr expr, int64_t factor)
Napi::Value Goperator_times(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr expr;
    if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], expr) && info[1].IsNumber())
    {
        int64_t factor = info[1].As<Napi::Number>().Int64Value();
        auto external  = Napi::External<LinearExpr>::New(env, new LinearExpr(expr * factor));
        return GLinearExpr::constructor.New({external});
    }

    return env.Null();
}
// CpSolverResponse Solve(const CpModelProto& model_proto);
Napi::Value GSolve(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GCpModelProto::constructor.Value()))
    {
        auto gCpModelProto     = Napi::ObjectWrap<GCpModelProto>::Unwrap(info[0].As<Napi::Object>());
        auto gCpSolverResponse = Solve(*gCpModelProto->pCpModelProto);
        auto external          = Napi::External<CpSolverResponse>::New(env, new CpSolverResponse(gCpSolverResponse));
        return GCpSolverResponse::constructor.New({external});
    }

    Napi::TypeError::New(env, "Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// bool SolutionBooleanValue(const CpSolverResponse &r, BoolVar x);
Napi::Value GSolutionBooleanValue(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 2 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GCpSolverResponse::constructor.Value()) && info[1].IsObject() && info[1].As<Napi::Object>().InstanceOf(GBoolVar::constructor.Value()))
    {
        auto gCpSolverResponse = Napi::ObjectWrap<GCpSolverResponse>::Unwrap(info[0].As<Napi::Object>());
        auto gBoolVar          = Napi::ObjectWrap<GBoolVar>::Unwrap(info[1].As<Napi::Object>());
        return Napi::Boolean::New(env, SolutionBooleanValue(*gCpSolverResponse->pCpSolverResponse, *gBoolVar->pBoolVar));
    }

    Napi::TypeError::New(env, "Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

Napi::Object FuncInit(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);

    exports.Set("operator_times", Napi::Function::New(env, Goperator_times));
    exports.Set("Solve", Napi::Function::New(env, GSolve));
    exports.Set("SolutionBooleanValue", Napi::Function::New(env, GSolutionBooleanValue));

    auto enumCpSolverStatus = Napi::Object::New(env);
    enumCpSolverStatus.Set("UNKNOWN", static_cast<int>(CpSolverStatus::UNKNOWN));
    enumCpSolverStatus.Set("MODEL_INVALID", static_cast<int>(CpSolverStatus::MODEL_INVALID));
    enumCpSolverStatus.Set("FEASIBLE", static_cast<int>(CpSolverStatus::FEASIBLE));
    enumCpSolverStatus.Set("INFEASIBLE", static_cast<int>(CpSolverStatus::INFEASIBLE));
    enumCpSolverStatus.Set("OPTIMAL", static_cast<int>(CpSolverStatus::OPTIMAL));
    exports.Set("CpSolverStatus", enumCpSolverStatus);

    return exports;
};
} // namespace sat
}; // namespace operations_research