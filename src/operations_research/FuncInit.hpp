#pragma once

#include "LinearExpr.hpp"
#include "LinearRange.hpp"
#include "napi.h"

namespace operations_research
{

// LinearRange operator>=(const LinearExpr &lhs, const LinearExpr &rhs);
Napi::Value Goperator_ge(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr lhs, rhs;
    if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], lhs) && GLinearExpr::ToLinearExpr(info[1], rhs))
    {
        auto result   = lhs >= rhs;
        auto external = Napi::External<LinearRange>::New(env, new LinearRange(result));
        return GLinearRange::constructor.New({external});
    }

    Napi::TypeError::New(env, "operations_research::operator_ge : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
};

// LinearRange operator==(const LinearExpr &lhs, const LinearExpr &rhs);
Napi::Value Goperator_eq(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr lhs, rhs;
    if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], lhs) && GLinearExpr::ToLinearExpr(info[1], rhs))
    {
        auto result   = lhs == rhs;
        auto external = Napi::External<LinearRange>::New(env, new LinearRange(result));
        return GLinearRange::constructor.New({external});
    }

    Napi::TypeError::New(env, "operations_research::operator_eq : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
};

// LinearRange operator<=(const LinearExpr &lhs, const LinearExpr &rhs);
Napi::Value Goperator_le(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr lhs, rhs;
    if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], lhs) && GLinearExpr::ToLinearExpr(info[1], rhs))
    {
        auto result   = lhs <= rhs;
        auto external = Napi::External<LinearRange>::New(env, new LinearRange(result));
        return GLinearRange::constructor.New({external});
    }

    Napi::TypeError::New(env, "operations_research::operator_le : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

// LinearExpr operator*(LinearExpr lhs, double rhs);
Napi::Value Goperator_times(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    LinearExpr lhs;
    double rhs;
    if (info.Length() == 2 && GLinearExpr::ToLinearExpr(info[0], lhs) && info[1].IsNumber())
    {
        rhs         = info[1].As<Napi::Number>().DoubleValue();
        auto result = lhs * rhs;
        return GLinearExpr::constructor.New({Napi::External<LinearExpr>::New(env, new LinearExpr(result))});
    }

    if (info.Length() == 2 && info[0].IsNumber() && GLinearExpr::ToLinearExpr(info[1], lhs))
    {
        rhs         = info[0].As<Napi::Number>().DoubleValue();
        auto result = rhs * lhs;
        return GLinearExpr::constructor.New({Napi::External<LinearExpr>::New(env, new LinearExpr(result))});
    }

    Napi::TypeError::New(env, "operations_research::operator_times : Invalid arguments").ThrowAsJavaScriptException();
    return env.Null();
}

Napi::Object FuncInit(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);

    exports.Set("operator_ge", Napi::Function::New(env, Goperator_ge));
    exports.Set("operator_eq", Napi::Function::New(env, Goperator_eq));
    exports.Set("operator_le", Napi::Function::New(env, Goperator_le));
    exports.Set("operator_times", Napi::Function::New(env, Goperator_times));

    return exports;
};

}; // namespace operations_research