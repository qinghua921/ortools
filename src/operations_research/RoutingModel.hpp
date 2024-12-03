#pragma once

#include "CallBackManager.hpp"
#include "RoutingIndexManager.hpp"
#include "napi.h"
#include "ortools/constraint_solver/routing.h"

namespace operations_research
{
class GRoutingModel : public Napi::ObjectWrap<GRoutingModel>
{
  public:
    static inline Napi::FunctionReference constructor;
    RoutingModel *pRoutingModel = nullptr;

    GRoutingModel(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GRoutingModel>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external = info[0].As<Napi::External<RoutingModel>>();
            pRoutingModel = dynamic_cast<RoutingModel *>(external.Data());
            if (pRoutingModel) return;
        }

        //      explicit RoutingModel(const RoutingIndexManager& index_manager);
        if (info.Length() == 1 && info[0].IsObject() && info[0].As<Napi::Object>().InstanceOf(GRoutingIndexManager::constructor.Value()))
        {
            auto gRoutingIndexManager = Napi::ObjectWrap<GRoutingIndexManager>::Unwrap(info[0].As<Napi::Object>());
            pRoutingModel             = new RoutingModel(*gRoutingIndexManager->pRoutingIndexManager);
            return;
        }

        Napi::TypeError::New(env, "operations_research::GRoutingModel::GRoutingModel : Invalid arguments").ThrowAsJavaScriptException();
    };

    ~GRoutingModel()
    {
        if (pRoutingModel) delete pRoutingModel;
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);

        auto enumTransitEvaluatorSign = Napi::Object::New(env);
        enumTransitEvaluatorSign.Set(Napi::String::New(env, "kTransitEvaluatorSignUnknown"), Napi::Number::New(env, 0));
        enumTransitEvaluatorSign.Set(Napi::String::New(env, "kTransitEvaluatorSignPositiveOrZero"), Napi::Number::New(env, 1));
        enumTransitEvaluatorSign.Set(Napi::String::New(env, "kTransitEvaluatorSignNegativeOrZero"), Napi::Number::New(env, 2));

        Napi::Function func = DefineClass(
            env,
            "RoutingModel",
            {
                StaticValue("TransitEvaluatorSign", enumTransitEvaluatorSign),
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "RoutingModel"), func);
        return exports;
    };

    //      int RegisterTransitCallback(
    //          TransitCallback2 callback,
    //          TransitEvaluatorSign sign = kTransitEvaluatorSignUnknown);
    Napi::Value RegisterTransitCallback(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);
        static CallBackManager callBackManager;

        if (info.Length() == 1 && info[0].IsFunction())
        {
            callBackManager.insert(env, info[0].As<Napi::Function>());
            int sign  = 0;
            int index = pRoutingModel->RegisterTransitCallback(
                [env](int64_t from_index, int64_t to_index)
                {
                    Napi::HandleScope scope(env);
                    auto ret = callBackManager.call(env, {Napi::Number::New(env, from_index), Napi::Number::New(env, to_index)});
                    return ret.As<Napi::Number>().Int64Value();
                }
            );
            return Napi::Number::New(env, index);
        }

        if (info.Length() == 2 && info[0].IsFunction() && info[1].IsNumber())
        {
            callBackManager.insert(env, info[0].As<Napi::Function>());
            int sign  = info[1].As<Napi::Number>().Int32Value();
            int index = pRoutingModel->RegisterTransitCallback(
                [env](int64_t from_index, int64_t to_index)
                {
                    Napi::HandleScope scope(env);
                    auto ret = callBackManager.call(env, {Napi::Number::New(env, from_index), Napi::Number::New(env, to_index)});
                    return ret.As<Napi::Number>().Int64Value();
                },
                static_cast<RoutingModel::TransitEvaluatorSign>(sign)
            );
            return Napi::Number::New(env, index);
        }

        Napi::TypeError::New(env, "RoutingModel::RegisterTransitCallback : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

}; // namespace operations_research