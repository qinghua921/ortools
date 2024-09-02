#pragma once

#include "napi.h"
#include "../commonheader.hpp"
#include "ortools/linear_solver/linear_solver.h"
#include "GMPVariable.hpp"
#include "GMPConstraint.hpp"
#include "GLinearRange.hpp"
#include "GMPObjective.hpp"
#include "GMPSolverParameters.hpp"
#include "GMPModelProto.hpp"
#include "GMPSolutionResponse.hpp"
#include "GMPModelRequest.hpp"
#include "../absl/GStatus.hpp"

namespace operations_research
{
class GMPSolver : public Napi::ObjectWrap< GMPSolver >
{
public:
    static Napi::FunctionReference constructor;
    MPSolver*                      pMPSolver = nullptr;
    GMPSolver( const Napi::CallbackInfo& info );
    ~GMPSolver();
    static Napi::Object Init( Napi::Env env, Napi::Object exports );

    static Napi::Value CreateSolver( const Napi::CallbackInfo& info );
    static Napi::Value SupportsProblemType( const Napi::CallbackInfo& info );
    static Napi::Value ParseSolverType( const Napi::CallbackInfo& info );
    static Napi::Value ParseSolverTypeOrDie( const Napi::CallbackInfo& info );
    Napi::Value        IsMIP( const Napi::CallbackInfo& info );
    Napi::Value        Name( const Napi::CallbackInfo& info );
    Napi::Value        ProblemType( const Napi::CallbackInfo& info );
    Napi::Value        Clear( const Napi::CallbackInfo& info );
    Napi::Value        NumVariables( const Napi::CallbackInfo& info );
    Napi::Value        variables( const Napi::CallbackInfo& info );
    Napi::Value        variable( const Napi::CallbackInfo& info );
    Napi::Value        LookupVariableOrNull( const Napi::CallbackInfo& info );
    Napi::Value        MakeVar( const Napi::CallbackInfo& info );
    Napi::Value        MakeNumVar( const Napi::CallbackInfo& info );
    Napi::Value        MakeIntVar( const Napi::CallbackInfo& info );
    Napi::Value        MakeBoolVar( const Napi::CallbackInfo& info );
    Napi::Value        MakeVarArray( const Napi::CallbackInfo& info );
    Napi::Value        MakeNumVarArray( const Napi::CallbackInfo& info );
    Napi::Value        MakeIntVarArray( const Napi::CallbackInfo& info );
    Napi::Value        MakeBoolVarArray( const Napi::CallbackInfo& info );
    Napi::Value        NumConstraints( const Napi::CallbackInfo& info );
    Napi::Value        constraints( const Napi::CallbackInfo& info );
    Napi::Value        constraint( const Napi::CallbackInfo& info );
    Napi::Value        LookupConstraintOrNull( const Napi::CallbackInfo& info );
    Napi::Value        MakeRowConstraint( const Napi::CallbackInfo& info );
    Napi::Value        Objective( const Napi::CallbackInfo& info );
    Napi::Value        MutableObjective( const Napi::CallbackInfo& info );
    Napi::Value        Solve( const Napi::CallbackInfo& info );
    Napi::Value        Write( const Napi::CallbackInfo& info );
    Napi::Value        ComputeConstraintActivities( const Napi::CallbackInfo& info );
    Napi::Value        VerifySolution( const Napi::CallbackInfo& info );
    Napi::Value        Reset( const Napi::CallbackInfo& info );
    Napi::Value        InterruptSolve( const Napi::CallbackInfo& info );
    Napi::Value        LoadModelFromProto( const Napi::CallbackInfo& info );
    Napi::Value        LoadModelFromProtoWithUniqueNamesOrDie( const Napi::CallbackInfo& info );
    Napi::Value        FillSolutionResponseProto( const Napi::CallbackInfo& info );
    static Napi::Value SolveWithProto( const Napi::CallbackInfo& info );
    static Napi::Value SolverTypeSupportsInterruption( const Napi::CallbackInfo& info );
    Napi::Value        ExportModelToProto( const Napi::CallbackInfo& info );
    Napi::Value        LoadSolutionFromProto( const Napi::CallbackInfo& info );
    Napi::Value        ClampSolutionWithinBounds( const Napi::CallbackInfo& info );
    Napi::Value        ExportModelAsLpFormat( const Napi::CallbackInfo& info );
    Napi::Value        ExportModelAsMpsFormat( const Napi::CallbackInfo& info );
    Napi::Value        SetNumThreads( const Napi::CallbackInfo& info );
    Napi::Value        GetNumThreads( const Napi::CallbackInfo& info );
    Napi::Value        SetSolverSpecificParametersAsString( const Napi::CallbackInfo& info );
    Napi::Value        GetSolverSpecificParametersAsString( const Napi::CallbackInfo& info );
    Napi::Value        SetHint( const Napi::CallbackInfo& info );
    Napi::Value        SetStartingLpBasis( const Napi::CallbackInfo& info );
    static Napi::Value infinity( const Napi::CallbackInfo& info );
    Napi::Value        OutputIsEnabled( const Napi::CallbackInfo& info );
    Napi::Value        EnableOutput( const Napi::CallbackInfo& info );
    Napi::Value        SuppressOutput( const Napi::CallbackInfo& info );
    Napi::Value        TimeLimit( const Napi::CallbackInfo& info );
    Napi::Value        SetTimeLimit( const Napi::CallbackInfo& info );
    Napi::Value        DurationSinceConstruction( const Napi::CallbackInfo& info );
    Napi::Value        iterations( const Napi::CallbackInfo& info );
    Napi::Value        nodes( const Napi::CallbackInfo& info );
    Napi::Value        SolverVersion( const Napi::CallbackInfo& info );
    Napi::Value        underlying_solver( const Napi::CallbackInfo& info );
    Napi::Value        ComputeExactConditionNumber( const Napi::CallbackInfo& info );
    Napi::Value        NextSolution( const Napi::CallbackInfo& info );
    Napi::Value        SetCallback( const Napi::CallbackInfo& info );
    Napi::Value        SupportsCallbacks( const Napi::CallbackInfo& info );
    static Napi::Value global_num_variables( const Napi::CallbackInfo& info );
    static Napi::Value global_num_constraints( const Napi::CallbackInfo& info );
    Napi::Value        time_limit( const Napi::CallbackInfo& info );
    Napi::Value        set_time_limit( const Napi::CallbackInfo& info );
    Napi::Value        time_limit_in_secs( const Napi::CallbackInfo& info );
    Napi::Value        wall_time( const Napi::CallbackInfo& info );
    Napi::Value        OwnsVariable( const Napi::CallbackInfo& info );
};
};  // namespace operations_research

Napi::FunctionReference operations_research::GMPSolver::constructor;

inline operations_research::GMPSolver::GMPSolver( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPSolver >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< MPSolver > >();
        pMPSolver     = dynamic_cast< MPSolver* >( external.Data() );
        if ( pMPSolver != nullptr ) return;
    }

    // MPSolver( const std::string& name, OptimizationProblemType problem_type );
    if ( info.Length() == 2 && info[ 0 ].IsString() && info[ 1 ].IsNumber() )
    {
        std::string name              = info[ 0 ].As< Napi::String >().Utf8Value();
        using OptimizationProblemType = MPSolver::OptimizationProblemType;
        OptimizationProblemType type  = static_cast< OptimizationProblemType >( info[ 1 ].As< Napi::Number >().Int32Value() );
        pMPSolver                     = new MPSolver( name, type );
        return;
    }

    ThrowJsError( operations_research::GMPSolver::GMPSolver : Invalid argument );
}

inline operations_research::GMPSolver::~GMPSolver()
{
    delete pMPSolver;
}

inline Napi::Object operations_research::GMPSolver::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "MPSolver",
        {

        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "MPSolver" ), func );
    return exports;
}

//     static MPSolver*                    CreateSolver( const std::string& solver_id );
inline Napi::Value operations_research::GMPSolver::CreateSolver( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string solver_id = info[ 0 ].As< Napi::String >().Utf8Value();
        MPSolver*   solver    = MPSolver::CreateSolver( solver_id );
        auto        external  = Napi::External< MPSolver >::New( info.Env(), solver );
        return GMPSolver::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GMPSolver::CreateSolver : Invalid argument );
    return info.Env().Undefined();
}

//     static bool                         SupportsProblemType( OptimizationProblemType problem_type );
inline Napi::Value operations_research::GMPSolver::SupportsProblemType( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        using OptimizationProblemType = MPSolver::OptimizationProblemType;
        OptimizationProblemType type  = static_cast< OptimizationProblemType >( info[ 0 ].As< Napi::Number >().Int32Value() );
        return Napi::Boolean::New( info.Env(), MPSolver::SupportsProblemType( type ) );
    }

    ThrowJsError( operations_research::GMPSolver::SupportsProblemType : Invalid argument );
    return info.Env().Undefined();
}

//     static bool                         ParseSolverType( absl::string_view solver_id, OptimizationProblemType* type );
inline Napi::Value operations_research::GMPSolver::ParseSolverType( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 2 && info[ 0 ].IsString() && info[ 1 ].IsNumber() )
    {
        std::string solver_id         = info[ 0 ].As< Napi::String >().Utf8Value();
        using OptimizationProblemType = MPSolver::OptimizationProblemType;
        OptimizationProblemType type  = static_cast< OptimizationProblemType >( info[ 1 ].As< Napi::Number >().Int32Value() );
        return Napi::Boolean::New( info.Env(), MPSolver::ParseSolverType( solver_id, &type ) );
    }

    ThrowJsError( operations_research::GMPSolver::ParseSolverType : Invalid argument );
    return info.Env().Undefined();
}

//     static OptimizationProblemType      ParseSolverTypeOrDie( const std::string& solver_id );
inline Napi::Value operations_research::GMPSolver::ParseSolverTypeOrDie( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string solver_id         = info[ 0 ].As< Napi::String >().Utf8Value();
        using OptimizationProblemType = MPSolver::OptimizationProblemType;
        OptimizationProblemType type  = MPSolver::ParseSolverTypeOrDie( solver_id );
        return Napi::Number::New( info.Env(), static_cast< int32_t >( type ) );
    }

    ThrowJsError( operations_research::GMPSolver::ParseSolverTypeOrDie : Invalid argument );
    return info.Env().Undefined();
}

//     bool                                IsMIP() const;
inline Napi::Value operations_research::GMPSolver::IsMIP( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 0 )
    {
        return Napi::Boolean::New( info.Env(), pMPSolver->IsMIP() );
    }

    ThrowJsError( operations_research::GMPSolver::IsMIP : Invalid argument );
    return info.Env().Undefined();
}

//     const std::string&                  Name() const;
inline Napi::Value operations_research::GMPSolver::Name( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 0 )
    {
        return Napi::String::New( info.Env(), pMPSolver->Name() );
    }

    ThrowJsError( operations_research::GMPSolver::Name : Invalid argument );
    return info.Env().Undefined();
}

//     virtual OptimizationProblemType     ProblemType() const;
inline Napi::Value operations_research::GMPSolver::ProblemType( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 0 )
    {
        using OptimizationProblemType = MPSolver::OptimizationProblemType;
        OptimizationProblemType type  = pMPSolver->ProblemType();
        return Napi::Number::New( info.Env(), static_cast< int32_t >( type ) );
    }

    ThrowJsError( operations_research::GMPSolver::ProblemType : Invalid argument );
    return info.Env().Undefined();
}

//     void                                Clear();
inline Napi::Value operations_research::GMPSolver::Clear( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 0 )
    {
        pMPSolver->Clear();
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPSolver::Clear : Invalid argument );
    return info.Env().Undefined();
}

//     int                                 NumVariables() const;
inline Napi::Value operations_research::GMPSolver::NumVariables( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), pMPSolver->NumVariables() );
    }

    ThrowJsError( operations_research::GMPSolver::NumVariables : Invalid argument );
    return info.Env().Undefined();
}

//     const std::vector< MPVariable* >&   variables() const;
inline Napi::Value operations_research::GMPSolver::variables( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 0 )
    {
        auto        variables = pMPSolver->variables();
        Napi::Array array     = Napi::Array::New( info.Env(), variables.size() );
        for ( int i = 0; i < variables.size(); i++ )
        {
            auto external = Napi::External< MPVariable >::New( info.Env(), variables[ i ] );
            array.Set( i, GMPVariable::constructor.New( { external } ) );
        }
        return array;
    }

    ThrowJsError( operations_research::GMPSolver::variables : Invalid argument );
    return info.Env().Undefined();
}

//     MPVariable*                         variable( int index ) const;
inline Napi::Value operations_research::GMPSolver::variable( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        int  index    = info[ 0 ].As< Napi::Number >().Int32Value();
        auto variable = pMPSolver->variable( index );
        if ( variable == nullptr ) return info.Env().Undefined();
        auto external = Napi::External< MPVariable >::New( info.Env(), variable );
        return GMPVariable::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GMPSolver::variable : Invalid argument );
    return info.Env().Undefined();
}

//     MPVariable*                         LookupVariableOrNull( const std::string& var_name ) const;
inline Napi::Value operations_research::GMPSolver::LookupVariableOrNull( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string var_name = info[ 0 ].As< Napi::String >().Utf8Value();
        auto        variable = pMPSolver->LookupVariableOrNull( var_name );
        if ( variable == nullptr ) return info.Env().Undefined();
        auto external = Napi::External< MPVariable >::New( info.Env(), variable );
        return GMPVariable::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GMPSolver::LookupVariableOrNull : Invalid argument );
    return info.Env().Undefined();
}

//     MPVariable*                         MakeVar( double lb, double ub, bool integer, const std::string& name );
inline Napi::Value operations_research::GMPSolver::MakeVar( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 4 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsBoolean() && info[ 3 ].IsString() )
    {
        double      lb       = info[ 0 ].As< Napi::Number >().DoubleValue();
        double      ub       = info[ 1 ].As< Napi::Number >().DoubleValue();
        bool        integer  = info[ 2 ].As< Napi::Boolean >().Value();
        std::string name     = info[ 3 ].As< Napi::String >().Utf8Value();
        auto        variable = pMPSolver->MakeVar( lb, ub, integer, name );
        auto        external = Napi::External< MPVariable >::New( info.Env(), variable );
        return GMPVariable::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GMPSolver::MakeVar : Invalid argument );
    return info.Env().Undefined();
}

//     MPVariable*                         MakeNumVar( double lb, double ub, const std::string& name );
inline Napi::Value operations_research::GMPSolver::MakeNumVar( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
    {
        double      lb       = info[ 0 ].As< Napi::Number >().DoubleValue();
        double      ub       = info[ 1 ].As< Napi::Number >().DoubleValue();
        std::string name     = info[ 2 ].As< Napi::String >().Utf8Value();
        auto        variable = pMPSolver->MakeNumVar( lb, ub, name );
        auto        external = Napi::External< MPVariable >::New( info.Env(), variable );
        return GMPVariable::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GMPSolver::MakeNumVar : Invalid argument );
    return info.Env().Undefined();
}

//     MPVariable*                         MakeIntVar( double lb, double ub, const std::string& name );
inline Napi::Value operations_research::GMPSolver::MakeIntVar( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
    {
        double      lb       = info[ 0 ].As< Napi::Number >().DoubleValue();
        double      ub       = info[ 1 ].As< Napi::Number >().DoubleValue();
        std::string name     = info[ 2 ].As< Napi::String >().Utf8Value();
        auto        variable = pMPSolver->MakeIntVar( lb, ub, name );
        auto        external = Napi::External< MPVariable >::New( info.Env(), variable );
        return GMPVariable::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GMPSolver::MakeIntVar : Invalid argument );
    return info.Env().Undefined();
}

//     MPVariable*                         MakeBoolVar( const std::string& name );
inline Napi::Value operations_research::GMPSolver::MakeBoolVar( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string name     = info[ 0 ].As< Napi::String >().Utf8Value();
        auto        variable = pMPSolver->MakeBoolVar( name );
        auto        external = Napi::External< MPVariable >::New( info.Env(), variable );
        return GMPVariable::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GMPSolver::MakeBoolVar : Invalid argument );
    return info.Env().Undefined();
}

// void MakeVarArray( int nb, double lb, double ub, bool integer, const std::string& name_prefix, std::vector< MPVariable* >* vars );
inline Napi::Value operations_research::GMPSolver::MakeVarArray( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 5 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsNumber() && info[ 3 ].IsBoolean() && info[ 4 ].IsString() )
    {
        int                         nb          = info[ 0 ].As< Napi::Number >().Int32Value();
        double                      lb          = info[ 1 ].As< Napi::Number >().DoubleValue();
        double                      ub          = info[ 2 ].As< Napi::Number >().DoubleValue();
        bool                        integer     = info[ 3 ].As< Napi::Boolean >().Value();
        std::string                 name_prefix = info[ 4 ].As< Napi::String >().Utf8Value();
        std::vector< MPVariable* >* vars        = new std::vector< MPVariable* >();
        pMPSolver->MakeVarArray( nb, lb, ub, integer, name_prefix, vars );
        Napi::Array array = Napi::Array::New( info.Env(), vars->size() );
        for ( int i = 0; i < vars->size(); i++ )
        {
            auto external = Napi::External< MPVariable >::New( info.Env(), vars->at( i ) );
            array.Set( i, GMPVariable::constructor.New( { external } ) );
        }
        delete vars;
        return array;
    }

    ThrowJsError( operations_research::GMPSolver::MakeVarArray : Invalid argument );
    return info.Env().Undefined();
}

// void MakeNumVarArray( int nb, double lb, double ub, const std::string& name, std::vector< MPVariable* >* vars );
inline Napi::Value operations_research::GMPSolver::MakeNumVarArray( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 4 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsNumber() && info[ 3 ].IsString() )
    {
        int                         nb   = info[ 0 ].As< Napi::Number >().Int32Value();
        double                      lb   = info[ 1 ].As< Napi::Number >().DoubleValue();
        double                      ub   = info[ 2 ].As< Napi::Number >().DoubleValue();
        std::string                 name = info[ 3 ].As< Napi::String >().Utf8Value();
        std::vector< MPVariable* >* vars = new std::vector< MPVariable* >();
        pMPSolver->MakeNumVarArray( nb, lb, ub, name, vars );
        Napi::Array array = Napi::Array::New( info.Env(), vars->size() );
        for ( int i = 0; i < vars->size(); i++ )
        {
            auto external = Napi::External< MPVariable >::New( info.Env(), vars->at( i ) );
            array.Set( i, GMPVariable::constructor.New( { external } ) );
        }
        delete vars;
        return array;
    }

    ThrowJsError( operations_research::GMPSolver::MakeNumVarArray : Invalid argument );
    return info.Env().Undefined();
}

// void MakeIntVarArray( int nb, double lb, double ub, const std::string& name, std::vector< MPVariable* >* vars );
inline Napi::Value operations_research::GMPSolver::MakeIntVarArray( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 4 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsNumber() && info[ 3 ].IsString() )
    {
        int                         nb   = info[ 0 ].As< Napi::Number >().Int32Value();
        double                      lb   = info[ 1 ].As< Napi::Number >().DoubleValue();
        double                      ub   = info[ 2 ].As< Napi::Number >().DoubleValue();
        std::string                 name = info[ 3 ].As< Napi::String >().Utf8Value();
        std::vector< MPVariable* >* vars = new std::vector< MPVariable* >();
        pMPSolver->MakeIntVarArray( nb, lb, ub, name, vars );
        Napi::Array array = Napi::Array::New( info.Env(), vars->size() );
        for ( int i = 0; i < vars->size(); i++ )
        {
            auto external = Napi::External< MPVariable >::New( info.Env(), vars->at( i ) );
            array.Set( i, GMPVariable::constructor.New( { external } ) );
        }
        delete vars;
        return array;
    }

    ThrowJsError( operations_research::GMPSolver::MakeIntVarArray : Invalid argument );
    return info.Env().Undefined();
}

// void MakeBoolVarArray( int nb, const std::string& name, std::vector< MPVariable* >* vars );
inline Napi::Value operations_research::GMPSolver::MakeBoolVarArray( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsString() )
    {
        int                         nb   = info[ 0 ].As< Napi::Number >().Int32Value();
        std::string                 name = info[ 1 ].As< Napi::String >().Utf8Value();
        std::vector< MPVariable* >* vars = new std::vector< MPVariable* >();
        pMPSolver->MakeBoolVarArray( nb, name, vars );
        Napi::Array array = Napi::Array::New( info.Env(), vars->size() );
        for ( int i = 0; i < vars->size(); i++ )
        {
            auto external = Napi::External< MPVariable >::New( info.Env(), vars->at( i ) );
            array.Set( i, GMPVariable::constructor.New( { external } ) );
        }
        delete vars;
        return array;
    }

    ThrowJsError( operations_research::GMPSolver::MakeBoolVarArray : Invalid argument );
    return info.Env().Undefined();
}

//     int                                 NumConstraints() const;
inline Napi::Value operations_research::GMPSolver::NumConstraints( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), pMPSolver->NumConstraints() );
    }

    ThrowJsError( operations_research::GMPSolver::NumConstraints : Invalid argument );
    return info.Env().Undefined();
}

//     const std::vector< MPConstraint* >& constraints() const;
inline Napi::Value operations_research::GMPSolver::constraints( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 0 )
    {
        auto        constraints = pMPSolver->constraints();
        Napi::Array array       = Napi::Array::New( info.Env(), constraints.size() );
        for ( int i = 0; i < constraints.size(); i++ )
        {
            auto external = Napi::External< MPConstraint >::New( info.Env(), constraints[ i ] );
            array.Set( i, GMPConstraint::constructor.New( { external } ) );
        }
        return array;
    }

    ThrowJsError( operations_research::GMPSolver::constraints : Invalid argument );
    return info.Env().Undefined();
}

//     MPConstraint*                       constraint( int index ) const;
inline Napi::Value operations_research::GMPSolver::constraint( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        int  index      = info[ 0 ].As< Napi::Number >().Int32Value();
        auto constraint = pMPSolver->constraint( index );
        if ( constraint == nullptr ) return info.Env().Undefined();
        auto external = Napi::External< MPConstraint >::New( info.Env(), constraint );
        return GMPConstraint::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GMPSolver::constraint : Invalid argument );
    return info.Env().Undefined();
}

//     MPConstraint*                       LookupConstraintOrNull( const std::string& constraint_name ) const;
inline Napi::Value operations_research::GMPSolver::LookupConstraintOrNull( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string constraint_name = info[ 0 ].As< Napi::String >().Utf8Value();
        auto        constraint      = pMPSolver->LookupConstraintOrNull( constraint_name );
        if ( constraint == nullptr ) return info.Env().Undefined();
        auto external = Napi::External< MPConstraint >::New( info.Env(), constraint );
        return GMPConstraint::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GMPSolver::LookupConstraintOrNull : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GMPSolver::MakeRowConstraint( const Napi::CallbackInfo& info )
{
    //     MPConstraint*                       MakeRowConstraint( double lb, double ub );
    if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() )
    {
        double lb         = info[ 0 ].As< Napi::Number >().DoubleValue();
        double ub         = info[ 1 ].As< Napi::Number >().DoubleValue();
        auto   constraint = pMPSolver->MakeRowConstraint( lb, ub );
        auto   external   = Napi::External< MPConstraint >::New( info.Env(), constraint );
        return GMPConstraint::constructor.New( { external } );
    }

    //     MPConstraint*                       MakeRowConstraint();
    if ( info.Length() == 0 )
    {
        auto constraint = pMPSolver->MakeRowConstraint();
        auto external   = Napi::External< MPConstraint >::New( info.Env(), constraint );
        return GMPConstraint::constructor.New( { external } );
    }

    //     MPConstraint*                       MakeRowConstraint( double lb, double ub, const std::string& name );
    if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
    {
        double      lb         = info[ 0 ].As< Napi::Number >().DoubleValue();
        double      ub         = info[ 1 ].As< Napi::Number >().DoubleValue();
        std::string name       = info[ 2 ].As< Napi::String >().Utf8Value();
        auto        constraint = pMPSolver->MakeRowConstraint( lb, ub, name );
        auto        external   = Napi::External< MPConstraint >::New( info.Env(), constraint );
        return GMPConstraint::constructor.New( { external } );
    }

    //     MPConstraint*                       MakeRowConstraint( const std::string& name );
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string name       = info[ 0 ].As< Napi::String >().Utf8Value();
        auto        constraint = pMPSolver->MakeRowConstraint( name );
        auto        external   = Napi::External< MPConstraint >::New( info.Env(), constraint );
        return GMPConstraint::constructor.New( { external } );
    }

    //     MPConstraint*                       MakeRowConstraint( const LinearRange& range );
    if ( info.Length() == 1 && info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearRange::constructor.Value() ) )
    {
        auto range      = GLinearRange::Unwrap( info[ 0 ].As< Napi::Object >() );
        auto constraint = pMPSolver->MakeRowConstraint( *range->pLinearRange );
        auto external   = Napi::External< MPConstraint >::New( info.Env(), constraint );
        return GMPConstraint::constructor.New( { external } );
    }

    //     MPConstraint*                       MakeRowConstraint( const LinearRange& range, const std::string& name );
    if ( info.Length() == 2 && info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearRange::constructor.Value() ) && info[ 1 ].IsString() )
    {
        auto        range      = GLinearRange::Unwrap( info[ 0 ].As< Napi::Object >() );
        std::string name       = info[ 1 ].As< Napi::String >().Utf8Value();
        auto        constraint = pMPSolver->MakeRowConstraint( *range->pLinearRange, name );
        auto        external   = Napi::External< MPConstraint >::New( info.Env(), constraint );
        return GMPConstraint::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GMPSolver::MakeRowConstraint : Invalid argument );
    return info.Env().Undefined();
}

//     const MPObjective&                  Objective() const;
inline Napi::Value operations_research::GMPSolver::Objective( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 0 )
    {
        auto external = Napi::External< MPObjective >::New( info.Env(), ( MPObjective* )&pMPSolver->Objective() );
        return GMPObjective::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GMPSolver::Objective : Invalid argument );
    return info.Env().Undefined();
}

//     MPObjective*                        MutableObjective();
inline Napi::Value operations_research::GMPSolver::MutableObjective( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 0 )
    {
        auto external = Napi::External< MPObjective >::New( info.Env(), pMPSolver->MutableObjective() );
        return GMPObjective::constructor.New( { external } );
    }

    ThrowJsError( operations_research::GMPSolver::MutableObjective : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::GMPSolver::Solve( const Napi::CallbackInfo& info )
{
    //     ResultStatus                        Solve();
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), pMPSolver->Solve() );
    }

    //     ResultStatus                        Solve( const MPSolverParameters& param );
    if ( info.Length() == 1 && info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GMPSolverParameters::constructor.Value() ) )
    {
        auto param = GMPSolverParameters::Unwrap( info[ 0 ].As< Napi::Object >() );
        return Napi::Number::New( info.Env(), pMPSolver->Solve( *param->pMPSolverParameters ) );
    }

    ThrowJsError( operations_research::GMPSolver::Solve : Invalid argument );
    return info.Env().Undefined();
}

//     void                                Write( const std::string& file_name );
inline Napi::Value operations_research::GMPSolver::Write( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string file_name = info[ 0 ].As< Napi::String >().Utf8Value();
        pMPSolver->Write( file_name );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPSolver::Write : Invalid argument );
    return info.Env().Undefined();
}

//     std::vector< double >               ComputeConstraintActivities() const;
inline Napi::Value operations_research::GMPSolver::ComputeConstraintActivities( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 0 )
    {
        auto        activities = pMPSolver->ComputeConstraintActivities();
        Napi::Array array      = Napi::Array::New( info.Env(), activities.size() );
        for ( int i = 0; i < activities.size(); i++ )
        {
            array.Set( i, Napi::Number::New( info.Env(), activities[ i ] ) );
        }
        return array;
    }

    ThrowJsError( operations_research::GMPSolver::ComputeConstraintActivities : Invalid argument );
    return info.Env().Undefined();
}

//     bool                                VerifySolution( double tolerance, bool log_errors ) const;
inline Napi::Value operations_research::GMPSolver::VerifySolution( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsBoolean() )
    {
        double tolerance  = info[ 0 ].As< Napi::Number >().DoubleValue();
        bool   log_errors = info[ 1 ].As< Napi::Boolean >().Value();
        bool   result     = pMPSolver->VerifySolution( tolerance, log_errors );
        return Napi::Boolean::New( info.Env(), result );
    }

    ThrowJsError( operations_research::GMPSolver::VerifySolution : Invalid argument );
    return info.Env().Undefined();
}

//     void                                Reset();
inline Napi::Value operations_research::GMPSolver::Reset( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 0 )
    {
        pMPSolver->Reset();
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPSolver::Reset : Invalid argument );
    return info.Env().Undefined();
}

//     bool                                InterruptSolve();
inline Napi::Value operations_research::GMPSolver::InterruptSolve( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 0 )
    {
        return Napi::Boolean::New( info.Env(), pMPSolver->InterruptSolve() );
    }

    ThrowJsError( operations_research::GMPSolver::InterruptSolve : Invalid argument );
    return info.Env().Undefined();
}

//     MPSolverResponseStatus              LoadModelFromProto( const MPModelProto& input_model, std::string* error_message );
inline Napi::Value operations_research::GMPSolver::LoadModelFromProto( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 1 && info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GMPModelProto::constructor.Value() ) )
    {
        auto        input_model = GMPModelProto::Unwrap( info[ 0 ].As< Napi::Object >() );
        std::string error_message;
        auto        status = pMPSolver->LoadModelFromProto( *input_model->pMPModelProto, &error_message );
        auto        ret    = Napi::Object::New( info.Env() );
        ret.Set( "status", Napi::Number::New( info.Env(), status ) );
        ret.Set( "errorMessage", Napi::String::New( info.Env(), error_message ) );
        return ret;
    }

    ThrowJsError( operations_research::GMPSolver::LoadModelFromProto : Invalid argument );
    return info.Env().Undefined();
}

//     MPSolverResponseStatus              LoadModelFromProtoWithUniqueNamesOrDie( const MPModelProto& input_model, std::string* error_message );
inline Napi::Value operations_research::GMPSolver::LoadModelFromProtoWithUniqueNamesOrDie( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 1 && info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GMPModelProto::constructor.Value() ) )
    {
        auto        input_model = GMPModelProto::Unwrap( info[ 0 ].As< Napi::Object >() );
        std::string error_message;
        auto        status = pMPSolver->LoadModelFromProtoWithUniqueNamesOrDie( *input_model->pMPModelProto, &error_message );
        auto        ret    = Napi::Object::New( info.Env() );
        ret.Set( "status", Napi::Number::New( info.Env(), status ) );
        ret.Set( "errorMessage", Napi::String::New( info.Env(), error_message ) );
        return ret;
    }

    ThrowJsError( operations_research::GMPSolver::LoadModelFromProtoWithUniqueNamesOrDie : Invalid argument );
    return info.Env().Undefined();
}

//     void                                FillSolutionResponseProto( MPSolutionResponse* response ) const;
inline Napi::Value operations_research::GMPSolver::FillSolutionResponseProto( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 1 && info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GMPSolutionResponse::constructor.Value() ) )
    {
        auto response = GMPSolutionResponse::Unwrap( info[ 0 ].As< Napi::Object >() );
        pMPSolver->FillSolutionResponseProto( response->pMPSolutionResponse );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPSolver::FillSolutionResponseProto : Invalid argument );
    return info.Env().Undefined();
}

// static void SolveWithProto( const MPModelRequest& model_request, MPSolutionResponse* response, std::atomic< bool >* interrupt = nullptr );
inline Napi::Value operations_research::GMPSolver::SolveWithProto( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GMPModelRequest::constructor.Value() ) )
    {
        auto model_request = GMPModelRequest::Unwrap( info[ 0 ].As< Napi::Object >() );
        auto response      = new MPSolutionResponse();
        MPSolver::SolveWithProto( *model_request->pMPModelRequest, response, nullptr );
        return GMPSolutionResponse::constructor.New( { Napi::External< MPSolutionResponse >::New( info.Env(), response ) } );
    }

    ThrowJsError( operations_research::GMPSolver::SolveWithProto : Invalid argument );
    return info.Env().Undefined();
}

//     static bool                         SolverTypeSupportsInterruption( const MPModelRequest::SolverType solver );
inline Napi::Value operations_research::GMPSolver::SolverTypeSupportsInterruption( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        auto solver = static_cast< MPModelRequest::SolverType >( info[ 0 ].As< Napi::Number >().Int32Value() );
        return Napi::Boolean::New( info.Env(), MPSolver::SolverTypeSupportsInterruption( solver ) );
    }

    ThrowJsError( operations_research::GMPSolver::SolverTypeSupportsInterruption : Invalid argument );
    return info.Env().Undefined();
}

//     void                                ExportModelToProto( MPModelProto* output_model ) const;
inline Napi::Value operations_research::GMPSolver::ExportModelToProto( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 0 )
    {
        auto output_model = new MPModelProto();
        pMPSolver->ExportModelToProto( output_model );
        return GMPModelProto::constructor.New( { Napi::External< MPModelProto >::New( info.Env(), output_model ) } );
    }

    ThrowJsError( operations_research::GMPSolver::ExportModelToProto : Invalid argument );
    return info.Env().Undefined();
}

// absl::Status LoadSolutionFromProto( const MPSolutionResponse& response, double tolerance = std::numeric_limits< double >::infinity() );
inline Napi::Value operations_research::GMPSolver::LoadSolutionFromProto( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        double tolerance = info[ 0 ].As< Napi::Number >().DoubleValue();
        auto   ret       = Napi::Object::New( info.Env() );
        auto   response  = new MPSolutionResponse();
        auto   status    = pMPSolver->LoadSolutionFromProto( *response, tolerance );
        ret.Set( "status", absl::GStatus::constructor.New( { Napi::External< absl::Status >::New( info.Env(), new absl::Status( status ) ) } ) );
        ret.Set( "response", GMPSolutionResponse::constructor.New( { Napi::External< MPSolutionResponse >::New( info.Env(), response ) } ) );
        return ret;
    }

    ThrowJsError( operations_research::GMPSolver::LoadSolutionFromProto : Invalid argument );
    return info.Env().Undefined();
}

//     absl::Status                        ClampSolutionWithinBounds();
inline Napi::Value operations_research::GMPSolver::ClampSolutionWithinBounds( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 0 )
    {
        auto status = pMPSolver->ClampSolutionWithinBounds();
        return absl::GStatus::constructor.New( { Napi::External< absl::Status >::New( info.Env(), new absl::Status( status ) ) } );
    }

    ThrowJsError( operations_research::GMPSolver::ClampSolutionWithinBounds : Invalid argument );
    return info.Env().Undefined();
}

//     bool                                ExportModelAsLpFormat( bool obfuscate, std::string* model_str ) const;

//     bool                                ExportModelAsMpsFormat( bool fixed_format, bool obfuscate, std::string* model_str ) const;

//     absl::Status                        SetNumThreads( int num_threads );

//     int                                 GetNumThreads() const;

//     bool                                SetSolverSpecificParametersAsString( const std::string& parameters );

//     std::string                         GetSolverSpecificParametersAsString() const;

//     void                                SetHint( std::vector< std::pair< const MPVariable*, double > > hint );

//     void                                SetStartingLpBasis( const std::vector< MPSolver::BasisStatus >& variable_statuses, const std::vector< MPSolver::BasisStatus >& constraint_statuses );

//     static double                       infinity();

//     bool                                OutputIsEnabled() const;

//     void                                EnableOutput();

//     void                                SuppressOutput();

//     absl::Duration                      TimeLimit() const;

//     void                                SetTimeLimit( absl::Duration time_limit );

//     absl::Duration                      DurationSinceConstruction() const;

//     int64_t                             iterations() const;

//     int64_t                             nodes() const;

//     std::string                         SolverVersion() const;

//     void*                               underlying_solver();

//     double                              ComputeExactConditionNumber() const;

//     ABSL_MUST_USE_RESULT bool           NextSolution();

//     void                                SetCallback( MPCallback* mp_callback );

//     bool                                SupportsCallbacks() const;
inline Napi::Value operations_research::GMPSolver::SupportsCallbacks( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 0 )
    {
        return Napi::Boolean::New( info.Env(), pMPSolver->SupportsCallbacks() );
    }

    ThrowJsError( operations_research::GMPSolver::SupportsCallbacks : Invalid argument );
    return info.Env().Undefined();
}

//     static int64_t                      global_num_variables();
inline Napi::Value operations_research::GMPSolver::global_num_constraints( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), MPSolver::global_num_constraints() );
    }

    ThrowJsError( operations_research::GMPSolver::global_num_constraints : Invalid argument );
    return info.Env().Undefined();
}

//     static int64_t                      global_num_constraints();
inline Napi::Value operations_research::GMPSolver::global_num_variables( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), MPSolver::global_num_variables() );
    }

    ThrowJsError( operations_research::GMPSolver::global_num_variables : Invalid argument );
    return info.Env().Undefined();
}

//     int64_t                             time_limit() const;
inline Napi::Value operations_research::GMPSolver::time_limit( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), pMPSolver->time_limit() );
    }

    ThrowJsError( operations_research::GMPSolver::time_limit : Invalid argument );
    return info.Env().Undefined();
}

//     void                                set_time_limit( int64_t time_limit_milliseconds );
inline Napi::Value operations_research::GMPSolver::set_time_limit( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        int64_t time_limit_milliseconds = info[ 0 ].As< Napi::Number >().Int64Value();
        pMPSolver->set_time_limit( time_limit_milliseconds );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPSolver::set_time_limit : Invalid argument );
    return info.Env().Undefined();
}

//     double                              time_limit_in_secs() const;
inline Napi::Value operations_research::GMPSolver::time_limit_in_secs( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), pMPSolver->time_limit_in_secs() );
    }

    ThrowJsError( operations_research::GMPSolver::time_limit_in_secs : Invalid argument );
    return info.Env().Undefined();
}

//     int64_t                             wall_time() const;
inline Napi::Value operations_research::GMPSolver::wall_time( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), pMPSolver->wall_time() );
    }

    ThrowJsError( operations_research::GMPSolver::wall_time : Invalid argument );
    return info.Env().Undefined();
}

//     bool                                OwnsVariable( const MPVariable* var ) const;
inline Napi::Value operations_research::GMPSolver::OwnsVariable( const Napi::CallbackInfo& info )
{
    if ( info.Length() == 1 && info[ 0 ].IsObject() && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        auto var = GMPVariable::Unwrap( info[ 0 ].As< Napi::Object >() );
        return Napi::Boolean::New( info.Env(), pMPSolver->OwnsVariable( var->pMPVariable ) );
    }

    ThrowJsError( operations_research::GMPSolver::OwnsVariable : Invalid argument );
    return info.Env().Undefined();
}
