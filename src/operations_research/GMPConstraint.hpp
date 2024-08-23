﻿#pragma once

#include <napi.h>
#include "ortools/linear_solver/linear_solver.h"
#include "../commonheader.hpp"

namespace operations_research
{

class GMPConstraint : public Napi::ObjectWrap< GMPConstraint >
{
public:
    static Napi::FunctionReference constructor;
    MPConstraint*                  pGMPConstraint = nullptr;

    GMPConstraint( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GMPConstraint >( info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external  = info[ 0 ].As< Napi::External< MPConstraint > >();
            pGMPConstraint = dynamic_cast< MPConstraint* >( external.Data() );
            if ( pGMPConstraint ) return;
        }

        ThrowJsError( GMPConstraint::GMPConstraint : Invalid argument );
    };

    ~GMPConstraint()
    {
        if ( pGMPConstraint )
        {
            delete pGMPConstraint;
            pGMPConstraint = nullptr;
        }
    };

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        // Napi::HandleScope scope( env );
        Napi::Function func = DefineClass(
            env, "MPConstraint",
            {
                InstanceMethod( "SetCoefficient", &GMPConstraint::SetCoefficient ),
            } );
        constructor = Napi::Persistent( func );
        // constructor.SuppressDestruct();
        exports.Set( "MPConstraint", func );
        return exports;
    }

    //     void SetCoefficient( const MPVariable* const var, double coeff );
    Napi::Value SetCoefficient( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 2
             && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() )
             && info[ 1 ].IsNumber() )
        {
            auto   var   = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 0 ].As< Napi::Object >() );
            double coeff = info[ 1 ].As< Napi::Number >().DoubleValue();
            pGMPConstraint->SetCoefficient( var->pMPVariable, coeff );
            return info.Env().Undefined();
        }

        ThrowJsError( GMPConstraint::SetCoefficient : Invalid argument );
        return info.Env().Undefined();
    };
};

Napi::FunctionReference GMPConstraint::constructor;

}  // namespace operations_research

// class MPConstraint
// {
// public:
//     /// Returns the name of the constraint.
//     const std::string& name() const
//     {
//         return name_;
//     }

//     /// Clears all variables and coefficients. Does not clear the bounds.
//     void Clear();

//     /**
//      * Gets the coefficient of a given variable on the constraint (which is 0 if
//      * the variable does not appear in the constraint).
//      */
//     double GetCoefficient( const MPVariable* const var ) const;

//     /**
//      * Returns a map from variables to their coefficients in the constraint.
//      *
//      * If a variable is not present in the map, then its coefficient is zero.
//      */
//     const absl::flat_hash_map< const MPVariable*, double >& terms() const
//     {
//         return coefficients_;
//     }

//     /// Returns the lower bound.
//     double lb() const
//     {
//         return lb_;
//     }

//     /// Returns the upper bound.
//     double ub() const
//     {
//         return ub_;
//     }

//     /// Sets the lower bound.
//     void SetLB( double lb )
//     {
//         SetBounds( lb, ub_ );
//     }

//     /// Sets the upper bound.
//     void SetUB( double ub )
//     {
//         SetBounds( lb_, ub );
//     }

//     /// Sets both the lower and upper bounds.
//     void SetBounds( double lb, double ub );

//     /// Advanced usage: returns true if the constraint is "lazy" (see below).
//     bool is_lazy() const
//     {
//         return is_lazy_;
//     }

//     /**
//      * Advanced usage: sets the constraint "laziness".
//      *
//      * <em>This is only supported for SCIP and has no effect on other
//      * solvers.</em>
//      *
//      * When \b laziness is true, the constraint is only considered by the Linear
//      * Programming solver if its current solution violates the constraint. In this
//      * case, the constraint is definitively added to the problem. This may be
//      * useful in some MIP problems, and may have a dramatic impact on performance.
//      *
//      * For more info see: http://tinyurl.com/lazy-constraints.
//      */
//     void set_is_lazy( bool laziness )
//     {
//         is_lazy_ = laziness;
//     }

//     const MPVariable* indicator_variable() const
//     {
//         return indicator_variable_;
//     }
//     bool indicator_value() const
//     {
//         return indicator_value_;
//     }

//     /// Returns the index of the constraint in the MPSolver::constraints_.
//     int index() const
//     {
//         return index_;
//     }

//     /**
//      * Advanced usage: returns the dual value of the constraint in the current
//      * solution (only available for continuous problems).
//      */
//     double dual_value() const;

//     /**
//      * Advanced usage: returns the basis status of the constraint.
//      *
//      * It is only available for continuous problems).
//      *
//      * Note that if a constraint "linear_expression in [lb, ub]" is transformed
//      * into "linear_expression + slack = 0" with slack in [-ub, -lb], then this
//      * status is the same as the status of the slack variable with AT_UPPER_BOUND
//      * and AT_LOWER_BOUND swapped.
//      *
//      * @see MPSolver::BasisStatus.
//      */
//     MPSolver::BasisStatus basis_status() const;

// };