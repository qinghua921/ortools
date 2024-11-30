#pragma once

#include "napi.h"
#include "ortools/packing/binpacking_2d_parser.h"
#include "MultipleDimensionsBinPackingShape.hpp"

namespace operations_research
{
namespace packing
{
class GMultipleDimensionsBinPackingItem : public Napi::ObjectWrap<GMultipleDimensionsBinPackingItem>
{
  public:
    static inline Napi::FunctionReference constructor;
    MultipleDimensionsBinPackingItem *pMultipleDimensionsBinPackingItem = nullptr;

    GMultipleDimensionsBinPackingItem(const Napi::CallbackInfo &info)
        : Napi::ObjectWrap<GMultipleDimensionsBinPackingItem>(info)
    {
        Napi::Env env = info.Env();

        if (info.Length() == 1 && info[0].IsExternal())
        {
            auto external                     = info[0].As<Napi::External<MultipleDimensionsBinPackingItem>>();
            pMultipleDimensionsBinPackingItem = dynamic_cast<MultipleDimensionsBinPackingItem *>(external.Data());
            if (pMultipleDimensionsBinPackingItem) return;
        }

        Napi::TypeError::New(env, "operations_research::GMultipleDimensionsBinPackingItem::GMultipleDimensionsBinPackingItem : Invalid arguments").ThrowAsJavaScriptException();
    };

    ~GMultipleDimensionsBinPackingItem()
    {
        if (pMultipleDimensionsBinPackingItem) delete pMultipleDimensionsBinPackingItem;
    };

    static Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        Napi::HandleScope scope(env);
        Napi::Function func = DefineClass(
            env,
            "MultipleDimensionsBinPackingItem",
            {
                InstanceMethod("shapes", &GMultipleDimensionsBinPackingItem::shapes),
                InstanceMethod("shapes_size", &GMultipleDimensionsBinPackingItem::shapes_size),
            }
        );
        constructor = Napi::Persistent(func);
        constructor.SuppressDestruct();
        exports.Set(Napi::String::New(env, "MultipleDimensionsBinPackingItem"), func);
        return exports;
    };

    //   int shapes_size() const;
    Napi::Value shapes_size(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        if (info.Length() == 0)
        {
            return Napi::Number::New(env, pMultipleDimensionsBinPackingItem->shapes_size());
        }

        Napi::TypeError::New(env, "operations_research::GMultipleDimensionsBinPackingItem::shapes_size : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    Napi::Value shapes(const Napi::CallbackInfo &info)
    {
        Napi::Env env = info.Env();
        Napi::HandleScope scope(env);

        //   const ::google::protobuf::RepeatedPtrField<::operations_research::packing::MultipleDimensionsBinPackingShape>& shapes() const;
        if (info.Length() == 0)
        {
            auto shapes        = pMultipleDimensionsBinPackingItem->shapes();
            Napi::Array result = Napi::Array::New(env, shapes.size());
            for (int i = 0; i < shapes.size(); i++)
            {
                auto external = Napi::External<MultipleDimensionsBinPackingShape>::New(env, new MultipleDimensionsBinPackingShape(shapes[i]));
                result.Set(i, GMultipleDimensionsBinPackingShape::constructor.New({external}));
            }
            return result;
        }

        //   const ::operations_research::packing::MultipleDimensionsBinPackingShape& shapes(int index) const;
        if (info.Length() == 1 && info[0].IsNumber())
        {
            int index     = info[0].As<Napi::Number>().Int32Value();
            auto shape    = pMultipleDimensionsBinPackingItem->shapes(index);
            auto external = Napi::External<MultipleDimensionsBinPackingShape>::New(env, new MultipleDimensionsBinPackingShape(shape));
            return GMultipleDimensionsBinPackingShape::constructor.New({external});
        }

        Napi::TypeError::New(env, "operations_research::GMultipleDimensionsBinPackingItem::shapes : Invalid arguments").ThrowAsJavaScriptException();
        return env.Null();
    }
};
}; // namespace packing
}; // namespace operations_research