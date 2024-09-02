#pragma once

#include <napi.h>
#include "ortools/linear_solver/linear_solver.h"
#include "ortools/sat/cp_model.h"
#include "ortools/graph/assignment.h"
#include "ortools/graph/min_cost_flow.h"

// ThrowAsJavaScriptException
#define ThrowJsError( errinfo ) \
    Napi::Error::New( info.Env(), ( char* )u8#errinfo ).ThrowAsJavaScriptException()

namespace operations_research
{
class GMPModelRequest : public Napi::ObjectWrap< GMPModelRequest >
{
public:
    static Napi::FunctionReference constructor;
    MPModelRequest*                pMPModelRequest = nullptr;
    GMPModelRequest( const Napi::CallbackInfo& info );
    ~GMPModelRequest();

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPModelRequest",
            {} );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPModelRequest" ), func );
        return exports;
    }
};

Napi::FunctionReference GMPModelRequest::constructor;

class GMPSolutionResponse : public Napi::ObjectWrap< GMPSolutionResponse >
{
public:
    static Napi::FunctionReference constructor;
    MPSolutionResponse*            pMPSolutionResponse = nullptr;
    GMPSolutionResponse( const Napi::CallbackInfo& info );
    ~GMPSolutionResponse();

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPSolutionResponse",
            {} );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPSolutionResponse" ), func );
        return exports;
    }
};

Napi::FunctionReference GMPSolutionResponse::constructor;

class GMPModelProto : public Napi::ObjectWrap< GMPModelProto >
{
public:
    static Napi::FunctionReference constructor;
    MPModelProto*                  pMPModelProto = nullptr;
    GMPModelProto( const Napi::CallbackInfo& info );
    ~GMPModelProto();

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPModelProto",
            {} );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPModelProto" ), func );
        return exports;
    }
};

Napi::FunctionReference GMPModelProto::constructor;

class GMPSolverParameters : public Napi::ObjectWrap< GMPSolverParameters >
{
public:
    static Napi::FunctionReference constructor;
    MPSolverParameters*            pMPSolverParameters = nullptr;
    GMPSolverParameters( const Napi::CallbackInfo& info );
    ~GMPSolverParameters();

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPSolverParameters",
            {} );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPSolverParameters" ), func );
        return exports;
    }
};

Napi::FunctionReference GMPSolverParameters::constructor;

class GMPVariable : public Napi::ObjectWrap< GMPVariable >
{
public:
    static Napi::FunctionReference constructor;
    MPVariable*                    pMPVariable = nullptr;
    GMPVariable( const Napi::CallbackInfo& info );
    ~GMPVariable();

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPVariable",
            {
                InstanceMethod( "name", &GMPVariable::name ),
                InstanceMethod( "SetInteger", &GMPVariable::SetInteger ),
                InstanceMethod( "integer", &GMPVariable::integer ),
                InstanceMethod( "solution_value", &GMPVariable::solution_value ),
                InstanceMethod( "index", &GMPVariable::index ),
                InstanceMethod( "lb", &GMPVariable::lb ),
                InstanceMethod( "ub", &GMPVariable::ub ),
                InstanceMethod( "SetLB", &GMPVariable::SetLB ),
                InstanceMethod( "SetUB", &GMPVariable::SetUB ),
                InstanceMethod( "SetBounds", &GMPVariable::SetBounds ),
                InstanceMethod( "unrounded_solution_value", &GMPVariable::unrounded_solution_value ),
                InstanceMethod( "reduced_cost", &GMPVariable::reduced_cost ),
                InstanceMethod( "basis_status", &GMPVariable::basis_status ),
                InstanceMethod( "branching_priority", &GMPVariable::branching_priority ),
                InstanceMethod( "SetBranchingPriority", &GMPVariable::SetBranchingPriority ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPVariable" ), func );
        return exports;
    }

    // const std::string& name() const;
    Napi::Value name( const Napi::CallbackInfo& info );
    // void SetInteger( bool integer );
    Napi::Value SetInteger( const Napi::CallbackInfo& info );
    // bool integer() const;
    Napi::Value integer( const Napi::CallbackInfo& info );
    // double solution_value() const;
    Napi::Value solution_value( const Napi::CallbackInfo& info );
    // int index() const;
    Napi::Value index( const Napi::CallbackInfo& info );
    // double lb() const;
    Napi::Value lb( const Napi::CallbackInfo& info );
    // double ub() const;
    Napi::Value ub( const Napi::CallbackInfo& info );
    // void SetLB( double lb );
    Napi::Value SetLB( const Napi::CallbackInfo& info );
    // void SetUB( double ub );
    Napi::Value SetUB( const Napi::CallbackInfo& info );
    // void SetBounds( double lb, double ub );
    Napi::Value SetBounds( const Napi::CallbackInfo& info );
    // double unrounded_solution_value() const;
    Napi::Value unrounded_solution_value( const Napi::CallbackInfo& info );
    // double reduced_cost() const;
    Napi::Value reduced_cost( const Napi::CallbackInfo& info );
    // MPSolver::BasisStatus basis_status() const;
    Napi::Value basis_status( const Napi::CallbackInfo& info );
    // int branching_priority() const;
    Napi::Value branching_priority( const Napi::CallbackInfo& info );
    // void SetBranchingPriority( int priority );
    Napi::Value SetBranchingPriority( const Napi::CallbackInfo& info );
};

Napi::FunctionReference GMPVariable::constructor;

class GLinearExpr : public Napi::ObjectWrap< GLinearExpr >
{
public:
    static Napi::FunctionReference constructor;
    LinearExpr*                    pLinearExpr = nullptr;
    GLinearExpr( const Napi::CallbackInfo& info );
    ~GLinearExpr();

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "LinearExpr",
            {
                InstanceMethod( "operator_plus_equals", &GLinearExpr::operator_plus_equals ),
                InstanceMethod( "operator_minus_equals", &GLinearExpr::operator_minus_equals ),
                InstanceMethod( "operator_times_equals", &GLinearExpr::operator_times_equals ),
                InstanceMethod( "operator_divide_equals", &GLinearExpr::operator_divide_equals ),
                InstanceMethod( "operator_negate", &GLinearExpr::operator_negate ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "LinearExpr" ), func );
        return exports;
    }

    Napi::Value operator_plus_equals( const Napi::CallbackInfo& info );    // LinearExpr& operator+=( const LinearExpr& rhs );
    Napi::Value operator_minus_equals( const Napi::CallbackInfo& info );   // LinearExpr& operator-=( const LinearExpr& rhs );
    Napi::Value operator_times_equals( const Napi::CallbackInfo& info );   // LinearExpr& operator*=( double rhs );
    Napi::Value operator_divide_equals( const Napi::CallbackInfo& info );  // LinearExpr& operator/=( double rhs );
    Napi::Value operator_negate( const Napi::CallbackInfo& info );         // LinearExpr  operator-() const;
};

Napi::FunctionReference GLinearExpr::constructor;

class GLinearRange : public Napi::ObjectWrap< GLinearRange >
{
public:
    static Napi::FunctionReference constructor;
    LinearRange*                   pLinearRange = nullptr;
    GLinearRange( const Napi::CallbackInfo& info );
    ~GLinearRange();

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "LinearRange",
            {} );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "LinearRange" ), func );
        return exports;
    }
};

Napi::FunctionReference GLinearRange::constructor;

// LinearRange operator<=( const LinearExpr& lhs, const LinearExpr& rhs );
Napi::Value operator_less_equals( const Napi::CallbackInfo& info );
// LinearRange operator==( const LinearExpr& lhs, const LinearExpr& rhs );
Napi::Value operator_equals( const Napi::CallbackInfo& info );
// LinearRange operator>=( const LinearExpr& lhs, const LinearExpr& rhs );
Napi::Value operator_greater_equals( const Napi::CallbackInfo& info );

class GMPConstraint : public Napi::ObjectWrap< GMPConstraint >
{
public:
    static Napi::FunctionReference constructor;
    MPConstraint*                  pMPConstraint = nullptr;
    GMPConstraint( const Napi::CallbackInfo& info );
    ~GMPConstraint();

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPConstraint",
            {
                InstanceMethod( "SetCoefficient", &GMPConstraint::SetCoefficient ),
            } );

        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPConstraint" ), func );
        return exports;
    }

    Napi::Value SetCoefficient( const Napi::CallbackInfo& info );  // void SetCoefficient( const MPVariable* const var, double coeff );
};

Napi::FunctionReference GMPConstraint::constructor;

class GMPObjective : public Napi::ObjectWrap< GMPObjective >
{
public:
    static Napi::FunctionReference constructor;
    MPObjective*                   pMPObjective = nullptr;
    GMPObjective( const Napi::CallbackInfo& info );
    ~GMPObjective();

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPObjective",
            {
                InstanceMethod( "SetCoefficient", &GMPObjective::SetCoefficient ),
                InstanceMethod( "SetMinimization", &GMPObjective::SetMinimization ),
                InstanceMethod( "Value", &GMPObjective::Value ),
                InstanceMethod( "Clear", &GMPObjective::Clear ),
                InstanceMethod( "GetCoefficient", &GMPObjective::GetCoefficient ),
                InstanceMethod( "terms", &GMPObjective::terms ),
                InstanceMethod( "SetOffset", &GMPObjective::SetOffset ),
                InstanceMethod( "offset", &GMPObjective::offset ),
                InstanceMethod( "OptimizeLinearExpr", &GMPObjective::OptimizeLinearExpr ),
                InstanceMethod( "MaximizeLinearExpr", &GMPObjective::MaximizeLinearExpr ),
                InstanceMethod( "MinimizeLinearExpr", &GMPObjective::MinimizeLinearExpr ),
                InstanceMethod( "AddLinearExpr", &GMPObjective::AddLinearExpr ),
                InstanceMethod( "SetOptimizationDirection", &GMPObjective::SetOptimizationDirection ),
                InstanceMethod( "SetMaximization", &GMPObjective::SetMaximization ),
                InstanceMethod( "maximization", &GMPObjective::maximization ),
                InstanceMethod( "minimization", &GMPObjective::minimization ),
                InstanceMethod( "BestBound", &GMPObjective::BestBound ),
            } );

        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "MPObjective" ), func );
        return exports;
    }

    // void SetCoefficient( const MPVariable* const var, double coeff );
    Napi::Value SetCoefficient( const Napi::CallbackInfo& info );
    // void SetMinimization();
    Napi::Value SetMinimization( const Napi::CallbackInfo& info );
    // double Value() const;
    Napi::Value Value( const Napi::CallbackInfo& info );
    // void Clear();
    Napi::Value Clear( const Napi::CallbackInfo& info );
    // double GetCoefficient( const MPVariable* const var ) const;
    Napi::Value GetCoefficient( const Napi::CallbackInfo& info );
    // const absl::flat_hash_map< const MPVariable*, double >& terms() const;
    Napi::Value terms( const Napi::CallbackInfo& info );
    // void SetOffset( double value );
    Napi::Value SetOffset( const Napi::CallbackInfo& info );
    // double offset() const;
    Napi::Value offset( const Napi::CallbackInfo& info );
    // void OptimizeLinearExpr( const LinearExpr& linear_expr, bool is_maximization );
    Napi::Value OptimizeLinearExpr( const Napi::CallbackInfo& info );
    // void MaximizeLinearExpr( const LinearExpr& linear_expr );
    Napi::Value MaximizeLinearExpr( const Napi::CallbackInfo& info );
    // void MinimizeLinearExpr( const LinearExpr& linear_expr );
    Napi::Value MinimizeLinearExpr( const Napi::CallbackInfo& info );
    //  void AddLinearExpr( const LinearExpr& linear_expr );
    Napi::Value AddLinearExpr( const Napi::CallbackInfo& info );
    // void SetOptimizationDirection( bool maximize );
    Napi::Value SetOptimizationDirection( const Napi::CallbackInfo& info );
    // void SetMaximization();
    Napi::Value SetMaximization( const Napi::CallbackInfo& info );
    // bool maximization() const;
    Napi::Value maximization( const Napi::CallbackInfo& info );
    // bool minimization() const;
    Napi::Value minimization( const Napi::CallbackInfo& info );
    // double BestBound() const;
    Napi::Value BestBound( const Napi::CallbackInfo& info );
};

Napi::FunctionReference GMPObjective::constructor;

class GSimpleLinearSumAssignment : public Napi::ObjectWrap< GSimpleLinearSumAssignment >
{
public:
    static Napi::FunctionReference constructor;
    SimpleLinearSumAssignment*     pSimpleLinearSumAssignment = nullptr;
    GSimpleLinearSumAssignment( const Napi::CallbackInfo& info );
    ~GSimpleLinearSumAssignment();

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );

        Napi::Object status = Napi::Object::New( env );
        status.Set( Napi::String::New( env, "OPTIMAL" ), Napi::Number::New( env, SimpleLinearSumAssignment::OPTIMAL ) );
        status.Set( Napi::String::New( env, "INFEASIBLE" ), Napi::Number::New( env, SimpleLinearSumAssignment::INFEASIBLE ) );
        status.Set( Napi::String::New( env, "POSSIBLE_OVERFLOW" ), Napi::Number::New( env, SimpleLinearSumAssignment::POSSIBLE_OVERFLOW ) );

        Napi::Function func = DefineClass(
            env, "SimpleLinearSumAssignment",
            {
                StaticValue( "Status", status ),
                InstanceMethod( "AddArcWithCost", &GSimpleLinearSumAssignment::AddArcWithCost ),
                InstanceMethod( "Solve", &GSimpleLinearSumAssignment::Solve ),
                InstanceMethod( "NumNodes", &GSimpleLinearSumAssignment::NumNodes ),
                InstanceMethod( "NumArcs", &GSimpleLinearSumAssignment::NumArcs ),
                InstanceMethod( "LeftNode", &GSimpleLinearSumAssignment::LeftNode ),
                InstanceMethod( "RightNode", &GSimpleLinearSumAssignment::RightNode ),
                InstanceMethod( "Cost", &GSimpleLinearSumAssignment::Cost ),
                InstanceMethod( "OptimalCost", &GSimpleLinearSumAssignment::OptimalCost ),
                InstanceMethod( "RightMate", &GSimpleLinearSumAssignment::RightMate ),
                InstanceMethod( "AssignmentCost", &GSimpleLinearSumAssignment::AssignmentCost ),
            } );

        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "SimpleLinearSumAssignment" ), func );
        return exports;
    }

    // ArcIndex AddArcWithCost( NodeIndex left_node, NodeIndex right_node, CostValue cost );
    Napi::Value AddArcWithCost( const Napi::CallbackInfo& info );
    // Status Solve();
    Napi::Value Solve( const Napi::CallbackInfo& info );
    //  NodeIndex NumNodes() const;
    Napi::Value NumNodes( const Napi::CallbackInfo& info );
    // ArcIndex NumArcs() const;
    Napi::Value NumArcs( const Napi::CallbackInfo& info );
    // NodeIndex LeftNode( ArcIndex arc ) const;
    Napi::Value LeftNode( const Napi::CallbackInfo& info );
    // NodeIndex RightNode( ArcIndex arc ) const;
    Napi::Value RightNode( const Napi::CallbackInfo& info );
    // CostValue Cost( ArcIndex arc ) const;
    Napi::Value Cost( const Napi::CallbackInfo& info );
    // CostValue OptimalCost() const;
    Napi::Value OptimalCost( const Napi::CallbackInfo& info );
    // NodeIndex RightMate( NodeIndex left_node ) const;
    Napi::Value RightMate( const Napi::CallbackInfo& info );
    // CostValue AssignmentCost( NodeIndex left_node ) const;
    Napi::Value AssignmentCost( const Napi::CallbackInfo& info );
};

Napi::FunctionReference GSimpleLinearSumAssignment::constructor;

class GSimpleMinCostFlow : public Napi::ObjectWrap< GSimpleMinCostFlow >
{
public:
    static Napi::FunctionReference constructor;
    SimpleMinCostFlow*             pSimpleMinCostFlow = nullptr;
    GSimpleMinCostFlow( const Napi::CallbackInfo& info );
    ~GSimpleMinCostFlow();

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );

        Napi::Object status = Napi::Object::New( env );
        status.Set( Napi::String::New( env, "NOT_SOLVED" ), Napi::Number::New( env, SimpleMinCostFlow::NOT_SOLVED ) );
        status.Set( Napi::String::New( env, "OPTIMAL" ), Napi::Number::New( env, SimpleMinCostFlow::OPTIMAL ) );
        status.Set( Napi::String::New( env, "FEASIBLE" ), Napi::Number::New( env, SimpleMinCostFlow::FEASIBLE ) );
        status.Set( Napi::String::New( env, "INFEASIBLE" ), Napi::Number::New( env, SimpleMinCostFlow::INFEASIBLE ) );
        status.Set( Napi::String::New( env, "UNBALANCED" ), Napi::Number::New( env, SimpleMinCostFlow::UNBALANCED ) );
        status.Set( Napi::String::New( env, "BAD_RESULT" ), Napi::Number::New( env, SimpleMinCostFlow::BAD_RESULT ) );
        status.Set( Napi::String::New( env, "BAD_COST_RANGE" ), Napi::Number::New( env, SimpleMinCostFlow::BAD_COST_RANGE ) );

        Napi::Function func = DefineClass(
            env, "SimpleMinCostFlow",
            {
                StaticValue( "Status", status ),
                InstanceMethod( "AddArcWithCapacityAndUnitCost", &GSimpleMinCostFlow::AddArcWithCapacityAndUnitCost ),
                InstanceMethod( "SetNodeSupply", &GSimpleMinCostFlow::SetNodeSupply ),
                InstanceMethod( "Solve", &GSimpleMinCostFlow::Solve ),
                InstanceMethod( "SolveMaxFlowWithMinCost", &GSimpleMinCostFlow::SolveMaxFlowWithMinCost ),
                InstanceMethod( "OptimalCost", &GSimpleMinCostFlow::OptimalCost ),
                InstanceMethod( "MaximumFlow", &GSimpleMinCostFlow::MaximumFlow ),
                InstanceMethod( "Flow", &GSimpleMinCostFlow::Flow ),
                InstanceMethod( "NumNodes", &GSimpleMinCostFlow::NumNodes ),
                InstanceMethod( "NumArcs", &GSimpleMinCostFlow::NumArcs ),
                InstanceMethod( "Tail", &GSimpleMinCostFlow::Tail ),
                InstanceMethod( "Head", &GSimpleMinCostFlow::Head ),
                InstanceMethod( "Capacity", &GSimpleMinCostFlow::Capacity ),
                InstanceMethod( "Supply", &GSimpleMinCostFlow::Supply ),
                InstanceMethod( "UnitCost", &GSimpleMinCostFlow::UnitCost ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "SimpleMinCostFlow" ), func );
        return exports;
    }

    // ArcIndex AddArcWithCapacityAndUnitCost( NodeIndex tail, NodeIndex head, FlowQuantity capacity, CostValue unit_cost );
    Napi::Value AddArcWithCapacityAndUnitCost( const Napi::CallbackInfo& info );
    //  void SetNodeSupply( NodeIndex node, FlowQuantity supply );
    Napi::Value SetNodeSupply( const Napi::CallbackInfo& info );
    // Status Solve();
    Napi::Value Solve( const Napi::CallbackInfo& info );
    // Status SolveMaxFlowWithMinCost();
    Napi::Value SolveMaxFlowWithMinCost( const Napi::CallbackInfo& info );
    // CostValue OptimalCost() const;
    Napi::Value OptimalCost( const Napi::CallbackInfo& info );
    // FlowQuantity MaximumFlow() const;
    Napi::Value MaximumFlow( const Napi::CallbackInfo& info );
    // FlowQuantity Flow( ArcIndex arc ) const;
    Napi::Value Flow( const Napi::CallbackInfo& info );
    // NodeIndex    NumNodes() const;
    Napi::Value NumNodes( const Napi::CallbackInfo& info );
    // ArcIndex     NumArcs() const;
    Napi::Value NumArcs( const Napi::CallbackInfo& info );
    // NodeIndex    Tail( ArcIndex arc ) const;
    Napi::Value Tail( const Napi::CallbackInfo& info );
    // NodeIndex    Head( ArcIndex arc ) const;
    Napi::Value Head( const Napi::CallbackInfo& info );
    // FlowQuantity Capacity( ArcIndex arc ) const;
    Napi::Value Capacity( const Napi::CallbackInfo& info );
    // FlowQuantity Supply( NodeIndex node ) const;
    Napi::Value Supply( const Napi::CallbackInfo& info );
    // CostValue    UnitCost( ArcIndex arc ) const;
    Napi::Value UnitCost( const Napi::CallbackInfo& info );
};

Napi::FunctionReference GSimpleMinCostFlow::constructor;

class GDomain : public Napi::ObjectWrap< GDomain >
{
public:
    static Napi::FunctionReference constructor;
    Domain*                        pDomain = nullptr;
    GDomain( const Napi::CallbackInfo& info );
    ~GDomain();

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "Domain",
            {} );

        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( Napi::String::New( env, "Domain" ), func );
        return exports;
    }
};

Napi::FunctionReference GDomain::constructor;

namespace sat
{
    class GCpModelBuilder : public Napi::ObjectWrap< GCpModelBuilder >
    {
    public:
        static Napi::FunctionReference constructor;
        CpModelBuilder*                pCpModelBuilder = nullptr;
        GCpModelBuilder( const Napi::CallbackInfo& info );
        ~GCpModelBuilder();

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "CpModelBuilder",
                {
                    InstanceMethod( "NewBoolVar", &GCpModelBuilder::NewBoolVar ),
                    InstanceMethod( "AddAtMostOne", &GCpModelBuilder::AddAtMostOne ),
                    InstanceMethod( "AddExactlyOne", &GCpModelBuilder::AddExactlyOne ),
                    InstanceMethod( "AddEquality", &GCpModelBuilder::AddEquality ),
                    InstanceMethod( "AddAllowedAssignments", &GCpModelBuilder::AddAllowedAssignments ),
                    InstanceMethod( "Minimize", &GCpModelBuilder::Minimize ),
                    InstanceMethod( "Build", &GCpModelBuilder::Build ),
                    InstanceMethod( "NewIntVar", &GCpModelBuilder::NewIntVar ),
                    InstanceMethod( "AddLessOrEqual", &GCpModelBuilder::AddLessOrEqual ),
                    InstanceMethod( "Maximize", &GCpModelBuilder::Maximize ),
                } );

            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "CpModelBuilder" ), func );
            return exports;
        }

        // BoolVar NewBoolVar();
        Napi::Value NewBoolVar( const Napi::CallbackInfo& info );
        // Constraint AddAtMostOne( absl::Span< const BoolVar > literals );
        Napi::Value AddAtMostOne( const Napi::CallbackInfo& info );
        // Constraint AddExactlyOne( absl::Span< const BoolVar > literals );
        Napi::Value AddExactlyOne( const Napi::CallbackInfo& info );
        // Constraint AddEquality( const LinearExpr& left, const LinearExpr& right );
        Napi::Value AddEquality( const Napi::CallbackInfo& info );
        // TableConstraint AddAllowedAssignments( absl::Span< const IntVar > vars );
        Napi::Value AddAllowedAssignments( const Napi::CallbackInfo& info );
        // void Minimize( const LinearExpr& expr );
        Napi::Value Minimize( const Napi::CallbackInfo& info );
        // const CpModelProto& Build() const
        Napi::Value Build( const Napi::CallbackInfo& info );
        // IntVar NewIntVar( const Domain& domain );
        Napi::Value NewIntVar( const Napi::CallbackInfo& info );
        // Constraint AddLessOrEqual( const LinearExpr& left, const LinearExpr& right );
        Napi::Value AddLessOrEqual( const Napi::CallbackInfo& info );
        // void Maximize( const LinearExpr& expr );
        Napi::Value Maximize( const Napi::CallbackInfo& info );

    };  // namespace sat

    Napi::FunctionReference GCpModelBuilder::constructor;

    class GBoolVar : public Napi::ObjectWrap< GBoolVar >
    {
    public:
        static Napi::FunctionReference constructor;
        BoolVar*                       pBoolVar = nullptr;
        GBoolVar( const Napi::CallbackInfo& info );
        ~GBoolVar();

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "BoolVar",
                {
                    InstanceMethod( "WithName", &GBoolVar::WithName ),
                } );

            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "BoolVar" ), func );
            return exports;
        }

        Napi::Value WithName( const Napi::CallbackInfo& info );  // BoolVar WithName( const std::string& name );
    };

    Napi::FunctionReference GBoolVar::constructor;

    class GConstraint : public Napi::ObjectWrap< GConstraint >
    {
    public:
        static Napi::FunctionReference constructor;
        Constraint*                    pConstraint = nullptr;
        GConstraint( const Napi::CallbackInfo& info );
        ~GConstraint();

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "Constraint",
                {} );

            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "Constraint" ), func );
            return exports;
        }
    };

    Napi::FunctionReference GConstraint::constructor;

    class GIntVar : public Napi::ObjectWrap< GIntVar >
    {
    public:
        static Napi::FunctionReference constructor;
        IntVar*                        pIntVar = nullptr;
        GIntVar( const Napi::CallbackInfo& info );
        ~GIntVar();

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "IntVar",
                {
                    InstanceMethod( "ToBoolVar", &GIntVar::ToBoolVar ),
                    InstanceMethod( "WithName", &GIntVar::WithName ),
                    InstanceMethod( "Name", &GIntVar::Name ),
                    InstanceMethod( "operator_equals", &GIntVar::operator_equals ),
                    InstanceMethod( "operator_not_equals", &GIntVar::operator_not_equals ),
                    InstanceMethod( "Domain", &GIntVar::Domain ),
                    InstanceMethod( "DebugString", &GIntVar::DebugString ),
                    InstanceMethod( "index", &GIntVar::index ),
                } );

            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "IntVar" ), func );
            return exports;
        }

        // BoolVar ToBoolVar() const;
        Napi::Value ToBoolVar( const Napi::CallbackInfo& info );
        // IntVar WithName( const std::string& name )
        Napi::Value WithName( const Napi::CallbackInfo& info );
        // std::string Name() const;
        Napi::Value Name( const Napi::CallbackInfo& info );
        // bool operator==( const IntVar& other ) const;
        Napi::Value operator_equals( const Napi::CallbackInfo& info );
        // bool operator!=( const IntVar& other ) const;
        Napi::Value operator_not_equals( const Napi::CallbackInfo& info );
        // ::operations_research::Domain Domain() const;
        Napi::Value Domain( const Napi::CallbackInfo& info );
        // std::string DebugString() const;
        Napi::Value DebugString( const Napi::CallbackInfo& info );
        // int index() const;
        Napi::Value index( const Napi::CallbackInfo& info );
    };

    Napi::FunctionReference GIntVar::constructor;

    class GLinearExpr : public Napi::ObjectWrap< GLinearExpr >
    {
    public:
        static Napi::FunctionReference constructor;
        LinearExpr*                    pLinearExpr = nullptr;
        GLinearExpr( const Napi::CallbackInfo& info );
        ~GLinearExpr();

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "LinearExpr",
                {
                    InstanceMethod( "operator_plus_equals", &GLinearExpr::operator_plus_equals ),
                    InstanceMethod( "operator_minus_equals", &GLinearExpr::operator_minus_equals ),
                    InstanceMethod( "operator_times_equals", &GLinearExpr::operator_times_equals ),
                } );

            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "LinearExpr" ), func );
            return exports;
        }

        Napi::Value operator_plus_equals( const Napi::CallbackInfo& info );   // LinearExpr& operator+=( const LinearExpr& other );
        Napi::Value operator_minus_equals( const Napi::CallbackInfo& info );  // LinearExpr& operator-=( const LinearExpr& other );
        Napi::Value operator_times_equals( const Napi::CallbackInfo& info );  // LinearExpr& operator*=( int64_t factor );
    };

    Napi::FunctionReference GLinearExpr::constructor;

    class GTableConstraint : public Napi::ObjectWrap< GTableConstraint >
    {
    public:
        static Napi::FunctionReference constructor;
        TableConstraint*               pTableConstraint = nullptr;
        GTableConstraint( const Napi::CallbackInfo& info );
        ~GTableConstraint();

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "TableConstraint",
                {
                    InstanceMethod( "AddTuple", &GTableConstraint::AddTuple ),
                } );

            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "TableConstraint" ), func );
            return exports;
        }

        Napi::Value AddTuple( const Napi::CallbackInfo& info );  // void AddTuple( absl::Span< const int64_t > tuple );
    };

    Napi::FunctionReference GTableConstraint::constructor;

    // inline LinearExpr operator+( const LinearExpr& lhs, const LinearExpr& rhs )
    Napi::Value Goperator_plus( const Napi::CallbackInfo& info );
    // inline LinearExpr operator-( const LinearExpr& lhs, const LinearExpr& rhs )
    Napi::Value Goperator_minus( const Napi::CallbackInfo& info );
    // inline LinearExpr operator*( LinearExpr expr, int64_t factor )
    // inline LinearExpr operator*( int64_t factor, LinearExpr expr )
    Napi::Value Goperator_times( const Napi::CallbackInfo& info );
    // CpSolverResponse Solve( const CpModelProto& model_proto );
    Napi::Value GSolve( const Napi::CallbackInfo& info );
    // int64_t SolutionIntegerValue( const CpSolverResponse& r, const LinearExpr& expr );
    Napi::Value GSolutionIntegerValue( const Napi::CallbackInfo& info );

    class GCpModelProto : public Napi::ObjectWrap< GCpModelProto >
    {
    public:
        static Napi::FunctionReference constructor;
        CpModelProto*                  pCpModelProto = nullptr;
        GCpModelProto( const Napi::CallbackInfo& info );
        ~GCpModelProto();

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "CpModelProto",
                {} );

            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "CpModelProto" ), func );
            return exports;
        }
    };

    Napi::FunctionReference GCpModelProto::constructor;

    class GCpSolverResponse : public Napi::ObjectWrap< GCpSolverResponse >
    {
    public:
        static Napi::FunctionReference constructor;
        CpSolverResponse*              pCpSolverResponse = nullptr;
        GCpSolverResponse( const Napi::CallbackInfo& info );
        ~GCpSolverResponse();

        static Napi::Object Init( Napi::Env env, Napi::Object exports )
        {
            Napi::HandleScope scope( env );
            Napi::Function    func = DefineClass(
                env, "CpSolverResponse",
                {
                    InstanceMethod( "status", &GCpSolverResponse::status ),
                    InstanceMethod( "objective_value", &GCpSolverResponse::objective_value ),
                } );

            constructor = Napi::Persistent( func );
            constructor.SuppressDestruct();
            exports.Set( Napi::String::New( env, "CpSolverResponse" ), func );
            return exports;
        }

        // operations_research::sat::CpSolverStatus status() const;
        Napi::Value status( const Napi::CallbackInfo& info );

        // double objective_value() const;
        Napi::Value objective_value( const Napi::CallbackInfo& info );
    };

    Napi::FunctionReference GCpSolverResponse::constructor;

    //  bool SolutionBooleanValue( const CpSolverResponse& r, const BoolVar& x );
    Napi::Value GSolutionBooleanValue( const Napi::CallbackInfo& info );

};  // namespace sat

};  // namespace operations_research

Napi::Object Init( Napi::Env env, Napi::Object exports )
{
    Napi::HandleScope scope( env );

    auto operations_research_sat_exports = Napi::Object::New( env );

    operations_research::sat::GCpModelBuilder::Init( env, operations_research_sat_exports );
    operations_research::sat::GBoolVar::Init( env, operations_research_sat_exports );
    operations_research::sat::GConstraint::Init( env, operations_research_sat_exports );
    operations_research::sat::GIntVar::Init( env, operations_research_sat_exports );
    operations_research::sat::GLinearExpr::Init( env, operations_research_sat_exports );
    operations_research::sat::GTableConstraint::Init( env, operations_research_sat_exports );
    operations_research::sat::GCpModelProto::Init( env, operations_research_sat_exports );
    operations_research::sat::GCpSolverResponse::Init( env, operations_research_sat_exports );

    operations_research_sat_exports.Set( "operator_plus", Napi::Function::New( env, operations_research::sat::Goperator_plus ) );
    operations_research_sat_exports.Set( "operator_minus", Napi::Function::New( env, operations_research::sat::Goperator_minus ) );
    operations_research_sat_exports.Set( "operator_times", Napi::Function::New( env, operations_research::sat::Goperator_times ) );
    operations_research_sat_exports.Set( "Solve", Napi::Function::New( env, operations_research::sat::GSolve ) );
    operations_research_sat_exports.Set( "SolutionBooleanValue", Napi::Function::New( env, operations_research::sat::GSolutionBooleanValue ) );
    operations_research_sat_exports.Set( "SolutionIntegerValue", Napi::Function::New( env, operations_research::sat::GSolutionIntegerValue ) );

    auto operations_research_sat_cp_solver_status = Napi::Object::New( env );
    operations_research_sat_cp_solver_status.Set( "UNKNOWN", Napi::Number::New( env, operations_research::sat::CpSolverStatus::UNKNOWN ) );
    operations_research_sat_cp_solver_status.Set( "MODEL_INVALID", Napi::Number::New( env, operations_research::sat::CpSolverStatus::MODEL_INVALID ) );
    operations_research_sat_cp_solver_status.Set( "FEASIBLE", Napi::Number::New( env, operations_research::sat::CpSolverStatus::FEASIBLE ) );
    operations_research_sat_cp_solver_status.Set( "INFEASIBLE", Napi::Number::New( env, operations_research::sat::CpSolverStatus::INFEASIBLE ) );
    operations_research_sat_cp_solver_status.Set( "OPTIMAL", Napi::Number::New( env, operations_research::sat::CpSolverStatus::OPTIMAL ) );
    operations_research_sat_exports.Set( "CpSolverStatus", operations_research_sat_cp_solver_status );

    auto operations_research_exports = Napi::Object::New( env );

    operations_research::GMPSolver::Init( env, operations_research_exports );
    operations_research::GMPVariable::Init( env, operations_research_exports );
    operations_research::GLinearExpr::Init( env, operations_research_exports );
    operations_research::GLinearRange::Init( env, operations_research_exports );
    operations_research::GMPConstraint::Init( env, operations_research_exports );
    operations_research::GMPObjective::Init( env, operations_research_exports );
    operations_research::GSimpleLinearSumAssignment::Init( env, operations_research_exports );
    operations_research::GSimpleMinCostFlow::Init( env, operations_research_exports );
    operations_research::GDomain::Init( env, operations_research_exports );

    operations_research_exports.Set( "operator_less_equals", Napi::Function::New( env, operations_research::operator_less_equals ) );
    operations_research_exports.Set( "operator_equals", Napi::Function::New( env, operations_research::operator_equals ) );
    operations_research_exports.Set( "operator_greater_equals", Napi::Function::New( env, operations_research::operator_greater_equals ) );

    operations_research_exports.Set( "sat", operations_research_sat_exports );

    exports.Set( "operations_research", operations_research_exports );

    return exports;
}

NODE_API_MODULE( ortools_binding, Init );
