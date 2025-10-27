#include <iostream>
#include <iomanip> // 使用 fixed, setprecision, setw
#include <vector>
int main()
{
    std::vector<double> numbers;
    double num;
    std::cout << "请输入一批数值 (输入非数字或按 Ctrl+Z/Ctrl+D 结束):" << std::endl;
    // 循环读取一批数值
    while (std::cin >> num)
    {
        numbers.push_back(num);
    }
    std::cout << "\n格式化输出结果:" << std::endl;
    // 设置输出格式：固定小数表示法，保留3位小数
    // 这两个设置是“粘性”的，设置一次即可
    std::cout << std::fixed << std::setprecision(3);
    // 遍历 vector 并输出
    for (double val : numbers)
    {
        // 通过设置一个固定的总宽度并右对齐（默认）来实现
        std::cout << std::setw(20) << val << std::endl;
    }
    return 0;
}