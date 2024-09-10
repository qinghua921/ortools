#pragma once

#include <napi.h>
#include "commonheader.hpp"
#include "ortools/sat/cp_model.h"

namespace operations_research
{
namespace sat
{
    static Napi::Object GEnumInit( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );

        // export enum CpSolverStatus
        auto cpSolverStatus = Napi::Object::New( env );
        cpSolverStatus.Set( "UNKNOWN", Napi::Number::New( env, CpSolverStatus::UNKNOWN ) );
        cpSolverStatus.Set( "MODEL_INVALID", Napi::Number::New( env, CpSolverStatus::MODEL_INVALID ) );
        cpSolverStatus.Set( "FEASIBLE", Napi::Number::New( env, CpSolverStatus::FEASIBLE ) );
        cpSolverStatus.Set( "INFEASIBLE", Napi::Number::New( env, CpSolverStatus::INFEASIBLE ) );
        cpSolverStatus.Set( "OPTIMAL", Napi::Number::New( env, CpSolverStatus::OPTIMAL ) );
        exports.Set( "CpSolverStatus", cpSolverStatus );

        // export namespace DecisionStrategyProto
        auto variableSelectionStrategy = Napi::Object::New( env );
        variableSelectionStrategy.Set( "CHOOSE_FIRST", Napi::Number::New( env, DecisionStrategyProto::CHOOSE_FIRST ) );
        variableSelectionStrategy.Set( "CHOOSE_LOWEST_MIN", Napi::Number::New( env, DecisionStrategyProto::CHOOSE_LOWEST_MIN ) );
        variableSelectionStrategy.Set( "CHOOSE_HIGHEST_MAX", Napi::Number::New( env, DecisionStrategyProto::CHOOSE_HIGHEST_MAX ) );
        variableSelectionStrategy.Set( "CHOOSE_MIN_DOMAIN_SIZE", Napi::Number::New( env, DecisionStrategyProto::CHOOSE_MIN_DOMAIN_SIZE ) );
        variableSelectionStrategy.Set( "CHOOSE_MAX_DOMAIN_SIZE", Napi::Number::New( env, DecisionStrategyProto::CHOOSE_MAX_DOMAIN_SIZE ) );
        exports.Set( "DecisionStrategyProto_VariableSelectionStrategy", variableSelectionStrategy );

        auto domainReductionStrategy = Napi::Object::New( env );
        domainReductionStrategy.Set( "SELECT_MIN_VALUE", Napi::Number::New( env, DecisionStrategyProto::SELECT_MIN_VALUE ) );
        domainReductionStrategy.Set( "SELECT_MAX_VALUE", Napi::Number::New( env, DecisionStrategyProto::SELECT_MAX_VALUE ) );
        domainReductionStrategy.Set( "SELECT_LOWER_HALF", Napi::Number::New( env, DecisionStrategyProto::SELECT_LOWER_HALF ) );
        domainReductionStrategy.Set( "SELECT_UPPER_HALF", Napi::Number::New( env, DecisionStrategyProto::SELECT_UPPER_HALF ) );
        domainReductionStrategy.Set( "SELECT_MEDIAN_VALUE", Napi::Number::New( env, DecisionStrategyProto::SELECT_MEDIAN_VALUE ) );
        exports.Set( "DecisionStrategyProto_DomainReductionStrategy", domainReductionStrategy );

        return exports;
    };

}  // namespace sat
}  // namespace operations_research
