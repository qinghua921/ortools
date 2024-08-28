﻿#pragma once

#include <napi.h>
#include "ortools/linear_solver/linear_solver.h"

// ThrowAsJavaScriptException
#define ThrowJsError( errinfo ) \
    Napi::Error::New( info.Env(), ( char* )u8#errinfo ).ThrowAsJavaScriptException()

namespace operations_research
{

class GMPSolver : public Napi::ObjectWrap< GMPSolver >
{
public:
    static Napi::FunctionReference constructor;
    MPSolver*                      pMPSolver = nullptr;
    GMPSolver( const Napi::CallbackInfo& info );
    ~GMPSolver();

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );

        Napi::Object resultStatus = Napi::Object::New( env );
        resultStatus.Set( Napi::String::New( env, "OPTIMAL" ), Napi::Number::New( env, MPSolver::OPTIMAL ) );
        resultStatus.Set( Napi::String::New( env, "FEASIBLE" ), Napi::Number::New( env, MPSolver::FEASIBLE ) );
        resultStatus.Set( Napi::String::New( env, "INFEASIBLE" ), Napi::Number::New( env, MPSolver::INFEASIBLE ) );
        resultStatus.Set( Napi::String::New( env, "UNBOUNDED" ), Napi::Number::New( env, MPSolver::UNBOUNDED ) );
        resultStatus.Set( Napi::String::New( env, "ABNORMAL" ), Napi::Number::New( env, MPSolver::ABNORMAL ) );
        resultStatus.Set( Napi::String::New( env, "MODEL_INVALID" ), Napi::Number::New( env, MPSolver::MODEL_INVALID ) );
        resultStatus.Set( Napi::String::New( env, "NOT_SOLVED" ), Napi::Number::New( env, MPSolver::NOT_SOLVED ) );

        Napi::Object optimizationProblemType = Napi::Object::New( env );
        optimizationProblemType.Set( Napi::String::New( env, "CLP_LINEAR_PROGRAMMING" ), Napi::Number::New( env, 0 ) );
        optimizationProblemType.Set( Napi::String::New( env, "GLPK_LINEAR_PROGRAMMING" ), Napi::Number::New( env, 1 ) );
        optimizationProblemType.Set( Napi::String::New( env, "GLOP_LINEAR_PROGRAMMING" ), Napi::Number::New( env, 2 ) );
        optimizationProblemType.Set( Napi::String::New( env, "PDLP_LINEAR_PROGRAMMING" ), Napi::Number::New( env, 8 ) );
        optimizationProblemType.Set( Napi::String::New( env, "HIGHS_LINEAR_PROGRAMMING" ), Napi::Number::New( env, 15 ) );
        optimizationProblemType.Set( Napi::String::New( env, "SCIP_MIXED_INTEGER_PROGRAMMING" ), Napi::Number::New( env, 3 ) );
        optimizationProblemType.Set( Napi::String::New( env, "GLPK_MIXED_INTEGER_PROGRAMMING" ), Napi::Number::New( env, 4 ) );
        optimizationProblemType.Set( Napi::String::New( env, "CBC_MIXED_INTEGER_PROGRAMMING" ), Napi::Number::New( env, 5 ) );
        optimizationProblemType.Set( Napi::String::New( env, "GUROBI_LINEAR_PROGRAMMING" ), Napi::Number::New( env, 6 ) );
        optimizationProblemType.Set( Napi::String::New( env, "GUROBI_MIXED_INTEGER_PROGRAMMING" ), Napi::Number::New( env, 7 ) );
        optimizationProblemType.Set( Napi::String::New( env, "CPLEX_LINEAR_PROGRAMMING" ), Napi::Number::New( env, 10 ) );
        optimizationProblemType.Set( Napi::String::New( env, "CPLEX_MIXED_INTEGER_PROGRAMMING" ), Napi::Number::New( env, 11 ) );
        optimizationProblemType.Set( Napi::String::New( env, "XPRESS_LINEAR_PROGRAMMING" ), Napi::Number::New( env, 101 ) );
        optimizationProblemType.Set( Napi::String::New( env, "XPRESS_MIXED_INTEGER_PROGRAMMING" ), Napi::Number::New( env, 102 ) );
        optimizationProblemType.Set( Napi::String::New( env, "HIGHS_MIXED_INTEGER_PROGRAMMING" ), Napi::Number::New( env, 16 ) );
        optimizationProblemType.Set( Napi::String::New( env, "KNAPSACK_MIXED_INTEGER_PROGRAMMING" ), Napi::Number::New( env, 13 ) );

        Napi::Function func = DefineClass(
            env, "MPSolver",
            {
                StaticMethod( "CreateSolver", &GMPSolver::CreateSolver ),
                InstanceMethod( "MakeBoolVar", &GMPSolver::MakeBoolVar ),
                InstanceMethod( "MakeRowConstraint", &GMPSolver::MakeRowConstraint ),
                InstanceMethod( "MutableObjective", &GMPSolver::MutableObjective ),
                InstanceMethod( "Solve", &GMPSolver::Solve ),
                StaticValue( "ResultStatus", resultStatus ),
                StaticValue( "OptimizationProblemType", optimizationProblemType ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPSolver" ), func );
        return exports;
    }

    static Napi::Value CreateSolver( const Napi::CallbackInfo& info );       // static MPSolver* CreateSolver( const std::string& solver_id );
    Napi::Value        MakeBoolVar( const Napi::CallbackInfo& info );        // MPVariable* MakeBoolVar( const std::string& name );
    Napi::Value        MakeRowConstraint( const Napi::CallbackInfo& info );  // MPConstraint* MakeRowConstraint( double lb, double ub );
    Napi::Value        MutableObjective( const Napi::CallbackInfo& info );   // MPObjective* MutableObjective();
    Napi::Value        Solve( const Napi::CallbackInfo& info );              // ResultStatus Solve();
};

Napi::FunctionReference GMPSolver::constructor;

class GMPVariable : public Napi::ObjectWrap< GMPVariable >
{
public:
    static Napi::FunctionReference constructor;
    MPVariable*                    pMPVariable = nullptr;
    GMPVariable( const Napi::CallbackInfo& info );
    ~GMPVariable();

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPVariable",
            {} );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPVariable" ), func );
        return exports;
    }
};

Napi::FunctionReference GMPVariable::constructor;

class GLinearExpr : public Napi::ObjectWrap< GLinearExpr >
{
public:
    static Napi::FunctionReference constructor;
    LinearExpr*                    pLinearExpr = nullptr;
    GLinearExpr( const Napi::CallbackInfo& info );
    ~GLinearExpr();

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "LinearExpr",
            {
                InstanceMethod( "operator_plus_equals", &GLinearExpr::operator_plus_equals ),
                InstanceMethod( "operator_minus_equals", &GLinearExpr::operator_minus_equals ),
                InstanceMethod( "operator_times_equals", &GLinearExpr::operator_times_equals ),
                InstanceMethod( "operator_divide_equals", &GLinearExpr::operator_divide_equals ),
                InstanceMethod( "operator_negate", &GLinearExpr::operator_negate ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "LinearExpr" ), func );
        return exports;
    }

    Napi::Value operator_plus_equals( const Napi::CallbackInfo& info );    // LinearExpr& operator+=( const LinearExpr& rhs );
    Napi::Value operator_minus_equals( const Napi::CallbackInfo& info );   // LinearExpr& operator-=( const LinearExpr& rhs );
    Napi::Value operator_times_equals( const Napi::CallbackInfo& info );   // LinearExpr& operator*=( double rhs );
    Napi::Value operator_divide_equals( const Napi::CallbackInfo& info );  // LinearExpr& operator/=( double rhs );
    Napi::Value operator_negate( const Napi::CallbackInfo& info );         // LinearExpr  operator-() const;
};

Napi::FunctionReference GLinearExpr::constructor;

class GLinearRange : public Napi::ObjectWrap< GLinearRange >
{
public:
    static Napi::FunctionReference constructor;
    LinearRange*                   pLinearRange = nullptr;
    GLinearRange( const Napi::CallbackInfo& info );
    ~GLinearRange();

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "LinearRange",
            {} );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "LinearRange" ), func );
        return exports;
    }
};

Napi::FunctionReference GLinearRange::constructor;

Napi::Value operator_less_equals( const Napi::CallbackInfo& info );     // LinearRange operator<=( const LinearExpr& lhs, const LinearExpr& rhs );
Napi::Value operator_equals( const Napi::CallbackInfo& info );          // LinearRange operator==( const LinearExpr& lhs, const LinearExpr& rhs );
Napi::Value operator_greater_equals( const Napi::CallbackInfo& info );  // LinearRange operator>=( const LinearExpr& lhs, const LinearExpr& rhs );

class GMPConstraint : public Napi::ObjectWrap< GMPConstraint >
{
public:
    static Napi::FunctionReference constructor;
    MPConstraint*                  pMPConstraint = nullptr;
    GMPConstraint( const Napi::CallbackInfo& info );
    ~GMPConstraint();

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPConstraint",
            {
                InstanceMethod( "SetCoefficient", &GMPConstraint::SetCoefficient ),
            } );

        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPConstraint" ), func );
        return exports;
    }

    Napi::Value SetCoefficient( const Napi::CallbackInfo& info );  // void SetCoefficient( const MPVariable* const var, double coeff );
};

Napi::FunctionReference GMPConstraint::constructor;

class GMPObjective : public Napi::ObjectWrap< GMPObjective >
{
public:
    static Napi::FunctionReference constructor;
    MPObjective*                   pMPObjective = nullptr;
    GMPObjective( const Napi::CallbackInfo& info );
    ~GMPObjective();

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPObjective",
            {
                InstanceMethod( "SetCoefficient", &GMPObjective::SetCoefficient ),
                InstanceMethod( "SetMinimization", &GMPObjective::SetMinimization ),
            } );

        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPObjective" ), func );
        return exports;
    }

    Napi::Value SetCoefficient( const Napi::CallbackInfo& info );   // void SetCoefficient( const MPVariable* const var, double coeff );
    Napi::Value SetMinimization( const Napi::CallbackInfo& info );  // void SetMinimization();
};

Napi::FunctionReference GMPObjective::constructor;

namespace sat
{

};  // namespace sat

};  // namespace operations_research

Napi::Object Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );

    auto operations_research_exports = Napi::Object::New( env );
    operations_research::GMPSolver::Init( env, operations_research_exports );
    operations_research::GMPVariable::Init( env, operations_research_exports );
    operations_research::GLinearExpr::Init( env, operations_research_exports );
    operations_research::GLinearRange::Init( env, operations_research_exports );
    operations_research::GMPConstraint::Init( env, operations_research_exports );
    operations_research::GMPObjective::Init( env, operations_research_exports );

    operations_research_exports.Set( "operator_less_equals", Napi::Function::New( env, operations_research::operator_less_equals ) );
    operations_research_exports.Set( "operator_equals", Napi::Function::New( env, operations_research::operator_equals ) );
    operations_research_exports.Set( "operator_greater_equals", Napi::Function::New( env, operations_research::operator_greater_equals ) );

    exports.Set( "operations_research", operations_research_exports );

    return exports;
}

NODE_API_MODULE( ortools_binding, Init );