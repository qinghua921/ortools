#pragma once

#include "or.hpp"
#include <napi.h>
#include <ortools/sat/cp_model.h>

namespace operations_research
{
namespace sat
{
class GCpModelBuilder : public Napi::ObjectWrap<GCpModelBuilder>
{
  public:
    static inline Napi::FunctionReference constructor;
    CpModelBuilder *pCpModelBuilder = nullptr;
    GCpModelBuilder(const Napi::CallbackInfo &info);
    ~GCpModelBuilder();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);

    Napi::Value SetName(const Napi::CallbackInfo &info);
    Napi::Value NewIntVar(const Napi::CallbackInfo &info);
    Napi::Value NewBoolVar(const Napi::CallbackInfo &info);
    Napi::Value NewConstant(const Napi::CallbackInfo &info);
    Napi::Value TrueVar(const Napi::CallbackInfo &info);
    Napi::Value FalseVar(const Napi::CallbackInfo &info);
    Napi::Value NewIntervalVar(const Napi::CallbackInfo &info);
    Napi::Value NewFixedSizeIntervalVar(const Napi::CallbackInfo &info);
    Napi::Value NewOptionalIntervalVar(const Napi::CallbackInfo &info);
    Napi::Value NewOptionalFixedSizeIntervalVar(const Napi::CallbackInfo &info);
    Napi::Value FixVariable(const Napi::CallbackInfo &info);
    Napi::Value AddBoolOr(const Napi::CallbackInfo &info);
    Napi::Value AddAtLeastOne(const Napi::CallbackInfo &info);
    Napi::Value AddAtMostOne(const Napi::CallbackInfo &info);
    Napi::Value AddExactlyOne(const Napi::CallbackInfo &info);
    Napi::Value AddBoolAnd(const Napi::CallbackInfo &info);
    Napi::Value AddBoolXor(const Napi::CallbackInfo &info);
    Napi::Value AddImplication(const Napi::CallbackInfo &info);
    Napi::Value AddEquality(const Napi::CallbackInfo &info);
    Napi::Value AddGreaterOrEqual(const Napi::CallbackInfo &info);
    Napi::Value AddGreaterThan(const Napi::CallbackInfo &info);
    Napi::Value AddLessOrEqual(const Napi::CallbackInfo &info);
    Napi::Value AddLessThan(const Napi::CallbackInfo &info);
    Napi::Value AddLinearConstraint(const Napi::CallbackInfo &info);
    Napi::Value AddNotEqual(const Napi::CallbackInfo &info);
    Napi::Value AddAllDifferent(const Napi::CallbackInfo &info);
    Napi::Value AddVariableElement(const Napi::CallbackInfo &info);
    Napi::Value AddElement(const Napi::CallbackInfo &info);
    Napi::Value AddCircuitConstraint(const Napi::CallbackInfo &info);
    Napi::Value AddMultipleCircuitConstraint(const Napi::CallbackInfo &info);
    Napi::Value AddAllowedAssignments(const Napi::CallbackInfo &info);
    Napi::Value AddForbiddenAssignments(const Napi::CallbackInfo &info);
    Napi::Value AddInverseConstraint(const Napi::CallbackInfo &info);
    Napi::Value AddReservoirConstraint(const Napi::CallbackInfo &info);
    Napi::Value AddAutomaton(const Napi::CallbackInfo &info);
    Napi::Value AddMinEquality(const Napi::CallbackInfo &info);
    Napi::Value AddMaxEquality(const Napi::CallbackInfo &info);
    Napi::Value AddDivisionEquality(const Napi::CallbackInfo &info);
    Napi::Value AddAbsEquality(const Napi::CallbackInfo &info);
    Napi::Value AddModuloEquality(const Napi::CallbackInfo &info);
    Napi::Value AddMultiplicationEquality(const Napi::CallbackInfo &info);
    Napi::Value AddNoOverlap(const Napi::CallbackInfo &info);
    Napi::Value AddNoOverlap2D(const Napi::CallbackInfo &info);
    Napi::Value AddCumulative(const Napi::CallbackInfo &info);
    Napi::Value Minimize(const Napi::CallbackInfo &info);
    Napi::Value Maximize(const Napi::CallbackInfo &info);
    Napi::Value ClearObjective(const Napi::CallbackInfo &info);
    Napi::Value HasObjective(const Napi::CallbackInfo &info);
    Napi::Value AddDecisionStrategy(const Napi::CallbackInfo &info);
    Napi::Value AddHint(const Napi::CallbackInfo &info);
    Napi::Value ClearHints(const Napi::CallbackInfo &info);

    Napi::Value AddAssumption(const Napi::CallbackInfo &info);
    Napi::Value AddAssumptions(const Napi::CallbackInfo &info);
    Napi::Value ClearAssumptions(const Napi::CallbackInfo &info);
    Napi::Value Build(const Napi::CallbackInfo &info);
    Napi::Value Proto(const Napi::CallbackInfo &info);
    Napi::Value MutableProto(const Napi::CallbackInfo &info);
    Napi::Value ExportToFile(const Napi::CallbackInfo &info);
    Napi::Value Clone(const Napi::CallbackInfo &info);
    Napi::Value GetBoolVarFromProtoIndex(const Napi::CallbackInfo &info);
    Napi::Value GetIntVarFromProtoIndex(const Napi::CallbackInfo &info);
    Napi::Value GetIntervalVarFromProtoIndex(const Napi::CallbackInfo &info);
};

class GIntVar : public Napi::ObjectWrap<GIntVar>
{
  public:
    static inline Napi::FunctionReference constructor;
    IntVar *pIntVar = nullptr;
    GIntVar(const Napi::CallbackInfo &info);
    ~GIntVar();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
};

class GBoolVar : public Napi::ObjectWrap<GBoolVar>
{
  public:
    static inline Napi::FunctionReference constructor;
    BoolVar *pBoolVar = nullptr;
    GBoolVar(const Napi::CallbackInfo &info);
    ~GBoolVar();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
};

class GIntervalVar : public Napi::ObjectWrap<GIntervalVar>
{
  public:
    static inline Napi::FunctionReference constructor;
    IntervalVar *pIntervalVar = nullptr;
    GIntervalVar(const Napi::CallbackInfo &info);
    ~GIntervalVar();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
};

class GLinearExpr : public Napi::ObjectWrap<GLinearExpr>
{
  public:
    static inline Napi::FunctionReference constructor;
    LinearExpr *pLinearExpr = nullptr;
    GLinearExpr(const Napi::CallbackInfo &info);
    ~GLinearExpr();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    static bool ToLinearExpr(const Napi::Value &value, LinearExpr &expr);
};

class GConstraint : public Napi::ObjectWrap<GConstraint>
{
  public:
    static inline Napi::FunctionReference constructor;
    Constraint *pConstraint = nullptr;
    GConstraint(const Napi::CallbackInfo &info);
    ~GConstraint();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
};

class GCpModelProto : public Napi::ObjectWrap<GCpModelProto>
{
  public:
    static inline Napi::FunctionReference constructor;
    CpModelProto *pCpModelProto = nullptr;
    GCpModelProto(const Napi::CallbackInfo &info);
    ~GCpModelProto();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
};

class GCircuitConstraint : public Napi::ObjectWrap<GCircuitConstraint>
{
  public:
    static inline Napi::FunctionReference constructor;
    CircuitConstraint *pCircuitConstraint = nullptr;
    GCircuitConstraint(const Napi::CallbackInfo &info);
    ~GCircuitConstraint();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
};
class GMultipleCircuitConstraint : public Napi::ObjectWrap<GMultipleCircuitConstraint>
{
  public:
    static inline Napi::FunctionReference constructor;
    MultipleCircuitConstraint *pMultipleCircuitConstraint = nullptr;
    GMultipleCircuitConstraint(const Napi::CallbackInfo &info);
    ~GMultipleCircuitConstraint();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
};

class GTableConstraint : public Napi::ObjectWrap<GTableConstraint>
{
  public:
    static inline Napi::FunctionReference constructor;
    TableConstraint *pTableConstraint = nullptr;
    GTableConstraint(const Napi::CallbackInfo &info);
    ~GTableConstraint();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
};

class GReservoirConstraint : public Napi::ObjectWrap<GReservoirConstraint>
{
  public:
    static inline Napi::FunctionReference constructor;
    ReservoirConstraint *pReservoirConstraint = nullptr;
    GReservoirConstraint(const Napi::CallbackInfo &info);
    ~GReservoirConstraint();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
};

class GAutomatonConstraint : public Napi::ObjectWrap<GAutomatonConstraint>
{
  public:
    static inline Napi::FunctionReference constructor;
    AutomatonConstraint *pAutomatonConstraint = nullptr;
    GAutomatonConstraint(const Napi::CallbackInfo &info);
    ~GAutomatonConstraint();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
};

class GNoOverlap2DConstraint : public Napi::ObjectWrap<GNoOverlap2DConstraint>
{
  public:
    static inline Napi::FunctionReference constructor;
    NoOverlap2DConstraint *pNoOverlap2DConstraint = nullptr;
    GNoOverlap2DConstraint(const Napi::CallbackInfo &info);
    ~GNoOverlap2DConstraint();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
};

class GCumulativeConstraint : public Napi::ObjectWrap<GCumulativeConstraint>
{
  public:
    static inline Napi::FunctionReference constructor;
    CumulativeConstraint *pCumulativeConstraint = nullptr;
    GCumulativeConstraint(const Napi::CallbackInfo &info);
    ~GCumulativeConstraint();
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
};

} // namespace sat
} // namespace operations_research
