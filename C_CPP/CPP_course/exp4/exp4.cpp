#include <iostream>
#include <cmath> // 用于数学计算 (sqrt, pow, abs)

// 定义一个常量PI
const double PI = 3.14159265358979323846;

// 定义顶点Point类
class Point
{
public:
    double x, y;

    // 构造函数
    Point(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {}

    // 辅助函数：计算当前点到另一个点的距离
    double distanceTo(const Point &other) const
    {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }
};

// 定义抽象基类Shape
class Shape
{
public:
    // 纯虚函数 (pure virtual function)
    // 使得 Shape 成为一个抽象基类
    virtual double area() const = 0;

    // 基类应始终有虚析构函数，以确保派生类对象被正确销毁
    virtual ~Shape()
    {
        // 析构函数体可以为空
    }
};

// 定义派生类
class Circle : public Shape
{
private:
    Point center;
    double radius;

public:
    // 构造函数，在定义对象时给定数据 [cite: 13]
    Circle(const Point &c, double r) : center(c), radius(r)
    {
        // 要求：构造函数中应判断给定顶点组合是否满足图形属性
        if (radius <= 0)
        {
            std::cerr << "Error: Invalid Circle. Radius must be positive. Setting radius to 0." << std::endl;
            radius = 0; // 置为一个安全(0面积)状态
        }
    }

    // 重写(override)基类的纯虚函数 area()
    double area() const override
    {
        return PI * radius * radius;
    }
};

class Triangle : public Shape
{
private:
    Point v1, v2, v3;
    double side1, side2, side3; // 存储三边边长

public:
    // 构造函数，在定义对象时给定数据 [cite: 13]
    Triangle(const Point &p1, const Point &p2, const Point &p3) : v1(p1), v2(p2), v3(p3)
    {
        side1 = v1.distanceTo(v2);
        side2 = v2.distanceTo(v3);
        side3 = v3.distanceTo(v1);

        // 要求：构造函数中应判断给定顶点组合是否满足图形属性
        // 校验：任意两边之和必须大于第三边 (检查是否共线)
        if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1)
        {
            std::cerr << "Error: Invalid Triangle. Points are collinear. Setting area to 0." << std::endl;
            // 将边长设为0，这样面积计算将返回0
            side1 = side2 = side3 = 0;
        }
    }

    // 重写(override)基类的纯虚函数 area()
    // 使用海伦公式 (Heron's formula)
    double area() const override
    {
        if (side1 == 0 || side2 == 0 || side3 == 0)
        {
            return 0.0; // 处理无效三角形
        }
        double s = (side1 + side2 + side3) / 2.0;
        return std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
};

class Rectangle : public Shape
{
private:
    Point topLeft;
    Point bottomRight;
    double width;
    double height;

public:
    // 构造函数，在定义对象时给定数据
    // 为简单起见，我们假定给定的是左上角和右下角两个对角顶点
    Rectangle(const Point &p1, const Point &p2) : topLeft(p1), bottomRight(p2)
    {
        width = std::abs(topLeft.x - bottomRight.x);
        height = std::abs(topLeft.y - bottomRight.y);

        // 要求：构造函数中应判断给定顶点组合是否满足图形属性
        if (width == 0 || height == 0)
        {
            std::cerr << "Error: Invalid Rectangle. Width or height is zero. Setting area to 0.\n" << std::endl;
            width = 0; // 置为一个安全(0面积)状态
            height = 0;
        }
    }

    // 重写(override)基类的纯虚函数 area()
    double area() const override
    {
        return width * height;
    }
};

// 主函数 (main) - 实现多态调用
int main()
{
    // 要求用基类指针数组
    const int NUM_SHAPES = 4;
    Shape *shapes[NUM_SHAPES];

    // 使它的每一个元素指向一个派生类的对象
    // 图型的数据在定义对象时给定
    shapes[0] = new Circle(Point(0, 0), 5.0);
    shapes[1] = new Triangle(Point(0, 0), Point(3, 0), Point(0, 4));
    shapes[2] = new Rectangle(Point(1, 1), Point(6, 3));

    // 添加一个无效的三角形来测试构造函数校验
    shapes[3] = new Triangle(Point(0, 0), Point(1, 1), Point(2, 2)); // 这三点共线

    std::cout << "Calculating Areas of Shapes\n"
              << std::endl;

    double totalArea = 0.0;

    // 要求：使用一个循环完成对多个图像的面积计算与求和
    for (int i = 0; i < NUM_SHAPES; ++i)
    {
        // 编译器在编译时不知道 shapes[i] 指向哪个对象,
        // 但在运行时，它会调用正确的 area() (Circle, Triangle 或 Rectangle)
        double currentArea = shapes[i]->area();

        std::cout << "Shape " << i << " area: " << currentArea << std::endl;
        totalArea += currentArea;
    }

    // 要求：并求它们的面积和
    std::cout << "\nTotal area of all shapes: " << totalArea << std::endl;

    // 每次你使用 `new`，都必须在最后使用 `delete`
    for (int i = 0; i < NUM_SHAPES; ++i)
    {
        delete shapes[i];
        shapes[i] = nullptr;
    }

    return 0;
}