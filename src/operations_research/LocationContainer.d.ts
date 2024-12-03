export class LocationContainer
{
    // public:
    constructor(speed: number, use_deterministic_seed: boolean);
    //  void AddLocation(int64_t x, int64_t y) {
    //    locations_.push_back(Location(x, y));
    //  }
    //  void AddRandomLocation(int64_t x_max, int64_t y_max);
    //  void AddRandomLocation(int64_t x_max, int64_t y_max, int duplicates);

    ManhattanDistance(from: number, to: number): number;
    //  int64_t NegManhattanDistance(RoutingIndexManager::NodeIndex from,
    //                               RoutingIndexManager::NodeIndex to) const;
    //  int64_t ManhattanTime(RoutingIndexManager::NodeIndex from,
    //                        RoutingIndexManager::NodeIndex to) const;

    //  bool SameLocation(RoutingIndexManager::NodeIndex node1,
    //                    RoutingIndexManager::NodeIndex node2) const;
    //  int64_t SameLocationFromIndex(int64_t node1, int64_t node2) const;

};
