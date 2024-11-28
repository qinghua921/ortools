#pragma once

#include "napi.h"
#include "ortools/graph/min_cost_flow.h"

namespace operations_research
{
class GSimpleMinCostFlow : public Napi::ObjectWrap<GSimpleMinCostFlow>
{
  public:
    static inline Napi::FunctionReference constructor;
    SimpleMinCostFlow *pSimpleMinCostFlow = nullptr;

    GSimpleMinCostFlow(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GSimpleMinCostFlow>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external      = info[0].As<Napi::External<SimpleMinCostFlow>>();
            pSimpleMinCostFlow = dynamic_cast<SimpleMinCostFlow *>(external.Data());
            if (pSimpleMinCostFlow) return;
        }

        if (info.Length() == 0)
        {
            pSimpleMinCostFlow = new SimpleMinCostFlow();
            return;
        }

        Napi::TypeError::New(env, "operations_research::GSimpleMinCostFlow::GSimpleMinCostFlow : Invalid arguments").ThrowAsJavaScriptException();
    };

    ~GSimpleMinCostFlow()
    {
        if (pSimpleMinCostFlow) delete pSimpleMinCostFlow;
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);

        auto enumStatus = Napi::Object::New(env);
        enumStatus.Set(Napi::String::New(env, "NOT_SOLVED"), Napi::Number::New(env, SimpleMinCostFlow::NOT_SOLVED));
        enumStatus.Set(Napi::String::New(env, "OPTIMAL"), Napi::Number::New(env, SimpleMinCostFlow::OPTIMAL));
        enumStatus.Set(Napi::String::New(env, "FEASIBLE"), Napi::Number::New(env, SimpleMinCostFlow::FEASIBLE));
        enumStatus.Set(Napi::String::New(env, "INFEASIBLE"), Napi::Number::New(env, SimpleMinCostFlow::INFEASIBLE));
        enumStatus.Set(Napi::String::New(env, "UNBALANCED"), Napi::Number::New(env, SimpleMinCostFlow::UNBALANCED));
        enumStatus.Set(Napi::String::New(env, "BAD_RESULT"), Napi::Number::New(env, SimpleMinCostFlow::BAD_RESULT));
        enumStatus.Set(Napi::String::New(env, "BAD_COST_RANGE"), Napi::Number::New(env, SimpleMinCostFlow::BAD_COST_RANGE));

        Napi::Function func = DefineClass(
            env,
            "SimpleMinCostFlow",
            {
                StaticValue("Status", enumStatus),
                InstanceMethod("AddArcWithCapacityAndUnitCost", &GSimpleMinCostFlow::AddArcWithCapacityAndUnitCost),
                InstanceMethod("SetNodeSupply", &GSimpleMinCostFlow::SetNodeSupply),
                InstanceMethod("OptimalCost", &GSimpleMinCostFlow::OptimalCost),
                InstanceMethod("NumArcs", &GSimpleMinCostFlow::NumArcs),
                InstanceMethod("Tail", &GSimpleMinCostFlow::Tail),
                InstanceMethod("Head", &GSimpleMinCostFlow::Head),
                InstanceMethod("Flow", &GSimpleMinCostFlow::Flow),
                InstanceMethod("UnitCost", &GSimpleMinCostFlow::UnitCost),
                InstanceMethod("Solve", &GSimpleMinCostFlow::Solve),
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "SimpleMinCostFlow"), func);
        return exports;
    };

    //    CostValue UnitCost(ArcIndex arc) const;
    Napi::Value UnitCost(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsNumber())
        {
            ArcIndex arc   = info[0].As<Napi::Number>().Int32Value();
            auto unit_cost = pSimpleMinCostFlow->UnitCost(arc);
            return Napi::Number::New(env, unit_cost);
        }

        Napi::TypeError::New(env, "operations_research::GSimpleMinCostFlow::UnitCost : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //    NodeIndex Head(ArcIndex arc) const;
    Napi::Value Head(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsNumber())
        {
            ArcIndex arc   = info[0].As<Napi::Number>().Int32Value();
            NodeIndex head = pSimpleMinCostFlow->Head(arc);
            return Napi::Number::New(env, head);
        }

        Napi::TypeError::New(env, "operations_research::GSimpleMinCostFlow::Head : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //    FlowQuantity Flow(ArcIndex arc) const;
    Napi::Value Flow(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsNumber())
        {
            ArcIndex arc      = info[0].As<Napi::Number>().Int32Value();
            FlowQuantity flow = pSimpleMinCostFlow->Flow(arc);
            return Napi::Number::New(env, flow);
        }

        Napi::TypeError::New(env, "operations_research::GSimpleMinCostFlow::Flow : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //    NodeIndex Tail(ArcIndex arc) const;
    Napi::Value Tail(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsNumber())
        {
            ArcIndex arc   = info[0].As<Napi::Number>().Int32Value();
            NodeIndex tail = pSimpleMinCostFlow->Tail(arc);
            return Napi::Number::New(env, tail);
        }

        Napi::TypeError::New(env, "operations_research::GSimpleMinCostFlow::Tail : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //    ArcIndex NumArcs() const;
    Napi::Value NumArcs(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            auto num_arcs = pSimpleMinCostFlow->NumArcs();
            return Napi::Number::New(env, num_arcs);
        }

        Napi::TypeError::New(env, "operations_research::GSimpleMinCostFlow::NumArcs : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //    CostValue OptimalCost() const;
    Napi::Value OptimalCost(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            auto optimal_cost = pSimpleMinCostFlow->OptimalCost();
            return Napi::Number::New(env, optimal_cost);
        }

        Napi::TypeError::New(env, "operations_research::GSimpleMinCostFlow::OptimalCost : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //    Status Solve()
    Napi::Value Solve(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            auto status = pSimpleMinCostFlow->Solve();
            return Napi::Number::New(env, status);
        }

        Napi::TypeError::New(env, "operations_research::GSimpleMinCostFlow::Solve : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //    void SetNodeSupply(NodeIndex node, FlowQuantity supply);
    Napi::Value SetNodeSupply(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 2 && info[0].IsNumber() && info[1].IsNumber())
        {
            NodeIndex node      = info[0].As<Napi::Number>().Int32Value();
            FlowQuantity supply = info[1].As<Napi::Number>().Int32Value();
            pSimpleMinCostFlow->SetNodeSupply(node, supply);
            return env.Null();
        }

        Napi::TypeError::New(env, "operations_research::GSimpleMinCostFlow::SetNodeSupply : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //    ArcIndex AddArcWithCapacityAndUnitCost(NodeIndex tail, NodeIndex head, FlowQuantity capacity, CostValue unit_cost);
    Napi::Value AddArcWithCapacityAndUnitCost(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 4 && info[0].IsNumber() && info[1].IsNumber() && info[2].IsNumber() && info[3].IsNumber())
        {
            NodeIndex tail        = info[0].As<Napi::Number>().Int32Value();
            NodeIndex head        = info[1].As<Napi::Number>().Int32Value();
            FlowQuantity capacity = info[2].As<Napi::Number>().Int32Value();
            CostValue unit_cost   = info[3].As<Napi::Number>().Int32Value();

            ArcIndex arc_index    = pSimpleMinCostFlow->AddArcWithCapacityAndUnitCost(tail, head, capacity, unit_cost);
            return Napi::Number::New(env, arc_index);
        }

        Napi::TypeError::New(env, "operations_research::GSimpleMinCostFlow::AddArcWithCapacityAndUnitCost : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };
};

}; // namespace operations_research