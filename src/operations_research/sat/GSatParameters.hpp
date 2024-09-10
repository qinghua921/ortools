#pragma once

#include <napi.h>
#include "../../commonheader.hpp"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
    class GSatParameters : public Napi::ObjectWrap< GSatParameters >
    {
    public:
        static Napi::FunctionReference constructor;
        SatParameters*                 pSatParameters = nullptr;
        GSatParameters( const Napi::CallbackInfo& info );
        ~GSatParameters();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );

        Napi::Value set_log_search_progress( const Napi::CallbackInfo& info );
        Napi::Value set_use_timetabling_in_no_overlap_2d( const Napi::CallbackInfo& info );
        Napi::Value set_use_energetic_reasoning_in_no_overlap_2d( const Napi::CallbackInfo& info );
        Napi::Value set_search_branching( const Napi::CallbackInfo& info );
        Napi::Value set_enumerate_all_solutions( const Napi::CallbackInfo& info );
    };
};  // namespace sat
};  // namespace operations_research

Napi::FunctionReference operations_research::sat::GSatParameters::constructor;

inline operations_research::sat::GSatParameters::GSatParameters( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GSatParameters >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external  = info[ 0 ].As< Napi::External< SatParameters > >();
        pSatParameters = dynamic_cast< SatParameters* >( external.Data() );
        if ( pSatParameters != nullptr ) return;
    }

    //     inline SatParameters()
    //         : SatParameters( nullptr ) {}
    if ( info.Length() == 0 )
    {
        pSatParameters = new SatParameters();
        return;
    }

    ThrowJsError( operations_research::GSatParameters::GSatParameters : Invalid argument );
}

inline operations_research::sat::GSatParameters::~GSatParameters()
{
    delete pSatParameters;
}

inline Napi::Object operations_research::sat::GSatParameters::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );

    // export enum SearchBranching
    auto search_branching_enum = Napi::Object::New( env );
    search_branching_enum.Set( Napi::String::New( env, "AUTOMATIC_SEARCH" ), Napi::Number::New( env, 0 ) );
    search_branching_enum.Set( Napi::String::New( env, "FIXED_SEARCH" ), Napi::Number::New( env, 1 ) );
    search_branching_enum.Set( Napi::String::New( env, "PORTFOLIO_SEARCH" ), Napi::Number::New( env, 2 ) );
    search_branching_enum.Set( Napi::String::New( env, "LP_SEARCH" ), Napi::Number::New( env, 3 ) );
    search_branching_enum.Set( Napi::String::New( env, "PSEUDO_COST_SEARCH" ), Napi::Number::New( env, 4 ) );
    search_branching_enum.Set( Napi::String::New( env, "PORTFOLIO_WITH_QUICK_RESTART_SEARCH" ), Napi::Number::New( env, 5 ) );
    search_branching_enum.Set( Napi::String::New( env, "HINT_SEARCH" ), Napi::Number::New( env, 6 ) );
    search_branching_enum.Set( Napi::String::New( env, "PARTIAL_FIXED_SEARCH" ), Napi::Number::New( env, 7 ) );

    Napi::Function func = DefineClass(
        env, "SatParameters",
        {
            StaticValue( "SearchBranching", search_branching_enum ),
            InstanceMethod( "set_log_search_progress", &GSatParameters::set_log_search_progress ),
            InstanceMethod( "set_use_timetabling_in_no_overlap_2d", &GSatParameters::set_use_timetabling_in_no_overlap_2d ),
            InstanceMethod( "set_use_energetic_reasoning_in_no_overlap_2d", &GSatParameters::set_use_energetic_reasoning_in_no_overlap_2d ),
            InstanceMethod( "set_search_branching", &GSatParameters::set_search_branching ),
            InstanceMethod( "set_enumerate_all_solutions", &GSatParameters::set_enumerate_all_solutions ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "SatParameters" ), func );
    return exports;
}

inline Napi::Value operations_research::sat::GSatParameters::set_enumerate_all_solutions( const Napi::CallbackInfo& info )
{
    //     void set_enumerate_all_solutions( bool value );
    if ( info.Length() == 1 && info[ 0 ].IsBoolean() )
    {
        pSatParameters->set_enumerate_all_solutions( info[ 0 ].As< Napi::Boolean >().Value() );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GSatParameters::set_enumerate_all_solutions : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GSatParameters::set_search_branching( const Napi::CallbackInfo& info )
{
    //     void  set_search_branching( ::operations_research::sat::SatParameters_SearchBranching value );
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        pSatParameters->set_search_branching( static_cast< SatParameters::SearchBranching >( info[ 0 ].As< Napi::Number >().Int32Value() ) );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GSatParameters::set_search_branching : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GSatParameters::set_use_energetic_reasoning_in_no_overlap_2d( const Napi::CallbackInfo& info )
{
    //     void set_use_energetic_reasoning_in_no_overlap_2d( bool value );
    if ( info.Length() == 1 && info[ 0 ].IsBoolean() )
    {
        pSatParameters->set_use_energetic_reasoning_in_no_overlap_2d( info[ 0 ].As< Napi::Boolean >().Value() );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GSatParameters::set_use_energetic_reasoning_in_no_overlap_2d : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GSatParameters::set_use_timetabling_in_no_overlap_2d( const Napi::CallbackInfo& info )
{
    //     void set_use_timetabling_in_no_overlap_2d( bool value );
    if ( info.Length() == 1 && info[ 0 ].IsBoolean() )
    {
        pSatParameters->set_use_timetabling_in_no_overlap_2d( info[ 0 ].As< Napi::Boolean >().Value() );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GSatParameters::set_use_timetabling_in_no_overlap_2d : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GSatParameters::set_log_search_progress( const Napi::CallbackInfo& info )
{
    //     void set_log_search_progress( bool value );
    if ( info.Length() == 1 && info[ 0 ].IsBoolean() )
    {
        pSatParameters->set_log_search_progress( info[ 0 ].As< Napi::Boolean >().Value() );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GSatParameters::set_log_search_progress : Invalid argument );
    return info.Env().Undefined();
}
