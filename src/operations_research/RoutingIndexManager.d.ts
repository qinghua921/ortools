export class RoutingIndexManager
{
    // public:
    //  typedef RoutingNodeIndex NodeIndex;
    //  static const int64_t kUnassigned;

    constructor(num_nodes: number, num_vehicles: number, depot: number);
    //  RoutingIndexManager(int num_nodes, int num_vehicles,
    //                      const std::vector<NodeIndex>& starts,
    //                      const std::vector<NodeIndex>& ends);
    //  RoutingIndexManager(
    //      int num_nodes, int num_vehicles,
    //      const std::vector<std::pair<NodeIndex, NodeIndex> >& starts_ends);

    //  // Returns the number of nodes in the manager.
    //  int num_nodes() const { return num_nodes_; }
    //  // Returns the number of vehicles in the manager.
    //  int num_vehicles() const { return num_vehicles_; }
    //  // Returns the number of indices mapped to nodes.
    //  int num_indices() const { return index_to_node_.size(); }
    //  // Returns start and end indices of the given vehicle.
    //  int64_t GetStartIndex(int vehicle) const {
    //    return vehicle_to_start_[vehicle];
    //  }
    //  int64_t GetEndIndex(int vehicle) const { return vehicle_to_end_[vehicle]; }
    //  // Returns the index of a node. A node can correspond to multiple indices if
    //  // it's a start or end node. As of 03/2020, kUnassigned will be returned for
    //  // all end nodes. If a node appears more than once as a start node, the index
    //  // of the first node in the list of start nodes is returned.
    //  int64_t NodeToIndex(NodeIndex node) const {
    //    DCHECK_GE(node.value(), 0);
    //    DCHECK_LT(node.value(), node_to_index_.size());
    //    return node_to_index_[node];
    //  }
    //  // Same as NodeToIndex but for a given vector of nodes.
    //  std::vector<int64_t> NodesToIndices(
    //      const std::vector<NodeIndex>& nodes) const;
    IndexToNode(index: number): number;

    //  // Same as IndexToNode but for a given vector of indices.
    //  std::vector<NodeIndex> IndicesToNodes(
    //      const std::vector<int64_t>& indices) const;
    //  // TODO(user) Add unit tests for NodesToIndices and IndicesToNodes.
    //  // TODO(user): Remove when removal of NodeIndex from RoutingModel is
    //  /// complete.
    //  int num_unique_depots() const { return num_unique_depots_; }
    //  std::vector<NodeIndex> GetIndexToNodeMap() const { return index_to_node_; }

    // private:
    //  void Initialize(
    //      int num_nodes, int num_vehicles,
    //      const std::vector<std::pair<NodeIndex, NodeIndex> >& starts_ends);

    //  std::vector<NodeIndex> index_to_node_;
    //  util_intops::StrongVector<NodeIndex, int64_t> node_to_index_;
    //  std::vector<int64_t> vehicle_to_start_;
    //  std::vector<int64_t> vehicle_to_end_;
    //  int num_nodes_;
    //  int num_vehicles_;
    //  int num_unique_depots_;
};
