// 一个数如果恰好等于它的因子之和，这个数就称为“完数”。例如，6 的因子为1，2，3，而6=1+2+3，并因此6是“完数”。编写程序找出 1000 之内的所有完数，按下面格式输出其因子:
//  6, its factors are 1，2，3
#include <iostream>
using namespace std;
int main()
{
    for (int n = 2; n <= 1000; ++n)
    {
        int sum = 0;
        int factors[100], cnt = 0;
        for (int i = 1; i <= n / 2; ++i)
        {
            if (n % i == 0)
            {
                sum += i;
                factors[cnt++] = i;
            }
        }
        if (sum == n)
        {
            cout << n << ", its factors are ";
            for (int i = 0; i < cnt; ++i)
            {
                cout << factors[i];
                if (i != cnt - 1)
                    cout << ", ";
            }
            cout << endl;
        }
    }
    return 0;
} 