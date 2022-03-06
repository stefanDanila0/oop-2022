#pragma once
class Student {
    char Name[56]       = "\0";
    float grade_history = 0;
    float grade_english = 0;
    float grade_math    = 0;
    float average       = 0;

  public:
    void setName();
    void setHistoryGrade();
    void setEnglishGrade();
    void setMathGrade();

    const char* getName() const;
    const float getHistoryGrade() const;
    const float getEnglishGrade() const;
    const float getMathGrade() const;
    const float getAverageGrade();
};