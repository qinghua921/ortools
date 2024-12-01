#pragma once

#include "Constraint.hpp"
#include "DecisionBuilder.hpp"
#include "IntVar.hpp"
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

        Napi::Object enumIntVarStrategy = Napi::Object::New(env);
        enumIntVarStrategy.Set(Napi::String::New(env, "INT_VAR_DEFAULT"), Napi::Number::New(env, static_cast<int>(Solver::INT_VAR_DEFAULT)));
        enumIntVarStrategy.Set(Napi::String::New(env, "INT_VAR_SIMPLE"), Napi::Number::New(env, static_cast<int>(Solver::INT_VAR_SIMPLE)));
        enumIntVarStrategy.Set(Napi::String::New(env, "CHOOSE_FIRST_UNBOUND"), Napi::Number::New(env, static_cast<int>(Solver::CHOOSE_FIRST_UNBOUND)));
        enumIntVarStrategy.Set(Napi::String::New(env, "CHOOSE_RANDOM"), Napi::Number::New(env, static_cast<int>(Solver::CHOOSE_RANDOM)));
        enumIntVarStrategy.Set(Napi::String::New(env, "CHOOSE_MIN_SIZE_LOWEST_MIN"), Napi::Number::New(env, static_cast<int>(Solver::CHOOSE_MIN_SIZE_LOWEST_MIN)));
        enumIntVarStrategy.Set(Napi::String::New(env, "CHOOSE_MIN_SIZE_HIGHEST_MIN"), Napi::Number::New(env, static_cast<int>(Solver::CHOOSE_MIN_SIZE_HIGHEST_MIN)));
        enumIntVarStrategy.Set(Napi::String::New(env, "CHOOSE_MIN_SIZE_LOWEST_MAX"), Napi::Number::New(env, static_cast<int>(Solver::CHOOSE_MIN_SIZE_LOWEST_MAX)));
        enumIntVarStrategy.Set(Napi::String::New(env, "CHOOSE_MIN_SIZE_HIGHEST_MAX"), Napi::Number::New(env, static_cast<int>(Solver::CHOOSE_MIN_SIZE_HIGHEST_MAX)));
        enumIntVarStrategy.Set(Napi::String::New(env, "CHOOSE_LOWEST_MIN"), Napi::Number::New(env, static_cast<int>(Solver::CHOOSE_LOWEST_MIN)));
        enumIntVarStrategy.Set(Napi::String::New(env, "CHOOSE_HIGHEST_MAX"), Napi::Number::New(env, static_cast<int>(Solver::CHOOSE_HIGHEST_MAX)));
        enumIntVarStrategy.Set(Napi::String::New(env, "CHOOSE_MIN_SIZE"), Napi::Number::New(env, static_cast<int>(Solver::CHOOSE_MIN_SIZE)));
        enumIntVarStrategy.Set(Napi::String::New(env, "CHOOSE_MAX_SIZE"), Napi::Number::New(env, static_cast<int>(Solver::CHOOSE_MAX_SIZE)));
        enumIntVarStrategy.Set(Napi::String::New(env, "CHOOSE_MAX_REGRET_ON_MIN"), Napi::Number::New(env, static_cast<int>(Solver::CHOOSE_MAX_REGRET_ON_MIN)));
        enumIntVarStrategy.Set(Napi::String::New(env, "CHOOSE_PATH"), Napi::Number::New(env, static_cast<int>(Solver::CHOOSE_PATH)));

        Napi::Object enumIntValueStrategy = Napi::Object::New(env);
        enumIntValueStrategy.Set(Napi::String::New(env, "INT_VALUE_DEFAULT"), Napi::Number::New(env, static_cast<int>(Solver::INT_VALUE_DEFAULT)));
        enumIntValueStrategy.Set(Napi::String::New(env, "INT_VALUE_SIMPLE"), Napi::Number::New(env, static_cast<int>(Solver::INT_VALUE_SIMPLE)));
        enumIntValueStrategy.Set(Napi::String::New(env, "ASSIGN_MIN_VALUE"), Napi::Number::New(env, static_cast<int>(Solver::ASSIGN_MIN_VALUE)));
        enumIntValueStrategy.Set(Napi::String::New(env, "ASSIGN_MAX_VALUE"), Napi::Number::New(env, static_cast<int>(Solver::ASSIGN_MAX_VALUE)));
        enumIntValueStrategy.Set(Napi::String::New(env, "ASSIGN_RANDOM_VALUE"), Napi::Number::New(env, static_cast<int>(Solver::ASSIGN_RANDOM_VALUE)));
        enumIntValueStrategy.Set(Napi::String::New(env, "ASSIGN_CENTER_VALUE"), Napi::Number::New(env, static_cast<int>(Solver::ASSIGN_CENTER_VALUE)));
        enumIntValueStrategy.Set(Napi::String::New(env, "SPLIT_LOWER_HALF"), Napi::Number::New(env, static_cast<int>(Solver::SPLIT_LOWER_HALF)));
        enumIntValueStrategy.Set(Napi::String::New(env, "SPLIT_UPPER_HALF"), Napi::Number::New(env, static_cast<int>(Solver::SPLIT_UPPER_HALF)));

        Napi::Function func = DefineClass(
            env,
            "Solver",
            {
                StaticValue("IntVarStrategy", enumIntVarStrategy),
                StaticValue("IntValueStrategy", enumIntValueStrategy),
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

            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "Solver"), func);
        return exports;
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