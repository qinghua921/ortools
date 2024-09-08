#pragma once

#include <napi.h>
#include "../commonheader.hpp"
#include "google/protobuf/repeated_ptr_field.h"

namespace google
{
namespace protobuf
{
    template < typename Element >
    class GRepeatedPtrField : public Napi::ObjectWrap< GRepeatedPtrField >
    {
    public:
        static Napi::FunctionReference constructor;
        RepeatedPtrField< Element >*   pRepeatedPtrField = nullptr;
        GRepeatedPtrField( const Napi::CallbackInfo& info );
        ~GRepeatedPtrField();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );
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
        if ( std::is_same< Element, int64_t >::value )
            return "RepeatedPtrField_Int64";
        else
            throw std::runtime_error( "google::protobuf::GRepeatedPtrField::Init : Invalid Typename Element" );
    };

    Napi::HandleScope scope( env );
    Napi::Function    func = GlobalReplaceSubstring< Element >::DefineClass(
        env, get_name(),
        {} );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, get_name() ), func );
    return exports;
}
