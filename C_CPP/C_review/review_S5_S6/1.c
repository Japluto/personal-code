#include <stdio.h>

// 必须传递 size
void printArray(int arr[], int size) {
    printf("在函数内部，sizeof(arr) = %zu\n", sizeof(arr)); // 会打印 4 或 8
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    int count = sizeof(a) / sizeof(a[0]); // 在 main 中，sizeof(a) = 20
    printArray(a, count); // 必须把 count 传进去
    return 0;
}