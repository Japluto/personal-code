// database.c

#include <stdio.h>
#include "database.h"

#define DB_CAPACITY 10 // 数据库最大容量

// 使用 static 将这两个变量的作用域限制在本文件内，实现数据隐藏
static Student student_database[DB_CAPACITY];
static int student_count = 0;

void init_database(void)
{
    student_count = 0;
    // (可以添加清空数组的逻辑，但这里 student_count=0 已经足够)
}

int add_student_to_db(const Student *s)
{
    if (student_count >= DB_CAPACITY)
    {
        printf("Error: Database is full.\n");
        return 0; // 失败
    }
    student_database[student_count] = *s;
    student_count++;
    return 1; // 成功
}

void print_database(void)
{
    printf("\n=========== Student Database ===========\n");
    if (student_count == 0)
    {
        printf("Database is empty.\n");
    }
    else
    {
        for (int i = 0; i < student_count; i++)
        {
            print_student_info(&student_database[i]);
        }
    }
    printf("======================================\n\n");
}

Student *find_student_by_id(int id)
{
    for (int i = 0; i < student_count; i++)
    {
        if (student_database[i].id == id)
        {
            return &student_database[i]; // 返回指向该学生的指针
        }
    }
    return NULL; // 未找到
}