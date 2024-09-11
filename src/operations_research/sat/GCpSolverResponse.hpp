#pragma once

#include "commonheader.hpp"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
    WrapOrToolsClass(
        CpSolverResponse,
        WrapOrToolsMethod( objective_value );
        WrapOrToolsMethod( status );
        WrapOrToolsMethod( sufficient_assumptions_for_infeasibility ); );
};  // namespace sat
};  // namespace operations_research

inline operations_research::sat::GCpSolverResponse::GCpSolverResponse( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GCpSolverResponse >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< CpSolverResponse > >();
        shared_ptr    = std::shared_ptr< CpSolverResponse >( external.Data() );
        return;
    }

    ThrowJsError( operations_research::GCpSolverResponse::GCpSolverResponse : Invalid argument );
}

inline void operations_research::sat::GCpSolverResponse::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "CpSolverResponse",
        {
            InstanceMethod( "status", &GCpSolverResponse::status ),
            InstanceMethod( "objective_value", &GCpSolverResponse::objective_value ),
            InstanceMethod( "sufficient_assumptions_for_infeasibility", &GCpSolverResponse::sufficient_assumptions_for_infeasibility ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "CpSolverResponse" ), func );
}

inline Napi::Value operations_research::sat::GCpSolverResponse::sufficient_assumptions_for_infeasibility( const Napi::CallbackInfo& info )
{
    //     int32_t sufficient_assumptions_for_infeasibility( int index ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        int index = info[ 0 ].As< Napi::Number >().Int32Value();
        return Napi::Number::New( info.Env(), shared_ptr->sufficient_assumptions_for_infeasibility( index ) );
    }

    //     const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
    //     sufficient_assumptions_for_infeasibility() const;
    if ( info.Length() == 0 )
    {
        auto assumptions = shared_ptr->sufficient_assumptions_for_infeasibility();
        auto array       = Napi::Array::New( info.Env(), assumptions.size() );
        for ( int i = 0; i < assumptions.size(); i++ )
        {
            array[ i ] = Napi::Number::New( info.Env(), assumptions[ i ] );
        }
        return array;
    }

    ThrowJsError( operations_research::GCpSolverResponse::sufficient_assumptions_for_infeasibility : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GCpSolverResponse::objective_value( const Napi::CallbackInfo& info )
{
    //     double objective_value() const;
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), shared_ptr->objective_value() );
    }

    ThrowJsError( operations_research::GCpSolverResponse::objective_value : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GCpSolverResponse::status( const Napi::CallbackInfo& info )
{
    //     ::operations_research::sat::CpSolverStatus status() const;
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), shared_ptr->status() );
    }

    ThrowJsError( operations_research::GCpSolverResponse::Status : Invalid argument );
    return info.Env().Undefined();
}