#pragma once

#include "napi.h"
#include "ortools/sat/cp_model.h"
#include "IntVar.hpp"
#include "CpModelProto.hpp"
#include "TableConstraint.hpp"
#include "LinearExpr.hpp"
#include "NoOverlap2DConstraint.hpp"
#include "IntervalVar.hpp"

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
                    InstanceMethod( "Build", &GCpModelBuilder::Build ),
                    InstanceMethod( "AddEquality", &GCpModelBuilder::AddEquality ),
                    InstanceMethod( "AddLessOrEqual", &GCpModelBuilder::AddLessOrEqual ),
                    InstanceMethod( "NewIntVar", &GCpModelBuilder::NewIntVar ),
                    InstanceMethod( "AddGreaterThan", &GCpModelBuilder::AddGreaterThan ),
                    InstanceMethod( "AddAssumptions", &GCpModelBuilder::AddAssumptions ),
                    InstanceMethod( "AddBoolOr", &GCpModelBuilder::AddBoolOr ),
                    InstanceMethod( "NewOptionalFixedSizeIntervalVar", &GCpModelBuilder::NewOptionalFixedSizeIntervalVar ),
                    InstanceMethod( "AddNoOverlap2D", &GCpModelBuilder::AddNoOverlap2D ),
                    InstanceMethod( "AddGreaterOrEqual", &GCpModelBuilder::AddGreaterOrEqual ),
                    InstanceMethod( "AddImplication", &GCpModelBuilder::AddImplication ),
                } );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "CpModelBuilder" ), func );
            return exports;
        };

        Napi::Value AddImplication( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            // Constraint AddImplication( BoolVar a, BoolVar b );
            if ( info.Length() == 2
                 && info[ 0 ].IsObject()
                 && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() )
                 && info[ 1 ].IsObject()
                 && info[ 1 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
            {
                auto a      = GBoolVar::Unwrap( info[ 0 ].As< Napi::Object >() );
                auto b      = GBoolVar::Unwrap( info[ 1 ].As< Napi::Object >() );
                auto result = pCpModelBuilder->AddImplication( *a->pBoolVar, *b->pBoolVar );
                return GConstraint::constructor.New( { Napi::External< Constraint >::New( env, new Constraint( result ) ) } );
            }

            // Constraint AddImplication( absl::Span< const BoolVar >  lhs,
            //                           *absl::Span< const BoolVar > rhs )
            if ( info.Length() == 2
                 && info[ 0 ].IsArray()
                 && info[ 1 ].IsArray() )
            {
                auto                   lhsArray = info[ 0 ].As< Napi::Array >();
                auto                   rhsArray = info[ 1 ].As< Napi::Array >();
                std::vector< BoolVar > lhs;
                std::vector< BoolVar > rhs;
                for ( int i = 0; i < lhsArray.Length(); i++ )
                {
                    if ( lhsArray.Get( i ).IsObject() && lhsArray.Get( i ).As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
                    {
                        auto boolVar = GBoolVar::Unwrap( lhsArray.Get( i ).As< Napi::Object >() );
                        lhs.push_back( *boolVar->pBoolVar );
                    }
                    else
                    {
                        Napi::TypeError::New( env, "operations_research::GCpModelBuilder::AddImplication : Invalid arguments" ).ThrowAsJavaScriptException();
                        return env.Null();
                    }
                }
                for ( int i = 0; i < rhsArray.Length(); i++ )
                {
                    if ( rhsArray.Get( i ).IsObject() && rhsArray.Get( i ).As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
                    {
                        auto boolVar = GBoolVar::Unwrap( rhsArray.Get( i ).As< Napi::Object >() );
                        rhs.push_back( *boolVar->pBoolVar );
                    }
                    else
                    {
                        Napi::TypeError::New( env, "operations_research::GCpModelBuilder::AddImplication : Invalid arguments" ).ThrowAsJavaScriptException();
                        return env.Null();
                    }
                }
                auto result = pCpModelBuilder->AddImplication( lhs, rhs );
                return GConstraint::constructor.New( { Napi::External< Constraint >::New( env, new Constraint( result ) ) } );
            }

            Napi::TypeError::New( env, "operations_research::GCpModelBuilder::AddImplication : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };

        // Constraint AddGreaterOrEqual( const LinearExpr& left, const LinearExpr& right );
        Napi::Value AddGreaterOrEqual( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            LinearExpr left, right;
            if ( info.Length() == 2
                 && GLinearExpr::ToLinearExpr( info[ 0 ], left )
                 && GLinearExpr::ToLinearExpr( info[ 1 ], right ) )
            {
                auto result = pCpModelBuilder->AddGreaterOrEqual( left, right );
                return GConstraint::constructor.New( { Napi::External< Constraint >::New( env, new Constraint( result ) ) } );
            }

            Napi::TypeError::New( env, "operations_research::GCpModelBuilder::AddGreaterOrEqual : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };

        // NoOverlap2DConstraint AddNoOverlap2D();
        Napi::Value AddNoOverlap2D( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 0 )
            {
                auto result = pCpModelBuilder->AddNoOverlap2D();
                return GNoOverlap2DConstraint::constructor.New( { Napi::External< NoOverlap2DConstraint >::New( env, new NoOverlap2DConstraint( result ) ) } );
            }

            Napi::TypeError::New( env, "operations_research::GCpModelBuilder::AddNoOverlap2D : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };

        //    IntervalVar NewOptionalFixedSizeIntervalVar( const LinearExpr& start,
        //                                                 int64_t size, BoolVar presence );
        Napi::Value NewOptionalFixedSizeIntervalVar( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            LinearExpr start;
            if ( info.Length() == 3
                 && GLinearExpr::ToLinearExpr( info[ 0 ], start )
                 && info[ 1 ].IsNumber()
                 && info[ 2 ].IsObject()
                 && info[ 2 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
            {
                auto size     = info[ 1 ].As< Napi::Number >().Int64Value();
                auto presence = GBoolVar::Unwrap( info[ 2 ].As< Napi::Object >() );
                auto result   = pCpModelBuilder->NewOptionalFixedSizeIntervalVar( start, size, *presence->pBoolVar );
                auto external = Napi::External< IntervalVar >::New( env, new IntervalVar( result ) );
                return GIntervalVar::constructor.New( { external } );
            }

            Napi::TypeError::New( env, "operations_research::GCpModelBuilder::NewOptionalFixedSizeIntervalVar : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };

        // Constraint AddBoolOr( absl::Span< const BoolVar > literals );
        Napi::Value AddBoolOr( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 1
                 && info[ 0 ].IsArray() )
            {
                auto                   array = info[ 0 ].As< Napi::Array >();
                std::vector< BoolVar > literals;
                for ( int i = 0; i < array.Length(); i++ )
                {
                    if ( array.Get( i ).IsObject() && array.Get( i ).As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
                    {
                        auto boolVar = GBoolVar::Unwrap( array.Get( i ).As< Napi::Object >() );
                        literals.push_back( *boolVar->pBoolVar );
                    }
                    else
                    {
                        Napi::TypeError::New( env, "operations_research::GCpModelBuilder::AddBoolOr : Invalid arguments" ).ThrowAsJavaScriptException();
                        return env.Null();
                    }
                }
                auto result = pCpModelBuilder->AddBoolOr( literals );
                return GConstraint::constructor.New( { Napi::External< Constraint >::New( env, new Constraint( result ) ) } );
            }

            Napi::TypeError::New( env, "operations_research::GCpModelBuilder::AddBoolOr : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };

        // void AddAssumptions( absl::Span< const BoolVar > literals );
        Napi::Value AddAssumptions( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 1
                 && info[ 0 ].IsArray() )
            {
                auto                   array = info[ 0 ].As< Napi::Array >();
                std::vector< BoolVar > literals;
                for ( int i = 0; i < array.Length(); i++ )
                {
                    if ( array.Get( i ).IsObject() && array.Get( i ).As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
                    {
                        auto boolVar = GBoolVar::Unwrap( array.Get( i ).As< Napi::Object >() );
                        literals.push_back( *boolVar->pBoolVar );
                    }
                    else
                    {
                        Napi::TypeError::New( env, "operations_research::GCpModelBuilder::AddAssumptions : Invalid arguments" ).ThrowAsJavaScriptException();
                        return env.Null();
                    }
                }
                pCpModelBuilder->AddAssumptions( literals );
                return env.Undefined();
            }

            Napi::TypeError::New( env, "operations_research::GCpModelBuilder::AddAssumptions : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };

        // Constraint AddGreaterThan( const LinearExpr& left, const LinearExpr& right );
        Napi::Value AddGreaterThan( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            LinearExpr left, right;
            if ( info.Length() == 2
                 && GLinearExpr::ToLinearExpr( info[ 0 ], left )
                 && GLinearExpr::ToLinearExpr( info[ 1 ], right ) )
            {
                auto result = pCpModelBuilder->AddGreaterThan( left, right );
                return GConstraint::constructor.New( { Napi::External< Constraint >::New( env, new Constraint( result ) ) } );
            }

            Napi::TypeError::New( env, "operations_research::GCpModelBuilder::AddGreaterThan : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };

        // IntVar NewIntVar( const Domain& domain );
        Napi::Value NewIntVar( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            if ( info.Length() == 1
                 && info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GDomain::constructor.Value() ) )
            {
                auto domain   = GDomain::Unwrap( info[ 0 ].As< Napi::Object >() );
                auto result   = pCpModelBuilder->NewIntVar( *domain->pDomain );
                auto external = Napi::External< IntVar >::New( env, new IntVar( result ) );
                return GIntVar::constructor.New( { external } );
            }

            Napi::TypeError::New( env, "operations_research::GCpModelBuilder::NewIntVar : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
        };

        // Constraint AddLessOrEqual( const LinearExpr& left, const LinearExpr& right );
        Napi::Value AddLessOrEqual( const Napi::CallbackInfo& info )
        {
            Napi::Env         env = info.Env();
            Napi::HandleScope scope( env );

            LinearExpr left, right;
            if ( info.Length() == 2 && GLinearExpr::ToLinearExpr( info[ 0 ], left ) && GLinearExpr::ToLinearExpr( info[ 1 ], right ) )
            {
                auto result = pCpModelBuilder->AddLessOrEqual( left, right );
                return GConstraint::constructor.New( { Napi::External< Constraint >::New( env, new Constraint( result ) ) } );
            }

            Napi::TypeError::New( env, "operations_research::GCpModelBuilder::AddLessOrEqual : Invalid arguments" ).ThrowAsJavaScriptException();
            return env.Null();
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

            LinearExpr expr;
            if ( info.Length() == 1
                 && GLinearExpr::ToLinearExpr( info[ 0 ], expr ) )
            {
                pCpModelBuilder->Minimize( expr );
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