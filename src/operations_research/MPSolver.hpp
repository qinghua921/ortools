#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"
#include "MPVariable.hpp"
#include "MPConstraint.hpp"
#include "MPObjective.hpp"

namespace operations_research
{

class GMPSolver : public Napi::ObjectWrap< GMPSolver >
{
public:
    static inline Napi::FunctionReference constructor;
    MPSolver*                             pMPSolver = nullptr;

    GMPSolver( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GMPSolver >( info )
    {
        Napi::Env env = info.Env();

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external = info[ 0 ].As< Napi::External< MPSolver > >();
            pMPSolver     = dynamic_cast< MPSolver* >( external.Data() );
            if ( pMPSolver ) return;
        }

        // MPSolver( const std::string& name, OptimizationProblemType problem_type );
        if ( info.Length() == 2 && info[ 0 ].IsString() && info[ 1 ].IsNumber() )
        {
            std::string name         = info[ 0 ].As< Napi::String >().Utf8Value();
            int         problem_type = info[ 1 ].As< Napi::Number >().Int32Value();
            pMPSolver                = new MPSolver( name, static_cast< MPSolver::OptimizationProblemType >( problem_type ) );
            return;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::GMPSolver : Invalid arguments" ).ThrowAsJavaScriptException();
    };

    ~GMPSolver()
    {
        if ( pMPSolver ) delete pMPSolver;
    };

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );

        auto enumOptimizationProblemType = Napi::Object::New( env );
        enumOptimizationProblemType.Set( "CLP_LINEAR_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::CLP_LINEAR_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "GLPK_LINEAR_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::GLPK_LINEAR_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "GLOP_LINEAR_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::GLOP_LINEAR_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "PDLP_LINEAR_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::PDLP_LINEAR_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "HIGHS_LINEAR_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::HIGHS_LINEAR_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "SCIP_MIXED_INTEGER_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::SCIP_MIXED_INTEGER_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "GLPK_MIXED_INTEGER_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::GLPK_MIXED_INTEGER_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "CBC_MIXED_INTEGER_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::CBC_MIXED_INTEGER_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "HIGHS_MIXED_INTEGER_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::HIGHS_MIXED_INTEGER_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "BOP_INTEGER_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::BOP_INTEGER_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "SAT_INTEGER_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::SAT_INTEGER_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "KNAPSACK_MIXED_INTEGER_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::KNAPSACK_MIXED_INTEGER_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "GUROBI_LINEAR_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::GUROBI_LINEAR_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "GUROBI_MIXED_INTEGER_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::GUROBI_MIXED_INTEGER_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "CPLEX_LINEAR_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::CPLEX_LINEAR_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "CPLEX_MIXED_INTEGER_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::CPLEX_MIXED_INTEGER_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "XPRESS_LINEAR_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::XPRESS_LINEAR_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "XPRESS_MIXED_INTEGER_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::XPRESS_MIXED_INTEGER_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "COPT_LINEAR_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::COPT_LINEAR_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "COPT_MIXED_INTEGER_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::COPT_MIXED_INTEGER_PROGRAMMING ) );

        auto enumResultStatus = Napi::Object::New( env );
        enumResultStatus.Set( "OPTIMAL", static_cast< int >( MPSolver::ResultStatus::OPTIMAL ) );
        enumResultStatus.Set( "FEASIBLE", static_cast< int >( MPSolver::ResultStatus::FEASIBLE ) );
        enumResultStatus.Set( "INFEASIBLE", static_cast< int >( MPSolver::ResultStatus::INFEASIBLE ) );
        enumResultStatus.Set( "UNBOUNDED", static_cast< int >( MPSolver::ResultStatus::UNBOUNDED ) );
        enumResultStatus.Set( "ABNORMAL", static_cast< int >( MPSolver::ResultStatus::ABNORMAL ) );
        enumResultStatus.Set( "MODEL_INVALID", static_cast< int >( MPSolver::ResultStatus::MODEL_INVALID ) );
        enumResultStatus.Set( "NOT_SOLVED", static_cast< int >( MPSolver::ResultStatus::NOT_SOLVED ) );

        Napi::Function func = DefineClass(
            env, "MPSolver",
            {
                StaticValue( "OptimizationProblemType", enumOptimizationProblemType ),
                StaticValue( "ResultStatus", enumResultStatus ),

                StaticMethod( "CreateSolver", &GMPSolver::CreateSolver ),
                InstanceMethod( "MakeBoolVar", &GMPSolver::MakeBoolVar ),
                InstanceMethod( "MakeRowConstraint", &GMPSolver::MakeRowConstraint ),
                InstanceMethod( "MutableObjective", &GMPSolver::MutableObjective ),
                InstanceMethod( "Solve", &GMPSolver::Solve ),
                InstanceMethod( "MakeIntVar", &GMPSolver::MakeIntVar ),
                InstanceMethod( "MakeNumVar", &GMPSolver::MakeNumVar ),
                InstanceMethod( "NumVariables", &GMPSolver::NumVariables ),
                StaticMethod( "infinity", &GMPSolver::infinity ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPSolver" ), func );
        return exports;
    };

    // static double infinity()

    static Napi::Value infinity( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::Number::New( env, MPSolver::infinity() );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::infinity : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // int NumVariables() const
    Napi::Value NumVariables( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::Number::New( env, pMPSolver->NumVariables() );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::NumVariables : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // MPVariable* MakeNumVar( double lb, double ub, const std::string& name );
    Napi::Value MakeNumVar( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
        {
            double      lb       = info[ 0 ].As< Napi::Number >().DoubleValue();
            double      ub       = info[ 1 ].As< Napi::Number >().DoubleValue();
            std::string name     = info[ 2 ].As< Napi::String >().Utf8Value();
            MPVariable* pVar     = pMPSolver->MakeNumVar( lb, ub, name );
            auto        external = Napi::External< MPVariable >::New( env, pVar );
            return GMPVariable::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeNumVar : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // MPVariable* MakeIntVar( double lb, double ub, const std::string& name );
    Napi::Value MakeIntVar( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
        {
            double      lb       = info[ 0 ].As< Napi::Number >().DoubleValue();
            double      ub       = info[ 1 ].As< Napi::Number >().DoubleValue();
            std::string name     = info[ 2 ].As< Napi::String >().Utf8Value();
            MPVariable* pVar     = pMPSolver->MakeIntVar( lb, ub, name );
            auto        external = Napi::External< MPVariable >::New( env, pVar );
            return GMPVariable::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeIntVar : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    //    ResultStatus Solve();
    Napi::Value Solve( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            MPSolver::ResultStatus status = pMPSolver->Solve();
            return Napi::Number::New( env, static_cast< int >( status ) );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::Solve : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // MPObjective* MutableObjective();
    Napi::Value MutableObjective( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            MPObjective* pObjective = pMPSolver->MutableObjective();
            auto         external   = Napi::External< MPObjective >::New( env, pObjective );
            return GMPObjective::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MutableObjective : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    Napi::Value MakeRowConstraint( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        // MPConstraint* MakeRowConstraint( double lb, double ub );
        if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() )
        {
            double        lb          = info[ 0 ].As< Napi::Number >().DoubleValue();
            double        ub          = info[ 1 ].As< Napi::Number >().DoubleValue();
            MPConstraint* pConstraint = pMPSolver->MakeRowConstraint( lb, ub );
            auto          external    = Napi::External< MPConstraint >::New( env, pConstraint );
            return GMPConstraint::constructor.New( { external } );
        }

        // MPConstraint* MakeRowConstraint();
        if ( info.Length() == 0 )
        {
            MPConstraint* pConstraint = pMPSolver->MakeRowConstraint();
            auto          external    = Napi::External< MPConstraint >::New( env, pConstraint );
            return GMPConstraint::constructor.New( { external } );
        }

        //    MPConstraint* MakeRowConstraint( double lb, double ub,
        //                                     const std::string& name );
        if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
        {
            double        lb          = info[ 0 ].As< Napi::Number >().DoubleValue();
            double        ub          = info[ 1 ].As< Napi::Number >().DoubleValue();
            std::string   name        = info[ 2 ].As< Napi::String >().Utf8Value();
            MPConstraint* pConstraint = pMPSolver->MakeRowConstraint( lb, ub, name );
            auto          external    = Napi::External< MPConstraint >::New( env, pConstraint );
            return GMPConstraint::constructor.New( { external } );
        }

        //    MPConstraint* MakeRowConstraint( const std::string& name );
        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string   name        = info[ 0 ].As< Napi::String >().Utf8Value();
            MPConstraint* pConstraint = pMPSolver->MakeRowConstraint( name );
            auto          external    = Napi::External< MPConstraint >::New( env, pConstraint );
            return GMPConstraint::constructor.New( { external } );
        }

        //    MPConstraint* MakeRowConstraint( const LinearRange& range );
        if ( info.Length() == 1 && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearRange::constructor.Value() ) )
        {
            auto          linear_range = GLinearRange::Unwrap( info[ 0 ].As< Napi::Object >() );
            LinearRange*  pRange       = linear_range->pLinearRange;
            MPConstraint* pConstraint  = pMPSolver->MakeRowConstraint( *pRange );
            auto          external     = Napi::External< MPConstraint >::New( env, pConstraint );
            return GMPConstraint::constructor.New( { external } );
        }

        //    MPConstraint* MakeRowConstraint( const LinearRange& range,
        //                                     const std::string& name );
        if ( info.Length() == 2 && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearRange::constructor.Value() )
             && info[ 1 ].IsString() )
        {
            auto          linear_range = GLinearRange::Unwrap( info[ 0 ].As< Napi::Object >() );
            LinearRange*  pRange       = linear_range->pLinearRange;
            std::string   name         = info[ 1 ].As< Napi::String >().Utf8Value();
            MPConstraint* pConstraint  = pMPSolver->MakeRowConstraint( *pRange, name );
            auto          external     = Napi::External< MPConstraint >::New( env, pConstraint );
            return GMPConstraint::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeRowConstraint : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // MPVariable* MakeBoolVar( const std::string& name );
    Napi::Value MakeBoolVar( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string name     = info[ 0 ].As< Napi::String >().Utf8Value();
            MPVariable* pVar     = pMPSolver->MakeBoolVar( name );
            auto        external = Napi::External< MPVariable >::New( env, pVar );
            return GMPVariable::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeBoolVar : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // static MPSolver* CreateSolver( const std::string& solver_id );
    static Napi::Value CreateSolver( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string solver_id = info[ 0 ].As< Napi::String >().Utf8Value();
            MPSolver*   pMPSolver = MPSolver::CreateSolver( solver_id );
            auto        external  = Napi::External< MPSolver >::New( env, pMPSolver );
            return GMPSolver::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::CreateSolver : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };
};

};  // namespace operations_research