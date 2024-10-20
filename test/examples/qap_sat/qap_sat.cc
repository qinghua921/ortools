
























#include <string>
#include <tuple>
#include <vector>

#include "absl/flags/flag.h"
#include "absl/strings/str_cat.h"
#include "google/protobuf/text_format.h"
#include "ortools/base/commandlineflags.h"
#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"
#include "ortools/sat/sat_parameters.pb.h"
#include "ortools/util/qap_reader.h"

ABSL_FLAG(std::string, input, "", "Input file name containing a QAP instance.");
ABSL_FLAG(std::string, params, "", "Specific params to use with CP-SAT.");

namespace operations_research {
namespace sat {

void SolveQap() {
  LOG(INFO) << "Reading QAP problem from '" << absl::GetFlag(FLAGS_input)
            << "'.";
  QapProblem qap = ReadQapProblemOrDie(absl::GetFlag(FLAGS_input));
  const int n = qap.weights.size();

  CpModelBuilder cp_model;

  

  

  

  std::vector<std::vector<BoolVar>> place_vars;
  place_vars.resize(n);
  for (int f = 0; f < n; ++f) {
    place_vars[f].resize(n);
    for (int l = 0; l < n; ++l) {
      place_vars[f][l] =
          cp_model.NewBoolVar().WithName(absl::StrCat("place_", f, "_", l));
    }
  }

  

  for (int f = 0; f < n; ++f) {
    cp_model.AddExactlyOne(place_vars[f]);
  }

  

  for (int l = 0; l < n; ++l) {
    std::vector<BoolVar> tmp;
    for (int f = 0; f < n; ++f) {
      tmp.push_back(place_vars[f][l]);
    }
    cp_model.AddExactlyOne(tmp);
  }

  

  absl::flat_hash_map<std::tuple<int, int, int, int>, BoolVar> cache;
  LinearExpr objective;
  for (int f1 = 0; f1 < n; ++f1) {
    for (int f2 = 0; f2 < n; ++f2) {
      if (f1 == f2) continue;
      if (qap.weights[f1][f2] == 0) continue;
      for (int l1 = 0; l1 < n; ++l1) {
        for (int l2 = 0; l2 < n; ++l2) {
          if (l1 == l2) continue;
          if (qap.distances[l1][l2] == 0) continue;

          const std::tuple<int, int, int, int> key =
              f1 < f2 ? std::make_tuple(f1, f2, l1, l2)
                      : std::make_tuple(f2, f1, l2, l1);
          BoolVar product;
          const auto it = cache.find(key);
          if (it == cache.end()) {
            product = cp_model.NewBoolVar();
            cp_model.AddMultiplicationEquality(product, place_vars[f1][l1],
                                               place_vars[f2][l2]);
            cache[key] = product;
          } else {
            product = it->second;
          }

          objective += product * qap.weights[f1][f2] * qap.distances[l1][l2];
        }
      }
    }
  }

  for (int f = 0; f < n; ++f) {
    for (int l = 0; l < n; ++l) {
      objective += place_vars[f][l] * qap.weights[f][f] * qap.distances[l][l];
    }
  }

  cp_model.Minimize(objective);

  

  SatParameters parameters;
  parameters.set_log_search_progress(true);
  

  if (!absl::GetFlag(FLAGS_params).empty()) {
    CHECK(google::protobuf::TextFormat::MergeFromString(
        absl::GetFlag(FLAGS_params), &parameters))
        << absl::GetFlag(FLAGS_params);
  }

  

  const CpSolverResponse response =
      SolveWithParameters(cp_model.Build(), parameters);
}

}  

}  


static const char kUsageStr[] =
    "Solves quadratic assignment problems with CP-SAT. "
    "The input file should have the format described in the QAPLIB (see "
    "http:


int main(int argc, char** argv) {
  InitGoogle(kUsageStr, &argc, &argv, 
true);
  if (absl::GetFlag(FLAGS_input).empty()) {
    LOG(INFO) << "--input is required";
    return EXIT_SUCCESS;
  }

  operations_research::sat::SolveQap();
  return EXIT_SUCCESS;
}
