//template <typename NodeIndexType = int32_t, typename ArcIndexType = int32_t>
export class StaticGraph
{
    // typedef BaseGraph<NodeIndexType, ArcIndexType, false> Base;
    // using Base::arc_capacity_;
    // using Base::const_capacities_;
    // using Base::node_capacity_;
    // using Base::num_arcs_;
    // using Base::num_nodes_;

    //public:
    // using Base::IsArcValid;
    // StaticGraph() : is_built_(false), arc_in_order_(true), last_tail_seen_(0) {}
    // StaticGraph(NodeIndexType num_nodes, ArcIndexType arc_capacity)
    //     : is_built_(false), arc_in_order_(true), last_tail_seen_(0) {
    //   this->Reserve(num_nodes, arc_capacity);
    //   this->FreezeCapacities();
    //   this->AddNode(num_nodes - 1);
    // }

    // // Shortcut to directly create a finalized graph, i.e. Build() is called.
    // template <class ArcContainer>  // e.g. vector<pair<int, int>>.
    // static StaticGraph FromArcs(NodeIndexType num_nodes,
    //                             const ArcContainer& arcs);

    // // Do not use directly. See instead the arc iteration functions below.
    // class OutgoingArcIterator;

    // NodeIndexType Head(ArcIndexType arc) const;
    // NodeIndexType Tail(ArcIndexType arc) const;
    // ArcIndexType OutDegree(NodeIndexType node) const;  // Work in O(1).
    // BeginEndWrapper<OutgoingArcIterator> OutgoingArcs(NodeIndexType node) const;
    // BeginEndWrapper<OutgoingArcIterator> OutgoingArcsStartingFrom(
    //     NodeIndexType node, ArcIndexType from) const;

    // // This loops over the heads of the OutgoingArcs(node). It is just a more
    // // convenient way to achieve this. Moreover this interface is used by some
    // // graph algorithms.
    // absl::Span<const NodeIndexType> operator[](NodeIndexType node) const;

    // void ReserveNodes(NodeIndexType bound) override;
    // void ReserveArcs(ArcIndexType bound) override;
    // void AddNode(NodeIndexType node);
    AddArc(tail: NodeIndexType, head: NodeIndexType): ArcIndexType;

    // void Build() { Build(nullptr); }
    Build(permutation: number[]): void;

    //private:
    // ArcIndexType DirectArcLimit(NodeIndexType node) const {
    //   DCHECK(is_built_);
    //   DCHECK(Base::IsNodeValid(node));
    //   return node + 1 < num_nodes_ ? start_[node + 1] : num_arcs_;
    // }

    // bool is_built_;
    // bool arc_in_order_;
    // NodeIndexType last_tail_seen_;
    // std::vector<ArcIndexType> start_;
    // std::vector<NodeIndexType> head_;
    // std::vector<NodeIndexType> tail_;
};
