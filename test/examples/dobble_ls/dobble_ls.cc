



























































#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <random>
#include <utility>
#include <vector>

#include "absl/random/random.h"
#include "absl/strings/str_format.h"
#include "ortools/base/commandlineflags.h"
#include "ortools/base/init_google.h"
#include "ortools/base/map_util.h"
#include "ortools/base/types.h"
#include "ortools/constraint_solver/constraint_solveri.h"
#include "ortools/util/bitset.h"

ABSL_FLAG(int, symbols_per_card, 8, "Number of symbols per card.");
ABSL_FLAG(int, ls_seed, 1,
          "Seed for the random number generator (used by "
          "the Local Neighborhood Search).");
ABSL_FLAG(bool, use_filter, true,
          "Use filter in the local search to prune moves.");
ABSL_FLAG(int, num_swaps, 4,
          "If num_swap > 0, the search for an optimal "
          "solution will be allowed to use an operator that swaps the "
          "symbols of up to num_swap pairs ((card1, symbol on card1), "
          "(card2, symbol on card2)).");
ABSL_FLAG(int, time_limit_in_ms, 60000,
          "Time limit for the global search in ms.");

namespace operations_research {










class SymbolsSharedByTwoCardsConstraint : public Constraint {
 public:
  

  SymbolsSharedByTwoCardsConstraint(
      Solver* const solver, const std::vector<IntVar*>& card1_symbol_vars,
      const std::vector<IntVar*>& card2_symbol_vars,
      IntVar* const num_symbols_in_common_var)
      : Constraint(solver),
        card1_symbol_vars_(card1_symbol_vars),
        card2_symbol_vars_(card2_symbol_vars),
        num_symbols_(card1_symbol_vars.size()),
        num_symbols_in_common_var_(num_symbols_in_common_var) {
    

    CHECK_EQ(card1_symbol_vars.size(), card2_symbol_vars.size());

    

    for (int i = 0; i < num_symbols_; ++i) {
      CHECK_GE(card1_symbol_vars_[i]->Min(), 0);
      CHECK_GE(card2_symbol_vars_[i]->Min(), 0);
      CHECK_LE(card1_symbol_vars_[i]->Max(), 1);
      CHECK_LE(card2_symbol_vars_[i]->Max(), 1);
    }
  }

  ~SymbolsSharedByTwoCardsConstraint() override = default;

  

  

  

  void Post() override {
    

    

    

    

    

    

    Demon* const global_demon =
        solver()->MakeDelayedConstraintInitialPropagateCallback(this);
    

    for (int i = 0; i < num_symbols_; ++i) {
      card1_symbol_vars_[i]->WhenBound(global_demon);
      card2_symbol_vars_[i]->WhenBound(global_demon);
    }
    

    num_symbols_in_common_var_->WhenBound(global_demon);
  }

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  void InitialPropagate() override {
    int max_symbols_in_common = 0;
    int min_symbols_in_common = 0;
    for (int i = 0; i < num_symbols_; ++i) {
      if (card1_symbol_vars_[i]->Min() == 1 &&
          card2_symbol_vars_[i]->Min() == 1) {
        min_symbols_in_common++;
      }
      if (card1_symbol_vars_[i]->Max() == 1 &&
          card2_symbol_vars_[i]->Max() == 1) {
        max_symbols_in_common++;
      }
    }
    num_symbols_in_common_var_->SetRange(min_symbols_in_common,
                                         max_symbols_in_common);
    

    

    

    if (min_symbols_in_common == max_symbols_in_common) {
      DCHECK_EQ(min_symbols_in_common, num_symbols_in_common_var_->Max());
      DCHECK_EQ(min_symbols_in_common, num_symbols_in_common_var_->Min());
      return;
    }
    if (num_symbols_in_common_var_->Max() == min_symbols_in_common) {
      

      for (int i = 0; i < num_symbols_; ++i) {
        

        

        

        

        if (card1_symbol_vars_[i]->Min() == 1 &&
            card2_symbol_vars_[i]->Min() == 0) {
          card2_symbol_vars_[i]->SetValue(0);
        } else if (card2_symbol_vars_[i]->Min() == 1 &&
                   card1_symbol_vars_[i]->Min() == 0) {
          card1_symbol_vars_[i]->SetValue(0);
        }
      }
    } else if (num_symbols_in_common_var_->Min() == max_symbols_in_common) {
      

      for (int i = 0; i < num_symbols_; ++i) {
        if (card1_symbol_vars_[i]->Max() == 1 &&
            card2_symbol_vars_[i]->Max() == 1) {
          

          

          card1_symbol_vars_[i]->SetValue(1);
          card2_symbol_vars_[i]->SetValue(1);
        }
      }
    }
  }

 private:
  std::vector<IntVar*> card1_symbol_vars_;
  std::vector<IntVar*> card2_symbol_vars_;
  const int num_symbols_;
  IntVar* const num_symbols_in_common_var_;
};











IntVar* CreateViolationVar(Solver* const solver,
                           const std::vector<IntVar*>& card1_symbol_vars,
                           const std::vector<IntVar*>& card2_symbol_vars,
                           int num_symbols_per_card) {
  IntVar* const num_symbols_in_common_var =
      solver->MakeIntVar(0, num_symbols_per_card);
  

  solver->AddConstraint(solver->RevAlloc(new SymbolsSharedByTwoCardsConstraint(
      solver, card1_symbol_vars, card2_symbol_vars,
      num_symbols_in_common_var)));
  return solver->MakeAbs(solver->MakeSum(num_symbols_in_common_var, -1))->Var();
}




























































class DobbleOperator : public IntVarLocalSearchOperator {
 public:
  DobbleOperator(const std::vector<IntVar*>& card_symbol_vars, int num_cards,
                 int num_symbols, int num_symbols_per_card)
      : IntVarLocalSearchOperator(card_symbol_vars),
        num_cards_(num_cards),
        num_symbols_(num_symbols),
        num_symbols_per_card_(num_symbols_per_card),
        symbols_per_card_(num_cards) {
    CHECK_GT(num_cards, 0);
    CHECK_GT(num_symbols, 0);
    CHECK_GT(num_symbols_per_card, 0);
    for (int card = 0; card < num_cards; ++card) {
      symbols_per_card_[card].assign(num_symbols_per_card, -1);
    }
  }

  ~DobbleOperator() override = default;

 protected:
  

  

  

  void OnStart() override {
    for (int card = 0; card < num_cards_; ++card) {
      int found = 0;
      for (int symbol = 0; symbol < num_symbols_; ++symbol) {
        if (Value(VarIndex(card, symbol)) == 1) {
          symbols_per_card_[card][found++] = symbol;
        }
      }
      DCHECK_EQ(num_symbols_per_card_, found);
    }
    InitNeighborhoodSearch();
  }

  virtual void InitNeighborhoodSearch() = 0;

  

  

  int VarIndex(int card, int symbol) { return card * num_symbols_ + symbol; }

  

  void SwapTwoSymbolsOnCards(int card1, int symbol1, int card2, int symbol2) {
    SetValue(VarIndex(card1, symbol1), 0);
    SetValue(VarIndex(card2, symbol2), 0);
    SetValue(VarIndex(card1, symbol2), 1);
    SetValue(VarIndex(card2, symbol1), 1);
  }

  const int num_cards_;
  const int num_symbols_;
  const int num_symbols_per_card_;
  std::vector<std::vector<int> > symbols_per_card_;
};


















class SwapSymbols : public DobbleOperator {
 public:
  SwapSymbols(const std::vector<IntVar*>& card_symbol_vars, int num_cards,
              int num_symbols, int num_symbols_per_card)
      : DobbleOperator(card_symbol_vars, num_cards, num_symbols,
                       num_symbols_per_card),
        current_card1_(-1),
        current_card2_(-1),
        current_symbol1_(-1),
        current_symbol2_(-1) {}

  ~SwapSymbols() override = default;

  

  bool MakeOneNeighbor() override {
    if (!PickNextSwap()) {
      VLOG(1) << "finished neighborhood";
      return false;
    }

    const int symbol1 = symbols_per_card_[current_card1_][current_symbol1_];
    const int symbol2 = symbols_per_card_[current_card2_][current_symbol2_];
    SwapTwoSymbolsOnCards(current_card1_, symbol1, current_card2_, symbol2);
    return true;
  }

 private:
  

  void InitNeighborhoodSearch() override {
    current_card1_ = 0;
    current_card2_ = 1;
    current_symbol1_ = 0;
    current_symbol2_ = -1;
  }

  

  bool PickNextSwap() {
    current_symbol2_++;
    if (current_symbol2_ == num_symbols_per_card_) {
      current_symbol2_ = 0;
      current_symbol1_++;
      if (current_symbol1_ == num_symbols_per_card_) {
        current_symbol1_ = 0;
        current_card2_++;
        if (current_card2_ == num_cards_) {
          current_card1_++;
          current_card2_ = current_card1_ + 1;
        }
      }
    }
    return current_card1_ < num_cards_ - 1;
  }

  int current_card1_;
  int current_card2_;
  int current_symbol1_;
  int current_symbol2_;
};























class SwapSymbolsOnCardPairs : public DobbleOperator {
 public:
  SwapSymbolsOnCardPairs(const std::vector<IntVar*>& card_symbol_vars,
                         int num_cards, int num_symbols,
                         int num_symbols_per_card, int max_num_swaps)
      : DobbleOperator(card_symbol_vars, num_cards, num_symbols,
                       num_symbols_per_card),
        rand_(absl::GetFlag(FLAGS_ls_seed)),
        max_num_swaps_(max_num_swaps) {
    CHECK_GE(max_num_swaps, 2);
  }

  ~SwapSymbolsOnCardPairs() override = default;

 protected:
  bool MakeOneNeighbor() override {
    const int num_swaps =
        absl::Uniform<int32_t>(rand_, 0, max_num_swaps_ - 1) + 2;
    for (int i = 0; i < num_swaps; ++i) {
      const int card_1 = absl::Uniform<int32_t>(rand_, 0, num_cards_);
      const int symbol_index_1 =
          absl::Uniform<int32_t>(rand_, 0, num_symbols_per_card_);
      const int symbol_1 = symbols_per_card_[card_1][symbol_index_1];
      const int card_2 = absl::Uniform<int32_t>(rand_, 0, num_cards_);
      const int symbol_index_2 =
          absl::Uniform<int32_t>(rand_, 0, num_symbols_per_card_);
      const int symbol_2 = symbols_per_card_[card_2][symbol_index_2];
      SwapTwoSymbolsOnCards(card_1, symbol_1, card_2, symbol_2);
    }
    return true;
  }

  void InitNeighborhoodSearch() override {}

 private:
  std::mt19937 rand_;
  const int max_num_swaps_;
};





















































class DobbleFilter : public IntVarLocalSearchFilter {
 public:
  DobbleFilter(const std::vector<IntVar*>& card_symbol_vars, int num_cards,
               int num_symbols, int num_symbols_per_card)
      : IntVarLocalSearchFilter(card_symbol_vars),
        num_cards_(num_cards),
        num_symbols_(num_symbols),
        num_symbols_per_card_(num_symbols_per_card),
        temporary_bitset_(0),
        symbol_bitmask_per_card_(num_cards, 0),
        violation_costs_(num_cards_, std::vector<int>(num_cards_, 0)) {}

  

  

  void OnSynchronize(const Assignment* delta) override {
    symbol_bitmask_per_card_.assign(num_cards_, 0);
    for (int card = 0; card < num_cards_; ++card) {
      for (int symbol = 0; symbol < num_symbols_; ++symbol) {
        if (Value(VarIndex(card, symbol))) {
          SetBit64(&symbol_bitmask_per_card_[card], symbol);
        }
      }
    }
    for (int card1 = 0; card1 < num_cards_; ++card1) {
      for (int card2 = 0; card2 < num_cards_; ++card2) {
        violation_costs_[card1][card2] = ViolationCost(BitCount64(
            symbol_bitmask_per_card_[card1] & symbol_bitmask_per_card_[card2]));
      }
    }
    DCHECK(CheckCards());
  }

  

  

  

  bool Accept(const Assignment* delta, const Assignment* unused_deltadelta,
              int64_t objective_min, int64_t objective_max) override {
    const Assignment::IntContainer& solution_delta = delta->IntVarContainer();
    const int solution_delta_size = solution_delta.Size();

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    for (int i = 0; i < solution_delta_size; ++i) {
      if (!solution_delta.Element(i).Activated()) {
        VLOG(1) << "Element #" << i << " of the delta assignment given to"
                << " DobbleFilter::Accept() is not activated (i.e. its variable"
                << " is not bound to a single value anymore). This means that"
                << " we are in a LNS phase, and the DobbleFilter won't be able"
                << " to filter anything. Returning true.";
        return true;
      }
    }
    VLOG(1) << "No LNS, size = " << solution_delta_size;

    

    std::vector<int> touched_cards;
    ComputeTouchedCards(solution_delta, &touched_cards);

    

    if (!CheckCards()) {
      RestoreBitsetPerCard();
      DCHECK(CheckCards());
      VLOG(1) << "reject by size";
      return false;
    }

    

    const int cost_delta = ComputeNewCost(touched_cards);

    

    RestoreBitsetPerCard();

    

    

    if (cost_delta >= 0) {
      VLOG(1) << "reject";
    }
    return cost_delta < 0;
  }

 private:
  

  struct UndoChange {
    UndoChange(int c, uint64_t b) : card(c), bitset(b) {}
    int card;
    uint64_t bitset;
  };

  int VarIndex(int card, int symbol) { return card * num_symbols_ + symbol; }

  void ClearBitset() { temporary_bitset_ = 0; }

  

  

  

  int ComputeNewCost(const std::vector<int>& touched_cards) {
    ClearBitset();
    int cost_delta = 0;
    for (int i = 0; i < touched_cards.size(); ++i) {
      const int touched = touched_cards[i];
      SetBit64(&temporary_bitset_, touched);
      const uint64_t card_bitset = symbol_bitmask_per_card_[touched];
      const std::vector<int>& row_cost = violation_costs_[touched];
      for (int other_card = 0; other_card < num_cards_; ++other_card) {
        if (!IsBitSet64(&temporary_bitset_, other_card)) {
          cost_delta += ViolationCost(
              BitCount64(card_bitset & symbol_bitmask_per_card_[other_card]));
          cost_delta -= row_cost[other_card];
        }
      }
    }
    return cost_delta;
  }

  

  void ComputeTouchedCards(const Assignment::IntContainer& solution_delta,
                           std::vector<int>* const touched_cards) {
    ClearBitset();
    const int solution_delta_size = solution_delta.Size();
    const int kUnassigned = -1;
    for (int index = 0; index < solution_delta_size; ++index) {
      int64_t touched_var = kUnassigned;
      FindIndex(solution_delta.Element(index).Var(), &touched_var);
      CHECK_NE(touched_var, kUnassigned);
      const int card = touched_var / num_symbols_;
      const int symbol = touched_var % num_symbols_;
      const int new_value = solution_delta.Element(index).Value();
      if (!IsBitSet64(&temporary_bitset_, card)) {
        SaveRestoreInformation(card);
        touched_cards->push_back(card);
        SetBit64(&temporary_bitset_, card);
      }
      if (new_value) {
        SetBit64(&symbol_bitmask_per_card_[card], symbol);
      } else {
        ClearBit64(&symbol_bitmask_per_card_[card], symbol);
      }
    }
  }

  

  void RestoreBitsetPerCard() {
    for (int i = 0; i < restore_information_.size(); ++i) {
      symbol_bitmask_per_card_[restore_information_[i].card] =
          restore_information_[i].bitset;
    }
    restore_information_.clear();
  }

  

  void SaveRestoreInformation(int card) {
    restore_information_.push_back(
        UndoChange(card, symbol_bitmask_per_card_[card]));
  }

  

  

  bool CheckCards() {
    for (int i = 0; i < num_cards_; ++i) {
      if (num_symbols_per_card_ != BitCount64(symbol_bitmask_per_card_[i])) {
        VLOG(1) << "card " << i << " has bitset of size "
                << BitCount64(symbol_bitmask_per_card_[i]);
        return false;
      }
    }
    return true;
  }

  int ViolationCost(uint64_t cardinality) const {
    return (cardinality > 0 ? cardinality - 1 : 1);
  }

  const int num_cards_;
  const int num_symbols_;
  const int num_symbols_per_card_;
  uint64_t temporary_bitset_;
  std::vector<uint64_t> symbol_bitmask_per_card_;
  std::vector<std::vector<int> > violation_costs_;
  std::vector<UndoChange> restore_information_;
};




void SolveDobble(int num_cards, int num_symbols, int num_symbols_per_card) {
  LOG(INFO) << "Solving dobble assignment problem:";
  LOG(INFO) << "  - " << num_cards << " cards";
  LOG(INFO) << "  - " << num_symbols << " symbols";
  LOG(INFO) << "  - " << num_symbols_per_card << " symbols per card";

  

  Solver solver("dobble");
  

  std::vector<std::vector<IntVar*> > card_symbol_vars(num_cards);
  std::vector<IntVar*> all_card_symbol_vars;
  for (int card_index = 0; card_index < num_cards; ++card_index) {
    solver.MakeBoolVarArray(num_symbols,
                            absl::StrFormat("card_%i_", card_index),
                            &card_symbol_vars[card_index]);
    for (int symbol_index = 0; symbol_index < num_symbols; ++symbol_index) {
      all_card_symbol_vars.push_back(
          card_symbol_vars[card_index][symbol_index]);
    }
  }
  

  

  std::vector<IntVar*> violation_vars;
  for (int card1 = 0; card1 < num_cards; ++card1) {
    for (int card2 = 0; card2 < num_cards; ++card2) {
      if (card1 != card2) {
        violation_vars.push_back(
            CreateViolationVar(&solver, card_symbol_vars[card1],
                               card_symbol_vars[card2], num_symbols_per_card));
      }
    }
  }
  

  IntVar* const objective_var = solver.MakeSum(violation_vars)->Var();

  

  

  for (int card = 0; card < num_cards; ++card) {
    solver.AddConstraint(
        solver.MakeSumEquality(card_symbol_vars[card], num_symbols_per_card));
  }

  

  

  

  

  

  

  for (int symbol_index = 0; symbol_index < num_symbols; ++symbol_index) {
    std::vector<IntVar*> tmp;
    for (int card_index = 0; card_index < num_cards; ++card_index) {
      tmp.push_back(card_symbol_vars[card_index][symbol_index]);
    }
    solver.AddConstraint(solver.MakeSumEquality(tmp, num_symbols_per_card));
  }

  

  LOG(INFO) << "Solving with Local Search";
  LOG(INFO) << "  - time limit = " << absl::GetFlag(FLAGS_time_limit_in_ms)
            << " ms";

  

  

  

  DecisionBuilder* const build_db = solver.MakePhase(
      all_card_symbol_vars, Solver::CHOOSE_RANDOM,  

      Solver::ASSIGN_MAX_VALUE);                    


  

  std::vector<LocalSearchOperator*> operators;
  LocalSearchOperator* const switch_operator = solver.RevAlloc(new SwapSymbols(
      all_card_symbol_vars, num_cards, num_symbols, num_symbols_per_card));
  operators.push_back(switch_operator);
  LOG(INFO) << "  - add switch operator";
  if (absl::GetFlag(FLAGS_num_swaps) > 0) {
    LocalSearchOperator* const swaps_operator =
        solver.RevAlloc(new SwapSymbolsOnCardPairs(
            all_card_symbol_vars, num_cards, num_symbols, num_symbols_per_card,
            absl::GetFlag(FLAGS_num_swaps)));
    operators.push_back(swaps_operator);
    LOG(INFO) << "  - add swaps operator with at most "
              << absl::GetFlag(FLAGS_num_swaps) << " swaps";
  }

  

  std::vector<LocalSearchFilter*> filters;
  if (absl::GetFlag(FLAGS_use_filter)) {
    filters.push_back(solver.RevAlloc(new DobbleFilter(
        all_card_symbol_vars, num_cards, num_symbols, num_symbols_per_card)));
  }
  LocalSearchFilterManager* ls_manager =
      solver.RevAlloc(new LocalSearchFilterManager(std::move(filters)));
  

  

  

  DecisionBuilder* const final_db = solver.MakeLocalSearchPhase(
      all_card_symbol_vars, build_db,
      solver.MakeLocalSearchPhaseParameters(
          objective_var, solver.ConcatenateOperators(operators, true),
          nullptr,  

          nullptr,  

                    

                    

          ls_manager));

  std::vector<SearchMonitor*> monitors;
  

  OptimizeVar* const optimize = solver.MakeMinimize(objective_var, 1);
  monitors.push_back(optimize);

  

  SearchMonitor* const log = solver.MakeSearchLog(100000, optimize);
  monitors.push_back(log);

  

  SearchLimit* const time_limit = solver.MakeTimeLimit(
      absl::Milliseconds(absl::GetFlag(FLAGS_time_limit_in_ms)));
  monitors.push_back(time_limit);

  

  solver.Solve(final_db, monitors);
}
}  


int main(int argc, char** argv) {
  InitGoogle(argv[0], &argc, &argv, true);
  

  

  const int kSymbolsPerCard = absl::GetFlag(FLAGS_symbols_per_card);
  const int kCards = kSymbolsPerCard * (kSymbolsPerCard - 1) + 1;
  const int kSymbols = kCards;
  operations_research::SolveDobble(kCards, kSymbols, kSymbolsPerCard);
  return EXIT_SUCCESS;
}
