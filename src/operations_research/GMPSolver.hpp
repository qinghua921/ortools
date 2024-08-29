namespace operations_research
{

class GMPSolver : public Napi::ObjectWrap< GMPSolver >
{
public:
    static Napi::FunctionReference constructor;
    MPSolver*                      pMPSolver = nullptr;
    GMPSolver( const Napi::CallbackInfo& info );
    ~GMPSolver();

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );

        Napi::Object resultStatus = Napi::Object::New( env );
        resultStatus.Set( Napi::String::New( env, "OPTIMAL" ), Napi::Number::New( env, MPSolver::OPTIMAL ) );
        resultStatus.Set( Napi::String::New( env, "FEASIBLE" ), Napi::Number::New( env, MPSolver::FEASIBLE ) );
        resultStatus.Set( Napi::String::New( env, "INFEASIBLE" ), Napi::Number::New( env, MPSolver::INFEASIBLE ) );
        resultStatus.Set( Napi::String::New( env, "UNBOUNDED" ), Napi::Number::New( env, MPSolver::UNBOUNDED ) );
        resultStatus.Set( Napi::String::New( env, "ABNORMAL" ), Napi::Number::New( env, MPSolver::ABNORMAL ) );
        resultStatus.Set( Napi::String::New( env, "MODEL_INVALID" ), Napi::Number::New( env, MPSolver::MODEL_INVALID ) );
        resultStatus.Set( Napi::String::New( env, "NOT_SOLVED" ), Napi::Number::New( env, MPSolver::NOT_SOLVED ) );

        Napi::Object optimizationProblemType = Napi::Object::New( env );
        optimizationProblemType.Set( Napi::String::New( env, "CLP_LINEAR_PROGRAMMING" ), Napi::Number::New( env, 0 ) );
        optimizationProblemType.Set( Napi::String::New( env, "GLPK_LINEAR_PROGRAMMING" ), Napi::Number::New( env, 1 ) );
        optimizationProblemType.Set( Napi::String::New( env, "GLOP_LINEAR_PROGRAMMING" ), Napi::Number::New( env, 2 ) );
        optimizationProblemType.Set( Napi::String::New( env, "PDLP_LINEAR_PROGRAMMING" ), Napi::Number::New( env, 8 ) );
        optimizationProblemType.Set( Napi::String::New( env, "HIGHS_LINEAR_PROGRAMMING" ), Napi::Number::New( env, 15 ) );
        optimizationProblemType.Set( Napi::String::New( env, "SCIP_MIXED_INTEGER_PROGRAMMING" ), Napi::Number::New( env, 3 ) );
        optimizationProblemType.Set( Napi::String::New( env, "GLPK_MIXED_INTEGER_PROGRAMMING" ), Napi::Number::New( env, 4 ) );
        optimizationProblemType.Set( Napi::String::New( env, "CBC_MIXED_INTEGER_PROGRAMMING" ), Napi::Number::New( env, 5 ) );
        optimizationProblemType.Set( Napi::String::New( env, "GUROBI_LINEAR_PROGRAMMING" ), Napi::Number::New( env, 6 ) );
        optimizationProblemType.Set( Napi::String::New( env, "GUROBI_MIXED_INTEGER_PROGRAMMING" ), Napi::Number::New( env, 7 ) );
        optimizationProblemType.Set( Napi::String::New( env, "CPLEX_LINEAR_PROGRAMMING" ), Napi::Number::New( env, 10 ) );
        optimizationProblemType.Set( Napi::String::New( env, "CPLEX_MIXED_INTEGER_PROGRAMMING" ), Napi::Number::New( env, 11 ) );
        optimizationProblemType.Set( Napi::String::New( env, "XPRESS_LINEAR_PROGRAMMING" ), Napi::Number::New( env, 101 ) );
        optimizationProblemType.Set( Napi::String::New( env, "XPRESS_MIXED_INTEGER_PROGRAMMING" ), Napi::Number::New( env, 102 ) );
        optimizationProblemType.Set( Napi::String::New( env, "HIGHS_MIXED_INTEGER_PROGRAMMING" ), Napi::Number::New( env, 16 ) );
        optimizationProblemType.Set( Napi::String::New( env, "KNAPSACK_MIXED_INTEGER_PROGRAMMING" ), Napi::Number::New( env, 13 ) );

        Napi::Function func = DefineClass(
            env, "MPSolver",
            {
                StaticMethod( "CreateSolver", &GMPSolver::CreateSolver ),
                InstanceMethod( "MakeBoolVar", &GMPSolver::MakeBoolVar ),
                InstanceMethod( "MakeRowConstraint", &GMPSolver::MakeRowConstraint ),
                InstanceMethod( "MutableObjective", &GMPSolver::MutableObjective ),
                InstanceMethod( "Solve", &GMPSolver::Solve ),
                StaticValue( "ResultStatus", resultStatus ),
                StaticValue( "OptimizationProblemType", optimizationProblemType ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPSolver" ), func );
        return exports;
    }

    static Napi::Value CreateSolver( const Napi::CallbackInfo& info );       // static MPSolver* CreateSolver( const std::string& solver_id );
    Napi::Value        MakeBoolVar( const Napi::CallbackInfo& info );        // MPVariable* MakeBoolVar( const std::string& name );
    Napi::Value        MakeRowConstraint( const Napi::CallbackInfo& info );  // MPConstraint* MakeRowConstraint( double lb, double ub );
    Napi::Value        MutableObjective( const Napi::CallbackInfo& info );   // MPObjective* MutableObjective();
    Napi::Value        Solve( const Napi::CallbackInfo& info );              // ResultStatus Solve();
};

Napi::FunctionReference GMPSolver::constructor;

}