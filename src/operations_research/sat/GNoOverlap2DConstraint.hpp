#pragma once

#include <napi.h>
#include "commonheader.hpp"
#include "ortools/sat/cp_model.h"
#include "GIntervalVar.hpp"

namespace operations_research
{
namespace sat
{
    class GNoOverlap2DConstraint : public Napi::ObjectWrap< GNoOverlap2DConstraint >
    {
    public:
        static Napi::FunctionReference constructor;
        NoOverlap2DConstraint*         pNoOverlap2DConstraint = nullptr;
        GNoOverlap2DConstraint( const Napi::CallbackInfo& info );
        ~GNoOverlap2DConstraint();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );

        Napi::Value AddRectangle( const Napi::CallbackInfo& info );
    };
};  // namespace sat
};  // namespace operations_research

Napi::FunctionReference operations_research::sat::GNoOverlap2DConstraint::constructor;

inline operations_research::sat::GNoOverlap2DConstraint::GNoOverlap2DConstraint( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GNoOverlap2DConstraint >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external          = info[ 0 ].As< Napi::External< NoOverlap2DConstraint > >();
        pNoOverlap2DConstraint = dynamic_cast< NoOverlap2DConstraint* >( external.Data() );
        if ( pNoOverlap2DConstraint != nullptr ) return;
    }

    ThrowJsError( operations_research::GNoOverlap2DConstraint::GNoOverlap2DConstraint : Invalid argument );
}

inline operations_research::sat::GNoOverlap2DConstraint::~GNoOverlap2DConstraint()
{
    delete pNoOverlap2DConstraint;
}

inline Napi::Object operations_research::sat::GNoOverlap2DConstraint::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "NoOverlap2DConstraint",
        {
            InstanceMethod( "AddRectangle", &GNoOverlap2DConstraint::AddRectangle ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "NoOverlap2DConstraint" ), func );
    return exports;
}

inline Napi::Value operations_research::sat::GNoOverlap2DConstraint::AddRectangle( const Napi::CallbackInfo& info )
{
    //  void AddRectangle(IntervalVar x_coordinate, IntervalVar y_coordinate);
    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GIntervalVar::constructor.Value() )
         && info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GIntervalVar::constructor.Value() ) )
    {
        auto x_coordinate = GIntervalVar::Unwrap( info[ 0 ].As< Napi::Object >() );
        auto y_coordinate = GIntervalVar::Unwrap( info[ 1 ].As< Napi::Object >() );
        pNoOverlap2DConstraint->AddRectangle( *x_coordinate->pIntervalVar, *y_coordinate->pIntervalVar );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GNoOverlap2DConstraint::AddRectangle : Invalid argument );
    return info.Env().Undefined();
}
