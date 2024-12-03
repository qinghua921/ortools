#pragma once

#include "napi.h"
#include "ortools/routing/parsers/cvrptw_lib.h"

namespace operations_research
{
class GLocationContainer : public Napi::ObjectWrap<GLocationContainer>
{
  public:
    static inline Napi::FunctionReference constructor;
    LocationContainer *pLocationContainer = nullptr;

    GLocationContainer(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GLocationContainer>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external      = info[0].As<Napi::External<LocationContainer>>();
            pLocationContainer = dynamic_cast<LocationContainer *>(external.Data());
            if (pLocationContainer) return;
        }

        //  LocationContainer(int64_t speed, bool use_deterministic_seed);
        if (info.Length() == 2 && info[0].IsNumber() && info[1].IsBoolean())
        {
            int64_t speed               = info[0].As<Napi::Number>().Int64Value();
            bool use_deterministic_seed = info[1].As<Napi::Boolean>();
            pLocationContainer          = new LocationContainer(speed, use_deterministic_seed);
            return;
        }

        Napi::TypeError::New(env, "operations_research::GLocationContainer::GLocationContainer : Invalid arguments").ThrowAsJavaScriptException();
    };

    ~GLocationContainer()
    {
        if (pLocationContainer) delete pLocationContainer;
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);
        Napi::Function func = DefineClass(
            env,
            "LocationContainer",
            {
                InstanceMethod("ManhattanDistance", &GLocationContainer::ManhattanDistance),
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "LocationContainer"), func);
        return exports;
    };

    //  int64_t ManhattanDistance(RoutingIndexManager::NodeIndex from,
    //                            RoutingIndexManager::NodeIndex to) const;
    Napi::Value ManhattanDistance(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 2 && info[0].IsNumber() && info[1].IsNumber())
        {
            int64_t from = info[0].As<Napi::Number>().Int64Value();
            int64_t to   = info[1].As<Napi::Number>().Int64Value();
            return Napi::Number::New(env, pLocationContainer->ManhattanDistance(RoutingIndexManager::NodeIndex(from), RoutingIndexManager::NodeIndex(to)));
        }

        Napi::TypeError::New(env, "operations_research::GLocationContainer::ManhattanDistance : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };
};

}; // namespace operations_research