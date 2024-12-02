#pragma once

#include "Constraint.hpp"
#include "DecisionBuilder.hpp"
#include "IntExpr.hpp"
#include "Intvar.hpp"
#include "napi.h"
#include "ortools/constraint_solver/constraint_solver.h"

namespace operations_research
{
class GSolver : public Napi::ObjectWrap<GSolver>
{
  public:
    static inline Napi::FunctionReference constructor;
    Solver *pSolver = nullptr;

    GSolver(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GSolver>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external = info[0].As<Napi::External<Solver>>();
            pSolver       = dynamic_cast<Solver *>(external.Data());
            if (pSolver) return;
        }

        //      explicit Solver(const std::string& name);
        if (info.Length() == 1 && info[0].IsString())
        {
            std::string name = info[0].As<Napi::String>();
            pSolver          = new Solver(name);
            return;
        }

        Napi::TypeError::New(env, "operations_research::GSolver::GSolver : Invalid arguments").ThrowAsJavaScriptException();
    };

    ~GSolver()
    {
        if (pSolver) delete pSolver;
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);

        Napi::Function func = DefineClass(
            env,
            "Solver",
            {
                StaticValue("INT_VAR_DEFAULT", Napi::Number::New(env, Solver::INT_VAR_DEFAULT)),
                StaticValue("INT_VAR_SIMPLE", Napi::Number::New(env, Solver::INT_VAR_SIMPLE)),
                StaticValue("CHOOSE_FIRST_UNBOUND", Napi::Number::New(env, Solver::CHOOSE_FIRST_UNBOUND)),
                StaticValue("CHOOSE_RANDOM", Napi::Number::New(env, Solver::CHOOSE_RANDOM)),
                StaticValue("CHOOSE_MIN_SIZE_LOWEST_MIN", Napi::Number::New(env, Solver::CHOOSE_MIN_SIZE_LOWEST_MIN)),
                StaticValue("CHOOSE_MIN_SIZE_HIGHEST_MIN", Napi::Number::New(env, Solver::CHOOSE_MIN_SIZE_HIGHEST_MIN)),
                StaticValue("CHOOSE_MIN_SIZE_LOWEST_MAX", Napi::Number::New(env, Solver::CHOOSE_MIN_SIZE_LOWEST_MAX)),
                StaticValue("CHOOSE_MIN_SIZE_HIGHEST_MAX", Napi::Number::New(env, Solver::CHOOSE_MIN_SIZE_HIGHEST_MAX)),
                StaticValue("CHOOSE_LOWEST_MIN", Napi::Number::New(env, Solver::CHOOSE_LOWEST_MIN)),
                StaticValue("CHOOSE_HIGHEST_MAX", Napi::Number::New(env, Solver::CHOOSE_HIGHEST_MAX)),
                StaticValue("CHOOSE_MIN_SIZE", Napi::Number::New(env, Solver::CHOOSE_MIN_SIZE)),
                StaticValue("CHOOSE_MAX_SIZE", Napi::Number::New(env, Solver::CHOOSE_MAX_SIZE)),
                StaticValue("CHOOSE_MAX_REGRET_ON_MIN", Napi::Number::New(env, Solver::CHOOSE_MAX_REGRET_ON_MIN)),
                StaticValue("CHOOSE_PATH", Napi::Number::New(env, Solver::CHOOSE_PATH)),

                StaticValue("INT_VALUE_DEFAULT", Napi::Number::New(env, Solver::INT_VALUE_DEFAULT)),
                StaticValue("INT_VALUE_SIMPLE", Napi::Number::New(env, Solver::INT_VALUE_SIMPLE)),
                StaticValue("ASSIGN_MIN_VALUE", Napi::Number::New(env, Solver::ASSIGN_MIN_VALUE)),
                StaticValue("ASSIGN_MAX_VALUE", Napi::Number::New(env, Solver::ASSIGN_MAX_VALUE)),
                StaticValue("ASSIGN_RANDOM_VALUE", Napi::Number::New(env, Solver::ASSIGN_RANDOM_VALUE)),
                StaticValue("ASSIGN_CENTER_VALUE", Napi::Number::New(env, Solver::ASSIGN_CENTER_VALUE)),
                StaticValue("SPLIT_LOWER_HALF", Napi::Number::New(env, Solver::SPLIT_LOWER_HALF)),
                StaticValue("SPLIT_UPPER_HALF", Napi::Number::New(env, Solver::SPLIT_UPPER_HALF)),

                InstanceMethod("MakeIntVar", &GSolver::MakeIntVar),
                InstanceMethod("MakeAllDifferent", &GSolver::MakeAllDifferent),
                InstanceMethod("AddConstraint", &GSolver::AddConstraint),
                InstanceMethod("constraints", &GSolver::constraints),
                InstanceMethod("MakePhase", &GSolver::MakePhase),
                InstanceMethod("NewSearch", &GSolver::NewSearch),
                InstanceMethod("NextSolution", &GSolver::NextSolution),
                InstanceMethod("EndSearch", &GSolver::EndSearch),
                InstanceMethod("solutions", &GSolver::solutions),
                InstanceMethod("wall_time", &GSolver::wall_time),
                StaticMethod("MemoryUsage", &GSolver::MemoryUsage),
                InstanceMethod("MakeSum", &GSolver::MakeSum),
                InstanceMethod("MakeProd", &GSolver::MakeProd),
                InstanceMethod("MakeScalProd", &GSolver::MakeScalProd),
                InstanceMethod("MakeEquality", &GSolver::MakeEquality),
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "Solver"), func);
        return exports;
    };

    Napi::Value MakeEquality(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        //      Constraint* MakeEquality(IntExpr* left, IntExpr* right);
        IntExpr *pExprLeft  = GIntExpr::ToIntExpr(info[0]);
        IntExpr *pExprRight = GIntExpr::ToIntExpr(info[1]);
        if (info.Length() == 2 && pExprLeft && pExprRight)
        {
            Constraint *pCons = pSolver->MakeEquality(pExprLeft, pExprRight);
            auto external     = Napi::External<Constraint>::New(env, pCons);
            return GConstraint::constructor.New({external});
        }
        //      Constraint* MakeEquality(IntExpr* expr, int64_t value);
        //      Constraint* MakeEquality(IntExpr* expr, int value);
        if (info.Length() == 2 && pExprLeft && info[1].IsNumber())
        {
            int64_t value = info[1].As<Napi::Number>().Int64Value();
            Constraint *pCons = pSolver->MakeEquality(pExprLeft, value);
            auto external     = Napi::External<Constraint>::New(env, pCons);
            return GConstraint::constructor.New({external});
        }
        
        Napi::TypeError::New(env, "operations_research::GSolver::MakeEquality : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };
    //      IntExpr* MakeScalProd(const std::vector<IntVar*>& vars, const std::vector<int>& coefs);
    Napi::Value MakeScalProd(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 2 && info[0].IsArray() && info[1].IsArray())
        {
            std::vector<IntVar *> vars;
            Napi::Array array = info[0].As<Napi::Array>();
            for (uint32_t i = 0; i < array.Length(); i++)
            {
                if (array.Get(i).IsObject() && array.Get(i).As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()))
                {
                    auto gIntVar = Napi::ObjectWrap<GIntVar>::Unwrap(array.Get(i).As<Napi::Object>());
                    vars.push_back(gIntVar->pIntVar);
                    continue;
                }

                Napi::TypeError::New(env, "operations_research::GSolver::MakeScalProd : Invalid arguments").ThrowAsJavaScriptException();
                return env.Null();
            }

            std::vector<int64_t> coefs;
            Napi::Array array2 = info[1].As<Napi::Array>();
            for (uint32_t i = 0; i < array2.Length(); i++)
            {
                if (array2.Get(i).IsNumber())
                {
                    coefs.push_back(array2.Get(i).As<Napi::Number>().Int64Value());
                    continue;
                }

                Napi::TypeError::New(env, "operations_research::GSolver::MakeScalProd : Invalid arguments").ThrowAsJavaScriptException();
                return env.Null();
            }

            IntExpr *pExpr = pSolver->MakeScalProd(vars, coefs);
            auto external  = Napi::External<IntExpr>::New(env, pExpr);
            return GIntExpr::constructor.New({external});
        }

        Napi::TypeError::New(env, "operations_research::GSolver::MakeScalProd : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //      IntExpr* MakeProd(IntExpr* expr, int64_t value);
    Napi::Value MakeProd(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 2 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GIntExpr::constructor.Value()) && info[1].IsNumber())
        {
            auto gIntExpr  = Napi::ObjectWrap<GIntExpr>::Unwrap(info[0].As<Napi::Object>());
            int64_t value  = info[1].As<Napi::Number>().Int64Value();
            IntExpr *pExpr = pSolver->MakeProd(gIntExpr->pIntExpr, value);
            auto external  = Napi::External<IntExpr>::New(env, pExpr);
            return GIntExpr::constructor.New({external});
        }
        if (info.Length() == 2 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()) && info[1].IsNumber())
        {
            auto gIntExpr  = Napi::ObjectWrap<GIntVar>::Unwrap(info[0].As<Napi::Object>());
            int64_t value  = info[1].As<Napi::Number>().Int64Value();
            IntExpr *pExpr = pSolver->MakeProd(gIntExpr->pIntVar, value);
            auto external  = Napi::External<IntExpr>::New(env, pExpr);
            return GIntVar::constructor.New({external});
        }

        Napi::TypeError::New(env, "operations_research::GSolver::MakeProd : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    Napi::Value MakeSum(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        //      IntExpr* MakeSum(IntExpr* expr, int64_t value);
        IntExpr *pExpr = GIntExpr::ToIntExpr(info[0]);
        if (info.Length() == 2 && pExpr && info[1].IsNumber())
        {
            int64_t value  = info[1].As<Napi::Number>().Int64Value();
            IntExpr *pExpr = pSolver->MakeSum(pExpr, value);
            auto external  = Napi::External<IntExpr>::New(env, pExpr);
            return GIntExpr::constructor.New({external});
        }

        //      IntExpr* MakeSum(IntExpr* left, IntExpr* right);
        IntExpr *pExprLeft  = GIntExpr::ToIntExpr(info[0]);
        IntExpr *pExprRight = GIntExpr::ToIntExpr(info[1]);
        if (info.Length() == 2 && pExprLeft && pExprRight)
        {
            IntExpr *pExpr = pSolver->MakeSum(pExprLeft, pExprRight);
            auto external  = Napi::External<IntExpr>::New(env, pExpr);
            return GIntExpr::constructor.New({external});
        }

        Napi::TypeError::New(env, "operations_research::GSolver::MakeSum : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };
    //      static int64_t MemoryUsage();
    static Napi::Value MemoryUsage(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            return Napi::Number::New(env, Solver::MemoryUsage());
        }

        Napi::TypeError::New(env, "operations_research::GSolver::MemoryUsage : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //      int64_t wall_time() const;
    Napi::Value wall_time(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            return Napi::Number::New(env, pSolver->wall_time());
        }

        Napi::TypeError::New(env, "operations_research::GSolver::wall_time : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };
    //      int64_t solutions() const;
    Napi::Value solutions(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            return Napi::Number::New(env, pSolver->solutions());
        }

        Napi::TypeError::New(env, "operations_research::GSolver::solutions : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //      void EndSearch();
    Napi::Value EndSearch(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            pSolver->EndSearch();
            return env.Undefined();
        }

        Napi::TypeError::New(env, "operations_research::GSolver::EndSearch : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //      bool NextSolution();
    Napi::Value NextSolution(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            return Napi::Boolean::New(env, pSolver->NextSolution());
        }

        Napi::TypeError::New(env, "operations_research::GSolver::NextSolution : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars, IntVarStrategy var_str, IntValueStrategy val_str);
    Napi::Value MakePhase(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 3 && info[0].IsArray() && info[1].IsNumber() && info[2].IsNumber())
        {
            std::vector<IntVar *> vars;
            Napi::Array array = info[0].As<Napi::Array>();
            for (uint32_t i = 0; i < array.Length(); i++)
            {
                if (array.Get(i).IsObject() && array.Get(i).As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()))
                {
                    auto gIntVar = Napi::ObjectWrap<GIntVar>::Unwrap(array.Get(i).As<Napi::Object>());
                    vars.push_back(gIntVar->pIntVar);
                    continue;
                }

                Napi::TypeError::New(env, "operations_research::GSolver::MakePhase : Invalid arguments").ThrowAsJavaScriptException();
                return env.Null();
            }
            DecisionBuilder *pPhase = pSolver->MakePhase(
                vars,
                static_cast<Solver::IntVarStrategy>(info[1].As<Napi::Number>().Int32Value()),
                static_cast<Solver::IntValueStrategy>(info[2].As<Napi::Number>().Int32Value())
            );
            auto external = Napi::External<DecisionBuilder>::New(env, pPhase);
            return GDecisionBuilder::constructor.New({external});
        }

        Napi::TypeError::New(env, "operations_research::GSolver::MakePhase : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //      void NewSearch(DecisionBuilder* db);
    Napi::Value NewSearch(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GDecisionBuilder::constructor.Value()))
        {
            auto gDecisionBuilder = Napi::ObjectWrap<GDecisionBuilder>::Unwrap(info[0].As<Napi::Object>());
            pSolver->NewSearch(gDecisionBuilder->pDecisionBuilder);
            return env.Undefined();
        }

        Napi::TypeError::New(env, "operations_research::GSolver::NewSearch : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //      int constraints() ;
    Napi::Value constraints(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            return Napi::Number::New(env, pSolver->constraints());
        }

        Napi::TypeError::New(env, "operations_research::GSolver::constraints : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //      void AddConstraint(Constraint* c);
    Napi::Value AddConstraint(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GConstraint::constructor.Value()))
        {
            auto gConstraint = Napi::ObjectWrap<GConstraint>::Unwrap(info[0].As<Napi::Object>());
            pSolver->AddConstraint(gConstraint->pConstraint);
            return env.Null();
        }

        Napi::TypeError::New(env, "operations_research::GSolver::AddConstraint : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };
    //      Constraint* MakeAllDifferent(const std::vector<IntVar*>& vars);
    Napi::Value MakeAllDifferent(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsArray())
        {
            std::vector<IntVar *> vars;
            Napi::Array array = info[0].As<Napi::Array>();
            for (uint32_t i = 0; i < array.Length(); i++)
            {
                if (array.Get(i).IsObject() && array.Get(i).As<Napi::Object>().InstanceOf(GIntVar::constructor.Value()))
                {
                    auto gIntVar = Napi::ObjectWrap<GIntVar>::Unwrap(array.Get(i).As<Napi::Object>());
                    vars.push_back(gIntVar->pIntVar);
                    continue;
                }

                Napi::TypeError::New(env, "operations_research::GSolver::MakeAllDifferent : Invalid arguments").ThrowAsJavaScriptException();
                return env.Null();
            }
            Constraint *pConstraint = pSolver->MakeAllDifferent(vars);
            return GConstraint::constructor.New({Napi::External<Constraint>::New(env, pConstraint)});
        }

        Napi::TypeError::New(env, "operations_research::GSolver::MakeAllDifferent : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    Napi::Value MakeIntVar(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        //      IntVar* MakeIntVar(int64_t min, int64_t max, const std::string& name);
        if (info.Length() == 3 && info[0].IsNumber() && info[1].IsNumber() && info[2].IsString())
        {
            int64_t min      = info[0].As<Napi::Number>().Int64Value();
            int64_t max      = info[1].As<Napi::Number>().Int64Value();
            std::string name = info[2].As<Napi::String>();
            IntVar *pIntVar  = pSolver->MakeIntVar(min, max, name);
            auto external    = Napi::External<IntVar>::New(env, pIntVar);
            return GIntVar::constructor.New({external});
        }

        //      IntVar* MakeIntVar(const std::vector<int64_t>& values, const std::string& name);
        if (info.Length() == 2 && info[0].IsArray() && info[1].IsString())
        {
            std::vector<int64_t> values;
            Napi::Array array = info[0].As<Napi::Array>();
            for (uint32_t i = 0; i < array.Length(); i++)
            {
                values.push_back(array.Get(i).As<Napi::Number>().Int64Value());
            }
            std::string name = info[1].As<Napi::String>();
            IntVar *pIntVar  = pSolver->MakeIntVar(values, name);
            auto external    = Napi::External<IntVar>::New(env, pIntVar);
            return GIntVar::constructor.New({external});
        }

        Napi::TypeError::New(env, "operations_research::GSolver::MakeIntVar : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };
};

}; // namespace operations_research