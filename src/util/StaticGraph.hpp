#pragma once

#include "napi.h"
#include "ortools/graph/graph.h"

namespace util
{
class GStaticGraph : public Napi::ObjectWrap<GStaticGraph>
{
  public:
    static inline Napi::FunctionReference constructor;
    StaticGraph<> *pStaticGraph = nullptr;

    GStaticGraph(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GStaticGraph>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external = info[0].As<Napi::External<StaticGraph<>>>();
            pStaticGraph  = dynamic_cast<StaticGraph<> *>(external.Data());
            if (pStaticGraph) return;
        }

        if (info.Length() == 0)
        {
            pStaticGraph = new StaticGraph<>();
            return;
        }

        Napi::TypeError::New(env, "operations_research::GStaticGraph::GStaticGraph : Invalid arguments").ThrowAsJavaScriptException();
    };

    ~GStaticGraph()
    {
        if (pStaticGraph) delete pStaticGraph;
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);
        Napi::Function func = DefineClass(
            env,
            "StaticGraph",
            {
                InstanceMethod("AddArc", &GStaticGraph::AddArc),
                InstanceMethod("Build", &GStaticGraph::Build),
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "StaticGraph"), func);
        return exports;
    };
    // void Build(std::vector<ArcIndexType>* permutation);
    Napi::Value Build(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsArray())
        {
            auto permutation = info[0].As<Napi::Array>();
            std::vector<int32_t> perm;
            for (uint32_t i = 0; i < permutation.Length(); i++)
            {
                perm.push_back(permutation.Get(i).As<Napi::Number>().Int64Value());
            }
            pStaticGraph->Build(&perm);
            for (uint32_t i = 0; i < permutation.Length(); i++)
            {
                permutation.Set(i, Napi::Number::New(env, perm[i]));
            }
            return env.Undefined();
        }

        Napi::TypeError::New(env, "operations_research::GStaticGraph::Build : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };
    // ArcIndexType AddArc(NodeIndexType tail, NodeIndexType head);
    Napi::Value AddArc(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 2 && info[0].IsNumber() && info[1].IsNumber())
        {
            auto tail = info[0].As<Napi::Number>().Int64Value();
            auto head = info[1].As<Napi::Number>().Int64Value();
            auto arc  = pStaticGraph->AddArc(tail, head);
            return Napi::Number::New(env, arc);
        }

        Napi::TypeError::New(env, "operations_research::GStaticGraph::AddArc : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };
};

}; // namespace util