#pragma once

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

        Napi::Function func = DefineClass(
            env, "MPSolver",
            {
                StaticMethod( "CreateSolver", &GMPSolver::CreateSolver ),
                InstanceMethod( "MakeBoolVar", &GMPSolver::MakeBoolVar ),
            } );

        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPSolver" ), func );

        return exports;
    };

    static Napi::Value CreateSolver( const Napi::CallbackInfo& info );
    Napi::Value        MakeBoolVar( const Napi::CallbackInfo& info );
    Napi::Value        MakeRowConstraint( const Napi::CallbackInfo& info );
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

        Napi::Function func = DefineClass(
            env, "MPVariable",
            {} );

        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPVariable" ), func );

        return exports;
    };
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

        Napi::Function func = DefineClass(
            env, "LinearExpr",
            {
                InstanceMethod( "operator_plus_equals", &GLinearExpr::operator_plus_equals ),
            } );

        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "LinearExpr" ), func );

        return exports;
    };

    Napi::Value operator_plus_equals( const Napi::CallbackInfo& info );
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

        Napi::Function func = DefineClass(
            env, "LinearRange",
            {} );

        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "LinearRange" ), func );

        return exports;
    };
};

Napi::FunctionReference GLinearRange::constructor;

Napi::Value operator_less_equals( const Napi::CallbackInfo& info );
Napi::Value operator_equals( const Napi::CallbackInfo& info );
Napi::Value operator_greater_equals( const Napi::CallbackInfo& info );

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

    operations_research_exports.Set( "operator_less_equals", Napi::Function::New( env, operations_research::operator_less_equals ) );
    operations_research_exports.Set( "operator_equals", Napi::Function::New( env, operations_research::operator_equals ) );
    operations_research_exports.Set( "operator_greater_equals", Napi::Function::New( env, operations_research::operator_greater_equals ) );

    exports.Set( "operations_research", operations_research_exports );

    return exports;
}

NODE_API_MODULE( ortools_binding, Init );
