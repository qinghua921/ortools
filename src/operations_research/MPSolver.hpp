#pragma once

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
        Napi::Function func = DefineClass(
            env,
            "MPSolver",
            {
                StaticMethod("CreateSolver", &GMPSolver::CreateSolver),
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "MPSolver"), func);
        return exports;
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