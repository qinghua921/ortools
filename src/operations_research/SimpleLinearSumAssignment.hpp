#pragma once

#include "napi.h"
#include "ortools/graph/assignment.h"

namespace operations_research
{
class GSimpleLinearSumAssignment : public Napi::ObjectWrap<GSimpleLinearSumAssignment>
{
  public:
    static inline Napi::FunctionReference constructor;
    SimpleLinearSumAssignment *pSimpleLinearSumAssignment = nullptr;

    GSimpleLinearSumAssignment(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GSimpleLinearSumAssignment>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external              = info[0].As<Napi::External<SimpleLinearSumAssignment>>();
            pSimpleLinearSumAssignment = dynamic_cast<SimpleLinearSumAssignment *>(external.Data());
            if (pSimpleLinearSumAssignment) return;
        }

        //    SimpleLinearSumAssignment();
        if (info.Length() == 0)
        {
            pSimpleLinearSumAssignment = new SimpleLinearSumAssignment();
            return;
        }

        Napi::TypeError::New(env, "operations_research::GSimpleLinearSumAssignment::GSimpleLinearSumAssignment : Invalid arguments").ThrowAsJavaScriptException();
    };

    ~GSimpleLinearSumAssignment()
    {
        if (pSimpleLinearSumAssignment) delete pSimpleLinearSumAssignment;
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);

        auto enumStatus = Napi::Object::New(env);
        enumStatus.Set(Napi::String::New(env, "OPTIMAL"), Napi::Number::New(env, SimpleLinearSumAssignment::OPTIMAL));
        enumStatus.Set(Napi::String::New(env, "INFEASIBLE"), Napi::Number::New(env, SimpleLinearSumAssignment::INFEASIBLE));
        enumStatus.Set(Napi::String::New(env, "POSSIBLE_OVERFLOW"), Napi::Number::New(env, SimpleLinearSumAssignment::POSSIBLE_OVERFLOW));

        Napi::Function func = DefineClass(
            env,
            "SimpleLinearSumAssignment",
            {
                StaticValue("Status", enumStatus),
                InstanceMethod("AddArcWithCost", &GSimpleLinearSumAssignment::AddArcWithCost),
                InstanceMethod("Solve", &GSimpleLinearSumAssignment::Solve),
                InstanceMethod("OptimalCost", &GSimpleLinearSumAssignment::OptimalCost),
                InstanceMethod("RightMate", &GSimpleLinearSumAssignment::RightMate),
                InstanceMethod("AssignmentCost", &GSimpleLinearSumAssignment::AssignmentCost),
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "SimpleLinearSumAssignment"), func);
        return exports;
    };
    
    //    CostValue AssignmentCost(NodeIndex left_node) const
    Napi::Value AssignmentCost(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsNumber())
        {
            NodeIndex left_node = info[0].As<Napi::Number>().Int32Value();
            CostValue cost      = pSimpleLinearSumAssignment->AssignmentCost(left_node);
            return Napi::Number::New(env, cost);
        }

        Napi::TypeError::New(env, "operations_research::GSimpleLinearSumAssignment::AssignmentCost : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //    NodeIndex RightMate(NodeIndex left_node) const
    Napi::Value RightMate(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsNumber())
        {
            NodeIndex left_node  = info[0].As<Napi::Number>().Int32Value();
            NodeIndex right_node = pSimpleLinearSumAssignment->RightMate(left_node);
            return Napi::Number::New(env, right_node);
        }

        Napi::TypeError::New(env, "operations_research::GSimpleLinearSumAssignment::RightMate : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };
    //    CostValue OptimalCost() const
    Napi::Value OptimalCost(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            auto optimal_cost = pSimpleLinearSumAssignment->OptimalCost();
            return Napi::Number::New(env, optimal_cost);
        }

        Napi::TypeError::New(env, "operations_research::GSimpleLinearSumAssignment::OptimalCost : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //    Status Solve();
    Napi::Value Solve(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            auto status = pSimpleLinearSumAssignment->Solve();
            return Napi::Number::New(env, status);
        }

        Napi::TypeError::New(env, "operations_research::GSimpleLinearSumAssignment::Solve : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //    ArcIndex AddArcWithCost(NodeIndex left_node, NodeIndex right_node, CostValue cost);
    Napi::Value AddArcWithCost(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 3 && info[0].IsNumber() && info[1].IsNumber() && info[2].IsNumber())
        {
            NodeIndex left_node  = info[0].As<Napi::Number>().Int32Value();
            NodeIndex right_node = info[1].As<Napi::Number>().Int32Value();
            CostValue cost       = info[2].As<Napi::Number>().Int32Value();

            ArcIndex arc_index   = pSimpleLinearSumAssignment->AddArcWithCost(left_node, right_node, cost);
            return Napi::Number::New(env, arc_index);
        }

        Napi::TypeError::New(env, "operations_research::GSimpleLinearSumAssignment::AddArcWithCost : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };
};

}; // namespace operations_research