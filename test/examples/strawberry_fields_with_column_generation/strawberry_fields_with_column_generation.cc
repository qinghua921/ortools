







































































































#include <cstdlib>
#include <cstring>  

#include <map>
#include <memory>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

#include "absl/flags/flag.h"
#include "absl/log/check.h"
#include "absl/strings/str_format.h"
#include "absl/types/span.h"
#include "ortools/base/commandlineflags.h"
#include "ortools/base/init_google.h"
#include "ortools/base/logging.h"
#include "ortools/linear_solver/linear_solver.h"

ABSL_FLAG(bool, colgen_verbose, false, "print verbosely");
ABSL_FLAG(bool, colgen_complete, false, "generate all columns initially");
ABSL_FLAG(int, colgen_max_iterations, 500, "max iterations");
ABSL_FLAG(std::string, colgen_solver, "glop", "solver - glop (default) or clp");
ABSL_FLAG(int, colgen_instance, -1, "Which instance to solve (0 - 9)");

namespace operations_research {


struct Instance {
  int max_boxes;
  int width;
  int height;
  const char* grid;
};

Instance kInstances[] = {{4, 22, 6,
                          "..@@@@@..............."
                          "..@@@@@@........@@@..."
                          ".....@@@@@......@@@..."
                          ".......@@@@@@@@@@@@..."
                          ".........@@@@@........"
                          ".........@@@@@........"},
                         {3, 13, 10,
                          "............."
                          "............."
                          "............."
                          "...@@@@......"
                          "...@@@@......"
                          "...@@@@......"
                          ".......@@@..."
                          ".......@@@..."
                          ".......@@@..."
                          "............."},
                         {4, 13, 9,
                          "............."
                          "..@.@.@......"
                          "...@.@.@....."
                          "..@.@.@......"
                          "..@.@.@......"
                          "...@.@.@....."
                          "....@.@......"
                          "..........@@@"
                          "..........@@@"},
                         {4, 13, 9,
                          ".........@..."
                          ".........@..."
                          "@@@@@@@@@@..."
                          "..@......@..."
                          "..@......@..."
                          "..@......@..."
                          "..@@@@@@@@@@@"
                          "..@.........."
                          "..@.........."},
                         {7, 25, 14,
                          "........................."
                          "..@@@@@@@@@@@@@@@@@@@@..."
                          "..@@@@@@@@@@@@@@@@@@@@..."
                          "..@@.................@..."
                          "..@@.................@..."
                          "..@@.......@@@.......@.@."
                          "..@@.......@@@.......@..."
                          "..@@...@@@@@@@@@@@@@@@..."
                          "..@@...@@@@@@@@@@@@@@@..."
                          "..@@.......@@@.......@..."
                          "..@@.......@@@.......@..."
                          "..@@.................@..."
                          "..@@.................@..."
                          "........................."},
                         {6, 25, 16,
                          "........................."
                          "......@@@@@@@@@@@@@......"
                          "........................."
                          ".....@..........@........"
                          ".....@..........@........"
                          ".....@......@............"
                          ".....@......@.@@@@@@@...."
                          ".....@......@............"
                          ".....@......@.@@@@@@@...."
                          ".....@......@............"
                          "....@@@@....@............"
                          "....@@@@....@............"
                          "..@@@@@@....@............"
                          "..@@@.......@............"
                          "..@@@...................."
                          "..@@@@@@@@@@@@@@@@@@@@@@@"},
                         {5, 40, 18,
                          "........................................"
                          "........................................"
                          "...@@@@@@..............................."
                          "...@@@@@@..............................."
                          "...@@@@@@..............................."
                          "...@@@@@@.........@@@@@@@@@@............"
                          "...@@@@@@.........@@@@@@@@@@............"
                          "..................@@@@@@@@@@............"
                          "..................@@@@@@@@@@............"
                          ".............@@@@@@@@@@@@@@@............"
                          ".............@@@@@@@@@@@@@@@............"
                          "........@@@@@@@@@@@@...................."
                          "........@@@@@@@@@@@@...................."
                          "........@@@@@@.........................."
                          "........@@@@@@.........................."
                          "........................................"
                          "........................................"
                          "........................................"},
                         {8, 40, 18,
                          "........................................"
                          "..@@.@.@.@.............................."
                          "..@@.@.@.@...............@.............."
                          "..@@.@.@.@............@................."
                          "..@@.@.@.@.............................."
                          "..@@.@.@.@.................@............"
                          "..@@.@..................@..............."
                          "..@@.@.................................."
                          "..@@.@.................................."
                          "..@@.@................@@@@.............."
                          "..@@.@..............@@@@@@@@............"
                          "..@@.@.................................."
                          "..@@.@..............@@@@@@@@............"
                          "..@@.@.................................."
                          "..@@.@................@@@@.............."
                          "..@@.@.................................."
                          "..@@.@.................................."
                          "........................................"},
                         {10, 40, 19,
                          "@@@@@..................................."
                          "@@@@@..................................."
                          "@@@@@..................................."
                          "@@@@@..................................."
                          "@@@@@..................................."
                          "@@@@@...........@@@@@@@@@@@............."
                          "@@@@@...........@@@@@@@@@@@............."
                          "....................@@@@................"
                          "....................@@@@................"
                          "....................@@@@................"
                          "....................@@@@................"
                          "....................@@@@................"
                          "...............@@@@@@@@@@@@@@..........."
                          "...............@@@@@@@@@@@@@@..........."
                          ".......@@@@@@@@@@@@@@@@@@@@@@..........."
                          ".......@@@@@@@@@........................"
                          "........................................"
                          "........................................"
                          "........................................"},
                         {10, 40, 25,
                          "...................@...................."
                          "...............@@@@@@@@@................"
                          "............@@@.........@@@............."
                          "...........@...............@............"
                          "..........@.................@..........."
                          ".........@...................@.........."
                          ".........@...................@.........."
                          ".........@.....@@......@@....@.........."
                          "........@.....@@@@....@@@@....@........."
                          "........@.....................@........."
                          "........@.....................@........."
                          "........@..........@@.........@........."
                          ".......@@..........@@.........@@........"
                          "........@.....................@........."
                          "........@.....................@........."
                          "........@......@@@@@@@@@......@........."
                          "........@......@@@@@@@@@......@........."
                          ".........@...................@.........."
                          ".........@...................@.........."
                          ".........@...................@.........."
                          "..........@.................@..........."
                          "...........@...............@............"
                          "............@@@.........@@@............."
                          "...............@@@@@@@@@................"
                          "...................@...................."}};

const int kInstanceCount = 10;




class Box {
 public:
  static constexpr int kAreaCost = 1;
  static constexpr int kFixedCost = 10;

  Box() = default;
  Box(int x_min, int x_max, int y_min, int y_max)
      : x_min_(x_min), x_max_(x_max), y_min_(y_min), y_max_(y_max) {
    CHECK_GE(x_max, x_min);
    CHECK_GE(y_max, y_min);
  }

  int x_min() const { return x_min_; }
  int x_max() const { return x_max_; }
  int y_min() const { return y_min_; }
  int y_max() const { return y_max_; }

  

  int Compare(const Box& box) const {
    int c;
    if ((c = (x_min() - box.x_min())) != 0) return c;
    if ((c = (x_max() - box.x_max())) != 0) return c;
    if ((c = (y_min() - box.y_min())) != 0) return c;
    return y_max() - box.y_max();
  }

  bool Contains(int x, int y) const {
    return x >= x_min() && x <= x_max() && y >= y_min() && y <= y_max();
  }

  int Cost() const {
    return kAreaCost * (x_max() - x_min() + 1) * (y_max() - y_min() + 1) +
           kFixedCost;
  }

  std::string DebugString() const {
    return absl::StrFormat("[%d,%dx%d,%d]c%d", x_min(), y_min(), x_max(),
                           y_max(), Cost());
  }

 private:
  int x_min_;
  int x_max_;
  int y_min_;
  int y_max_;
};

struct BoxLessThan {
  bool operator()(const Box& b1, const Box& b2) const {
    return b1.Compare(b2) < 0;
  }
};




class CoveringProblem {
 public:
  

  

  

  CoveringProblem(MPSolver* const solver, const Instance& instance)
      : solver_(solver),
        max_boxes_(instance.max_boxes),
        width_(instance.width),
        height_(instance.height),
        grid_(instance.grid) {}

  

  

  bool Init() {
    

    int size = strlen(grid_);
    if (size != area()) {
      return false;
    }
    for (int i = 0; i < size; ++i) {
      char c = grid_[i];
      if ((c != '@') && (c != '.')) return false;
    }

    AddCellConstraints();     

    AddMaxBoxesConstraint();  

    if (!absl::GetFlag(FLAGS_colgen_complete)) {
      AddBox(Box(0, width() - 1, 0, height() - 1));  

    } else {
      

      

      for (int y_min = 0; y_min < height(); ++y_min) {
        for (int y_max = y_min; y_max < height(); ++y_max) {
          for (int x_min = 0; x_min < width(); ++x_min) {
            for (int x_max = x_min; x_max < width(); ++x_max) {
              AddBox(Box(x_min, x_max, y_min, y_max));
            }
          }
        }
      }
    }
    return true;
  }

  int width() const { return width_; }
  int height() const { return height_; }
  int area() const { return width() * height(); }
  int max_boxes() const { return max_boxes_; }

  bool IsCellOccupied(int x, int y) const { return grid_[index(x, y)] == '@'; }

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  double GetOptimalBox(Box* const target) {
    

    const double kCostChangeThreshold = -.01;

    

    

    std::vector<double> upper_left_sums(area());
    ComputeUpperLeftSums(&upper_left_sums);

    const double max_boxes_dual = max_boxes_constraint_->dual_value();
    double best_reduced_cost = kCostChangeThreshold;
    Box best_box;
    for (int y_min = 0; y_min < height(); ++y_min) {
      for (int y_max = y_min; y_max < height(); ++y_max) {
        for (int x_min = 0; x_min < width(); ++x_min) {
          for (int x_max = x_min; x_max < width(); ++x_max) {
            Box box(x_min, x_max, y_min, y_max);
            const double cell_coverage_dual =  

                +zero_access(upper_left_sums, x_max, y_max) -
                zero_access(upper_left_sums, x_max, y_min - 1) -
                zero_access(upper_left_sums, x_min - 1, y_max) +
                zero_access(upper_left_sums, x_min - 1, y_min - 1);

            

            

            

            const double reduced_cost =
                box.Cost() - (cell_coverage_dual + max_boxes_dual);

            if (reduced_cost < best_reduced_cost) {
              

              

              

              

              

              

              

              

              

              if (boxes_.find(box) == boxes_.end()) {
                best_reduced_cost = reduced_cost;
                best_box = box;
              }
            }
          }
        }
      }
    }

    if (best_reduced_cost < kCostChangeThreshold) {
      if (target) {
        *target = best_box;
      }
      return best_reduced_cost;
    }
    return 0;
  }

  

  

  MPVariable* AddBox(const Box& box) {
    CHECK(boxes_.find(box) == boxes_.end());
    MPVariable* const var = solver_->MakeNumVar(0., 1., box.DebugString());
    solver_->MutableObjective()->SetCoefficient(var, box.Cost());
    max_boxes_constraint_->SetCoefficient(var, 1.0);
    for (int y = box.y_min(); y <= box.y_max(); ++y) {
      for (int x = box.x_min(); x <= box.x_max(); ++x) {
        cell(x, y)->SetCoefficient(var, 1.0);
      }
    }
    boxes_[box] = var;
    return var;
  }

  std::string PrintGrid() const {
    std::string output =
        absl::StrFormat("width = %d, height = %d, max_boxes = %d\n", width_,
                        height_, max_boxes_);
    for (int y = 0; y < height_; ++y) {
      absl::StrAppendFormat(&output, "%s\n",
                            std::string(grid_ + width_ * y, width_));
    }
    return output;
  }

  

  

  

  

  std::string PrintCovering() const {
    static const double kTolerance = 1e-5;
    std::string output =
        absl::StrFormat("cost = %f\n", solver_->Objective().Value());
    std::unique_ptr<char[]> display(new char[(width_ + 1) * height_ + 1]);
    for (int y = 0; y < height_; ++y) {
      memcpy(display.get() + y * (width_ + 1), grid_ + width_ * y,
             width_);  

      display[y * (width_ + 1) + width_] = '\n';
    }
    display[height_ * (width_ + 1)] = '\0';
    int active_box_index = 0;
    for (BoxTable::const_iterator i = boxes_.begin(); i != boxes_.end(); ++i) {
      const double value = i->second->solution_value();
      if (value > kTolerance) {
        const char box_character =
            (i->second->solution_value() >= (1. - kTolerance) ? 'A' : 'a') +
            active_box_index++;
        absl::StrAppendFormat(&output, "%c: box %s with value %f\n",
                              box_character, i->first.DebugString(), value);
        const Box& box = i->first;
        for (int x = box.x_min(); x <= box.x_max(); ++x) {
          for (int y = box.y_min(); y <= box.y_max(); ++y) {
            display[x + y * (width_ + 1)] = box_character;
          }
        }
      }
    }
    output.append(display.get());
    return output;
  }

 protected:
  int index(int x, int y) const { return width_ * y + x; }
  MPConstraint* cell(int x, int y) { return cells_[index(x, y)]; }
  const MPConstraint* cell(int x, int y) const { return cells_[index(x, y)]; }

  

  

  void AddCellConstraints() {
    cells_.resize(area());
    for (int y = 0; y < height(); ++y) {
      for (int x = 0; x < width(); ++x) {
        cells_[index(x, y)] =
            solver_->MakeRowConstraint(IsCellOccupied(x, y) ? 1. : 0., 1.);
      }
    }
  }

  

  void AddMaxBoxesConstraint() {
    max_boxes_constraint_ = solver_->MakeRowConstraint(0., max_boxes());
  }

  

  double zero_access(absl::Span<const double> array, int x, int y) const {
    if (x < 0 || y < 0) {
      return 0;
    }
    return array[index(x, y)];
  }

  

  

  void ComputeUpperLeftSums(std::vector<double>* upper_left_sums) const {
    for (int y = 0; y < height(); ++y) {
      for (int x = 0; x < width(); ++x) {
        upper_left_sums->operator[](index(x, y)) =
            cell(x, y)->dual_value() + zero_access(*upper_left_sums, x - 1, y) +
            zero_access(*upper_left_sums, x, y - 1) -
            zero_access(*upper_left_sums, x - 1, y - 1);
      }
    }
  }

  typedef std::map<Box, MPVariable*, BoxLessThan> BoxTable;
  MPSolver* const solver_;  

  const int max_boxes_;
  const int width_;
  const int height_;
  const char* const grid_;
  std::vector<MPConstraint*> cells_;
  BoxTable boxes_;
  MPConstraint* max_boxes_constraint_;
};








void SolveInstance(const Instance& instance,
                   MPSolver::OptimizationProblemType solver_type) {
  

  MPSolver solver("ColumnGeneration", solver_type);
  solver.SuppressOutput();
  solver.MutableObjective()->SetMinimization();

  

  CoveringProblem problem(&solver, instance);
  CHECK(problem.Init());
  LOG(INFO) << "Initial problem:\n" << problem.PrintGrid();

  int step_number = 0;
  while (step_number < absl::GetFlag(FLAGS_colgen_max_iterations)) {
    if (absl::GetFlag(FLAGS_colgen_verbose)) {
      LOG(INFO) << "Step number " << step_number;
    }

    

    CHECK_EQ(MPSolver::OPTIMAL, solver.Solve());
    if (absl::GetFlag(FLAGS_colgen_verbose)) {
      LOG(INFO) << problem.PrintCovering();
    }

    

    Box box;
    const double reduced_cost = problem.GetOptimalBox(&box);
    if (reduced_cost >= 0) {
      break;
    }

    

    if (absl::GetFlag(FLAGS_colgen_verbose)) {
      LOG(INFO) << "Adding " << box.DebugString()
                << ", reduced_cost =" << reduced_cost;
    }
    problem.AddBox(box);

    ++step_number;
  }

  if (step_number >= absl::GetFlag(FLAGS_colgen_max_iterations)) {
    

    CHECK_EQ(MPSolver::OPTIMAL, solver.Solve());
  }

  LOG(INFO) << step_number << " columns added";
  LOG(INFO) << "Final coverage: " << problem.PrintCovering();
}
}  


int main(int argc, char** argv) {
  std::string usage = "column_generation\n";
  usage += "  --colgen_verbose             print verbosely\n";
  usage += "  --colgen_max_iterations <n>  max columns to generate\n";
  usage += "  --colgen_complete            generate all columns at start\n";

  absl::SetFlag(&FLAGS_stderrthreshold, 0);
  InitGoogle(usage.c_str(), &argc, &argv, true);

  operations_research::MPSolver::OptimizationProblemType solver_type;
  bool found = false;
#if defined(USE_CLP)
  if (absl::GetFlag(FLAGS_colgen_solver) == "clp") {
    solver_type = operations_research::MPSolver::CLP_LINEAR_PROGRAMMING;
    found = true;
  }
#endif  

  if (absl::GetFlag(FLAGS_colgen_solver) == "glop") {
    solver_type = operations_research::MPSolver::GLOP_LINEAR_PROGRAMMING;
    found = true;
  }
#if defined(USE_XPRESS)
  if (absl::GetFlag(FLAGS_colgen_solver) == "xpress") {
    solver_type = operations_research::MPSolver::XPRESS_LINEAR_PROGRAMMING;
    

    found = true;
  }
#endif
#if defined(USE_CPLEX)
  if (absl::GetFlag(FLAGS_colgen_solver) == "cplex") {
    solver_type = operations_research::MPSolver::CPLEX_LINEAR_PROGRAMMING;
    found = true;
  }
#endif
  if (!found) {
    LOG(ERROR) << "Unknown solver " << absl::GetFlag(FLAGS_colgen_solver);
    return 1;
  }

  LOG(INFO) << "Chosen solver: " << absl::GetFlag(FLAGS_colgen_solver)
            << std::endl;

  if (absl::GetFlag(FLAGS_colgen_instance) == -1) {
    for (int i = 0; i < operations_research::kInstanceCount; ++i) {
      const operations_research::Instance& instance =
          operations_research::kInstances[i];
      operations_research::SolveInstance(instance, solver_type);
    }
  } else {
    CHECK_GE(absl::GetFlag(FLAGS_colgen_instance), 0);
    CHECK_LT(absl::GetFlag(FLAGS_colgen_instance),
             operations_research::kInstanceCount);
    const operations_research::Instance& instance =
        operations_research::kInstances[absl::GetFlag(FLAGS_colgen_instance)];
    operations_research::SolveInstance(instance, solver_type);
  }
  return EXIT_SUCCESS;
}
