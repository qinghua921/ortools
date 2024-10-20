







































#include <cstdint>
#include <string>
#include <vector>

#include "absl/flags/flag.h"
#include "ortools/base/commandlineflags.h"
#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"

ABSL_FLAG(int, size, 16, "scaling factor of the model");
ABSL_FLAG(std::string, params,
          "num_workers:8,log_search_progress:true,max_time_in_seconds:10.0",
          "Sat parameters");

namespace operations_research {
namespace sat {

static const int kWeightMin = 16000;
static const int kWeightMax = 22000;
static const int kVolumeMin = 1156;
static const int kVolumeMax = 1600;



static const int kItemsWeights[] = {1008, 2087, 5522, 5250,  5720,
                                    4998, 275,  3145, 12580, 382};
static const int kItemsVolumes[] = {281, 307, 206, 111, 275,
                                    79,  23,  65,  261, 40};
static const int kNumItems = 10;

void MultiKnapsackSat(int scaling, const std::string& params) {
  CpModelBuilder builder;

  const int num_items = scaling * kNumItems;
  const int num_bins = scaling;

  std::vector<std::vector<BoolVar>> items_in_bins(num_bins);
  for (int b = 0; b < num_bins; ++b) {
    for (int i = 0; i < num_items; ++i) {
      items_in_bins[b].push_back(builder.NewBoolVar());
    }
  }

  std::vector<BoolVar> selected_items(num_items);
  for (int i = 0; i < num_items; ++i) {
    selected_items[i] = builder.NewBoolVar();
  }

  

  std::vector<int64_t> values(num_items);
  std::vector<int64_t> weights(num_items);
  std::vector<int64_t> volumes(num_items);
  for (int i = 0; i < num_items; ++i) {
    const int index = i % kNumItems;
    weights[i] = kItemsWeights[index];
    volumes[i] = kItemsVolumes[index];
  }

  

  std::vector<IntVar> bin_weights;
  for (int b = 0; b < num_bins; ++b) {
    IntVar bin_weight = builder.NewIntVar({kWeightMin, kWeightMax});
    bin_weights.push_back(bin_weight);
    builder.AddEquality(LinearExpr::WeightedSum(items_in_bins[b], weights),
                        bin_weight);
    builder.AddLinearConstraint(
        LinearExpr::WeightedSum(items_in_bins[b], volumes),
        {kVolumeMin, kVolumeMax});
  }

  

  for (int i = 0; i < num_items; ++i) {
    std::vector<BoolVar> bin_contain_item(num_bins);
    for (int b = 0; b < num_bins; ++b) {
      bin_contain_item[b] = items_in_bins[b][i];
    }
    builder.AddEquality(LinearExpr::Sum(bin_contain_item), selected_items[i]);
  }

  

  builder.Maximize(LinearExpr::Sum(bin_weights));

  

  const CpSolverResponse response =
      SolveWithParameters(builder.Build(), params);
  LOG(INFO) << CpSolverResponseStats(response);
}

}  

}  


int main(int argc, char** argv) {
  absl::SetFlag(&FLAGS_stderrthreshold, 0);
  InitGoogle(argv[0], &argc, &argv, true);
  operations_research::sat::MultiKnapsackSat(absl::GetFlag(FLAGS_size),
                                             absl::GetFlag(FLAGS_params));
  return EXIT_SUCCESS;
}
