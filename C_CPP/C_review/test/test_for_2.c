#include <stdio.h>

int main()
{
    double a = 1.22222;
    printf("a = %le\n", a);
    printf("char  %d\n", sizeof(char));
    printf("short %d\n", sizeof(short));
    printf("int   %d\n", sizeof(int));
    printf("long  %d\n", sizeof(long));
    printf("float %d\n", sizeof(float));
    printf("double %d\n", sizeof(double));

    double num = 12.341;

    printf("原始输出:|%.2f|\n", num); // 输出 12.35
    printf("宽度为3:|%9.2f|\n", num); // 总共占10个字符位，右对齐

    return 0;
}