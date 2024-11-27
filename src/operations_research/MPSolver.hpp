#pragma once

#include "MPObjective.hpp"
#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{
class GMPSolver : public Napi::ObjectWrap<GMPSolver>
{
  public:
    static inline Napi::FunctionReference constructor;
    MPSolver *pMPSolver = nullptr;

    GMPSolver(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GMPSolver>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external = info[0].As<Napi::External<MPSolver>>();
            pMPSolver     = dynamic_cast<MPSolver *>(external.Data());
            if (pMPSolver) return;
        }

        Napi::TypeError::New(env, "operations_research::GMPSolver::GMPSolver : Invalid arguments").ThrowAsJavaScriptException();
    };

    ~GMPSolver()
    {
        if (pMPSolver) delete pMPSolver;
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);

        auto enumResultStatus = Napi::Object::New(env);
        enumResultStatus.Set("OPTIMAL", static_cast<int>(MPSolver::ResultStatus::OPTIMAL));
        enumResultStatus.Set("FEASIBLE", static_cast<int>(MPSolver::ResultStatus::FEASIBLE));
        enumResultStatus.Set("INFEASIBLE", static_cast<int>(MPSolver::ResultStatus::INFEASIBLE));
        enumResultStatus.Set("UNBOUNDED", static_cast<int>(MPSolver::ResultStatus::UNBOUNDED));
        enumResultStatus.Set("ABNORMAL", static_cast<int>(MPSolver::ResultStatus::ABNORMAL));
        enumResultStatus.Set("MODEL_INVALID", static_cast<int>(MPSolver::ResultStatus::MODEL_INVALID));
        enumResultStatus.Set("NOT_SOLVED", static_cast<int>(MPSolver::ResultStatus::NOT_SOLVED));

        Napi::Function func = DefineClass(
            env,
            "MPSolver",
            {
                InstanceMethod("Solve", &GMPSolver::Solve),
                InstanceMethod("MutableObjective", &GMPSolver::MutableObjective),
                InstanceMethod("MakeRowConstraint", &GMPSolver::MakeRowConstraint),
                InstanceMethod("MakeBoolVar", &GMPSolver::MakeBoolVar),
                StaticMethod("CreateSolver", &GMPSolver::CreateSolver),
                StaticValue("ResultStatus", enumResultStatus),

            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "MPSolver"), func);
        return exports;
    };

    //     ResultStatus Solve();
    Napi::Value Solve(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            MPSolver::ResultStatus resultStatus = pMPSolver->Solve();
            return Napi::Number::New(env, static_cast<int>(resultStatus));
        }

        Napi::TypeError::New(env, "GMPSolver::Solve : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //     MPObjective *MutableObjective()
    Napi::Value MutableObjective(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            MPObjective *pMPObjective = pMPSolver->MutableObjective();
            auto external             = Napi::External<MPObjective>::New(env, pMPObjective);
            return GMPObjective::constructor.New({external});
        }

        Napi::TypeError::New(env, "GMPSolver::MutableObjective : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    Napi::Value MakeRowConstraint(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        //     MPConstraint *MakeRowConstraint(const LinearRange &range);
        if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GLinearRange::constructor.Value()))
        {
            auto pGLinearRange          = GLinearRange::Unwrap(info[0].As<Napi::Object>());
            MPConstraint *pMPConstraint = pMPSolver->MakeRowConstraint(*pGLinearRange->pLinearRange);
            auto eMPConstraint          = Napi::External<MPConstraint>::New(env, pMPConstraint);
            return GMPConstraint::constructor.New({eMPConstraint});
        }

        //     MPConstraint *MakeRowConstraint(double lb, double ub);
        if (info.Length() == 2 && info[0].IsNumber() && info[1].IsNumber())
        {
            double lb                   = info[0].As<Napi::Number>().DoubleValue();
            double ub                   = info[1].As<Napi::Number>().DoubleValue();
            MPConstraint *pMPConstraint = pMPSolver->MakeRowConstraint(lb, ub);
            auto eMPConstraint          = Napi::External<MPConstraint>::New(env, pMPConstraint);
            return GMPConstraint::constructor.New({eMPConstraint});
        }

        Napi::TypeError::New(env, "GMPConstraint::MakeRowConstraint : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //     MPVariable *MakeBoolVar(const std::string &name);
    Napi::Value MakeBoolVar(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsString())
        {
            std::string name        = info[0].As<Napi::String>().Utf8Value();
            MPVariable *pMPVariable = pMPSolver->MakeBoolVar(name);
            auto external           = Napi::External<MPVariable>::New(env, pMPVariable);
            return GMPVariable::constructor.New({external});
        }

        Napi::TypeError::New(env, "GMPVariable::MakeBoolVar : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //     static MPSolver *CreateSolver(const std::string &solver_id);
    static Napi::Value CreateSolver(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsString())
        {
            std::string solver_id = info[0].As<Napi::String>().Utf8Value();
            MPSolver *pMPSolver   = MPSolver::CreateSolver(solver_id);
            auto external         = Napi::External<MPSolver>::New(env, pMPSolver);
            return GMPSolver::constructor.New({external});
        }

        Napi::TypeError::New(env, "GMPSolver::CreateSolver : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };
};

}; // namespace operations_research