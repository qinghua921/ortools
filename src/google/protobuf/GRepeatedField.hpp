#pragma once

#include <napi.h>
#include "../commonheader.hpp"
#include "google/protobuf/repeated_field.h"

namespace google
{
namespace protobuf
{

    template < typename Element >
    class GRepeatedField : public Napi::ObjectWrap< GRepeatedField< Element > >
    {
    public:
        static Napi::FunctionReference constructor;
        RepeatedField< Element >*      pRepeatedField = nullptr;

        GRepeatedField( const Napi::CallbackInfo& info );
        ~GRepeatedField();

        static Napi::Object Init( Napi::Env env, Napi::Object exports );
    };

}  // namespace protobuf
}  // namespace google

template < typename Element >
Napi::FunctionReference google::protobuf::GRepeatedField< Element >::constructor;

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
    Napi::HandleScope scope( env );
    auto              func = DefineClass(
        env, "RepeatedField",
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "RepeatedField" ), func );
    return exports;
}
