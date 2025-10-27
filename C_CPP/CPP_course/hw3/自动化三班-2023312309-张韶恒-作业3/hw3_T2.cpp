// 2. 分别声明 Teacher(教师) 类和 Cadre(干部)类，采用多重继承方式由这两个类派生出新类Teacher Cadre(教师兼干部)。要求 :
// (1)在两个基类中都包含姓名、年龄、性别、地址、电话等数据成员。
// (2) 在Teacher 类中还包含数据成员 title(职称)，在 Cadre 类中还包含数据成员post(职务)。在Teacher Cadre类中还包含数据成员wages(工资)。
// (3)对两个基类中的姓名、年龄、性别、地址、电话等数据成员用相同的名字，在引用这些数据成员时，指定作用域。
// (4) 在类体中声明成员函数，在类外定义成员函数。
// (5) 在派生类Teacher_Cadre 的成员函数 show 中调用 Teacher 类中的display 函数输出姓名、年龄、性别、职称、地址、电话，然后再用cout语句输出职务与工资。

#include <iostream>
#include <string>

// 基类 Teacher
class Teacher
{
protected:
    std::string name;
    int age;
    std::string sex;
    std::string address;
    std::string phone;
    std::string title; // 职称
public:
    // 构造函数声明
    Teacher(std::string n, int a, std::string s, std::string addr, std::string p, std::string t);
    // display函数声明
    void display();
};

// 在类外定义Teacher的成员函数
Teacher::Teacher(std::string n, int a, std::string s, std::string addr, std::string p, std::string t)
{
    name = n;
    age = a;
    sex = s;
    address = addr;
    phone = p;
    title = t;
}

void Teacher::display()
{
    std::cout << "姓名: " << name << std::endl;
    std::cout << "年龄: " << age << std::endl;
    std::cout << "性别: " << sex << std::endl;
    std::cout << "职称: " << title << std::endl;
    std::cout << "地址: " << address << std::endl;
    std::cout << "电话: " << phone << std::endl;
}

// 基类 Cadre
class Cadre
{
protected:
    std::string name;
    int age;
    std::string sex;
    std::string address;
    std::string phone;
    std::string post; // 职务
public:
    // 构造函数声明
    Cadre(std::string n, int a, std::string s, std::string addr, std::string p, std::string po);
    // display函数声明(可选，但良好实践)
    void display();
};

// 在类外定义Cadre的成员函数
Cadre::Cadre(std::string n, int a, std::string s, std::string addr, std::string p, std::string po)
{
    name = n;
    age = a;
    sex = s;
    address = addr;
    phone = p;
    post = po;
}

void Cadre::display()
{
    std::cout << "姓名: " << name << std::endl;
    std::cout << "年龄: " << age << std::endl;
    std::cout << "性别: " << sex << std::endl;
    std::cout << "职务: " << post << std::endl;
    std::cout << "地址: " << address << std::endl;
    std::cout << "电话: " << phone << std::endl;
}

// 派生类 Teacher_Cadre
class Teacher_Cadre : public Teacher, public Cadre
{
private:
    float wages; // 工资
public:
    // 构造函数声明
    Teacher_Cadre(std::string n, int a, std::string s, std::string addr, std::string p, std::string t, std::string po, float w);
    // show函数声明
    void show();
};

// 在类外定义Teacher_Cadre的成员函数
// 构造函数需要分别调用基类的构造函数
Teacher_Cadre::Teacher_Cadre(std::string n, int a, std::string s, std::string addr, std::string p, std::string t, std::string po, float w)
    : Teacher(n, a, s, addr, p, t), Cadre(n, a, s, addr, p, po), wages(w) {}

void Teacher_Cadre::show()
{
    // (5) 调用Teacher类的display函数输出基本信息和职称
    Teacher::display();
    // 再用cout语句输出职务与工资
    std::cout << "职务: " << Cadre::post << std::endl; // 明确指定从Cadre类继承的post
    std::cout << "工资: " << wages << std::endl;
}

int main()
{
    // 创建一个教师兼干部对象
    Teacher_Cadre tc("王教授", 45, "男", "深圳市南山区", "1145141919810", "教授", "系主任", 80000.0);

    // 调用show函数显示其所有信息
    tc.show();

    return 0;
}