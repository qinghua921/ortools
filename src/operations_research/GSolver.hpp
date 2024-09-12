#pragma once

#include "commonheader.hpp"
#include "ortools/constraint_solver/constraint_solver.h"
#include "GIntVar.hpp"
#include "GConstraint.hpp"
#include "GDecisionBuilder.hpp"
#include "GSequenceVar.hpp"
#include "GIntervalVar.hpp"

namespace operations_research
{
class GSolver : public Napi::ObjectWrap< GSolver >
{
    CommonProperties( Solver );

    Napi::Value MakeIntVar( const Napi::CallbackInfo& info );
    Napi::Value MakeAllDifferent( const Napi::CallbackInfo& info );
    Napi::Value AddConstraint( const Napi::CallbackInfo& info );
    Napi::Value MakePhase_01( const Napi::CallbackInfo& info );
    Napi::Value MakePhase_02( const Napi::CallbackInfo& info );
    Napi::Value MakePhase_03( const Napi::CallbackInfo& info );
    Napi::Value MakePhase_04( const Napi::CallbackInfo& info );
    Napi::Value MakePhase_05( const Napi::CallbackInfo& info );
    Napi::Value MakePhase_06( const Napi::CallbackInfo& info );
    Napi::Value MakePhase_07( const Napi::CallbackInfo& info );
    Napi::Value MakePhase_08( const Napi::CallbackInfo& info );
    Napi::Value MakePhase_09( const Napi::CallbackInfo& info );
    Napi::Value MakePhase_10( const Napi::CallbackInfo& info );
    Napi::Value MakePhase_11( const Napi::CallbackInfo& info );
    Napi::Value MakePhase_12( const Napi::CallbackInfo& info );
    Napi::Value MakePhase_13( const Napi::CallbackInfo& info );
    Napi::Value MakePhase_14( const Napi::CallbackInfo& info );
    Napi::Value MakePhase_15( const Napi::CallbackInfo& info );
};
};  // namespace operations_research

inline operations_research::GSolver::GSolver( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< operations_research::GSolver >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< Solver > >();
        spSolver      = std::shared_ptr< Solver >( external.Data() );
        return;
    }

    //      explicit Solver(const std::string& name);
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string name = info[ 0 ].As< Napi::String >().Utf8Value();
        spSolver         = std::make_shared< Solver >( name );
        return;
    }

    ThrowJsError( operations_research::GSolver::GSolver : Invalid argument );
}

inline Napi::Object operations_research::GSolver::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );

    //     export enum IntVarStrategy
    auto intVarStrategy = Napi::Object::New( env );
    intVarStrategy.Set( Napi::String::New( env, "INT_VAR_DEFAULT" ), Napi::Number::New( env, Solver::INT_VAR_DEFAULT ) );
    intVarStrategy.Set( Napi::String::New( env, "INT_VAR_SIMPLE" ), Napi::Number::New( env, Solver::INT_VAR_SIMPLE ) );
    intVarStrategy.Set( Napi::String::New( env, "CHOOSE_FIRST_UNBOUND" ), Napi::Number::New( env, Solver::CHOOSE_FIRST_UNBOUND ) );
    intVarStrategy.Set( Napi::String::New( env, "CHOOSE_RANDOM" ), Napi::Number::New( env, Solver::CHOOSE_RANDOM ) );
    intVarStrategy.Set( Napi::String::New( env, "CHOOSE_MIN_SIZE_LOWEST_MIN" ), Napi::Number::New( env, Solver::CHOOSE_MIN_SIZE_LOWEST_MIN ) );
    intVarStrategy.Set( Napi::String::New( env, "CHOOSE_MIN_SIZE_HIGHEST_MIN" ), Napi::Number::New( env, Solver::CHOOSE_MIN_SIZE_HIGHEST_MIN ) );
    intVarStrategy.Set( Napi::String::New( env, "CHOOSE_MIN_SIZE_LOWEST_MAX" ), Napi::Number::New( env, Solver::CHOOSE_MIN_SIZE_LOWEST_MAX ) );
    intVarStrategy.Set( Napi::String::New( env, "CHOOSE_MIN_SIZE_HIGHEST_MAX" ), Napi::Number::New( env, Solver::CHOOSE_MIN_SIZE_HIGHEST_MAX ) );
    intVarStrategy.Set( Napi::String::New( env, "CHOOSE_LOWEST_MIN" ), Napi::Number::New( env, Solver::CHOOSE_LOWEST_MIN ) );
    intVarStrategy.Set( Napi::String::New( env, "CHOOSE_HIGHEST_MAX" ), Napi::Number::New( env, Solver::CHOOSE_HIGHEST_MAX ) );
    intVarStrategy.Set( Napi::String::New( env, "CHOOSE_MIN_SIZE" ), Napi::Number::New( env, Solver::CHOOSE_MIN_SIZE ) );
    intVarStrategy.Set( Napi::String::New( env, "CHOOSE_MAX_SIZE" ), Napi::Number::New( env, Solver::CHOOSE_MAX_SIZE ) );
    intVarStrategy.Set( Napi::String::New( env, "CHOOSE_MAX_REGRET_ON_MIN" ), Napi::Number::New( env, Solver::CHOOSE_MAX_REGRET_ON_MIN ) );
    intVarStrategy.Set( Napi::String::New( env, "CHOOSE_PATH" ), Napi::Number::New( env, Solver::CHOOSE_PATH ) );

    // export enum IntValueStrategy
    auto intValueStrategy = Napi::Object::New( env );
    intValueStrategy.Set( Napi::String::New( env, "INT_VALUE_DEFAULT" ), Napi::Number::New( env, Solver::INT_VALUE_DEFAULT ) );
    intValueStrategy.Set( Napi::String::New( env, "INT_VALUE_SIMPLE" ), Napi::Number::New( env, Solver::INT_VALUE_SIMPLE ) );
    intValueStrategy.Set( Napi::String::New( env, "ASSIGN_MIN_VALUE" ), Napi::Number::New( env, Solver::ASSIGN_MIN_VALUE ) );
    intValueStrategy.Set( Napi::String::New( env, "ASSIGN_MAX_VALUE" ), Napi::Number::New( env, Solver::ASSIGN_MAX_VALUE ) );
    intValueStrategy.Set( Napi::String::New( env, "ASSIGN_RANDOM_VALUE" ), Napi::Number::New( env, Solver::ASSIGN_RANDOM_VALUE ) );
    intValueStrategy.Set( Napi::String::New( env, "ASSIGN_CENTER_VALUE" ), Napi::Number::New( env, Solver::ASSIGN_CENTER_VALUE ) );
    intValueStrategy.Set( Napi::String::New( env, "SPLIT_LOWER_HALF" ), Napi::Number::New( env, Solver::SPLIT_LOWER_HALF ) );
    intValueStrategy.Set( Napi::String::New( env, "SPLIT_UPPER_HALF" ), Napi::Number::New( env, Solver::SPLIT_UPPER_HALF ) );

    // export enum SequenceStrategy
    // {
    //     SEQUENCE_DEFAULT,
    //     SEQUENCE_SIMPLE,
    //     CHOOSE_MIN_SLACK_RANK_FORWARD,
    //     CHOOSE_RANDOM_RANK_FORWARD,
    // };
    auto sequenceStrategy = Napi::Object::New( env );
    sequenceStrategy.Set( Napi::String::New( env, "SEQUENCE_DEFAULT" ), Napi::Number::New( env, Solver::SEQUENCE_DEFAULT ) );
    sequenceStrategy.Set( Napi::String::New( env, "SEQUENCE_SIMPLE" ), Napi::Number::New( env, Solver::SEQUENCE_SIMPLE ) );
    sequenceStrategy.Set( Napi::String::New( env, "CHOOSE_MIN_SLACK_RANK_FORWARD" ), Napi::Number::New( env, Solver::CHOOSE_MIN_SLACK_RANK_FORWARD ) );
    sequenceStrategy.Set( Napi::String::New( env, "CHOOSE_RANDOM_RANK_FORWARD" ), Napi::Number::New( env, Solver::CHOOSE_RANDOM_RANK_FORWARD ) );


    Napi::Function func = DefineClass(
        env, "Solver",
        {
            StaticValue( "IntVarStrategy", intVarStrategy ),
            StaticValue( "IntValueStrategy", intValueStrategy ),
            StaticValue( "SequenceStrategy", sequenceStrategy ),
            InstanceMethod( "MakeIntVar", &GSolver::MakeIntVar ),
            InstanceMethod( "MakeAllDifferent", &GSolver::MakeAllDifferent ),
            InstanceMethod( "AddConstraint", &GSolver::AddConstraint ),
            InstanceMethod( "MakePhase_01", &GSolver::MakePhase_01 ),
            InstanceMethod( "MakePhase_02", &GSolver::MakePhase_02 ),
            InstanceMethod( "MakePhase_03", &GSolver::MakePhase_03 ),
            InstanceMethod( "MakePhase_04", &GSolver::MakePhase_04 ),
            InstanceMethod( "MakePhase_05", &GSolver::MakePhase_05 ),
            InstanceMethod( "MakePhase_06", &GSolver::MakePhase_06 ),
            InstanceMethod( "MakePhase_07", &GSolver::MakePhase_07 ),
            InstanceMethod( "MakePhase_08", &GSolver::MakePhase_08 ),
            InstanceMethod( "MakePhase_09", &GSolver::MakePhase_09 ),
            InstanceMethod( "MakePhase_10", &GSolver::MakePhase_10 ),
            InstanceMethod( "MakePhase_11", &GSolver::MakePhase_11 ),
            InstanceMethod( "MakePhase_12", &GSolver::MakePhase_12 ),
            InstanceMethod( "MakePhase_13", &GSolver::MakePhase_13 ),
            InstanceMethod( "MakePhase_14", &GSolver::MakePhase_14 ),
            InstanceMethod( "MakePhase_15", &GSolver::MakePhase_15 ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "Solver" ), func );
    return exports;
}

inline Napi::Value operations_research::GSolver::MakePhase_01( const Napi::CallbackInfo& info )
{
    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IntVarStrategy var_str, IntValueStrategy val_str);
    if ( info.Length() == 3 && info[ 0 ].IsArray() && info[ 1 ].IsNumber() && info[ 2 ].IsNumber() )
    {
        std::vector< IntVar* > vars;
        Napi::Array            arr = info[ 0 ].As< Napi::Array >();

        for ( int i = 0; i < arr.Length(); i++ )
        {
            if ( arr.Get( i ).As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
            {
                auto gi = GIntVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                vars.push_back( gi->spIntVar.get() );
                continue;
            }
            ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
            return info.Env().Undefined();
        }

        Solver::IntVarStrategy   var_str = static_cast< Solver::IntVarStrategy >( info[ 1 ].As< Napi::Number >().Int32Value() );
        Solver::IntValueStrategy val_str = static_cast< Solver::IntValueStrategy >( info[ 2 ].As< Napi::Number >().Int32Value() );

        auto external = Napi::External< DecisionBuilder >::New( info.Env(), spSolver->MakePhase( vars, var_str, val_str ) );
        return GDecisionBuilder::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSolver::MakePhase_02( const Napi::CallbackInfo& info )
{
    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IndexEvaluator1 var_evaluator,
    //                                 IntValueStrategy val_str);
    if ( info.Length() == 3 && info[ 0 ].IsArray() && info[ 1 ].IsFunction() && info[ 2 ].IsNumber() )
    {
        std::vector< IntVar* > vars;
        Napi::Array            arr = info[ 0 ].As< Napi::Array >();

        for ( int i = 0; i < arr.Length(); i++ )
        {
            if ( arr.Get( i ).As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
            {
                auto gi = GIntVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                vars.push_back( gi->spIntVar.get() );
                continue;
            }

            ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
            return info.Env().Undefined();
        }

        auto indexEvaluator1 = info[ 1 ].As< Napi::Function >();
        auto indexEvaluator  = [ indexEvaluator1 ]( int64_t index ) {
            Napi::Env         env = indexEvaluator1.Env();
            Napi::HandleScope scope( env );
            auto              arg = Napi::Number::New( env, index );
            auto              res = indexEvaluator1.Call( { arg } );
            return res.As< Napi::Number >().Int64Value();
        };

        Solver::IntValueStrategy val_str = static_cast< Solver::IntValueStrategy >( info[ 2 ].As< Napi::Number >().Int32Value() );

        auto external = Napi::External< DecisionBuilder >::New( info.Env(), spSolver->MakePhase( vars, indexEvaluator, val_str ) );
        return GDecisionBuilder::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSolver::MakePhase_03( const Napi::CallbackInfo& info )
{
    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IntVarStrategy var_str,
    //                                 IndexEvaluator2 value_evaluator);
    if ( info.Length() == 3 && info[ 0 ].IsArray() && info[ 1 ].IsNumber() && info[ 2 ].IsFunction() )
    {
        std::vector< IntVar* > vars;
        Napi::Array            arr = info[ 0 ].As< Napi::Array >();

        for ( int i = 0; i < arr.Length(); i++ )
        {
            if ( arr.Get( i ).As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
            {
                auto gi = GIntVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                vars.push_back( gi->spIntVar.get() );
                continue;
            }

            ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
            return info.Env().Undefined();
        }

        Solver::IntVarStrategy var_str         = static_cast< Solver::IntVarStrategy >( info[ 1 ].As< Napi::Number >().Int32Value() );
        auto                   indexEvaluator2 = info[ 2 ].As< Napi::Function >();
        auto                   indexEvaluator  = [ indexEvaluator2 ]( int64_t index, int64_t index1 ) {
            Napi::Env         env = indexEvaluator2.Env();
            Napi::HandleScope scope( env );
            auto              arg  = Napi::Number::New( env, index );
            auto              arg1 = Napi::Number::New( env, index1 );
            auto              res  = indexEvaluator2.Call( { arg, arg1 } );
            return res.As< Napi::Number >().Int64Value();
        };

        auto external = Napi::External< DecisionBuilder >::New( info.Env(), spSolver->MakePhase( vars, var_str, indexEvaluator ) );
        return GDecisionBuilder::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSolver::MakePhase_04( const Napi::CallbackInfo& info )
{
    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IntVarStrategy var_str,
    //                                 VariableValueComparator var_val1_val2_comparator);
    if ( info.Length() == 3 && info[ 0 ].IsArray() && info[ 1 ].IsNumber() && info[ 2 ].IsFunction() )
    {
        std::vector< IntVar* > vars;
        Napi::Array            arr = info[ 0 ].As< Napi::Array >();

        for ( int i = 0; i < arr.Length(); i++ )
        {
            if ( arr.Get( i ).As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
            {
                auto gi = GIntVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                vars.push_back( gi->spIntVar.get() );
                continue;
            }

            ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
            return info.Env().Undefined();
        }

        Solver::IntVarStrategy var_str                  = static_cast< Solver::IntVarStrategy >( info[ 1 ].As< Napi::Number >().Int32Value() );
        auto                   var_val1_val2_comparator = info[ 2 ].As< Napi::Function >();
        auto                   comparator               = [ var_val1_val2_comparator ]( int64_t val1, int64_t val2, int64_t var3 ) {
            Napi::Env         env = var_val1_val2_comparator.Env();
            Napi::HandleScope scope( env );
            auto              arg1 = Napi::Number::New( env, val1 );
            auto              arg2 = Napi::Number::New( env, val2 );
            auto              arg3 = Napi::Number::New( env, var3 );
            auto              res  = var_val1_val2_comparator.Call( { arg1, arg2, arg3 } );
            return res.As< Napi::Boolean >().Value();
        };

        auto external = Napi::External< DecisionBuilder >::New( info.Env(), spSolver->MakePhase( vars, var_str, comparator ) );
        return GDecisionBuilder::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSolver::MakePhase_05( const Napi::CallbackInfo& info )
{
    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IndexEvaluator1 var_evaluator,
    //                                 IndexEvaluator2 value_evaluator);
    if ( info.Length() == 3 && info[ 0 ].IsArray() && info[ 1 ].IsFunction() && info[ 2 ].IsFunction() )
    {
        std::vector< IntVar* > vars;
        Napi::Array            arr = info[ 0 ].As< Napi::Array >();

        for ( int i = 0; i < arr.Length(); i++ )
        {
            if ( arr.Get( i ).As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
            {
                auto gi = GIntVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                vars.push_back( gi->spIntVar.get() );
                continue;
            }

            ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
            return info.Env().Undefined();
        }

        auto indexEvaluator1 = info[ 1 ].As< Napi::Function >();
        auto indexEvaluator  = [ indexEvaluator1 ]( int64_t index ) {
            Napi::Env         env = indexEvaluator1.Env();
            Napi::HandleScope scope( env );
            auto              arg = Napi::Number::New( env, index );
            auto              res = indexEvaluator1.Call( { arg } );
            return res.As< Napi::Number >().Int64Value();
        };

        auto indexEvaluator2 = info[ 2 ].As< Napi::Function >();
        auto indexEvaluator3 = [ indexEvaluator2 ]( int64_t index, int64_t index1 ) {
            Napi::Env         env = indexEvaluator2.Env();
            Napi::HandleScope scope( env );
            auto              arg  = Napi::Number::New( env, index );
            auto              arg1 = Napi::Number::New( env, index1 );
            auto              res  = indexEvaluator2.Call( { arg, arg1 } );
            return res.As< Napi::Number >().Int64Value();
        };

        auto external = Napi::External< DecisionBuilder >::New( info.Env(), spSolver->MakePhase( vars, indexEvaluator, indexEvaluator3 ) );
        return GDecisionBuilder::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSolver::MakePhase_06( const Napi::CallbackInfo& info )
{
    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IntVarStrategy var_str,
    //                                 IndexEvaluator2 value_evaluator,
    //                                 IndexEvaluator1 tie_breaker);
    if ( info.Length() == 4 && info[ 0 ].IsArray() && info[ 1 ].IsNumber() && info[ 2 ].IsFunction() && info[ 3 ].IsFunction() )
    {
        std::vector< IntVar* > vars;
        Napi::Array            arr = info[ 0 ].As< Napi::Array >();

        for ( int i = 0; i < arr.Length(); i++ )
        {
            if ( arr.Get( i ).As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
            {
                auto gi = GIntVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                vars.push_back( gi->spIntVar.get() );
                continue;
            }

            ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
            return info.Env().Undefined();
        }

        Solver::IntVarStrategy var_str         = static_cast< Solver::IntVarStrategy >( info[ 1 ].As< Napi::Number >().Int32Value() );
        auto                   indexEvaluator2 = info[ 2 ].As< Napi::Function >();
        auto                   indexEvaluator  = [ indexEvaluator2 ]( int64_t index, int64_t index1 ) {
            Napi::Env         env = indexEvaluator2.Env();
            Napi::HandleScope scope( env );
            auto              arg  = Napi::Number::New( env, index );
            auto              arg1 = Napi::Number::New( env, index1 );
            auto              res  = indexEvaluator2.Call( { arg, arg1 } );
            return res.As< Napi::Number >().Int64Value();
        };

        auto indexEvaluator3 = info[ 3 ].As< Napi::Function >();
        auto indexEvaluator4 = [ indexEvaluator3 ]( int64_t index ) {
            Napi::Env         env = indexEvaluator3.Env();
            Napi::HandleScope scope( env );
            auto              arg = Napi::Number::New( env, index );
            auto              res = indexEvaluator3.Call( { arg } );
            return res.As< Napi::Number >().Int64Value();
        };

        auto external = Napi::External< DecisionBuilder >::New( info.Env(), spSolver->MakePhase( vars, var_str, indexEvaluator, indexEvaluator4 ) );
        return GDecisionBuilder::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSolver::MakePhase_07( const Napi::CallbackInfo& info )
{
    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IndexEvaluator1 var_evaluator,
    //                                 IndexEvaluator2 value_evaluator,
    //                                 IndexEvaluator1 tie_breaker);
    if ( info.Length() == 4 && info[ 0 ].IsArray() && info[ 1 ].IsFunction() && info[ 2 ].IsFunction() && info[ 3 ].IsFunction() )
    {
        std::vector< IntVar* > vars;
        Napi::Array            arr = info[ 0 ].As< Napi::Array >();

        for ( int i = 0; i < arr.Length(); i++ )
        {
            if ( arr.Get( i ).As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
            {
                auto gi = GIntVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                vars.push_back( gi->spIntVar.get() );
                continue;
            }

            ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
            return info.Env().Undefined();
        }

        auto indexEvaluator1 = info[ 1 ].As< Napi::Function >();
        auto indexEvaluator  = [ indexEvaluator1 ]( int64_t index ) {
            Napi::Env         env = indexEvaluator1.Env();
            Napi::HandleScope scope( env );
            auto              arg = Napi::Number::New( env, index );
            auto              res = indexEvaluator1.Call( { arg } );
            return res.As< Napi::Number >().Int64Value();
        };

        auto indexEvaluator2 = info[ 2 ].As< Napi::Function >();
        auto indexEvaluator3 = [ indexEvaluator2 ]( int64_t index, int64_t index1 ) {
            Napi::Env         env = indexEvaluator2.Env();
            Napi::HandleScope scope( env );
            auto              arg  = Napi::Number::New( env, index );
            auto              arg1 = Napi::Number::New( env, index1 );
            auto              res  = indexEvaluator2.Call( { arg, arg1 } );
            return res.As< Napi::Number >().Int64Value();
        };

        auto indexEvaluator4 = info[ 3 ].As< Napi::Function >();
        auto indexEvaluator5 = [ indexEvaluator4 ]( int64_t index ) {
            Napi::Env         env = indexEvaluator4.Env();
            Napi::HandleScope scope( env );
            auto              arg = Napi::Number::New( env, index );
            auto              res = indexEvaluator4.Call( { arg } );
            return res.As< Napi::Number >().Int64Value();
        };

        auto external = Napi::External< DecisionBuilder >::New( info.Env(), spSolver->MakePhase( vars, indexEvaluator, indexEvaluator3, indexEvaluator5 ) );
        return GDecisionBuilder::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSolver::MakePhase_08( const Napi::CallbackInfo& info )
{
    //      DecisionBuilder* MakePhase(IntVar* const v0, IntVarStrategy var_str,
    //                                 IntValueStrategy val_str);
    if ( info.Length() == 3 && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() )
         && info[ 1 ].IsNumber() && info[ 2 ].IsNumber() )
    {

        auto                     gi      = GIntVar::Unwrap( info[ 0 ].As< Napi::Object >() );
        Solver::IntVarStrategy   var_str = static_cast< Solver::IntVarStrategy >( info[ 1 ].As< Napi::Number >().Int32Value() );
        Solver::IntValueStrategy val_str = static_cast< Solver::IntValueStrategy >( info[ 2 ].As< Napi::Number >().Int32Value() );

        auto external = Napi::External< DecisionBuilder >::New( info.Env(), spSolver->MakePhase( gi->spIntVar.get(), var_str, val_str ) );
        return GDecisionBuilder::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSolver::MakePhase_09( const Napi::CallbackInfo& info )
{
    //      DecisionBuilder* MakePhase(IntVar* const v0, IntVar* const v1,
    //                                 IntVarStrategy var_str, IntValueStrategy val_str);
    if ( info.Length() == 4 && info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() )
         && info[ 1 ].IsObject() && info[ 1 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() )
         && info[ 2 ].IsNumber() && info[ 3 ].IsNumber() )
    {

        auto                     gi0     = GIntVar::Unwrap( info[ 0 ].As< Napi::Object >() );
        auto                     gi1     = GIntVar::Unwrap( info[ 1 ].As< Napi::Object >() );
        Solver::IntVarStrategy   var_str = static_cast< Solver::IntVarStrategy >( info[ 2 ].As< Napi::Number >().Int32Value() );
        Solver::IntValueStrategy val_str = static_cast< Solver::IntValueStrategy >( info[ 3 ].As< Napi::Number >().Int32Value() );

        auto external = Napi::External< DecisionBuilder >::New( info.Env(), spSolver->MakePhase( gi0->spIntVar.get(), gi1->spIntVar.get(), var_str, val_str ) );
        return GDecisionBuilder::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSolver::MakePhase_10( const Napi::CallbackInfo& info )
{
    //      DecisionBuilder* MakePhase(IntVar* const v0, IntVar* const v1,
    //                                 IntVar* const v2, IntVarStrategy var_str,
    //                                 IntValueStrategy val_str);
    if ( info.Length() == 5 && info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() )
         && info[ 1 ].IsObject() && info[ 1 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() )
         && info[ 2 ].IsObject() && info[ 2 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() )
         && info[ 3 ].IsNumber() && info[ 4 ].IsNumber() )
    {

        auto                     gi0     = GIntVar::Unwrap( info[ 0 ].As< Napi::Object >() );
        auto                     gi1     = GIntVar::Unwrap( info[ 1 ].As< Napi::Object >() );
        auto                     gi2     = GIntVar::Unwrap( info[ 2 ].As< Napi::Object >() );
        Solver::IntVarStrategy   var_str = static_cast< Solver::IntVarStrategy >( info[ 3 ].As< Napi::Number >().Int32Value() );
        Solver::IntValueStrategy val_str = static_cast< Solver::IntValueStrategy >( info[ 4 ].As< Napi::Number >().Int32Value() );

        auto external = Napi::External< DecisionBuilder >::New( info.Env(), spSolver->MakePhase( gi0->spIntVar.get(), gi1->spIntVar.get(), gi2->spIntVar.get(), var_str, val_str ) );
        return GDecisionBuilder::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSolver::MakePhase_11( const Napi::CallbackInfo& info )
{
    //      DecisionBuilder* MakePhase(IntVar* const v0, IntVar* const v1,
    //                                 IntVar* const v2, IntVar* const v3,
    //                                 IntVarStrategy var_str, IntValueStrategy val_str);
    if ( info.Length() == 6 && info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() )
         && info[ 1 ].IsObject() && info[ 1 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() )
         && info[ 2 ].IsObject() && info[ 2 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() )
         && info[ 3 ].IsObject() && info[ 3 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() )
         && info[ 4 ].IsNumber() && info[ 5 ].IsNumber() )
    {

        auto                     gi0     = GIntVar::Unwrap( info[ 0 ].As< Napi::Object >() );
        auto                     gi1     = GIntVar::Unwrap( info[ 1 ].As< Napi::Object >() );
        auto                     gi2     = GIntVar::Unwrap( info[ 2 ].As< Napi::Object >() );
        auto                     gi3     = GIntVar::Unwrap( info[ 3 ].As< Napi::Object >() );
        Solver::IntVarStrategy   var_str = static_cast< Solver::IntVarStrategy >( info[ 4 ].As< Napi::Number >().Int32Value() );
        Solver::IntValueStrategy val_str = static_cast< Solver::IntValueStrategy >( info[ 5 ].As< Napi::Number >().Int32Value() );

        auto external = Napi::External< DecisionBuilder >::New( info.Env(), spSolver->MakePhase( gi0->spIntVar.get(), gi1->spIntVar.get(), gi2->spIntVar.get(), gi3->spIntVar.get(), var_str, val_str ) );
        return GDecisionBuilder::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSolver::MakePhase_12( const Napi::CallbackInfo& info )
{
    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IndexEvaluator2 eval, EvaluatorStrategy str);
    if ( info.Length() == 3 && info[ 0 ].IsArray() && info[ 1 ].IsFunction() && info[ 2 ].IsNumber() )
    {
        std::vector< IntVar* > vars;
        Napi::Array            arr = info[ 0 ].As< Napi::Array >();

        for ( int i = 0; i < arr.Length(); i++ )
        {
            if ( arr.Get( i ).As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
            {
                auto gi = GIntVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                vars.push_back( gi->spIntVar.get() );
                continue;
            }

            ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
            return info.Env().Undefined();
        }

        auto indexEvaluator2 = info[ 1 ].As< Napi::Function >();
        auto indexEvaluator  = [ indexEvaluator2 ]( int64_t index, int64_t index1 ) {
            Napi::Env         env = indexEvaluator2.Env();
            Napi::HandleScope scope( env );
            auto              arg  = Napi::Number::New( env, index );
            auto              arg1 = Napi::Number::New( env, index1 );
            auto              res  = indexEvaluator2.Call( { arg, arg1 } );
            return res.As< Napi::Number >().Int64Value();
        };

        Solver::EvaluatorStrategy str = static_cast< Solver::EvaluatorStrategy >( info[ 2 ].As< Napi::Number >().Int32Value() );

        auto external = Napi::External< DecisionBuilder >::New( info.Env(), spSolver->MakePhase( vars, indexEvaluator, str ) );
        return GDecisionBuilder::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSolver::MakePhase_13( const Napi::CallbackInfo& info )
{
    //      DecisionBuilder* MakePhase(const std::vector<IntVar*>& vars,
    //                                 IndexEvaluator2 eval, IndexEvaluator1 tie_breaker,
    //                                 EvaluatorStrategy str);
    if ( info.Length() == 4 && info[ 0 ].IsArray() && info[ 1 ].IsFunction() && info[ 2 ].IsFunction() && info[ 3 ].IsNumber() )
    {
        std::vector< IntVar* > vars;
        Napi::Array            arr = info[ 0 ].As< Napi::Array >();

        for ( int i = 0; i < arr.Length(); i++ )
        {
            if ( arr.Get( i ).As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
            {
                auto gi = GIntVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                vars.push_back( gi->spIntVar.get() );
                continue;
            }

            ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
            return info.Env().Undefined();
        }

        auto indexEvaluator2 = info[ 1 ].As< Napi::Function >();
        auto indexEvaluator  = [ indexEvaluator2 ]( int64_t index, int64_t index1 ) {
            Napi::Env         env = indexEvaluator2.Env();
            Napi::HandleScope scope( env );
            auto              arg  = Napi::Number::New( env, index );
            auto              arg1 = Napi::Number::New( env, index1 );
            auto              res  = indexEvaluator2.Call( { arg, arg1 } );
            return res.As< Napi::Number >().Int64Value();
        };

        auto indexEvaluator1 = info[ 2 ].As< Napi::Function >();
        auto indexEvaluator3 = [ indexEvaluator1 ]( int64_t index ) {
            Napi::Env         env = indexEvaluator1.Env();
            Napi::HandleScope scope( env );
            auto              arg = Napi::Number::New( env, index );
            auto              res = indexEvaluator1.Call( { arg } );
            return res.As< Napi::Number >().Int64Value();
        };

        Solver::EvaluatorStrategy str = static_cast< Solver::EvaluatorStrategy >( info[ 3 ].As< Napi::Number >().Int32Value() );

        auto external = Napi::External< DecisionBuilder >::New( info.Env(), spSolver->MakePhase( vars, indexEvaluator, indexEvaluator3, str ) );
        return GDecisionBuilder::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSolver::MakePhase_14( const Napi::CallbackInfo& info )
{
    //      DecisionBuilder* MakePhase(const std::vector<IntervalVar*>& intervals,
    //                                 IntervalStrategy str);
    if ( info.Length() == 2 && info[ 0 ].IsArray() && info[ 1 ].IsNumber() )
    {
        std::vector< IntervalVar* > intervals;
        Napi::Array                 arr = info[ 0 ].As< Napi::Array >();

        for ( int i = 0; i < arr.Length(); i++ )
        {
            if ( arr.Get( i ).As< Napi::Object >().InstanceOf( GIntervalVar::constructor.Value() ) )
            {
                auto giv = GIntervalVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                intervals.push_back( giv->spIntervalVar.get() );
                continue;
            }

            ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
            return info.Env().Undefined();
        }

        Solver::IntervalStrategy str = static_cast< Solver::IntervalStrategy >( info[ 1 ].As< Napi::Number >().Int32Value() );

        auto external = Napi::External< DecisionBuilder >::New( info.Env(), spSolver->MakePhase( intervals, str ) );
        return GDecisionBuilder::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSolver::MakePhase_15( const Napi::CallbackInfo& info )
{
    //      DecisionBuilder* MakePhase(const std::vector<SequenceVar*>& sequences,
    //                                 SequenceStrategy str);
    if ( info.Length() == 2 && info[ 0 ].IsArray() && info[ 1 ].IsNumber() )
    {
        std::vector< SequenceVar* > sequences;
        Napi::Array               arr = info[ 0 ].As< Napi::Array >();

        for ( int i = 0; i < arr.Length(); i++ )
        {            
            if ( arr.Get( i ).As< Napi::Object >().InstanceOf( GSequenceVar::constructor.Value() ) )
            {
                auto gsv = GSequenceVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                sequences.push_back( gsv->spSequenceVar.get() );
                continue;
            }

            ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
            return info.Env().Undefined();
        }

        Solver::SequenceStrategy str = static_cast< Solver::SequenceStrategy >( info[ 1 ].As< Napi::Number >().Int32Value() );

        auto external = Napi::External< DecisionBuilder >::New( info.Env(), spSolver->MakePhase( sequences, str ) );
        return GDecisionBuilder::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GSolver::MakePhase : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSolver::AddConstraint( const Napi::CallbackInfo& info )
{
    //      void AddConstraint(Constraint* const c);
    if ( info.Length() == 1 && info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GConstraint::constructor.Value() ) )
    {
        auto gc = GConstraint::Unwrap( info[ 0 ].As< Napi::Object >() );
        spSolver->AddConstraint( gc->spConstraint.get() );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GSolver::AddConstraint : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSolver::MakeAllDifferent( const Napi::CallbackInfo& info )
{
    //      Constraint* MakeAllDifferent(const std::vector<IntVar*>& vars);
    if ( info.Length() == 1 && info[ 0 ].IsArray() )
    {
        std::vector< IntVar* > vars;
        Napi::Array            arr = info[ 0 ].As< Napi::Array >();

        for ( int i = 0; i < arr.Length(); i++ )
        {
            if ( arr.Get( i ).As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
            {
                auto gi = GIntVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                vars.push_back( gi->spIntVar.get() );
                continue;
            }

            ThrowJsError( operations_research::GSolver::MakeAllDifferent : Invalid argument );
            return info.Env().Undefined();
        }

        auto external = Napi::External< Constraint >::New( info.Env(), spSolver->MakeAllDifferent( vars ) );
        return GConstraint::constructor.New( { external } );
    }

    //      Constraint* MakeAllDifferent(const std::vector<IntVar*>& vars,
    //                                   bool stronger_propagation);
    if ( info.Length() == 2 && info[ 0 ].IsArray() && info[ 1 ].IsBoolean() )
    {
        std::vector< IntVar* > vars;
        Napi::Array            arr = info[ 0 ].As< Napi::Array >();

        for ( int i = 0; i < arr.Length(); i++ )
        {
            if ( arr.Get( i ).As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
            {
                auto gi = GIntVar::Unwrap( arr.Get( i ).As< Napi::Object >() );
                vars.push_back( gi->spIntVar.get() );
                continue;
            }

            LOG( INFO ) << info[ i ].Type();

            ThrowJsError( operations_research::GSolver::MakeAllDifferent : Invalid argument );
            return info.Env().Undefined();
        }

        bool stronger_propagation = info[ 1 ].As< Napi::Boolean >().Value();
        auto external             = Napi::External< Constraint >::New( info.Env(), spSolver->MakeAllDifferent( vars, stronger_propagation ) );
        return GConstraint::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GSolver::MakeAllDifferent : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GSolver::MakeIntVar( const Napi::CallbackInfo& info )
{
    //      /// MakeIntVar will create the best range based int var for the bounds given.
    //      IntVar* MakeIntVar(int64_t min, int64_t max, const std::string& name);
    if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
    {
        int64_t     min      = info[ 0 ].As< Napi::Number >().Int64Value();
        int64_t     max      = info[ 1 ].As< Napi::Number >().Int64Value();
        std::string name     = info[ 2 ].As< Napi::String >().Utf8Value();
        auto        external = Napi::External< IntVar >::New( info.Env(), spSolver->MakeIntVar( min, max, name ) );
        return GIntVar::constructor.New( { external } );
    }

    //      /// MakeIntVar will create a variable with the given sparse domain.
    //      IntVar* MakeIntVar(const std::vector<int64_t>& values,
    //                         const std::string& name);
    //      /// MakeIntVar will create a variable with the given sparse domain.
    //      IntVar* MakeIntVar(const std::vector<int>& values, const std::string& name);
    if ( info.Length() == 2 && info[ 0 ].IsArray() && info[ 1 ].IsString() )
    {
        std::vector< int64_t > values;
        std::string            name = info[ 1 ].As< Napi::String >().Utf8Value();
        Napi::Array            arr  = info[ 0 ].As< Napi::Array >();

        for ( int i = 0; i < arr.Length(); i++ )
        {
            values.push_back( arr.Get( i ).As< Napi::Number >().Int64Value() );
        }

        auto external = Napi::External< IntVar >::New( info.Env(), spSolver->MakeIntVar( values, name ) );
        return GIntVar::constructor.New( { external } );
    }

    //      /// MakeIntVar will create the best range based int var for the bounds given.
    //      IntVar* MakeIntVar(int64_t min, int64_t max);
    if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() )
    {
        int64_t min      = info[ 0 ].As< Napi::Number >().Int64Value();
        int64_t max      = info[ 1 ].As< Napi::Number >().Int64Value();
        auto    external = Napi::External< IntVar >::New( info.Env(), spSolver->MakeIntVar( min, max ) );
        return GIntVar::constructor.New( { external } );
    }

    //      /// MakeIntVar will create a variable with the given sparse domain.
    //      IntVar* MakeIntVar(const std::vector<int64_t>& values);
    //      /// MakeIntVar will create a variable with the given sparse domain.
    //      IntVar* MakeIntVar(const std::vector<int>& values);
    if ( info.Length() == 1 && info[ 0 ].IsArray() )
    {
        std::vector< int64_t > values;
        Napi::Array            arr = info[ 0 ].As< Napi::Array >();

        for ( int i = 0; i < arr.Length(); i++ )
        {
            values.push_back( arr.Get( i ).As< Napi::Number >().Int64Value() );
        }

        auto external = Napi::External< IntVar >::New( info.Env(), spSolver->MakeIntVar( values ) );
        return GIntVar::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GSolver::MakeIntVar : Invalid argument );
    return info.Env().Undefined();
}