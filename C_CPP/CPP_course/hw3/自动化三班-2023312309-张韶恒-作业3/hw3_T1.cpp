// 1. 建立一个对象数组，内放5个学生的数据(姓名、学号、成绩)，用指针指向数组首元素，输出第1，3，5个学生的数据。
// （例如：姓名：李明 学号：01 成绩：100）

#include <iostream>
#include <string>

// 建立一个Student类
class Student
{
private:
    std::string name; // 姓名
    std::string sno;  // 学号 (student number)
    float score;      // 成绩

public:
    // 构造函数，用于初始化对象
    Student(std::string n, std::string s, float sc)
    {
        name = n;
        sno = s;
        score = sc;
    }

    // 显示学生信息的成员函数
    void display()
    {
        std::cout << "姓名：" << name << " 学号：" << sno << " 成绩：" << score << std::endl;
    }
};

int main()
{
    //  建立一个对象数组，内放5个学生的数据
    Student students[5] = {
        Student("张三", "2025001", 95.5),
        Student("李四", "2025002", 88.0),
        Student("王五", "2025003", 92.0),
        Student("赵六", "2025004", 76.5),
        Student("孙七", "2025005", 85.0)};

    //  用指针指向数组首元素
    Student *p = students;

    //  输出第1，3，5个学生的数据
    std::cout << "输出第1个学生的数据：" << std::endl;
    p->display(); // p指向第1个元素

    std::cout << "\n输出第3个学生的数据：" << std::endl;
    (p + 2)->display(); // p+2 指向第3个元素

    std::cout << "\n输出第5个学生的数据：" << std::endl;
    (p + 4)->display(); // p+4 指向第5个元素

    return 0;
}