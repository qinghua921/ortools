









































#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/flags/usage.h"
#include "absl/log/initialize.h"
#include "absl/random/random.h"
#include "ortools/base/logging.h"
#include "ortools/linear_solver/linear_solver.h"
#include "ortools/util/random_engine.h"

ABSL_FLAG(int, verbose, 0, "Verbosity level.");
ABSL_FLAG(int, facilities, 20, "Candidate facilities to consider.");
ABSL_FLAG(int, clients, 100, "Clients to serve.");
ABSL_FLAG(double, fix_cost, 5000, "Cost of opening a facility.");

namespace operations_research {

struct Location {
  double x = 0.0;
  double y = 0.0;
};

struct Edge {
  int f = -1;
  int c = -1;
  MPVariable* x = nullptr;
};

static double Distance(const Location& src, const Location& dst) {
  return sqrt((src.x - dst.x) * (src.x - dst.x) +
              (src.y - dst.y) * (src.y - dst.y));
}

static void UncapacitatedFacilityLocation(
    int32_t facilities, int32_t clients, double fix_cost,
    MPSolver::OptimizationProblemType optimization_problem_type) {
  LOG(INFO) << "Starting " << __func__;
  

  const int32_t kXMax = 1000;
  const int32_t kYMax = 1000;
  const double kMaxDistance = 6 * sqrt((kXMax * kYMax)) / facilities;
  const int kStrLen = 1024;
  

  char name_buffer[kStrLen + 1];
  name_buffer[kStrLen] = '\0';
  LOG(INFO) << "Facilities/Clients/Fix cost/MaxDist: " << facilities << "/"
            << clients << "/" << fix_cost << "/" << kMaxDistance;
  

  random_engine_t randomizer;  

  std::vector<Location> facility(facilities);
  std::vector<Location> client(clients);
  for (int i = 0; i < facilities; ++i) {
    facility[i].x = absl::Uniform(randomizer, 0, kXMax + 1);
    facility[i].y = absl::Uniform(randomizer, 0, kYMax + 1);
  }
  for (int i = 0; i < clients; ++i) {
    client[i].x = absl::Uniform(randomizer, 0, kXMax + 1);
    client[i].y = absl::Uniform(randomizer, 0, kYMax + 1);
  }

  

  

  

  

  

  

  

  

  MPSolver solver("UncapacitatedFacilityLocation", optimization_problem_type);
  const double infinity = solver.infinity();
  MPObjective* objective = solver.MutableObjective();
  objective->SetMinimization();

  

  std::vector<MPVariable*> xf{};
  for (int f = 0; f < facilities; ++f) {
    snprintf(name_buffer, kStrLen, "x[%d](%g,%g)", f, facility[f].x,
             facility[f].y);
    MPVariable* x = solver.MakeBoolVar(name_buffer);
    xf.push_back(x);
    objective->SetCoefficient(x, fix_cost);
  }

  

  std::vector<Edge> edges;
  for (int c = 0; c < clients; ++c) {
    snprintf(name_buffer, kStrLen, "R-Client[%d](%g,%g)", c, client[c].x,
             client[c].y);
    MPConstraint* client_constraint =
        solver.MakeRowConstraint(
 1, 
 infinity, name_buffer);
    for (int f = 0; f < facilities; ++f) {
      double distance = Distance(facility[f], client[c]);
      if (distance > kMaxDistance) continue;
      Edge edge{};
      snprintf(name_buffer, kStrLen, "x[%d,%d]", f, c);
      edge.x = solver.MakeNumVar(
 0, 
 1, name_buffer);
      edge.f = f;
      edge.c = c;
      edges.push_back(edge);
      objective->SetCoefficient(edge.x, distance);
      

      client_constraint->SetCoefficient(edge.x, 1);
      

      snprintf(name_buffer, kStrLen, "R-Edge[%d,%d]", f, c);
      MPConstraint* edge_constraint =
          solver.MakeRowConstraint(
 0, 
 infinity, name_buffer);
      edge_constraint->SetCoefficient(edge.x, -1);
      edge_constraint->SetCoefficient(xf[f], 1);
    }
  }  

  LOG(INFO) << "Number of variables = " << solver.NumVariables();
  LOG(INFO) << "Number of constraints = " << solver.NumConstraints();
  

  if (clients <= 10 && facilities <= 10) {
    std::string lp_string{};
    const bool obfuscate = false;
    solver.ExportModelAsLpFormat(obfuscate, &lp_string);
    std::cout << "LP-Model:\n" << lp_string << std::endl;
  }
  

  if (optimization_problem_type != MPSolver::SCIP_MIXED_INTEGER_PROGRAMMING) {
    if (!solver.SetNumThreads(8).ok()) {
      LOG(INFO) << "Could not set parallelism for "
                << optimization_problem_type;
    }
  }
  solver.EnableOutput();
  const MPSolver::ResultStatus result_status = solver.Solve();
  

  if (result_status != MPSolver::OPTIMAL) {
    LOG(FATAL) << "The problem does not have an optimal solution!";
  } else {
    LOG(INFO) << "Optimal objective value = " << objective->Value();
    if (absl::GetFlag(FLAGS_verbose)) {
      std::vector<std::vector<int> > solution(facilities);
      for (auto& edge : edges) {
        if (edge.x->solution_value() < 0.5) continue;
        solution[edge.f].push_back(edge.c);
      }
      std::cout << "\tSolution:\n";
      for (int f = 0; f < facilities; ++f) {
        if (solution[f].empty()) continue;
        assert(xf[f]->solution_value() > 0.5);
        snprintf(name_buffer, kStrLen, "\t  Facility[%d](%g,%g):", f,
                 facility[f].x, facility[f].y);
        std::cout << name_buffer;
        int i = 1;
        for (auto c : solution[f]) {
          snprintf(name_buffer, kStrLen, " Client[%d](%g,%g)", c, client[c].x,
                   client[c].y);
          if (i++ >= 5) {
            std::cout << "\n\t\t";
            i = 1;
          }
          std::cout << name_buffer;
        }
        std::cout << "\n";
      }
    }
    std::cout << "\n";
    LOG(INFO) << "";
    LOG(INFO) << "Advanced usage:";
    LOG(INFO) << "Problem solved in " << solver.DurationSinceConstruction()
              << " milliseconds";
    LOG(INFO) << "Problem solved in " << solver.iterations() << " iterations";
    LOG(INFO) << "Problem solved in " << solver.nodes()
              << " branch-and-bound nodes";
  }
}

void RunAllExamples(int32_t facilities, int32_t clients, double fix_cost) {
#if defined(USE_CBC)
  LOG(INFO) << "---- Integer programming example with CBC ----";
  UncapacitatedFacilityLocation(facilities, clients, fix_cost,
                                MPSolver::CBC_MIXED_INTEGER_PROGRAMMING);
#endif
#if defined(USE_GLPK)
  LOG(INFO) << "---- Integer programming example with GLPK ----";
  UncapacitatedFacilityLocation(facilities, clients, fix_cost,
                                MPSolver::GLPK_MIXED_INTEGER_PROGRAMMING);
#endif
#if defined(USE_SCIP)
  LOG(INFO) << "---- Integer programming example with SCIP ----";
  UncapacitatedFacilityLocation(facilities, clients, fix_cost,
                                MPSolver::SCIP_MIXED_INTEGER_PROGRAMMING);
#endif
#if defined(USE_GUROBI)
  LOG(INFO) << "---- Integer programming example with Gurobi ----";
  UncapacitatedFacilityLocation(facilities, clients, fix_cost,
                                MPSolver::GUROBI_MIXED_INTEGER_PROGRAMMING);
#endif  

#if defined(USE_CPLEX)
  LOG(INFO) << "---- Integer programming example with CPLEX ----";
  UncapacitatedFacilityLocation(facilities, clients, fix_cost,
                                MPSolver::CPLEX_MIXED_INTEGER_PROGRAMMING);
#endif  

  LOG(INFO) << "---- Integer programming example with CP-SAT ----";
  UncapacitatedFacilityLocation(facilities, clients, fix_cost,
                                MPSolver::SAT_INTEGER_PROGRAMMING);
}

}  


int main(int argc, char** argv) {
  absl::InitializeLog();
  absl::SetProgramUsageMessage(
      std::string("This program solve a (randomly generated)\n") +
      std::string("Uncapacitated Facility Location Problem. Sample Usage:\n"));
  absl::ParseCommandLine(argc, argv);
  CHECK_LT(0, absl::GetFlag(FLAGS_facilities))
      << "Specify an instance size greater than 0.";
  CHECK_LT(0, absl::GetFlag(FLAGS_clients))
      << "Specify a non-null client size.";
  CHECK_LT(0, absl::GetFlag(FLAGS_fix_cost))
      << "Specify a non-null client size.";
  absl::SetFlag(&FLAGS_stderrthreshold, 0);
  operations_research::RunAllExamples(absl::GetFlag(FLAGS_facilities),
                                      absl::GetFlag(FLAGS_clients),
                                      absl::GetFlag(FLAGS_fix_cost));
  return EXIT_SUCCESS;
}
