#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"
#include "GMPVariable.hpp"
#include "GMPConstraint.hpp"
#include "GLinearRange.hpp"
#include "GMPObjective.hpp"
#include "GMPSolverParameters.hpp"
#include "GMPModelProto.hpp"
#include "GMPSolutionResponse.hpp"

namespace operations_research
{

class GMPSolver : public Napi::ObjectWrap< GMPSolver >
{
public:
    static inline Napi::FunctionReference constructor;
    MPSolver*                             pMPSolver;

    GMPSolver( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GMPSolver >( info )
    {
        Napi::Env env = info.Env();

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external = info[ 0 ].As< Napi::External< MPSolver > >();
            pMPSolver     = dynamic_cast< MPSolver* >( external.Data() );
            if ( pMPSolver ) return;
        }

        // MPSolver( const std::string& name, OptimizationProblemType problem_type );
        if ( info.Length() == 2 && info[ 0 ].IsString() && info[ 1 ].IsNumber() )
        {
            std::string name         = info[ 0 ].As< Napi::String >().Utf8Value();
            int         problem_type = info[ 1 ].As< Napi::Number >().Int32Value();
            pMPSolver                = new MPSolver( name, static_cast< MPSolver::OptimizationProblemType >( problem_type ) );
            return;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::GMPSolver : Invalid arguments" ).ThrowAsJavaScriptException();
    };

    ~GMPSolver()
    {
        if ( pMPSolver ) delete pMPSolver;
    }

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );

        auto enumOptimizationProblemType = Napi::Object::New( env );
        enumOptimizationProblemType.Set( "CLP_LINEAR_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::CLP_LINEAR_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "GLPK_LINEAR_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::GLPK_LINEAR_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "GLOP_LINEAR_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::GLOP_LINEAR_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "PDLP_LINEAR_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::PDLP_LINEAR_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "HIGHS_LINEAR_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::HIGHS_LINEAR_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "SCIP_MIXED_INTEGER_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::SCIP_MIXED_INTEGER_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "GLPK_MIXED_INTEGER_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::GLPK_MIXED_INTEGER_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "CBC_MIXED_INTEGER_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::CBC_MIXED_INTEGER_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "HIGHS_MIXED_INTEGER_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::HIGHS_MIXED_INTEGER_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "BOP_INTEGER_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::BOP_INTEGER_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "SAT_INTEGER_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::SAT_INTEGER_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "KNAPSACK_MIXED_INTEGER_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::KNAPSACK_MIXED_INTEGER_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "GUROBI_LINEAR_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::GUROBI_LINEAR_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "GUROBI_MIXED_INTEGER_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::GUROBI_MIXED_INTEGER_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "CPLEX_LINEAR_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::CPLEX_LINEAR_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "CPLEX_MIXED_INTEGER_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::CPLEX_MIXED_INTEGER_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "XPRESS_LINEAR_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::XPRESS_LINEAR_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "XPRESS_MIXED_INTEGER_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::XPRESS_MIXED_INTEGER_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "COPT_LINEAR_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::COPT_LINEAR_PROGRAMMING ) );
        enumOptimizationProblemType.Set( "COPT_MIXED_INTEGER_PROGRAMMING", static_cast< int >( MPSolver::OptimizationProblemType::COPT_MIXED_INTEGER_PROGRAMMING ) );

        Napi::Object enumResultStatus = Napi::Object::New( env );
        enumResultStatus.Set( "OPTIMAL", static_cast< int >( MPSolver::ResultStatus::OPTIMAL ) );
        enumResultStatus.Set( "FEASIBLE", static_cast< int >( MPSolver::ResultStatus::FEASIBLE ) );
        enumResultStatus.Set( "INFEASIBLE", static_cast< int >( MPSolver::ResultStatus::INFEASIBLE ) );
        enumResultStatus.Set( "UNBOUNDED", static_cast< int >( MPSolver::ResultStatus::UNBOUNDED ) );
        enumResultStatus.Set( "ABNORMAL", static_cast< int >( MPSolver::ResultStatus::ABNORMAL ) );
        enumResultStatus.Set( "MODEL_INVALID", static_cast< int >( MPSolver::ResultStatus::MODEL_INVALID ) );
        enumResultStatus.Set( "NOT_SOLVED", static_cast< int >( MPSolver::ResultStatus::NOT_SOLVED ) );

        Napi::Object enumBasisStatus = Napi::Object::New( env );
        enumBasisStatus.Set( "FREE", static_cast< int >( MPSolver::BasisStatus::FREE ) );
        enumBasisStatus.Set( "AT_LOWER_BOUND", static_cast< int >( MPSolver::BasisStatus::AT_LOWER_BOUND ) );
        enumBasisStatus.Set( "AT_UPPER_BOUND", static_cast< int >( MPSolver::BasisStatus::AT_UPPER_BOUND ) );
        enumBasisStatus.Set( "FIXED_VALUE", static_cast< int >( MPSolver::BasisStatus::FIXED_VALUE ) );
        enumBasisStatus.Set( "BASIC", static_cast< int >( MPSolver::BasisStatus::BASIC ) );

        Napi::Function func = DefineClass(
            env, "MPSolver",
            {
                StaticValue( "OptimizationProblemType", enumOptimizationProblemType ),
                StaticValue( "ResultStatus", enumResultStatus ),
                StaticValue( "BasisStatus", enumBasisStatus ),

                // static MPSolver* CreateSolver( const std::string& solver_id );
                StaticMethod( "CreateSolver", &GMPSolver::CreateSolver ),

                // static MPSolver* CreateSolver( const std::string& solver_id );
                StaticMethod( "SupportsProblemType", &GMPSolver::SupportsProblemType ),

                // static bool ParseSolverType( absl::string_view solver_id, OptimizationProblemType* type );
                StaticMethod( "ParseSolverType", &GMPSolver::ParseSolverType ),

                // static OptimizationProblemType ParseSolverTypeOrDie( const std::string& solver_id );
                StaticMethod( "ParseSolverTypeOrDie", &GMPSolver::ParseSolverTypeOrDie ),

                // bool IsMIP() const;
                InstanceMethod( "IsMIP", &GMPSolver::IsMIP ),

                // const std::string& Name() const;
                InstanceMethod( "Name", &GMPSolver::Name ),

                // virtual OptimizationProblemType ProblemType() const;
                InstanceMethod( "ProblemType", &GMPSolver::ProblemType ),

                // void Clear();
                InstanceMethod( "Clear", &GMPSolver::Clear ),

                // int NumVariables() const;
                InstanceMethod( "NumVariables", &GMPSolver::NumVariables ),

                // const std::vector< MPVariable* >& variables() const;
                InstanceMethod( "variables", &GMPSolver::variables ),

                // MPVariable* variable( int index ) const;
                InstanceMethod( "variable", &GMPSolver::variable ),

                // MPVariable* LookupVariableOrNull( const std::string& var_name ) const;
                InstanceMethod( "LookupVariableOrNull", &GMPSolver::LookupVariableOrNull ),

                // MPVariable* MakeVar( double lb, double ub, bool integer, const std::string& name );
                InstanceMethod( "MakeVar", &GMPSolver::MakeVar ),

                // MPVariable* MakeNumVar( double lb, double ub, const std::string& name );
                InstanceMethod( "MakeNumVar", &GMPSolver::MakeNumVar ),

                // MPVariable* MakeIntVar( double lb, double ub, const std::string& name );
                InstanceMethod( "MakeIntVar", &GMPSolver::MakeIntVar ),

                // MPVariable* MakeBoolVar( const std::string& name );
                InstanceMethod( "MakeBoolVar", &GMPSolver::MakeBoolVar ),

                // void MakeVarArray( int nb, double lb, double ub, bool integer, const std::string& name_prefix, std::vector< MPVariable* >* vars );
                InstanceMethod( "MakeVarArray", &GMPSolver::MakeVarArray ),

                // void MakeNumVarArray( int nb, double lb, double ub, const std::string& name, std::vector< MPVariable* >* vars );
                InstanceMethod( "MakeNumVarArray", &GMPSolver::MakeNumVarArray ),

                // void MakeIntVarArray( int nb, double lb, double ub, const std::string& name, std::vector< MPVariable* >* vars );
                InstanceMethod( "MakeIntVarArray", &GMPSolver::MakeIntVarArray ),

                // void MakeBoolVarArray( int nb, const std::string& name, std::vector< MPVariable* >* vars );
                InstanceMethod( "MakeBoolVarArray", &GMPSolver::MakeBoolVarArray ),

                // int NumConstraints() const;
                InstanceMethod( "NumConstraints", &GMPSolver::NumConstraints ),

                // const std::vector< MPConstraint* >& constraints() const;
                InstanceMethod( "constraints", &GMPSolver::constraints ),

                // MPConstraint* constraint( int index ) const;
                InstanceMethod( "constraint", &GMPSolver::constraint ),

                // MPConstraint* LookupConstraintOrNull( const std::string& constraint_name ) const;
                InstanceMethod( "LookupConstraintOrNull", &GMPSolver::LookupConstraintOrNull ),

                // MPConstraint* MakeRowConstraint( double lb, double ub );
                // MPConstraint* MakeRowConstraint();
                // MPConstraint* MakeRowConstraint( double lb, double ub, const std::string& name );
                // MPConstraint* MakeRowConstraint( const std::string& name );
                // MPConstraint* MakeRowConstraint( const LinearRange& range );
                // MPConstraint* MakeRowConstraint( const LinearRange& range, const std::string& name );
                InstanceMethod( "MakeRowConstraint", &GMPSolver::MakeRowConstraint ),

                // MPObjective* MutableObjective();
                InstanceMethod( "MutableObjective", &GMPSolver::MutableObjective ),

                // ResultStatus Solve();
                // ResultStatus Solve( const MPSolverParameters& param );
                InstanceMethod( "Solve", &GMPSolver::Solve ),

                // void Write( const std::string& file_name );
                InstanceMethod( "Write", &GMPSolver::Write ),

                // std::vector< double > ComputeConstraintActivities() const;
                InstanceMethod( "ComputeConstraintActivities", &GMPSolver::ComputeConstraintActivities ),

                // bool VerifySolution( double tolerance, bool log_errors ) const;
                InstanceMethod( "VerifySolution", &GMPSolver::VerifySolution ),

                // void Reset();
                InstanceMethod( "Reset", &GMPSolver::Reset ),

                // bool InterruptSolve();
                InstanceMethod( "InterruptSolve", &GMPSolver::InterruptSolve ),

                // MPSolverResponseStatus LoadModelFromProto( const MPModelProto& input_model, std::string* error_message, bool clear_names = true );
                InstanceMethod( "LoadModelFromProto", &GMPSolver::LoadModelFromProto ),

                // MPSolverResponseStatus LoadModelFromProtoWithUniqueNamesOrDie( const MPModelProto& input_model, std::string* error_message );
                InstanceMethod( "LoadModelFromProtoWithUniqueNamesOrDie", &GMPSolver::LoadModelFromProtoWithUniqueNamesOrDie ),

                // void FillSolutionResponseProto( MPSolutionResponse* response ) const;
                InstanceMethod( "FillSolutionResponseProto", &GMPSolver::FillSolutionResponseProto ),

                // ABSL_DEPRECATED( "Prefer SolveMPModel() from solve_mp_model.h." )

                // static void SolveWithProto( const MPModelRequest& model_request, MPSolutionResponse* response, std::atomic< bool >* interrupt = nullptr );

                // ABSL_DEPRECATED( "Prefer SolveMPModel() from solve_mp_model.h." )

                // static void SolveLazyMutableRequest( LazyMutableCopy< MPModelRequest > request, MPSolutionResponse* response, std::atomic< bool >* interrupt = nullptr );

                // ABSL_DEPRECATED( "Prefer SolverTypeSupportsInterruption() from solve_mp_model.h." )

                // static bool SolverTypeSupportsInterruption( const MPModelRequest::SolverType solver );

                // void ExportModelToProto( MPModelProto* output_model ) const;

                // absl::Status LoadSolutionFromProto( const MPSolutionResponse& response, double tolerance = std::numeric_limits< double >::infinity() );

                // absl::Status ClampSolutionWithinBounds();

                // bool ExportModelAsLpFormat( bool obfuscate, std::string* model_str ) const;

                // bool ExportModelAsMpsFormat( bool fixed_format, bool obfuscate, std::string* model_str ) const;

                // absl::Status SetNumThreads( int num_threads );

                // int GetNumThreads() const;

                // bool SetSolverSpecificParametersAsString( const std::string& parameters );

                // std::string GetSolverSpecificParametersAsString() const;

                // void SetHint( std::vector< std::pair< const MPVariable*, double > > hint );

                // ABSL_DEPRECATED( "Prefer MPModelRequestLoggingInfo() from solve_mp_model.h." )

                // static std::string GetMPModelRequestLoggingInfo( const MPModelRequest& request );

                // void SetStartingLpBasis( const std::vector< MPSolver::BasisStatus >& variable_statuses, const std::vector< MPSolver::BasisStatus >& constraint_statuses );

                // static double infinity();

                // double solver_infinity();

                // bool OutputIsEnabled() const;

                // void EnableOutput();

                // void SuppressOutput();

                // absl::Duration TimeLimit() const;

                // void SetTimeLimit( absl::Duration time_limit );

                // absl::Duration DurationSinceConstruction() const;

                // int64_t iterations() const;

                // int64_t nodes() const;

                // std::string SolverVersion() const;

                // void* underlying_solver();

                // double ComputeExactConditionNumber() const;

                // ABSL_MUST_USE_RESULT bool NextSolution();

                // void SetCallback( MPCallback* mp_callback );

                // bool SupportsCallbacks() const;

                // static int64_t global_num_variables();

                // static int64_t global_num_constraints();

                // int64_t time_limit() const;

                // void set_time_limit( int64_t time_limit_milliseconds );

                // double time_limit_in_secs() const;

                // int64_t wall_time() const;

                // bool OwnsVariable( const MPVariable* var ) const;
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPSolver" ), func );
        return exports;
    };

    // static MPSolver* CreateSolver( const std::string& solver_id );
    static Napi::Value CreateSolver( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string solver_id = info[ 0 ].As< Napi::String >().Utf8Value();
            MPSolver*   pMPSolver = MPSolver::CreateSolver( solver_id );
            auto        external  = Napi::External< MPSolver >::New( env, pMPSolver );
            return GMPSolver::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::CreateSolver : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // static bool SupportsProblemType( OptimizationProblemType problem_type );
    static Napi::Value SupportsProblemType( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsNumber() )
        {
            int problem_type = info[ 0 ].As< Napi::Number >().Int32Value();
            return Napi::Boolean::New( env, MPSolver::SupportsProblemType( static_cast< MPSolver::OptimizationProblemType >( problem_type ) ) );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::SupportsProblemType : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // static bool ParseSolverType( absl::string_view solver_id, OptimizationProblemType* type );
    static Napi::Value ParseSolverType( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string                       solver_id = info[ 0 ].As< Napi::String >().Utf8Value();
            MPSolver::OptimizationProblemType type;
            auto                              result = MPSolver::ParseSolverType( solver_id, &type );
            auto                              ret    = Napi::Object::New( env );
            ret.Set( "return", Napi::Boolean::New( env, result ) );
            ret.Set( "type", static_cast< int >( type ) );
            return ret;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::ParseSolverType : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // static OptimizationProblemType ParseSolverTypeOrDie( const std::string& solver_id );
    static Napi::Value ParseSolverTypeOrDie( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string solver_id = info[ 0 ].As< Napi::String >().Utf8Value();
            auto        type      = MPSolver::ParseSolverTypeOrDie( solver_id );
            return Napi::Number::New( env, static_cast< int >( type ) );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::ParseSolverTypeOrDie : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // bool IsMIP() const;
    Napi::Value IsMIP( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::Boolean::New( env, pMPSolver->IsMIP() );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::IsMIP : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // const std::string& Name() const;
    Napi::Value Name( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::String::New( env, pMPSolver->Name() );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::Name : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // virtual OptimizationProblemType ProblemType() const;
    Napi::Value ProblemType( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::Number::New( env, static_cast< int >( pMPSolver->ProblemType() ) );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::ProblemType : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // void Clear();
    Napi::Value Clear( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            pMPSolver->Clear();
            return env.Undefined();
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::Clear : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // int NumVariables() const;
    Napi::Value NumVariables( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::Number::New( env, pMPSolver->NumVariables() );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::NumVariables : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // const std::vector< MPVariable* >& variables() const;
    Napi::Value variables( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            auto variables = pMPSolver->variables();
            auto ret       = Napi::Array::New( env, variables.size() );
            for ( int i = 0; i < variables.size(); i++ )
            {
                auto external = Napi::External< MPVariable >::New( env, variables[ i ] );
                ret.Set( i, GMPVariable::constructor.New( { external } ) );
            }
            return ret;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::variables : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // MPVariable* variable( int index ) const;
    Napi::Value variable( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsNumber() )
        {
            int  index = info[ 0 ].As< Napi::Number >().Int32Value();
            auto var   = pMPSolver->variable( index );
            if ( var == nullptr )
            {
                return env.Null();
            }
            auto external = Napi::External< MPVariable >::New( env, var );
            return GMPVariable::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::variable : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // MPVariable* LookupVariableOrNull( const std::string& var_name ) const;
    Napi::Value LookupVariableOrNull( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string var_name = info[ 0 ].As< Napi::String >().Utf8Value();
            auto        var      = pMPSolver->LookupVariableOrNull( var_name );
            if ( var == nullptr )
            {
                return env.Null();
            }
            auto external = Napi::External< MPVariable >::New( env, var );
            return GMPVariable::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::LookupVariableOrNull : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // MPVariable* MakeVar( double lb, double ub, bool integer, const std::string& name );
    Napi::Value MakeVar( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 4 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsBoolean() && info[ 3 ].IsString() )
        {
            double      lb       = info[ 0 ].As< Napi::Number >().DoubleValue();
            double      ub       = info[ 1 ].As< Napi::Number >().DoubleValue();
            bool        integer  = info[ 2 ].As< Napi::Boolean >().Value();
            std::string name     = info[ 3 ].As< Napi::String >().Utf8Value();
            auto        var      = pMPSolver->MakeVar( lb, ub, integer, name );
            auto        external = Napi::External< MPVariable >::New( env, var );
            return GMPVariable::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeVar : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // MPVariable* MakeNumVar( double lb, double ub, const std::string& name );
    Napi::Value MakeNumVar( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
        {
            double      lb       = info[ 0 ].As< Napi::Number >().DoubleValue();
            double      ub       = info[ 1 ].As< Napi::Number >().DoubleValue();
            std::string name     = info[ 2 ].As< Napi::String >().Utf8Value();
            auto        var      = pMPSolver->MakeNumVar( lb, ub, name );
            auto        external = Napi::External< MPVariable >::New( env, var );
            return GMPVariable::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeNumVar : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // MPVariable* MakeIntVar( double lb, double ub, const std::string& name );
    Napi::Value MakeIntVar( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
        {
            double      lb       = info[ 0 ].As< Napi::Number >().DoubleValue();
            double      ub       = info[ 1 ].As< Napi::Number >().DoubleValue();
            std::string name     = info[ 2 ].As< Napi::String >().Utf8Value();
            auto        var      = pMPSolver->MakeIntVar( lb, ub, name );
            auto        external = Napi::External< MPVariable >::New( env, var );
            return GMPVariable::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeIntVar : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // MPVariable* MakeBoolVar( const std::string& name );
    Napi::Value MakeBoolVar( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string name     = info[ 0 ].As< Napi::String >().Utf8Value();
            auto        var      = pMPSolver->MakeBoolVar( name );
            auto        external = Napi::External< MPVariable >::New( env, var );
            return GMPVariable::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeBoolVar : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // void MakeVarArray( int nb, double lb, double ub, bool integer, const std::string& name_prefix, std::vector< MPVariable* >* vars );
    Napi::Value MakeVarArray( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 5 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsNumber() && info[ 3 ].IsBoolean() && info[ 4 ].IsString() )
        {
            int                        nb          = info[ 0 ].As< Napi::Number >().Int32Value();
            double                     lb          = info[ 1 ].As< Napi::Number >().DoubleValue();
            double                     ub          = info[ 2 ].As< Napi::Number >().DoubleValue();
            bool                       integer     = info[ 3 ].As< Napi::Boolean >().Value();
            std::string                name_prefix = info[ 4 ].As< Napi::String >().Utf8Value();
            std::vector< MPVariable* > vars;
            pMPSolver->MakeVarArray( nb, lb, ub, integer, name_prefix, &vars );
            auto ret = Napi::Array::New( env, vars.size() );
            for ( int i = 0; i < vars.size(); i++ )
            {
                auto external = Napi::External< MPVariable >::New( env, vars[ i ] );
                ret.Set( i, GMPVariable::constructor.New( { external } ) );
            }
            return ret;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeVarArray : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // void MakeNumVarArray( int nb, double lb, double ub, const std::string& name, std::vector< MPVariable* >* vars );
    Napi::Value MakeNumVarArray( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 4 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsNumber() && info[ 3 ].IsString() )
        {
            int                        nb          = info[ 0 ].As< Napi::Number >().Int32Value();
            double                     lb          = info[ 1 ].As< Napi::Number >().DoubleValue();
            double                     ub          = info[ 2 ].As< Napi::Number >().DoubleValue();
            std::string                name_prefix = info[ 3 ].As< Napi::String >().Utf8Value();
            std::vector< MPVariable* > vars;
            pMPSolver->MakeNumVarArray( nb, lb, ub, name_prefix, &vars );
            auto ret = Napi::Array::New( env, vars.size() );
            for ( int i = 0; i < vars.size(); i++ )
            {
                auto external = Napi::External< MPVariable >::New( env, vars[ i ] );
                ret.Set( i, GMPVariable::constructor.New( { external } ) );
            }
            return ret;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeNumVarArray : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // void MakeIntVarArray( int nb, double lb, double ub, const std::string& name, std::vector< MPVariable* >* vars );
    Napi::Value MakeIntVarArray( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 4 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsNumber() && info[ 3 ].IsString() )
        {
            int                        nb          = info[ 0 ].As< Napi::Number >().Int32Value();
            double                     lb          = info[ 1 ].As< Napi::Number >().DoubleValue();
            double                     ub          = info[ 2 ].As< Napi::Number >().DoubleValue();
            std::string                name_prefix = info[ 3 ].As< Napi::String >().Utf8Value();
            std::vector< MPVariable* > vars;
            pMPSolver->MakeIntVarArray( nb, lb, ub, name_prefix, &vars );
            auto ret = Napi::Array::New( env, vars.size() );
            for ( int i = 0; i < vars.size(); i++ )
            {
                auto external = Napi::External< MPVariable >::New( env, vars[ i ] );
                ret.Set( i, GMPVariable::constructor.New( { external } ) );
            }
            return ret;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeIntVarArray : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // void MakeBoolVarArray( int nb, const std::string& name, std::vector< MPVariable* >* vars );
    Napi::Value MakeBoolVarArray( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsString() )
        {
            int                        nb          = info[ 0 ].As< Napi::Number >().Int32Value();
            std::string                name_prefix = info[ 1 ].As< Napi::String >().Utf8Value();
            std::vector< MPVariable* > vars;
            pMPSolver->MakeBoolVarArray( nb, name_prefix, &vars );
            auto ret = Napi::Array::New( env, vars.size() );
            for ( int i = 0; i < vars.size(); i++ )
            {
                auto external = Napi::External< MPVariable >::New( env, vars[ i ] );
                ret.Set( i, GMPVariable::constructor.New( { external } ) );
            }
            return ret;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeBoolVarArray : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // int NumConstraints() const;
    Napi::Value NumConstraints( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            return Napi::Number::New( env, pMPSolver->NumConstraints() );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::NumConstraints : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // const std::vector< MPConstraint* >& constraints() const;
    Napi::Value constraints( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            auto constraints = pMPSolver->constraints();
            auto ret         = Napi::Array::New( env, constraints.size() );
            for ( int i = 0; i < constraints.size(); i++ )
            {
                auto external = Napi::External< MPConstraint >::New( env, constraints[ i ] );
                ret.Set( i, GMPConstraint::constructor.New( { external } ) );
            }
            return ret;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::constraints : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // MPConstraint* constraint( int index ) const;
    Napi::Value constraint( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsNumber() )
        {
            int  index      = info[ 0 ].As< Napi::Number >().Int32Value();
            auto constraint = pMPSolver->constraint( index );
            if ( constraint == nullptr )
            {
                return env.Null();
            }
            auto external = Napi::External< MPConstraint >::New( env, constraint );
            return GMPConstraint::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::constraint : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // MPConstraint* LookupConstraintOrNull( const std::string& constraint_name ) const;
    Napi::Value LookupConstraintOrNull( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string constraint_name = info[ 0 ].As< Napi::String >().Utf8Value();
            auto        constraint      = pMPSolver->LookupConstraintOrNull( constraint_name );
            if ( constraint == nullptr )
            {
                return env.Null();
            }
            auto external = Napi::External< MPConstraint >::New( env, constraint );
            return GMPConstraint::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::LookupConstraintOrNull : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    Napi::Value MakeRowConstraint( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        // MPConstraint* MakeRowConstraint( double lb, double ub );
        if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() )
        {
            double lb         = info[ 0 ].As< Napi::Number >().DoubleValue();
            double ub         = info[ 1 ].As< Napi::Number >().DoubleValue();
            auto   constraint = pMPSolver->MakeRowConstraint( lb, ub );
            auto   external   = Napi::External< MPConstraint >::New( env, constraint );
            return GMPConstraint::constructor.New( { external } );
        }

        // MPConstraint* MakeRowConstraint();
        if ( info.Length() == 0 )
        {
            auto constraint = pMPSolver->MakeRowConstraint();
            auto external   = Napi::External< MPConstraint >::New( env, constraint );
            return GMPConstraint::constructor.New( { external } );
        }

        // MPConstraint* MakeRowConstraint( double lb, double ub, const std::string& name );
        if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
        {
            double      lb         = info[ 0 ].As< Napi::Number >().DoubleValue();
            double      ub         = info[ 1 ].As< Napi::Number >().DoubleValue();
            std::string name       = info[ 2 ].As< Napi::String >().Utf8Value();
            auto        constraint = pMPSolver->MakeRowConstraint( lb, ub, name );
            auto        external   = Napi::External< MPConstraint >::New( env, constraint );
            return GMPConstraint::constructor.New( { external } );
        }

        // MPConstraint* MakeRowConstraint( const std::string& name );
        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string name       = info[ 0 ].As< Napi::String >().Utf8Value();
            auto        constraint = pMPSolver->MakeRowConstraint( name );
            auto        external   = Napi::External< MPConstraint >::New( env, constraint );
            return GMPConstraint::constructor.New( { external } );
        }

        // MPConstraint* MakeRowConstraint( const LinearRange& range );
        if ( info.Length() == 1 && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearRange::constructor.Value() ) )
        {
            auto range      = GLinearRange::Unwrap( info[ 0 ].As< Napi::Object >() );
            auto constraint = pMPSolver->MakeRowConstraint( *range->pLinearRange );
            auto external   = Napi::External< MPConstraint >::New( env, constraint );
            return GMPConstraint::constructor.New( { external } );
        }

        // MPConstraint* MakeRowConstraint( const LinearRange& range, const std::string& name );
        if ( info.Length() == 2 && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearRange::constructor.Value() )
             && info[ 1 ].IsString() )
        {
            auto        range      = GLinearRange::Unwrap( info[ 0 ].As< Napi::Object >() );
            std::string name       = info[ 1 ].As< Napi::String >().Utf8Value();
            auto        constraint = pMPSolver->MakeRowConstraint( *range->pLinearRange, name );
            auto        external   = Napi::External< MPConstraint >::New( env, constraint );
            return GMPConstraint::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeRowConstraint : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // MPObjective* MutableObjective();
    Napi::Value MutableObjective( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            auto objective = pMPSolver->MutableObjective();
            auto external  = Napi::External< MPObjective >::New( env, objective );
            return GMPObjective::constructor.New( { external, Napi::Boolean::New( env, true ) } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MutableObjective : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    Napi::Value Solve( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        // ResultStatus Solve();
        if ( info.Length() == 0 )
        {
            return Napi::Number::New( env, static_cast< int >( pMPSolver->Solve() ) );
        }

        // ResultStatus Solve( const MPSolverParameters& param );
        if ( info.Length() == 1 && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GMPSolverParameters::constructor.Value() ) )
        {
            auto param = GMPSolverParameters::Unwrap( info[ 0 ].As< Napi::Object >() );
            return Napi::Number::New( env, static_cast< int >( pMPSolver->Solve( *param->pMPSolverParameters ) ) );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::Solve : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // void Write( const std::string& file_name );
    Napi::Value Write( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string file_name = info[ 0 ].As< Napi::String >().Utf8Value();
            pMPSolver->Write( file_name );
            return env.Undefined();
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::Write : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // std::vector< double > ComputeConstraintActivities() const;
    Napi::Value ComputeConstraintActivities( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            auto activities = pMPSolver->ComputeConstraintActivities();
            auto ret        = Napi::Array::New( env, activities.size() );
            for ( int i = 0; i < activities.size(); i++ )
            {
                ret.Set( i, Napi::Number::New( env, activities[ i ] ) );
            }
            return ret;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::ComputeConstraintActivities : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // bool VerifySolution( double tolerance, bool log_errors ) const;
    Napi::Value VerifySolution( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsBoolean() )
        {
            double tolerance  = info[ 0 ].As< Napi::Number >().DoubleValue();
            bool   log_errors = info[ 1 ].As< Napi::Boolean >().Value();
            bool   ret        = pMPSolver->VerifySolution( tolerance, log_errors );
            return Napi::Boolean::New( env, ret );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::VerifySolution : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // void Reset();
    Napi::Value Reset( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            pMPSolver->Reset();
            return env.Undefined();
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::Reset : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // bool InterruptSolve();
    Napi::Value InterruptSolve( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 0 )
        {
            bool ret = pMPSolver->InterruptSolve();
            return Napi::Boolean::New( env, ret );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::InterruptSolve : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // MPSolverResponseStatus LoadModelFromProto( const MPModelProto& input_model, std::string* error_message, bool clear_names = true );
    Napi::Value LoadModelFromProto( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GMPModelProto::constructor.Value() ) )
        {
            auto        input_model = GMPModelProto::Unwrap( info[ 0 ].As< Napi::Object >() );
            std::string error_message;
            auto        result = pMPSolver->LoadModelFromProto( *input_model->pMPModelProto, &error_message, true );
            auto        ret    = Napi::Object::New( env );
            ret.Set( "return", Napi::Number::New( env, static_cast< int >( result ) ) );
            ret.Set( "error_message", Napi::String::New( env, error_message ) );
            return ret;
        }

        if ( info.Length() == 2 && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GMPModelProto::constructor.Value() )
             && info[ 1 ].IsBoolean() )
        {
            auto        input_model = GMPModelProto::Unwrap( info[ 0 ].As< Napi::Object >() );
            bool        clear_names = info[ 1 ].As< Napi::Boolean >().Value();
            std::string error_message;
            auto        result = pMPSolver->LoadModelFromProto( *input_model->pMPModelProto, &error_message, clear_names );
            auto        ret    = Napi::Object::New( env );
            ret.Set( "return", Napi::Number::New( env, static_cast< int >( result ) ) );
            ret.Set( "error_message", Napi::String::New( env, error_message ) );
            return ret;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::LoadModelFromProto : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // MPSolverResponseStatus LoadModelFromProtoWithUniqueNamesOrDie( const MPModelProto& input_model, std::string* error_message );
    Napi::Value LoadModelFromProtoWithUniqueNamesOrDie( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GMPModelProto::constructor.Value() ) )
        {
            auto        input_model = GMPModelProto::Unwrap( info[ 0 ].As< Napi::Object >() );
            std::string error_message;
            auto        result = pMPSolver->LoadModelFromProtoWithUniqueNamesOrDie( *input_model->pMPModelProto, &error_message );
            auto        ret    = Napi::Object::New( env );
            ret.Set( "return", Napi::Number::New( env, static_cast< int >( result ) ) );
            ret.Set( "error_message", Napi::String::New( env, error_message ) );
            return ret;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::LoadModelFromProtoWithUniqueNamesOrDie : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // void FillSolutionResponseProto( MPSolutionResponse* response ) const;
    Napi::Value FillSolutionResponseProto( const Napi::CallbackInfo& info )
    {
        Napi::Env         env = info.Env();
        Napi::HandleScope scope( env );

        if ( info.Length() == 1 && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GMPSolutionResponse::constructor.Value() ) )
        {
            auto        response = GMPSolutionResponse::Unwrap( info[ 0 ].As< Napi::Object >() );
            pMPSolver->FillSolutionResponseProto( response->pMPSolutionResponse );
            return env.Undefined();
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::FillSolutionResponseProto : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // ABSL_DEPRECATED( "Prefer SolveMPModel() from solve_mp_model.h." )

    // static void SolveWithProto( const MPModelRequest& model_request, MPSolutionResponse* response, std::atomic< bool >* interrupt = nullptr );

    // ABSL_DEPRECATED( "Prefer SolveMPModel() from solve_mp_model.h." )

    // static void SolveLazyMutableRequest( LazyMutableCopy< MPModelRequest > request, MPSolutionResponse* response, std::atomic< bool >* interrupt = nullptr );

    // ABSL_DEPRECATED( "Prefer SolverTypeSupportsInterruption() from solve_mp_model.h." )

    // static bool SolverTypeSupportsInterruption( const MPModelRequest::SolverType solver );

    // void ExportModelToProto( MPModelProto* output_model ) const;

    // absl::Status LoadSolutionFromProto( const MPSolutionResponse& response, double tolerance = std::numeric_limits< double >::infinity() );

    // absl::Status ClampSolutionWithinBounds();

    // bool ExportModelAsLpFormat( bool obfuscate, std::string* model_str ) const;

    // bool ExportModelAsMpsFormat( bool fixed_format, bool obfuscate, std::string* model_str ) const;

    // absl::Status SetNumThreads( int num_threads );

    // int GetNumThreads() const;

    // bool SetSolverSpecificParametersAsString( const std::string& parameters );

    // std::string GetSolverSpecificParametersAsString() const;

    // void SetHint( std::vector< std::pair< const MPVariable*, double > > hint );

    // ABSL_DEPRECATED( "Prefer MPModelRequestLoggingInfo() from solve_mp_model.h." )

    // static std::string GetMPModelRequestLoggingInfo( const MPModelRequest& request );

    // void SetStartingLpBasis( const std::vector< MPSolver::BasisStatus >& variable_statuses, const std::vector< MPSolver::BasisStatus >& constraint_statuses );

    // static double infinity();

    // double solver_infinity();

    // bool OutputIsEnabled() const;

    // void EnableOutput();

    // void SuppressOutput();

    // absl::Duration TimeLimit() const;

    // void SetTimeLimit( absl::Duration time_limit );

    // absl::Duration DurationSinceConstruction() const;

    // int64_t iterations() const;

    // int64_t nodes() const;

    // std::string SolverVersion() const;

    // void* underlying_solver();

    // double ComputeExactConditionNumber() const;

    // ABSL_MUST_USE_RESULT bool NextSolution();

    // void SetCallback( MPCallback* mp_callback );

    // bool SupportsCallbacks() const;

    // static int64_t global_num_variables();

    // static int64_t global_num_constraints();

    // int64_t time_limit() const;

    // void set_time_limit( int64_t time_limit_milliseconds );

    // double time_limit_in_secs() const;

    // int64_t wall_time() const;

    // bool OwnsVariable( const MPVariable* var ) const;
};

};  // namespace operations_research