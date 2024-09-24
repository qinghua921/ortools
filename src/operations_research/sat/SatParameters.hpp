#pragma once

#include "napi.h"

namespace operations_research
{
namespace sat
{
    class GSatParameters : public Napi::ObjectWrap< GSatParameters >
    {
    public:
        static inline Napi::FunctionReference constructor;
        SatParameters*                        pSatParameters = nullptr;

        GSatParameters( const Napi::CallbackInfo& info )
            : Napi::ObjectWrap< GSatParameters >( info )
        {
            Napi::Env env = info.Env();

            if ( info.Length() == 1 && info[ 0 ].IsExternal() )
            {
                auto external  = info[ 0 ].As< Napi::External< SatParameters > >();
                pSatParameters = dynamic_cast< SatParameters* >( external.Data() );
                if ( pSatParameters ) return;
            }

            // inline SatParameters()
            if ( info.Length() == 0 )
            {
                pSatParameters = new SatParameters();
                return;
            }

            Napi::TypeError::New( env, "operations_research::GSatParameters::GSatParameters : Invalid arguments" ).ThrowAsJavaScriptException();
        };

        ~GSatParameters()
        {
            if ( pSatParameters ) delete pSatParameters;
        };

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "SatParameters",
                {
                    InstanceMethod( "set_log_search_progress", &GSatParameters::set_log_search_progress ),
                    InstanceMethod( "set_use_timetabling_in_no_overlap_2d", &GSatParameters::set_use_timetabling_in_no_overlap_2d ),
                    InstanceMethod( "set_use_energetic_reasoning_in_no_overlap_2d", &GSatParameters::set_use_energetic_reasoning_in_no_overlap_2d ),
                } );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "SatParameters" ), func );
            return exports;
        };

        //  void set_use_energetic_reasoning_in_no_overlap_2d( bool value );
        Napi::Value set_use_energetic_reasoning_in_no_overlap_2d( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 1 && info[ 0 ].IsBoolean() )
            {
                pSatParameters->set_use_energetic_reasoning_in_no_overlap_2d( info[ 0 ].As< Napi::Boolean >().Value() );
                return Napi::Boolean::New( env, true );
            }

            Napi::TypeError::New( env, "operations_research::GSatParameters::set_use_energetic_reasoning_in_no_overlap_2d : Invalid arguments" ).ThrowAsJavaScriptException();
            return Napi::Boolean::New( env, false );
        };

        //  void set_use_timetabling_in_no_overlap_2d( bool value );
        Napi::Value set_use_timetabling_in_no_overlap_2d( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 1 && info[ 0 ].IsBoolean() )
            {
                pSatParameters->set_use_timetabling_in_no_overlap_2d( info[ 0 ].As< Napi::Boolean >().Value() );
                return Napi::Boolean::New( env, true );
            }

            Napi::TypeError::New( env, "operations_research::GSatParameters::set_use_timetabling_in_no_overlap_2d : Invalid arguments" ).ThrowAsJavaScriptException();
            return Napi::Boolean::New( env, false );
        };

        // void set_log_search_progress( bool value );
        Napi::Value set_log_search_progress( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 1 && info[ 0 ].IsBoolean() )
            {
                pSatParameters->set_log_search_progress( info[ 0 ].As< Napi::Boolean >().Value() );
                return Napi::Boolean::New( env, true );
            }

            Napi::TypeError::New( env, "operations_research::GSatParameters::set_log_search_progress : Invalid arguments" ).ThrowAsJavaScriptException();
            return Napi::Boolean::New( env, false );
        };
    };
}  // namespace sat

};  // namespace operations_research