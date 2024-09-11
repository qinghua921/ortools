#pragma once

#include "GLinearExpr.hpp"
#include "GCpModelProto.hpp"
#include "GCpSolverResponse.hpp"
#include "GSatParameters.hpp"
#include "commonheader.hpp"
#include "GModel.hpp"

namespace operations_research
{
namespace sat
{

    static Napi::Object GFuncInit( Napi::Env env, Napi::Object exports );

    Napi::Value GCpSolverResponseStats( const Napi::CallbackInfo& info );
    Napi::Value GSolutionIntegerValue( const Napi::CallbackInfo& info );
    Napi::Value GSolve( const Napi::CallbackInfo& info );
    Napi::Value Goperator_negate( const Napi::CallbackInfo& info );
    Napi::Value Goperator_plus( const Napi::CallbackInfo& info );
    Napi::Value Goperator_minus( const Napi::CallbackInfo& info );
    Napi::Value Goperator_times( const Napi::CallbackInfo& info );
    Napi::Value GSolutionBooleanValue( const Napi::CallbackInfo& info );
    Napi::Value GSolveWithParameters( const Napi::CallbackInfo& info );
    Napi::Value GNot( const Napi::CallbackInfo& info );
    Napi::Value GNewSatParameters( const Napi::CallbackInfo& info );
    Napi::Value GSolveCpModel( const Napi::CallbackInfo& info );
    Napi::Value GNewFeasibleSolutionObserver( const Napi::CallbackInfo& info );

};  // namespace sat
};  // namespace operations_research

inline Napi::Object operations_research::sat::GFuncInit( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );

    exports.Set( Napi::String::New( env, "Solve" ), Napi::Function::New( env, GSolve ) );
    exports.Set( Napi::String::New( env, "operator_negate" ), Napi::Function::New( env, Goperator_negate ) );
    exports.Set( Napi::String::New( env, "operator_plus" ), Napi::Function::New( env, Goperator_plus ) );
    exports.Set( Napi::String::New( env, "operator_minus" ), Napi::Function::New( env, Goperator_minus ) );
    exports.Set( Napi::String::New( env, "operator_times" ), Napi::Function::New( env, Goperator_times ) );
    exports.Set( Napi::String::New( env, "SolutionIntegerValue" ), Napi::Function::New( env, GSolutionIntegerValue ) );
    exports.Set( Napi::String::New( env, "CpSolverResponseStats" ), Napi::Function::New( env, GCpSolverResponseStats ) );
    exports.Set( Napi::String::New( env, "SolutionBooleanValue" ), Napi::Function::New( env, GSolutionBooleanValue ) );
    exports.Set( Napi::String::New( env, "SolveWithParameters" ), Napi::Function::New( env, GSolveWithParameters ) );
    exports.Set( Napi::String::New( env, "Not" ), Napi::Function::New( env, GNot ) );
    exports.Set( Napi::String::New( env, "NewSatParameters" ), Napi::Function::New( env, GNewSatParameters ) );
    exports.Set( Napi::String::New( env, "SolveCpModel" ), Napi::Function::New( env, GSolveCpModel ) );
    exports.Set( Napi::String::New( env, "NewFeasibleSolutionObserver" ), Napi::Function::New( env, GNewFeasibleSolutionObserver ) );

    return exports;
}

inline Napi::Value operations_research::sat::GNewFeasibleSolutionObserver( const Napi::CallbackInfo& info )
{
    // std::function<void(Model*)> NewFeasibleSolutionObserver(
    //     const std::function<void(const CpSolverResponse& response)>& observer);
    if ( info.Length() == 1 && info[ 0 ].IsFunction() )
    {
        auto observer             = info[ 0 ].As< Napi::Function >();
        auto fnThreadSafeFunction = Napi::ThreadSafeFunction::New( observer.Env(), observer, "GNewFeasibleSolutionObserver ThreadSafeFunction", 0, 1 );
        auto ret_func             = NewFeasibleSolutionObserver(
            [ fnThreadSafeFunction ]( const CpSolverResponse& response ) -> void  //
            {
                fnThreadSafeFunction.Acquire();
                auto newResponse = new CpSolverResponse( response );
                fnThreadSafeFunction.BlockingCall( newResponse, []( Napi::Env env, Napi::Function jsCallback, CpSolverResponse* value ) {
                    auto asExternalVar      = Napi::External< CpSolverResponse >::New( env, value );
                    auto vGCpSolverResponse = GCpSolverResponse::constructor.New( { asExternalVar } );
                    jsCallback.Call( { vGCpSolverResponse } );
                } );
                fnThreadSafeFunction.Release();
            } );

        return Napi::Function::New(
            info.Env(), [ ret_func ]( const Napi::CallbackInfo& info ) -> Napi::Value  //
            {
                if ( info.Length() == 1 && info[ 0 ].IsObject()
                     && info[ 0 ].As< Napi::Object >().InstanceOf( GModel::constructor.Value() ) )
                {
                    auto model = GModel::Unwrap( info[ 0 ].As< Napi::Object >() );
                    ret_func( model->spModel.get() );
                    return info.Env().Undefined();
                }

                ThrowJsError( "operations_research::sat::GNewFeasibleSolutionObserver : Invalid arguments" );
                return info.Env().Undefined();
            } );
    }

    ThrowJsError( "operations_research::sat::GNewFeasibleSolutionObserver : Invalid arguments" );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GSolveCpModel( const Napi::CallbackInfo& info )
{
    // CpSolverResponse SolveCpModel(const CpModelProto& model_proto, Model* model);
    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GCpModelProto::constructor.Value() )
         && info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GModel::constructor.Value() ) )
    {
        auto model_proto      = GCpModelProto::Unwrap( info[ 0 ].As< Napi::Object >() );
        auto model            = GModel::Unwrap( info[ 1 ].As< Napi::Object >() );
        auto cpSolverResponse = SolveCpModel( *model_proto->pCpModelProto, model->spModel.get() );
        auto exterior         = Napi::External< CpSolverResponse >::New( info.Env(), new CpSolverResponse( cpSolverResponse ) );
        return GCpSolverResponse::constructor.New( { exterior } );
    }

    ThrowJsError( operations_research::sat::GSolveCpModel - Invalid arguments );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GNewSatParameters( const Napi::CallbackInfo& info )
{
    // std::function<SatParameters(Model*)> NewSatParameters( const SatParameters& parameters);
    if ( info.Length() == 1 && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GSatParameters::constructor.Value() ) )
    {
        auto sat_parameters = GSatParameters::Unwrap( info[ 0 ].As< Napi::Object >() );
        auto ret_func       = NewSatParameters( *sat_parameters->pSatParameters );
        auto ret_js_func    = Napi::Function::New(
            info.Env(), [ ret_func ]( const Napi::CallbackInfo& info ) -> Napi::Value  //
            {
                if ( info.Length() == 1 && info[ 0 ].IsObject()
                     && info[ 0 ].As< Napi::Object >().InstanceOf( GModel::constructor.Value() ) )
                {
                    auto model = GModel::Unwrap( info[ 0 ].As< Napi::Object >() );
                    auto ret   = ret_func( model->spModel.get() );
                    return GSatParameters::constructor.New( { Napi::External< SatParameters >::New( info.Env(), new SatParameters( ret ) ) } );
                }

                ThrowJsError( operations_research::sat::GNewSatParameters std::function< SatParameters( Model* ) > : Invalid arguments );
                return info.Env().Undefined();
            } );
        return ret_js_func;
    }

    ThrowJsError( operations_research::sat::GNewSatParameters : Invalid arguments );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GNot( const Napi::CallbackInfo& info )
{
    // BoolVar Not(BoolVar x);
    if ( info.Length() == 1 && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        auto bool_var = GBoolVar::Unwrap( info[ 0 ].As< Napi::Object >() );
        auto not_     = Not( *bool_var->pBoolVar );
        auto exterior = Napi::External< BoolVar >::New( info.Env(), new BoolVar( not_ ) );
        return GBoolVar::constructor.New( { exterior } );
    }

    ThrowJsError( operations_research::sat::GNot : Invalid arguments );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GSolveWithParameters( const Napi::CallbackInfo& info )
{
    // CpSolverResponse SolveWithParameters(const CpModelProto& model_proto,
    //     const SatParameters& params);
    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GCpModelProto::constructor.Value() )
         && info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GSatParameters::constructor.Value() ) )
    {
        auto model_proto      = GCpModelProto::Unwrap( info[ 0 ].As< Napi::Object >() );
        auto sat_parameters   = GSatParameters::Unwrap( info[ 1 ].As< Napi::Object >() );
        auto cpSolverResponse = SolveWithParameters( *model_proto->pCpModelProto, *sat_parameters->pSatParameters );
        auto exterior         = Napi::External< CpSolverResponse >::New( info.Env(), new CpSolverResponse( cpSolverResponse ) );
        return GCpSolverResponse::constructor.New( { exterior } );
    }

    ThrowJsError( operations_research::sat::GSolveWithParameters : Invalid arguments );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::sat::GSolutionBooleanValue( const Napi::CallbackInfo& info )
{
    // bool SolutionBooleanValue( const CpSolverResponse& r, BoolVar x );
    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GCpSolverResponse::constructor.Value() )
         && info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        auto solver_response = GCpSolverResponse::Unwrap( info[ 0 ].As< Napi::Object >() );
        auto model_proto     = GBoolVar::Unwrap( info[ 1 ].As< Napi::Object >() );
        return Napi::Boolean::New( info.Env(), SolutionBooleanValue( *solver_response->pCpSolverResponse, *model_proto->pBoolVar ) );
    }

    ThrowJsError( operations_research::sat::GSolutionBooleanValue : Invalid arguments );
    return info.Env().Undefined();
};

Napi::Value operations_research::sat::GCpSolverResponseStats( const Napi::CallbackInfo& info )
{
    //    std::string CpSolverResponseStats( const CpSolverResponse& response,
    //     bool                    has_objective = true );
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GCpSolverResponse::constructor.Value() ) )
    {
        auto solver_response = GCpSolverResponse::Unwrap( info[ 0 ].As< Napi::Object >() );
        return Napi::String::New( info.Env(), CpSolverResponseStats( *solver_response->pCpSolverResponse ) );
    }

    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GCpSolverResponse::constructor.Value() )
         && info[ 1 ].IsBoolean() )
    {
        auto solver_response = GCpSolverResponse::Unwrap( info[ 0 ].As< Napi::Object >() );
        bool has_objective   = info[ 1 ].As< Napi::Boolean >().Value();
        return Napi::String::New( info.Env(), CpSolverResponseStats( *solver_response->pCpSolverResponse, has_objective ) );
    }

    ThrowJsError( operations_research::sat::GCpSolverResponseStats : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GSolutionIntegerValue( const Napi::CallbackInfo& info )
{
    // int64_t SolutionIntegerValue( const CpSolverResponse& r, const LinearExpr& expr );
    LinearExpr expr;
    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GCpSolverResponse::constructor.Value() )
         && GLinearExpr::ToLinearExpr( info[ 1 ], expr ) )
    {
        auto solver_response = GCpSolverResponse::Unwrap( info[ 0 ].As< Napi::Object >() );
        return Napi::Number::New( info.Env(), SolutionIntegerValue( *solver_response->pCpSolverResponse, expr ) );
    }

    ThrowJsError( operations_research::sat::GSolutionIntegerValue : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GSolve( const Napi::CallbackInfo& info )
{
    // CpSolverResponse Solve( const CpModelProto& model_proto );
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GCpModelProto::constructor.Value() ) )
    {
        auto model_proto      = GCpModelProto::Unwrap( info[ 0 ].As< Napi::Object >() );
        auto cpSolverResponse = Solve( *model_proto->pCpModelProto );
        auto exterior         = Napi::External< CpSolverResponse >::New( info.Env(), new CpSolverResponse( cpSolverResponse ) );
        return GCpSolverResponse::constructor.New( { exterior } );
    }

    ThrowJsError( operations_research::sat::GSolve : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::Goperator_negate( const Napi::CallbackInfo& info )
{
    // inline LinearExpr operator-( LinearExpr expr )
    LinearExpr expr;
    if ( info.Length() == 1 && GLinearExpr::ToLinearExpr( info[ 0 ], expr ) )
    {
        auto result   = -expr;
        auto exterior = Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) );
        return GLinearExpr::constructor.New( { exterior } );
    }

    ThrowJsError( operations_research::sat::Goperator_negate : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::Goperator_plus( const Napi::CallbackInfo& info )
{
    // inline LinearExpr operator+( const LinearExpr& lhs, const LinearExpr& rhs )
    LinearExpr lhs;
    LinearExpr rhs;
    if ( info.Length() == 2
         && GLinearExpr::ToLinearExpr( info[ 0 ], lhs )
         && GLinearExpr::ToLinearExpr( info[ 1 ], rhs ) )
    {
        auto result   = lhs + rhs;
        auto exterior = Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) );
        return GLinearExpr::constructor.New( { exterior } );
    }

    ThrowJsError( operations_research::sat::Goperator_plus : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::Goperator_minus( const Napi::CallbackInfo& info )
{
    // inline LinearExpr operator-( const LinearExpr& lhs, const LinearExpr& rhs )
    LinearExpr lhs;
    LinearExpr rhs;
    if ( info.Length() == 2
         && GLinearExpr::ToLinearExpr( info[ 0 ], lhs )
         && GLinearExpr::ToLinearExpr( info[ 1 ], rhs ) )
    {
        auto result   = lhs - rhs;
        auto exterior = Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) );
        return GLinearExpr::constructor.New( { exterior } );
    }

    ThrowJsError( operations_research::sat::Goperator_minus : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::Goperator_times( const Napi::CallbackInfo& info )
{
    // inline LinearExpr operator*( LinearExpr expr, int64_t factor )
    LinearExpr expr;
    if ( info.Length() == 2 && GLinearExpr::ToLinearExpr( info[ 0 ], expr ) && info[ 1 ].IsNumber() )
    {
        int64_t factor   = info[ 1 ].As< Napi::Number >().Int64Value();
        auto    result   = expr * factor;
        auto    exterior = Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) );
        return GLinearExpr::constructor.New( { exterior } );
    }

    // inline LinearExpr operator*( int64_t factor, LinearExpr expr )
    if ( info.Length() == 2 && GLinearExpr::ToLinearExpr( info[ 1 ], expr ) && info[ 0 ].IsNumber() )
    {
        int64_t factor   = info[ 0 ].As< Napi::Number >().Int64Value();
        auto    result   = expr * factor;
        auto    exterior = Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) );
        return GLinearExpr::constructor.New( { exterior } );
    }

    ThrowJsError( operations_research::sat::Goperator_times : Invalid arguments );
    return info.Env().Undefined();
}
