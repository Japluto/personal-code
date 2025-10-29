// main.c

#include <stdio.h>
#include "student.h"
#include "database.h"

int main()
{
    // 初始化数据库
    init_database();

    // 创建几个学生
    Student alice = create_student(101, "Alice", 2005, 8, 15);
    set_student_scores(&alice, 88.0f, 92.5f, 76.0f);

    Student bob = create_student(102, "Bob", 2006, 3, 22);
    set_student_scores(&bob, 95.0f, 85.5f, 89.0f);

    // 将学生添加到数据库
    add_student_to_db(&alice);
    add_student_to_db(&bob);

    // 打印整个数据库
    print_database();

    // 查找指定ID的学生并进行操作
    printf("Searching for student with ID 102...\n");
    Student *found_student = find_student_by_id(102);
    if (found_student != NULL)
    {
        printf("Found student: %s\n", found_student->name);
        printf("Bob's average score is: %.2f\n", get_student_average_score(found_student));
    }
    else
    {
        printf("Student with ID 102 not found.\n");
    }

    return 0;
}