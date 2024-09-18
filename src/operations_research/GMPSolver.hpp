#pragma once

#include "napi.h"
#include "ortools/linear_solver/linear_solver.h"
#include "GMPVariable.hpp"

namespace operations_research
{

class GMPSolver : public Napi::ObjectWrap< GMPSolver >
{
public:
    static inline Napi::FunctionReference constructor;
    std::shared_ptr< MPSolver >           spMPSolver;

    GMPSolver( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GMPSolver >( info )
    {
        Napi::Env env = info.Env();

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external = info[ 0 ].As< Napi::External< MPSolver > >();
            spMPSolver    = std::shared_ptr< MPSolver >( external.Data() );
            return;
        }

        // MPSolver( const std::string& name, OptimizationProblemType problem_type );
        if ( info.Length() == 2 && info[ 0 ].IsString() && info[ 1 ].IsNumber() )
        {
            std::string name         = info[ 0 ].As< Napi::String >().Utf8Value();
            int         problem_type = info[ 1 ].As< Napi::Number >().Int32Value();
            spMPSolver               = std::make_shared< MPSolver >( name, static_cast< MPSolver::OptimizationProblemType >( problem_type ) );
            return;
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::GMPSolver : Invalid arguments" ).ThrowAsJavaScriptException();
    };

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

                // void MakeNumVarArray( int nb, double lb, double ub, const std::string& name, std::vector< MPVariable* >* vars );

                // void MakeIntVarArray( int nb, double lb, double ub, const std::string& name, std::vector< MPVariable* >* vars );

                // void MakeBoolVarArray( int nb, const std::string& name, std::vector< MPVariable* >* vars );

                // int NumConstraints() const;

                // const std::vector< MPConstraint* >& constraints() const;

                // MPConstraint* constraint( int index ) const;

                // MPConstraint* LookupConstraintOrNull( const std::string& constraint_name ) const;

                // MPConstraint* MakeRowConstraint( double lb, double ub );

                // MPConstraint* MakeRowConstraint();

                // MPConstraint* MakeRowConstraint( double lb, double ub, const std::string& name );

                // MPConstraint* MakeRowConstraint( const std::string& name );

                // MPConstraint* MakeRowConstraint( const LinearRange& range );

                // MPConstraint* MakeRowConstraint( const LinearRange& range, const std::string& name );

                // const MPObjective& Objective() const;

                // MPObjective* MutableObjective();

                // ResultStatus Solve();

                // ResultStatus Solve( const MPSolverParameters& param );

                // void Write( const std::string& file_name );

                // std::vector< double > ComputeConstraintActivities() const;

                // bool VerifySolution( double tolerance, bool log_errors ) const;

                // void Reset();

                // bool InterruptSolve();

                // MPSolverResponseStatus LoadModelFromProto( const MPModelProto& input_model, std::string* error_message, bool clear_names = true );

                // MPSolverResponseStatus LoadModelFromProtoWithUniqueNamesOrDie( const MPModelProto& input_model, std::string* error_message );

                // void FillSolutionResponseProto( MPSolutionResponse* response ) const;

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
            std::string solver_id  = info[ 0 ].As< Napi::String >().Utf8Value();
            MPSolver*   spMPSolver = MPSolver::CreateSolver( solver_id );
            auto        external   = Napi::External< MPSolver >::New( env, spMPSolver );
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
            return Napi::Boolean::New( env, spMPSolver->IsMIP() );
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
            return Napi::String::New( env, spMPSolver->Name() );
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
            return Napi::Number::New( env, static_cast< int >( spMPSolver->ProblemType() ) );
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
            spMPSolver->Clear();
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
            return Napi::Number::New( env, spMPSolver->NumVariables() );
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
            auto variables = spMPSolver->variables();
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
            auto var   = spMPSolver->variable( index );
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
            auto        var      = spMPSolver->LookupVariableOrNull( var_name );
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
            auto        var      = spMPSolver->MakeVar( lb, ub, integer, name );
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
            auto        var      = spMPSolver->MakeNumVar( lb, ub, name );
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
            auto        var      = spMPSolver->MakeIntVar( lb, ub, name );
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
            auto        var      = spMPSolver->MakeBoolVar( name );
            auto        external = Napi::External< MPVariable >::New( env, var );
            return GMPVariable::constructor.New( { external } );
        }

        Napi::TypeError::New( env, "operations_research::GMPSolver::MakeBoolVar : Invalid arguments" ).ThrowAsJavaScriptException();
        return env.Null();
    };

    // void MakeVarArray( int nb, double lb, double ub, bool integer, const std::string& name_prefix, std::vector< MPVariable* >* vars );

    // void MakeNumVarArray( int nb, double lb, double ub, const std::string& name, std::vector< MPVariable* >* vars );

    // void MakeIntVarArray( int nb, double lb, double ub, const std::string& name, std::vector< MPVariable* >* vars );

    // void MakeBoolVarArray( int nb, const std::string& name, std::vector< MPVariable* >* vars );

    // int NumConstraints() const;

    // const std::vector< MPConstraint* >& constraints() const;

    // MPConstraint* constraint( int index ) const;

    // MPConstraint* LookupConstraintOrNull( const std::string& constraint_name ) const;

    // MPConstraint* MakeRowConstraint( double lb, double ub );

    // MPConstraint* MakeRowConstraint();

    // MPConstraint* MakeRowConstraint( double lb, double ub, const std::string& name );

    // MPConstraint* MakeRowConstraint( const std::string& name );

    // MPConstraint* MakeRowConstraint( const LinearRange& range );

    // MPConstraint* MakeRowConstraint( const LinearRange& range, const std::string& name );

    // const MPObjective& Objective() const;

    // MPObjective* MutableObjective();

    // ResultStatus Solve();

    // ResultStatus Solve( const MPSolverParameters& param );

    // void Write( const std::string& file_name );

    // std::vector< double > ComputeConstraintActivities() const;

    // bool VerifySolution( double tolerance, bool log_errors ) const;

    // void Reset();

    // bool InterruptSolve();

    // MPSolverResponseStatus LoadModelFromProto( const MPModelProto& input_model, std::string* error_message, bool clear_names = true );

    // MPSolverResponseStatus LoadModelFromProtoWithUniqueNamesOrDie( const MPModelProto& input_model, std::string* error_message );

    // void FillSolutionResponseProto( MPSolutionResponse* response ) const;

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