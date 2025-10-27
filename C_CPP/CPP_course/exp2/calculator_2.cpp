#include <iostream>
#include <string>
#include <vector>
#include <stdexcept> // 用于异常处理
#include <cctype>    // 用于 isdigit

// 实现模板栈功能
template <typename T>
class Stack
{
private:
    std::vector<T> elems; // 使用 std::vector 作为底层容器

public:
    // 压入元素到栈顶
    void push(T const &elem)
    {
        elems.push_back(elem);
    }

    // 弹出栈顶元素
    void pop()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        elems.pop_back();
    }

    // 返回栈顶元素
    T top() const
    {
        if (isEmpty())
        {
            throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elems.back();
    }

    // 检查栈是否为空
    bool isEmpty() const
    {
        return elems.empty();
    }
};

// 实现表达式计算求值
// 辅助函数：获取运算符的优先级
int getPrecedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    if (op == '*' || op == '/')
    {
        return 2;
    }
    return 0; // 其他符号（如括号）优先级为0
}

// 辅助函数：执行计算
double applyOp(double a, double b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return b - a; // 注意顺序
    case '*':
        return a * b;
    case '/':
        if (a == 0)
        {
            throw std::runtime_error("除数为0，错误!");
        }
        return b / a; // 注意顺序
    }
    return 0;
}

// 核心函数：计算表达式的值
double evaluate(const std::string &expression)
{
    Stack<double> values; // 操作数栈
    Stack<char> ops;      // 操作符栈

    for (int i = 0; i < expression.length(); ++i)
    {
        // 跳过空格
        if (expression[i] == ' ')
        {
            continue;
        }

        // 如果是数字，则解析完整的数字并压入操作数栈
        if (isdigit(expression[i]) || expression[i] == '.')
        {
            std::string num_str;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.'))
            {
                num_str += expression[i];
                i++;
            }
            i--; // 循环会自增，这里回退一步
            values.push(std::stod(num_str));
        }
        // 如果是左括号，压入操作符栈
        else if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            ops.push(expression[i]);
        }
        // 如果是右括号，则处理括号内的表达式
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
        {
            char open_bracket = (expression[i] == ')') ? '(' : ((expression[i] == ']') ? '[' : '{');
            while (!ops.isEmpty() && ops.top() != open_bracket)
            {
                double val1 = values.top(); // 注意这里的操作数顺序
                values.pop();
                double val2 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            if (ops.isEmpty())
            { // 检查是否匹配
                throw std::runtime_error("Mismatched parentheses!");
            }
            ops.pop(); // 弹出左括号
        }
        // 如果是操作符
        else
        {
            // 当操作符栈不为空，且栈顶操作符优先级大于等于当前操作符时，进行计算
            while (!ops.isEmpty() && getPrecedence(ops.top()) >= getPrecedence(expression[i]))
            {
                double val1 = values.top();
                values.pop();
                double val2 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            // 将当前操作符压入栈
            ops.push(expression[i]);
        }
    }

    // 处理栈中剩余的操作符
    while (!ops.isEmpty())
    {
        double val1 = values.top();
        values.pop();
        double val2 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(applyOp(val1, val2, op));
    }

    // 操作数栈中最后剩下的唯一元素就是结果
    return values.top();
}

// 实现主程序
int main()
{
    std::string expression;

    std::cout << "欢迎来到ZSH的C++计算器Ⅱ !" << std::endl;
    std::cout << "请输入一个表达式以供计算，或输入'exit'退出程序：" << std::endl;

    while (true)
    {
        std::getline(std::cin, expression); // 读取一整行输入

        // 检查用户是否希望退出
        if (expression == "exit" || expression == "quit")
        {
            break;
        }

        // 如果用户直接按回车，则继续下一次循环
        if (expression.empty())
        {
            continue;
        }

        try
        {
            double result = evaluate(expression);
            std::cout << "结果为: " << result << std::endl;
        }
        catch (const std::exception &e)
        {
            // 捕获并打印计算过程中可能出现的错误
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    std::cout << "计算器已结束工作，下次见！" << std::endl;

    return 0;
}