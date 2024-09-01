#include "index.hpp"

operations_research::GMPSolver::GMPSolver( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< operations_research::GMPSolver >( info )
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
        std::string name              = info[ 0 ].As< Napi::String >();
        int         problem_type      = info[ 1 ].As< Napi::Number >();
        using OptimizationProblemType = MPSolver::OptimizationProblemType;
        pMPSolver                     = new MPSolver( name, static_cast< OptimizationProblemType >( problem_type ) );
        return;
    }

    ThrowJsError( operations_research::GMPSolver::GMPSolver : Invalid argument );
}

operations_research::GMPSolver::~GMPSolver()
{
    delete pMPSolver;
}

Napi::Value operations_research::GMPSolver::SolverTypeSupportsInterruption( const Napi::CallbackInfo& info )
{
    // static bool SolverTypeSupportsInterruption(const MPModelRequest::SolverType solver );
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        int solver_type = info[ 0 ].As< Napi::Number >();
        return Napi::Boolean::New( info.Env(), MPSolver::SolverTypeSupportsInterruption( static_cast< MPModelRequest::SolverType >( solver_type ) ) );
    }

    ThrowJsError( operations_research::GMPSolver::SolverTypeSupportsInterruption : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::ParseSolverTypeOrDie( const Napi::CallbackInfo& info )
{
    // static OptimizationProblemType ParseSolverTypeOrDie( const std::string& solver_id );
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string solver_id         = info[ 0 ].As< Napi::String >();
        using OptimizationProblemType = MPSolver::OptimizationProblemType;
        auto type                     = MPSolver::ParseSolverTypeOrDie( solver_id );
        return Napi::Number::New( info.Env(), static_cast< int >( type ) );
    }

    ThrowJsError( operations_research::GMPSolver::ParseSolverTypeOrDie : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::ParseSolverType( const Napi::CallbackInfo& info )
{
    // static bool ParseSolverType( absl::string_view solver_id, OptimizationProblemType* type );
    if ( info.Length() == 2 && info[ 0 ].IsString() && info[ 1 ].IsNumber() )
    {
        std::string solver_id         = info[ 0 ].As< Napi::String >();
        using OptimizationProblemType = MPSolver::OptimizationProblemType;
        OptimizationProblemType type  = static_cast< OptimizationProblemType >( info[ 1 ].As< Napi::Number >().Int32Value() );
        return Napi::Boolean::New( info.Env(), MPSolver::ParseSolverType( solver_id, &type ) );
    }

    ThrowJsError( operations_research::GMPSolver::ParseSolverType : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::SupportsProblemType( const Napi::CallbackInfo& info )
{
    // static bool SupportsProblemType( OptimizationProblemType problem_type );
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        int problem_type              = info[ 0 ].As< Napi::Number >();
        using OptimizationProblemType = MPSolver::OptimizationProblemType;
        return Napi::Boolean::New( info.Env(), MPSolver::SupportsProblemType( static_cast< OptimizationProblemType >( problem_type ) ) );
    }

    ThrowJsError( operations_research::GMPSolver::SupportsProblemType : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::CreateSolver( const Napi::CallbackInfo& info )
{
    //     static MPSolver* CreateSolver( const std::string& solver_id );
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string solver_id  = info[ 0 ].As< Napi::String >();
        MPSolver*   pMPSolver  = MPSolver::CreateSolver( solver_id );
        auto        gmp_solver = Napi::External< MPSolver >::New( info.Env(), pMPSolver );
        return GMPSolver::constructor.New( { gmp_solver } );
    }

    ThrowJsError( operations_research::GMPSolver::CreateSolver : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::SolveWithProto( const Napi::CallbackInfo& info )
{
    // static void SolveWithProto( const MPModelRequest& model_request, MPSolutionResponse*   response, std::atomic< bool >* interrupt = nullptr );
    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GMPModelRequest::constructor.Value() )
         && info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GMPSolutionResponse::constructor.Value() ) )
    {
        auto                 gmp_model_request     = Napi::ObjectWrap< GMPModelRequest >::Unwrap( info[ 0 ].As< Napi::Object >() );
        auto                 gmp_solution_response = Napi::ObjectWrap< GMPSolutionResponse >::Unwrap( info[ 1 ].As< Napi::Object >() );
        std::atomic< bool >* interrupt             = nullptr;
        MPSolver::SolveWithProto( *gmp_model_request->pMPModelRequest, gmp_solution_response->pMPSolutionResponse, interrupt );
        return info.Env().Undefined();
    }

    if ( info.Length() == 3
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GMPModelRequest::constructor.Value() )
         && info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GMPSolutionResponse::constructor.Value() )
         && info[ 2 ].IsBoolean() )
    {
        auto                 gmp_model_request     = Napi::ObjectWrap< GMPModelRequest >::Unwrap( info[ 0 ].As< Napi::Object >() );
        auto                 gmp_solution_response = Napi::ObjectWrap< GMPSolutionResponse >::Unwrap( info[ 1 ].As< Napi::Object >() );
        std::atomic< bool >* interrupt             = new std::atomic< bool >( info[ 2 ].As< Napi::Boolean >().Value() );
        MPSolver::SolveWithProto( *gmp_model_request->pMPModelRequest, gmp_solution_response->pMPSolutionResponse, interrupt );
        delete interrupt;
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPSolver::SolveWithProto : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::FillSolutionResponseProto( const Napi::CallbackInfo& info )
{
    // void FillSolutionResponseProto( MPSolutionResponse* response ) const;
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GMPSolutionResponse::constructor.Value() ) )
    {
        auto gmp_solution_response = Napi::ObjectWrap< GMPSolutionResponse >::Unwrap( info[ 0 ].As< Napi::Object >() );
        pMPSolver->FillSolutionResponseProto( gmp_solution_response->pMPSolutionResponse );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPSolver::FillSolutionResponseProto : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::LoadModelFromProtoWithUniqueNamesOrDie( const Napi::CallbackInfo& info )
{
    //  MPSolverResponseStatus LoadModelFromProtoWithUniqueNamesOrDie(  const MPModelProto& input_model, std::string* error_message );
    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GMPModelProto::constructor.Value() )
         && info[ 1 ].IsString() )
    {
        auto                   gmp_model_proto = Napi::ObjectWrap< GMPModelProto >::Unwrap( info[ 0 ].As< Napi::Object >() );
        std::string            error_message;
        MPSolverResponseStatus status = pMPSolver->LoadModelFromProtoWithUniqueNamesOrDie( *gmp_model_proto->pMPModelProto, &error_message );
        return Napi::Number::New( info.Env(), static_cast< int >( status ) );
    }

    ThrowJsError( operations_research::GMPSolver::LoadModelFromProtoWithUniqueNamesOrDie : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::LoadModelFromProto( const Napi::CallbackInfo& info )
{
    // MPSolverResponseStatus LoadModelFromProto( const MPModelProto& input_model, std::string*        error_message );
    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GMPModelProto::constructor.Value() )
         && info[ 1 ].IsString() )
    {
        auto                   gmp_model_proto = Napi::ObjectWrap< GMPModelProto >::Unwrap( info[ 0 ].As< Napi::Object >() );
        std::string            error_message;
        MPSolverResponseStatus status = pMPSolver->LoadModelFromProto( *gmp_model_proto->pMPModelProto, &error_message );
        return Napi::Number::New( info.Env(), static_cast< int >( status ) );
    }

    ThrowJsError( operations_research::GMPSolver::LoadModelFromProto : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::InterruptSolve( const Napi::CallbackInfo& info )
{
    // bool InterruptSolve();
    if ( info.Length() == 0 )
    {
        return Napi::Boolean::New( info.Env(), pMPSolver->InterruptSolve() );
    }

    ThrowJsError( operations_research::GMPSolver::InterruptSolve : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::Reset( const Napi::CallbackInfo& info )
{
    //  void Reset();
    if ( info.Length() == 0 )
    {
        pMPSolver->Reset();
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPSolver::Reset : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::VerifySolution( const Napi::CallbackInfo& info )
{
    // bool VerifySolution( double tolerance, bool log_errors ) const;
    if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsBoolean() )
    {
        double tolerance  = info[ 0 ].As< Napi::Number >();
        bool   log_errors = info[ 1 ].As< Napi::Boolean >();
        bool   result     = pMPSolver->VerifySolution( tolerance, log_errors );
        return Napi::Boolean::New( info.Env(), result );
    }

    ThrowJsError( operations_research::GMPSolver::VerifySolution : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::ComputeConstraintActivities( const Napi::CallbackInfo& info )
{
    // std::vector< double > ComputeConstraintActivities() const;
    if ( info.Length() == 0 )
    {
        std::vector< double > activities = pMPSolver->ComputeConstraintActivities();
        Napi::Array           result     = Napi::Array::New( info.Env(), activities.size() );
        for ( int i = 0; i < activities.size(); i++ )
        {
            result[ i ] = Napi::Number::New( info.Env(), activities[ i ] );
        }
        return result;
    }

    ThrowJsError( operations_research::GMPSolver::ComputeConstraintActivities : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::Write( const Napi::CallbackInfo& info )
{
    // void Write( const std::string& file_name );
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string file_name = info[ 0 ].As< Napi::String >();
        pMPSolver->Write( file_name );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPSolver::Write : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::MakeBoolVar( const Napi::CallbackInfo& info )
{
    // MPVariable* MakeBoolVar( const std::string& name );
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string name         = info[ 0 ].As< Napi::String >();
        MPVariable* pMPVariable  = pMPSolver->MakeBoolVar( name );
        auto        gmp_variable = Napi::External< MPVariable >::New( info.Env(), pMPVariable );
        return GMPVariable::constructor.New( { gmp_variable } );
    }

    ThrowJsError( operations_research::GMPSolver::MakeBoolVar : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::MakeRowConstraint( const Napi::CallbackInfo& info )
{
    // MPConstraint* MakeRowConstraint( double lb, double ub );
    if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() )
    {
        double        lb             = info[ 0 ].As< Napi::Number >();
        double        ub             = info[ 1 ].As< Napi::Number >();
        MPConstraint* pMPConstraint  = pMPSolver->MakeRowConstraint( lb, ub );
        auto          gmp_constraint = Napi::External< MPConstraint >::New( info.Env(), pMPConstraint );
        return GMPConstraint::constructor.New( { gmp_constraint } );
    }

    //  MPConstraint* MakeRowConstraint();
    if ( info.Length() == 0 )
    {
        MPConstraint* pMPConstraint  = pMPSolver->MakeRowConstraint();
        auto          gmp_constraint = Napi::External< MPConstraint >::New( info.Env(), pMPConstraint );
        return GMPConstraint::constructor.New( { gmp_constraint } );
    }

    // MPConstraint* MakeRowConstraint( double lb, double ub, const std::string& name );
    if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
    {
        double        lb             = info[ 0 ].As< Napi::Number >();
        double        ub             = info[ 1 ].As< Napi::Number >();
        std::string   name           = info[ 2 ].As< Napi::String >();
        MPConstraint* pMPConstraint  = pMPSolver->MakeRowConstraint( lb, ub, name );
        auto          gmp_constraint = Napi::External< MPConstraint >::New( info.Env(), pMPConstraint );
        return GMPConstraint::constructor.New( { gmp_constraint } );
    }

    // MPConstraint* MakeRowConstraint( const std::string& name );
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string   name           = info[ 0 ].As< Napi::String >();
        MPConstraint* pMPConstraint  = pMPSolver->MakeRowConstraint( name );
        auto          gmp_constraint = Napi::External< MPConstraint >::New( info.Env(), pMPConstraint );
        return GMPConstraint::constructor.New( { gmp_constraint } );
    }

    // MPConstraint* MakeRangeConstraint( const LinearRange& range );
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearRange::constructor.Value() ) )
    {
        auto          linear_range   = Napi::ObjectWrap< GLinearRange >::Unwrap( info[ 0 ].As< Napi::Object >() );
        MPConstraint* pMPConstraint  = pMPSolver->MakeRowConstraint( *linear_range->pLinearRange );
        auto          gmp_constraint = Napi::External< MPConstraint >::New( info.Env(), pMPConstraint );
        return GMPConstraint::constructor.New( { gmp_constraint } );
    }

    // MPConstraint* MakeRowConstraint( const LinearRange& range, const std::string& name );
    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearRange::constructor.Value() )
         && info[ 1 ].IsString() )
    {
        auto          linear_range   = Napi::ObjectWrap< GLinearRange >::Unwrap( info[ 0 ].As< Napi::Object >() );
        std::string   name           = info[ 1 ].As< Napi::String >();
        MPConstraint* pMPConstraint  = pMPSolver->MakeRowConstraint( *linear_range->pLinearRange, name );
        auto          gmp_constraint = Napi::External< MPConstraint >::New( info.Env(), pMPConstraint );
        return GMPConstraint::constructor.New( { gmp_constraint } );
    }

    ThrowJsError( operations_research::GMPSolver::MakeRowConstraint : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::MutableObjective( const Napi::CallbackInfo& info )
{
    // MPObjective* MutableObjective();

    if ( info.Length() == 0 )
    {
        MPObjective* pMPObjective  = pMPSolver->MutableObjective();
        auto         gmp_objective = Napi::External< MPObjective >::New( info.Env(), pMPObjective );
        return GMPObjective::constructor.New( { gmp_objective } );
    }

    ThrowJsError( operations_research::GMPSolver::MutableObjective : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::Solve( const Napi::CallbackInfo& info )
{
    // ResultStatus Solve();
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), pMPSolver->Solve() );
    }

    // ResultStatus Solve( const MPSolverParameters& param );
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GMPSolverParameters::constructor.Value() ) )
    {
        auto mp_solver_parameters = Napi::ObjectWrap< GMPSolverParameters >::Unwrap( info[ 0 ].As< Napi::Object >() );
        auto status               = pMPSolver->Solve( *mp_solver_parameters->pMPSolverParameters );
        return Napi::Number::New( info.Env(), status );
    }

    ThrowJsError( operations_research::GMPSolver::Solve : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::IsMIP( const Napi::CallbackInfo& info )
{
    // bool IsMIP() const;
    if ( info.Length() == 0 )
    {
        return Napi::Boolean::New( info.Env(), pMPSolver->IsMIP() );
    }

    ThrowJsError( operations_research::GMPSolver::IsMIP : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::Name( const Napi::CallbackInfo& info )
{
    // const std::string& Name() const;
    if ( info.Length() == 0 )
    {
        return Napi::String::New( info.Env(), pMPSolver->Name() );
    }

    ThrowJsError( operations_research::GMPSolver::Name : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::ProblemType( const Napi::CallbackInfo& info )
{
    // virtual OptimizationProblemType ProblemType() const;
    if ( info.Length() == 0 )
    {
        using OptimizationProblemType = MPSolver::OptimizationProblemType;
        return Napi::Number::New( info.Env(), static_cast< int >( pMPSolver->ProblemType() ) );
    }

    ThrowJsError( operations_research::GMPSolver::ProblemType : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::Clear( const Napi::CallbackInfo& info )
{
    // void Clear();
    if ( info.Length() == 0 )
    {
        pMPSolver->Clear();
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPSolver::Clear : Invalid argument );

    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::NumVariables( const Napi::CallbackInfo& info )
{
    // int NumVariables() const;
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), pMPSolver->NumVariables() );
    }

    ThrowJsError( operations_research::GMPSolver::NumVariables : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::variables( const Napi::CallbackInfo& info )
{
    //  const std::vector< MPVariable* >& variables() const;
    if ( info.Length() == 0 )
    {
        auto gmp_variables = Napi::Array::New( info.Env(), pMPSolver->variables().size() );
        for ( int i = 0; i < pMPSolver->variables().size(); i++ )
        {
            auto gmp_variable = Napi::External< MPVariable >::New( info.Env(), pMPSolver->variables()[ i ] );
            gmp_variables.Set( i, GMPVariable::constructor.New( { gmp_variable } ) );
        }
        return gmp_variables;
    }

    ThrowJsError( operations_research::GMPSolver::variables : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::variable( const Napi::CallbackInfo& info )
{
    // MPVariable* variable( int index ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        int         index        = info[ 0 ].As< Napi::Number >();
        MPVariable* pMPVariable  = pMPSolver->variable( index );
        auto        gmp_variable = Napi::External< MPVariable >::New( info.Env(), pMPVariable );
        return GMPVariable::constructor.New( { gmp_variable } );
    }

    ThrowJsError( operations_research::GMPSolver::variable : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::LookupVariableOrNull( const Napi::CallbackInfo& info )
{
    //  MPVariable* LookupVariableOrNull( const std::string& var_name ) const;
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string var_name    = info[ 0 ].As< Napi::String >();
        MPVariable* pMPVariable = pMPSolver->LookupVariableOrNull( var_name );
        if ( pMPVariable == nullptr ) return info.Env().Null();
        auto gmp_variable = Napi::External< MPVariable >::New( info.Env(), pMPVariable );
        return GMPVariable::constructor.New( { gmp_variable } );
    }

    ThrowJsError( operations_research::GMPSolver::LookupVariableOrNull : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::MakeVar( const Napi::CallbackInfo& info )
{
    // MPVariable* MakeVar( double lb, double ub, bool integer, const std::string& name );
    if ( info.Length() == 4 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsBoolean() && info[ 3 ].IsString() )
    {
        double      lb           = info[ 0 ].As< Napi::Number >();
        double      ub           = info[ 1 ].As< Napi::Number >();
        bool        integer      = info[ 2 ].As< Napi::Boolean >();
        std::string name         = info[ 3 ].As< Napi::String >();
        MPVariable* pMPVariable  = pMPSolver->MakeVar( lb, ub, integer, name );
        auto        gmp_variable = Napi::External< MPVariable >::New( info.Env(), pMPVariable );
        return GMPVariable::constructor.New( { gmp_variable } );
    }

    ThrowJsError( operations_research::GMPSolver::MakeVar : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::MakeNumVar( const Napi::CallbackInfo& info )
{
    // MPVariable* MakeNumVar( double lb, double ub, const std::string& name );
    if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
    {
        double      lb           = info[ 0 ].As< Napi::Number >();
        double      ub           = info[ 1 ].As< Napi::Number >();
        std::string name         = info[ 2 ].As< Napi::String >();
        MPVariable* pMPVariable  = pMPSolver->MakeNumVar( lb, ub, name );
        auto        gmp_variable = Napi::External< MPVariable >::New( info.Env(), pMPVariable );
        return GMPVariable::constructor.New( { gmp_variable } );
    }

    ThrowJsError( operations_research::GMPSolver::MakeNumVar : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::MakeIntVar( const Napi::CallbackInfo& info )
{
    // MPVariable* MakeIntVar( double lb, double ub, const std::string& name );
    if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
    {
        double      lb           = info[ 0 ].As< Napi::Number >();
        double      ub           = info[ 1 ].As< Napi::Number >();
        std::string name         = info[ 2 ].As< Napi::String >();
        MPVariable* pMPVariable  = pMPSolver->MakeIntVar( lb, ub, name );
        auto        gmp_variable = Napi::External< MPVariable >::New( info.Env(), pMPVariable );
        return GMPVariable::constructor.New( { gmp_variable } );
    }

    ThrowJsError( operations_research::GMPSolver::MakeIntVar : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::MakeVarArray( const Napi::CallbackInfo& info )
{
    // void MakeVarArray( int nb, double lb, double ub, bool integer,  const std::string& name_prefix, std::vector< MPVariable* >* vars );
    if ( info.Length() == 5
         && info[ 0 ].IsNumber()
         && info[ 1 ].IsNumber()
         && info[ 2 ].IsNumber()
         && info[ 3 ].IsBoolean()
         && info[ 4 ].IsString() )
    {
        int                         nb          = info[ 0 ].As< Napi::Number >();
        double                      lb          = info[ 1 ].As< Napi::Number >();
        double                      ub          = info[ 2 ].As< Napi::Number >();
        bool                        integer     = info[ 3 ].As< Napi::Boolean >();
        std::string                 name_prefix = info[ 4 ].As< Napi::String >();
        std::vector< MPVariable* >* vars        = new std::vector< MPVariable* >();
        pMPSolver->MakeVarArray( nb, lb, ub, integer, name_prefix, vars );
        auto gmp_variables = Napi::Array::New( info.Env(), vars->size() );
        for ( int i = 0; i < vars->size(); i++ )
        {
            auto gmp_variable = Napi::External< MPVariable >::New( info.Env(), vars->at( i ) );
            gmp_variables.Set( i, GMPVariable::constructor.New( { gmp_variable } ) );
        }
        return gmp_variables;
    }

    ThrowJsError( operations_research::GMPSolver::MakeVarArray : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::MakeNumVarArray( const Napi::CallbackInfo& info )
{
    // void MakeNumVarArray( int nb, double lb, double ub, const std::string& name, std::vector< MPVariable* >* vars );
    if ( info.Length() == 4
         && info[ 0 ].IsNumber()
         && info[ 1 ].IsNumber()
         && info[ 2 ].IsNumber()
         && info[ 3 ].IsString() )
    {
        int                         nb   = info[ 0 ].As< Napi::Number >();
        double                      lb   = info[ 1 ].As< Napi::Number >();
        double                      ub   = info[ 2 ].As< Napi::Number >();
        std::string                 name = info[ 3 ].As< Napi::String >();
        std::vector< MPVariable* >* vars = new std::vector< MPVariable* >();
        pMPSolver->MakeNumVarArray( nb, lb, ub, name, vars );
        auto gmp_variables = Napi::Array::New( info.Env(), vars->size() );
        for ( int i = 0; i < vars->size(); i++ )
        {
            auto gmp_variable = Napi::External< MPVariable >::New( info.Env(), vars->at( i ) );
            gmp_variables.Set( i, GMPVariable::constructor.New( { gmp_variable } ) );
        }
        return gmp_variables;
    }

    ThrowJsError( operations_research::GMPSolver::MakeNumVarArray : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::MakeIntVarArray( const Napi::CallbackInfo& info )
{
    // void MakeIntVarArray( int nb, double lb, double ub, const std::string& name, std::vector< MPVariable* >* vars );
    if ( info.Length() == 4
         && info[ 0 ].IsNumber()
         && info[ 1 ].IsNumber()
         && info[ 2 ].IsNumber()
         && info[ 3 ].IsString() )
    {
        int                         nb   = info[ 0 ].As< Napi::Number >();
        double                      lb   = info[ 1 ].As< Napi::Number >();
        double                      ub   = info[ 2 ].As< Napi::Number >();
        std::string                 name = info[ 3 ].As< Napi::String >();
        std::vector< MPVariable* >* vars = new std::vector< MPVariable* >();
        pMPSolver->MakeIntVarArray( nb, lb, ub, name, vars );
        auto gmp_variables = Napi::Array::New( info.Env(), vars->size() );
        for ( int i = 0; i < vars->size(); i++ )
        {
            auto gmp_variable = Napi::External< MPVariable >::New( info.Env(), vars->at( i ) );
            gmp_variables.Set( i, GMPVariable::constructor.New( { gmp_variable } ) );
        }
        return gmp_variables;
    }

    ThrowJsError( operations_research::GMPSolver::MakeIntVarArray : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::MakeBoolVarArray( const Napi::CallbackInfo& info )
{
    // void MakeBoolVarArray( int nb, const std::string& name, std::vector< MPVariable* >* vars );
    if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsString() )
    {
        int                         nb   = info[ 0 ].As< Napi::Number >();
        std::string                 name = info[ 1 ].As< Napi::String >();
        std::vector< MPVariable* >* vars = new std::vector< MPVariable* >();
        pMPSolver->MakeBoolVarArray( nb, name, vars );
        auto gmp_variables = Napi::Array::New( info.Env(), vars->size() );
        for ( int i = 0; i < vars->size(); i++ )
        {
            auto gmp_variable = Napi::External< MPVariable >::New( info.Env(), vars->at( i ) );
            gmp_variables.Set( i, GMPVariable::constructor.New( { gmp_variable } ) );
        }
        return gmp_variables;
    }

    ThrowJsError( operations_research::GMPSolver::MakeBoolVarArray : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::NumConstraints( const Napi::CallbackInfo& info )
{
    // int NumConstraints() const;
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), pMPSolver->NumConstraints() );
    }

    ThrowJsError( operations_research::GMPSolver::NumConstraints : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::constraints( const Napi::CallbackInfo& info )
{
    // const std::vector< MPConstraint* >& constraints() const;
    if ( info.Length() == 0 )
    {
        auto constraints     = pMPSolver->constraints();
        auto gmp_constraints = Napi::Array::New( info.Env(), constraints.size() );
        for ( int i = 0; i < constraints.size(); i++ )
        {
            auto gmp_constraint = Napi::External< MPConstraint >::New( info.Env(), constraints[ i ] );
            gmp_constraints.Set( i, GMPConstraint::constructor.New( { gmp_constraint } ) );
        }
        return gmp_constraints;
    }

    ThrowJsError( operations_research::GMPSolver::constraints : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::constraint( const Napi::CallbackInfo& info )
{
    //  MPConstraint* constraint( int index ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        int           index          = info[ 0 ].As< Napi::Number >();
        MPConstraint* pMPConstraint  = pMPSolver->constraint( index );
        auto          gmp_constraint = Napi::External< MPConstraint >::New( info.Env(), pMPConstraint );
        return GMPConstraint::constructor.New( { gmp_constraint } );
    }

    ThrowJsError( operations_research::GMPSolver::constraint : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::LookupConstraintOrNull( const Napi::CallbackInfo& info )
{
    // MPConstraint* LookupConstraintOrNull( const std::string& constraint_name ) const;
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string   constraint_name = info[ 0 ].As< Napi::String >();
        MPConstraint* pMPConstraint   = pMPSolver->LookupConstraintOrNull( constraint_name );
        if ( pMPConstraint == nullptr ) return info.Env().Null();
        auto gmp_constraint = Napi::External< MPConstraint >::New( info.Env(), pMPConstraint );
        return GMPConstraint::constructor.New( { gmp_constraint } );
    }

    ThrowJsError( operations_research::GMPSolver::LookupConstraintOrNull : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::Objective( const Napi::CallbackInfo& info )
{
    // const MPObjective& Objective() const;
    if ( info.Length() == 0 )
    {
        const MPObjective& objective     = pMPSolver->Objective();
        auto               gmp_objective = Napi::External< MPObjective >::New( info.Env(), const_cast< MPObjective* >( &objective ) );
        return GMPObjective::constructor.New( { gmp_objective } );
    }

    ThrowJsError( operations_research::GMPSolver::Objective : Invalid argument );
    return info.Env().Undefined();
}

operations_research::GMPVariable::GMPVariable( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< operations_research::GMPVariable >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< MPVariable > >();
        pMPVariable   = dynamic_cast< MPVariable* >( external.Data() );
        if ( pMPVariable != nullptr ) return;
    }

    ThrowJsError( operations_research::GMPVariable::GMPVariable : Invalid argument );
}

operations_research::GMPVariable::~GMPVariable()
{
    delete pMPVariable;
}

operations_research::GLinearExpr::GLinearExpr( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< operations_research::GLinearExpr >( info )
{
    //     LinearExpr();
    if ( info.Length() == 0 )
    {
        pLinearExpr = new LinearExpr();
        return;
    }

    //     LinearExpr( double constant );  // NOLINT
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        double constant = info[ 0 ].As< Napi::Number >();
        pLinearExpr     = new LinearExpr( constant );
        return;
    }

    //     LinearExpr( const MPVariable* var );  // NOLINT
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        auto mp_variable = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 0 ].As< Napi::Object >() );
        pLinearExpr      = new LinearExpr( mp_variable->pMPVariable );
        return;
    }

    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< LinearExpr > >();
        pLinearExpr   = dynamic_cast< LinearExpr* >( external.Data() );
        if ( pLinearExpr != nullptr ) return;
    }

    ThrowJsError( operations_research::GLinearExpr::GLinearExpr : Invalid argument );
}

operations_research::GLinearExpr::~GLinearExpr()
{
    delete pLinearExpr;
}

Napi::Value operations_research::GLinearExpr::operator_plus_equals( const Napi::CallbackInfo& info )
{
    //     LinearExpr& operator+=( const LinearExpr& rhs );
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        auto linear_expr = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
        *pLinearExpr += *linear_expr->pLinearExpr;
        return info.This();
    }

    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        double constant = info[ 0 ].As< Napi::Number >();
        *pLinearExpr += constant;
        return info.This();
    }

    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        auto mp_variable = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 0 ].As< Napi::Object >() );
        *pLinearExpr += mp_variable->pMPVariable;
        return info.This();
    }

    ThrowJsError( operations_research::GLinearExpr::operator_plus_equals : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GLinearExpr::operator_minus_equals( const Napi::CallbackInfo& info )
{
    //     LinearExpr& operator-=( const LinearExpr& rhs );
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        auto linear_expr = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
        *pLinearExpr -= *linear_expr->pLinearExpr;
        return info.This();
    }

    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        double constant = info[ 0 ].As< Napi::Number >();
        *pLinearExpr -= constant;
        return info.This();
    }

    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        auto mp_variable = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 0 ].As< Napi::Object >() );
        *pLinearExpr -= mp_variable->pMPVariable;
        return info.This();
    }

    ThrowJsError( operations_research::GLinearExpr::operator_minus_equals : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GLinearExpr::operator_times_equals( const Napi::CallbackInfo& info )
{
    //     LinearExpr& operator*=( double rhs );
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        double rhs = info[ 0 ].As< Napi::Number >();
        *pLinearExpr *= rhs;
        return info.This();
    }

    ThrowJsError( operations_research::GLinearExpr::operator_times_equals : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GLinearExpr::operator_divide_equals( const Napi::CallbackInfo& info )
{
    //     LinearExpr& operator/=( double rhs );
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        double rhs = info[ 0 ].As< Napi::Number >();
        *pLinearExpr /= rhs;
        return info.This();
    }

    ThrowJsError( operations_research::GLinearExpr::operator_divide_equals : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GLinearExpr::operator_negate( const Napi::CallbackInfo& info )
{
    //     LinearExpr  operator-() const;
    if ( info.Length() == 0 )
    {
        LinearExpr* pLinearExpr_copy = new LinearExpr( -*pLinearExpr );
        auto        gmp_linear_expr  = Napi::External< LinearExpr >::New( info.Env(), pLinearExpr_copy );
        return GLinearExpr::constructor.New( { gmp_linear_expr } );
    }

    ThrowJsError( operations_research::GLinearExpr::operator_negate : Invalid argument );
    return info.Env().Undefined();
}

operations_research::GLinearRange::GLinearRange( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< operations_research::GLinearRange >( info )
{
    // LinearRange() : lower_bound_( 0 ), upper_bound_( 0 ) {}
    if ( info.Length() == 0 )
    {
        pLinearRange = new LinearRange();
        return;
    }

    //     LinearRange( double lower_bound, const LinearExpr& linear_expr, double upper_bound );
    if ( info.Length() == 3
         && info[ 0 ].IsNumber()
         && info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() )
         && info[ 2 ].IsNumber() )
    {
        double lower_bound = info[ 0 ].As< Napi::Number >();
        auto   linear_expr = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() );
        double upper_bound = info[ 2 ].As< Napi::Number >();
        pLinearRange       = new LinearRange( lower_bound, *linear_expr->pLinearExpr, upper_bound );
        return;
    }

    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< LinearRange > >();
        pLinearRange  = dynamic_cast< LinearRange* >( external.Data() );
        if ( pLinearRange != nullptr ) return;
    }

    ThrowJsError( operations_research::GLinearRange::GLinearRange : Invalid argument );
}

operations_research::GLinearRange::~GLinearRange()
{
    delete pLinearRange;
}

Napi::Value operations_research::operator_less_equals( const Napi::CallbackInfo& info )
{
    // LinearRange operator<=( const LinearExpr& lhs, const LinearExpr& rhs );
    if ( info.Length() != 2 )
    {
        ThrowJsError( operations_research::operator_less_equals : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr lhsLinearExpr;

    if ( info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        lhsLinearExpr = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 0 ].IsNumber() )
    {
        lhsLinearExpr = LinearExpr( info[ 0 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 0 ].IsObject()
              && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        lhsLinearExpr = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 0 ].As< Napi::Object >() )->pMPVariable;
    }
    else
    {
        ThrowJsError( operations_research::operator_less_equals : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr rhsLinearExpr;

    if ( info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        rhsLinearExpr = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 1 ].IsNumber() )
    {
        rhsLinearExpr = LinearExpr( info[ 1 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 1 ].IsObject()
              && info[ 1 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        rhsLinearExpr = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 1 ].As< Napi::Object >() )->pMPVariable;
    }
    else
    {
        ThrowJsError( operations_research::operator_less_equals : Invalid argument );
        return info.Env().Undefined();
    }

    auto pLinearRange = new LinearRange( lhsLinearExpr <= rhsLinearExpr );
    auto external     = Napi::External< LinearRange >::New( info.Env(), pLinearRange );
    return GLinearRange::constructor.New( { external } );
}

Napi::Value operations_research::operator_equals( const Napi::CallbackInfo& info )
{
    // LinearRange operator==( const LinearExpr& lhs, const LinearExpr& rhs );
    if ( info.Length() != 2 )
    {
        ThrowJsError( operations_research::operator_equals : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr lhsLinearExpr;

    if ( info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        lhsLinearExpr = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 0 ].IsNumber() )
    {
        lhsLinearExpr = LinearExpr( info[ 0 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 0 ].IsObject()
              && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        lhsLinearExpr = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 0 ].As< Napi::Object >() )->pMPVariable;
    }
    else
    {
        ThrowJsError( operations_research::operator_equals : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr rhsLinearExpr;

    if ( info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        rhsLinearExpr = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 1 ].IsNumber() )
    {
        rhsLinearExpr = LinearExpr( info[ 1 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 1 ].IsObject()
              && info[ 1 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        rhsLinearExpr = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 1 ].As< Napi::Object >() )->pMPVariable;
    }
    else
    {
        ThrowJsError( operations_research::operator_equals : Invalid argument );
        return info.Env().Undefined();
    }

    auto pLinearRange = new LinearRange( lhsLinearExpr == rhsLinearExpr );
    auto external     = Napi::External< LinearRange >::New( info.Env(), pLinearRange );
    return GLinearRange::constructor.New( { external } );
}

Napi::Value operations_research::operator_greater_equals( const Napi::CallbackInfo& info )
{
    // LinearRange operator>=( const LinearExpr& lhs, const LinearExpr& rhs );
    if ( info.Length() != 2 )
    {
        ThrowJsError( operations_research::operator_greater_equals : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr lhsLinearExpr;

    if ( info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        lhsLinearExpr = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 0 ].IsNumber() )
    {
        lhsLinearExpr = LinearExpr( info[ 0 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 0 ].IsObject()
              && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        lhsLinearExpr = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 0 ].As< Napi::Object >() )->pMPVariable;
    }
    else
    {
        ThrowJsError( operations_research::operator_greater_equals : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr rhsLinearExpr;

    if ( info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        rhsLinearExpr = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 1 ].IsNumber() )
    {
        rhsLinearExpr = LinearExpr( info[ 1 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 1 ].IsObject()
              && info[ 1 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        rhsLinearExpr = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 1 ].As< Napi::Object >() )->pMPVariable;
    }
    else
    {
        ThrowJsError( operations_research::operator_greater_equals : Invalid argument );
        return info.Env().Undefined();
    }

    auto pLinearRange = new LinearRange( lhsLinearExpr >= rhsLinearExpr );
    auto external     = Napi::External< LinearRange >::New( info.Env(), pLinearRange );
    return GLinearRange::constructor.New( { external } );
}

operations_research::GMPConstraint::GMPConstraint( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< operations_research::GMPConstraint >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< MPConstraint > >();
        pMPConstraint = dynamic_cast< MPConstraint* >( external.Data() );
        if ( pMPConstraint != nullptr ) return;
    }

    ThrowJsError( operations_research::GMPConstraint::GMPConstraint : Invalid argument );
}

operations_research::GMPConstraint::~GMPConstraint()
{
    delete pMPConstraint;
}

Napi::Value operations_research::GMPConstraint::SetCoefficient( const Napi::CallbackInfo& info )
{
    // void SetCoefficient( const MPVariable* const var, double coeff );
    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() )
         && info[ 1 ].IsNumber() )
    {
        auto   mp_variable = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 0 ].As< Napi::Object >() );
        double coeff       = info[ 1 ].As< Napi::Number >().DoubleValue();
        pMPConstraint->SetCoefficient( mp_variable->pMPVariable, coeff );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPConstraint::SetCoefficient : Invalid argument );
    return info.Env().Undefined();
}

operations_research::GMPObjective::GMPObjective( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< operations_research::GMPObjective >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< MPObjective > >();
        pMPObjective  = dynamic_cast< MPObjective* >( external.Data() );
        if ( pMPObjective != nullptr ) return;
    }

    ThrowJsError( operations_research::GMPObjective::GMPObjective : Invalid argument );
}

operations_research::GMPObjective::~GMPObjective()
{
    delete pMPObjective;
}

Napi::Value operations_research::GMPObjective::SetCoefficient( const Napi::CallbackInfo& info )
{
    //     void SetCoefficient( const MPVariable* const var, double coeff );
    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() )
         && info[ 1 ].IsNumber() )
    {
        auto   mp_variable = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 0 ].As< Napi::Object >() );
        double coeff       = info[ 1 ].As< Napi::Number >().DoubleValue();
        pMPObjective->SetCoefficient( mp_variable->pMPVariable, coeff );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPObjective::SetCoefficient : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPObjective::SetMinimization( const Napi::CallbackInfo& info )
{
    // void SetMinimization();
    if ( info.Length() == 0 )
    {
        pMPObjective->SetMinimization();
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPObjective::SetMaximization : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPObjective::Value( const Napi::CallbackInfo& info )
{
    // double Value() const;
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), pMPObjective->Value() );
    }

    ThrowJsError( operations_research::GMPObjective::Value : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPObjective::Clear( const Napi::CallbackInfo& info )
{
    // void Clear();
    if ( info.Length() == 0 )
    {
        pMPObjective->Clear();
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPObjective::Clear : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPObjective::GetCoefficient( const Napi::CallbackInfo& info )
{
    // double GetCoefficient( const MPVariable* const var ) const;
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        auto mp_variable = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 0 ].As< Napi::Object >() );
        return Napi::Number::New( info.Env(), pMPObjective->GetCoefficient( mp_variable->pMPVariable ) );
    }

    ThrowJsError( operations_research::GMPObjective::GetCoefficient : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPObjective::terms( const Napi::CallbackInfo& info )
{
    // const absl::flat_hash_map< const MPVariable*, double >& terms() const;
    if ( info.Length() == 0 )
    {
        auto terms = pMPObjective->terms();
        auto obj   = Napi::Object::New( info.Env() );
        for ( auto it = terms.begin(); it != terms.end(); it++ )
        {
            auto mp_variable = it->first;
            auto coeff       = it->second;
            auto external    = Napi::External< MPVariable >::New( info.Env(), ( MPVariable* )mp_variable );
            auto variable    = GMPVariable::constructor.New( { external } );
            obj.Set( variable, Napi::Number::New( info.Env(), coeff ) );
        }
        return obj;
    }

    ThrowJsError( operations_research::GMPObjective::terms : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPObjective::SetOffset( const Napi::CallbackInfo& info )
{
    // void SetOffset( double value );
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        double value = info[ 0 ].As< Napi::Number >().DoubleValue();
        pMPObjective->SetOffset( value );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPObjective::SetOffset : Invalid argument );
    return info.Env().Undefined();
}

operations_research::sat::GCpModelBuilder::GCpModelBuilder( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< operations_research::sat::GCpModelBuilder >( info )
{
    if ( info.Length() == 0 )
    {
        pCpModelBuilder = new CpModelBuilder();
        return;
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::GCpModelBuilder : Invalid argument );
}

operations_research::sat::GCpModelBuilder::~GCpModelBuilder()
{
    delete pCpModelBuilder;
}

Napi::Value operations_research::sat::GCpModelBuilder::NewBoolVar( const Napi::CallbackInfo& info )
{
    // BoolVar NewBoolVar();
    if ( info.Length() == 0 )
    {
        auto pBoolVar = pCpModelBuilder->NewBoolVar();
        auto external = Napi::External< BoolVar >::New( info.Env(), new BoolVar( pBoolVar ) );
        return GBoolVar::constructor.New( { external } );
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::NewBoolVar : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GCpModelBuilder::AddAtMostOne( const Napi::CallbackInfo& info )
{
    // Constraint AddAtMostOne( absl::Span< const BoolVar > literals );
    if ( info.Length() == 1 && info[ 0 ].IsArray() )
    {
        std::vector< BoolVar > literals;
        auto                   array = info[ 0 ].As< Napi::Array >();
        for ( int i = 0; i < array.Length(); i++ )
        {
            if ( array.Get( i ).IsObject()
                 && array.Get( i ).As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
            {
                literals.push_back( *Napi::ObjectWrap< GBoolVar >::Unwrap( array.Get( i ).As< Napi::Object >() )->pBoolVar );
            }
            else
            {
                ThrowJsError( operations_research::sat::GCpModelBuilder::AddAtMostOne : Invalid argument );
                return info.Env().Undefined();
            }
        }
        auto pConstraint = pCpModelBuilder->AddAtMostOne( literals );
        auto external    = Napi::External< Constraint >::New( info.Env(), new Constraint( pConstraint ) );
        return GConstraint::constructor.New( { external } );
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::AddAtMostOne : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GCpModelBuilder::AddExactlyOne( const Napi::CallbackInfo& info )
{
    // Constraint AddExactlyOne( absl::Span< const BoolVar > literals );
    if ( info.Length() == 1 && info[ 0 ].IsArray() )
    {
        std::vector< BoolVar > literals;
        auto                   array = info[ 0 ].As< Napi::Array >();
        for ( int i = 0; i < array.Length(); i++ )
        {
            if ( array.Get( i ).IsObject()
                 && array.Get( i ).As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
            {
                literals.push_back( *Napi::ObjectWrap< GBoolVar >::Unwrap( array.Get( i ).As< Napi::Object >() )->pBoolVar );
            }
            else
            {
                ThrowJsError( operations_research::sat::GCpModelBuilder::AddExactlyOne : Invalid argument );
                return info.Env().Undefined();
            }
        }
        auto pConstraint = pCpModelBuilder->AddExactlyOne( literals );
        auto external    = Napi::External< Constraint >::New( info.Env(), new Constraint( pConstraint ) );
        return GConstraint::constructor.New( { external } );
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::AddExactlyOne : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GCpModelBuilder::AddEquality( const Napi::CallbackInfo& info )
{
    // Constraint AddEquality( const LinearExpr& left, const LinearExpr& right );
    if ( info.Length() != 2 )
    {
        ThrowJsError( operations_research::sat::GCpModelBuilder::AddEquality : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr LinearExpr_left;

    if ( info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        LinearExpr_left = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 0 ].IsNumber() )
    {
        LinearExpr_left = LinearExpr( info[ 0 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 0 ].IsObject()
              && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        LinearExpr_left = LinearExpr( *Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 0 ].As< Napi::Object >() )->pBoolVar );
    }
    else if ( info[ 0 ].IsObject()
              && info[ 0 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
    {
        LinearExpr_left = LinearExpr( *Napi::ObjectWrap< GIntVar >::Unwrap( info[ 0 ].As< Napi::Object >() )->pIntVar );
    }
    else
    {
        ThrowJsError( operations_research::sat::GCpModelBuilder::AddEquality : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr LinearExpr_right;

    if ( info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        LinearExpr_right = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 1 ].IsNumber() )
    {
        LinearExpr_right = LinearExpr( info[ 1 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 1 ].IsObject()
              && info[ 1 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        LinearExpr_right = LinearExpr( *Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 1 ].As< Napi::Object >() )->pBoolVar );
    }
    else if ( info[ 1 ].IsObject()
              && info[ 1 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
    {
        LinearExpr_right = LinearExpr( *Napi::ObjectWrap< GIntVar >::Unwrap( info[ 1 ].As< Napi::Object >() )->pIntVar );
    }
    else
    {
        ThrowJsError( operations_research::sat::GCpModelBuilder::AddEquality : Invalid argument );
        return info.Env().Undefined();
    }

    auto pConstraint = pCpModelBuilder->AddEquality( LinearExpr_left, LinearExpr_right );
    auto external    = Napi::External< Constraint >::New( info.Env(), new Constraint( pConstraint ) );
    return GConstraint::constructor.New( { external } );
}

Napi::Value operations_research::sat::GCpModelBuilder::AddAllowedAssignments( const Napi::CallbackInfo& info )
{
    //   TableConstraint AddAllowedAssignments( absl::Span< const IntVar > vars );
    if ( info.Length() == 1 && info[ 0 ].IsArray() )
    {
        std::vector< IntVar > vars;
        auto                  array = info[ 0 ].As< Napi::Array >();
        for ( int i = 0; i < array.Length(); i++ )
        {
            if ( array.Get( i ).IsObject()
                 && array.Get( i ).As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
            {
                vars.push_back( *Napi::ObjectWrap< GIntVar >::Unwrap( array.Get( i ).As< Napi::Object >() )->pIntVar );
            }
            else
            {
                ThrowJsError( operations_research::sat::GCpModelBuilder::AddAllowedAssignments : Invalid argument );
                return info.Env().Undefined();
            }
        }

        auto pTableConstraint = pCpModelBuilder->AddAllowedAssignments( vars );
        auto external         = Napi::External< TableConstraint >::New( info.Env(), new TableConstraint( pTableConstraint ) );
        return GTableConstraint::constructor.New( { external } );
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::AddAllowedAssignments : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GCpModelBuilder::Minimize( const Napi::CallbackInfo& info )
{
    // void Minimize( const LinearExpr& expr );
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        auto linear_expr = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
        pCpModelBuilder->Minimize( *linear_expr->pLinearExpr );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::Minimize : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GCpModelBuilder::Build( const Napi::CallbackInfo& info )
{
    // const CpModelProto& Build() const
    if ( info.Length() == 0 )
    {
        auto pCpModelProto = pCpModelBuilder->Build();
        auto external      = Napi::External< CpModelProto >::New( info.Env(), new CpModelProto( pCpModelProto ) );
        return GCpModelProto::constructor.New( { external } );
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::Build : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GCpModelBuilder::NewIntVar( const Napi::CallbackInfo& info )
{
    // IntVar NewIntVar( const Domain& domain );
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GDomain::constructor.Value() ) )
    {
        auto domain   = Napi::ObjectWrap< GDomain >::Unwrap( info[ 0 ].As< Napi::Object >() );
        auto pIntVar  = pCpModelBuilder->NewIntVar( *domain->pDomain );
        auto external = Napi::External< IntVar >::New( info.Env(), new IntVar( pIntVar ) );
        return GIntVar::constructor.New( { external } );
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::NewIntVar : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GCpModelBuilder::AddLessOrEqual( const Napi::CallbackInfo& info )
{
    // Constraint AddLessOrEqual( const LinearExpr& left, const LinearExpr& right );
    if ( info.Length() != 2 )
    {
        ThrowJsError( operations_research::sat::GCpModelBuilder::AddLessOrEqual : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr LinearExpr_left;

    if ( info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        LinearExpr_left = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 0 ].IsNumber() )
    {
        LinearExpr_left = LinearExpr( info[ 0 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 0 ].IsObject()
              && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        LinearExpr_left = LinearExpr( *Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 0 ].As< Napi::Object >() )->pBoolVar );
    }
    else if ( info[ 0 ].IsObject()
              && info[ 0 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
    {
        LinearExpr_left = LinearExpr( *Napi::ObjectWrap< GIntVar >::Unwrap( info[ 0 ].As< Napi::Object >() )->pIntVar );
    }
    else
    {
        ThrowJsError( operations_research::sat::GCpModelBuilder::AddLessOrEqual : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr LinearExpr_right;

    if ( info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        LinearExpr_right = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 1 ].IsNumber() )
    {
        LinearExpr_right = LinearExpr( info[ 1 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 1 ].IsObject()
              && info[ 1 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        LinearExpr_right = LinearExpr( *Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 1 ].As< Napi::Object >() )->pBoolVar );
    }
    else if ( info[ 1 ].IsObject()
              && info[ 1 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
    {
        LinearExpr_right = LinearExpr( *Napi::ObjectWrap< GIntVar >::Unwrap( info[ 1 ].As< Napi::Object >() )->pIntVar );
    }
    else
    {
        ThrowJsError( operations_research::sat::GCpModelBuilder::AddLessOrEqual : Invalid argument );
        return info.Env().Undefined();
    }

    auto pConstraint = pCpModelBuilder->AddLessOrEqual( LinearExpr_left, LinearExpr_right );
    auto external    = Napi::External< Constraint >::New( info.Env(), new Constraint( pConstraint ) );
    return GConstraint::constructor.New( { external } );
}

Napi::Value operations_research::sat::GCpModelBuilder::Maximize( const Napi::CallbackInfo& info )
{
    // void Maximize( const LinearExpr& expr );
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        auto linear_expr = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
        pCpModelBuilder->Maximize( *linear_expr->pLinearExpr );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::sat::GCpModelBuilder::Maximize : Invalid argument );
    return info.Env().Undefined();
}

operations_research::sat::GBoolVar::GBoolVar( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< operations_research::sat::GBoolVar >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< BoolVar > >();
        pBoolVar      = dynamic_cast< BoolVar* >( external.Data() );
        if ( pBoolVar != nullptr ) return;
    }

    // BoolVar() = default;
    if ( info.Length() == 0 )
    {
        pBoolVar = new BoolVar();
        return;
    }

    ThrowJsError( operations_research::sat::GBoolVar : Invalid argument );
}

operations_research::sat::GBoolVar::~GBoolVar()
{
    delete pBoolVar;
}

Napi::Value operations_research::sat::GBoolVar::WithName( const Napi::CallbackInfo& info )
{
    // BoolVar WithName( const std::string& name )
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string name     = info[ 0 ].As< Napi::String >().Utf8Value();
        auto        boo      = pBoolVar->WithName( name );
        auto        external = Napi::External< BoolVar >::New( info.Env(), new BoolVar( boo ) );
        return GBoolVar::constructor.New( { external } );
    }

    ThrowJsError( operations_research::sat::GBoolVar::WithName : Invalid argument );
    return info.Env().Undefined();
}

operations_research::sat::GConstraint::GConstraint( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< operations_research::sat::GConstraint >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< Constraint > >();
        pConstraint   = dynamic_cast< Constraint* >( external.Data() );
        if ( pConstraint != nullptr ) return;
    }

    ThrowJsError( operations_research::sat::GConstraint : Invalid argument );
}

operations_research::sat::GConstraint::~GConstraint()
{
    delete pConstraint;
}

operations_research::sat::GIntVar::GIntVar( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< operations_research::sat::GIntVar >( info )
{
    // IntVar() = default;
    if ( info.Length() == 0 )
    {
        pIntVar = new IntVar();
        return;
    }

    // explicit IntVar( const BoolVar& var );
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        auto bool_var = Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 0 ].As< Napi::Object >() );
        pIntVar       = new IntVar( *bool_var->pBoolVar );
        return;
    }

    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< IntVar > >();
        pIntVar       = dynamic_cast< IntVar* >( external.Data() );
        if ( pIntVar != nullptr ) return;
    }

    ThrowJsError( operations_research::sat::GIntVar : Invalid argument );
}

operations_research::sat::GIntVar::~GIntVar()
{
    delete pIntVar;
}

operations_research::sat::GLinearExpr::GLinearExpr( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< operations_research::sat::GLinearExpr >( info )
{
    // LinearExpr() = default;
    if ( info.Length() == 0 )
    {
        pLinearExpr = new LinearExpr();
        return;
    }

    // LinearExpr( BoolVar var );
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        auto bool_var = Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 0 ].As< Napi::Object >() );
        pLinearExpr   = new LinearExpr( *bool_var->pBoolVar );
        return;
    }

    // LinearExpr( IntVar var );
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
    {
        auto int_var = Napi::ObjectWrap< GIntVar >::Unwrap( info[ 0 ].As< Napi::Object >() );
        pLinearExpr  = new LinearExpr( *int_var->pIntVar );
        return;
    }

    //  LinearExpr( int64_t constant );
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        int64_t constant = info[ 0 ].As< Napi::Number >().Int64Value();
        pLinearExpr      = new LinearExpr( constant );
        return;
    }

    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< LinearExpr > >();
        pLinearExpr   = dynamic_cast< LinearExpr* >( external.Data() );
        if ( pLinearExpr != nullptr ) return;
    }

    ThrowJsError( operations_research::sat::GLinearExpr : Invalid argument );
}

operations_research::sat::GLinearExpr::~GLinearExpr()
{
    delete pLinearExpr;
}

Napi::Value operations_research::sat::GLinearExpr::operator_plus_equals( const Napi::CallbackInfo& info )
{
    // LinearExpr& operator+=( const LinearExpr& other );
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        auto other = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
        *pLinearExpr += *other->pLinearExpr;
        return info.This();
    }

    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        int64_t constant = info[ 0 ].As< Napi::Number >().Int64Value();
        *pLinearExpr += constant;
        return info.This();
    }

    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        auto bool_var = Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 0 ].As< Napi::Object >() );
        *pLinearExpr += *bool_var->pBoolVar;
        return info.This();
    }

    ThrowJsError( operations_research::sat::GLinearExpr::operator_plus_equals : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GLinearExpr::operator_minus_equals( const Napi::CallbackInfo& info )
{
    // LinearExpr& operator-=( const LinearExpr& other );
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        auto other = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
        *pLinearExpr -= *other->pLinearExpr;
        return info.This();
    }

    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        int64_t constant = info[ 0 ].As< Napi::Number >().Int64Value();
        *pLinearExpr -= constant;
        return info.This();
    }

    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        auto bool_var = Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 0 ].As< Napi::Object >() );
        *pLinearExpr -= *bool_var->pBoolVar;
        return info.This();
    }

    ThrowJsError( operations_research::sat::GLinearExpr::operator_minus_equals : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GLinearExpr::operator_times_equals( const Napi::CallbackInfo& info )
{
    // LinearExpr& operator*=( int64_t factor );
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        int64_t factor = info[ 0 ].As< Napi::Number >().Int64Value();
        *pLinearExpr *= factor;
        return info.This();
    }

    ThrowJsError( operations_research::sat::GLinearExpr::operator_times_equals : Invalid argument );
    return info.Env().Undefined();
}

operations_research::sat::GTableConstraint::GTableConstraint( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< operations_research::sat::GTableConstraint >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external    = info[ 0 ].As< Napi::External< TableConstraint > >();
        pTableConstraint = dynamic_cast< TableConstraint* >( external.Data() );
        if ( pTableConstraint != nullptr ) return;
    }

    ThrowJsError( operations_research::sat::GTableConstraint : Invalid argument );
}

operations_research::sat::GTableConstraint::~GTableConstraint()
{
    delete pTableConstraint;
}

Napi::Value operations_research::sat::GTableConstraint::AddTuple( const Napi::CallbackInfo& info )
{
    // void AddTuple( absl::Span< const int64_t > tuple );
    if ( info.Length() == 1 && info[ 0 ].IsArray() )
    {
        std::vector< int64_t > tuple;
        auto                   array = info[ 0 ].As< Napi::Array >();
        for ( int i = 0; i < array.Length(); i++ )
        {
            if ( array.Get( i ).IsNumber() )
            {
                tuple.push_back( array.Get( i ).As< Napi::Number >().Int64Value() );
            }
            else
            {
                ThrowJsError( operations_research::sat::GTableConstraint::AddTuple : Invalid argument );
                return info.Env().Undefined();
            }
        }

        pTableConstraint->AddTuple( tuple );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::sat::GTableConstraint::AddTuple : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::Goperator_plus( const Napi::CallbackInfo& info )
{
    // inline LinearExpr operator+( const LinearExpr& lhs, const LinearExpr& rhs )
    if ( info.Length() != 2 )
    {
        ThrowJsError( operations_research::sat::operator_plus : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr lhsLinearExpr;

    if ( info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        lhsLinearExpr = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 0 ].IsNumber() )
    {
        lhsLinearExpr = LinearExpr( info[ 0 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 0 ].IsObject()
              && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        lhsLinearExpr = LinearExpr( *Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 0 ].As< Napi::Object >() )->pBoolVar );
    }
    else
    {
        ThrowJsError( operations_research::sat::operator_plus : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr rhsLinearExpr;
    if ( info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        rhsLinearExpr = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 1 ].IsNumber() )
    {
        rhsLinearExpr = LinearExpr( info[ 1 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 1 ].IsObject()
              && info[ 1 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        rhsLinearExpr = LinearExpr( *Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 1 ].As< Napi::Object >() )->pBoolVar );
    }
    else
    {
        ThrowJsError( operations_research::sat::operator_plus : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr result = lhsLinearExpr + rhsLinearExpr;
    return GLinearExpr::constructor.New( { Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) ) } );
}

Napi::Value operations_research::sat::Goperator_minus( const Napi::CallbackInfo& info )
{
    // inline LinearExpr operator-( const LinearExpr& lhs, const LinearExpr& rhs )
    if ( info.Length() != 2 )
    {
        ThrowJsError( operations_research::sat::operator_minus : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr lhsLinearExpr;

    if ( info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        lhsLinearExpr = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 0 ].IsNumber() )
    {
        lhsLinearExpr = LinearExpr( info[ 0 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 0 ].IsObject()
              && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        lhsLinearExpr = LinearExpr( *Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 0 ].As< Napi::Object >() )->pBoolVar );
    }
    else
    {
        ThrowJsError( operations_research::sat::operator_minus : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr rhsLinearExpr;
    if ( info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        rhsLinearExpr = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 1 ].IsNumber() )
    {
        rhsLinearExpr = LinearExpr( info[ 1 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 1 ].IsObject()
              && info[ 1 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        rhsLinearExpr = LinearExpr( *Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 1 ].As< Napi::Object >() )->pBoolVar );
    }
    else
    {
        ThrowJsError( operations_research::sat::operator_minus : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr result = lhsLinearExpr - rhsLinearExpr;
    return GLinearExpr::constructor.New( { Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) ) } );
}

Napi::Value operations_research::sat::Goperator_times( const Napi::CallbackInfo& info )
{
    if ( info.Length() != 2 )
    {
        ThrowJsError( operations_research::sat::operator_times : Invalid argument );
        return info.Env().Undefined();
    }

    // inline LinearExpr operator*( LinearExpr expr, int64_t factor )
    if ( ( info[ 0 ].IsObject() || info[ 0 ].IsNumber() ) && info[ 1 ].IsNumber() )
    {
        LinearExpr expr;
        if ( info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
        {
            expr = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() )->pLinearExpr;
        }
        else if ( info[ 0 ].IsNumber() )
        {
            expr = LinearExpr( info[ 0 ].As< Napi::Number >().DoubleValue() );
        }
        else if ( info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
        {
            expr = LinearExpr( *Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 0 ].As< Napi::Object >() )->pBoolVar );
        }
        else if ( info[ 0 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
        {
            expr = LinearExpr( *Napi::ObjectWrap< GIntVar >::Unwrap( info[ 0 ].As< Napi::Object >() )->pIntVar );
        }
        else
        {
            ThrowJsError( operations_research::sat::operator_times : Invalid argument );
            return info.Env().Undefined();
        }

        int64_t    factor = info[ 1 ].As< Napi::Number >().Int64Value();
        LinearExpr result = expr * factor;
        return GLinearExpr::constructor.New( { Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) ) } );
    }

    // inline LinearExpr operator*( int64_t factor, LinearExpr expr )
    if ( ( info[ 1 ].IsObject() || info[ 1 ].IsNumber() ) && info[ 0 ].IsNumber() )
    {
        LinearExpr expr;
        if ( info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
        {
            expr = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() )->pLinearExpr;
        }
        else if ( info[ 1 ].IsNumber() )
        {
            expr = LinearExpr( info[ 1 ].As< Napi::Number >().DoubleValue() );
        }
        else if ( info[ 1 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
        {
            expr = LinearExpr( *Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 1 ].As< Napi::Object >() )->pBoolVar );
        }
        else if ( info[ 1 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
        {
            expr = LinearExpr( *Napi::ObjectWrap< GIntVar >::Unwrap( info[ 1 ].As< Napi::Object >() )->pIntVar );
        }
        else
        {
            ThrowJsError( operations_research::sat::operator_times : Invalid argument );
            return info.Env().Undefined();
        }

        int64_t    factor = info[ 0 ].As< Napi::Number >().Int64Value();
        LinearExpr result = expr * factor;
        return GLinearExpr::constructor.New( { Napi::External< LinearExpr >::New( info.Env(), new LinearExpr( result ) ) } );
    }

    ThrowJsError( operations_research::sat::operator_times : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GSolve( const Napi::CallbackInfo& info )
{
    // CpSolverResponse Solve( const CpModelProto& model_proto );
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GCpModelProto::constructor.Value() ) )
    {
        auto             model_proto = Napi::ObjectWrap< GCpModelProto >::Unwrap( info[ 0 ].As< Napi::Object >() );
        CpModelProto*    pModelProto = model_proto->pCpModelProto;
        CpSolverResponse response    = Solve( *pModelProto );
        return GCpSolverResponse::constructor.New( { Napi::External< CpSolverResponse >::New( info.Env(), new CpSolverResponse( response ) ) } );
    }

    ThrowJsError( operations_research::sat::Solve : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GSolutionIntegerValue( const Napi::CallbackInfo& info )
{
    // int64_t SolutionIntegerValue( const CpSolverResponse& r, const LinearExpr& expr );
    if ( info.Length() != 2 )
    {
        ThrowJsError( operations_research::sat::SolutionIntegerValue : Invalid argument );
        return info.Env().Undefined();
    }

    if ( !info[ 0 ].IsObject()
         || !info[ 0 ].As< Napi::Object >().InstanceOf( GCpSolverResponse::constructor.Value() ) )
    {
        ThrowJsError( operations_research::sat::SolutionIntegerValue : Invalid argument );
        return info.Env().Undefined();
    }

    if ( !info[ 1 ].IsObject() )
    {
        ThrowJsError( operations_research::sat::SolutionIntegerValue : Invalid argument );
        return info.Env().Undefined();
    }

    if ( info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        auto linear_expr     = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() );
        auto expr            = *linear_expr->pLinearExpr;
        auto solver_response = Napi::ObjectWrap< GCpSolverResponse >::Unwrap( info[ 0 ].As< Napi::Object >() );
        return Napi::Number::New( info.Env(), SolutionIntegerValue( *solver_response->pCpSolverResponse, expr ) );
    }

    if ( info[ 1 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
    {
        auto int_var         = Napi::ObjectWrap< GIntVar >::Unwrap( info[ 1 ].As< Napi::Object >() );
        auto solver_response = Napi::ObjectWrap< GCpSolverResponse >::Unwrap( info[ 0 ].As< Napi::Object >() );
        return Napi::Number::New( info.Env(), SolutionIntegerValue( *solver_response->pCpSolverResponse, *int_var->pIntVar ) );
    }

    if ( info[ 1 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        auto bool_var        = Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 1 ].As< Napi::Object >() );
        auto solver_response = Napi::ObjectWrap< GCpSolverResponse >::Unwrap( info[ 0 ].As< Napi::Object >() );
        return Napi::Boolean::New( info.Env(), SolutionBooleanValue( *solver_response->pCpSolverResponse, *bool_var->pBoolVar ) );
    }

    ThrowJsError( operations_research::sat::SolutionIntegerValue : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GSolutionBooleanValue( const Napi::CallbackInfo& info )
{
    //  bool SolutionBooleanValue( const CpSolverResponse& r, const BoolVar& x );
    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GCpSolverResponse::constructor.Value() )
         && info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        auto solver_response = Napi::ObjectWrap< GCpSolverResponse >::Unwrap( info[ 0 ].As< Napi::Object >() );
        auto bool_var        = Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 1 ].As< Napi::Object >() );
        return Napi::Boolean::New( info.Env(), SolutionBooleanValue( *solver_response->pCpSolverResponse, *bool_var->pBoolVar ) );
    }

    ThrowJsError( operations_research::sat::SolutionBooleanValue : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GCpSolverResponse::objective_value( const Napi::CallbackInfo& info )
{
    // double objective_value() const;
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), pCpSolverResponse->objective_value() );
    }

    ThrowJsError( operations_research::sat::objective_value : Invalid argument );
    return info.Env().Undefined();
}

operations_research::sat::GCpModelProto::GCpModelProto( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< operations_research::sat::GCpModelProto >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< CpModelProto > >();
        pCpModelProto = dynamic_cast< CpModelProto* >( external.Data() );
        if ( pCpModelProto != nullptr ) return;
    }

    ThrowJsError( operations_research::sat::GCpModelProto : Invalid argument );
}

operations_research::sat::GCpModelProto::~GCpModelProto()
{
    delete pCpModelProto;
}

operations_research::sat::GCpSolverResponse::GCpSolverResponse( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< operations_research::sat::GCpSolverResponse >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external     = info[ 0 ].As< Napi::External< CpSolverResponse > >();
        pCpSolverResponse = dynamic_cast< CpSolverResponse* >( external.Data() );
        if ( pCpSolverResponse != nullptr ) return;
    }

    ThrowJsError( operations_research::sat::GCpSolverResponse : Invalid argument );
}

operations_research::sat::GCpSolverResponse::~GCpSolverResponse()
{
    delete pCpSolverResponse;
}

Napi::Value operations_research::sat::GCpSolverResponse::status( const Napi::CallbackInfo& info )
{
    // ::operations_research::sat::CpSolverStatus status() const;
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), pCpSolverResponse->status() );
    }

    ThrowJsError( operations_research::sat::GCpSolverResponse::status : Invalid argument );
    return info.Env().Undefined();
}

operations_research::GSimpleLinearSumAssignment::GSimpleLinearSumAssignment( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< operations_research::GSimpleLinearSumAssignment >( info )
{
    // SimpleLinearSumAssignment();
    if ( info.Length() == 0 )
    {
        pSimpleLinearSumAssignment = new operations_research::SimpleLinearSumAssignment();
        return;
    }

    ThrowJsError( operations_research::GSimpleLinearSumAssignment : Invalid argument );
}

operations_research::GSimpleLinearSumAssignment::~GSimpleLinearSumAssignment()
{
    delete pSimpleLinearSumAssignment;
}

Napi::Value operations_research::GSimpleLinearSumAssignment::AddArcWithCost( const Napi::CallbackInfo& info )
{
    // ArcIndex AddArcWithCost( NodeIndex left_node, NodeIndex right_node, CostValue cost );
    if ( info.Length() == 3
         && info[ 0 ].IsNumber()
         && info[ 1 ].IsNumber()
         && info[ 2 ].IsNumber() )
    {
        NodeIndex left_node  = info[ 0 ].As< Napi::Number >().Int64Value();
        NodeIndex right_node = info[ 1 ].As< Napi::Number >().Int64Value();
        CostValue cost       = info[ 2 ].As< Napi::Number >().Int64Value();
        ArcIndex  arc_index  = pSimpleLinearSumAssignment->AddArcWithCost( left_node, right_node, cost );
        return Napi::Number::New( info.Env(), arc_index );
    }

    ThrowJsError( operations_research::GSimpleLinearSumAssignment::AddArcWithCost : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GSimpleLinearSumAssignment::Solve( const Napi::CallbackInfo& info )
{
    // Status Solve();
    if ( info.Length() == 0 )
    {
        operations_research::SimpleLinearSumAssignment::Status status = pSimpleLinearSumAssignment->Solve();
        return Napi::Number::New( info.Env(), status );
    }

    ThrowJsError( operations_research::GSimpleLinearSumAssignment::Solve : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GSimpleLinearSumAssignment::NumNodes( const Napi::CallbackInfo& info )
{
    //  NodeIndex NumNodes() const;
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), pSimpleLinearSumAssignment->NumNodes() );
    }

    ThrowJsError( operations_research::GSimpleLinearSumAssignment::NumNodes : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GSimpleLinearSumAssignment::NumArcs( const Napi::CallbackInfo& info )
{
    // ArcIndex NumArcs() const;
    if ( info.Length() == 0 )
    {
        return Napi::Number::New( info.Env(), pSimpleLinearSumAssignment->NumArcs() );
    }

    ThrowJsError( operations_research::GSimpleLinearSumAssignment::NumArcs : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GSimpleLinearSumAssignment::RightNode( const Napi::CallbackInfo& info )
{
    // NodeIndex RightNode( ArcIndex arc ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        ArcIndex  arc        = info[ 0 ].As< Napi::Number >().Int32Value();
        NodeIndex right_node = pSimpleLinearSumAssignment->RightNode( arc );
        return Napi::Number::New( info.Env(), right_node );
    }

    ThrowJsError( operations_research::GSimpleLinearSumAssignment::RightNode : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GSimpleLinearSumAssignment::Cost( const Napi::CallbackInfo& info )
{
    // CostValue Cost( ArcIndex arc ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        ArcIndex  arc  = info[ 0 ].As< Napi::Number >().Int32Value();
        CostValue cost = pSimpleLinearSumAssignment->Cost( arc );
        return Napi::Number::New( info.Env(), cost );
    }

    ThrowJsError( operations_research::GSimpleLinearSumAssignment::Cost : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GSimpleLinearSumAssignment::OptimalCost( const Napi::CallbackInfo& info )
{
    // CostValue OptimalCost() const;
    if ( info.Length() == 0 )
    {
        CostValue optimal_cost = pSimpleLinearSumAssignment->OptimalCost();
        return Napi::Number::New( info.Env(), optimal_cost );
    }

    ThrowJsError( operations_research::GSimpleLinearSumAssignment::OptimalCost : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GSimpleLinearSumAssignment::RightMate( const Napi::CallbackInfo& info )
{
    //    NodeIndex RightMate( NodeIndex left_node ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        NodeIndex left_node  = info[ 0 ].As< Napi::Number >().Int32Value();
        NodeIndex right_mate = pSimpleLinearSumAssignment->RightMate( left_node );
        return Napi::Number::New( info.Env(), right_mate );
    }

    ThrowJsError( operations_research::GSimpleLinearSumAssignment::RightMate : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GSimpleLinearSumAssignment::AssignmentCost( const Napi::CallbackInfo& info )
{
    // CostValue AssignmentCost( NodeIndex left_node ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        NodeIndex node = info[ 0 ].As< Napi::Number >().Int32Value();
        CostValue cost = pSimpleLinearSumAssignment->AssignmentCost( node );
        return Napi::Number::New( info.Env(), cost );
    }

    ThrowJsError( operations_research::GSimpleLinearSumAssignment::AssignmentCost : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GSimpleLinearSumAssignment::LeftNode( const Napi::CallbackInfo& info )
{
    //  NodeIndex LeftNode( ArcIndex arc ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        ArcIndex  arc       = info[ 0 ].As< Napi::Number >().Int32Value();
        NodeIndex left_node = pSimpleLinearSumAssignment->LeftNode( arc );
        return Napi::Number::New( info.Env(), left_node );
    }

    ThrowJsError( operations_research::GSimpleLinearSumAssignment::LeftNode : Invalid argument );
    return info.Env().Undefined();
}

operations_research::GSimpleMinCostFlow::GSimpleMinCostFlow( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< operations_research::GSimpleMinCostFlow >( info )
{
    if ( info.Length() == 0 )
    {
        pSimpleMinCostFlow = new operations_research::SimpleMinCostFlow();
        return;
    }

    //  explicit SimpleMinCostFlow( NodeIndex reserve_num_nodes = 0, ArcIndex  reserve_num_arcs  = 0 );
    if ( info.Length() == 2
         && info[ 0 ].IsNumber()
         && info[ 1 ].IsNumber() )
    {
        NodeIndex reserve_num_nodes = info[ 0 ].As< Napi::Number >().Int64Value();
        ArcIndex  reserve_num_arcs  = info[ 1 ].As< Napi::Number >().Int64Value();
        pSimpleMinCostFlow          = new operations_research::SimpleMinCostFlow( reserve_num_nodes, reserve_num_arcs );
        return;
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow : Invalid argument );
}

operations_research::GSimpleMinCostFlow::~GSimpleMinCostFlow()
{
    delete pSimpleMinCostFlow;
}

Napi::Value operations_research::GSimpleMinCostFlow::AddArcWithCapacityAndUnitCost( const Napi::CallbackInfo& info )
{
    // ArcIndex AddArcWithCapacityAndUnitCost( NodeIndex tail, NodeIndex head, FlowQuantity capacity, CostValue unit_cost );
    if ( info.Length() == 4
         && info[ 0 ].IsNumber()
         && info[ 1 ].IsNumber()
         && info[ 2 ].IsNumber()
         && info[ 3 ].IsNumber() )
    {
        NodeIndex    tail      = info[ 0 ].As< Napi::Number >().Int32Value();
        NodeIndex    head      = info[ 1 ].As< Napi::Number >().Int32Value();
        FlowQuantity capacity  = info[ 2 ].As< Napi::Number >().Int64Value();
        CostValue    unit_cost = info[ 3 ].As< Napi::Number >().Int64Value();
        ArcIndex     arc_index = pSimpleMinCostFlow->AddArcWithCapacityAndUnitCost( tail, head, capacity, unit_cost );
        return Napi::Number::New( info.Env(), arc_index );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::AddArcWithCapacityAndUnitCost : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GSimpleMinCostFlow::SetNodeSupply( const Napi::CallbackInfo& info )
{
    //   void SetNodeSupply( NodeIndex node, FlowQuantity supply );
    if ( info.Length() == 2
         && info[ 0 ].IsNumber()
         && info[ 1 ].IsNumber() )
    {
        NodeIndex    node   = info[ 0 ].As< Napi::Number >().Int32Value();
        FlowQuantity supply = info[ 1 ].As< Napi::Number >().Int64Value();
        pSimpleMinCostFlow->SetNodeSupply( node, supply );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::SetNodeSupply : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GSimpleMinCostFlow::Solve( const Napi::CallbackInfo& info )
{
    // Status Solve();
    if ( info.Length() == 0 )
    {
        operations_research::SimpleMinCostFlow::Status status = pSimpleMinCostFlow->Solve();
        return Napi::Number::New( info.Env(), status );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::Solve : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GSimpleMinCostFlow::SolveMaxFlowWithMinCost( const Napi::CallbackInfo& info )
{
    // Status SolveMaxFlowWithMinCost();
    if ( info.Length() == 0 )
    {
        operations_research::SimpleMinCostFlow::Status status = pSimpleMinCostFlow->SolveMaxFlowWithMinCost();
        return Napi::Number::New( info.Env(), status );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::SolveMaxFlowWithMinCost : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GSimpleMinCostFlow::OptimalCost( const Napi::CallbackInfo& info )
{
    // CostValue OptimalCost() const;
    if ( info.Length() == 0 )
    {
        CostValue optimal_cost = pSimpleMinCostFlow->OptimalCost();
        return Napi::Number::New( info.Env(), optimal_cost );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::OptimalCost : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GSimpleMinCostFlow::MaximumFlow( const Napi::CallbackInfo& info )
{
    // FlowQuantity MaximumFlow() const;
    if ( info.Length() == 0 )
    {
        FlowQuantity maximum_flow = pSimpleMinCostFlow->MaximumFlow();
        return Napi::Number::New( info.Env(), maximum_flow );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::MaximumFlow : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GSimpleMinCostFlow::Flow( const Napi::CallbackInfo& info )
{
    // FlowQuantity Flow( ArcIndex arc ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        ArcIndex     arc  = info[ 0 ].As< Napi::Number >().Int32Value();
        FlowQuantity flow = pSimpleMinCostFlow->Flow( arc );
        return Napi::Number::New( info.Env(), flow );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::Flow : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GSimpleMinCostFlow::NumNodes( const Napi::CallbackInfo& info )
{
    // NodeIndex    NumNodes() const;
    if ( info.Length() == 0 )
    {
        NodeIndex num_nodes = pSimpleMinCostFlow->NumNodes();
        return Napi::Number::New( info.Env(), num_nodes );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::NumNodes : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GSimpleMinCostFlow::NumArcs( const Napi::CallbackInfo& info )
{
    // ArcIndex     NumArcs() const;
    if ( info.Length() == 0 )
    {
        ArcIndex num_arcs = pSimpleMinCostFlow->NumArcs();
        return Napi::Number::New( info.Env(), num_arcs );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::NumArcs : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GSimpleMinCostFlow::Tail( const Napi::CallbackInfo& info )
{
    // NodeIndex    Tail( ArcIndex arc ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        ArcIndex  arc       = info[ 0 ].As< Napi::Number >().Int32Value();
        NodeIndex tail_node = pSimpleMinCostFlow->Tail( arc );
        return Napi::Number::New( info.Env(), tail_node );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::Tail : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GSimpleMinCostFlow::Head( const Napi::CallbackInfo& info )
{
    // NodeIndex    Head( ArcIndex arc ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        ArcIndex  arc       = info[ 0 ].As< Napi::Number >().Int32Value();
        NodeIndex head_node = pSimpleMinCostFlow->Head( arc );
        return Napi::Number::New( info.Env(), head_node );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::Head : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GSimpleMinCostFlow::Capacity( const Napi::CallbackInfo& info )
{
    // FlowQuantity Capacity( ArcIndex arc ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        ArcIndex     arc      = info[ 0 ].As< Napi::Number >().Int32Value();
        FlowQuantity capacity = pSimpleMinCostFlow->Capacity( arc );
        return Napi::Number::New( info.Env(), capacity );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::Capacity : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GSimpleMinCostFlow::Supply( const Napi::CallbackInfo& info )
{
    // FlowQuantity Supply( NodeIndex node ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        NodeIndex    node   = info[ 0 ].As< Napi::Number >().Int32Value();
        FlowQuantity supply = pSimpleMinCostFlow->Supply( node );
        return Napi::Number::New( info.Env(), supply );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::Supply : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GSimpleMinCostFlow::UnitCost( const Napi::CallbackInfo& info )
{
    // CostValue    UnitCost( ArcIndex arc ) const;
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        ArcIndex  arc       = info[ 0 ].As< Napi::Number >().Int32Value();
        CostValue unit_cost = pSimpleMinCostFlow->UnitCost( arc );
        return Napi::Number::New( info.Env(), unit_cost );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::UnitCost : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPObjective::offset( const Napi::CallbackInfo& info )
{
    // double offset() const;
    if ( info.Length() == 0 )
    {
        double offset = pMPObjective->offset();
        return Napi::Number::New( info.Env(), offset );
    }

    ThrowJsError( operations_research::GMPObjective::offset : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPObjective::OptimizeLinearExpr( const Napi::CallbackInfo& info )
{
    // void OptimizeLinearExpr( const LinearExpr& linear_expr, bool is_maximization );
    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() )
         && info[ 1 ].IsBoolean() )
    {
        auto linear_expr     = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
        bool is_maximization = info[ 1 ].As< Napi::Boolean >().Value();
        pMPObjective->OptimizeLinearExpr( *linear_expr->pLinearExpr, is_maximization );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPObjective::OptimizeLinearExpr : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPObjective::MaximizeLinearExpr( const Napi::CallbackInfo& info )
{
    // void MaximizeLinearExpr( const LinearExpr& linear_expr );
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        auto linear_expr = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPObjective::MaximizeLinearExpr : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPObjective::MinimizeLinearExpr( const Napi::CallbackInfo& info )
{
    // void MinimizeLinearExpr( const LinearExpr& linear_expr );
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        auto linear_expr = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPObjective::MinimizeLinearExpr : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPObjective::AddLinearExpr( const Napi::CallbackInfo& info )
{
    //  void AddLinearExpr( const LinearExpr& linear_expr );
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        auto linear_expr = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPObjective::AddLinearExpr : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPObjective::SetOptimizationDirection( const Napi::CallbackInfo& info )
{
    // void SetOptimizationDirection( bool maximize );
    if ( info.Length() == 1 && info[ 0 ].IsBoolean() )
    {
        bool maximize = info[ 0 ].As< Napi::Boolean >().Value();
        pMPObjective->SetOptimizationDirection( maximize );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPObjective::SetOptimizationDirection : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPObjective::SetMaximization( const Napi::CallbackInfo& info )
{
    // void SetMaximization();
    if ( info.Length() == 0 )
    {
        pMPObjective->SetMaximization();
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPObjective::SetMaximization : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPObjective::maximization( const Napi::CallbackInfo& info )
{
    // bool maximization() const;
    if ( info.Length() == 0 )
    {
        bool maximization = pMPObjective->maximization();
        return Napi::Boolean::New( info.Env(), maximization );
    }

    ThrowJsError( operations_research::GMPObjective::maximization : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPObjective::minimization( const Napi::CallbackInfo& info )
{
    // bool minimization() const;
    if ( info.Length() == 0 )
    {
        bool minimization = pMPObjective->minimization();
        return Napi::Boolean::New( info.Env(), minimization );
    }

    ThrowJsError( operations_research::GMPObjective::minimization : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPObjective::BestBound( const Napi::CallbackInfo& info )
{
    // double BestBound() const;
    if ( info.Length() == 0 )
    {
        double best_bound = pMPObjective->BestBound();
        return Napi::Number::New( info.Env(), best_bound );
    }

    ThrowJsError( operations_research::GMPObjective::BestBound : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPVariable::name( const Napi::CallbackInfo& info )
{
    // const std::string& name() const;
    if ( info.Length() == 0 )
    {
        const std::string& name = pMPVariable->name();
        return Napi::String::New( info.Env(), name );
    }

    ThrowJsError( operations_research::GMPVariable::name : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPVariable::SetInteger( const Napi::CallbackInfo& info )
{
    // void SetInteger( bool integer );
    if ( info.Length() == 1 && info[ 0 ].IsBoolean() )
    {
        bool integer = info[ 0 ].As< Napi::Boolean >().Value();
        pMPVariable->SetInteger( integer );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPVariable::SetInteger : Invalid argument );
    return info.Env().Undefined();
}
Napi::Value operations_research::GMPVariable::integer( const Napi::CallbackInfo& info )
{
    // bool integer() const;
    if ( info.Length() == 0 )
    {
        bool integer = pMPVariable->integer();
        return Napi::Boolean::New( info.Env(), integer );
    }

    ThrowJsError( operations_research::GMPVariable::integer : Invalid argument );
    return info.Env().Undefined();
}
Napi::Value operations_research::GMPVariable::solution_value( const Napi::CallbackInfo& info )
{
    // double solution_value() const;
    if ( info.Length() == 0 )
    {
        double solution_value = pMPVariable->solution_value();
        return Napi::Number::New( info.Env(), solution_value );
    }

    ThrowJsError( operations_research::GMPVariable::solution_value : Invalid argument );
    return info.Env().Undefined();
}
Napi::Value operations_research::GMPVariable::index( const Napi::CallbackInfo& info )
{
    // int index() const;
    if ( info.Length() == 0 )
    {
        int index = pMPVariable->index();
        return Napi::Number::New( info.Env(), index );
    }

    ThrowJsError( operations_research::GMPVariable::index : Invalid argument );
    return info.Env().Undefined();
}
Napi::Value operations_research::GMPVariable::lb( const Napi::CallbackInfo& info )
{
    // double lb() const;
    if ( info.Length() == 0 )
    {
        double lb = pMPVariable->lb();
        return Napi::Number::New( info.Env(), lb );
    }

    ThrowJsError( operations_research::GMPVariable::lb : Invalid argument );
    return info.Env().Undefined();
}
Napi::Value operations_research::GMPVariable::ub( const Napi::CallbackInfo& info )
{
    // double ub() const;
    if ( info.Length() == 0 )
    {
        double ub = pMPVariable->ub();
        return Napi::Number::New( info.Env(), ub );
    }

    ThrowJsError( operations_research::GMPVariable::ub : Invalid argument );
    return info.Env().Undefined();
}
Napi::Value operations_research::GMPVariable::SetLB( const Napi::CallbackInfo& info )
{
    // void SetLB( double lb );
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        double lb = info[ 0 ].As< Napi::Number >().DoubleValue();
        pMPVariable->SetLB( lb );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPVariable::SetLB : Invalid argument );
    return info.Env().Undefined();
}
Napi::Value operations_research::GMPVariable::SetUB( const Napi::CallbackInfo& info )
{
    // void SetUB( double ub );
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        double ub = info[ 0 ].As< Napi::Number >().DoubleValue();
        pMPVariable->SetUB( ub );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPVariable::SetUB : Invalid argument );
    return info.Env().Undefined();
}
Napi::Value operations_research::GMPVariable::SetBounds( const Napi::CallbackInfo& info )
{
    // void SetBounds( double lb, double ub );
    if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() )
    {
        double lb = info[ 0 ].As< Napi::Number >().DoubleValue();
        double ub = info[ 1 ].As< Napi::Number >().DoubleValue();
        pMPVariable->SetBounds( lb, ub );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPVariable::SetBounds : Invalid argument );
    return info.Env().Undefined();
}
Napi::Value operations_research::GMPVariable::unrounded_solution_value( const Napi::CallbackInfo& info )
{
    // double unrounded_solution_value() const;
    if ( info.Length() == 0 )
    {
        double unrounded_solution_value = pMPVariable->unrounded_solution_value();
        return Napi::Number::New( info.Env(), unrounded_solution_value );
    }

    ThrowJsError( operations_research::GMPVariable::unrounded_solution_value : Invalid argument );
    return info.Env().Undefined();
}
Napi::Value operations_research::GMPVariable::reduced_cost( const Napi::CallbackInfo& info )
{
    // double reduced_cost() const;
    if ( info.Length() == 0 )
    {
        double reduced_cost = pMPVariable->reduced_cost();
        return Napi::Number::New( info.Env(), reduced_cost );
    }

    ThrowJsError( operations_research::GMPVariable::reduced_cost : Invalid argument );
    return info.Env().Undefined();
}
Napi::Value operations_research::GMPVariable::basis_status( const Napi::CallbackInfo& info )
{
    // MPSolver::BasisStatus basis_status() const;
    if ( info.Length() == 0 )
    {
        MPSolver::BasisStatus basis_status = pMPVariable->basis_status();
        return Napi::Number::New( info.Env(), basis_status );
    }

    ThrowJsError( operations_research::GMPVariable::basis_status : Invalid argument );
    return info.Env().Undefined();
}
Napi::Value operations_research::GMPVariable::branching_priority( const Napi::CallbackInfo& info )
{
    // int branching_priority() const;
    if ( info.Length() == 0 )
    {
        int branching_priority = pMPVariable->branching_priority();
        return Napi::Number::New( info.Env(), branching_priority );
    }

    ThrowJsError( operations_research::GMPVariable::branching_priority : Invalid argument );
    return info.Env().Undefined();
}
Napi::Value operations_research::GMPVariable::SetBranchingPriority( const Napi::CallbackInfo& info )
{
    // void SetBranchingPriority( int priority );
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        int priority = info[ 0 ].As< Napi::Number >().Int32Value();
        pMPVariable->SetBranchingPriority( priority );
        return info.Env().Undefined();
    }

    ThrowJsError( operations_research::GMPVariable::SetBranchingPriority : Invalid argument );
    return info.Env().Undefined();
}

operations_research::GMPSolverParameters::~GMPSolverParameters()
{
    delete pMPSolverParameters;
}

operations_research::GMPSolverParameters::GMPSolverParameters( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPSolverParameters >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external       = info[ 0 ].As< Napi::External< MPSolverParameters > >();
        pMPSolverParameters = dynamic_cast< MPSolverParameters* >( external.Data() );
        if ( pMPSolverParameters != nullptr ) return;
    }

    ThrowJsError( operations_research::GMPSolverParameters : Invalid argument );
}

operations_research::GMPModelProto::GMPModelProto( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPModelProto >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< MPModelProto > >();
        pMPModelProto = dynamic_cast< MPModelProto* >( external.Data() );
        if ( pMPModelProto != nullptr ) return;
    }

    ThrowJsError( operations_research::GMPModelProto : Invalid argument );
}

operations_research::GMPModelProto::~GMPModelProto()
{
    delete pMPModelProto;
}

operations_research::GMPSolutionResponse::GMPSolutionResponse( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPSolutionResponse >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external       = info[ 0 ].As< Napi::External< MPSolutionResponse > >();
        pMPSolutionResponse = dynamic_cast< MPSolutionResponse* >( external.Data() );
        if ( pMPSolutionResponse != nullptr ) return;
    }

    ThrowJsError( operations_research::GMPSolutionResponse : Invalid argument );
}

operations_research::GMPSolutionResponse::~GMPSolutionResponse()
{
    delete pMPSolutionResponse;
}

operations_research::GMPModelRequest::GMPModelRequest( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GMPModelRequest >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external   = info[ 0 ].As< Napi::External< MPModelRequest > >();
        pMPModelRequest = dynamic_cast< MPModelRequest* >( external.Data() );
        if ( pMPModelRequest != nullptr ) return;
    }

    ThrowJsError( operations_research::GMPModelRequest : Invalid argument );
}

operations_research::GMPModelRequest::~GMPModelRequest()
{
    delete pMPModelRequest;
}

operations_research::GDomain::GDomain( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GDomain >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< operations_research::Domain > >();
        pDomain       = dynamic_cast< operations_research::Domain* >( external.Data() );
        if ( pDomain != nullptr ) return;
    }

    //  Domain() {}
    if ( info.Length() == 0 )
    {
        pDomain = new Domain();
        return;
    }

    // explicit Domain( int64_t value );
    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        int64_t value = info[ 0 ].As< Napi::Number >().Int64Value();
        pDomain       = new Domain( value );
        return;
    }

    // Domain(int64_t left, int64_t right);
    if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() )
    {
        int64_t left  = info[ 0 ].As< Napi::Number >().Int64Value();
        int64_t right = info[ 1 ].As< Napi::Number >().Int64Value();
        pDomain       = new Domain( left, right );
        return;
    }

    ThrowJsError( operations_research::sat::GDomain : Invalid argument );
}

operations_research::GDomain::~GDomain()
{
    delete pDomain;
}

Napi::Value operations_research::sat::GIntVar::ToBoolVar( const Napi::CallbackInfo& info )
{
    // BoolVar ToBoolVar() const;
    if ( info.Length() == 0 )
    {
        auto result  = pIntVar->ToBoolVar();
        auto wrapper = Napi::External< BoolVar >::New( info.Env(), new BoolVar( result ) );
        return GBoolVar::constructor.New( { wrapper } );
    }

    ThrowJsError( operations_research::sat::GIntVar::ToBoolVar : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GIntVar::WithName( const Napi::CallbackInfo& info )
{
    // IntVar WithName( const std::string& name ) const;
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string name    = info[ 0 ].As< Napi::String >().Utf8Value();
        auto        result  = pIntVar->WithName( name );
        auto        wrapper = Napi::External< IntVar >::New( info.Env(), new IntVar( result ) );
        return GIntVar::constructor.New( { wrapper } );
    }

    ThrowJsError( operations_research::sat::GIntVar::WithName : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GIntVar::Name( const Napi::CallbackInfo& info )
{
    // std::string Name() const;
    if ( info.Length() == 0 )
    {
        std::string name = pIntVar->Name();
        return Napi::String::New( info.Env(), name );
    }

    ThrowJsError( operations_research::sat::GIntVar::Name : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GIntVar::operator_equals( const Napi::CallbackInfo& info )
{
    // bool operator==( const IntVar& other ) const;
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
    {
        auto other = GIntVar::Unwrap( info[ 0 ].As< Napi::Object >() );
        return Napi::Boolean::New( info.Env(), *pIntVar == *other->pIntVar );
    }

    ThrowJsError( operations_research::sat::GIntVar::operator_equals : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GIntVar::operator_not_equals( const Napi::CallbackInfo& info )
{
    // bool operator!=( const IntVar& other ) const;
    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GIntVar::constructor.Value() ) )
    {
        auto other = GIntVar::Unwrap( info[ 0 ].As< Napi::Object >() );
        return Napi::Boolean::New( info.Env(), *pIntVar != *other->pIntVar );
    }

    ThrowJsError( operations_research::sat::GIntVar::operator_not_equals : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GIntVar::Domain( const Napi::CallbackInfo& info )
{
    // ::operations_research::Domain Domain() const;
    if ( info.Length() == 0 )
    {
        auto domain  = pIntVar->Domain();
        auto wrapper = Napi::External< operations_research::Domain >::New( info.Env(), new operations_research::Domain( domain ) );
        return GDomain::constructor.New( { wrapper } );
    }

    ThrowJsError( operations_research::sat::GIntVar::Domain : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GIntVar::DebugString( const Napi::CallbackInfo& info )
{
    // std::string DebugString() const;
    if ( info.Length() == 0 )
    {
        std::string debug_string = pIntVar->DebugString();
        return Napi::String::New( info.Env(), debug_string );
    }

    ThrowJsError( operations_research::sat::GIntVar::DebugString : Invalid argument );
    return info.Env().Undefined();
}

Napi::Value operations_research::sat::GIntVar::index( const Napi::CallbackInfo& info )
{
    // int index() const;
    if ( info.Length() == 0 )
    {
        int index = pIntVar->index();
        return Napi::Number::New( info.Env(), index );
    }

    ThrowJsError( operations_research::sat::GIntVar::index : Invalid argument );
    return info.Env().Undefined();
}
