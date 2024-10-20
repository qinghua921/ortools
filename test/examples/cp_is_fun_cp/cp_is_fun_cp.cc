








































#include <cstdint>
#include <vector>

#include "absl/flags/flag.h"
#include "absl/log/flags.h"
#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"
#include "ortools/constraint_solver/constraint_solver.h"



namespace operations_research {



IntVar* MakeBaseLine2(Solver* s, IntVar* const v1, IntVar* const v2,
                      const int64_t base) {
  return s->MakeSum(s->MakeProd(v1, base), v2)->Var();
}

IntVar* MakeBaseLine3(Solver* s, IntVar* const v1, IntVar* const v2,
                      IntVar* const v3, const int64_t base) {
  std::vector<IntVar*> tmp_vars;
  std::vector<int64_t> coefficients;
  tmp_vars.push_back(v1);
  coefficients.push_back(base * base);
  tmp_vars.push_back(v2);
  coefficients.push_back(base);
  tmp_vars.push_back(v3);
  coefficients.push_back(1);

  return s->MakeScalProd(tmp_vars, coefficients)->Var();
}

IntVar* MakeBaseLine4(Solver* s, IntVar* const v1, IntVar* const v2,
                      IntVar* const v3, IntVar* const v4, const int64_t base) {
  std::vector<IntVar*> tmp_vars;
  std::vector<int64_t> coefficients;
  tmp_vars.push_back(v1);
  coefficients.push_back(base * base * base);
  tmp_vars.push_back(v2);
  coefficients.push_back(base * base);
  tmp_vars.push_back(v3);
  coefficients.push_back(base);
  tmp_vars.push_back(v4);
  coefficients.push_back(1);

  return s->MakeScalProd(tmp_vars, coefficients)->Var();
}

void CPIsFunCp() {
  

  

  Solver solver("CP is fun!");
  


  

  const int64_t kBase = 10;

  

  IntVar* const c = solver.MakeIntVar(1, kBase - 1, "C");
  IntVar* const p = solver.MakeIntVar(0, kBase - 1, "P");
  IntVar* const i = solver.MakeIntVar(1, kBase - 1, "I");
  IntVar* const s = solver.MakeIntVar(0, kBase - 1, "S");
  IntVar* const f = solver.MakeIntVar(1, kBase - 1, "F");
  IntVar* const u = solver.MakeIntVar(0, kBase - 1, "U");
  IntVar* const n = solver.MakeIntVar(0, kBase - 1, "N");
  IntVar* const t = solver.MakeIntVar(1, kBase - 1, "T");
  IntVar* const r = solver.MakeIntVar(0, kBase - 1, "R");
  IntVar* const e = solver.MakeIntVar(0, kBase - 1, "E");

  

  

  std::vector<IntVar*> letters{c, p, i, s, f, u, n, t, r, e};

  

  CHECK_GE(kBase, letters.size());
  


  

  

  solver.AddConstraint(solver.MakeAllDifferent(letters));

  

  IntVar* const term1 = MakeBaseLine2(&solver, c, p, kBase);
  IntVar* const term2 = MakeBaseLine2(&solver, i, s, kBase);
  IntVar* const term3 = MakeBaseLine3(&solver, f, u, n, kBase);
  IntVar* const sum_terms =
      solver.MakeSum(solver.MakeSum(term1, term2), term3)->Var();

  IntVar* const sum = MakeBaseLine4(&solver, t, r, u, e, kBase);

  solver.AddConstraint(solver.MakeEquality(sum_terms, sum));
  


  

  int num_solutions = 0;
  

  DecisionBuilder* const db = solver.MakePhase(
      letters, Solver::CHOOSE_FIRST_UNBOUND, Solver::ASSIGN_MIN_VALUE);
  solver.NewSearch(db);
  while (solver.NextSolution()) {
    LOG(INFO) << "C=" << c->Value() << " " << "P=" << p->Value() << " "
              << "I=" << i->Value() << " " << "S=" << s->Value() << " "
              << "F=" << f->Value() << " " << "U=" << u->Value() << " "
              << "N=" << n->Value() << " " << "T=" << t->Value() << " "
              << "R=" << r->Value() << " " << "E=" << e->Value();

    

    CHECK_EQ(p->Value() + s->Value() + n->Value() +
                 kBase * (c->Value() + i->Value() + u->Value()) +
                 kBase * kBase * f->Value(),
             e->Value() + kBase * u->Value() + kBase * kBase * r->Value() +
                 kBase * kBase * kBase * t->Value());
    num_solutions++;
  }
  solver.EndSearch();
  LOG(INFO) << "Number of solutions found: " << num_solutions;
  

}

}  


int main(int argc, char** argv) {
  InitGoogle(argv[0], &argc, &argv, true);
  absl::SetFlag(&FLAGS_stderrthreshold, 0);
  operations_research::CPIsFunCp();
  return EXIT_SUCCESS;
}


