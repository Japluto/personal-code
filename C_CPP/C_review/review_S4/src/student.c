// student.c

#include <stdio.h>
#include <string.h> // for strcpy
#include "student.h"

// 创建学生对象的函数定义
Student create_student(int id, const char *name, int year, int month, int day)
{
    Student new_student;
    new_student.id = id;
    strcpy(new_student.name, name); // 字符串赋值需要用 strcpy
    new_student.date_of_birth.year = year;
    new_student.date_of_birth.month = month;
    new_student.date_of_birth.day = day;
    // 成绩默认为0
    for (int i = 0; i < 3; i++)
    {
        new_student.scores[i] = 0.0f;
    }
    return new_student;
}

// 设置成绩的函数定义
void set_student_scores(Student *s, float score1, float score2, float score3)
{
    if (s != NULL)
    { // 检查指针是否有效
        s->scores[0] = score1;
        s->scores[1] = score2;
        s->scores[2] = score3;
    }
}

// 计算平均分的函数定义
float get_student_average_score(const Student *s)
{
    if (s == NULL)
        return 0.0f;
    float total = 0.0f;
    for (int i = 0; i < 3; i++)
    {
        total += s->scores[i];
    }
    return total / 3.0f;
}

// 打印信息的函数定义
void print_student_info(const Student *s)
{
    if (s == NULL)
        return;
    printf("----------------------------------------\n");
    printf("ID:   %d\n", s->id);
    printf("Name: %s\n", s->name);
    printf("DOB:  %d-%02d-%02d\n", s->date_of_birth.year, s->date_of_birth.month, s->date_of_birth.day);
    printf("Scores: %.1f, %.1f, %.1f\n", s->scores[0], s->scores[1], s->scores[2]);
    printf("Average Score: %.2f\n", get_student_average_score(s));
    printf("----------------------------------------\n");
}