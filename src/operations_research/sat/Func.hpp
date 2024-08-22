#include <napi.h>

#include "GCpModelProto.hpp"
#include "GCpSolverResponse.hpp"
#include "GIntVar.hpp"
#include "FuncSolveWorker.hpp"
#include "GLinearExpr.hpp"
#include "GModel.hpp"
#include "FuncSolveCpModelWorker.hpp"
#include "GSatParameters.hpp"

namespace operations_research
{
namespace sat
{

    Napi::Value GSolutionIntegerValue( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 2 && info[ 0 ].IsObject() && info[ 1 ].IsObject() )
        {
            GCpSolverResponse* pGCpSolverResponse = GCpSolverResponse::Unwrap( info[ 0 ].As< Napi::Object >() );

            LinearExpr linearExpr;
            auto       linearExprOk = GLinearExpr ::UnwrapValue( info[ 1 ], linearExpr );
            if ( typeid( *pGCpSolverResponse ) == typeid( GCpSolverResponse ) && linearExprOk )
            {
                auto value = SolutionIntegerValue( *pGCpSolverResponse->pCpSolverResponse, linearExpr );
                return Napi::Number::New( info.Env(), value );
            }
        }

        ThrowJsError( GSolutionIntegerValue Error );
        return info.Env().Undefined();
    }

    Napi::Value GSolveCpModel( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 2 && info[ 0 ].IsObject() && info[ 1 ].IsObject() )
        {
            auto* pGCpModelProto = GCpModelProto::Unwrap( info[ 0 ].As< Napi::Object >() );
            auto* pGModel        = GModel::Unwrap( info[ 1 ].As< Napi::Object >() );

            if ( typeid( *pGCpModelProto ) == typeid( GCpModelProto ) && typeid( *pGModel ) == typeid( GModel ) )
            {
                auto worker = new FuncSolveCpModelWorker( info.Env(), pGCpModelProto, pGModel );
                worker->Queue();
                return worker->Promise();
            }
        }

        ThrowJsError( GSolutionIntegerValue Error );
        return info.Env().Undefined();
    }

    Napi::Value GSolve( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsObject() )
        {
            GCpModelProto* pGCpModelProto = GCpModelProto::Unwrap( info[ 0 ].As< Napi::Object >() );
            if ( typeid( *pGCpModelProto ) == typeid( GCpModelProto ) )
            {
                auto worker = new FuncSolveWorker( info.Env(), pGCpModelProto );
                worker->Queue();
                return worker->Promise();
            }
        }

        ThrowJsError( GSolve ERROR );
        return info.Env().Undefined();
    }

    Napi::Value GNewFeasibleSolutionObserver( const Napi::CallbackInfo& outerInfo )
    {
        if ( outerInfo.Length() == 1 && outerInfo[ 0 ].IsFunction() )
        {
            auto outerEnv             = outerInfo.Env();
            auto jsCpSolverResponse   = outerInfo[ 0 ].As< Napi::Function >();
            auto fnThreadSafeFunction = Napi::ThreadSafeFunction::New( outerEnv, jsCpSolverResponse, "GNewFeasibleSolutionObserver ThreadSafeFunction", 0, 1 );
            auto cppModel             = NewFeasibleSolutionObserver( [ fnThreadSafeFunction ]( const CpSolverResponse& response ) {
                fnThreadSafeFunction.Acquire();
                auto newResponse = new CpSolverResponse( response );
                fnThreadSafeFunction.BlockingCall( newResponse, []( Napi::Env env, Napi::Function jsCallback, CpSolverResponse* value ) {
                    auto asExternalVar      = Napi::External< CpSolverResponse >::New( env, value );
                    auto vGCpSolverResponse = GCpSolverResponse::constructor.New( { asExternalVar, Napi::Boolean::New( env, true ) } );
                    jsCallback.Call( { vGCpSolverResponse } );
                } );
                fnThreadSafeFunction.Release();
            } );

            return Napi::Function::New  //
                (
                    outerEnv,
                    [ cppModel ]( const Napi::CallbackInfo& innerInfo )  //
                    {
                        if ( innerInfo.Length() == 1 && innerInfo[ 0 ].IsObject() )
                        {
                            auto pGModel = GModel::Unwrap( innerInfo[ 0 ].As< Napi::Object >() );
                            if ( typeid( *pGModel ) == typeid( GModel ) )
                            {
                                cppModel( pGModel->pModel );
                                return;
                            }
                        }

                        Napi::Error::New( innerInfo.Env(), ( char* )u8"GNewFeasibleSolutionObserver func_return ERROR" ).ThrowAsJavaScriptException();
                    }  //
                );
        }

        Napi::Error::New( outerInfo.Env(), ( char* )u8"GNewFeasibleSolutionObserver ERROR" ).ThrowAsJavaScriptException();
        return outerInfo.Env().Undefined();
    }

    Napi::Value GNewSatParameters( const Napi::CallbackInfo& outerInfo )
    {
        if ( outerInfo.Length() == 1 && outerInfo[ 0 ].IsObject() )
        {
            auto pGSatParameters = GSatParameters::Unwrap( outerInfo[ 0 ].As< Napi::Object >() );
            if ( typeid( *pGSatParameters ) == typeid( GSatParameters ) )
            {
                auto outerEnv            = outerInfo.Env();
                auto retNewSatParameters = NewSatParameters( pGSatParameters->vSatParameters );

                return Napi::Function::New  //
                    (
                        outerEnv,
                        [ retNewSatParameters ]( const Napi::CallbackInfo& innerInfo ) -> Napi::Value  //
                        {
                            if ( innerInfo.Length() == 1 && innerInfo[ 0 ].IsObject() )
                            {
                                auto pGModel = GModel::Unwrap( innerInfo[ 0 ].As< Napi::Object >() );
                                if ( typeid( *pGModel ) == typeid( GModel ) )
                                {
                                    auto ret           = retNewSatParameters( pGModel->pModel );
                                    auto asExternalVar = Napi::External< SatParameters >::New( innerInfo.Env(), &ret );
                                    return GSatParameters::constructor.New( { asExternalVar } );
                                }
                            }

                            Napi::Error::New( innerInfo.Env(), ( char* )u8"GNewFeasibleSolutionObserver func_return ERROR" ).ThrowAsJavaScriptException();
                            return innerInfo.Env().Undefined();
                        }  //
                    );
            }
        }

        Napi::Error::New( outerInfo.Env(), ( char* )u8"GNewSatParameters ERROR" ).ThrowAsJavaScriptException();
        return outerInfo.Env().Undefined();
    }

    Napi::Value GCpSolverResponseStats( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsObject() )
        {
            GCpSolverResponse* pGCpSolverResponse = GCpSolverResponse::Unwrap( info[ 0 ].As< Napi::Object >() );
            if ( typeid( *pGCpSolverResponse ) == typeid( GCpSolverResponse ) )
            {
                auto vCpSolverResponse = CpSolverResponseStats( *pGCpSolverResponse->pCpSolverResponse );
                return Napi::String::New( info.Env(), vCpSolverResponse );
            }
        }

        ThrowJsError( GCpSolverResponseStats ERROR );
        return info.Env().Undefined();
    }

    Napi::Value GVarDebugString( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 2 && info[ 0 ].IsObject() && info[ 1 ].IsNumber() )
        {
            GCpModelProto* pGCpModelProto = GCpModelProto::Unwrap( info[ 0 ].As< Napi::Object >() );
            if ( typeid( *pGCpModelProto ) == typeid( GCpModelProto ) )
            {
                auto vstring = VarDebugString( *pGCpModelProto->pCpModelProto, info[ 1 ].As< Napi::Number >() );
                return Napi::String::New( info.Env(), vstring );
            }
        }

        ThrowJsError( GVarDebugString Error );
        return info.Env().Undefined();
    }

    Napi::Value GCpModelStats( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsObject() )
        {
            GCpModelProto* pGCpModelProto = GCpModelProto::Unwrap( info[ 0 ].As< Napi::Object >() );
            if ( typeid( *pGCpModelProto ) == typeid( GCpModelProto ) )
            {
                auto vstring = CpModelStats( *pGCpModelProto->pCpModelProto );
                return Napi::String::New( info.Env(), vstring );
            }
        }

        ThrowJsError( GCpModelStats Error );
        return info.Env().Undefined();
    }

    Napi::Object FuncInit( Napi::Env env, Napi::Object exports )
    {
        exports.Set( "Solve", Napi::Function::New( env, GSolve ) );
        exports.Set( "CpSolverResponseStats", Napi::Function::New( env, GCpSolverResponseStats ) );
        exports.Set( "SolutionIntegerValue", Napi::Function::New( env, GSolutionIntegerValue ) );
        exports.Set( "VarDebugString", Napi::Function::New( env, GVarDebugString ) );
        exports.Set( "CpModelStats", Napi::Function::New( env, GCpModelStats ) );
        exports.Set( "SolveCpModel", Napi::Function::New( env, GSolveCpModel ) );
        exports.Set( "NewFeasibleSolutionObserver", Napi::Function::New( env, GNewFeasibleSolutionObserver ) );
        exports.Set( "NewSatParameters", Napi::Function::New( env, GNewSatParameters ) );

        return exports;
    }

}  // namespace sat
}  // namespace operations_research
