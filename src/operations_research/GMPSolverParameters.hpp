#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"

namespace operations_research
{

class GMPSolverParameters : public Napi::ObjectWrap< GMPSolverParameters >
{
public:
    static inline Napi::FunctionReference constructor;
    MPSolverParameters*                   pMPSolverParameters;
    GMPSolverParameters( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GMPSolverParameters >( info )
    {
        Napi::Env env = info.Env();

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external       = info[ 0 ].As< Napi::External< MPSolverParameters > >();
            pMPSolverParameters = dynamic_cast< MPSolverParameters* >( external.Data() );
            if ( pMPSolverParameters ) return;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolverParameters::GMPSolverParameters : Invalid arguments" ).ThrowAsJavaScriptException();
    };

    ~GMPSolverParameters()
    {
        if ( pMPSolverParameters ) delete pMPSolverParameters;
    };

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );

        auto enumDoubleParam = Napi::Object::New( env );
        enumDoubleParam.Set( "RELATIVE_MIP_GAP", static_cast< int >( MPSolverParameters::DoubleParam::RELATIVE_MIP_GAP ) );
        enumDoubleParam.Set( "PRIMAL_TOLERANCE", static_cast< int >( MPSolverParameters::DoubleParam::PRIMAL_TOLERANCE ) );
        enumDoubleParam.Set( "DUAL_TOLERANCE", static_cast< int >( MPSolverParameters::DoubleParam::DUAL_TOLERANCE ) );

        auto enumIntegerParam = Napi::Object::New( env );
        enumIntegerParam.Set( "PRESOLVE", static_cast< int >( MPSolverParameters::IntegerParam::PRESOLVE ) );
        enumIntegerParam.Set( "LP_ALGORITHM", static_cast< int >( MPSolverParameters::IntegerParam::LP_ALGORITHM ) );
        enumIntegerParam.Set( "INCREMENTALITY", static_cast< int >( MPSolverParameters::IntegerParam::INCREMENTALITY ) );
        enumIntegerParam.Set( "SCALING", static_cast< int >( MPSolverParameters::IntegerParam::SCALING ) );

        auto enumPresolveValues = Napi::Object::New( env );
        enumPresolveValues.Set( "PRESOLVE_OFF", static_cast< int >( MPSolverParameters::PresolveValues::PRESOLVE_OFF ) );
        enumPresolveValues.Set( "PRESOLVE_ON", static_cast< int >( MPSolverParameters::PresolveValues::PRESOLVE_ON ) );

        auto enumLpAlgorithmValues = Napi::Object::New( env );
        enumLpAlgorithmValues.Set( "DUAL", static_cast< int >( MPSolverParameters::LpAlgorithmValues::DUAL ) );
        enumLpAlgorithmValues.Set( "PRIMAL", static_cast< int >( MPSolverParameters::LpAlgorithmValues::PRIMAL ) );
        enumLpAlgorithmValues.Set( "BARRIER", static_cast< int >( MPSolverParameters::LpAlgorithmValues::BARRIER ) );

        auto enumIncrementalityValues = Napi::Object::New( env );
        enumIncrementalityValues.Set( "INCREMENTALITY_OFF", static_cast< int >( MPSolverParameters::IncrementalityValues::INCREMENTALITY_OFF ) );
        enumIncrementalityValues.Set( "INCREMENTALITY_ON", static_cast< int >( MPSolverParameters::IncrementalityValues::INCREMENTALITY_ON ) );

        auto enumScalingValues = Napi::Object::New( env );
        enumScalingValues.Set( "SCALING_OFF", static_cast< int >( MPSolverParameters::ScalingValues::SCALING_OFF ) );
        enumScalingValues.Set( "SCALING_ON", static_cast< int >( MPSolverParameters::ScalingValues::SCALING_ON ) );

        Napi::Function func = DefineClass(
            env, "MPSolverParameters",
            {
                StaticValue( "DoubleParam", enumDoubleParam ),
                StaticValue( "IntegerParam", enumIntegerParam ),
                StaticValue( "PresolveValues", enumPresolveValues ),
                StaticValue( "LpAlgorithmValues", enumLpAlgorithmValues ),
                StaticValue( "IncrementalityValues", enumIncrementalityValues ),
                StaticValue( "ScalingValues", enumScalingValues ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPSolverParameters" ), func );
        return exports;
    };
};

};  // namespace operations_research