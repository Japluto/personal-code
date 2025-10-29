// student.h

#ifndef STUDENT_H
#define STUDENT_H

// 定义一个日期结构体
typedef struct
{
    int year;
    int month;
    int day;
} Date;

// 定义一个学生结构体
typedef struct
{
    int id;
    char name[50];
    Date date_of_birth;
    float scores[3]; // 假设有3门课程：语文、数学、英语
} Student;

// --- 函数声明 ---

// 创建并初始化一个学生对象 (类似构造函数)
Student create_student(int id, const char *name, int year, int month, int day);

// 设置一个学生的三门课成绩
void set_student_scores(Student *s, float score1, float score2, float score3);

// 计算一个学生的平均分
float get_student_average_score(const Student *s);

// 打印单个学生的信息
void print_student_info(const Student *s);

#endif // STUDENT_H