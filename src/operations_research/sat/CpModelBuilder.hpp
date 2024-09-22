#pragma once

#include "napi.h"
#include "ortools/sat/cp_model.h"
#include "IntVar.hpp"
#include "CpModelProto.hpp"
#include "TableConstraint.hpp"
#include "./LinearExpr.hpp"

namespace operations_research
{
namespace sat
{

    class GCpModelBuilder : public Napi::ObjectWrap< GCpModelBuilder >
    {
    public:
        static inline Napi::FunctionReference constructor;
        CpModelBuilder*                       pCpModelBuilder = nullptr;

        GCpModelBuilder( const Napi::CallbackInfo& info )
            : Napi::ObjectWrap< GCpModelBuilder >( info )
        {
            Napi::Env env = info.Env();

            if ( info.Length() == 1 && info[ 0 ].IsExternal() )
            {
                auto external   = info[ 0 ].As< Napi::External< CpModelBuilder > >();
                pCpModelBuilder = dynamic_cast< CpModelBuilder* >( external.Data() );
                if ( pCpModelBuilder ) return;
            }

            if ( info.Length() == 0 )
            {
                pCpModelBuilder = new CpModelBuilder();
                return;
            }

            Napi::TypeError::New( env, "operations_research::GCpModelBuilder::GCpModelBuilder : Invalid arguments" ).ThrowAsJavaScriptException();
        };

        ~GCpModelBuilder()
        {
            if ( pCpModelBuilder ) delete pCpModelBuilder;
        };

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "CpModelBuilder",
                {
                    InstanceMethod( "NewBoolVar", &GCpModelBuilder::NewBoolVar ),
                    InstanceMethod( "AddAtMostOne", &GCpModelBuilder::AddAtMostOne ),
                    InstanceMethod( "AddExactlyOne", &GCpModelBuilder::AddExactlyOne ),
                    InstanceMethod( "AddAllowedAssignments", &GCpModelBuilder::AddAllowedAssignments ),
                    InstanceMethod( "Minimize", &GCpModelBuilder::Minimize ),
                    InstanceMethod( "AddEquality", &GCpModelBuilder::AddEquality ),
                } );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "CpModelBuilder" ), func );
            return exports;
        };

        // Constraint AddEquality( const LinearExpr& left, const LinearExpr& right );
        Napi::Value AddEquality( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            LinearExpr left, right;
            if ( info.Length() == 2 && GLinearExpr::ToLinearExpr( info[ 0 ], left ) && GLinearExpr::ToLinearExpr( info[ 1 ], right ) )
            {
                auto result = pCpModelBuilder->AddEquality( left, right );
                return GConstraint::constructor.New( { Napi::External< Constraint >::New( env, new Constraint( result ) ) } );
            }

            Napi::TypeError::New( env, "operations_research::GCpModelBuilder::AddEquality : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };

        // const CpModelProto& Build() const;
        Napi::Value Build( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 0 )
            {
                auto result   = pCpModelBuilder->Build();
                auto external = Napi::External< CpModelProto >::New( env, new CpModelProto( result ) );
                return GCpModelProto::constructor.New( { external } );
            }

            Napi::TypeError::New( env, "operations_research::GCpModelBuilder::Build : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };

        // void Minimize( const LinearExpr& expr );
        Napi::Value Minimize( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 1 && info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
            {
                auto linear_expr = GLinearExpr::Unwrap( info[ 0 ].As< Napi::Object >() );
                pCpModelBuilder->Minimize( ( const LinearExpr& )*linear_expr->pLinearExpr );
                return env.Undefined();
            }

            Napi::TypeError::New( env, "operations_research::GCpModelBuilder::Minimize : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };

        // TableConstraint AddAllowedAssignments( absl::Span< const IntVar > vars );
        Napi::Value AddAllowedAssignments( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 1 && info[ 0 ].IsArray() )
            {
                auto                  vars = info[ 0 ].As< Napi::Array >();
                std::vector< IntVar > int_vars;
                for ( int i = 0; i < vars.Length(); i++ )
                {
                    auto int_var = GIntVar::Unwrap( vars.Get( i ).As< Napi::Object >() );
                    int_vars.push_back( *int_var->pIntVar );
                }
                auto result = pCpModelBuilder->AddAllowedAssignments( int_vars );
                return GTableConstraint::constructor.New( { Napi::External< TableConstraint >::New( env, new TableConstraint( result ) ) } );
            }

            Napi::TypeError::New( env, "operations_research::GCpModelBuilder::AddAllowedAssignments : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };

        // Constraint AddExactlyOne( absl::Span< const BoolVar > literals );
        Napi::Value AddExactlyOne( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 1 && info[ 0 ].IsArray() )
            {
                auto                   literals = info[ 0 ].As< Napi::Array >();
                std::vector< BoolVar > bool_vars;
                for ( int i = 0; i < literals.Length(); i++ )
                {
                    auto bool_var = GBoolVar::Unwrap( literals.Get( i ).As< Napi::Object >() );
                    bool_vars.push_back( *bool_var->pBoolVar );
                }
                auto result = pCpModelBuilder->AddExactlyOne( bool_vars );
                return GConstraint::constructor.New( { Napi::External< Constraint >::New( env, new Constraint( result ) ) } );
            }

            Napi::TypeError::New( env, "operations_research::GCpModelBuilder::AddExactlyOne : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };

        // Constraint AddAtMostOne( absl::Span< const BoolVar > literals );
        Napi::Value AddAtMostOne( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 1 && info[ 0 ].IsArray() )
            {
                auto                   literals = info[ 0 ].As< Napi::Array >();
                std::vector< BoolVar > bool_vars;
                for ( int i = 0; i < literals.Length(); i++ )
                {
                    auto bool_var = GBoolVar::Unwrap( literals.Get( i ).As< Napi::Object >() );
                    bool_vars.push_back( *bool_var->pBoolVar );
                }
                auto result = pCpModelBuilder->AddAtMostOne( bool_vars );
                return GConstraint::constructor.New( { Napi::External< Constraint >::New( env, new Constraint( result ) ) } );
            }

            Napi::TypeError::New( env, "operations_research::GCpModelBuilder::AddAtMostOne : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };

        // BoolVar NewBoolVar();
        Napi::Value NewBoolVar( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 0 )
            {
                auto result   = pCpModelBuilder->NewBoolVar();
                auto external = Napi::External< BoolVar >::New( env, new BoolVar( result ) );
                return GBoolVar::constructor.New( { external } );
            }

            Napi::TypeError::New( env, "operations_research::GCpModelBuilder::NewBoolVar : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };
    };
}  // namespace sat

};  // namespace operations_research