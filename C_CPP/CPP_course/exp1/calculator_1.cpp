#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>

const int STACK_MAX_SIZE = 100;

class CharStack
{
private:
    char data[STACK_MAX_SIZE]; // 用于存储栈元素的数组，最大容量为STACK_MAX_SIZE
    int top_index;             // 栈顶元素的索引，-1表示栈为空

public:
    CharStack()
    {
        top_index = -1;
    }

    /**
     * 压栈操作：将一个字符压入栈顶
     * @param c 要压入栈的字符
     * 如果栈已满，会输出错误信息并返回
     */
    void push(char c)
    {
        if (top_index >= STACK_MAX_SIZE - 1) // 检查栈是否已满
        {
            std::cout << "错误：栈溢出！" << std::endl;
            return;
        }
        data[++top_index] = c; // 先将top_index加1，然后将字符存入新位置
    }

    /**
     * 弹栈操作：移除栈顶元素
     * 如果栈不为空，则将栈顶索引减1
     */
    void pop()
    {
        if (!isEmpty()) // 检查栈是否为空
        {
            top_index--;
        }
    }

    /**
     * 获取栈顶元素：返回栈顶的字符，但不移除它
     * @return 栈顶字符，如果栈为空则返回空字符'\0'
     */
    char top()
    {
        if (isEmpty())
        {
            return '\0';
        }
        return data[top_index];
    }

    /**
     * 检查栈是否为空
     * @return 如果栈为空返回true，否则返回false
     */
    bool isEmpty() const
    {
        return top_index == -1;
    }
};

/**
 * 将字符串转换为双精度浮点数
 * @param numStr 要转换的数字字符串
 * @return 转换后的双精度浮点数值
 */
double stringToDouble(const std::string &numStr)
{
    double result = 0.0;          // 存储最终转换结果
    bool isDecimalPart = false;   // 标记当前是否处理小数部分
    double decimalDivider = 10.0; // 小数部分的除数，用于确定小数位数

    // 遍历字符串中的每个字符
    for (char c : numStr)
    {
        // 如果遇到小数点，标记进入小数部分，并跳过当前字符
        if (c == '.')
        {
            isDecimalPart = true;
            continue;
        }

        int digit = c - '0'; // 将字符转换为对应的数字值
        // 处理整数部分
        if (!isDecimalPart)
        {
            result = result * 10.0 + digit; // 左移一位并加上当前数字
        }
        // 处理小数部分
        else
        {
            result = result + digit / decimalDivider; // 将数字添加到相应的小数位
            decimalDivider *= 10.0;                   // 更新除数，以便处理下一个小数位
        }
    }
    return result; // 返回转换结果
}

int main()
{
    CharStack bracketStack;
    std::string expression;

    std::cout << "请输入一个表达式: ";
    std::getline(std::cin, expression);

    for (int i = 0; i < expression.length(); ++i)
    {
        char currentChar = expression[i];

        if (isdigit(currentChar) || currentChar == '.')
        {
            std::string numberStr;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.'))
            {
                numberStr += expression[i];
                i++;
            }
            i--;

            double value = stringToDouble(numberStr);
            std::cout << "操作数: " << value << std::endl;
        }
        else
        {
            switch (currentChar)
            {
            case '+':
                std::cout << "操作符: 加号" << std::endl;
                break;
            case '-':
                std::cout << "操作符: 减号" << std::endl;
                break;
            case '*':
                std::cout << "操作符: 乘号" << std::endl;
                break;
            case '/':
                std::cout << "操作符: 除号" << std::endl;
                break;
            case '(':
                std::cout << "操作符: 左小括号" << std::endl;
                bracketStack.push(currentChar);
                break;
            case '[':
                std::cout << "操作符: 左中括号" << std::endl;
                bracketStack.push(currentChar);
                break;
            case '{':
                std::cout << "操作符: 左大括号" << std::endl;
                bracketStack.push(currentChar);
                break;
            case ')':
                if (bracketStack.isEmpty() || bracketStack.top() != '(')
                {
                    std::cout << "操作符: 右小括号 匹配错误" << std::endl;
                    return 1;
                }
                bracketStack.pop();
                std::cout << "操作符: 右小括号" << std::endl;
                break;
            case ']':
                if (bracketStack.isEmpty() || bracketStack.top() != '[')
                {
                    std::cout << "操作符: 右中括号 匹配错误" << std::endl;
                    return 1;
                }
                bracketStack.pop();
                std::cout << "操作符: 右中括号" << std::endl;
                break;
            case '}':
                if (bracketStack.isEmpty() || bracketStack.top() != '{')
                {
                    std::cout << "操作符: 右大括号 匹配错误" << std::endl;
                    return 1;
                }
                bracketStack.pop();
                std::cout << "操作符: 右大括号" << std::endl;
                break;
            case ' ':
            case '\t': // 处理制表符(Tab)的情况，不做任何操作直接跳过
                break; // 跳出当前switch-case结构
            default:
                std::cout << "错误: 表达式中包含未知字符 '" << currentChar << "'" << std::endl;
                return 1;
            }
        }
    }

    if (!bracketStack.isEmpty())
    {
        std::cout << "错误: 表达式扫描完成, 但存在未匹配的左括号" << std::endl;
        return 1;
    }

    std::cout << "\n表达式解析完成, 括号匹配正确。" << std::endl;

    return 0;
}