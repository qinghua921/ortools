#pragma once


#include "commonheader.hpp"
#include "GVariable.hpp"
#include "GLinearConstraint.hpp"
#include "ortools/math_opt/cpp/math_opt.h"

namespace operations_research
{
namespace math_opt
{
    class GModel : public Napi::ObjectWrap< GModel >
    {
    public:
        static Napi::FunctionReference constructor;
        Model*                         pModel = nullptr;
        GModel( const Napi::CallbackInfo& info );
        ~GModel();
        static Napi::Object Init( Napi::Env env, Napi::Object exports );

        Napi::Value AddBinaryVariable( const Napi::CallbackInfo& info );
        Napi::Value AddContinuousVariable( const Napi::CallbackInfo& info );
        Napi::Value AddLinearConstraint( const Napi::CallbackInfo& info );
    };
};  // namespace math_opt
};  // namespace operations_research

Napi::FunctionReference operations_research::math_opt::GModel::constructor;

inline operations_research::math_opt::GModel::GModel( const Napi::CallbackInfo& info )
    : Napi::ObjectWrap< GModel >( info )
{
    if ( info.Length() == 1 && info[ 0 ].IsExternal() )
    {
        auto external = info[ 0 ].As< Napi::External< Model > >();
        pModel        = dynamic_cast< Model* >( external.Data() );
        if ( pModel != nullptr ) return;
    }

    //     explicit Model( absl::string_view name = "" );
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string name = info[ 0 ].As< Napi::String >().Utf8Value();
        pModel           = new Model( name );
        return;
    }

    ThrowJsError( operations_research::GModel::GModel : Invalid argument );
}

inline operations_research::math_opt::GModel::~GModel()
{
    delete pModel;
}

inline Napi::Object operations_research::math_opt::GModel::Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );
    Napi::Function    func = DefineClass(
        env, "Model",
        {
            InstanceMethod( "AddBinaryVariable", &GModel::AddBinaryVariable ),
            InstanceMethod( "AddContinuousVariable", &GModel::AddContinuousVariable ),
            InstanceMethod( "AddLinearConstraint", &GModel::AddLinearConstraint ),
        } );
    constructor = Napi::Persistent( func );
    constructor.SuppressDestruct();
    exports.Set( Napi::String::New( env, "Model" ), func );
    return exports;
}

inline Napi::Value operations_research::math_opt::GModel::AddLinearConstraint( const Napi::CallbackInfo& info )
{
    //     inline LinearConstraint AddLinearConstraint( absl::string_view name = "" );
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string name     = info[ 0 ].As< Napi::String >().Utf8Value();
        auto        cons     = pModel->AddLinearConstraint( name );
        auto        external = Napi::External< LinearConstraint >::New( info.Env(), new LinearConstraint( cons ) );
        return GLinearConstraint::constructor.New( { external } );
    }

    //     inline LinearConstraint AddLinearConstraint( double            lower_bound,
    //                                                  double            upper_bound,
    //                                                  absl::string_view name = "" );
    if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
    {
        double      lower_bound = info[ 0 ].As< Napi::Number >().DoubleValue();
        double      upper_bound = info[ 1 ].As< Napi::Number >().DoubleValue();
        std::string name        = info[ 2 ].As< Napi::String >().Utf8Value();
        auto        cons        = pModel->AddLinearConstraint( lower_bound, upper_bound, name );
        auto        external    = Napi::External< LinearConstraint >::New( info.Env(), new LinearConstraint( cons ) );
        return GLinearConstraint::constructor.New( { external } );
    }

    ThrowJsError( operations_research::math_opt::GModel::AddLinearConstraint : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::math_opt::GModel::AddContinuousVariable( const Napi::CallbackInfo& info )
{
    //     inline Variable AddContinuousVariable( double lower_bound, double upper_bound,
    //                                            absl::string_view name = "" );
    if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
    {
        double      lower_bound = info[ 0 ].As< Napi::Number >().DoubleValue();
        double      upper_bound = info[ 1 ].As< Napi::Number >().DoubleValue();
        std::string name        = info[ 2 ].As< Napi::String >().Utf8Value();
        auto        var         = pModel->AddContinuousVariable( lower_bound, upper_bound, name );
        auto        external    = Napi::External< Variable >::New( info.Env(), new Variable( var ) );
        return GVariable::constructor.New( { external } );
    }

    ThrowJsError( operations_research::math_opt::GModel::AddContinuousVariable : Invalid argument );
    return info.Env().Undefined();
}

inline Napi::Value operations_research::math_opt::GModel::AddBinaryVariable( const Napi::CallbackInfo& info )
{
    //     inline Variable AddBinaryVariable( absl::string_view name = "" );
    if ( info.Length() == 1 && info[ 0 ].IsString() )
    {
        std::string name     = info[ 0 ].As< Napi::String >().Utf8Value();
        auto        var      = pModel->AddBinaryVariable( name );
        auto        external = Napi::External< Variable >::New( info.Env(), new Variable( var ) );
        return GVariable::constructor.New( { external } );
    }

    ThrowJsError( operations_research::math_opt::GModel::AddBinaryVariable : Invalid argument );
    return info.Env().Undefined();
}
