// 输入一行字符，分别统计出其中英文字母、空格、数字和其他字符的个数
#include <iostream>
using namespace std;

int main()
{
    char ch;
    int letter = 0, space = 0, digit = 0, other = 0;
    cout << "请输入一行字符，以换行键结束：" << endl;
    while ((ch = cin.get()) != '\n') // 逐字符读入，直到遇到换行符为止
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            letter++;
        else if (ch == ' ')
            space++;
        else if (ch >= '0' && ch <= '9')
            digit++;
        else
            other++;
    }
    // 输出统计结果
    cout << "英文字母个数：" << letter << endl;
    cout << "空格个数：" << space << endl;
    cout << "数字个数：" << digit << endl;
    cout << "其他字符个数：" << other << endl;
    return 0;
}