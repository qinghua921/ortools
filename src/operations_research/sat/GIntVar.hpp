#pragma once

#include <napi.h>
#include "ortools/sat/cp_model.h"
#include "../../commonheader.hpp"

namespace operations_research
{
namespace sat
{

    class GIntVar : public Napi::ObjectWrap< GIntVar >
    {
    public:
        static Napi::FunctionReference constructor;
        IntVar*                        pIntVar = nullptr;

        GIntVar( const Napi::CallbackInfo& info )
            : Napi::ObjectWrap< GIntVar >( info )
        {
            //     IntVar() = default;
            if ( info.Length() == 0 )
            {
                pIntVar = new IntVar();
                return;
            }

            ThrowJsError( GIntVar::GIntVar : Invalid number of arguments );
        };

        ~GIntVar()
        {
            if ( pIntVar )
            {
                delete pIntVar;
                pIntVar = nullptr;
            }
        }

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "IntVar",
                {} );
            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( "IntVar", func );
            return exports;
        };

        //     /// Cast BoolVar -> IntVar.
        //     /// The IntVar will take the value 1 (when the bool is true) and 0 otherwise.
        //     ///
        //     /// Warning: If you construct an IntVar from a negated BoolVar, this might
        //     /// create a new variable in the model. Otherwise this just point to the same
        //     /// underlying variable.
        //     explicit IntVar( const BoolVar& var );

        //     /// Cast IntVar -> BoolVar.
        //     ///
        //     /// Warning: The domain of the var must be within {0,1}. If not, we crash
        //     /// in debug mode, and in opt mode you will get an invalid model if you use
        //     /// this BoolVar anywhere since it will not have a valid domain.
        //     BoolVar ToBoolVar() const;

        //     /// Sets the name of the variable.
        //     IntVar WithName( const std::string& name );

        //     /// Returns the name of the variable (or the empty string if not set).
        //     std::string Name() const;

        //     bool operator==( const IntVar& other ) const
        //     {
        //         return other.builder_ == builder_ && other.index_ == index_;
        //     }

        //     bool operator!=( const IntVar& other ) const
        //     {
        //         return other.builder_ != builder_ || other.index_ != index_;
        //     }

        //     // Returns the domain of the variable.
        //     // Note that we keep the fully qualified return type as compilation fails with
        //     // gcc otherwise.
        //     ::operations_research::Domain Domain() const;

        //     std::string DebugString() const;

        //     /// Returns the index of the variable in the model. This will be non-negative.
        //     int index() const
        //     {
        //         return index_;
        //     }

        // };
    };

    Napi::FunctionReference GIntVar::constructor;

};  // namespace sat
};  // namespace operations_research