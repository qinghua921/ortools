import { RoutingIndexManager } from "./RoutingIndexManager";
export namespace RoutingModel
{
    export enum TransitEvaluatorSign
    {
        kTransitEvaluatorSignUnknown = 0,
        kTransitEvaluatorSignPositiveOrZero = 1,
        kTransitEvaluatorSignNegativeOrZero = 2,
    };
}
export class RoutingModel
{
    //     public:
    //      /// Status of the search.
    //      enum Status {
    //        /// Problem not solved yet (before calling RoutingModel::Solve()).
    //        ROUTING_NOT_SOLVED,
    //        /// Problem solved successfully after calling RoutingModel::Solve().
    //        ROUTING_SUCCESS,
    //        /// Problem solved successfully after calling RoutingModel::Solve(), except
    //        /// that a local optimum has not been reached. Leaving more time would allow
    //        /// improving the solution.
    //        ROUTING_PARTIAL_SUCCESS_LOCAL_OPTIMUM_NOT_REACHED,
    //        /// No solution found to the problem after calling RoutingModel::Solve().
    //        ROUTING_FAIL,
    //        /// Time limit reached before finding a solution with RoutingModel::Solve().
    //        ROUTING_FAIL_TIMEOUT,
    //        /// Model, model parameters or flags are not valid.
    //        ROUTING_INVALID,
    //        /// Problem proven to be infeasible.
    //        ROUTING_INFEASIBLE,
    //        /// Problem has been solved to optimality.
    //        ROUTING_OPTIMAL
    //      };

    //      /// Types of precedence policy applied to pickup and delivery pairs.
    //      enum PickupAndDeliveryPolicy {
    //        /// Any precedence is accepted.
    //        PICKUP_AND_DELIVERY_NO_ORDER,
    //        /// Deliveries must be performed in reverse order of pickups.
    //        PICKUP_AND_DELIVERY_LIFO,
    //        /// Deliveries must be performed in the same order as pickups.
    //        PICKUP_AND_DELIVERY_FIFO
    //      };
    //      typedef RoutingCostClassIndex CostClassIndex;
    //      typedef RoutingDimensionIndex DimensionIndex;
    //      typedef RoutingDisjunctionIndex DisjunctionIndex;
    //      typedef RoutingVehicleClassIndex VehicleClassIndex;
    //      typedef RoutingResourceClassIndex ResourceClassIndex;
    //      typedef RoutingTransitCallback1 TransitCallback1;
    //      typedef RoutingTransitCallback2 TransitCallback2;



    //      /// Struct used to sort and store vehicles by their type. Two vehicles have
    //      /// the same "vehicle type" iff they have the same cost class and start/end
    //      /// nodes.
    //      struct VehicleTypeContainer {
    //        struct VehicleClassEntry {
    //          int vehicle_class;
    //          int64_t fixed_cost;

    //          bool operator<(const VehicleClassEntry& other) const {
    //            return std::tie(fixed_cost, vehicle_class) <
    //                   std::tie(other.fixed_cost, other.vehicle_class);
    //          }
    //        };

    //        int NumTypes() const { return sorted_vehicle_classes_per_type.size(); }

    //        int Type(int vehicle) const {
    //          DCHECK_LT(vehicle, type_index_of_vehicle.size());
    //          return type_index_of_vehicle[vehicle];
    //        }

    //        std::vector<int> type_index_of_vehicle;
    //        // clang-format off
    //        std::vector<std::set<VehicleClassEntry> > sorted_vehicle_classes_per_type;
    //        std::vector<std::deque<int> > vehicles_per_vehicle_class;
    //        // clang-format on
    //      };

    //      /// A ResourceGroup defines a set of available Resources with attributes on
    //      /// one or multiple dimensions.
    //      /// For every ResourceGroup in the model, each (used) vehicle in the solution
    //      /// which requires a resource (see NotifyVehicleRequiresResource()) from this
    //      /// group must be assigned to exactly 1 resource, and each resource can in
    //      /// turn be assigned to at most 1 vehicle requiring it. This
    //      /// vehicle-to-resource assignment will apply the corresponding Attributes to
    //      /// the dimensions affected by the resource group. NOTE: As of 2021/07, each
    //      /// ResourceGroup can only affect a single RoutingDimension at a time, i.e.
    //      /// all Resources in a group must apply attributes to the same single
    //      /// dimension.
    //      class ResourceGroup {
    //       public:
    //        /// Attributes for a dimension.
    //        class Attributes {
    //         public:
    //          Attributes();
    //          Attributes(Domain start_domain, Domain end_domain);

    //          const Domain& start_domain() const { return start_domain_; }
    //          const Domain& end_domain() const { return end_domain_; }

    //          friend bool operator==(const Attributes& a, const Attributes& b) {
    //            return a.start_domain_ == b.start_domain_ &&
    //                   a.end_domain_ == b.end_domain_;
    //          }
    //          template <typename H>
    //          friend H AbslHashValue(H h, const Attributes& attributes) {
    //            return H::combine(std::move(h), attributes.start_domain_,
    //                              attributes.end_domain_);
    //          }

    //         private:
    //          /// The following domains constrain the dimension start/end cumul of
    //          /// the vehicle assigned to this resource:
    //          /// start_domain_.Min() <= cumul[Start(v)] <= start_domain_.Max()
    //          Domain start_domain_;
    //          /// end_domain_.Min() <= cumul[End(v)] <= end_domain_.Max()
    //          Domain end_domain_;
    //        };

    //        /// A Resource sets attributes (costs/constraints) for a set of dimensions.
    //        class Resource {
    //         public:
    //          const ResourceGroup::Attributes& GetDimensionAttributes(
    //              const RoutingDimension* dimension) const;

    //         private:
    //          explicit Resource(const RoutingModel* model) : model_(model) {}

    //          void SetDimensionAttributes(ResourceGroup::Attributes attributes,
    //                                      const RoutingDimension* dimension);
    //          const ResourceGroup::Attributes& GetDefaultAttributes() const;

    //          const RoutingModel* const model_;
    //          absl::flat_hash_map<DimensionIndex, ResourceGroup::Attributes>
    //              dimension_attributes_;

    //          friend class ResourceGroup;
    //        };

    //        /// Adds a Resource with the given attributes for the corresponding
    //        /// dimension. Returns the index of the added resource in resources_.
    //        int AddResource(Attributes attributes, const RoutingDimension* dimension);

    //        /// Notifies that the given vehicle index requires a resource from this
    //        /// group if the vehicle is used (i.e. if its route is non-empty or
    //        /// vehicle_used_when_empty_[vehicle] is true).
    //        void NotifyVehicleRequiresAResource(int vehicle);

    //        const std::vector<int>& GetVehiclesRequiringAResource() const {
    //          return vehicles_requiring_resource_;
    //        }

    //        bool VehicleRequiresAResource(int vehicle) const {
    //          return vehicle_requires_resource_[vehicle];
    //        }

    //        void SetAllowedResourcesForVehicle(
    //            int vehicle, const std::vector<int>& allowed_resource_indices) {
    //          DCHECK(!model_->closed_);
    //          // NOTE: As of 12/2023, an empty set of allowed resources means "all
    //          // resources allowed", so we make sure the empty set isn't used here
    //          // explicitly by the user to mark a vehicle as "unusable".
    //          DCHECK(!allowed_resource_indices.empty());
    //          DCHECK(vehicle_requires_resource_[vehicle]);
    //          DCHECK_LT(vehicle, vehicle_allowed_resources_.size());
    //          vehicle_allowed_resources_[vehicle].clear();
    //          vehicle_allowed_resources_[vehicle].insert(
    //              allowed_resource_indices.begin(), allowed_resource_indices.end());
    //        }
    //        void ClearAllowedResourcesForVehicle(int vehicle) {
    //          DCHECK_LT(vehicle, vehicle_allowed_resources_.size());
    //          vehicle_allowed_resources_[vehicle].clear();
    //        }
    //        const absl::flat_hash_set<int>& GetResourcesMarkedAllowedForVehicle(
    //            int vehicle) const {
    //          DCHECK_LT(vehicle, vehicle_allowed_resources_.size());
    //          return vehicle_allowed_resources_[vehicle];
    //        }
    //        bool IsResourceAllowedForVehicle(int resource, int vehicle) const {
    //          DCHECK_LT(vehicle, vehicle_allowed_resources_.size());
    //          return vehicle_allowed_resources_[vehicle].empty() ||
    //                 vehicle_allowed_resources_[vehicle].contains(resource);
    //        }

    //        const std::vector<Resource>& GetResources() const { return resources_; }
    //        const Resource& GetResource(int resource_index) const {
    //          DCHECK_LT(resource_index, resources_.size());
    //          return resources_[resource_index];
    //        }
    //        const absl::flat_hash_set<DimensionIndex>& GetAffectedDimensionIndices()
    //            const {
    //          return affected_dimension_indices_;
    //        }

    //        int GetResourceClassesCount() const {
    //          return resource_indices_per_class_.size();
    //        }
    //        const std::vector<int>& GetResourceIndicesInClass(
    //            ResourceClassIndex resource_class) const {
    //          DCHECK_LT(resource_class, resource_indices_per_class_.size());
    //          return resource_indices_per_class_[resource_class];
    //        }
    //        // clang-format off
    //        const util_intops::StrongVector<ResourceClassIndex, std::vector<int> >&
    //            GetResourceIndicesPerClass() const {
    //          return resource_indices_per_class_;
    //        }
    //        // clang-format on
    //        ResourceClassIndex GetResourceClassIndex(int resource_index) const {
    //          DCHECK_LT(resource_index, resource_class_indices_.size());
    //          return resource_class_indices_[resource_index];
    //        }

    //        int Size() const { return resources_.size(); }
    //        int Index() const { return index_; }

    //       private:
    //        explicit ResourceGroup(const RoutingModel* model)
    //            : index_(model->GetResourceGroups().size()),
    //              model_(model),
    //              vehicle_requires_resource_(model->vehicles(), false),
    //              vehicle_allowed_resources_(model->vehicles()) {}

    //        void ComputeResourceClasses();

    //        const int index_;
    //        const RoutingModel* const model_;
    //        std::vector<Resource> resources_;
    //        // Stores the ResourceClassIndex of each resource (See implementation of
    //        // ComputeResourceClasses()).
    //        std::vector<ResourceClassIndex> resource_class_indices_;
    //        // clang-format off
    //        util_intops::StrongVector<ResourceClassIndex, std::vector<int> >
    //            resource_indices_per_class_;
    //        // clang-format on

    //        std::vector<bool> vehicle_requires_resource_;
    //        std::vector<int> vehicles_requiring_resource_;
    //        // For each vehicle, stores the set of allowed resource indices if it's
    //        // restricted for that vehicle. If the set is empty for a vehicle, then any
    //        // resource from this group can be assigned to it.
    //        // clang-format off
    //        std::vector<absl::flat_hash_set<int> > vehicle_allowed_resources_;
    //        // clang-format on
    //        /// All indices of dimensions affected by this resource group.
    //        absl::flat_hash_set<DimensionIndex> affected_dimension_indices_;

    //        friend class RoutingModel;
    //      };

    //      /// Struct used to store a variable value.
    //      struct VariableValuePair {
    //        int var_index;
    //        int64_t value;
    //      };

    //      /// Class used to solve a secondary model within a first solution strategy.
    //      class SecondaryOptimizer {
    //       public:
    //        SecondaryOptimizer(RoutingModel* model,
    //                           RoutingSearchParameters* search_parameters,
    //                           int64_t solve_period);
    //        bool Solve(const std::vector<RoutingModel::VariableValuePair>& in_state,
    //                   std::vector<RoutingModel::VariableValuePair>* out_state);

    //       private:
    //        RoutingModel* const model_;
    //        const RoutingSearchParameters* const search_parameters_;
    //        const int64_t solve_period_ = 0;
    //        int64_t call_count_ = 0;
    //        Assignment* state_ = nullptr;
    //        absl::flat_hash_map<IntVar*, int> var_to_index_;
    //      };

    //      /// Constant used to express a hard constraint instead of a soft penalty.
    //      static const int64_t kNoPenalty;

    //      /// Constant used to express the "no disjunction" index, returned when a node
    //      /// does not appear in any disjunction.
    //      static const DisjunctionIndex kNoDisjunction;

    //      /// Constant used to express the "no dimension" index, returned when a
    //      /// dimension name does not correspond to an actual dimension.
    //      static const DimensionIndex kNoDimension;

    constructor(index_manager: RoutingIndexManager);
    //      RoutingModel(const RoutingIndexManager& index_manager,
    //                   const RoutingModelParameters& parameters);

    //      // This type is neither copyable nor movable.
    //      RoutingModel(const RoutingModel&) = delete;
    //      RoutingModel& operator=(const RoutingModel&) = delete;



    //      /// Registers 'callback' and returns its index.
    //      /// The sign parameter allows to notify the solver that the callback only
    //      /// return values of the given sign. This can help the solver, but passing
    //      /// an incorrect sign may crash in non-opt compilation mode, and yield
    //      /// incorrect results in opt.
    //      int RegisterUnaryTransitVector(std::vector<int64_t> values);
    //      int RegisterUnaryTransitCallback(
    //          TransitCallback1 callback,
    //          TransitEvaluatorSign sign = kTransitEvaluatorSignUnknown);

    //      int RegisterTransitMatrix(
    //          std::vector<std::vector<int64_t> /*needed_for_swig*/> values);
    //      int RegisterTransitCallback(
    //          TransitCallback2 callback,
    //          TransitEvaluatorSign sign = kTransitEvaluatorSignUnknown);
    RegisterTransitCallback(callback: (number, number) => number, sign: RoutingModel.TransitEvaluatorSign = RoutingModel.TransitEvaluatorSign.kTransitEvaluatorSignUnknown): number;

    //      int RegisterStateDependentTransitCallback(VariableIndexEvaluator2 callback);
    //      const TransitCallback2& TransitCallback(int callback_index) const {
    //        CHECK_LT(callback_index, transit_evaluators_.size());
    //        return transit_evaluators_[callback_index];
    //      }
    //      const TransitCallback1& UnaryTransitCallbackOrNull(int callback_index) const {
    //        CHECK_LT(callback_index, unary_transit_evaluators_.size());
    //        return unary_transit_evaluators_[callback_index];
    //      }
    //      const VariableIndexEvaluator2& StateDependentTransitCallback(
    //          int callback_index) const {
    //        CHECK_LT(callback_index, state_dependent_transit_evaluators_.size());
    //        return state_dependent_transit_evaluators_[callback_index];
    //      }

    //      /// Model creation

    //      /// Methods to add dimensions to routes; dimensions represent quantities
    //      /// accumulated at nodes along the routes. They represent quantities such as
    //      /// weights or volumes carried along the route, or distance or times.
    //      /// Quantities at a node are represented by "cumul" variables and the increase
    //      /// or decrease of quantities between nodes are represented by "transit"
    //      /// variables. These variables are linked as follows:
    //      /// if j == next(i), cumul(j) = cumul(i) + transit(i, j) + slack(i)
    //      /// where slack is a positive slack variable (can represent waiting times for
    //      /// a time dimension).
    //      /// Setting the value of fix_start_cumul_to_zero to true will force the
    //      /// "cumul" variable of the start node of all vehicles to be equal to 0.

    //      /// Creates a dimension where the transit variable is constrained to be
    //      /// equal to evaluator(i, next(i)); 'slack_max' is the upper bound of the
    //      /// slack variable and 'capacity' is the upper bound of the cumul variables.
    //      /// 'name' is the name used to reference the dimension; this name is used to
    //      /// get cumul and transit variables from the routing model.
    //      /// Returns false if a dimension with the same name has already been created
    //      /// (and doesn't create the new dimension).
    //      /// Takes ownership of the callback 'evaluator'.
    //      bool AddDimension(int evaluator_index, int64_t slack_max, int64_t capacity,
    //                        bool fix_start_cumul_to_zero, const std::string& name);
    //      bool AddDimensionWithVehicleTransits(
    //          const std::vector<int>& evaluator_indices, int64_t slack_max,
    //          int64_t capacity, bool fix_start_cumul_to_zero, const std::string& name);
    //      bool AddDimensionWithVehicleCapacity(int evaluator_index, int64_t slack_max,
    //                                           std::vector<int64_t> vehicle_capacities,
    //                                           bool fix_start_cumul_to_zero,
    //                                           const std::string& name);
    //      bool AddDimensionWithVehicleTransitAndCapacity(
    //          const std::vector<int>& evaluator_indices, int64_t slack_max,
    //          std::vector<int64_t> vehicle_capacities, bool fix_start_cumul_to_zero,
    //          const std::string& name);
    //      /// Creates a dimension where the transit variable is constrained to be
    //      /// equal to 'value'; 'capacity' is the upper bound of the cumul variables.
    //      /// 'name' is the name used to reference the dimension; this name is used to
    //      /// get cumul and transit variables from the routing model.
    //      /// Returns a pair consisting of an index to the registered unary transit
    //      /// callback and a bool denoting whether the dimension has been created.
    //      /// It is false if a dimension with the same name has already been created
    //      /// (and doesn't create the new dimension but still register a new callback).
    //      std::pair<int, bool> AddConstantDimensionWithSlack(
    //          int64_t value, int64_t capacity, int64_t slack_max,
    //          bool fix_start_cumul_to_zero, const std::string& name);
    //      std::pair<int, bool> AddConstantDimension(int64_t value, int64_t capacity,
    //                                                bool fix_start_cumul_to_zero,
    //                                                const std::string& name) {
    //        return AddConstantDimensionWithSlack(value, capacity, 0,
    //                                             fix_start_cumul_to_zero, name);
    //      }
    //      /// Creates a dimension where the transit variable is constrained to be
    //      /// equal to 'values[i]' for node i; 'capacity' is the upper bound of
    //      /// the cumul variables. 'name' is the name used to reference the dimension;
    //      /// this name is used to get cumul and transit variables from the routing
    //      /// model.
    //      /// Returns a pair consisting of an index to the registered unary transit
    //      /// callback and a bool denoting whether the dimension has been created.
    //      /// It is false if a dimension with the same name has already been created
    //      /// (and doesn't create the new dimension but still register a new callback).
    //      std::pair<int, bool> AddVectorDimension(std::vector<int64_t> values,
    //                                              int64_t capacity,
    //                                              bool fix_start_cumul_to_zero,
    //                                              const std::string& name);
    //      /// Creates a dimension where the transit variable is constrained to be
    //      /// equal to 'values[i][next(i)]' for node i; 'capacity' is the upper bound of
    //      /// the cumul variables. 'name' is the name used to reference the dimension;
    //      /// this name is used to get cumul and transit variables from the routing
    //      /// model.
    //      /// Returns a pair consisting of an index to the registered transit callback
    //      /// and a bool denoting whether the dimension has been created.
    //      /// It is false if a dimension with the same name has already been created
    //      /// (and doesn't create the new dimension but still register a new callback).
    //      std::pair<int, bool> AddMatrixDimension(
    //          std::vector<std::vector<int64_t> /*needed_for_swig*/> values,
    //          int64_t capacity, bool fix_start_cumul_to_zero, const std::string& name);
    //      /// Creates a dimension with transits depending on the cumuls of another
    //      /// dimension. 'pure_transits' are the per-vehicle fixed transits as above.
    //      /// 'dependent_transits' is a vector containing for each vehicle an index to a
    //      /// registered state dependent transit callback. 'base_dimension' indicates
    //      /// the dimension from which the cumul variable is taken. If 'base_dimension'
    //      /// is nullptr, then the newly created dimension is self-based.
    //      bool AddDimensionDependentDimensionWithVehicleCapacity(
    //          const std::vector<int>& pure_transits,
    //          const std::vector<int>& dependent_transits,
    //          const RoutingDimension* base_dimension, int64_t slack_max,
    //          std::vector<int64_t> vehicle_capacities, bool fix_start_cumul_to_zero,
    //          const std::string& name) {
    //        return AddDimensionDependentDimensionWithVehicleCapacityInternal(
    //            pure_transits, dependent_transits, base_dimension, slack_max,
    //            std::move(vehicle_capacities), fix_start_cumul_to_zero, name);
    //      }

    //      /// As above, but pure_transits are taken to be zero evaluators.
    //      bool AddDimensionDependentDimensionWithVehicleCapacity(
    //          const std::vector<int>& transits, const RoutingDimension* base_dimension,
    //          int64_t slack_max, std::vector<int64_t> vehicle_capacities,
    //          bool fix_start_cumul_to_zero, const std::string& name);
    //      /// Homogeneous versions of the functions above.
    //      bool AddDimensionDependentDimensionWithVehicleCapacity(
    //          int transit, const RoutingDimension* base_dimension, int64_t slack_max,
    //          int64_t vehicle_capacity, bool fix_start_cumul_to_zero,
    //          const std::string& name);
    //      bool AddDimensionDependentDimensionWithVehicleCapacity(
    //          int pure_transit, int dependent_transit,
    //          const RoutingDimension* base_dimension, int64_t slack_max,
    //          int64_t vehicle_capacity, bool fix_start_cumul_to_zero,
    //          const std::string& name);

    //      /// Creates a cached StateDependentTransit from an std::function.
    //      static RoutingModel::StateDependentTransit MakeStateDependentTransit(
    //          const std::function<int64_t(int64_t)>& f, int64_t domain_start,
    //          int64_t domain_end);

    //      /// Outputs the names of all dimensions added to the routing engine.
    //      // TODO(user): rename.
    //      std::vector<std::string> GetAllDimensionNames() const;
    //      /// Returns all dimensions of the model.
    //      const std::vector<RoutingDimension*>& GetDimensions() const {
    //        return dimensions_.get();
    //      }
    //      /// Returns dimensions with soft or vehicle span costs.
    //      std::vector<RoutingDimension*> GetDimensionsWithSoftOrSpanCosts() const;
    //      /// Returns dimensions for which all transit evaluators are unary.
    //      std::vector<RoutingDimension*> GetUnaryDimensions() const;

    //      /// Returns the dimensions which have [global|local]_dimension_optimizers_.
    //      std::vector<const RoutingDimension*> GetDimensionsWithGlobalCumulOptimizers()
    //          const;
    //      std::vector<const RoutingDimension*> GetDimensionsWithLocalCumulOptimizers()
    //          const;

    //      /// Returns whether the given dimension has global/local cumul optimizers.
    //      bool HasGlobalCumulOptimizer(const RoutingDimension& dimension) const {
    //        return GetGlobalCumulOptimizerIndex(dimension) >= 0;
    //      }
    //      bool HasLocalCumulOptimizer(const RoutingDimension& dimension) const {
    //        return GetLocalCumulOptimizerIndex(dimension) >= 0;
    //      }
    //      /// Returns the global/local dimension cumul optimizer for a given dimension,
    //      /// or nullptr if there is none.
    //      GlobalDimensionCumulOptimizer* GetMutableGlobalCumulLPOptimizer(
    //          const RoutingDimension& dimension) const;
    //      GlobalDimensionCumulOptimizer* GetMutableGlobalCumulMPOptimizer(
    //          const RoutingDimension& dimension) const;
    //      LocalDimensionCumulOptimizer* GetMutableLocalCumulLPOptimizer(
    //          const RoutingDimension& dimension) const;
    //      LocalDimensionCumulOptimizer* GetMutableLocalCumulMPOptimizer(
    //          const RoutingDimension& dimension) const;

    //      /// Returns true if a dimension exists for a given dimension name.
    //      bool HasDimension(absl::string_view dimension_name) const;
    //      /// Returns a dimension from its name. Dies if the dimension does not exist.
    //      const RoutingDimension& GetDimensionOrDie(
    //          const std::string& dimension_name) const;
    //      /// Returns a dimension from its name. Returns nullptr if the dimension does
    //      /// not exist.
    //      RoutingDimension* GetMutableDimension(
    //          const std::string& dimension_name) const;
    //      /// Set the given dimension as "primary constrained". As of August 2013, this
    //      /// is only used by ArcIsMoreConstrainedThanArc().
    //      /// "dimension" must be the name of an existing dimension, or be empty, in
    //      /// which case there will not be a primary dimension after this call.
    //      void SetPrimaryConstrainedDimension(const std::string& dimension_name) {
    //        DCHECK(dimension_name.empty() || HasDimension(dimension_name));
    //        primary_constrained_dimension_ = dimension_name;
    //      }
    //      /// Get the primary constrained dimension, or an empty string if it is unset.
    //      const std::string& GetPrimaryConstrainedDimension() const {
    //        return primary_constrained_dimension_;
    //      }

    //      /// Adds a resource group to the routing model and returns a pointer to it.
    //      ResourceGroup* AddResourceGroup();
    //      // clang-format off
    //      const std::vector<std::unique_ptr<ResourceGroup> >& GetResourceGroups()
    //          const {
    //        return resource_groups_;
    //      }
    //      // clang-format on
    //      ResourceGroup* GetResourceGroup(int rg_index) const {
    //        DCHECK_LT(rg_index, resource_groups_.size());
    //        return resource_groups_[rg_index].get();
    //      }

    //      /// Returns the indices of resource groups for this dimension. This method can
    //      /// only be called after the model has been closed.
    //      const std::vector<int>& GetDimensionResourceGroupIndices(
    //          const RoutingDimension* dimension) const;

    //      /// Returns the index of the resource group attached to the dimension.
    //      /// DCHECKS that there's exactly one resource group for this dimension.
    //      int GetDimensionResourceGroupIndex(const RoutingDimension* dimension) const {
    //        DCHECK_EQ(GetDimensionResourceGroupIndices(dimension).size(), 1);
    //        return GetDimensionResourceGroupIndices(dimension)[0];
    //      }

    //      /// Adds a disjunction constraint on the indices: exactly 'max_cardinality' of
    //      /// the indices are active. Start and end indices of any vehicle cannot be
    //      /// part of a disjunction.
    //      ///
    //      /// If a penalty is given, at most 'max_cardinality' of the indices can be
    //      /// active, and if less are active, 'penalty' is payed per inactive index.
    //      /// This is equivalent to adding the constraint:
    //      ///     p + Sum(i)active[i] == max_cardinality
    //      /// where p is an integer variable, and the following cost to the cost
    //      /// function:
    //      ///     p * penalty.
    //      /// 'penalty' must be positive to make the disjunction optional; a negative
    //      /// penalty will force 'max_cardinality' indices of the disjunction to be
    //      /// performed, and therefore p == 0.
    //      /// Note: passing a vector with a single index will model an optional index
    //      /// with a penalty cost if it is not visited.
    //      DisjunctionIndex AddDisjunction(const std::vector<int64_t>& indices,
    //                                      int64_t penalty = kNoPenalty,
    //                                      int64_t max_cardinality = 1);
    //      /// Returns the indices of the disjunctions to which an index belongs.
    //      const std::vector<DisjunctionIndex>& GetDisjunctionIndices(
    //          int64_t index) const {
    //        return index_to_disjunctions_[index];
    //      }
    //      /// Calls f for each variable index of indices in the same disjunctions as the
    //      /// node corresponding to the variable index 'index'; only disjunctions of
    //      /// cardinality 'cardinality' are considered.
    //      template <typename F>
    //      void ForEachNodeInDisjunctionWithMaxCardinalityFromIndex(
    //          int64_t index, int64_t max_cardinality, F f) const {
    //        for (const DisjunctionIndex disjunction : GetDisjunctionIndices(index)) {
    //          if (disjunctions_[disjunction].value.max_cardinality == max_cardinality) {
    //            for (const int64_t d_index : disjunctions_[disjunction].indices) {
    //              f(d_index);
    //            }
    //          }
    //        }
    //      }
    //    #if !defined(SWIGPYTHON)
    //      /// Returns the variable indices of the nodes in the disjunction of index
    //      /// 'index'.
    //      const std::vector<int64_t>& GetDisjunctionNodeIndices(
    //          DisjunctionIndex index) const {
    //        return disjunctions_[index].indices;
    //      }
    //    #endif  // !defined(SWIGPYTHON)
    //      /// Returns the penalty of the node disjunction of index 'index'.
    //      int64_t GetDisjunctionPenalty(DisjunctionIndex index) const {
    //        return disjunctions_[index].value.penalty;
    //      }
    //      /// Returns the maximum number of possible active nodes of the node
    //      /// disjunction of index 'index'.
    //      int64_t GetDisjunctionMaxCardinality(DisjunctionIndex index) const {
    //        return disjunctions_[index].value.max_cardinality;
    //      }
    //      /// Returns the number of node disjunctions in the model.
    //      int GetNumberOfDisjunctions() const { return disjunctions_.size(); }
    //      /// Returns true if the model contains mandatory disjunctions (ones with
    //      /// kNoPenalty as penalty).
    //      bool HasMandatoryDisjunctions() const;
    //      /// Returns true if the model contains at least one disjunction which is
    //      /// constrained by its max_cardinality.
    //      bool HasMaxCardinalityConstrainedDisjunctions() const;
    //      /// Returns the list of all perfect binary disjunctions, as pairs of variable
    //      /// indices: a disjunction is "perfect" when its variables do not appear in
    //      /// any other disjunction. Each pair is sorted (lowest variable index first),
    //      /// and the output vector is also sorted (lowest pairs first).
    //      std::vector<std::pair<int64_t, int64_t>> GetPerfectBinaryDisjunctions() const;
    //      /// SPECIAL: Makes the solver ignore all the disjunctions whose active
    //      /// variables are all trivially zero (i.e. Max() == 0), by setting their
    //      /// max_cardinality to 0.
    //      /// This can be useful when using the BaseBinaryDisjunctionNeighborhood
    //      /// operators, in the context of arc-based routing.
    //      void IgnoreDisjunctionsAlreadyForcedToZero();

    //      /// Adds a soft constraint to force a set of variable indices to be on the
    //      /// same vehicle. If all nodes are not on the same vehicle, each extra vehicle
    //      /// used adds 'cost' to the cost function.
    //      void AddSoftSameVehicleConstraint(const std::vector<int64_t>& indices,
    //                                        int64_t cost);

    //      /// Sets the vehicles which can visit a given node. If the node is in a
    //      /// disjunction, this will not prevent it from being unperformed.
    //      /// Specifying an empty vector of vehicles has no effect (all vehicles
    //      /// will be allowed to visit the node).
    //      void SetAllowedVehiclesForIndex(const std::vector<int>& vehicles,
    //                                      int64_t index);

    //      /// Returns true if a vehicle is allowed to visit a given node.
    //      bool IsVehicleAllowedForIndex(int vehicle, int64_t index) const {
    //        return allowed_vehicles_[index].empty() ||
    //               allowed_vehicles_[index].find(vehicle) !=
    //                   allowed_vehicles_[index].end();
    //      }

    //      /// Notifies that index1 and index2 form a pair of nodes which should belong
    //      /// to the same route. This methods helps the search find better solutions,
    //      /// especially in the local search phase.
    //      /// It should be called each time you have an equality constraint linking
    //      /// the vehicle variables of two node (including for instance pickup and
    //      /// delivery problems):
    //      ///     Solver* const solver = routing.solver();
    //      ///     int64_t index1 = manager.NodeToIndex(node1);
    //      ///     int64_t index2 = manager.NodeToIndex(node2);
    //      ///     solver->AddConstraint(solver->MakeEquality(
    //      ///         routing.VehicleVar(index1),
    //      ///         routing.VehicleVar(index2)));
    //      ///     routing.AddPickupAndDelivery(index1, index2);
    //      ///
    //      // TODO(user): Remove this when model introspection detects linked nodes.
    //      void AddPickupAndDelivery(int64_t pickup, int64_t delivery);
    //      /// Same as AddPickupAndDelivery but notifying that the performed node from
    //      /// the disjunction of index 'pickup_disjunction' is on the same route as the
    //      /// performed node from the disjunction of index 'delivery_disjunction'.
    //      void AddPickupAndDeliverySets(DisjunctionIndex pickup_disjunction,
    //                                    DisjunctionIndex delivery_disjunction);

    //      /// The position of a node in the set of pickup and delivery pairs.
    //      struct PickupDeliveryPosition {
    //        /// The index of the pickup and delivery pair within which the node appears.
    //        int pd_pair_index;
    //        /// The index of the node in the vector of pickup (resp. delivery)
    //        /// alternatives of the pair.
    //        int alternative_index;
    //      };
    //      /// Returns the pickup and delivery positions where the node is a pickup.
    //      const std::vector<PickupDeliveryPosition>& GetPickupPositions(
    //          int64_t node_index) const;
    //      /// Returns the pickup and delivery positions where the node is a delivery.
    //      const std::vector<PickupDeliveryPosition>& GetDeliveryPositions(
    //          int64_t node_index) const;
    //      /// Returns whether the node is a pickup (resp. delivery).
    //      bool IsPickup(int64_t node_index) const {
    //        return !GetPickupPositions(node_index).empty();
    //      }
    //      bool IsDelivery(int64_t node_index) const {
    //        return !GetDeliveryPositions(node_index).empty();
    //      }

    //      /// Sets the Pickup and delivery policy of all vehicles. It is equivalent to
    //      /// calling SetPickupAndDeliveryPolicyOfVehicle on all vehicles.
    //      void SetPickupAndDeliveryPolicyOfAllVehicles(PickupAndDeliveryPolicy policy);
    //      void SetPickupAndDeliveryPolicyOfVehicle(PickupAndDeliveryPolicy policy,
    //                                               int vehicle);
    //      PickupAndDeliveryPolicy GetPickupAndDeliveryPolicyOfVehicle(
    //          int vehicle) const;
    //      /// Returns the number of non-start/end nodes which do not appear in a
    //      /// pickup/delivery pair.

    //      int GetNumOfSingletonNodes() const;

    //    #ifndef SWIG
    //      /// Returns pickup and delivery pairs currently in the model.
    //      const std::vector<PickupDeliveryPair>& GetPickupAndDeliveryPairs() const {
    //        return pickup_delivery_pairs_;
    //      }
    //      const std::vector<std::pair<DisjunctionIndex, DisjunctionIndex>>&
    //      GetPickupAndDeliveryDisjunctions() const {
    //        return pickup_delivery_disjunctions_;
    //      }
    //      /// Returns implicit pickup and delivery pairs currently in the model.
    //      /// Pairs are implicit if they are not linked by a pickup and delivery
    //      /// constraint but that for a given unary dimension, the first element of the
    //      /// pair has a positive demand d, and the second element has a demand of -d.
    //      const std::vector<PickupDeliveryPair>&
    //      GetImplicitUniquePickupAndDeliveryPairs() const {
    //        DCHECK(closed_);
    //        return implicit_pickup_delivery_pairs_without_alternatives_;
    //      }
    //    #endif  // SWIG
    //      /// Set the node visit types and incompatibilities/requirements between the
    //      /// types (see below).
    //      ///
    //      /// NOTE: Before adding any incompatibilities and/or requirements on types:
    //      ///       1) All corresponding node types must have been set.
    //      ///       2) CloseVisitTypes() must be called so all containers are resized
    //      ///          accordingly.
    //      ///
    //      /// The following enum is used to describe how a node with a given type 'T'
    //      /// impacts the number of types 'T' on the route when visited, and thus
    //      /// determines how temporal incompatibilities and requirements take effect.
    //      enum VisitTypePolicy {
    //        /// When visited, the number of types 'T' on the vehicle increases by one.
    //        TYPE_ADDED_TO_VEHICLE,
    //        /// When visited, one instance of type 'T' previously added to the route
    //        /// (TYPE_ADDED_TO_VEHICLE), if any, is removed from the vehicle.
    //        /// If the type was not previously added to the route or all added instances
    //        /// have already been removed, this visit has no effect on the types.
    //        ADDED_TYPE_REMOVED_FROM_VEHICLE,
    //        /// With the following policy, the visit enforces that type 'T' is
    //        /// considered on the route from its start until this node is visited.
    //        TYPE_ON_VEHICLE_UP_TO_VISIT,
    //        /// The visit doesn't have an impact on the number of types 'T' on the
    //        /// route, as it's (virtually) added and removed directly.
    //        /// This policy can be used for visits which are part of an incompatibility
    //        /// or requirement set without affecting the type count on the route.
    //        TYPE_SIMULTANEOUSLY_ADDED_AND_REMOVED
    //      };
    //      // TODO(user): Support multiple visit types per node?
    //      void SetVisitType(int64_t index, int type, VisitTypePolicy type_policy);
    //      int GetVisitType(int64_t index) const;
    //      const std::vector<int>& GetSingleNodesOfType(int type) const;
    //      const std::vector<int>& GetPairIndicesOfType(int type) const;
    //      VisitTypePolicy GetVisitTypePolicy(int64_t index) const;
    //      /// This function should be called once all node visit types have been set and
    //      /// prior to adding any incompatibilities/requirements.
    //      // TODO(user): Reconsider the logic and potentially remove the need to
    //      /// "close" types.
    //      void CloseVisitTypes();
    //      int GetNumberOfVisitTypes() const { return num_visit_types_; }
    //    #ifndef SWIG
    //      const std::vector<std::vector<int>>& GetTopologicallySortedVisitTypes()
    //          const {
    //        DCHECK(closed_);
    //        return topologically_sorted_visit_types_;
    //      }
    //    #endif  // SWIG
    //      /// Incompatibilities:
    //      /// Two nodes with "hard" incompatible types cannot share the same route at
    //      /// all, while with a "temporal" incompatibility they can't be on the same
    //      /// route at the same time.
    //      void AddHardTypeIncompatibility(int type1, int type2);
    //      void AddTemporalTypeIncompatibility(int type1, int type2);
    //      /// Returns visit types incompatible with a given type.
    //      const absl::flat_hash_set<int>& GetHardTypeIncompatibilitiesOfType(
    //          int type) const;
    //      const absl::flat_hash_set<int>& GetTemporalTypeIncompatibilitiesOfType(
    //          int type) const;
    //      /// Returns true iff any hard (resp. temporal) type incompatibilities have
    //      /// been added to the model.
    //      bool HasHardTypeIncompatibilities() const {
    //        return has_hard_type_incompatibilities_;
    //      }
    //      bool HasTemporalTypeIncompatibilities() const {
    //        return has_temporal_type_incompatibilities_;
    //      }
    //      /// Requirements:
    //      /// NOTE: As of 2019-04, cycles in the requirement graph are not supported,
    //      /// and lead to the dependent nodes being skipped if possible (otherwise
    //      /// the model is considered infeasible).
    //      /// The following functions specify that "dependent_type" requires at least
    //      /// one of the types in "required_type_alternatives".
    //      ///
    //      /// For same-vehicle requirements, a node of dependent type type_D requires at
    //      /// least one node of type type_R among the required alternatives on the same
    //      /// route.
    //      void AddSameVehicleRequiredTypeAlternatives(
    //          int dependent_type, absl::flat_hash_set<int> required_type_alternatives);
    //      /// If type_D depends on type_R when adding type_D, any node_D of type_D and
    //      /// VisitTypePolicy TYPE_ADDED_TO_VEHICLE or
    //      /// TYPE_SIMULTANEOUSLY_ADDED_AND_REMOVED requires at least one type_R on its
    //      /// vehicle at the time node_D is visited.
    //      void AddRequiredTypeAlternativesWhenAddingType(
    //          int dependent_type, absl::flat_hash_set<int> required_type_alternatives);
    //      /// The following requirements apply when visiting dependent nodes that remove
    //      /// their type from the route, i.e. type_R must be on the vehicle when type_D
    //      /// of VisitTypePolicy ADDED_TYPE_REMOVED_FROM_VEHICLE,
    //      /// TYPE_ON_VEHICLE_UP_TO_VISIT or TYPE_SIMULTANEOUSLY_ADDED_AND_REMOVED is
    //      /// visited.
    //      void AddRequiredTypeAlternativesWhenRemovingType(
    //          int dependent_type, absl::flat_hash_set<int> required_type_alternatives);
    //      // clang-format off
    //      /// Returns the set of same-vehicle requirement alternatives for the given
    //      /// type.
    //      const std::vector<absl::flat_hash_set<int> >&
    //          GetSameVehicleRequiredTypeAlternativesOfType(int type) const;
    //      /// Returns the set of requirement alternatives when adding the given type.
    //      const std::vector<absl::flat_hash_set<int> >&
    //          GetRequiredTypeAlternativesWhenAddingType(int type) const;
    //      /// Returns the set of requirement alternatives when removing the given type.
    //      const std::vector<absl::flat_hash_set<int> >&
    //          GetRequiredTypeAlternativesWhenRemovingType(int type) const;
    //      // clang-format on
    //      /// Returns true iff any same-route (resp. temporal) type requirements have
    //      /// been added to the model.
    //      bool HasSameVehicleTypeRequirements() const {
    //        return has_same_vehicle_type_requirements_;
    //      }
    //      bool HasTemporalTypeRequirements() const {
    //        return has_temporal_type_requirements_;
    //      }

    //      /// Returns true iff the model has any incompatibilities or requirements set
    //      /// on node types.
    //      bool HasTypeRegulations() const {
    //        return HasTemporalTypeIncompatibilities() ||
    //               HasHardTypeIncompatibilities() || HasSameVehicleTypeRequirements() ||
    //               HasTemporalTypeRequirements();
    //      }

    //      /// Get the "unperformed" penalty of a node. This is only well defined if the
    //      /// node is only part of a single Disjunction, and that disjunction has a
    //      /// penalty. For forced active nodes returns max int64_t. In all other cases,
    //      /// this returns 0.
    //      int64_t UnperformedPenalty(int64_t var_index) const;
    //      /// Same as above except that it returns default_value instead of 0 when
    //      /// penalty is not well defined (default value is passed as first argument to
    //      /// simplify the usage of the method in a callback).
    //      int64_t UnperformedPenaltyOrValue(int64_t default_value,
    //                                        int64_t var_index) const;
    //      /// Returns the variable index of the first starting or ending node of all
    //      /// routes. If all routes start  and end at the same node (single depot), this
    //      /// is the node returned.
    //      int64_t GetDepot() const;

    //      /// Constrains the maximum number of active vehicles, aka the number of
    //      /// vehicles which do not have an empty route. For instance, this can be used
    //      /// to limit the number of routes in the case where there are fewer drivers
    //      /// than vehicles and that the fleet of vehicle is heterogeneous.
    //      void SetMaximumNumberOfActiveVehicles(int max_active_vehicles) {
    //        max_active_vehicles_ = max_active_vehicles;
    //      }
    //      /// Returns the maximum number of active vehicles.
    //      int GetMaximumNumberOfActiveVehicles() const { return max_active_vehicles_; }
    //      /// Sets the cost function of the model such that the cost of a segment of a
    //      /// route between node 'from' and 'to' is evaluator(from, to), whatever the
    //      /// route or vehicle performing the route.
    //      void SetArcCostEvaluatorOfAllVehicles(int evaluator_index);
    //      /// Sets the cost function for a given vehicle route.
    //      void SetArcCostEvaluatorOfVehicle(int evaluator_index, int vehicle);
    //      /// Sets the fixed cost of all vehicle routes. It is equivalent to calling
    //      /// SetFixedCostOfVehicle on all vehicle routes.
    //      void SetFixedCostOfAllVehicles(int64_t cost);
    //      /// Sets the fixed cost of one vehicle route.
    //      void SetFixedCostOfVehicle(int64_t cost, int vehicle);
    //      /// Returns the route fixed cost taken into account if the route of the
    //      /// vehicle is not empty, aka there's at least one node on the route other
    //      /// than the first and last nodes.
    //      int64_t GetFixedCostOfVehicle(int vehicle) const;
    //      // Sets the energy cost of a vehicle.
    //      // The energy used by a vehicle is the integral of the force dimension over
    //      // the distance dimension: it is the sum over nodes visited by the vehicle of
    //      // force.CumulVar(Next(node)) * distance.TransitVar(node).
    //      // The energy cost of a vehicle is linear in the energy used by the vehicle,
    //      // this call sets the coefficient to unit_cost, it is zero if unset.
    //      void SetPathEnergyCostOfVehicle(const std::string& force,
    //                                      const std::string& distance,
    //                                      int64_t unit_cost, int vehicle);

    //      /// The following methods set the linear and quadratic cost factors of
    //      /// vehicles (must be positive values). The default value of these parameters
    //      /// is zero for all vehicles.
    //      ///
    //      /// When set, the cost_ of the model will contain terms aiming at reducing the
    //      /// number of vehicles used in the model, by adding the following to the
    //      /// objective for every vehicle v:
    //      /// INDICATOR(v used in the model) *
    //      ///   [linear_cost_factor_of_vehicle_[v]
    //      ///    - quadratic_cost_factor_of_vehicle_[v]*(square of length of route v)]
    //      /// i.e. for every used vehicle, we add the linear factor as fixed cost, and
    //      /// subtract the square of the route length multiplied by the quadratic
    //      /// factor. This second term aims at making the routes as dense as possible.
    //      ///
    //      /// Sets the linear and quadratic cost factor of all vehicles.
    //      void SetAmortizedCostFactorsOfAllVehicles(int64_t linear_cost_factor,
    //                                                int64_t quadratic_cost_factor);
    //      /// Sets the linear and quadratic cost factor of the given vehicle.
    //      void SetAmortizedCostFactorsOfVehicle(int64_t linear_cost_factor,
    //                                            int64_t quadratic_cost_factor,
    //                                            int vehicle);

    //      const std::vector<int64_t>& GetAmortizedLinearCostFactorOfVehicles() const {
    //        return linear_cost_factor_of_vehicle_;
    //      }
    //      const std::vector<int64_t>& GetAmortizedQuadraticCostFactorOfVehicles()
    //          const {
    //        return quadratic_cost_factor_of_vehicle_;
    //      }

    //      void SetVehicleUsedWhenEmpty(bool is_used, int vehicle) {
    //        DCHECK_LT(vehicle, vehicles_);
    //        vehicle_used_when_empty_[vehicle] = is_used;
    //      }

    //      bool IsVehicleUsedWhenEmpty(int vehicle) const {
    //        DCHECK_LT(vehicle, vehicles_);
    //        return vehicle_used_when_empty_[vehicle];
    //      }

    //    /// Gets/sets the evaluator used during the search. Only relevant when
    //    /// RoutingSearchParameters.first_solution_strategy = EVALUATOR_STRATEGY.
    //    #ifndef SWIG
    //      const Solver::IndexEvaluator2& first_solution_evaluator() const {
    //        return first_solution_evaluator_;
    //      }
    //    #endif
    //      /// Takes ownership of evaluator.
    //      void SetFirstSolutionEvaluator(Solver::IndexEvaluator2 evaluator) {
    //        first_solution_evaluator_ = std::move(evaluator);
    //      }
    //      /// Adds a local search operator to the set of operators used to solve the
    //      /// vehicle routing problem.
    //      void AddLocalSearchOperator(LocalSearchOperator* ls_operator);
    //      /// Adds a search monitor to the search used to solve the routing model.
    //      void AddSearchMonitor(SearchMonitor* monitor);
    //      /// Adds a callback called each time a solution is found during the search.
    //      /// This is a shortcut to creating a monitor to call the callback on
    //      /// AtSolution() and adding it with AddSearchMonitor.
    //      /// If track_unchecked_neighbors is true, the callback will also be called on
    //      /// AcceptUncheckedNeighbor() events, which is useful to grab solutions
    //      /// obtained when solver_parameters.check_solution_period > 1 (aka fastLS).
    //      void AddAtSolutionCallback(std::function<void()> callback,
    //                                 bool track_unchecked_neighbors = false);
    //      /// Adds a variable to minimize in the solution finalizer. The solution
    //      /// finalizer is called each time a solution is found during the search and
    //      /// allows to instantiate secondary variables (such as dimension cumul
    //      /// variables).
    //      void AddVariableMinimizedByFinalizer(IntVar* var);
    //      /// Adds a variable to maximize in the solution finalizer (see above for
    //      /// information on the solution finalizer).
    //      void AddVariableMaximizedByFinalizer(IntVar* var);
    //      /// Adds a variable to minimize in the solution finalizer, with a weighted
    //      /// priority: the higher the more priority it has.
    //      void AddWeightedVariableMinimizedByFinalizer(IntVar* var, int64_t cost);
    //      /// Adds a variable to maximize in the solution finalizer, with a weighted
    //      /// priority: the higher the more priority it has.
    //      void AddWeightedVariableMaximizedByFinalizer(IntVar* var, int64_t cost);
    //      /// Add a variable to set the closest possible to the target value in the
    //      /// solution finalizer.
    //      void AddVariableTargetToFinalizer(IntVar* var, int64_t target);
    //      /// Same as above with a weighted priority: the higher the cost, the more
    //      /// priority it has to be set close to the target value.
    //      void AddWeightedVariableTargetToFinalizer(IntVar* var, int64_t target,
    //                                                int64_t cost);
    //      /// Closes the current routing model; after this method is called, no
    //      /// modification to the model can be done, but RoutesToAssignment becomes
    //      /// available. Note that CloseModel() is automatically called by Solve() and
    //      /// other methods that produce solution.
    //      /// This is equivalent to calling
    //      /// CloseModelWithParameters(DefaultRoutingSearchParameters()).
    //      void CloseModel();
    //      /// Same as above taking search parameters (as of 10/2015 some the parameters
    //      /// have to be set when closing the model).
    //      void CloseModelWithParameters(
    //          const RoutingSearchParameters& search_parameters);
    //      /// Solves the current routing model; closes the current model.
    //      /// This is equivalent to calling
    //      /// SolveWithParameters(DefaultRoutingSearchParameters())
    //      /// or
    //      /// SolveFromAssignmentWithParameters(assignment,
    //      ///                                   DefaultRoutingSearchParameters()).
    //      const Assignment* Solve(const Assignment* assignment = nullptr);
    //      /// Solves the current routing model with the given parameters. If 'solutions'
    //      /// is specified, it will contain the k best solutions found during the search
    //      /// (from worst to best, including the one returned by this method), where k
    //      /// corresponds to the 'number_of_solutions_to_collect' in
    //      /// 'search_parameters'. Note that the Assignment returned by the method and
    //      /// the ones in solutions are owned by the underlying solver and should not be
    //      /// deleted.
    //      const Assignment* SolveWithParameters(
    //          const RoutingSearchParameters& search_parameters,
    //          std::vector<const Assignment*>* solutions = nullptr);
    //      /// Same as above, except that if assignment is not null, it will be used as
    //      /// the initial solution.
    //      const Assignment* SolveFromAssignmentWithParameters(
    //          const Assignment* assignment,
    //          const RoutingSearchParameters& search_parameters,
    //          std::vector<const Assignment*>* solutions = nullptr);
    //      /// Improves a given assignment using unchecked local search.
    //      /// If check_solution_in_cp is true the final solution will be checked with
    //      /// the CP solver.
    //      /// As of 11/2023, only works with greedy descent.
    //      const Assignment* FastSolveFromAssignmentWithParameters(
    //          const Assignment* assignment,
    //          const RoutingSearchParameters& search_parameters,
    //          bool check_solution_in_cp,
    //          absl::flat_hash_set<IntVar*>* touched = nullptr);
    //      /// Same as above but will try all assignments in order as first solutions
    //      /// until one succeeds.
    //      const Assignment* SolveFromAssignmentsWithParameters(
    //          const std::vector<const Assignment*>& assignments,
    //          const RoutingSearchParameters& search_parameters,
    //          std::vector<const Assignment*>* solutions = nullptr);
    //      /// Solves the current routing model by using an Iterated Local Search
    //      /// approach.
    //      const Assignment* SolveWithIteratedLocalSearch(
    //          const RoutingSearchParameters& search_parameters);
    //      /// Given a "source_model" and its "source_assignment", resets
    //      /// "target_assignment" with the IntVar variables (nexts_, and vehicle_vars_
    //      /// if costs aren't homogeneous across vehicles) of "this" model, with the
    //      /// values set according to those in "other_assignment".
    //      /// The objective_element of target_assignment is set to this->cost_.
    //      void SetAssignmentFromOtherModelAssignment(
    //          Assignment* target_assignment, const RoutingModel* source_model,
    //          const Assignment* source_assignment);
    //      /// Computes a lower bound to the routing problem solving a linear assignment
    //      /// problem. The routing model must be closed before calling this method.
    //      /// Note that problems with node disjunction constraints (including optional
    //      /// nodes) and non-homogenous costs are not supported (the method returns 0 in
    //      /// these cases).
    //      // TODO(user): Add support for non-homogeneous costs and disjunctions.
    //      int64_t ComputeLowerBound();
    //      /// Returns the current lower bound found by internal solvers during the
    //      /// search.
    //      int64_t objective_lower_bound() const { return objective_lower_bound_; }
    //      /// Returns the current status of the routing model.
    //      Status status() const { return status_; }
    //      /// Returns the value of the internal enable_deep_serialization_ parameter.
    //      bool enable_deep_serialization() const { return enable_deep_serialization_; }
    //      /// Applies a lock chain to the next search. 'locks' represents an ordered
    //      /// vector of nodes representing a partial route which will be fixed during
    //      /// the next search; it will constrain next variables such that:
    //      /// next[locks[i]] == locks[i+1].
    //      ///
    //      /// Returns the next variable at the end of the locked chain; this variable is
    //      /// not locked. An assignment containing the locks can be obtained by calling
    //      /// PreAssignment().
    //      IntVar* ApplyLocks(const std::vector<int64_t>& locks);
    //      /// Applies lock chains to all vehicles to the next search, such that locks[p]
    //      /// is the lock chain for route p. Returns false if the locks do not contain
    //      /// valid routes; expects that the routes do not contain the depots,
    //      /// i.e. there are empty vectors in place of empty routes.
    //      /// If close_routes is set to true, adds the end nodes to the route of each
    //      /// vehicle and deactivates other nodes.
    //      /// An assignment containing the locks can be obtained by calling
    //      /// PreAssignment().
    //      bool ApplyLocksToAllVehicles(const std::vector<std::vector<int64_t>>& locks,
    //                                   bool close_routes);
    //      /// Returns an assignment used to fix some of the variables of the problem.
    //      /// In practice, this assignment locks partial routes of the problem. This
    //      /// can be used in the context of locking the parts of the routes which have
    //      /// already been driven in online routing problems.
    //      const Assignment* PreAssignment() const { return preassignment_; }
    //      Assignment* MutablePreAssignment() { return preassignment_; }
    //      /// Writes the current solution to a file containing an AssignmentProto.
    //      /// Returns false if the file cannot be opened or if there is no current
    //      /// solution.
    //      bool WriteAssignment(const std::string& file_name) const;
    //      /// Reads an assignment from a file and returns the current solution.
    //      /// Returns nullptr if the file cannot be opened or if the assignment is not
    //      /// valid.
    //      Assignment* ReadAssignment(const std::string& file_name);
    //      /// Restores an assignment as a solution in the routing model and returns the
    //      /// new solution. Returns nullptr if the assignment is not valid.
    //      Assignment* RestoreAssignment(const Assignment& solution);
    //      /// Restores the routes as the current solution. Returns nullptr if the
    //      /// solution cannot be restored (routes do not contain a valid solution). Note
    //      /// that calling this method will run the solver to assign values to the
    //      /// dimension variables; this may take considerable amount of time, especially
    //      /// when using dimensions with slack.
    //      Assignment* ReadAssignmentFromRoutes(
    //          const std::vector<std::vector<int64_t>>& routes,
    //          bool ignore_inactive_indices);
    //      /// Fills an assignment from a specification of the routes of the
    //      /// vehicles. The routes are specified as lists of variable indices that
    //      /// appear on the routes of the vehicles. The indices of the outer vector in
    //      /// 'routes' correspond to vehicles IDs, the inner vector contains the
    //      /// variable indices on the routes for the given vehicle. The inner vectors
    //      /// must not contain the start and end indices, as these are determined by the
    //      /// routing model.  Sets the value of NextVars in the assignment, adding the
    //      /// variables to the assignment if necessary. The method does not touch other
    //      /// variables in the assignment. The method can only be called after the model
    //      /// is closed.  With ignore_inactive_indices set to false, this method will
    //      /// fail (return nullptr) in case some of the route contain indices that are
    //      /// deactivated in the model; when set to true, these indices will be
    //      /// skipped.  Returns true if routes were successfully
    //      /// loaded. However, such assignment still might not be a valid
    //      /// solution to the routing problem due to more complex constraints;
    //      /// it is advisible to call solver()->CheckSolution() afterwards.
    //      bool RoutesToAssignment(const std::vector<std::vector<int64_t>>& routes,
    //                              bool ignore_inactive_indices, bool close_routes,
    //                              Assignment* assignment) const;
    //      /// Converts the solution in the given assignment to routes for all vehicles.
    //      /// Expects that assignment contains a valid solution (i.e. routes for all
    //      /// vehicles end with an end index for that vehicle).
    //      void AssignmentToRoutes(const Assignment& assignment,
    //                              std::vector<std::vector<int64_t>>* routes) const;
    //      /// Converts the solution in the given assignment to routes for all vehicles.
    //      /// If the returned vector is route_indices, route_indices[i][j] is the index
    //      /// for jth location visited on route i. Note that contrary to
    //      /// AssignmentToRoutes, the vectors do include start and end locations.
    //    #ifndef SWIG
    //      std::vector<std::vector<int64_t>> GetRoutesFromAssignment(
    //          const Assignment& assignment);
    //    #endif
    //      /// Returns a compacted version of the given assignment, in which all vehicles
    //      /// with id lower or equal to some N have non-empty routes, and all vehicles
    //      /// with id greater than N have empty routes. Does not take ownership of the
    //      /// returned object.
    //      /// If found, the cost of the compact assignment is the same as in the
    //      /// original assignment and it preserves the values of 'active' variables.
    //      /// Returns nullptr if a compact assignment was not found.
    //      /// This method only works in homogenous mode, and it only swaps equivalent
    //      /// vehicles (vehicles with the same start and end nodes). When creating the
    //      /// compact assignment, the empty plan is replaced by the route assigned to
    //      /// the compatible vehicle with the highest id. Note that with more complex
    //      /// constraints on vehicle variables, this method might fail even if a compact
    //      /// solution exists.
    //      /// This method changes the vehicle and dimension variables as necessary.
    //      /// While compacting the solution, only basic checks on vehicle variables are
    //      /// performed; if one of these checks fails no attempts to repair it are made
    //      /// (instead, the method returns nullptr).
    //      Assignment* CompactAssignment(const Assignment& assignment) const;
    //      /// Same as CompactAssignment() but also checks the validity of the final
    //      /// compact solution; if it is not valid, no attempts to repair it are made
    //      /// (instead, the method returns nullptr).
    //      Assignment* CompactAndCheckAssignment(const Assignment& assignment) const;
    //      /// Adds an extra variable to the vehicle routing assignment.
    //      void AddToAssignment(IntVar* var);
    //      void AddIntervalToAssignment(IntervalVar* interval);
    //      /// For every dimension in the model with an optimizer in
    //      /// local/global_dimension_optimizers_, this method tries to pack the cumul
    //      /// values of the dimension, such that:
    //      /// - The cumul costs (span costs, soft lower and upper bound costs, etc) are
    //      ///   minimized.
    //      /// - The cumuls of the ends of the routes are minimized for this given
    //      ///   minimal cumul cost.
    //      /// - Given these minimal end cumuls, the route start cumuls are maximized.
    //      /// Returns the assignment resulting from allocating these packed cumuls with
    //      /// the solver, and nullptr if these cumuls could not be set by the solver.
    //      const Assignment* PackCumulsOfOptimizerDimensionsFromAssignment(
    //          const Assignment* original_assignment, absl::Duration duration_limit,
    //          bool* time_limit_was_reached = nullptr);
    //      /// Contains the information needed by the solver to optimize a dimension's
    //      /// cumuls with travel-start dependent transit values.
    //      struct RouteDimensionTravelInfo {
    //        /// Contains the information for a single transition on the route.
    //        struct TransitionInfo {
    //          /// The following struct defines a piecewise linear formulation, with
    //          /// int64_t values for the "anchor" x and y values, and potential double
    //          /// values for the slope of each linear function.
    //          // TODO(user): Adjust the inlined vector sizes based on experiments.
    //          struct PiecewiseLinearFormulation {
    //            /// The set of *increasing* anchor cumul values for the interpolation.
    //            absl::InlinedVector<int64_t, 8> x_anchors;
    //            /// The y values used for the interpolation:
    //            /// For any x anchor value, let i be an index such that
    //            /// x_anchors[i] ≤ x < x_anchors[i+1], then the y value for x is
    //            /// y_anchors[i] * (1-λ) + y_anchors[i+1] * λ, with
    //            /// λ = (x - x_anchors[i]) / (x_anchors[i+1] - x_anchors[i]).
    //            absl::InlinedVector<int64_t, 8> y_anchors;

    //            std::string DebugString(std::string line_prefix = "") const;
    //          };

    //          /// Models the (real) travel value Tᵣ, for this transition based on the
    //          /// departure value of the travel.
    //          PiecewiseLinearFormulation travel_start_dependent_travel;

    //          /// travel_compression_cost models the cost of the difference between the
    //          /// (real) travel value Tᵣ given by travel_start_dependent_travel and the
    //          /// compressed travel value considered in the scheduling.
    //          PiecewiseLinearFormulation travel_compression_cost;

    //          /// The parts of the transit which occur pre/post travel between the
    //          /// nodes. The total transit between the two nodes i and j is
    //          /// = pre_travel_transit_value + travel(i, j) + post_travel_transit_value.
    //          int64_t pre_travel_transit_value;
    //          int64_t post_travel_transit_value;

    //          /// The hard lower bound of the compressed travel value that will be
    //          /// enforced by the scheduling module.
    //          int64_t compressed_travel_value_lower_bound;

    //          /// The hard upper bound of the (real) travel value Tᵣ (see
    //          /// above). This value should be chosen so as to prevent
    //          /// the overall cost of the model
    //          /// (dimension costs + travel_compression_cost) to overflow.
    //          int64_t travel_value_upper_bound;

    //          std::string DebugString(std::string line_prefix = "") const;
    //        };

    //        /// For each node #i on the route, transition_info[i] contains the relevant
    //        /// information for the travel between nodes #i and #(i + 1) on the route.
    //        std::vector<TransitionInfo> transition_info;
    //        /// The cost per unit of travel for this vehicle.
    //        int64_t travel_cost_coefficient;

    //        std::string DebugString(std::string line_prefix = "") const;
    //      };

    //    #ifndef SWIG
    //      // TODO(user): Revisit if coordinates are added to the RoutingModel class.
    //      void SetSweepArranger(SweepArranger* sweep_arranger);
    //      /// Returns the sweep arranger to be used by routing heuristics.
    //      SweepArranger* sweep_arranger() const;
    //    #endif
    //      class NodeNeighborsByCostClass {
    //       public:
    //        NodeNeighborsByCostClass() = default;

    //        /// Computes num_neighbors neighbors of all nodes for every cost class in
    //        /// routing_model.
    //        void ComputeNeighbors(const RoutingModel& routing_model, int num_neighbors,
    //                              bool add_vehicle_starts_to_neighbors);
    //        /// Returns the neighbors of the given node for the given cost_class.
    //        const std::vector<int>& GetNeighborsOfNodeForCostClass(
    //            int cost_class, int node_index) const {
    //          return all_nodes_.empty() ? node_index_to_neighbors_by_cost_class_
    //                                          [node_index][cost_class]
    //                                              ->PositionsSetAtLeastOnce()
    //                                    : all_nodes_;
    //        }

    //       private:
    //        std::vector<std::vector<std::unique_ptr<SparseBitset<int>>>>
    //            node_index_to_neighbors_by_cost_class_;
    //        std::vector<int> all_nodes_;
    //      };

    //      /// Returns neighbors of all nodes for every cost class. The result is cached
    //      /// and is computed once. The number of neighbors considered is based on a
    //      /// ratio of non-vehicle nodes, specified by neighbors_ratio, with a minimum
    //      /// of min-neighbors node considered.
    //      const NodeNeighborsByCostClass* GetOrCreateNodeNeighborsByCostClass(
    //          double neighbors_ratio, int64_t min_neighbors,
    //          double& neighbors_ratio_used,
    //          bool add_vehicle_starts_to_neighbors = true);
    //      /// Returns parameters.num_neighbors neighbors of all nodes for every cost
    //      /// class. The result is cached and is computed once.
    //      const NodeNeighborsByCostClass* GetOrCreateNodeNeighborsByCostClass(
    //          int num_neighbors, bool add_vehicle_starts_to_neighbors = true);
    //      /// Adds a custom local search filter to the list of filters used to speed up
    //      /// local search by pruning unfeasible variable assignments.
    //      /// Calling this method after the routing model has been closed (CloseModel()
    //      /// or Solve() has been called) has no effect.
    //      /// The routing model does not take ownership of the filter.
    //      void AddLocalSearchFilter(LocalSearchFilter* filter) {
    //        CHECK(filter != nullptr);
    //        if (closed_) {
    //          LOG(WARNING) << "Model is closed, filter addition will be ignored.";
    //        }
    //        extra_filters_.push_back({filter, LocalSearchFilterManager::kRelax});
    //        extra_filters_.push_back({filter, LocalSearchFilterManager::kAccept});
    //      }

    //      /// Model inspection.
    //      /// Returns the variable index of the starting node of a vehicle route.
    //      int64_t Start(int vehicle) const { return paths_metadata_.Starts()[vehicle]; }
    //      /// Returns the variable index of the ending node of a vehicle route.
    //      int64_t End(int vehicle) const { return paths_metadata_.Ends()[vehicle]; }
    //      /// Returns true if 'index' represents the first node of a route.
    //      bool IsStart(int64_t index) const { return paths_metadata_.IsStart(index); }
    //      /// Returns true if 'index' represents the last node of a route.
    //      bool IsEnd(int64_t index) const { return paths_metadata_.IsEnd(index); }
    //      /// Returns the vehicle of the given start/end index, and -1 if the given
    //      /// index is not a vehicle start/end.
    //      int VehicleIndex(int64_t index) const {
    //        return paths_metadata_.GetPath(index);
    //      }
    //      /// Assignment inspection
    //      /// Returns the variable index of the node directly after the node
    //      /// corresponding to 'index' in 'assignment'.
    //      int64_t Next(const Assignment& assignment, int64_t index) const;
    //      /// Returns true if the route of 'vehicle' is non empty in 'assignment'.
    //      bool IsVehicleUsed(const Assignment& assignment, int vehicle) const;

    //    #if !defined(SWIGPYTHON)
    //      /// Returns all next variables of the model, such that Nexts(i) is the next
    //      /// variable of the node corresponding to i.
    //      const std::vector<IntVar*>& Nexts() const { return nexts_; }
    //      /// Returns all vehicle variables of the model,  such that VehicleVars(i) is
    //      /// the vehicle variable of the node corresponding to i.
    //      const std::vector<IntVar*>& VehicleVars() const { return vehicle_vars_; }
    //      /// Returns vehicle resource variables for a given resource group, such that
    //      /// ResourceVars(r_g)[v] is the resource variable for vehicle 'v' in resource
    //      /// group 'r_g'.
    //      const std::vector<IntVar*>& ResourceVars(int resource_group) const {
    //        return resource_vars_[resource_group];
    //      }
    //    #endif  /// !defined(SWIGPYTHON)
    //      /// Returns the next variable of the node corresponding to index. Note that
    //      /// NextVar(index) == index is equivalent to ActiveVar(index) == 0.
    //      IntVar* NextVar(int64_t index) const { return nexts_[index]; }
    //      /// Returns the active variable of the node corresponding to index.
    //      IntVar* ActiveVar(int64_t index) const { return active_[index]; }
    //      /// Returns the active variable of the vehicle. It will be equal to 1 iff the
    //      /// route of the vehicle is not empty, 0 otherwise.
    //      IntVar* ActiveVehicleVar(int vehicle) const {
    //        return vehicle_active_[vehicle];
    //      }
    //      /// Returns the variable specifying whether or not the given vehicle route is
    //      /// considered for costs and constraints. It will be equal to 1 iff the route
    //      /// of the vehicle is not empty OR vehicle_used_when_empty_[vehicle] is true.
    //      IntVar* VehicleRouteConsideredVar(int vehicle) const {
    //        return vehicle_route_considered_[vehicle];
    //      }
    //      /// Returns the vehicle variable of the node corresponding to index. Note that
    //      /// VehicleVar(index) == -1 is equivalent to ActiveVar(index) == 0.
    //      IntVar* VehicleVar(int64_t index) const { return vehicle_vars_[index]; }
    //      /// Returns the resource variable for the given vehicle index in the given
    //      /// resource group. If a vehicle doesn't require a resource from the
    //      /// corresponding resource group, then ResourceVar(v, r_g) == -1.
    //      IntVar* ResourceVar(int vehicle, int resource_group) const {
    //        DCHECK_LT(resource_group, resource_vars_.size());
    //        DCHECK_LT(vehicle, resource_vars_[resource_group].size());
    //        return resource_vars_[resource_group][vehicle];
    //      }
    //      /// Returns the global cost variable which is being minimized.
    //      IntVar* CostVar() const { return cost_; }

    //      /// Returns the cost of the transit arc between two nodes for a given vehicle.
    //      /// Input are variable indices of node. This returns 0 if vehicle < 0.
    //      int64_t GetArcCostForVehicle(int64_t from_index, int64_t to_index,
    //                                   int64_t vehicle) const;
    //      /// Whether costs are homogeneous across all vehicles.
    //      bool CostsAreHomogeneousAcrossVehicles() const {
    //        return costs_are_homogeneous_across_vehicles_;
    //      }
    //      /// Returns the cost of the segment between two nodes supposing all vehicle
    //      /// costs are the same (returns the cost for the first vehicle otherwise).
    //      int64_t GetHomogeneousCost(int64_t from_index, int64_t to_index) const {
    //        return GetArcCostForVehicle(from_index, to_index, /*vehicle=*/0);
    //      }
    //      /// Returns the cost of the arc in the context of the first solution strategy.
    //      /// This is typically a simplification of the actual cost; see the .cc.
    //      int64_t GetArcCostForFirstSolution(int64_t from_index,
    //                                         int64_t to_index) const;
    //      /// Returns the cost of the segment between two nodes for a given cost
    //      /// class. Input are variable indices of nodes and the cost class.
    //      /// Unlike GetArcCostForVehicle(), if cost_class is kNoCost, then the
    //      /// returned cost won't necessarily be zero: only some of the components
    //      /// of the cost that depend on the cost class will be omited. See the code
    //      /// for details.
    //      int64_t GetArcCostForClass(int64_t from_index, int64_t to_index,
    //                                 int64_t /*CostClassIndex*/ cost_class_index) const;
    //      /// Get the cost class index of the given vehicle.
    //      CostClassIndex GetCostClassIndexOfVehicle(int64_t vehicle) const {
    //        DCHECK(closed_);
    //        DCHECK_GE(vehicle, 0);
    //        DCHECK_LT(vehicle, cost_class_index_of_vehicle_.size());
    //        DCHECK_GE(cost_class_index_of_vehicle_[vehicle], 0);
    //        return cost_class_index_of_vehicle_[vehicle];
    //      }
    //      /// Returns true iff the model contains a vehicle with the given
    //      /// cost_class_index.
    //      bool HasVehicleWithCostClassIndex(CostClassIndex cost_class_index) const {
    //        DCHECK(closed_);
    //        if (cost_class_index == kCostClassIndexOfZeroCost) {
    //          return has_vehicle_with_zero_cost_class_;
    //        }
    //        return cost_class_index < cost_classes_.size();
    //      }
    //      /// Returns the number of different cost classes in the model.
    //      int GetCostClassesCount() const { return cost_classes_.size(); }
    //      /// Ditto, minus the 'always zero', built-in cost class.
    //      int GetNonZeroCostClassesCount() const {
    //        return std::max(0, GetCostClassesCount() - 1);
    //      }
    //      VehicleClassIndex GetVehicleClassIndexOfVehicle(int64_t vehicle) const {
    //        DCHECK(closed_);
    //        return vehicle_class_index_of_vehicle_[vehicle];
    //      }
    //      /// Returns a vehicle of the given vehicle class, and -1 if there are no
    //      /// vehicles for this class.
    //      int GetVehicleOfClass(VehicleClassIndex vehicle_class) const {
    //        DCHECK(closed_);
    //        const RoutingModel::VehicleTypeContainer& vehicle_type_container =
    //            GetVehicleTypeContainer();
    //        if (vehicle_class.value() >= GetVehicleClassesCount() ||
    //            vehicle_type_container.vehicles_per_vehicle_class[vehicle_class.value()]
    //                .empty()) {
    //          return -1;
    //        }
    //        return vehicle_type_container
    //            .vehicles_per_vehicle_class[vehicle_class.value()]
    //            .front();
    //      }
    //      /// Returns the number of different vehicle classes in the model.
    //      int GetVehicleClassesCount() const { return num_vehicle_classes_; }
    //      /// Returns variable indices of nodes constrained to be on the same route.
    //      const std::vector<int>& GetSameVehicleIndicesOfIndex(int node) const {
    //        DCHECK(closed_);
    //        return same_vehicle_groups_[same_vehicle_group_[node]];
    //      }

    //      const VehicleTypeContainer& GetVehicleTypeContainer() const {
    //        DCHECK(closed_);
    //        return vehicle_type_container_;
    //      }

    //      /// Returns whether the arc from->to1 is more constrained than from->to2,
    //      /// taking into account, in order:
    //      /// - whether the destination node isn't an end node
    //      /// - whether the destination node is mandatory
    //      /// - whether the destination node is bound to the same vehicle as the source
    //      /// - the "primary constrained" dimension (see SetPrimaryConstrainedDimension)
    //      /// It then breaks ties using, in order:
    //      /// - the arc cost (taking unperformed penalties into account)
    //      /// - the size of the vehicle vars of "to1" and "to2" (lowest size wins)
    //      /// - the value: the lowest value of the indices to1 and to2 wins.
    //      /// See the .cc for details.
    //      /// The more constrained arc is typically preferable when building a
    //      /// first solution. This method is intended to be used as a callback for the
    //      /// BestValueByComparisonSelector value selector.
    //      /// Args:
    //      ///   from: the variable index of the source node
    //      ///   to1: the variable index of the first candidate destination node.
    //      ///   to2: the variable index of the second candidate destination node.
    //      bool ArcIsMoreConstrainedThanArc(int64_t from, int64_t to1, int64_t to2);
    //      /// Print some debugging information about an assignment, including the
    //      /// feasible intervals of the CumulVar for dimension "dimension_to_print"
    //      /// at each step of the routes.
    //      /// If "dimension_to_print" is omitted, all dimensions will be printed.
    //      std::string DebugOutputAssignment(
    //          const Assignment& solution_assignment,
    //          const std::string& dimension_to_print) const;
    //      /// Returns a vector cumul_bounds, for which cumul_bounds[i][j] is a pair
    //      /// containing the minimum and maximum of the CumulVar of the jth node on
    //      /// route i.
    //      /// - cumul_bounds[i][j].first is the minimum.
    //      /// - cumul_bounds[i][j].second is the maximum.
    //    #ifndef SWIG
    //      std::vector<std::vector<std::pair<int64_t, int64_t>>> GetCumulBounds(
    //          const Assignment& solution_assignment, const RoutingDimension& dimension);
    //    #endif
    //      /// Checks if an assignment is feasible.
    //      bool CheckIfAssignmentIsFeasible(const Assignment& assignment,
    //                                       bool call_at_solution_monitors);
    //      /// Returns the underlying constraint solver. Can be used to add extra
    //      /// constraints and/or modify search algorithms.
    //      Solver* solver() const { return solver_.get(); }

    //      /// Returns true if the search limit has been crossed with the given time
    //      /// offset.
    //      bool CheckLimit(absl::Duration offset = absl::ZeroDuration()) {
    //        DCHECK(limit_ != nullptr);
    //        return limit_->CheckWithOffset(offset);
    //      }

    //      /// Returns the time left in the search limit.
    //      absl::Duration RemainingTime() const {
    //        DCHECK(limit_ != nullptr);
    //        return limit_->AbsoluteSolverDeadline() - solver_->Now();
    //      }

    //      /// Updates the time limit of the search limit.
    //      void UpdateTimeLimit(absl::Duration time_limit) {
    //        RegularLimit* limit = GetOrCreateLimit();
    //        limit->UpdateLimits(time_limit, std::numeric_limits<int64_t>::max(),
    //                            std::numeric_limits<int64_t>::max(),
    //                            limit->solutions());
    //      }

    //      /// Returns the time buffer to safely return a solution.
    //      absl::Duration TimeBuffer() const { return time_buffer_; }

    //      /// Returns the atomic<bool> to stop the CP-SAT solver.
    //      std::atomic<bool>* GetMutableCPSatInterrupt() { return &interrupt_cp_sat_; }
    //      /// Returns the atomic<bool> to stop the CP solver.
    //      std::atomic<bool>* GetMutableCPInterrupt() { return &interrupt_cp_; }
    //      /// Cancels the current search.
    //      void CancelSearch() {
    //        interrupt_cp_sat_ = true;
    //        interrupt_cp_ = true;
    //      }

    //      /// Sizes and indices
    //      /// Returns the number of nodes in the model.
    //      int nodes() const { return nodes_; }
    //      /// Returns the number of vehicle routes in the model.
    //      int vehicles() const { return vehicles_; }
    //      /// Returns the number of next variables in the model.
    //      int64_t Size() const { return nodes_ + vehicles_ - start_end_count_; }

    //      /// Returns statistics on first solution search, number of decisions sent to
    //      /// filters, number of decisions rejected by filters.
    //      int64_t GetNumberOfDecisionsInFirstSolution(
    //          const RoutingSearchParameters& search_parameters) const;
    //      int64_t GetNumberOfRejectsInFirstSolution(
    //          const RoutingSearchParameters& search_parameters) const;
    //      /// Returns the automatic first solution strategy selected.
    //      operations_research::FirstSolutionStrategy::Value
    //      GetAutomaticFirstSolutionStrategy() const {
    //        return automatic_first_solution_strategy_;
    //      }

    //      /// Returns true if a vehicle/node matching problem is detected.
    //      bool IsMatchingModel() const;

    //      /// Returns true if routes are interdependent. This means that any
    //      /// modification to a route might impact another.
    //      bool AreRoutesInterdependent(const RoutingSearchParameters& parameters) const;

    //    #ifndef SWIG
    //      /// Sets the callback returning the variable to use for the Tabu Search
    //      /// metaheuristic.
    //      using GetTabuVarsCallback =
    //          std::function<std::vector<operations_research::IntVar*>(RoutingModel*)>;

    //      void SetTabuVarsCallback(GetTabuVarsCallback tabu_var_callback);
    //    #endif  // SWIG

    //      /// The next few members are in the public section only for testing purposes.
    //      // TODO(user): Find a way to test and restrict the access at the same time.
    //      ///
    //      /// MakeGuidedSlackFinalizer creates a DecisionBuilder for the slacks of a
    //      /// dimension using a callback to choose which values to start with.
    //      /// The finalizer works only when all next variables in the model have
    //      /// been fixed. It has the following two characteristics:
    //      /// 1. It follows the routes defined by the nexts variables when choosing a
    //      ///    variable to make a decision on.
    //      /// 2. When it comes to choose a value for the slack of node i, the decision
    //      ///    builder first calls the callback with argument i, and supposingly the
    //      ///    returned value is x it creates decisions slack[i] = x, slack[i] = x +
    //      ///    1, slack[i] = x - 1, slack[i] = x + 2, etc.
    //      DecisionBuilder* MakeGuidedSlackFinalizer(
    //          const RoutingDimension* dimension,
    //          std::function<int64_t(int64_t)> initializer);
    //    #ifndef SWIG
    //      // TODO(user): MakeGreedyDescentLSOperator is too general for routing.h.
    //      /// Perhaps move it to constraint_solver.h.
    //      /// MakeGreedyDescentLSOperator creates a local search operator that tries to
    //      /// improve the initial assignment by moving a logarithmically decreasing step
    //      /// away in each possible dimension.
    //      static std::unique_ptr<LocalSearchOperator> MakeGreedyDescentLSOperator(
    //          std::vector<IntVar*> variables);
    //      // Read access to currently registered search monitors.
    //      const std::vector<SearchMonitor*>& GetSearchMonitors() const {
    //        return monitors_;
    //      }
    //    #endif  /// __SWIG__
    //      /// MakeSelfDependentDimensionFinalizer is a finalizer for the slacks of a
    //      /// self-dependent dimension. It makes an extensive use of the caches of the
    //      /// state dependent transits.
    //      /// In detail, MakeSelfDependentDimensionFinalizer returns a composition of a
    //      /// local search decision builder with a greedy descent operator for the cumul
    //      /// of the start of each route and a guided slack finalizer. Provided there
    //      /// are no time windows and the maximum slacks are large enough, once the
    //      /// cumul of the start of route is fixed, the guided finalizer can find
    //      /// optimal values of the slacks for the rest of the route in time
    //      /// proportional to the length of the route. Therefore the composed finalizer
    //      /// generally works in time O(log(t)*n*m), where t is the latest possible
    //      /// departute time, n is the number of nodes in the network and m is the
    //      /// number of vehicles.
    //      DecisionBuilder* MakeSelfDependentDimensionFinalizer(
    //          const RoutingDimension* dimension);

    //      const PathsMetadata& GetPathsMetadata() const { return paths_metadata_; }
    //    #ifndef SWIG
    //      BinCapacities* GetBinCapacities() { return bin_capacities_.get(); }

    //      /// Sets a secondary solver (routing model + parameters) which can be used to
    //      /// run sub-solves while building a first solution.
    //      void SetSecondaryModel(RoutingModel* secondary_model,
    //                             RoutingSearchParameters secondary_parameters) {
    //        DCHECK(!closed_);
    //        secondary_model_ = secondary_model;
    //        secondary_parameters_ = std::move(secondary_parameters);
    //      }
    //    #endif  // SWIG

    //     private:
    //      /// Local search move operator usable in routing.
    //      enum RoutingLocalSearchOperator {
    //        RELOCATE = 0,
    //        RELOCATE_PAIR,
    //        LIGHT_RELOCATE_PAIR,
    //        RELOCATE_NEIGHBORS,
    //        EXCHANGE,
    //        EXCHANGE_PAIR,
    //        CROSS,
    //        CROSS_EXCHANGE,
    //        TWO_OPT,
    //        OR_OPT,
    //        GLOBAL_CHEAPEST_INSERTION_CLOSE_NODES_LNS,
    //        LOCAL_CHEAPEST_INSERTION_CLOSE_NODES_LNS,
    //        GLOBAL_CHEAPEST_INSERTION_PATH_LNS,
    //        LOCAL_CHEAPEST_INSERTION_PATH_LNS,
    //        RELOCATE_PATH_GLOBAL_CHEAPEST_INSERTION_INSERT_UNPERFORMED,
    //        GLOBAL_CHEAPEST_INSERTION_EXPENSIVE_CHAIN_LNS,
    //        LOCAL_CHEAPEST_INSERTION_EXPENSIVE_CHAIN_LNS,
    //        RELOCATE_EXPENSIVE_CHAIN,
    //        LIN_KERNIGHAN,
    //        TSP_OPT,
    //        MAKE_ACTIVE,
    //        RELOCATE_AND_MAKE_ACTIVE,
    //        MAKE_ACTIVE_AND_RELOCATE,
    //        MAKE_INACTIVE,
    //        MAKE_CHAIN_INACTIVE,
    //        SWAP_ACTIVE,
    //        EXTENDED_SWAP_ACTIVE,
    //        SHORTEST_PATH_SWAP_ACTIVE,
    //        NODE_PAIR_SWAP,
    //        PATH_LNS,
    //        FULL_PATH_LNS,
    //        TSP_LNS,
    //        INACTIVE_LNS,
    //        EXCHANGE_RELOCATE_PAIR,
    //        RELOCATE_SUBTRIP,
    //        EXCHANGE_SUBTRIP,
    //        LOCAL_SEARCH_OPERATOR_COUNTER
    //      };

    //      /// Structure storing a value for a set of variable indices. Is used to store
    //      /// data for index disjunctions (variable indices, max_cardinality and penalty
    //      /// when unperformed).
    //      template <typename T>
    //      struct ValuedNodes {
    //        std::vector<int64_t> indices;
    //        T value;
    //      };
    //      struct DisjunctionValues {
    //        int64_t penalty;
    //        int64_t max_cardinality;
    //      };
    //      typedef ValuedNodes<DisjunctionValues> Disjunction;

    //      /// Storage of a cost cache element corresponding to a cost arc ending at
    //      /// node 'index' and on the cost class 'cost_class'.
    //      struct CostCacheElement {
    //        /// This is usually an int64_t, but using an int here decreases the RAM
    //        /// usage, and should be fine since in practice we never have more than
    //        /// 1<<31 vars. Note(user): on 2013-11, microbenchmarks on the arc costs
    //        /// callbacks also showed a 2% speed-up thanks to using int rather than
    //        /// int64_t.
    //        int index;
    //        CostClassIndex cost_class_index;
    //        int64_t cost;
    //      };

    //      /// Internal struct used to store the lp/mp versions of the local and global
    //      /// cumul optimizers for a given dimension.
    //      template <class DimensionCumulOptimizer>
    //      struct DimensionCumulOptimizers {
    //        std::unique_ptr<DimensionCumulOptimizer> lp_optimizer;
    //        std::unique_ptr<DimensionCumulOptimizer> mp_optimizer;
    //      };

    //      /// Internal methods.
    //      void Initialize();
    //      void AddNoCycleConstraintInternal();
    //      bool AddDimensionWithCapacityInternal(
    //          const std::vector<int>& evaluator_indices, int64_t slack_max,
    //          std::vector<int64_t> vehicle_capacities, bool fix_start_cumul_to_zero,
    //          const std::string& name);
    //      bool AddDimensionDependentDimensionWithVehicleCapacityInternal(
    //          const std::vector<int>& pure_transits,
    //          const std::vector<int>& dependent_transits,
    //          const RoutingDimension* base_dimension, int64_t slack_max,
    //          std::vector<int64_t> vehicle_capacities, bool fix_start_cumul_to_zero,
    //          const std::string& name);
    //      bool InitializeDimensionInternal(
    //          const std::vector<int>& evaluator_indices,
    //          const std::vector<int>& state_dependent_evaluator_indices,
    //          int64_t slack_max, bool fix_start_cumul_to_zero,
    //          RoutingDimension* dimension);
    //      DimensionIndex GetDimensionIndex(const std::string& dimension_name) const;

    //      /// Creates global and local cumul optimizers for the dimensions needing them,
    //      /// and stores them in the corresponding [local|global]_dimension_optimizers_
    //      /// vectors.
    //      /// This function also computes and stores the "offsets" for these dimensions,
    //      /// used in the local/global optimizers to simplify LP computations.
    //      ///
    //      /// Note on the offsets computation:
    //      /// The global/local cumul offsets are used by the respective optimizers to
    //      /// have smaller numbers, and therefore better numerical behavior in the LP.
    //      /// These offsets are used as a minimum value for the cumuls over the route
    //      /// (or globally), i.e. a value we consider all cumuls to be greater or equal
    //      /// to. When transits are all positive, the cumuls of every node on a route is
    //      /// necessarily greater than the cumul of its start. Therefore, the local
    //      /// offset for a vehicle can be set to the minimum of its start node's cumul,
    //      /// and for the global optimizers, to the min start cumul over all vehicles.
    //      /// However, to be able to distinguish between infeasible nodes (i.e. nodes
    //      /// for which the cumul upper bound is less than the min cumul of the
    //      /// vehicle's start), we set the offset to "min_start_cumul" - 1. By doing so,
    //      /// all infeasible nodes described above will have bounds of [0, 0]. Example:
    //      /// Start cumul bounds: [11, 20] --> offset = 11 - 1 = 10.
    //      /// Two nodes with cumul bounds. Node1: [5, 10],  Node2: [7, 20]
    //      /// After applying the offset to the above windows, they become:
    //      /// Vehicle: [1, 10].     Node1: [0, 0] (infeasible).     Node2: [0, 10].
    //      ///
    //      /// On the other hand, when transits on a route can be negative, no assumption
    //      /// can be made on the cumuls of nodes wrt the start cumuls, and the offset is
    //      /// therefore set to 0.
    //      void StoreDimensionCumulOptimizers(const RoutingSearchParameters& parameters);

    //      /// The following method looks at node-to-vehicle assignment feasibility
    //      /// based on node transit values on unary dimensions: If the (absolute) value
    //      /// of transit for a node is greater than the vehicle capacity on any
    //      /// dimension, this node cannot be served by this vehicle and the latter is
    //      /// thus removed from allowed_vehicles_[node].
    //      void FinalizeAllowedVehicles();

    //      void ComputeCostClasses(const RoutingSearchParameters& parameters);
    //      void ComputeVehicleClasses();
    //      /// The following method initializes the vehicle_type_container_:
    //      /// - Computes the vehicle types of vehicles and stores it in
    //      ///   type_index_of_vehicle.
    //      /// - The vehicle classes corresponding to each vehicle type index are stored
    //      ///   and sorted by fixed cost in sorted_vehicle_classes_per_type.
    //      /// - The vehicles for each vehicle class are stored in
    //      ///   vehicles_per_vehicle_class.
    //      void ComputeVehicleTypes();
    //      /// Computes resource classes for all resource groups in the model.
    //      void ComputeResourceClasses();
    //      /// This method scans the visit types and sets up the following members:
    //      /// - single_nodes_of_type_[type] contains indices of nodes of visit type
    //      ///   "type" which are not part of any pickup/delivery pair.
    //      /// - pair_indices_of_type_[type] is the set of "pair_index" such that
    //      ///   pickup_delivery_pairs_[pair_index] has at least one pickup or delivery
    //      ///   with visit type "type".
    //      /// - topologically_sorted_visit_types_ contains the visit types in
    //      ///   topological order based on required-->dependent arcs from the
    //      ///   visit type requirements.
    //      void FinalizeVisitTypes();
    //      // Called by FinalizeVisitTypes() to setup topologically_sorted_visit_types_.
    //      void TopologicallySortVisitTypes();
    //      int64_t GetArcCostForClassInternal(int64_t from_index, int64_t to_index,
    //                                         CostClassIndex cost_class_index) const;
    //      void AppendHomogeneousArcCosts(const RoutingSearchParameters& parameters,
    //                                     int node_index,
    //                                     std::vector<IntVar*>* cost_elements);
    //      void AppendArcCosts(const RoutingSearchParameters& parameters, int node_index,
    //                          std::vector<IntVar*>* cost_elements);
    //      Assignment* DoRestoreAssignment();
    //      static const CostClassIndex kCostClassIndexOfZeroCost;
    //      int64_t SafeGetCostClassInt64OfVehicle(int64_t vehicle) const {
    //        DCHECK_LT(0, vehicles_);
    //        return (vehicle >= 0 ? GetCostClassIndexOfVehicle(vehicle)
    //                             : kCostClassIndexOfZeroCost)
    //            .value();
    //      }
    //      int64_t GetDimensionTransitCostSum(int64_t i, int64_t j,
    //                                         const CostClass& cost_class) const;
    //      /// Returns nullptr if no penalty cost, otherwise returns penalty variable.
    //      IntVar* CreateDisjunction(DisjunctionIndex disjunction);
    //      /// Sets up pickup and delivery sets.
    //      void AddPickupAndDeliverySetsInternal(const std::vector<int64_t>& pickups,
    //                                            const std::vector<int64_t>& deliveries);
    //      /// Returns the cost variable related to the soft same vehicle constraint of
    //      /// index 'vehicle_index'.
    //      IntVar* CreateSameVehicleCost(int vehicle_index);
    //      /// Returns the first active variable index in 'indices' starting from index
    //      /// + 1.
    //      int FindNextActive(int index, const std::vector<int64_t>& indices) const;

    //      /// Checks that all nodes on the route starting at start_index (using the
    //      /// solution stored in assignment) can be visited by the given vehicle.
    //      bool RouteCanBeUsedByVehicle(const Assignment& assignment, int start_index,
    //                                   int vehicle) const;
    //      /// Replaces the route of unused_vehicle with the route of active_vehicle in
    //      /// compact_assignment. Expects that unused_vehicle is a vehicle with an empty
    //      /// route and that the route of active_vehicle is non-empty. Also expects that
    //      /// 'assignment' contains the original assignment, from which
    //      /// compact_assignment was created.
    //      /// Returns true if the vehicles were successfully swapped; otherwise, returns
    //      /// false.
    //      bool ReplaceUnusedVehicle(int unused_vehicle, int active_vehicle,
    //                                Assignment* compact_assignment) const;

    //      void QuietCloseModel();
    //      void QuietCloseModelWithParameters(
    //          const RoutingSearchParameters& parameters) {
    //        if (!closed_) {
    //          CloseModelWithParameters(parameters);
    //        }
    //      }

    //      /// Solve matching problem with min-cost flow and store result in assignment.
    //      bool SolveMatchingModel(Assignment* assignment,
    //                              const RoutingSearchParameters& parameters);
    //    #ifndef SWIG
    //      /// Append an assignment to a vector of assignments if it is feasible.
    //      bool AppendAssignmentIfFeasible(
    //          const Assignment& assignment,
    //          std::vector<std::unique_ptr<Assignment>>* assignments,
    //          bool call_at_solution_monitors = true);
    //    #endif
    //      /// Log a solution.
    //      void LogSolution(const RoutingSearchParameters& parameters,
    //                       absl::string_view description, int64_t solution_cost,
    //                       int64_t start_time_ms);
    //      /// See CompactAssignment. Checks the final solution if
    //      /// check_compact_assignment is true.
    //      Assignment* CompactAssignmentInternal(const Assignment& assignment,
    //                                            bool check_compact_assignment) const;
    //      /// Checks that the current search parameters are valid for the current
    //      /// model's specific settings.
    //      std::string FindErrorInSearchParametersForModel(
    //          const RoutingSearchParameters& search_parameters) const;
    //      /// Sets up search objects, such as decision builders and monitors.
    //      void SetupSearch(const RoutingSearchParameters& search_parameters);
    //      /// Set of auxiliary methods used to setup the search.
    //      // TODO(user): Document each auxiliary method.
    //      Assignment* GetOrCreateAssignment();
    //      Assignment* GetOrCreateTmpAssignment();
    //      RegularLimit* GetOrCreateLimit();
    //      RegularLimit* GetOrCreateCumulativeLimit();
    //      RegularLimit* GetOrCreateLocalSearchLimit();
    //      RegularLimit* GetOrCreateLargeNeighborhoodSearchLimit();
    //      RegularLimit* GetOrCreateFirstSolutionLargeNeighborhoodSearchLimit();
    //      LocalSearchOperator* CreateInsertionOperator();
    //      LocalSearchOperator* CreateMakeInactiveOperator();
    //    #ifndef SWIG
    //      template <class T>
    //      LocalSearchOperator* CreateCPOperator(const T& operator_factory) {
    //        return operator_factory(solver_.get(), nexts_,
    //                                CostsAreHomogeneousAcrossVehicles()
    //                                    ? std::vector<IntVar*>()
    //                                    : vehicle_vars_,
    //                                vehicle_start_class_callback_);
    //      }
    //      template <class T>
    //      LocalSearchOperator* CreateCPOperator() {
    //        return CreateCPOperator(MakeLocalSearchOperator<T>);
    //      }
    //      using NeighborAccessor = std::function<const std::vector<int>&(int, int)>;
    //      template <class T>
    //      LocalSearchOperator* CreateCPOperatorWithNeighbors(
    //          NeighborAccessor get_neighbors) {
    //        return CreateCPOperatorWithNeighbors(
    //            MakeLocalSearchOperatorWithNeighbors<T>, std::move(get_neighbors));
    //      }
    //      template <class T>
    //      LocalSearchOperator* CreateOperatorWithNeighborsRatio(
    //          int neighbors_ratio_used, NeighborAccessor get_neighbors) {
    //        return neighbors_ratio_used == 1
    //                   ? CreateCPOperator<T>()
    //                   : CreateCPOperatorWithNeighbors<T>(std::move(get_neighbors));
    //      }
    //      template <class T>
    //      LocalSearchOperator* CreateCPOperatorWithNeighbors(
    //          const T& operator_factory, NeighborAccessor get_neighbors) {
    //        return operator_factory(
    //            solver_.get(), nexts_,
    //            CostsAreHomogeneousAcrossVehicles() ? std::vector<IntVar*>()
    //                                                : vehicle_vars_,
    //            vehicle_start_class_callback_, std::move(get_neighbors));
    //      }
    //      template <class T, class Arg>
    //      LocalSearchOperator* CreateOperator(const Arg& arg) {
    //        return solver_->RevAlloc(new T(nexts_,
    //                                       CostsAreHomogeneousAcrossVehicles()
    //                                           ? std::vector<IntVar*>()
    //                                           : vehicle_vars_,
    //                                       vehicle_start_class_callback_, arg));
    //      }
    //      template <class T, class Arg>
    //      LocalSearchOperator* CreateOperatorWithNeighbors(
    //          NeighborAccessor get_neighbors, const Arg& arg) {
    //        return solver_->RevAlloc(
    //            new T(nexts_,
    //                  CostsAreHomogeneousAcrossVehicles() ? std::vector<IntVar*>()
    //                                                      : vehicle_vars_,
    //                  vehicle_start_class_callback_, std::move(get_neighbors), arg));
    //      }
    //      template <class T, class Arg>
    //      LocalSearchOperator* CreateOperatorWithNeighborsRatio(
    //          int neighbors_ratio_used, NeighborAccessor get_neighbors,
    //          const Arg& arg) {
    //        return neighbors_ratio_used == 1
    //                   ? CreateOperator<T>(arg)
    //                   : CreateOperatorWithNeighbors<T>(std::move(get_neighbors), arg);
    //      }
    //      template <class T, class Arg1, class MoveableArg2>
    //      LocalSearchOperator* CreateOperator(const Arg1& arg1, MoveableArg2 arg2) {
    //        return solver_->RevAlloc(
    //            new T(nexts_,
    //                  CostsAreHomogeneousAcrossVehicles() ? std::vector<IntVar*>()
    //                                                      : vehicle_vars_,
    //                  vehicle_start_class_callback_, arg1, std::move(arg2)));
    //      }
    //      template <class T, class Arg1, class MoveableArg2>
    //      LocalSearchOperator* CreateOperatorWithNeighborsRatio(
    //          int neighbors_ratio_used, NeighborAccessor get_neighbors,
    //          const Arg1& arg1, MoveableArg2 arg2) {
    //        return neighbors_ratio_used == 1
    //                   ? CreateOperator<T>(arg1, std::move(arg2))
    //                   : solver_->RevAlloc(new T(nexts_,
    //                                             CostsAreHomogeneousAcrossVehicles()
    //                                                 ? std::vector<IntVar*>()
    //                                                 : vehicle_vars_,
    //                                             vehicle_start_class_callback_,
    //                                             std::move(get_neighbors), arg1,
    //                                             std::move(arg2)));
    //      }
    //      template <class T>
    //      LocalSearchOperator* CreatePairOperator() {
    //        return CreateOperator<T>(pickup_delivery_pairs_);
    //      }
    //      template <class T>
    //      LocalSearchOperator* CreatePairOperator(int neighbors_ratio_used,
    //                                              NeighborAccessor get_neighbors) {
    //        return neighbors_ratio_used == 1
    //                   ? CreateOperator<T>(pickup_delivery_pairs_)
    //                   : CreateOperatorWithNeighbors<T>(std::move(get_neighbors),
    //                                                    pickup_delivery_pairs_);
    //      }
    //    #endif  // SWIG
    //      void CreateNeighborhoodOperators(const RoutingSearchParameters& parameters);
    //      LocalSearchOperator* ConcatenateOperators(
    //          const RoutingSearchParameters& search_parameters,
    //          const std::vector<LocalSearchOperator*>& operators) const;
    //      LocalSearchOperator* GetNeighborhoodOperators(
    //          const RoutingSearchParameters& search_parameters,
    //          const absl::flat_hash_set<RoutingLocalSearchOperator>&
    //              operators_to_consider) const;

    //      struct FilterOptions {
    //        bool filter_objective;
    //        bool filter_with_cp_solver;

    //        bool operator==(const FilterOptions& other) const {
    //          return other.filter_objective == filter_objective &&
    //                 other.filter_with_cp_solver == filter_with_cp_solver;
    //        }
    //        template <typename H>
    //        friend H AbslHashValue(H h, const FilterOptions& options) {
    //          return H::combine(std::move(h), options.filter_objective,
    //                            options.filter_with_cp_solver);
    //        }
    //      };
    //      std::vector<LocalSearchFilterManager::FilterEvent> CreateLocalSearchFilters(
    //          const RoutingSearchParameters& parameters, const FilterOptions& options);
    //      LocalSearchFilterManager* GetOrCreateLocalSearchFilterManager(
    //          const RoutingSearchParameters& parameters, const FilterOptions& options);
    //      DecisionBuilder* CreateSolutionFinalizer(
    //          const RoutingSearchParameters& parameters, SearchLimit* lns_limit);
    //      void CreateFirstSolutionDecisionBuilders(
    //          const RoutingSearchParameters& search_parameters);
    //      DecisionBuilder* GetFirstSolutionDecisionBuilder(
    //          const RoutingSearchParameters& search_parameters) const;
    //      IntVarFilteredDecisionBuilder* GetFilteredFirstSolutionDecisionBuilderOrNull(
    //          const RoutingSearchParameters& parameters) const;
    //    #ifndef SWIG
    //      template <typename Heuristic, typename... Args>
    //      IntVarFilteredDecisionBuilder* CreateIntVarFilteredDecisionBuilder(
    //          const Args&... args);
    //    #endif
    //      LocalSearchPhaseParameters* CreateLocalSearchParameters(
    //          const RoutingSearchParameters& search_parameters, bool secondary_ls);
    //      DecisionBuilder* CreatePrimaryLocalSearchDecisionBuilder(
    //          const RoutingSearchParameters& search_parameters);
    //      void SetupDecisionBuilders(const RoutingSearchParameters& search_parameters);
    //      void SetupMetaheuristics(const RoutingSearchParameters& search_parameters);
    //      void SetupAssignmentCollector(
    //          const RoutingSearchParameters& search_parameters);
    //      void SetupTrace(const RoutingSearchParameters& search_parameters);
    //      void SetupImprovementLimit(const RoutingSearchParameters& search_parameters);
    //      void SetupSearchMonitors(const RoutingSearchParameters& search_parameters);
    //      bool UsesLightPropagation(
    //          const RoutingSearchParameters& search_parameters) const;
    //      GetTabuVarsCallback tabu_var_callback_;

    //      // Detects implicit pickup delivery pairs. These pairs are
    //      // non-pickup/delivery pairs for which there exists a unary dimension such
    //      // that the demand d of the implicit pickup is positive and the demand of the
    //      // implicit delivery is equal to -d.
    //      void DetectImplicitPickupAndDeliveries();

    //      int GetVehicleStartClass(int64_t start) const;

    //      void InitSameVehicleGroups(int number_of_groups) {
    //        same_vehicle_group_.assign(Size(), 0);
    //        same_vehicle_groups_.assign(number_of_groups, {});
    //      }
    //      void SetSameVehicleGroup(int index, int group) {
    //        same_vehicle_group_[index] = group;
    //        same_vehicle_groups_[group].push_back(index);
    //      }

    //      /// Returns the internal global/local optimizer index for the given dimension
    //      /// if any, and -1 otherwise.
    //      int GetGlobalCumulOptimizerIndex(const RoutingDimension& dimension) const;
    //      int GetLocalCumulOptimizerIndex(const RoutingDimension& dimension) const;

    //      /// Model
    //      std::unique_ptr<Solver> solver_;
    //      int nodes_;
    //      int vehicles_;
    //      int max_active_vehicles_;
    //      Constraint* no_cycle_constraint_ = nullptr;
    //      /// Decision variables: indexed by int64_t var index.
    //      std::vector<IntVar*> nexts_;
    //      std::vector<IntVar*> vehicle_vars_;
    //      std::vector<IntVar*> active_;
    //      /// Resource variables, indexed first by resource group index and then by
    //      /// vehicle index. A resource variable can have a negative value of -1, iff
    //      /// the corresponding vehicle doesn't require a resource from this resource
    //      /// group, OR if the vehicle is unused (i.e. no visits on its route and
    //      /// vehicle_used_when_empty_[v] is false).
    //      // clang-format off
    //      std::vector<std::vector<IntVar*> > resource_vars_;
    //      // clang-format on
    //      // The following vectors are indexed by vehicle index.
    //      std::vector<IntVar*> vehicle_active_;
    //      std::vector<IntVar*> vehicle_route_considered_;
    //      /// is_bound_to_end_[i] will be true iff the path starting at var #i is fully
    //      /// bound and reaches the end of a route, i.e. either:
    //      /// - IsEnd(i) is true
    //      /// - or nexts_[i] is bound and is_bound_to_end_[nexts_[i].Value()] is true.
    //      std::vector<IntVar*> is_bound_to_end_;
    //      mutable RevSwitch is_bound_to_end_ct_added_;
    //      /// Dimensions
    //      absl::flat_hash_map<std::string, DimensionIndex> dimension_name_to_index_;
    //      util_intops::StrongVector<DimensionIndex, RoutingDimension*> dimensions_;
    //      /// Resource Groups.
    //      /// If resource_groups_ is not empty, then for each group of resources, each
    //      /// (used) vehicle must be assigned to exactly 1 resource, and each resource
    //      /// can in turn be assigned to at most 1 vehicle.
    //      // clang-format off
    //      std::vector<std::unique_ptr<ResourceGroup> > resource_groups_;
    //      /// Stores the set of resource groups related to each dimension.
    //      util_intops::StrongVector<DimensionIndex, std::vector<int> >
    //          dimension_resource_group_indices_;

    //      /// TODO(user): Define a new Dimension[Global|Local]OptimizerIndex type
    //      /// and use it to define ITIVectors and for the dimension to optimizer index
    //      /// mappings below.
    //      std::vector<DimensionCumulOptimizers<GlobalDimensionCumulOptimizer> >
    //          global_dimension_optimizers_;
    //      util_intops::StrongVector<DimensionIndex, int> global_optimizer_index_;
    //      std::vector<DimensionCumulOptimizers<LocalDimensionCumulOptimizer> >
    //          local_dimension_optimizers_;
    //      util_intops::StrongVector<DimensionIndex, int> local_optimizer_index_;
    //      // clang-format on
    //      std::string primary_constrained_dimension_;
    //      /// Costs
    //      IntVar* cost_ = nullptr;
    //      std::vector<int> vehicle_to_transit_cost_;
    //      std::vector<int64_t> fixed_cost_of_vehicle_;
    //      std::vector<CostClassIndex> cost_class_index_of_vehicle_;
    //      bool has_vehicle_with_zero_cost_class_;
    //      std::vector<int64_t> linear_cost_factor_of_vehicle_;
    //      std::vector<int64_t> quadratic_cost_factor_of_vehicle_;
    //      bool vehicle_amortized_cost_factors_set_;
    //      /// vehicle_used_when_empty_[vehicle] determines if "vehicle" should be
    //      /// taken into account for costs (arc costs, span costs, etc.) and constraints
    //      /// (eg. resources) even when the route of the vehicle is empty (i.e. goes
    //      /// straight from its start to its end).
    //      ///
    //      /// NOTE1: A vehicle's fixed cost is added iff the vehicle serves nodes on its
    //      /// route, regardless of this variable's value.
    //      ///
    //      /// NOTE2: The default value for this boolean is 'false' for all vehicles,
    //      /// i.e. by default empty routes will not contribute to the cost nor be
    //      /// considered for constraints.
    //      std::vector<bool> vehicle_used_when_empty_;
    //    #ifndef SWIG
    //      absl::flat_hash_map<std::pair<std::string, std::string>, std::vector<int64_t>,
    //                          absl::Hash<std::pair<std::string, std::string>>>
    //          force_distance_to_vehicle_unit_costs_;
    //      util_intops::StrongVector<CostClassIndex, CostClass> cost_classes_;
    //    #endif  // SWIG
    //      bool costs_are_homogeneous_across_vehicles_;
    //      bool cache_callbacks_;
    //      mutable std::vector<CostCacheElement> cost_cache_;  /// Index by source index.
    //      std::vector<VehicleClassIndex> vehicle_class_index_of_vehicle_;
    //      int num_vehicle_classes_;

    //      VehicleTypeContainer vehicle_type_container_;
    //      std::function<int(int64_t)> vehicle_start_class_callback_;
    //      /// Disjunctions
    //      util_intops::StrongVector<DisjunctionIndex, Disjunction> disjunctions_;
    //      // clang-format off
    //      std::vector<std::vector<DisjunctionIndex> > index_to_disjunctions_;
    //      /// Same vehicle costs
    //      std::vector<ValuedNodes<int64_t> > same_vehicle_costs_;
    //      /// Allowed vehicles
    //    #ifndef SWIG
    //      std::vector<absl::flat_hash_set<int>> allowed_vehicles_;
    //    #endif  // SWIG
    //      /// Pickup and delivery
    //      std::vector<PickupDeliveryPair> pickup_delivery_pairs_;
    //      std::vector<PickupDeliveryPair>
    //          implicit_pickup_delivery_pairs_without_alternatives_;
    //      std::vector<std::pair<DisjunctionIndex, DisjunctionIndex> >
    //          pickup_delivery_disjunctions_;
    //      // If node_index is a pickup, index_to_pickup_positions_[node_index] contains
    //      // all the PickupDeliveryPosition {pickup_delivery_index, alternative_index}
    //      // such that (pickup_delivery_pairs_[pickup_delivery_index]
    //      //               .pickup_alternatives)[alternative_index] == node_index
    //      std::vector<std::vector<PickupDeliveryPosition>> index_to_pickup_positions_;
    //      // Same as above for deliveries.
    //      std::vector<std::vector<PickupDeliveryPosition>> index_to_delivery_positions_;
    //      // clang-format on
    //      std::vector<PickupAndDeliveryPolicy> vehicle_pickup_delivery_policy_;
    //      // Same vehicle group to which a node belongs.
    //      std::vector<int> same_vehicle_group_;
    //      // Same vehicle node groups.
    //      std::vector<std::vector<int>> same_vehicle_groups_;
    //      // Node visit types
    //      // Variable index to visit type index.
    //      std::vector<int> index_to_visit_type_;
    //      // Variable index to VisitTypePolicy.
    //      std::vector<VisitTypePolicy> index_to_type_policy_;
    //      // clang-format off
    //      std::vector<std::vector<int> > single_nodes_of_type_;
    //      std::vector<std::vector<int> > pair_indices_of_type_;

    //      std::vector<absl::flat_hash_set<int> >
    //          hard_incompatible_types_per_type_index_;
    //      bool has_hard_type_incompatibilities_;
    //      std::vector<absl::flat_hash_set<int> >
    //          temporal_incompatible_types_per_type_index_;
    //      bool has_temporal_type_incompatibilities_;

    //      std::vector<std::vector<absl::flat_hash_set<int> > >
    //          same_vehicle_required_type_alternatives_per_type_index_;
    //      bool has_same_vehicle_type_requirements_;
    //      std::vector<std::vector<absl::flat_hash_set<int> > >
    //          required_type_alternatives_when_adding_type_index_;
    //      std::vector<std::vector<absl::flat_hash_set<int> > >
    //          required_type_alternatives_when_removing_type_index_;
    //      bool has_temporal_type_requirements_;
    //      absl::flat_hash_map</*type*/int, absl::flat_hash_set<VisitTypePolicy> >
    //          trivially_infeasible_visit_types_to_policies_;

    //      // Visit types sorted topologically based on required-->dependent requirement
    //      // arcs between the types (if the requirement/dependency graph is acyclic).
    //      // Visit types of the same topological level are sorted in each sub-vector
    //      // by decreasing requirement "tightness", computed as the pair of the two
    //      // following criteria:
    //      //
    //      // 1) How highly *dependent* this type is, determined by
    //      //    (total number of required alternative sets for that type)
    //      //        / (average number of types in the required alternative sets)
    //      // 2) How highly *required* this type t is, computed as
    //      //    SUM_{S required set containing t} ( 1 / |S| ),
    //      //    i.e. the sum of reverse number of elements of all required sets
    //      //    containing the type t.
    //      //
    //      // The higher these two numbers, the tighter the type is wrt requirements.
    //      std::vector<std::vector<int> > topologically_sorted_visit_types_;
    //      // clang-format on
    //      int num_visit_types_;
    //      // Two indices are equivalent if they correspond to the same node (as given
    //      // to the constructors taking a RoutingIndexManager).
    //      std::vector<int> index_to_equivalence_class_;
    //      const PathsMetadata paths_metadata_;
    //      // TODO(user): b/62478706 Once the port is done, this shouldn't be needed
    //      //                  anymore.
    //      RoutingIndexManager manager_;
    //      int start_end_count_;
    //      // Model status
    //      bool closed_ = false;
    //      Status status_ = ROUTING_NOT_SOLVED;
    //      bool enable_deep_serialization_ = true;

    //      // Secondary routing solver
    //      RoutingModel* secondary_model_ = nullptr;
    //      RoutingSearchParameters secondary_parameters_;
    //      std::unique_ptr<SecondaryOptimizer> secondary_optimizer_;

    //      // Search data
    //      std::vector<DecisionBuilder*> first_solution_decision_builders_;
    //      std::vector<IntVarFilteredDecisionBuilder*>
    //          first_solution_filtered_decision_builders_;
    //      Solver::IndexEvaluator2 first_solution_evaluator_;
    //      FirstSolutionStrategy::Value automatic_first_solution_strategy_ =
    //          FirstSolutionStrategy::UNSET;
    //      std::vector<LocalSearchOperator*> local_search_operators_;
    //      std::vector<SearchMonitor*> monitors_;
    //      std::vector<SearchMonitor*> secondary_ls_monitors_;
    //      std::vector<SearchMonitor*> at_solution_monitors_;
    //      SearchMonitor* metaheuristic_ = nullptr;
    //      SearchMonitor* search_log_ = nullptr;
    //      bool local_optimum_reached_ = false;
    //      // Best lower bound found during the search.
    //      int64_t objective_lower_bound_ = kint64min;
    //      SolutionCollector* collect_assignments_ = nullptr;
    //      SolutionCollector* collect_secondary_ls_assignments_ = nullptr;
    //      SolutionCollector* collect_one_assignment_ = nullptr;
    //      SolutionCollector* optimized_dimensions_assignment_collector_ = nullptr;
    //      DecisionBuilder* solve_db_ = nullptr;
    //      DecisionBuilder* improve_db_ = nullptr;
    //      DecisionBuilder* secondary_ls_db_ = nullptr;
    //      DecisionBuilder* restore_assignment_ = nullptr;
    //      DecisionBuilder* restore_tmp_assignment_ = nullptr;
    //      Assignment* assignment_ = nullptr;
    //      Assignment* preassignment_ = nullptr;
    //      Assignment* tmp_assignment_ = nullptr;
    //      LocalSearchOperator* primary_ls_operator_ = nullptr;
    //      LocalSearchOperator* secondary_ls_operator_ = nullptr;
    //      std::vector<IntVar*> extra_vars_;
    //      std::vector<IntervalVar*> extra_intervals_;
    //      std::vector<LocalSearchOperator*> extra_operators_;
    //      absl::flat_hash_map<FilterOptions, LocalSearchFilterManager*>
    //          local_search_filter_managers_;
    //      std::vector<LocalSearchFilterManager::FilterEvent> extra_filters_;
    //      struct NodeNeighborsParameters {
    //        int num_neighbors;
    //        bool add_vehicle_starts_to_neighbors;

    //        bool operator==(const NodeNeighborsParameters& other) const {
    //          return num_neighbors == other.num_neighbors &&
    //                 add_vehicle_starts_to_neighbors ==
    //                     other.add_vehicle_starts_to_neighbors;
    //        }
    //        template <typename H>
    //        friend H AbslHashValue(H h, const NodeNeighborsParameters& params) {
    //          return H::combine(std::move(h), params.num_neighbors,
    //                            params.add_vehicle_starts_to_neighbors);
    //        }
    //      };
    //      absl::flat_hash_map<NodeNeighborsParameters,
    //                          std::unique_ptr<NodeNeighborsByCostClass>>
    //          node_neighbors_by_cost_class_per_size_;
    //      std::unique_ptr<FinalizerVariables> finalizer_variables_;
    //    #ifndef SWIG
    //      std::unique_ptr<SweepArranger> sweep_arranger_;
    //    #endif

    //      RegularLimit* limit_ = nullptr;
    //      RegularLimit* cumulative_limit_ = nullptr;
    //      RegularLimit* ls_limit_ = nullptr;
    //      RegularLimit* lns_limit_ = nullptr;
    //      RegularLimit* first_solution_lns_limit_ = nullptr;
    //      absl::Duration time_buffer_;

    //      std::atomic<bool> interrupt_cp_sat_;
    //      std::atomic<bool> interrupt_cp_;

    //      typedef std::pair<int64_t, int64_t> CacheKey;
    //      typedef absl::flat_hash_map<CacheKey, int64_t> TransitCallbackCache;
    //      typedef absl::flat_hash_map<CacheKey, StateDependentTransit>
    //          StateDependentTransitCallbackCache;

    //      // All transit callbacks are stored in transit_evaluators_,
    //      // we refer to callbacks by the index in this vector.
    //      // We maintain unary_transit_evaluators_[] (with the same size) to store
    //      // callbacks that are unary:
    //      // - if a callback is unary, it is in unary_transit_evaluators_[i],
    //      //   and a binary version is stored at transit_evaluators_[i].
    //      // - if a callback is binary, it is stored at transit_evaluators_[i],
    //      //   and unary_transit_evaluators_[i] is nullptr.
    //      std::vector<TransitCallback1> unary_transit_evaluators_;
    //      std::vector<TransitCallback2> transit_evaluators_;
    //      std::vector<TransitEvaluatorSign> transit_evaluator_sign_;

    //      std::vector<VariableIndexEvaluator2> state_dependent_transit_evaluators_;
    //      std::vector<std::unique_ptr<StateDependentTransitCallbackCache>>
    //          state_dependent_transit_evaluators_cache_;

    //      // Returns global BinCapacities state, may be nullptr.
    //      std::unique_ptr<BinCapacities> bin_capacities_;

    //      friend class RoutingDimension;
    //      friend class RoutingModelInspector;
    //      friend class ResourceGroup::Resource;
};
