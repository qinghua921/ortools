#pragma once

#include <napi.h>
#include "commonheader.hpp"
#include "google/protobuf/repeated_ptr_field.h"

namespace google
{
namespace protobuf
{
    template < typename Element >
    class GRepeatedPtrField : public Napi::ObjectWrap< GRepeatedPtrField< Element > >
    {
    public:
        static Napi::FunctionReference constructor;
        RepeatedPtrField< Element >*   pRepeatedPtrField = nullptr;
        GRepeatedPtrField( const Napi::CallbackInfo& info );
        ~GRepeatedPtrField();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );

        Napi::Value size( const Napi::CallbackInfo& info );
        Napi::Value Get( const Napi::CallbackInfo& info );
    };
};  // namespace protobuf
};  // namespace google

template < typename Element >
Napi::FunctionReference google::protobuf::GRepeatedPtrField< Element >::constructor;

template < typename Element >
inline google::protobuf::GRepeatedPtrField< Element >::GRepeatedPtrField( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GRepeatedPtrField< Element > >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external     = info[ 0 ].As< Napi::External< RepeatedPtrField< Element > > >();
        pRepeatedPtrField = dynamic_cast< RepeatedPtrField< Element >* >( external.Data() );
        if ( pRepeatedPtrField != nullptr ) return;
    }

    ThrowJsError( google::protobuf::GRepeatedPtrField::GRepeatedPtrField : Invalid argument );
}

template < typename Element >
inline google::protobuf::GRepeatedPtrField< Element >::~GRepeatedPtrField()
{
    delete pRepeatedPtrField;
}

template < typename Element >
inline Napi::Object google::protobuf::GRepeatedPtrField< Element >::Init( Napi::Env env, Napi::Object exports )
{
    auto get_name = []() {
        if ( std::is_same< Element, operations_research::packing::GMultipleDimensionsBinPackingItem >::value )
            return "RepeatedPtrField_MultipleDimensionsBinPackingItem";
        else
            throw std::runtime_error( "google::protobuf::GRepeatedPtrField::Init : Invalid Typename Element" );
    };

    Napi::HandleScope scope( env );
    Napi::Function    func = GRepeatedPtrField< Element >::DefineClass(
        env, get_name(),
        {
            GRepeatedPtrField< Element >::InstanceMethod( "size", &GRepeatedPtrField< Element >::size ),
            GRepeatedPtrField< Element >::InstanceMethod( "Get", &GRepeatedPtrField< Element >::Get ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, get_name() ), func );
    return exports;
}

template < typename Element >
inline Napi::Value google::protobuf::GRepeatedPtrField< Element >::Get( const Napi::CallbackInfo& info )
{
    //         const Element& Get( int index ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        int index = info[ 0 ].As< Napi::Number >().Int32Value();
        if ( index >= 0 && index < pRepeatedPtrField->size() )
        {
            auto element  = pRepeatedPtrField->Get( index );
            auto external = Napi::External< Element >::New( info.Env(), new Element( element ) );
            return Element::constructor.New( { external } );
        }
    }

    ThrowJsError( google::protobuf::GRepeatedPtrField::Get : Invalid argument );
    return info.Env().Undefined();
}

template < typename Element >
inline Napi::Value google::protobuf::GRepeatedPtrField< Element >::size( const Napi::CallbackInfo& info )
{
    //         int  size() const;
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), pRepeatedPtrField->size() );
    }

    ThrowJsError( google::protobuf::GRepeatedPtrField::size : Invalid argument );
    return info.Env().Undefined();
}
