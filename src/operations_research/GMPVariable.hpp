#pragma once

#include <napi.h>
#include "ortools/linear_solver/linear_solver.h"
#include "../commonheader.hpp"

namespace operations_research
{

class GMPVariable : public Napi::ObjectWrap< GMPVariable >
{
public:
    static Napi::FunctionReference constructor;
    MPVariable*                    pMPVariable = nullptr;

    GMPVariable( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GMPVariable >( info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external = info[ 0 ].As< Napi::External< MPVariable > >();
            pMPVariable   = dynamic_cast< MPVariable* >( external.Data() );
            if ( pMPVariable ) return;
        }

        ThrowJsError( GMPVariable::GMPVariable : Invalid argument );
    };

    ~GMPVariable()
    {
        if ( pMPVariable )
        {
            delete pMPVariable;
            pMPVariable = nullptr;
        }
    }

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPVariable",
            {
                InstanceMethod( "name", &GMPVariable::Name ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( "MPVariable", func );
        return exports;
    };

    // const std::string& name() const
    Napi::Value Name( const Napi::CallbackInfo& info )
    {
        return Napi::String::New( info.Env(), pMPVariable->name() );
    }
};

Napi::FunctionReference GMPVariable::constructor;

};  // namespace operations_research

// class MPVariable
// {
// public:

//     /// Sets the integrality requirement of the variable.
//     void SetInteger( bool integer );

//     /// Returns the integrality requirement of the variable.
//     bool integer() const
//     {
//         return integer_;
//     }

//     /**
//      * Returns the value of the variable in the current solution.
//      *
//      * If the variable is integer, then the value will always be an integer (the
//      * underlying solver handles floating-point values only, but this function
//      * automatically rounds it to the nearest integer; see: man 3 round).
//      */
//     double solution_value() const;

//     /// Returns the index of the variable in the MPSolver::variables_.
//     int index() const
//     {
//         return index_;
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

//     /**
//      * Advanced usage: unrounded solution value.
//      *
//      * The returned value won't be rounded to the nearest integer even if the
//      * variable is integer.
//      */
//     double unrounded_solution_value() const;

//     /**
//      * Advanced usage: returns the reduced cost of the variable in the current
//      * solution (only available for continuous problems).
//      */
//     double reduced_cost() const;

//     /**
//      * Advanced usage: returns the basis status of the variable in the current
//      * solution (only available for continuous problems).
//      *
//      * @see MPSolver::BasisStatus.
//      */
//     MPSolver::BasisStatus basis_status() const;

//     /**
//      * Advanced usage: Certain MIP solvers (e.g. Gurobi or SCIP) allow you to set
//      * a per-variable priority for determining which variable to branch on.
//      *
//      * A value of 0 is treated as default, and is equivalent to not setting the
//      * branching priority. The solver looks first to branch on fractional
//      * variables in higher priority levels. As of 2019-05, only Gurobi and SCIP
//      * support setting branching priority; all other solvers will simply ignore
//      * this annotation.
//      */
//     int branching_priority() const
//     {
//         return branching_priority_;
//     }
//     void SetBranchingPriority( int priority );

// };
