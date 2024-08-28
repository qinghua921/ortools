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
    bool       is_lhs_ok = false;

    if ( info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        LinearExpr_lhs = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() )->pLinearExpr;
        is_lhs_ok      = true;
    }
    else if ( info[ 0 ].IsNumber() )
    {
        LinearExpr_lhs = LinearExpr( info[ 0 ].As< Napi::Number >().DoubleValue() );
        is_lhs_ok      = true;
    }
    else if ( info[ 0 ].IsObject()
              && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        LinearExpr_lhs = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 0 ].As< Napi::Object >() )->pMPVariable;
        is_lhs_ok      = true;
    }

    LinearExpr LinearExpr_rhs;
    bool       is_rhs_ok = false;

    if ( info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        LinearExpr_rhs = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() )->pLinearExpr;
        is_rhs_ok      = true;
    }
    else if ( info[ 1 ].IsNumber() )
    {
        LinearExpr_rhs = LinearExpr( info[ 1 ].As< Napi::Number >().DoubleValue() );
        is_rhs_ok      = true;
    }
    else if ( info[ 1 ].IsObject()
              && info[ 1 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        LinearExpr_rhs = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 1 ].As< Napi::Object >() )->pMPVariable;
        is_rhs_ok      = true;
    }

    if ( is_lhs_ok && is_rhs_ok )
    {
        auto pLinearRange = new LinearRange( LinearExpr_lhs <= LinearExpr_rhs );
        auto external     = Napi::External< LinearRange >::New( info.Env(), pLinearRange );
        return GLinearRange::constructor.New( { external } );
    }

    ThrowJsError( operations_research::operator_less_equals : Invalid argument );
    return info.Env().Undefined();
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
    bool       is_lhs_ok = false;

    if ( info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        LinearExpr_lhs = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() )->pLinearExpr;
        is_lhs_ok      = true;
    }
    else if ( info[ 0 ].IsNumber() )
    {
        LinearExpr_lhs = LinearExpr( info[ 0 ].As< Napi::Number >().DoubleValue() );
        is_lhs_ok      = true;
    }
    else if ( info[ 0 ].IsObject()
              && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        LinearExpr_lhs = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 0 ].As< Napi::Object >() )->pMPVariable;
        is_lhs_ok      = true;
    }

    LinearExpr LinearExpr_rhs;
    bool       is_rhs_ok = false;

    if ( info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        LinearExpr_rhs = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() )->pLinearExpr;
        is_rhs_ok      = true;
    }
    else if ( info[ 1 ].IsNumber() )
    {
        LinearExpr_rhs = LinearExpr( info[ 1 ].As< Napi::Number >().DoubleValue() );
        is_rhs_ok      = true;
    }
    else if ( info[ 1 ].IsObject()
              && info[ 1 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        LinearExpr_rhs = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 1 ].As< Napi::Object >() )->pMPVariable;
        is_rhs_ok      = true;
    }

    if ( is_lhs_ok && is_rhs_ok )
    {
        auto pLinearRange = new LinearRange( LinearExpr_lhs == LinearExpr_rhs );
        auto external     = Napi::External< LinearRange >::New( info.Env(), pLinearRange );
        return GLinearRange::constructor.New( { external } );
    }

    ThrowJsError( operations_research::operator_equals : Invalid argument );
    return info.Env().Undefined();
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
    bool       is_lhs_ok = false;

    if ( info[ 0 ].IsObject()
         && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        LinearExpr_lhs = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 0 ].As< Napi::Object >() )->pLinearExpr;
        is_lhs_ok      = true;
    }
    else if ( info[ 0 ].IsNumber() )
    {
        LinearExpr_lhs = LinearExpr( info[ 0 ].As< Napi::Number >().DoubleValue() );
        is_lhs_ok      = true;
    }
    else if ( info[ 0 ].IsObject()
              && info[ 0 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        LinearExpr_lhs = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 0 ].As< Napi::Object >() )->pMPVariable;
        is_lhs_ok      = true;
    }

    LinearExpr LinearExpr_rhs;
    bool       is_rhs_ok = false;

    if ( info[ 1 ].IsObject()
         && info[ 1 ].As< Napi::Object >().InstanceOf( GLinearExpr::constructor.Value() ) )
    {
        LinearExpr_rhs = *Napi::ObjectWrap< GLinearExpr >::Unwrap( info[ 1 ].As< Napi::Object >() )->pLinearExpr;
        is_rhs_ok      = true;
    }
    else if ( info[ 1 ].IsNumber() )
    {
        LinearExpr_rhs = LinearExpr( info[ 1 ].As< Napi::Number >().DoubleValue() );
        is_rhs_ok      = true;
    }
    else if ( info[ 1 ].IsObject()
              && info[ 1 ].As< Napi::Object >().InstanceOf( GMPVariable::constructor.Value() ) )
    {
        LinearExpr_rhs = Napi::ObjectWrap< GMPVariable >::Unwrap( info[ 1 ].As< Napi::Object >() )->pMPVariable;
        is_rhs_ok      = true;
    }

    if ( is_lhs_ok && is_rhs_ok )
    {
        auto pLinearRange = new LinearRange( LinearExpr_lhs >= LinearExpr_rhs );
        auto external     = Napi::External< LinearRange >::New( info.Env(), pLinearRange );
        return GLinearRange::constructor.New( { external } );
    }

    ThrowJsError( operations_research::operator_greater_equals : Invalid argument );
    return info.Env().Undefined();
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
