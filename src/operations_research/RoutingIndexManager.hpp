#pragma once

#include "napi.h"
#include "ortools/constraint_solver/routing.h"

namespace operations_research
{
class GRoutingIndexManager : public Napi::ObjectWrap<GRoutingIndexManager>
{
  public:
    static inline Napi::FunctionReference constructor;
    RoutingIndexManager *pRoutingIndexManager = nullptr;

    GRoutingIndexManager(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GRoutingIndexManager>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external        = info[0].As<Napi::External<RoutingIndexManager>>();
            pRoutingIndexManager = dynamic_cast<RoutingIndexManager *>(external.Data());
            if (pRoutingIndexManager) return;
        }

        //  RoutingIndexManager(int num_nodes, int num_vehicles, NodeIndex depot);
        if (info.Length() == 3 && info[0].IsNumber() && info[1].IsNumber() && info[2].IsNumber())
        {
            int num_nodes        = info[0].As<Napi::Number>().Int32Value();
            int num_vehicles     = info[1].As<Napi::Number>().Int32Value();
            int depot            = info[2].As<Napi::Number>().Int32Value();
            pRoutingIndexManager = new RoutingIndexManager(num_nodes, num_vehicles, RoutingIndexManager::NodeIndex(depot));
            return;
        }

        Napi::TypeError::New(env, "operations_research::GRoutingIndexManager::GRoutingIndexManager : Invalid arguments").ThrowAsJavaScriptException();
    };

    ~GRoutingIndexManager()
    {
        if (pRoutingIndexManager) delete pRoutingIndexManager;
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);
        Napi::Function func = DefineClass(
            env,
            "RoutingIndexManager",
            {
                InstanceMethod("IndexToNode", &GRoutingIndexManager::IndexToNode),
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "RoutingIndexManager"), func);
        return exports;
    };

    //  NodeIndex IndexToNode(int64_t index) ;
    Napi::Value IndexToNode(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 1 && info[0].IsNumber())
        {
            int64_t index   = info[0].As<Napi::Number>().Int64Value();
            auto node_index = pRoutingIndexManager->IndexToNode(index);
            return Napi::Number::New(env, node_index.value());
        }

        Napi::TypeError::New(env, "operations_research::GRoutingIndexManager::IndexToNode : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };
};

}; // namespace operations_research