// 输入两个正整数 m和n，求其最大公约数和最小公倍数
#include <iostream>
using namespace std;
int main()
{
    int m, n;
    cout << "请输入两个正整数：";
    cin >> m >> n;
    int a = m, b = n;
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    int gcd = a;             // 最大公约数
    int lcm = (m * n) / gcd; // 最小公倍数
    cout << "最大公约数为：" << gcd << endl;
    cout << "最小公倍数为：" << lcm << endl;
    return 0;
}