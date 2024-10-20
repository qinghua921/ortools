
























#include <stdlib.h>

#include <vector>

#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"
#include "ortools/sat/cp_model.pb.h"
#include "ortools/sat/cp_model_solver.h"

namespace operations_research {
namespace sat {

void BinpackingProblemSat() {
  

  const int kBinCapacity = 100;
  const int kSlackCapacity = 20;
  const int kNumBins = 5;

  const std::vector<std::vector<int>> items = {
      {20, 6}, {15, 6}, {30, 4}, {45, 3}};
  const int num_items = items.size();

  

  CpModelBuilder cp_model;

  

  std::vector<std::vector<IntVar>> x(num_items);
  for (int i = 0; i < num_items; ++i) {
    const int num_copies = items[i][1];
    for (int b = 0; b < kNumBins; ++b) {
      x[i].push_back(cp_model.NewIntVar({0, num_copies}));
    }
  }

  

  std::vector<IntVar> load(kNumBins);
  for (int b = 0; b < kNumBins; ++b) {
    load[b] = cp_model.NewIntVar({0, kBinCapacity});
  }

  

  std::vector<BoolVar> slacks(kNumBins);
  for (int b = 0; b < kNumBins; ++b) {
    slacks[b] = cp_model.NewBoolVar();
  }

  

  for (int b = 0; b < kNumBins; ++b) {
    LinearExpr expr;
    for (int i = 0; i < num_items; ++i) {
      expr += x[i][b] * items[i][0];
    }
    cp_model.AddEquality(expr, load[b]);
  }

  

  for (int i = 0; i < num_items; ++i) {
    cp_model.AddEquality(LinearExpr::Sum(x[i]), items[i][1]);
  }

  

  const int safe_capacity = kBinCapacity - kSlackCapacity;
  for (int b = 0; b < kNumBins; ++b) {
    

    cp_model.AddLessOrEqual(load[b], safe_capacity).OnlyEnforceIf(slacks[b]);
    

    cp_model.AddGreaterThan(load[b], safe_capacity).OnlyEnforceIf(~slacks[b]);
  }

  

  cp_model.Maximize(LinearExpr::Sum(slacks));

  

  const CpSolverResponse response = Solve(cp_model.Build());
  LOG(INFO) << CpSolverResponseStats(response);
}

}  

}  


int main() {
  operations_research::sat::BinpackingProblemSat();

  return EXIT_SUCCESS;
}
