#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"
#include "MPVariable.hpp"

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

        Napi::Function func = DefineClass(
            env, "MPSolver",
            {
                StaticValue( "OptimizationProblemType", enumOptimizationProblemType ),

                StaticMethod( "CreateSolver", &GMPSolver::CreateSolver ),
                InstanceMethod( "MakeBoolVar", &GMPSolver::MakeBoolVar ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPSolver" ), func );
        return exports;
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