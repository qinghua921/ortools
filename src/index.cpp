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

    ThrowJsError( operations_research::GMPSolver::GMPSolver : Invalid argument );
}

operations_research::GMPSolver::~GMPSolver()
{
    delete pMPSolver;
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

    ThrowJsError( operations_research::GMPSolver::Solve : Invalid argument );
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

    LinearExpr LinearExpr_lhs;

    if ( info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        LinearExpr_lhs = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 0 ].IsNumber() )
    {
        LinearExpr_lhs = LinearExpr( info[ 0 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 0 ].IsObject()
              && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        LinearExpr_lhs = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 0 ].As< Napi::Object >() )->pMPVariable;
    }
    else
    {
        ThrowJsError( operations_research::operator_less_equals : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr LinearExpr_rhs;

    if ( info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        LinearExpr_rhs = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 1 ].IsNumber() )
    {
        LinearExpr_rhs = LinearExpr( info[ 1 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 1 ].IsObject()
              && info[ 1 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        LinearExpr_rhs = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 1 ].As< Napi::Object >() )->pMPVariable;
    }
    else
    {
        ThrowJsError( operations_research::operator_less_equals : Invalid argument );
        return info.Env().Undefined();
    }

    auto pLinearRange = new LinearRange( LinearExpr_lhs <= LinearExpr_rhs );
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

    LinearExpr LinearExpr_lhs;

    if ( info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        LinearExpr_lhs = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 0 ].IsNumber() )
    {
        LinearExpr_lhs = LinearExpr( info[ 0 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 0 ].IsObject()
              && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        LinearExpr_lhs = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 0 ].As< Napi::Object >() )->pMPVariable;
    }
    else
    {
        ThrowJsError( operations_research::operator_equals : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr LinearExpr_rhs;

    if ( info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        LinearExpr_rhs = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 1 ].IsNumber() )
    {
        LinearExpr_rhs = LinearExpr( info[ 1 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 1 ].IsObject()
              && info[ 1 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        LinearExpr_rhs = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 1 ].As< Napi::Object >() )->pMPVariable;
    }
    else
    {
        ThrowJsError( operations_research::operator_equals : Invalid argument );
        return info.Env().Undefined();
    }

    auto pLinearRange = new LinearRange( LinearExpr_lhs == LinearExpr_rhs );
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

    LinearExpr LinearExpr_lhs;

    if ( info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        LinearExpr_lhs = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 0 ].IsNumber() )
    {
        LinearExpr_lhs = LinearExpr( info[ 0 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 0 ].IsObject()
              && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        LinearExpr_lhs = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 0 ].As< Napi::Object >() )->pMPVariable;
    }
    else
    {
        ThrowJsError( operations_research::operator_greater_equals : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr LinearExpr_rhs;

    if ( info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        LinearExpr_rhs = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 1 ].IsNumber() )
    {
        LinearExpr_rhs = LinearExpr( info[ 1 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 1 ].IsObject()
              && info[ 1 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        LinearExpr_rhs = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 1 ].As< Napi::Object >() )->pMPVariable;
    }
    else
    {
        ThrowJsError( operations_research::operator_greater_equals : Invalid argument );
        return info.Env().Undefined();
    }

    auto pLinearRange = new LinearRange( LinearExpr_lhs >= LinearExpr_rhs );
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
    // TODO
}

operations_research::sat::GConstraint::~GConstraint()
{
    delete pConstraint;
}

operations_research::sat::GIntVar::GIntVar( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< operations_research::sat::GIntVar >( info )
{
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

    LinearExpr LinearExpr_lhs;

    if ( info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        LinearExpr_lhs = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 0 ].IsNumber() )
    {
        LinearExpr_lhs = LinearExpr( info[ 0 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 0 ].IsObject()
              && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        LinearExpr_lhs = LinearExpr( *Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 0 ].As< Napi::Object >() )->pBoolVar );
    }
    else
    {
        ThrowJsError( operations_research::sat::operator_plus : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr LinearExpr_rhs;
    if ( info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        LinearExpr_rhs = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 1 ].IsNumber() )
    {
        LinearExpr_rhs = LinearExpr( info[ 1 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 1 ].IsObject()
              && info[ 1 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        LinearExpr_rhs = LinearExpr( *Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 1 ].As< Napi::Object >() )->pBoolVar );
    }
    else
    {
        ThrowJsError( operations_research::sat::operator_plus : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr result = LinearExpr_lhs + LinearExpr_rhs;
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

    LinearExpr LinearExpr_lhs;

    if ( info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        LinearExpr_lhs = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 0 ].IsNumber() )
    {
        LinearExpr_lhs = LinearExpr( info[ 0 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 0 ].IsObject()
              && info[ 0 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        LinearExpr_lhs = LinearExpr( *Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 0 ].As< Napi::Object >() )->pBoolVar );
    }
    else
    {
        ThrowJsError( operations_research::sat::operator_minus : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr LinearExpr_rhs;
    if ( info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        LinearExpr_rhs = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() )->pLinearExpr;
    }
    else if ( info[ 1 ].IsNumber() )
    {
        LinearExpr_rhs = LinearExpr( info[ 1 ].As< Napi::Number >().DoubleValue() );
    }
    else if ( info[ 1 ].IsObject()
              && info[ 1 ].As< Napi::Object >().InstanceOf( GBoolVar::constructor.Value() ) )
    {
        LinearExpr_rhs = LinearExpr( *Napi::ObjectWrap< GBoolVar >::Unwrap( info[ 1 ].As< Napi::Object >() )->pBoolVar );
    }
    else
    {
        ThrowJsError( operations_research::sat::operator_minus : Invalid argument );
        return info.Env().Undefined();
    }

    LinearExpr result = LinearExpr_lhs - LinearExpr_rhs;
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
    if ( info[ 0 ].IsObject() && info[ 1 ].IsNumber() )
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
    if ( info[ 1 ].IsObject()
         && info[ 0 ].IsNumber() )
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
        ArcIndex  arc        = info[ 0 ].As< Napi::Number >().Int32Value();
        CostValue unit_cost = pSimpleMinCostFlow->UnitCost( arc );
        return Napi::Number::New( info.Env(), unit_cost );
    }

    ThrowJsError( operations_research::GSimpleMinCostFlow::UnitCost : Invalid argument );
    return info.Env().Undefined();
}
