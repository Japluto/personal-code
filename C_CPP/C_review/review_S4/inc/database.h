// database.h

#ifndef DATABASE_H
#define DATABASE_H

#include "student.h" // 需要知道 Student 是什么样子

// --- 函数声明 ---

// 初始化数据库
void init_database(void);

// 向数据库中添加一个学生 (成功返回1, 失败返回0)
int add_student_to_db(const Student *s);

// 打印数据库中所有学生的信息
void print_database(void);

// 根据ID查找学生 (找到返回学生指针, 没找到返回 NULL)
Student *find_student_by_id(int id);

#endif // DATABASE_H