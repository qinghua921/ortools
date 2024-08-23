#pragma once

#include <napi.h>
#include "ortools/linear_solver/linear_solver.h"
#include "../commonheader.hpp"

namespace operations_research
{

class GMPSolverParameters : public Napi::ObjectWrap< GMPSolverParameters >
{
public:
    static Napi::FunctionReference constructor;
    MPSolverParameters*            pMPSolverParameters = nullptr;

    GMPSolverParameters( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GMPSolverParameters >( info )
    {
        //     MPSolverParameters();
        if ( info.Length() == 0 )
        {
            pMPSolverParameters = new MPSolverParameters();
            return;
        }

        ThrowJsError( GMPSolverParameters::GMPSolverParameters : Invalid number of arguments );
    };

    ~GMPSolverParameters()
    {
        if ( pMPSolverParameters )
        {
            delete pMPSolverParameters;
            pMPSolverParameters = nullptr;
        }
    }

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPSolverParameters",
            {} );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( "MPSolverParameters", func );
        return exports;
    };
};

Napi::FunctionReference GMPSolverParameters::constructor;
};  // namespace operations_research

// class MPSolverParameters
// {
// public:

//     // Placeholder value to indicate that a parameter is set to
//     // the default value defined in the wrapper.
//     static const double kDefaultDoubleParamValue;
//     static const int    kDefaultIntegerParamValue;

//     // Placeholder value to indicate that a parameter is unknown.
//     static const double kUnknownDoubleParamValue;
//     static const int    kUnknownIntegerParamValue;

//     // Default values for parameters. Only parameters that define the
//     // properties of the solution returned need to have a default value
//     // (that is the same for all solvers). You can also define a default
//     // value for performance parameters when you are confident it is a
//     // good choice (example: always turn presolve on).
//     static const double               kDefaultRelativeMipGap;
//     static const double               kDefaultPrimalTolerance;
//     static const double               kDefaultDualTolerance;
//     static const PresolveValues       kDefaultPresolve;
//     static const IncrementalityValues kDefaultIncrementality;

//     /// Sets a double parameter to a specific value.
//     void SetDoubleParam( MPSolverParameters::DoubleParam param, double value );

//     /// Sets a integer parameter to a specific value.
//     void SetIntegerParam( MPSolverParameters::IntegerParam param, int value );

//     /**
//      * Sets a double parameter to its default value (default value defined in
//      * MPSolverParameters if it exists, otherwise the default value defined in
//      * the underlying solver).
//      */
//     void ResetDoubleParam( MPSolverParameters::DoubleParam param );

//     /**
//      * Sets an integer parameter to its default value (default value defined in
//      * MPSolverParameters if it exists, otherwise the default value defined in
//      * the underlying solver).
//      */
//     void ResetIntegerParam( MPSolverParameters::IntegerParam param );

//     /// Sets all parameters to their default value.
//     void Reset();

//     /// Returns the value of a double parameter.
//     double GetDoubleParam( MPSolverParameters::DoubleParam param ) const;

//     /// Returns the value of an integer parameter.
//     int GetIntegerParam( MPSolverParameters::IntegerParam param ) const;

// };
