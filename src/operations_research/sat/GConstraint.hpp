#pragma once

#include <napi.h>
#include "ortools/sat/cp_model.h"
#include "../../commonheader.hpp"

namespace operations_research
{
namespace sat
{

    class GConstraint : public Napi::ObjectWrap< GConstraint >
    {
    public:
        static Napi::FunctionReference constructor;
        Constraint*                    pConstraint = nullptr;

        GConstraint( const Napi::CallbackInfo& info )
            : Napi::ObjectWrap< GConstraint >( info )
        {
            if ( info.Length() == 1 && info[ 0 ].IsExternal() )
            {
                auto external = info[ 0 ].As< Napi::External< Constraint > >();
                pConstraint   = dynamic_cast< Constraint* >( external.Data() );
                if ( pConstraint != nullptr ) return;
            }

            ThrowJsError( GConstraint::GConstraint : constructor called with invalid arguments );
        }

        ~GConstraint()
        {
            if ( pConstraint != nullptr )
            {
                delete pConstraint;
                pConstraint = nullptr;
            }
        };

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "Constraint",
                {} );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( "Constraint", func );
            return exports;
        };

        // class Constraint
        // {
        // public:
        //     /**
        //      * The constraint will be enforced iff all literals listed here are true.
        //      *
        //      * If this is empty, then the constraint will always be enforced. An enforced
        //      * constraint must be satisfied, and an un-enforced one will simply be
        //      * ignored.
        //      *
        //      * This is also called half-reification. To have an equivalence between a
        //      * literal and a constraint (full reification), one must add both a constraint
        //      * (controlled by a literal l) and its negation (controlled by the negation of
        //      * l).
        //      *
        //      * [Important] currently, only a few constraints support enforcement:
        //      * - bool_or, bool_and, linear: fully supported.
        //      * - interval: only support a single enforcement literal.
        //      * - other: no support (but can be added on a per-demand basis).
        //      */
        //     Constraint OnlyEnforceIf( absl::Span< const BoolVar > literals );

        //     /// See OnlyEnforceIf(absl::Span<const BoolVar> literals).
        //     Constraint OnlyEnforceIf( BoolVar literal );

        //     /// Sets the name of the constraint.
        //     Constraint WithName( const std::string& name );

        //     /// Returns the name of the constraint (or the empty string if not set).
        //     const std::string& Name() const;

        //     /// Returns the underlying protobuf object (useful for testing).
        //     const ConstraintProto& Proto() const
        //     {
        //         return *proto_;
        //     }

        //     /// Returns the mutable underlying protobuf object (useful for model edition).
        //     ConstraintProto* MutableProto() const
        //     {
        //         return proto_;
        //     }

        // };
    };

    Napi::FunctionReference GConstraint::constructor;

}  // namespace sat
}  // namespace operations_research