#include "Globals.h"
#include <string.h>
#include <iostream>

const int compareNames(Student& st1, Student& st2) {
    if (strlen(st1.getName()) == strlen(st2.getName())) {
        std::cout << "Name-wise, the students name lengths are equal." << '\n';
        return 0;
    } else if (strlen(st1.getName()) > strlen(st2.getName())) {
        std::cout << "Name-wise, the first student name is longer than the second." << '\n';
        return 1;
    }
    std::cout << "Name-wise, the second student name is longer than the first." << '\n';
    return -1;
}

const int compareHistoryGrade(Student st1, Student st2) {
    if (st1.getHistoryGrade() == st2.getHistoryGrade()) {
        std::cout << "The history grade of the students are equal." << '\n';
        return 0;
    } else if (st1.getHistoryGrade() > st2.getHistoryGrade()) {
        std::cout << "The history grade of the first student is greater." << '\n';
        return 1;
    }
    std::cout << "The history grade of the second student is greater." << '\n';
    return -1;
}

const int compareEnglishGrade(Student st1, Student st2) {
    if (st1.getEnglishGrade() == st2.getEnglishGrade()) {
        std::cout << "The english grade of the students are equal." << '\n';
        return 0;
    } else if (st1.getEnglishGrade() > st2.getEnglishGrade()) {
        std::cout << "The english grade of the first student is greater." << '\n';
        return 1;
    }
    std::cout << "The english grade of the second student is greater." << '\n';
    return -1;
}

const int compareMathGrade(Student st1, Student st2) {
    if (st1.getMathGrade() == st2.getMathGrade()) {
        std::cout << "The math grade of the students are equal." << '\n';
        return 0;
    } else if (st1.getMathGrade() > st2.getMathGrade()) {
        std::cout << "The math grade of the first student is greater." << '\n';
        return 1;
    }
    std::cout << "The math grade of the second student is greater." << '\n';
    return -1;
}

const int compareAverages(Student st1, Student st2) {
    if (st1.getAverageGrade() == st2.getAverageGrade()) {
        std::cout << "The average grade of the students are equal." << '\n';
        return 0;
    } else if (st1.getAverageGrade() > st2.getAverageGrade()) {
        std::cout << "The average grade of the first student is greater." << '\n';
        return 1;
    }
    std::cout << "The average grade of the second student is greater." << '\n';
    return -1;
}
