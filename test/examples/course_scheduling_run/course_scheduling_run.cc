





































#include <cstdlib>

#include "examples/cpp/course_scheduling.h"
#include "ortools/base/commandlineflags.h"
#include "ortools/base/helpers.h"
#include "ortools/base/init_google.h"
#include "ortools/base/options.h"
#include "ortools/base/timer.h"
#include "ortools/scheduling/course_scheduling.pb.h"

ABSL_FLAG(std::string, input, "",
          "Input file containing a CourseSchedulingModel in text format.");

namespace operations_research {

void Main() {
  CourseSchedulingModel input;
  const auto proto_status =
      file::GetTextProto(absl::GetFlag(FLAGS_input), &input, file::Defaults());
  if (!proto_status.ok()) {
    LOG(ERROR) << proto_status.message();
    return;
  }

  CourseSchedulingSolver solver;
  WallTimer timer;
  timer.Start();
  const CourseSchedulingResult result = solver.Solve(input);
  timer.Stop();

  LOG(INFO) << "Solver result status: "
            << CourseSchedulingResultStatus_Name(result.solver_status()) << ". "
            << result.message();

  for (const ClassAssignment& class_assignment : result.class_assignments()) {
    const int course_index = class_assignment.course_index();
    const int section_number = class_assignment.section_number();

    int teacher_index = 0;
    const Course& course = input.courses(course_index);
    int sections = 0;
    for (int section_index = 0;
         section_index < course.teacher_section_counts_size();
         ++section_index) {
      sections += course.teacher_section_counts(section_index);
      if (section_number < sections) {
        teacher_index = course.teacher_indices(section_index);
        break;
      }
    }

    LOG(INFO) << course.display_name();
    LOG(INFO) << "  Section: " << section_number;
    LOG(INFO) << "  Teacher: " << input.teachers(teacher_index).display_name();
    for (int i = 0; i < class_assignment.time_slots_size(); ++i) {
      if (input.rooms_size() > 0) {
        LOG(INFO)
            << "  Scheduled for time slot " << class_assignment.time_slots(i)
            << " in room "
            << input.rooms(class_assignment.room_indices(i)).display_name();
      } else {
        LOG(INFO) << "  Scheduled for time slot "
                  << class_assignment.time_slots(i);
      }
    }
  }

  for (const StudentAssignment& student_assignment :
       result.student_assignments()) {
    const int student_index = student_assignment.student_index();

    LOG(INFO) << input.students(student_index).display_name();
    for (int i = 0; i < student_assignment.course_indices_size(); ++i) {
      LOG(INFO)
          << "  "
          << input.courses(student_assignment.course_indices(i)).display_name()
          << " " << student_assignment.section_indices(i);
    }
  }

  LOG(INFO) << "Solved model in " << timer.GetDuration();
}

}  


int main(int argc, char** argv) {
  InitGoogle(argv[0], &argc, &argv, 
true);
  operations_research::Main();
  return EXIT_SUCCESS;
}
