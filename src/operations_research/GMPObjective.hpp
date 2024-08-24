#pragma once

#include <napi.h>
#include "ortools/linear_solver/linear_solver.h"
#include "../commonheader.hpp"
#include "GMPVariable.hpp"

namespace operations_research
{

class GMPObjective : public Napi::ObjectWrap< GMPObjective >
{
public:
    static Napi::FunctionReference constructor;
    MPObjective*                   pMPObjective = nullptr;

    GMPObjective( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GMPObjective >( info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external = info[ 0 ].As< Napi::External< MPObjective > >();
            pMPObjective  = dynamic_cast< MPObjective* >( external.Data() );
            if ( pMPObjective ) return;
        }

        ThrowJsError( GMPObjective::GMPObjective : Invalid argument );
    };

    ~GMPObjective();

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPObjective",
            {
                InstanceMethod( "SetCoefficient", &GMPObjective::SetCoefficient ),
                InstanceMethod( "SetMaximization", &GMPObjective::SetMaximization ),
                InstanceMethod( "Clear", &GMPObjective::Clear ),
                InstanceMethod( "offset", &GMPObjective::offset ),
                InstanceMethod( "SetMinimization", &GMPObjective::SetMinimization ),
                InstanceMethod( "SetOffset", &GMPObjective::SetOffset ),
                InstanceMethod( "Value", &GMPObjective::Value ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( "MPObjective", func );
        return exports;
    };

    Napi::Value Value( const Napi::CallbackInfo& info );            //     double Value() const;
    Napi::Value SetOffset( const Napi::CallbackInfo& info );        //     void SetOffset( double value );
    Napi::Value SetMinimization( const Napi::CallbackInfo& info );  //     void SetMinimization()
    Napi::Value offset( const Napi::CallbackInfo& info );           //     double offset() const
    Napi::Value Clear( const Napi::CallbackInfo& info );            //     void Clear();
    Napi::Value SetCoefficient( const Napi::CallbackInfo& info );   //     void SetCoefficient( const MPVariable* const var, double coeff );
    Napi::Value SetMaximization( const Napi::CallbackInfo& info );  //     void SetMaximization()

    // class MPObjective
    // {
    // public:

    //     /**
    //      *  Gets the coefficient of a given variable in the objective
    //      *
    //      * It returns 0 if the variable does not appear in the objective).
    //      */
    //     double GetCoefficient( const MPVariable* const var ) const;

    //     /**
    //      * Returns a map from variables to their coefficients in the objective.
    //      *
    //      * If a variable is not present in the map, then its coefficient is zero.
    //      */
    //     const absl::flat_hash_map< const MPVariable*, double >& terms() const
    //     {
    //         return coefficients_;
    //     }

    //     /**
    //      * Resets the current objective to take the value of linear_expr, and sets the
    //      * objective direction to maximize if "is_maximize", otherwise minimizes.
    //      */
    //     void OptimizeLinearExpr( const LinearExpr& linear_expr, bool is_maximization );

    //     /// Resets the current objective to maximize linear_expr.
    //     void MaximizeLinearExpr( const LinearExpr& linear_expr )
    //     {
    //         OptimizeLinearExpr( linear_expr, true );
    //     }
    //     /// Resets the current objective to minimize linear_expr.
    //     void MinimizeLinearExpr( const LinearExpr& linear_expr )
    //     {
    //         OptimizeLinearExpr( linear_expr, false );
    //     }

    //     /// Adds linear_expr to the current objective, does not change the direction.
    //     void AddLinearExpr( const LinearExpr& linear_expr );

    //     /// Sets the optimization direction (maximize: true or minimize: false).
    //     void SetOptimizationDirection( bool maximize );

    //     /// Is the optimization direction set to maximize?
    //     bool maximization() const;

    //     /// Is the optimization direction set to minimize?
    //     bool minimization() const;

    //     /**
    //      * Returns the best objective bound.
    //      *
    //      * In case of minimization, it is a lower bound on the objective value of the
    //      * optimal integer solution. Only available for discrete problems.
    //      */
    //     double BestBound() const;

    // };
};

GMPObjective::~GMPObjective()
{
    if ( pMPObjective )
    {
        delete pMPObjective;
        pMPObjective = nullptr;
    }
}

Napi::Value GMPObjective::Value( const Napi::CallbackInfo& info )
{
    return Napi::Number::New( info.Env(), pMPObjective->Value() );
}

Napi::Value GMPObjective::SetOffset( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        double value = info[ 0 ].As< Napi::Number >().DoubleValue();
        pMPObjective->SetOffset( value );
        return info.Env().Undefined();
    }

    ThrowJsError( GMPObjective::SetOffset : Invalid argument );
    return info.Env().Undefined();
};

Napi::Value GMPObjective::SetMinimization( const Napi::CallbackInfo& info )
{
    pMPObjective->SetMinimization();
    return info.Env().Undefined();
}
Napi::Value GMPObjective::offset( const Napi::CallbackInfo& info )
{
    return Napi::Number::New( info.Env(), pMPObjective->offset() );
}
Napi::Value GMPObjective::Clear( const Napi::CallbackInfo& info )
{
    pMPObjective->Clear();
    return info.Env().Undefined();
}
Napi::Value GMPObjective::SetCoefficient( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() )
         && info[ 1 ].IsNumber() )
    {
        auto   var   = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 0 ].As< Napi::Object >() );
        double coeff = info[ 1 ].As< Napi::Number >().DoubleValue();
        pMPObjective->SetCoefficient( var->pMPVariable, coeff );
        return info.Env().Undefined();
    }

    ThrowJsError( GMPObjective::SetCoefficient : Invalid argument );
    return info.Env().Undefined();
};
Napi::Value GMPObjective::SetMaximization( const Napi::CallbackInfo& info )
{
    pMPObjective->SetMaximization();
    return info.Env().Undefined();
};

Napi::FunctionReference GMPObjective::constructor;

};  // namespace operations_research
