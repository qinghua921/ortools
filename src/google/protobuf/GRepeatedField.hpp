#pragma once


#include "commonheader.hpp"
#include "google/protobuf/repeated_field.h"

namespace google
{
namespace protobuf
{
    template < typename Element >
    class GRepeatedField : public Napi::ObjectWrap< GRepeatedField< Element > >
    {
    public:
        static inline Napi::FunctionReference constructor;
        RepeatedField< Element >*      pRepeatedField = nullptr;

        GRepeatedField( const Napi::CallbackInfo& info );
        ~GRepeatedField();

        static Napi::Object Init( Napi::Env env, Napi::Object exports );

        Napi::Value size( const Napi::CallbackInfo& info );
        Napi::Value operator_get( const Napi::CallbackInfo& info );
    };

}  // namespace protobuf
}  // namespace google


template < typename Element >
inline google::protobuf::GRepeatedField< Element >::GRepeatedField( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GRepeatedField< Element > >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external  = info[ 0 ].As< Napi::External< RepeatedField< Element > > >();
        pRepeatedField = dynamic_cast< RepeatedField< Element >* >( external.Data() );
        if ( pRepeatedField != nullptr ) return;
    }

    ThrowJsError( google::protobuf::GRepeatedField::GRepeatedField : Invalid argument );
}

template < typename Element >
inline google::protobuf::GRepeatedField< Element >::~GRepeatedField()
{
    delete pRepeatedField;
}

template < typename Element >
inline Napi::Object google::protobuf::GRepeatedField< Element >::Init( Napi::Env env, Napi::Object exports )
{
    auto get_name = []() {
        if ( std::is_same< Element, int64_t >::value )
            return "RepeatedField_Int64";
        else
            throw std::runtime_error( "google::protobuf::GRepeatedField::Init : Invalid Typename Element" );
    };

    Napi::HandleScope scope( env );
    auto              func = GRepeatedField< Element >::DefineClass(
        env, get_name(),
        {
            GRepeatedField< Element >::InstanceMethod( "size", &GRepeatedField< Element >::size ),
            GRepeatedField< Element >::InstanceMethod( "operator_get", &GRepeatedField< Element >::operator_get ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, get_name() ), func );
    return exports;
}

template < typename Element >
inline Napi::Value google::protobuf::GRepeatedField< Element >::operator_get( const Napi::CallbackInfo& info )
{
    //   const Element& operator[](int index) const { return Get(index); }
    
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        int index = info[ 0 ].As< Napi::Number >().Int32Value();
        if ( index >= 0 && index < pRepeatedField->size() )
        {
            return Napi::Value::From( info.Env(), pRepeatedField->Get( index ) );
        }
    }

    ThrowJsError( google::protobuf::GRepeatedField::operator_get : Invalid argument );
    return info.Env().Undefined();
}

template < typename Element >
inline Napi::Value google::protobuf::GRepeatedField< Element >::size( const Napi::CallbackInfo& info )
{
    //   int size() const;
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), pRepeatedField->size() );
    }

    ThrowJsError( google::protobuf::GRepeatedField::size : Invalid argument );
    return info.Env().Undefined();
}
