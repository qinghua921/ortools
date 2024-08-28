#include "index.hpp"

operations_research::GMPSolver::GMPSolver( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< operations_research::GMPSolver >( info )
{
    //     MPSolver( const std::string& name, OptimizationProblemType problem_type );
    if ( info.Length() == 2 && info[ 0 ].IsString() && info[ 1 ].IsNumber() )
    {
        std::string name                     = info[ 0 ].As< Napi::String >();
        using OptimizationProblemType        = MPSolver::OptimizationProblemType;
        OptimizationProblemType problem_type = static_cast< OptimizationProblemType >( info[ 1 ].As< Napi::Number >().Int32Value() );
        pMPSolver                            = new MPSolver( name, problem_type );
        return;
    }

    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< MPSolver > >();
        pMPSolver     = dynamic_cast< MPSolver* >( external.Data() );
        if ( pMPSolver != nullptr ) return;
    }

    ThrowJsError( GMPSolver::GMPSolver : Invalid arguments );
}

operations_research::GMPSolver::~GMPSolver()
{
    delete pMPSolver;
}

Napi::Value operations_research::GMPSolver::CreateSolver( const Napi::CallbackInfo& info )
{
    // static MPSolver* CreateSolver( const std::string& solver_id );
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string solver_id = info[ 0 ].As< Napi::String >();
        MPSolver*   pSolver   = MPSolver::CreateSolver( solver_id );
        auto        external  = Napi::External< MPSolver >::New( info.Env(), pSolver );
        return GMPSolver::constructor.New( { external } );
    }

    ThrowJsError( GMPSolver::CreateSolver : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::MakeBoolVar( const Napi::CallbackInfo& info )
{
    //  MPVariable* MakeBoolVar( const std::string& name );
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string name     = info[ 0 ].As< Napi::String >();
        MPVariable* pVar     = pMPSolver->MakeBoolVar( name );
        auto        external = Napi::External< MPVariable >::New( info.Env(), pVar );
        return GMPVariable::constructor.New( { external } );
    }

    ThrowJsError( GMPSolver::MakeBoolVar : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value operations_research::GMPSolver::MakeRowConstraint( const Napi::CallbackInfo& info )
{

    // MakeRowConstraint(lb: number, ub: number): MPConstraint;
    if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() )
    {
        double lb = info[ 0 ].As< Napi::Number >().DoubleValue();
        double ub = info[ 1 ].As< Napi::Number >().DoubleValue();
        // TODO
    }

    // MakeRowConstraint(): MPConstraint;

    // MakeRowConstraint(lb: number, ub: number, name: string): MPConstraint;

    // MakeRowConstraint(name: string): MPConstraint;

    // MakeRowConstraint(range: LinearRange): MPConstraint;

    // MakeRowConstraint(range: LinearRange, name: string): MPConstraint;
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

    ThrowJsError( GMPVariable::GMPVariable : Invalid arguments );
}

operations_research::GMPVariable::~GMPVariable()
{
    delete pMPVariable;
}

operations_research::GLinearExpr::GLinearExpr( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< operations_research::GLinearExpr >( info )
{
    // LinearExpr();
    if ( info.Length() == 0 )
    {
        pLinearExpr = new LinearExpr();
        return;
    }

    ThrowJsError( GLinearExpr::GLinearExpr : Invalid arguments );
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
        auto        rhs      = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
        LinearExpr* pRhsExpr = rhs->pLinearExpr;
        *pLinearExpr += *pRhsExpr;
        return info.This();
    }

    if ( info.Length() == 1 && info[ 0 ].IsNumber() )
    {
        double value = info[ 0 ].As< Napi::Number >().DoubleValue();
        *pLinearExpr += value;
        return info.This();
    }

    if ( info.Length() == 1
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        auto        var  = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 0 ].As< Napi::Object >() );
        MPVariable* pVar = var->pMPVariable;
        *pLinearExpr += pVar;
        return info.This();
    }

    ThrowJsError( GLinearExpr::operator_plus_equals : Invalid arguments );
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

    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< LinearRange > >();
        pLinearRange  = dynamic_cast< LinearRange* >( external.Data() );
        if ( pLinearRange != nullptr ) return;
    }

    ThrowJsError( GLinearRange::GLinearRange : Invalid arguments );
}

operations_research::GLinearRange::~GLinearRange()
{
    delete pLinearRange;
}

Napi::Value operations_research::operator_less_equals( const Napi::CallbackInfo& info )
{
    // LinearRange operator<=( const LinearExpr& lhs, const LinearExpr& rhs );
    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() )
         && info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        auto        lhs      = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
        LinearExpr* pLhsExpr = lhs->pLinearExpr;
        auto        rhs      = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() );
        LinearExpr* pRhsExpr = rhs->pLinearExpr;
        auto        range    = *pLhsExpr <= *pRhsExpr;
        auto        external = Napi::External< LinearRange >::New( info.Env(), new LinearRange( range ) );
        return GLinearRange::constructor.New( { external } );
    }

    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() )
         && info[ 1 ].IsNumber() )
    {
        auto        lhs      = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
        LinearExpr* pLhsExpr = lhs->pLinearExpr;
        double      value    = info[ 1 ].As< Napi::Number >().DoubleValue();
        auto        range    = *pLhsExpr <= value;
        auto        external = Napi::External< LinearRange >::New( info.Env(), new LinearRange( range ) );
        return GLinearRange::constructor.New( { external } );
    }

    if ( info.Length() == 2
         && info[ 0 ].IsNumber()
         && info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        double      value    = info[ 0 ].As< Napi::Number >().DoubleValue();
        auto        rhs      = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() );
        LinearExpr* pRhsExpr = rhs->pLinearExpr;
        auto        range    = value <= *pRhsExpr;
        auto        external = Napi::External< LinearRange >::New( info.Env(), new LinearRange( range ) );
        return GLinearRange::constructor.New( { external } );
    }

    ThrowJsError( operator_less_equals : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value operations_research::operator_equals( const Napi::CallbackInfo& info )
{
    // LinearRange operator==( const LinearExpr& lhs, const LinearExpr& rhs );
    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() )
         && info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        auto        lhs      = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
        LinearExpr* pLhsExpr = lhs->pLinearExpr;
        auto        rhs      = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() );
        LinearExpr* pRhsExpr = rhs->pLinearExpr;
        auto        range    = *pLhsExpr == *pRhsExpr;
        auto        external = Napi::External< LinearRange >::New( info.Env(), new LinearRange( range ) );
        return GLinearRange::constructor.New( { external } );
    }

    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() )
         && info[ 1 ].IsNumber() )
    {
        auto        lhs      = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
        LinearExpr* pLhsExpr = lhs->pLinearExpr;
        double      value    = info[ 1 ].As< Napi::Number >().DoubleValue();
        auto        range    = *pLhsExpr == value;
        auto        external = Napi::External< LinearRange >::New( info.Env(), new LinearRange( range ) );
        return GLinearRange::constructor.New( { external } );
    }

    if ( info.Length() == 2
         && info[ 0 ].IsNumber()
         && info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        double      value    = info[ 0 ].As< Napi::Number >().DoubleValue();
        auto        rhs      = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() );
        LinearExpr* pRhsExpr = rhs->pLinearExpr;
        auto        range    = value == *pRhsExpr;
        auto        external = Napi::External< LinearRange >::New( info.Env(), new LinearRange( range ) );
        return GLinearRange::constructor.New( { external } );
    }

    ThrowJsError( operator_equals : Invalid arguments );
    return info.Env().Undefined();
}

Napi::Value operations_research::operator_greater_equals( const Napi::CallbackInfo& info )
{
    // LinearRange operator>=( const LinearExpr& lhs, const LinearExpr& rhs );
    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() )
         && info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        auto        lhs      = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
        LinearExpr* pLhsExpr = lhs->pLinearExpr;
        auto        rhs      = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() );
        LinearExpr* pRhsExpr = rhs->pLinearExpr;
        auto        range    = *pLhsExpr >= *pRhsExpr;
        auto        external = Napi::External< LinearRange >::New( info.Env(), new LinearRange( range ) );
        return GLinearRange::constructor.New( { external } );
    }

    if ( info.Length() == 2
         && info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() )
         && info[ 1 ].IsNumber() )
    {
        auto        lhs      = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() );
        LinearExpr* pLhsExpr = lhs->pLinearExpr;
        double      value    = info[ 1 ].As< Napi::Number >().DoubleValue();
        auto        range    = *pLhsExpr >= value;
        auto        external = Napi::External< LinearRange >::New( info.Env(), new LinearRange( range ) );
        return GLinearRange::constructor.New( { external } );
    }

    if ( info.Length() == 2
         && info[ 0 ].IsNumber()
         && info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        double      value    = info[ 0 ].As< Napi::Number >().DoubleValue();
        auto        rhs      = Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() );
        LinearExpr* pRhsExpr = rhs->pLinearExpr;
        auto        range    = value >= *pRhsExpr;
        auto        external = Napi::External< LinearRange >::New( info.Env(), new LinearRange( range ) );
        return GLinearRange::constructor.New( { external } );
    }

    ThrowJsError( operator_greater_equals : Invalid arguments );
    return info.Env().Undefined();
}
