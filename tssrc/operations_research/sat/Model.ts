import { ortools } from "../../fuzhu"

/**
 * Class that owns everything related to a particular optimization model.
 *
 * This class is actually a fully generic wrapper that can hold any type of
 * constraints, watchers, solvers and provide a mechanism to wire them together.
 */
export interface Model
{
    /**
     * This makes it possible  to have a nicer API on the client side, and it
     * allows both of these forms:
     *   - ConstraintCreationFunction(constraint_args, &model);
     *   - model.Add(ConstraintCreationFunction(constraint_args));
     *
     * The second form is a bit nicer for the client and it also allows to store
     * constraints and add them later. However, the function creating the
     * constraint is slighly more involved.
     *
     * \code
     std::function<void(Model*)> ConstraintCreationFunction(constraint_args) {
        return [=] (Model* model) {
        ... the same code ...
        };
    }
    \endcode
    *
    * We also have a templated return value for the functions that need it like
    * \code
    const BooleanVariable b = model.Add(NewBooleanVariable());
    const IntegerVariable i = model.Add(NewWeightedSum(weights, variables));
    \endcode
    */
    Add<T>(func: (model: Model) => T): T

    Name(): string
}
export const Model:
    {

        /**
         * When there is more than one model in an application, it makes sense to
         * name them for debugging or logging.
         */
        new(name: string): Model

    } = ortools.operations_research.sat.Model
