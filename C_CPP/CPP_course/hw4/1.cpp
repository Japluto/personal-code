#include <iostream>
#include <cmath> // 要用sqrt (平方根) 函数

int main()
{
    double a, b, c;
    std::cout << "请输入三角形的三边 (a, b, c)，以空格分隔: ";
    std::cin >> a >> b >> c;
    // 检查是否满足三角形的条件
    // (a+b>c) && (b+c>a) && (c+a>b)
    if (a > 0 && b > 0 && c > 0 && (a + b > c) && (b + c > a) && (c + a > b))
    {
        // 先计算半周长 s
        double s = (a + b + c) / 2.0;

        // 计算面积 (海伦公式) ，s(s-a)(s-b)(s-c) 是面积的平方
        double area = std::sqrt(s * (s - a) * (s - b) * (s - c));
        std::cout << "三角形的面积为: " << area << std::endl;
    }
    else
    {
        // 不满足条件，使用 cerr 输出错误信息
        std::cerr << "错误：输入的三边 (" << a << ", " << b << ", " << c << ") 无法构成有效的三角形。" << std::endl;
    }
    return 0;
}