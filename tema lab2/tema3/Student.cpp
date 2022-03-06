#define _CRT_SECURE_NO_WARNINGS

#include "Student.h"
#include <iostream>

void Student::setName() {
    std::cout << "Student name: " << '\n';
    scanf("%s", &Name);
}

void Student::setHistoryGrade() {
loop:
    std::cout << "Set history grade: " << '\n';
    float grade;
    std::cin >> grade;
    if (grade >= 1.0 && grade <= 10.0) {
        grade_history = grade;
    } else {
        std::cout << "Grade isn't between 1 and 10. Set another grade: " << '\n';
        goto loop;
    }
}

void Student::setEnglishGrade() {
loop:
    std::cout << "Set english grade: " << '\n';
    float grade;
    std::cin >> grade;
    if (grade >= 1.0 && grade <= 10.0) {
        grade_english = grade;
    } else {
        std::cout << "Grade isn't between 1 and 10. Set another grade: " << '\n';
        goto loop;
    }
}

void Student::setMathGrade() {
loop:
    std::cout << "Set math grade: " << '\n';
    float grade;
    std::cin >> grade;
    if (grade >= 1.0 && grade <= 10.0) {
        grade_math = grade;
    } else {
        std::cout << "Grade isn't between 1 and 10. Set another grade: " << '\n';
        goto loop;
    }
}

const char* Student::getName() const {
    return &Name[0];
}

const float Student::getHistoryGrade() const {
    return grade_history;
}

const float Student::getEnglishGrade() const {
    return grade_english;
}

const float Student::getMathGrade() const {
    return grade_math;
}
const float Student::getAverageGrade() {
    average = (grade_english + grade_history + grade_math) / 3;
    return average;
}
