#pragma once

#include "napi.h"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
class GModel : public Napi::ObjectWrap<GModel>
{
  public:
    static inline Napi::FunctionReference constructor;
    Model *pModel = nullptr;

    GModel(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GModel>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external = info[0].As<Napi::External<Model>>();
            pModel        = dynamic_cast<Model *>(external.Data());
            if (pModel) return;
        }

        //     Model() = default;
        if (info.Length() == 0)
        {
            pModel = new Model();
            return;
        }

        //     explicit Model(std::string name)
        if (info.Length() == 1 && info[0].IsString())
        {
            std::string name = info[0].As<Napi::String>();
            pModel           = new Model(name);
            return;
        }

        Napi::TypeError::New(env, "operations_research::GModel::GModel : Invalid arguments").ThrowAsJavaScriptException();
    };

    ~GModel()
    {
        if (pModel) delete pModel;
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);
        Napi::Function func = DefineClass(
            env, "Model", {}
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "Model"), func);
        return exports;
    };
};
}; // namespace sat
}; // namespace operations_research