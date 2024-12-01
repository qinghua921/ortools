#pragma once

#include "CpSolverResponse.hpp"
#include "LinearExpr.hpp"
#include "Model.hpp"
#include "SatParameters.hpp"
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

    if (info.Length() == 2 && info[0].IsNumber() && GLinearExpr::ToLinearExpr(info[1], expr))
    {
        int64_t factor = info[0].As<Napi::Number>().Int64Value();
        auto external  = Napi::External<LinearExpr>::New(env, new LinearExpr(expr * factor));
        return GLinearExpr::constructor.New({external});
    }

    Napi::TypeError::New(env, "operations_research::sat::operator_times: Invalid arguments").ThrowAsJavaScriptException();
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

    Napi::TypeError::New(env, "operations_research::sat::GSolve : Invalid arguments").ThrowAsJavaScriptException();
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

    Napi::TypeError::New(env, "operations_research::sat::GSolutionBooleanValue : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// std::string CpSolverResponseStats(const CpSolverResponse& response, bool has_objective = true);
Napi::Value GCpSolverResponseStats(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GCpSolverResponse::constructor.Value()))
    {
        auto gCpSolverResponse = Napi::ObjectWrap<GCpSolverResponse>::Unwrap(info[0].As<Napi::Object>());
        return Napi::String::New(env, CpSolverResponseStats(*gCpSolverResponse->pCpSolverResponse));
    }

    if (info.Length() == 2 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GCpSolverResponse::constructor.Value()) && info[1].IsBoolean())
    {
        auto gCpSolverResponse = Napi::ObjectWrap<GCpSolverResponse>::Unwrap(info[0].As<Napi::Object>());
        bool has_objective     = info[1].As<Napi::Boolean>().Value();
        return Napi::String::New(env, CpSolverResponseStats(*gCpSolverResponse->pCpSolverResponse, has_objective));
    }

    Napi::TypeError::New(env, "operations_research::sat::GCpSolverResponseStats : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}
// CpSolverResponse SolveWithParameters(const CpModelProto& model_proto, const SatParameters& params);
Napi::Value GSolveWithParameters(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 2                                                                                  //
        && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GCpModelProto::constructor.Value())  //
        && info[1].IsObject() && info[1].As<Napi::Object>().InstanceOf(GSatParameters::constructor.Value()) //
    )
    {
        auto gCpModelProto     = Napi::ObjectWrap<GCpModelProto>::Unwrap(info[0].As<Napi::Object>());
        auto gSatParameters    = Napi::ObjectWrap<GSatParameters>::Unwrap(info[1].As<Napi::Object>());
        auto gCpSolverResponse = SolveWithParameters(*gCpModelProto->pCpModelProto, *gSatParameters->pSatParameters);
        auto external          = Napi::External<CpSolverResponse>::New(env, new CpSolverResponse(gCpSolverResponse));
        return GCpSolverResponse::constructor.New({external});
    }

    Napi::TypeError::New(env, "operations_research::sat::GSolveWithParameters : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// inline LinearExpr operator+(LinearExpr&& lhs, LinearExpr&& rhs)
Napi::Value Goperator_plus(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr lhs, rhs;
    if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], lhs) && GLinearExpr::ToLinearExpr(info[1], rhs))
    {
        auto external = Napi::External<LinearExpr>::New(env, new LinearExpr(lhs + rhs));
        return GLinearExpr::constructor.New({external});
    }

    Napi::TypeError::New(env, "operations_research::sat::Goperator_plus : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// std::function<SatParameters(Model*)> NewSatParameters(const SatParameters& parameters);
Napi::Value GNewSatParameters(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GSatParameters::constructor.Value()))
    {
        auto gSatParameters = Napi::ObjectWrap<GSatParameters>::Unwrap(info[0].As<Napi::Object>());
        auto func           = NewSatParameters(*gSatParameters->pSatParameters);
        return Napi::Function::New(
            env,
            [func](const Napi::CallbackInfo &info) -> Napi::Value
            {
                Napi::Env env = info.Env();
                Napi::HandleScope scope(env);

                if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GModel::constructor.Value()))
                {
                    auto gModel = Napi::ObjectWrap<GModel>::Unwrap(info[0].As<Napi::Object>());
                    return GSatParameters::constructor.New({Napi::External<SatParameters>::New(env, new SatParameters(func(gModel->pModel)))});
                }

                Napi::TypeError::New(env, "operations_research::sat::GNewSatParameters return function : Invalid arguments").ThrowAsJavaScriptException();
                return env.Null();
            }
        );
    }

    Napi::TypeError::New(env, "operations_research::sat::GNewSatParameters : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

Napi::FunctionReference callbackNewFeasibleSolutionObserver;
// std::function<void(Model*)> NewFeasibleSolutionObserver( const std::function<void(const CpSolverResponse& response)>& callback);
Napi::Value GNewFeasibleSolutionObserver(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (!callbackNewFeasibleSolutionObserver.IsEmpty())
    {
        Napi::Error::New(env, "operations_research::sat::GNewFeasibleSolutionObserver : callback already set").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (info.Length() == 1 && info[0].IsFunction())
    {
        callbackNewFeasibleSolutionObserver = Napi::Persistent(info[0].As<Napi::Function>());
        auto func                           = NewFeasibleSolutionObserver(
            [env](const CpSolverResponse &response)
            {
                Napi::HandleScope scope(env);
                auto gCpSolverResponse = GCpSolverResponse::constructor.New({Napi::External<CpSolverResponse>::New(env, new CpSolverResponse(response))});
                callbackNewFeasibleSolutionObserver.Call({gCpSolverResponse});
            }
        );
        return Napi::Function::New(
            env,
            [func](const Napi::CallbackInfo &info) -> Napi::Value
            {
                Napi::Env env = info.Env();
                Napi::HandleScope scope(env);

                if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GModel::constructor.Value()))
                {
                    auto gModel = Napi::ObjectWrap<GModel>::Unwrap(info[0].As<Napi::Object>());
                    func(gModel->pModel);
                    return env.Null();
                }

                Napi::TypeError::New(env, "operations_research::sat::GNewFeasibleSolutionObserver return function : Invalid arguments").ThrowAsJavaScriptException();
                return env.Null();
            }
        );
    }

    Napi::TypeError::New(env, "operations_research::sat::GNewFeasibleSolutionObserver : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// int64_t SolutionIntegerValue(const CpSolverResponse& r, const LinearExpr& expr);
Napi::Value GSolutionIntegerValue(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr expr;
    if (info.Length() == 2                                                                                     //
        && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GCpSolverResponse::constructor.Value()) //
        && GLinearExpr::ToLinearExpr(info[1], expr)                                                            //
    )
    {
        auto gCpSolverResponse = Napi::ObjectWrap<GCpSolverResponse>::Unwrap(info[0].As<Napi::Object>());
        return Napi::Number::New(env, SolutionIntegerValue(*gCpSolverResponse->pCpSolverResponse, expr));
    }

    Napi::TypeError::New(env, "operations_research::sat::GSolutionIntegerValue : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// CpSolverResponse SolveCpModel(const CpModelProto& model_proto, Model* model);
Napi::Value GSolveCpModel(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    if (info.Length() == 2                                                                                 //
        && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GCpModelProto::constructor.Value()) //
        && info[1].IsObject() && info[1].As<Napi::Object>().InstanceOf(GModel::constructor.Value())        //
    )
    {
        auto gCpModelProto    = Napi::ObjectWrap<GCpModelProto>::Unwrap(info[0].As<Napi::Object>());
        auto gModel           = Napi::ObjectWrap<GModel>::Unwrap(info[1].As<Napi::Object>());
        auto cpSolverResponse = SolveCpModel(*gCpModelProto->pCpModelProto, gModel->pModel);
        auto external         = Napi::External<CpSolverResponse>::New(env, new CpSolverResponse(cpSolverResponse));
        return GCpSolverResponse::constructor.New({external});
    }

    Napi::TypeError::New(env, "operations_research::sat::GSolveCpModel : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

Napi::Object FuncInit(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);

    exports.Set("operator_times", Napi::Function::New(env, Goperator_times));
    exports.Set("Solve", Napi::Function::New(env, GSolve));
    exports.Set("SolutionBooleanValue", Napi::Function::New(env, GSolutionBooleanValue));
    exports.Set("CpSolverResponseStats", Napi::Function::New(env, GCpSolverResponseStats));
    exports.Set("SolveWithParameters", Napi::Function::New(env, GSolveWithParameters));
    exports.Set("operator_plus", Napi::Function::New(env, Goperator_plus));
    exports.Set("NewSatParameters", Napi::Function::New(env, GNewSatParameters));
    exports.Set("NewFeasibleSolutionObserver", Napi::Function::New(env, GNewFeasibleSolutionObserver));
    exports.Set("SolutionIntegerValue", Napi::Function::New(env, GSolutionIntegerValue));
    exports.Set("SolveCpModel", Napi::Function::New(env, GSolveCpModel));

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