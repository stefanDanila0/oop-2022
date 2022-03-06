#include "Student.h"
#include "Globals.h"

int main() {
    Student student1{};
    Student student2{};

    student1.setName();
    student1.setHistoryGrade();
    student1.setEnglishGrade();
    student1.setMathGrade();
    student1.getAverageGrade();

    student2.setName();
    student2.setHistoryGrade();
    student2.setEnglishGrade();
    student2.setMathGrade();
    student2.getAverageGrade();

    compareNames(student1, student2);
    compareHistoryGrade(student1, student2);
    compareEnglishGrade(student1, student2);
    compareMathGrade(student1, student2);
    compareAverages(student1, student2);
}