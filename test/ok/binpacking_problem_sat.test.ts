// // Copyright 2010-2022 Google LLC
// // Licensed under the Apache License, Version 2.0 (the "License");
// // you may not use this file except in compliance with the License.
// // You may obtain a copy of the License at
// //
// //     http://www.apache.org/licenses/LICENSE-2.0
// //
// // Unless required by applicable law or agreed to in writing, software
// // distributed under the License is distributed on an "AS IS" BASIS,
// // WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// // See the License for the specific language governing permissions and
// // limitations under the License.

// #include <stdlib.h>

// #include <vector>

// #include "ortools/base/logging.h"
// #include "ortools/sat/cp_model.h"
// #include "ortools/sat/cp_model.pb.h"
// #include "ortools/sat/cp_model_solver.h"

// namespace operations_research {
// namespace sat {

// void BinpackingProblemSat() {
//   // Data.
//   const int kBinCapacity = 100;
//   const int kSlackCapacity = 20;
//   const int kNumBins = 5;

//   const std::vector<std::vector<int>> items = {
//       {20, 6}, {15, 6}, {30, 4}, {45, 3}};
//   const int num_items = items.size();

//   // Model.
//   CpModelBuilder cp_model;

//   // Main variables.
//   std::vector<std::vector<IntVar>> x(num_items);
//   for (int i = 0; i < num_items; ++i) {
//     const int num_copies = items[i][1];
//     for (int b = 0; b < kNumBins; ++b) {
//       x[i].push_back(cp_model.NewIntVar({0, num_copies}));
//     }
//   }

//   // Load variables.
//   std::vector<IntVar> load(kNumBins);
//   for (int b = 0; b < kNumBins; ++b) {
//     load[b] = cp_model.NewIntVar({0, kBinCapacity});
//   }

//   // Slack variables.
//   std::vector<BoolVar> slacks(kNumBins);
//   for (int b = 0; b < kNumBins; ++b) {
//     slacks[b] = cp_model.NewBoolVar();
//   }

//   // Links load and x.
//   for (int b = 0; b < kNumBins; ++b) {
//     LinearExpr expr;
//     for (int i = 0; i < num_items; ++i) {
//       expr += x[i][b] * items[i][0];
//     }
//     cp_model.AddEquality(expr, load[b]);
//   }

//   // Place all items.
//   for (int i = 0; i < num_items; ++i) {
//     cp_model.AddEquality(LinearExpr::Sum(x[i]), items[i][1]);
//   }

//   // Links load and slack through an equivalence relation.
//   const int safe_capacity = kBinCapacity - kSlackCapacity;
//   for (int b = 0; b < kNumBins; ++b) {
//     // slack[b] => load[b] <= safe_capacity.
//     cp_model.AddLessOrEqual(load[b], safe_capacity).OnlyEnforceIf(slacks[b]);
//     // not(slack[b]) => load[b] > safe_capacity.
//     cp_model.AddGreaterThan(load[b], safe_capacity)
//         .OnlyEnforceIf(Not(slacks[b]));
//   }

//   // Maximize sum of slacks.
//   cp_model.Maximize(LinearExpr::Sum(slacks));

//   // Solving part.
//   const CpSolverResponse response = Solve(cp_model.Build());
//   LOG(INFO) << CpSolverResponseStats(response);
// }

// }  // namespace sat
// }  // namespace operations_research

// int main() {
//   operations_research::sat::BinpackingProblemSat();

//   return EXIT_SUCCESS;
// }
import { operations_research } from "../../src";

test('assignment_groups_mip', () =>
{
  const kBinCapacity = 100;
  const kSlackCapacity = 20;
  const kNumBins = 5;


  const items = [
    [20, 6],
    [15, 6],
    [30, 4],
    [45, 3]
  ];
  const num_items = items.length;

  const cp_model = new operations_research.sat.CpModelBuilder();

  // Main variables.
  const x = [];
  for (let i = 0; i < num_items; ++i)
  {
    const num_copies = items[i][1];
    const x_i_b = [];
    for (let b = 0; b < kNumBins; ++b)
    {
      x_i_b.push(cp_model.NewIntVar(new operations_research.Domain(0, num_copies)));
    }
    x.push(x_i_b);
  }

  // Load variables.
  const load = [];
  for (let b = 0; b < kNumBins; ++b)
  {
    load.push(cp_model.NewIntVar(new operations_research.Domain(0, kBinCapacity)));
  }

  // Slack variables.
  const slacks = [];
  for (let b = 0; b < kNumBins; ++b)
  {
    slacks.push(cp_model.NewBoolVar());
  }

  // Links load and x.
  for (let b = 0; b < kNumBins; ++b)
  {
    let expr = new operations_research.sat.LinearExpr();
    for (let i = 0; i < num_items; ++i)
    {
      expr.operator_plus_equals(operations_research.sat.operator_plus(x[i][b], items[i][0]))
    }
    cp_model.AddEquality(expr, load[b]);
  }

  // Place all items.
  for (let i = 0; i < num_items; ++i)
  {
    let sum = operations_research.sat.LinearExpr.Sum(x[i])
    cp_model.AddEquality(sum, items[i][1]);
  }

  // Links load and slack through an equivalence relation.
  const safe_capacity = kBinCapacity - kSlackCapacity;
  for (let b = 0; b < kNumBins; ++b)
  {
    // slack[b] => load[b] <= safe_capacity.
    cp_model.AddLessOrEqual(load[b], safe_capacity).OnlyEnforceIf(slacks[b]);
    // not(slack[b]) => load[b] > safe_capacity.
    cp_model.AddGreaterThan(load[b], safe_capacity).OnlyEnforceIf(operations_research.sat.Not(slacks[b]));
  }
  // Maximize sum of slacks.
  cp_model.Maximize(operations_research.sat.LinearExpr.Sum(slacks));

  // Solving part.
  const response = operations_research.sat.Solve(cp_model.Build());
  console.log(operations_research.sat.CpSolverResponseStats(response));





}
);