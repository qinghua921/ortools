#pragma once

#include "MultipleDimensionsBinPackingItem.hpp"
#include "MultipleDimensionsBinPackingShape.hpp"
#include "napi.h"
#include "ortools/packing/binpacking_2d_parser.h"

namespace operations_research
{
namespace packing
{
class GMultipleDimensionsBinPackingProblem : public Napi::ObjectWrap<GMultipleDimensionsBinPackingProblem>
{
  public:
    static inline Napi::FunctionReference constructor;
    MultipleDimensionsBinPackingProblem *pMultipleDimensionsBinPackingProblem = nullptr;

    GMultipleDimensionsBinPackingProblem(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GMultipleDimensionsBinPackingProblem>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external                        = info[0].As<Napi::External<MultipleDimensionsBinPackingProblem>>();
            pMultipleDimensionsBinPackingProblem = dynamic_cast<MultipleDimensionsBinPackingProblem *>(external.Data());
            if (pMultipleDimensionsBinPackingProblem) return;
        }

        Napi::TypeError::New(env, "operations_research::GMultipleDimensionsBinPackingProblem::GMultipleDimensionsBinPackingProblem : Invalid arguments").ThrowAsJavaScriptException();
    };

    ~GMultipleDimensionsBinPackingProblem()
    {
        if (pMultipleDimensionsBinPackingProblem) delete pMultipleDimensionsBinPackingProblem;
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);
        Napi::Function func = DefineClass(
            env,
            "MultipleDimensionsBinPackingProblem",
            {
                InstanceMethod("items_size", &GMultipleDimensionsBinPackingProblem::items_size),
                InstanceMethod("items", &GMultipleDimensionsBinPackingProblem::items),
                InstanceMethod("box_shape", &GMultipleDimensionsBinPackingProblem::box_shape),
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "MultipleDimensionsBinPackingProblem"), func);
        return exports;
    };
    //   const ::operations_research::packing::MultipleDimensionsBinPackingShape& box_shape() const;
    Napi::Value box_shape(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            auto box_shape = pMultipleDimensionsBinPackingProblem->box_shape();
            auto external  = Napi::External<MultipleDimensionsBinPackingShape>::New(env, new MultipleDimensionsBinPackingShape(box_shape));
            return GMultipleDimensionsBinPackingShape::constructor.New({external});
        }

        Napi::TypeError::New(env, "operations_research::packing::GMultipleDimensionsBinPackingProblem::box_shape : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    Napi::Value items(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        //   const ::google::protobuf::RepeatedPtrField<::operations_research::packing::MultipleDimensionsBinPackingItem>& items() const;
        if (info.Length() == 0)
        {
            auto items         = pMultipleDimensionsBinPackingProblem->items();
            Napi::Array result = Napi::Array::New(env, items.size());
            for (int i = 0; i < items.size(); i++)
            {
                auto item     = items.Get(i);
                auto external = Napi::External<MultipleDimensionsBinPackingItem>::New(env, new MultipleDimensionsBinPackingItem(item));
                result.Set(i, GMultipleDimensionsBinPackingItem::constructor.New({external}));
            }
            return result;
        }

        //   const ::operations_research::packing::MultipleDimensionsBinPackingItem& items(int index) const;
        if (info.Length() == 1 && info[0].IsNumber())
        {
            int index     = info[0].As<Napi::Number>().Int32Value();
            auto item     = pMultipleDimensionsBinPackingProblem->items(index);
            auto external = Napi::External<MultipleDimensionsBinPackingItem>::New(env, new MultipleDimensionsBinPackingItem(item));
            return GMultipleDimensionsBinPackingItem::constructor.New({external});
        }

        Napi::TypeError::New(env, "operations_research::packing::GMultipleDimensionsBinPackingProblem::items : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };

    //   int items_size() const;
    Napi::Value items_size(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            return Napi::Number::New(env, pMultipleDimensionsBinPackingProblem->items_size());
        }

        Napi::TypeError::New(env, "items_size : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    };
};
}; // namespace packing
}; // namespace operations_research