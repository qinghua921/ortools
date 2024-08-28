import { ortools } from '../addon'


/**
 * This class stores parameter settings for LP and MIP solvers. Some parameters
 * are marked as advanced: do not change their values unless you know what you
 * are doing!
 *
 * For developers: how to add a new parameter:
 * - Add the new Foo parameter in the DoubleParam or IntegerParam enum.
 * - If it is a categorical param, add a FooValues enum.
 * - Decide if the wrapper should define a default value for it: yes
 *   if it controls the properties of the solution (example:
 *   tolerances) or if it consistently improves performance, no
 *   otherwise. If yes, define kDefaultFoo.
 * - Add a foo_value_ member and, if no default value is defined, a
 *   foo_is_default_ member.
 * - Add code to handle Foo in Set...Param, Reset...Param,
 *   Get...Param, Reset and the constructor.
 * - In class MPSolverInterface, add a virtual method SetFoo, add it
 *   to SetCommonParameters or SetMIPParameters, and implement it for
 *   each solver. Sometimes, parameters need to be implemented
 *   differently, see for example the INCREMENTALITY implementation.
 * - Add a test in linear_solver_test.cc.
 *
 * TODO(user): store the parameter values in a protocol buffer
 * instead. We need to figure out how to deal with the subtleties of
 * the default values.
 */
export interface GMPSolverParameters { }

export const GMPSolverParameters:
    {

        // The constructor sets all parameters to their default value.
        new(): GMPSolverParameters;

    } = ortools.operations_research.MPSolverParameters;

// Enumeration of parameters that take continuous values.
export enum DoubleParam
{
    /// Limit for relative MIP gap.
    RELATIVE_MIP_GAP = 0,

    /**
     * Advanced usage: tolerance for primal feasibility of basic solutions.
     *
     * This does not control the integer feasibility tolerance of integer
     * solutions for MIP or the tolerance used during presolve.
     */
    PRIMAL_TOLERANCE = 1,
    /// Advanced usage: tolerance for dual feasibility of basic solutions.
    DUAL_TOLERANCE = 2
};


// Enumeration of parameters that take integer or categorical values.
export enum IntegerParam
{
    /// Advanced usage: presolve mode.
    PRESOLVE = 1000,
    /// Algorithm to solve linear programs.
    LP_ALGORITHM = 1001,
    /// Advanced usage: incrementality from one solve to the next.
    INCREMENTALITY = 1002,
    /// Advanced usage: enable or disable matrix scaling.
    SCALING = 1003
};

// For each categorical parameter, enumeration of possible values.
export enum PresolveValues
{
    /// Presolve is off.
    PRESOLVE_OFF = 0,
    /// Presolve is on.
    PRESOLVE_ON = 1
};

// LP algorithm to use.
export enum LpAlgorithmValues
{
    /// Dual simplex.
    DUAL = 10,
    /// Primal simplex.
    PRIMAL = 11,
    /// Barrier algorithm.
    BARRIER = 12
};

// Advanced usage: Incrementality options.
export enum IncrementalityValues
{
    /// Start solve from scratch.
    INCREMENTALITY_OFF = 0,

    /**
     * Reuse results from previous solve as much as the underlying solver
     * allows.
     */
    INCREMENTALITY_ON = 1
};

// Advanced usage: Scaling options.
export enum ScalingValues
{
    /// Scaling is off.
    SCALING_OFF = 0,
    /// Scaling is on.
    SCALING_ON = 1
};
