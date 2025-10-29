// ####练习2：阶乘函数

//     - **题目 **：编写一个名为 `factorial` 的函数，它接收一个 `int` 类型的参数 `n`，并返回 `n` 的阶乘($n != 1 \times 2 \times \dots \times n$)。在 `main` 函数中调用它，计算并打印 5\!的值。
//     - **提示 * *：函数内部需要用到循环。

#include <stdio.h>

int factorial(int n);

int main()
{
    int n = 5;
    int result = factorial(n);
    printf("%d 的阶乘是 %d\n", n, result);
    return 0;
}

int factorial(int n)
{
    int ans = 1;
    if (n == 0)
        return 1;
    else
    {
        for (int i = 1; i <= n; i++)
        {
            ans = ans * i;
        }
        return ans;
    }
}