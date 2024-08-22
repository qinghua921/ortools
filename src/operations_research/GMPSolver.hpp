#pragma once

#include <napi.h>
#include "ortools/linear_solver/linear_solver.h"
#include "../commonheader.hpp"
#include "GMPVariable.hpp"
#include "GMPConstraint.hpp"
#include "GLinearRange.hpp"

namespace operations_research
{

class GMPSolver : public Napi::ObjectWrap< GMPSolver >
{
public:
    static Napi::FunctionReference constructor;
    MPSolver*                      pMPSolver = nullptr;

    GMPSolver( const Napi::CallbackInfo& info )
        : Napi::ObjectWrap< GMPSolver >( info )
    {
        // MPSolver( const std::string& name, OptimizationProblemType problem_type );
        if ( info.Length() == 2 && info[ 0 ].IsString() && info[ 1 ].IsNumber() )
        {
            std::string name                     = info[ 0 ].As< Napi::String >().Utf8Value();
            using OptimizationProblemType        = MPSolver::OptimizationProblemType;
            OptimizationProblemType problem_type = static_cast< OptimizationProblemType >( info[ 1 ].As< Napi::Number >().Int32Value() );
            pMPSolver                            = new MPSolver( name, problem_type );
            return;
        }

        if ( info.Length() == 1 && info[ 0 ].IsExternal() )
        {
            auto external = info[ 0 ].As< Napi::External< MPSolver > >();
            pMPSolver     = dynamic_cast< MPSolver* >( external.Data() );
            if ( pMPSolver ) return;
        }

        ThrowJsError( GMPSolver::GMPSolver : Invalid arguments );
    };

    ~GMPSolver()
    {
        if ( pMPSolver )
        {
            delete pMPSolver;
            pMPSolver = nullptr;
        }
    };

    static Napi::Object Init( Napi::Env env, Napi::Object exports )
    {
        Napi::HandleScope scope( env );
        Napi::Function    func = DefineClass(
            env, "MPSolver",
            {
                StaticMethod( "CreateSolver", &GMPSolver::CreateSolver ),
                InstanceMethod( "MakeBoolVar", &GMPSolver::MakeBoolVar ),
                InstanceMethod( "MakeRowConstraint", &GMPSolver::MakeRowConstraint ),
            } );
        constructor = Napi::Persistent( func );
        constructor.SuppressDestruct();
        exports.Set( "MPSolver", func );
        return exports;
    }

    //     MPVariable* MakeBoolVar( const std::string& name );
    Napi::Value MakeBoolVar( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string name     = info[ 0 ].As< Napi::String >().Utf8Value();
            MPVariable* pVar     = pMPSolver->MakeBoolVar( name );
            auto        external = Napi::External< MPVariable >::New( info.Env(), pVar );
            return GMPVariable::constructor.New( { external } );
        }

        ThrowJsError( GMPSolver::MakeBoolVar : Invalid arguments );
        return info.Env().Undefined();
    }

    // static MPSolver* CreateSolver( const std::string& solver_id );
    static Napi::Value CreateSolver( const Napi::CallbackInfo& info )
    {
        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string solver_id = info[ 0 ].As< Napi::String >().Utf8Value();
            MPSolver*   pSolver   = MPSolver::CreateSolver( solver_id );
            auto        external  = Napi::External< MPSolver >::New( info.Env(), pSolver );
            return GMPSolver::constructor.New( { external } );
        }

        ThrowJsError( GMPSolver::CreateSolver : Invalid arguments );
        return info.Env().Undefined();
    }

    Napi::Value MakeRowConstraint( const Napi::CallbackInfo& info )
    {
        //     MPConstraint* MakeRowConstraint( double lb, double ub );
        if ( info.Length() == 2 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() )
        {
            double        lb          = info[ 0 ].As< Napi::Number >().DoubleValue();
            double        ub          = info[ 1 ].As< Napi::Number >().DoubleValue();
            MPConstraint* pConstraint = pMPSolver->MakeRowConstraint( lb, ub );
            auto          external    = Napi::External< MPConstraint >::New( info.Env(), pConstraint );
            return GMPConstraint::constructor.New( { external } );
        }

        //     MPConstraint* MakeRowConstraint();
        if ( info.Length() == 0 )
        {
            MPConstraint* pConstraint = pMPSolver->MakeRowConstraint();
            auto          external    = Napi::External< MPConstraint >::New( info.Env(), pConstraint );
            return GMPConstraint::constructor.New( { external } );
        }

        //     MPConstraint* MakeRowConstraint( double lb, double ub, const std::string& name );
        if ( info.Length() == 3 && info[ 0 ].IsNumber() && info[ 1 ].IsNumber() && info[ 2 ].IsString() )
        {
            double        lb          = info[ 0 ].As< Napi::Number >().DoubleValue();
            double        ub          = info[ 1 ].As< Napi::Number >().DoubleValue();
            std::string   name        = info[ 2 ].As< Napi::String >().Utf8Value();
            MPConstraint* pConstraint = pMPSolver->MakeRowConstraint( lb, ub, name );
            auto          external    = Napi::External< MPConstraint >::New( info.Env(), pConstraint );
            return GMPConstraint::constructor.New( { external } );
        }

        //     MPConstraint* MakeRowConstraint( const std::string& name );
        if ( info.Length() == 1 && info[ 0 ].IsString() )
        {
            std::string   name        = info[ 0 ].As< Napi::String >().Utf8Value();
            MPConstraint* pConstraint = pMPSolver->MakeRowConstraint( name );
            auto          external    = Napi::External< MPConstraint >::New( info.Env(), pConstraint );
            return GMPConstraint::constructor.New( { external } );
        }

        //     MPConstraint* MakeRowConstraint( const LinearRange& range );
        if ( info.Length() == 1 && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearRange::constructor.Value() ) )
        {

            auto          range        = Napi::ObjectWrap< GLinearRange >::Unwrap( info[ 0 ].As< Napi::Object >() );
            LinearRange*  pLinearRange = range->pLinearRange;
            MPConstraint* pConstraint  = pMPSolver->MakeRowConstraint( *pLinearRange );
            auto          external     = Napi::External< MPConstraint >::New( info.Env(), pConstraint );
            return GMPConstraint::constructor.New( { external } );
        }

        //     MPConstraint* MakeRowConstraint( const LinearRange& range,  const std::string& name );
        if ( info.Length() == 2 && info[ 0 ].IsObject()
             && info[ 0 ].As< Napi::Object >().InstanceOf( GLinearRange::constructor.Value() )
             && info[ 1 ].IsString() )
        {

            auto          range        = Napi::ObjectWrap< GLinearRange >::Unwrap( info[ 0 ].As< Napi::Object >() );
            LinearRange*  pLinearRange = range->pLinearRange;
            std::string   name         = info[ 1 ].As< Napi::String >().Utf8Value();
            MPConstraint* pConstraint  = pMPSolver->MakeRowConstraint( *pLinearRange, name );
            auto          external     = Napi::External< MPConstraint >::New( info.Env(), pConstraint );
            return GMPConstraint::constructor.New( { external } );
        }

        ThrowJsError( GMPSolver::MakeRowConstraint : Invalid arguments );
        return info.Env().Undefined();
    }
};

Napi::FunctionReference GMPSolver::constructor;

};  // namespace operations_research

// class MPSolver
// {
// public:

//     /**
//      * Whether the given problem type is supported (this will depend on the
//      * targets that you linked).
//      */
//     static bool SupportsProblemType( OptimizationProblemType problem_type );

//     /**
//      * Parses the name of the solver. Returns true if the solver type is
//      * successfully parsed as one of the OptimizationProblemType.
//      * See the documentation of CreateSolver() for the list of supported names.
//      */
//     static bool ParseSolverType( absl::string_view        solver_id,
//                                  OptimizationProblemType* type );

//     /**
//      * Parses the name of the solver and returns the correct optimization type or
//      * dies. Invariant: ParseSolverTypeOrDie(ToString(type)) = type.
//      */
//     static OptimizationProblemType ParseSolverTypeOrDie(
//         const std::string& solver_id );

//     bool IsMIP() const;

//     /// Returns the name of the model set at construction.
//     const std::string& Name() const
//     {
//         return name_;  // Set at construction.
//     }

//     /// Returns the optimization problem type set at construction.
//     virtual OptimizationProblemType ProblemType() const
//     {
//         return problem_type_;  // Set at construction.
//     }

//     /**
//      * Clears the objective (including the optimization direction), all variables
//      * and constraints. All the other properties of the MPSolver (like the time
//      * limit) are kept untouched.
//      */
//     void Clear();

//     /// Returns the number of variables.
//     int NumVariables() const
//     {
//         return variables_.size();
//     }

//     /**
//      * Returns the array of variables handled by the MPSolver. (They are listed in
//      * the order in which they were created.)
//      */
//     const std::vector< MPVariable* >& variables() const
//     {
//         return variables_;
//     }

//     /**
//      * Returns the variable at position index.
//      */
//     MPVariable* variable( int index ) const
//     {
//         return variables_[ index ];
//     }

//     /**
//      * Looks up a variable by name, and returns nullptr if it does not exist. The
//      * first call has a O(n) complexity, as the variable name index is lazily
//      * created upon first use. Will crash if variable names are not unique.
//      */
//     MPVariable* LookupVariableOrNull( const std::string& var_name ) const;

//     /**
//      * Creates a variable with the given bounds, integrality requirement and
//      * name. Bounds can be finite or +/- MPSolver::infinity(). The MPSolver owns
//      * the variable (i.e. the returned pointer is borrowed). Variable names are
//      * optional. If you give an empty name, name() will auto-generate one for you
//      * upon request.
//      */
//     MPVariable* MakeVar( double lb, double ub, bool integer,
//                          const std::string& name );

//     /// Creates a continuous variable.
//     MPVariable* MakeNumVar( double lb, double ub, const std::string& name );

//     /// Creates an integer variable.
//     MPVariable* MakeIntVar( double lb, double ub, const std::string& name );

//     /**
//      * Creates an array of variables. All variables created have the same bounds
//      * and integrality requirement. If nb <= 0, no variables are created, the
//      * function crashes in non-opt mode.
//      *
//      * @param nb the number of variables to create.
//      * @param lb the lower bound of created variables
//      * @param ub the upper bound of created variables
//      * @param integer controls whether the created variables are continuous or
//      * integral.
//      * @param name_prefix the prefix of the variable names. Variables are named
//      * name_prefix0, name_prefix1, ...
//      * @param[out] vars the vector of variables to fill with variables.
//      */
//     void MakeVarArray( int nb, double lb, double ub, bool integer,
//                        const std::string&          name_prefix,
//                        std::vector< MPVariable* >* vars );

//     /// Creates an array of continuous variables.
//     void MakeNumVarArray( int nb, double lb, double ub, const std::string& name,
//                           std::vector< MPVariable* >* vars );

//     ///  Creates an array of integer variables.
//     void MakeIntVarArray( int nb, double lb, double ub, const std::string& name,
//                           std::vector< MPVariable* >* vars );

//     /// Creates an array of boolean variables.
//     void MakeBoolVarArray( int nb, const std::string& name,
//                            std::vector< MPVariable* >* vars );

//     /// Returns the number of constraints.
//     int NumConstraints() const
//     {
//         return constraints_.size();
//     }

//     /**
//      * Returns the array of constraints handled by the MPSolver.
//      *
//      * They are listed in the order in which they were created.
//      */
//     const std::vector< MPConstraint* >& constraints() const
//     {
//         return constraints_;
//     }

//     /** Returns the constraint at the given index. */
//     MPConstraint* constraint( int index ) const
//     {
//         return constraints_[ index ];
//     }

//     /**
//      *  Looks up a constraint by name, and returns nullptr if it does not exist.
//      *
//      * The first call has a O(n) complexity, as the constraint name index is
//      * lazily created upon first use. Will crash if constraint names are not
//      * unique.
//      */
//     MPConstraint* LookupConstraintOrNull(
//         const std::string& constraint_name ) const;

//     /**
//      * Returns the objective object.
//      *
//      * Note that the objective is owned by the solver, and is initialized to its
//      * default value (see the MPObjective class below) at construction.
//      */
//     const MPObjective& Objective() const
//     {
//         return *objective_;
//     }

//     /// Returns the mutable objective object.
//     MPObjective* MutableObjective()
//     {
//         return objective_.get();
//     }

//     /**
//      * The status of solving the problem. The straightforward translation to
//      * homonymous enum values of MPSolverResponseStatus (see
//      * ./linear_solver.proto) is guaranteed by ./enum_consistency_test.cc, you may
//      * rely on it.
//      */
//     enum ResultStatus
//     {
//         /// optimal.
//         OPTIMAL,
//         /// feasible, or stopped by limit.
//         FEASIBLE,
//         /// proven infeasible.
//         INFEASIBLE,
//         /// proven unbounded.
//         UNBOUNDED,
//         /// abnormal, i.e., error of some kind.
//         ABNORMAL,
//         /// the model is trivially invalid (NaN coefficients, etc).
//         MODEL_INVALID,
//         /// not been solved yet.
//         NOT_SOLVED = 6
//     };

//     /// Solves the problem using the default parameter values.
//     ResultStatus Solve();

//     /// Solves the problem using the specified parameter values.
//     ResultStatus Solve( const MPSolverParameters& param );

//     /**
//      * Writes the model using the solver internal write function.  Currently only
//      * available for Gurobi.
//      */
//     void Write( const std::string& file_name );

//     /**
//      * Advanced usage: compute the "activities" of all constraints, which are the
//      * sums of their linear terms. The activities are returned in the same order
//      * as constraints(), which is the order in which constraints were added; but
//      * you can also use MPConstraint::index() to get a constraint's index.
//      */
//     std::vector< double > ComputeConstraintActivities() const;

//     /**
//      * Advanced usage: Verifies the *correctness* of the solution.
//      *
//      * It verifies that all variables must be within their domains, all
//      * constraints must be satisfied, and the reported objective value must be
//      * accurate.
//      *
//      * Usage:
//      * - This can only be called after Solve() was called.
//      * - "tolerance" is interpreted as an absolute error threshold.
//      * - For the objective value only, if the absolute error is too large,
//      *   the tolerance is interpreted as a relative error threshold instead.
//      * - If "log_errors" is true, every single violation will be logged.
//      * - If "tolerance" is negative, it will be set to infinity().
//      *
//      * Most users should just set the --verify_solution flag and not bother using
//      * this method directly.
//      */
//     bool VerifySolution( double tolerance, bool log_errors ) const;

//     /**
//      * Advanced usage: resets extracted model to solve from scratch.
//      *
//      * This won't reset the parameters that were set with
//      * SetSolverSpecificParametersAsString() or set_time_limit() or even clear the
//      * linear program. It will just make sure that next Solve() will be as if
//      * everything was reconstructed from scratch.
//      */
//     void Reset();

//     /** Interrupts the Solve() execution to terminate processing if possible.
//      *
//      * If the underlying interface supports interruption; it does that and returns
//      * true regardless of whether there's an ongoing Solve() or not. The Solve()
//      * call may still linger for a while depending on the conditions.  If
//      * interruption is not supported; returns false and does nothing.
//      * MPSolver::SolverTypeSupportsInterruption can be used to check if
//      * interruption is supported for a given solver type.
//      */
//     bool InterruptSolve();

//     /**
//      * Loads model from protocol buffer.
//      *
//      * Returns MPSOLVER_MODEL_IS_VALID if the model is valid, and another status
//      * otherwise (currently only MPSOLVER_MODEL_INVALID and MPSOLVER_INFEASIBLE).
//      * If the model isn't valid, populates "error_message".
//      */
//     MPSolverResponseStatus LoadModelFromProto( const MPModelProto& input_model,
//                                                std::string*        error_message );
//     /**
//      * Loads model from protocol buffer.
//      *
//      * The same as above, except that the loading keeps original variable and
//      * constraint names. Caller should make sure that all variable names and
//      * constraint names are unique, respectively.
//      */
//     MPSolverResponseStatus LoadModelFromProtoWithUniqueNamesOrDie(
//         const MPModelProto& input_model, std::string* error_message );

//     /// Encodes the current solution in a solution response protocol buffer.
//     void FillSolutionResponseProto( MPSolutionResponse* response ) const;

//     /**
//      * Solves the model encoded by a MPModelRequest protocol buffer and fills the
//      * solution encoded as a MPSolutionResponse. The solve is stopped prematurely
//      * if interrupt is non-null at set to true during (or before) solving.
//      * Interruption is only supported if SolverTypeSupportsInterruption() returns
//      * true for the requested solver. Passing a non-null interruption with any
//      * other solver type immediately returns an MPSOLVER_INCOMPATIBLE_OPTIONS
//      * error.
//      *
//      * Note(user): This attempts to first use `DirectlySolveProto()` (if
//      * implemented). Consequently, this most likely does *not* override any of
//      * the default parameters of the underlying solver. This behavior *differs*
//      * from `MPSolver::Solve()` which by default sets the feasibility tolerance
//      * and the gap limit (as of 2020/02/11, to 1e-7 and 0.0001, respectively).
//      */
//     static void SolveWithProto( const MPModelRequest& model_request,
//                                 MPSolutionResponse*   response,
//                                 // `interrupt` is non-const because the internal
//                                 // solver may set it to true itself, in some cases.
//                                 std::atomic< bool >* interrupt = nullptr );

//     static bool SolverTypeSupportsInterruption(
//         const MPModelRequest::SolverType solver )
//     {
//         // Interruption requires that MPSolver::InterruptSolve is supported for the
//         // underlying solver. Interrupting requests using SCIP is also not supported
//         // as of 2021/08/23, since InterruptSolve is not go/thread-safe
//         // for SCIP (see e.g. cl/350545631 for details).
//         return solver == MPModelRequest::GLOP_LINEAR_PROGRAMMING || solver == MPModelRequest::GUROBI_LINEAR_PROGRAMMING || solver == MPModelRequest::GUROBI_MIXED_INTEGER_PROGRAMMING || solver == MPModelRequest::SAT_INTEGER_PROGRAMMING || solver == MPModelRequest::PDLP_LINEAR_PROGRAMMING;
//     }

//     /// Exports model to protocol buffer.
//     void ExportModelToProto( MPModelProto* output_model ) const;

//     /**
//      * Load a solution encoded in a protocol buffer onto this solver for easy
//     access via the MPSolver interface.
//      *
//      * IMPORTANT: This may only be used in conjunction with ExportModel(),
//     following this example:
//      *
//      \code
//        MPSolver my_solver;
//        ... add variables and constraints ...
//        MPModelProto model_proto;
//        my_solver.ExportModelToProto(&model_proto);
//        MPSolutionResponse solver_response;
//        MPSolver::SolveWithProto(model_proto, &solver_response);
//        if (solver_response.result_status() == MPSolutionResponse::OPTIMAL) {
//          CHECK_OK(my_solver.LoadSolutionFromProto(solver_response));
//          ... inspect the solution using the usual API: solution_value(), etc...
//        }
//     \endcode
//      *
//      * The response must be in OPTIMAL or FEASIBLE status.
//      *
//      * Returns a non-OK status if a problem arised (typically, if it wasn't used
//      *     like it should be):
//      * - loading a solution whose variables don't correspond to the solver's
//      *   current variables
//      * - loading a dual solution whose constraints don't correspond to the
//      *   solver's current constraints
//      * - loading a solution with a status other than OPTIMAL / FEASIBLE.
//      *
//      * Note: the objective value isn't checked. You can use VerifySolution() for
//      *       that.
//      */
//     absl::Status LoadSolutionFromProto(
//         const MPSolutionResponse& response,
//         double                    tolerance = std::numeric_limits< double >::infinity() );

//     /**
//      * Resets values of out of bound variables to the corresponding bound and
//      * returns an error if any of the variables have NaN value.
//      */
//     absl::Status ClampSolutionWithinBounds();

//     /**
//      * Shortcuts to the homonymous MPModelProtoExporter methods, via exporting to
//      * a MPModelProto with ExportModelToProto() (see above).
//      *
//      * Produces empty std::string on portable platforms (e.g. android, ios).
//      */
//     bool ExportModelAsLpFormat( bool obfuscate, std::string* model_str ) const;
//     bool ExportModelAsMpsFormat( bool fixed_format, bool obfuscate,
//                                  std::string* model_str ) const;

//     /**
//      *  Sets the number of threads to use by the underlying solver.
//      *
//      * Returns OkStatus if the operation was successful. num_threads must be equal
//      * to or greater than 1. Note that the behaviour of this call depends on the
//      * underlying solver. E.g., it may set the exact number of threads or the max
//      * number of threads (check the solver's interface implementation for
//      * details). Also, some solvers may not (yet) support this function, but still
//      * enable multi-threading via SetSolverSpecificParametersAsString().
//      */
//     absl::Status SetNumThreads( int num_threads );

//     /// Returns the number of threads to be used during solve.
//     int GetNumThreads() const
//     {
//         return num_threads_;
//     }

//     /**
//      * Advanced usage: pass solver specific parameters in text format.
//      *
//      * The format is solver-specific and is the same as the corresponding solver
//      * configuration file format. Returns true if the operation was successful.
//      */
//     bool        SetSolverSpecificParametersAsString( const std::string& parameters );
//     std::string GetSolverSpecificParametersAsString() const
//     {
//         return solver_specific_parameter_string_;
//     }

//     /**
//      * Sets a hint for solution.
//      *
//      * If a feasible or almost-feasible solution to the problem is already known,
//      * it may be helpful to pass it to the solver so that it can be used. A solver
//      * that supports this feature will try to use this information to create its
//      * initial feasible solution.
//      *
//      * Note: It may not always be faster to give a hint like this to the
//      * solver. There is also no guarantee that the solver will use this hint or
//      * try to return a solution "close" to this assignment in case of multiple
//      * optimal solutions.
//      *
//      * Calling SetHint clears all previous hints.
//      */
//     void SetHint( std::vector< std::pair< const MPVariable*, double > > hint );

//     /**
//      * Advanced usage: possible basis status values for a variable and the slack
//      * variable of a linear constraint.
//      */
//     enum BasisStatus
//     {
//         FREE = 0,
//         AT_LOWER_BOUND,
//         AT_UPPER_BOUND,
//         FIXED_VALUE,
//         BASIC
//     };

//     /**
//      * Advanced usage: Incrementality.
//      *
//      * This function takes a starting basis to be used in the next LP Solve()
//      * call. The statuses of a current solution can be retrieved via the
//      * basis_status() function of a MPVariable or a MPConstraint.
//      *
//      * WARNING: With Glop, you should disable presolve when using this because
//      * this information will not be modified in sync with the presolve and will
//      * likely not mean much on the presolved problem.
//      */
//     void SetStartingLpBasis(
//         const std::vector< MPSolver::BasisStatus >& variable_statuses,
//         const std::vector< MPSolver::BasisStatus >& constraint_statuses );

//     /**
//      * Infinity.
//      *
//      * You can use -MPSolver::infinity() for negative infinity.
//      */
//     static double infinity()
//     {
//         return std::numeric_limits< double >::infinity();
//     }

//     /**
//      * Controls (or queries) the amount of output produced by the underlying
//      * solver. The output can surface to LOGs, or to stdout or stderr, depending
//      * on the implementation. The amount of output will greatly vary with each
//      * implementation and each problem.
//      *
//      * Output is suppressed by default.
//      */
//     bool OutputIsEnabled() const;

//     /// Enables solver logging.
//     void EnableOutput();

//     /// Suppresses solver logging.
//     void SuppressOutput();

//     absl::Duration TimeLimit() const
//     {
//         return time_limit_;
//     }
//     void SetTimeLimit( absl::Duration time_limit )
//     {
//         DCHECK_GE( time_limit, absl::ZeroDuration() );
//         time_limit_ = time_limit;
//     }

//     absl::Duration DurationSinceConstruction() const
//     {
//         return absl::Now() - construction_time_;
//     }

//     /// Returns the number of simplex iterations.
//     int64_t iterations() const;

//     /**
//      * Returns the number of branch-and-bound nodes evaluated during the solve.
//      *
//      * Only available for discrete problems.
//      */
//     int64_t nodes() const;

//     /// Returns a string describing the underlying solver and its version.
//     std::string SolverVersion() const;

//     /**
//      * Advanced usage: returns the underlying solver.
//      *
//      * Returns the underlying solver so that the user can use solver-specific
//      * features or features that are not exposed in the simple API of MPSolver.
//      * This method is for advanced users, use at your own risk! In particular, if
//      * you modify the model or the solution by accessing the underlying solver
//      * directly, then the underlying solver will be out of sync with the
//      * information kept in the wrapper (MPSolver, MPVariable, MPConstraint,
//      * MPObjective). You need to cast the void* returned back to its original type
//      * that depends on the interface (CBC: OsiClpSolverInterface*, CLP:
//      * ClpSimplex*, GLPK: glp_prob*, SCIP: SCIP*).
//      */
//     void* underlying_solver();

//     /** Advanced usage: computes the exact condition number of the current scaled
//      * basis: L1norm(B) * L1norm(inverse(B)), where B is the scaled basis.
//      *
//      * This method requires that a basis exists: it should be called after Solve.
//      * It is only available for continuous problems. It is implemented for GLPK
//      * but not CLP because CLP does not provide the API for doing it.
//      *
//      * The condition number measures how well the constraint matrix is conditioned
//      * and can be used to predict whether numerical issues will arise during the
//      * solve: the model is declared infeasible whereas it is feasible (or
//      * vice-versa), the solution obtained is not optimal or violates some
//      * constraints, the resolution is slow because of repeated singularities.
//      *
//      * The rule of thumb to interpret the condition number kappa is:
//      *   - o kappa <= 1e7: virtually no chance of numerical issues
//      *   - o 1e7 < kappa <= 1e10: small chance of numerical issues
//      *   - o 1e10 < kappa <= 1e13: medium chance of numerical issues
//      *   - o kappa > 1e13: high chance of numerical issues
//      *
//      * The computation of the condition number depends on the quality of the LU
//      * decomposition, so it is not very accurate when the matrix is ill
//      * conditioned.
//      */
//     double ComputeExactConditionNumber() const;

//     /**
//      * Some solvers (MIP only, not LP) can produce multiple solutions to the
//      * problem. Returns true when another solution is available, and updates the
//      * MPVariable* objects to make the new solution queryable. Call only after
//      * calling solve.
//      *
//      * The optimality properties of the additional solutions found, and whether or
//      * not the solver computes them ahead of time or when NextSolution() is called
//      * is solver specific.
//      *
//      * As of 2020-02-10, only Gurobi and SCIP support NextSolution(), see
//      * linear_solver_interfaces_test for an example of how to configure these
//      * solvers for multiple solutions. Other solvers return false unconditionally.
//      */
//     ABSL_MUST_USE_RESULT bool NextSolution();

//     // Does not take ownership of "mp_callback".
//     //
//     // As of 2019-10-22, only SCIP and Gurobi support Callbacks.
//     // SCIP does not support suggesting a heuristic solution in the callback.
//     //
//     // See go/mpsolver-callbacks for additional documentation.
//     void SetCallback( MPCallback* mp_callback );
//     bool SupportsCallbacks() const;

//     // Global counters of variables and constraints ever created across all
//     // MPSolver instances. Those are only updated after the destruction
//     // (or Clear()) of each MPSolver instance.
//     static int64_t global_num_variables();
//     static int64_t global_num_constraints();

//     // DEPRECATED: Use TimeLimit() and SetTimeLimit(absl::Duration) instead.
//     // NOTE: These deprecated functions used the convention time_limit = 0 to mean
//     // "no limit", which now corresponds to time_limit_ = InfiniteDuration().
//     int64_t time_limit() const
//     {
//         return time_limit_ == absl::InfiniteDuration()
//                    ? 0
//                    : absl::ToInt64Milliseconds( time_limit_ );
//     }
//     void set_time_limit( int64_t time_limit_milliseconds )
//     {
//         SetTimeLimit( time_limit_milliseconds == 0
//                           ? absl::InfiniteDuration()
//                           : absl::Milliseconds( time_limit_milliseconds ) );
//     }
//     double time_limit_in_secs() const
//     {
//         return static_cast< double >( time_limit() ) / 1000.0;
//     }

//     // DEPRECATED: Use DurationSinceConstruction() instead.
//     int64_t wall_time() const
//     {
//         return absl::ToInt64Milliseconds( DurationSinceConstruction() );
//     }

//     // Debugging: verify that the given MPVariable* belongs to this solver.
//     bool OwnsVariable( const MPVariable* var ) const;
// };
