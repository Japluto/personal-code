# C语言复习计划

> 复习规划概览 ——
> 结合大一做的笔记进行复习 先看之前做的ppt上的笔记 
> 然后看网课 这里选择看翁恺[C语言网课]()
> 后续Cpp也是打算看翁恺老师的Cpp来入坑 看这个[网课](https://www.bilibili.com/video/BV1dE41167hJ/?spm_id_from=333.337.search-card.all.click&vd_source=f5a2732f8f252a40c362257617bc6e48)
---
### 一、指针之前的内容复习
- **主要的复习策略就是看PPT过知识点 打代码回复手感这样子**
- **就先这样子把这块学掉加油！！**
- **ppt review 进度表**
   - [x] **第一~三章**  
   - [ ] **第四~八章**
   - [ ] **第九~十一章**

### 二、具体复习内容

-----

### 第二章：变量与计算

程序的核心是处理数据。本章我们学习如何使用变量来存储数据，并对这些数据进行基本的计算。

#### 核心知识点

#### 1\. 变量 (Variable)

  - **定义**：变量是内存中一个有名字的、用来存放数据的空间。
  - **特点**：变量的值在程序运行过程中可以被改变。
  - **声明**：使用变量前必须先声明，指明变量的**类型**和**名称**。
    ```c
    // 声明一个名为 price 的整型变量
    int price;
    // 声明一个名为 weight 的双精度浮点型变量
    double weight;
    ```

#### 2\. 数据类型 (Data Type)

C 语言中常见的基础数据类型有：

  - `int`：**整型**，用于存放整数。例如：`5`, `-10`, `0`。`%d`打印整型
  - `double` / `float`：**浮点型**，用于存放小数。`double` 的精度比 `float` 更高，是更常用的选择。例如：`3.14`, `-0.01`。`%lf`/`%f`打印浮点型
  - `char`：**字符型**，用于存放单个字符。字符需要用单引号 `' '` 括起来。例如：`'A'`, `'c'`, `' '`。`%c`打印单个字符
  - `sizeof()`**一个神奇的运算符**。`sizeof()` 是 C 语言中的一个**运算符 (operator)**，而不是一个函数。这一点很重要，虽然它看起来像个函数。它的作用是在**编译时**计算出它的操作数（一个数据类型或者一个变量）在内存中所占用的空间大小，单位是**字节 (Byte)**。
  所以当你编译`sizeof(char)`，得到的结果便会是整数1（printf时注意对应%d）。
  #### `sizeof()` 在数组上的妙用

`sizeof()` 一个非常实用且重要的应用是计算数组的大小和元素个数。

1.  **获取整个数组占用的总字节数**：`sizeof(array_name)`
2.  **获取数组中一个元素占用的字节数**：`sizeof(array_name[0])`
3.  **计算数组的元素个数**：`总字节数 / 单个元素的字节数`

**实例代码：**

```c
#include <stdio.h>

int main() {
    int scores[] = {100, 98, 85, 90, 77, 88}; // 一个包含6个元素的int数组
    
    // 1. 获取数组总大小
    size_t total_size = sizeof(scores);
    printf("数组 scores 的总大小是: %zu 字节\n", total_size);

    // 2. 获取单个元素的大小
    size_t element_size = sizeof(scores[0]);
    printf("数组 scores 单个元素的大小是: %zu 字节\n", element_size);
    
    // 3. 计算数组元素个数
    size_t num_elements = total_size / element_size;
    printf("数组 scores 的元素个数是: %zu\n", num_elements);
    
    // 在 for 循环中使用这个技巧
    printf("遍历数组 scores:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", scores[i]);
    }
    printf("\n");

    return 0;
}
```

**输出结果：**

```
数组 scores 的总大小是: 24 字节   // 6个元素 * 每个int占4字节
数组 scores 单个元素的大小是: 4 字节 // 第一个元素是int类型
数组 scores 的元素个数是: 6
遍历数组 scores:
100 98 85 90 77 88 
```
#### 3\. 赋值与初始化

  - **赋值 (Assignment)**：使用 `=` 运算符。`=` 的意思是“将右边的值赋给左边的变量”。
    ```c
    int age;
    age = 18; // 赋值
    ```
  - **初始化 (Initialization)**：在声明变量的同时进行赋值。
    ```c
    int age = 18; // 初始化
    double pi = 3.14159;
    ```

#### 4\. 基本算术运算符

  - `+` (加)
  - `-` (减)
  - `*` (乘)
  - `/` (除)
      >- **注意**：两个整数相除，结果会被截断为整数。例如 `5 / 2` 的结果是 `2`。若要得到浮点数结果，至少有一个操作数需要是浮点数，例如 `5.0 / 2` 的结果是 `2.5`。
  - `%` (取余/模)
      - 只用于整数，结果是除法的余数。例如 `10 % 3` 的结果是 `1`。

#### 5\. 常量 (Constant)

对于程序中不希望被改变的值（如圆周率），可以定义为常量。

  - **`const` 关键字**：
    ```c
    const double PI = 3.14159;
    ```
  - **`#define` 预处理指令**：
    ```c
    #define PI 3.14159
    ```

#### 6\. 输入输出函数 (`stdio.h`)

  - **`printf()` (输出)**：向屏幕打印信息。
      - `%d`: 对应 `int`
      - `%lf`: 对应 `double`
      - `%c`: 对应 `char`
      - `%.nf`: 控制浮点数输出，保留 `n` 位小数。例如 `%.2f` 保留两位小数。
      - `\n`: 换行符。
  - **`scanf()` (输入)**：从键盘读取用户输入。
      - **重要**：变量名前面必须加取地址符 `&`。
    <!-- end list -->
    ```c
    int num;
    double val;
    scanf("%d", &num);
    scanf("%lf", &val);
    ```

#### 常用函数补充 (`math.h`)

要使用以下函数，必须在文件开头添加 `#include <math.h>`。

  - `sqrt(x)`: 计算 `x` 的**平方根**。 (参数和返回值为 `double`)
  - `pow(x, y)`: 计算 `x` 的 `y` **次方**。 (参数和返回值为 `double`)
  - `fabs(x)`: 计算浮点数 `x` 的**绝对值**。 (参数和返回值为 `double`)
  - `ceil(x)`: **向上取整**，返回不小于 `x` 的最小整数。 (返回值为 `double`)
  - `floor(x)`: **向下取整**，返回不大于 `x` 的最大整数。 (返回值为 `double`)

### 实例与练习

#### 实例1：两数求和

**题目**：编写一个程序，要求用户输入两个整数，然后计算并输出它们的和。

**代码**：

```c
#include <stdio.h>

int main() {
    // 1. 声明变量
    int a, b, sum;

    // 2. 提示并读取输入
    printf("请输入第一个整数：");
    scanf("%d", &a);

    printf("请输入第二个整数：");
    scanf("%d", &b);

    // 3. 计算和
    sum = a + b;

    // 4. 输出结果
    printf("%d + %d = %d\n", a, b, sum);

    return 0;
}
```

#### 实例2：计算直角三角形的斜边

**题目**：用户输入直角三角形的两条直角边长度，程序计算并输出斜边长度。

**代码**：

```c
#include <stdio.h>
#include <math.h> // 引入数学库

int main() {
    double a, b, c;

    printf("请输入直角边a的长度: ");
    scanf("%lf", &a);

    printf("请输入直角边b的长度: ");
    scanf("%lf", &b);

    // 使用 pow 和 sqrt 函数计算斜边
    c = sqrt(pow(a, 2.0) + pow(b, 2.0));

    printf("斜边长为: %.2f\n", c);

    return 0;
}
```

#### 练习题

#### 练习1：华氏度转摄氏度

  - **题目**：编写一个程序，让用户输入一个华氏温度，程序将其转换为摄氏温度后输出。
  - **公式**：$C = (F - 32) \times \frac{5}{9}$
  - **提示**：
    1.  使用 `double` 类型存储温度。
    2.  为避免整数除法问题，应写成 `5.0 / 9.0`。
    3.  使用 `%.2f` 控制输出结果保留两位小数。

#### 练习2：计算圆的面积和周长

  - **题目**：让用户输入圆的半径，程序计算并输出该圆的面积和周长。
  - **公式**：面积 $A = \pi r^2$ ，周长 $C = 2 \pi r$。
  - **提示**：
    1.  使用 `const double PI = 3.14159;` 定义一个常量 $\pi$。
    2.  使用 `pow(r, 2.0)` 计算半径的平方。

-----  


### 第三章：判断与循环

程序的核心是决策与重复。本章我们学习如何使用判断与循环语句来控制程序的执行流程，让程序变得“智能”。

#### 核心知识点

#### 1\. 判断语句 (If-else) 与相关运算符

  - **定义**：判断语句允许程序根据一个或多个条件的真假，来选择性地执行不同的代码块。
  - **条件真假**：在 C 语言中，`0` 代表 **假 (False)**，所有 **非 `0`** 的值都代表 **真 (True)**。
  - **关系运算符**：用于比较两个值，构成条件。
      - `>` (大于), `<` (小于), `>=` (大于等于), `<=` (小于等于)
      - `==` (等于), `!=` (不等于)
  - **逻辑运算符**：用于连接多个条件。
      - `&&` (与), `||` (或), `!` (非)

**`if-else` 的三种基本形式**：

```c
// 形式一：单分支
if (condition) {
    // ...
}

// 形式二：双分支
if (condition) {
    // ...
} else {
    // ...
}

// 形式三：多分支
if (condition1) {
    // ...
} else if (condition2) {
    // ...
} else {
    // ...
}
```

#### 2\. 循环语句 (Loop)

循环语句使得一段代码可以被重复执行多次。

  - `while` 循环：**前测试循环**。先判断条件，再执行循环体。循环体可能一次都不执行。
    ```c
    while (condition) {
        // 循环体
    }
    ```
  - `do-while` 循环：**后测试循环**。先执行一次循环体，再判断条件。循环体**至少执行一次**。
    ```c
    do {
        // 循环体
    } while (condition); // 注意有分号
    ```
  - `for` 循环：结构最紧凑的循环，将**初始化、条件、更新**三要素集于一体，特别适合**已知循环次数**的场景。
    ```c
    for (initialization; condition; update) {
        // 循环体
    }
    ```

#### `break` 与 `continue` 的妙用

`break` 和 `continue` 是循环内部的流程控制器。

1.  **`break`**：**立即终止并跳出**整个循环。
2.  **`continue`**：**跳过本次循环的剩余部分**，直接开始下一次循环。

**实例代码：**

```c
#include <stdio.h>

int main() {
    printf("break 与 continue 示例:\n");
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            // 如果 i 是偶数，跳过本次循环的 printf
            continue;
        }
        if (i > 7) {
            // 如果 i 超过 7，直接终止循环
            break;
        }
        printf("%d ", i); // 只会打印 1, 3, 5, 7
    }
    printf("\n循环结束。\n");
    return 0;
}
```

**输出结果：**

```
break 与 continue 示例:
1 3 5 7 
循环结束。
```

### 实例与练习

#### 实例1：判断奇偶数

**题目**：编写一个程序，要求用户输入一个整数，然后判断它是奇数还是偶数。

**代码**：

```c
#include <stdio.h>

int main() {
    int number;

    printf("请输入一个整数：");
    scanf("%d", &number);

    // 使用取模运算符判断
    if (number % 2 == 0) {
        printf("%d 是一个偶数。\n", number);
    } else {
        printf("%d 是一个奇数。\n", number);
    }

    return 0;
}
```

#### 实例2：用 for 循环计算1到100的和

**题目**：计算 $1 + 2 + 3 + \\dots + 100$ 的总和。

**代码**：

```c
#include <stdio.h>

int main() {
    int sum = 0;
    
    // 使用 for 循环，i 从 1 增加到 100
    for (int i = 1; i <= 100; i++) {
        sum += i; // 累加
    }

    printf("1到100的总和是: %d\n", sum);

    return 0;
}
```

#### 练习题

#### 练习1：闰年判断

  - **题目**：编写一个程序，让用户输入一个年份，程序判断该年份是否是闰年。
  - **规则**：年份 `year` 满足以下条件之一即为闰年：
    1.  `year` 能被 4 整除，但不能被 100 整除。
    2.  `year` 能被 400 整除。
  - **提示**：
    1.  这是一个绝佳的练习 `if-else` 和逻辑运算符 `&&` 与 `||` 的机会。
    2.  对应的逻辑表达式为 `(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)`。

#### 练习2：打印九九乘法表

  - **题目**：在屏幕上工整地打印出九九乘法表。
  - **格式**：
    ```
    1*1=1
    1*2=2  2*2=4
    ...
    ```
  - **提示**：
    1.  使用**嵌套循环**。外层循环变量 `i` 控制行，内层循环变量 `j` 控制列。
    2.  内层循环的结束条件依赖于外层循环的变量 (`j <= i`)。
    3.  使用 `printf` 的格式控制（如 `%-7s`）可以使输出对齐，更加美观。

-----

### 第四章：函数与工程结构

到目前为止，我们所有的代码都写在 `main` 函数里。随着程序逻辑变复杂，`main` 函数会变得异常臃肿且难以维护。**函数 (Function)** 是我们组织代码、降低复杂度的核心工具。本章我们将从函数的基础用法，一路学习到如何构建一个专业的多文件 C 语言工程。

#### 核心知识点

#### 1\. 函数 (Function) 基础

  - **定义**：函数是一段封装了特定功能的、可被命名的代码块。它就像一个“工人”，你可以给他一些原材料（参数），他会返回给你一个成品（返回值）。
  - **优势**：
    1.  **模块化 (Modularity)**：将大程序拆分成一个个功能独立的小模块。
    2.  **代码复用 (Reusability)**：同一段逻辑可以在程序的不同地方被反复调用。
    3.  **可维护性 (Maintainability)**：修改或调试一个功能时，只需关注对应的函数。

#### 2\. 函数的定义、调用与声明

  - **函数定义**：定义一个函数，你需要明确三件事：它需要什么（参数），它返回什么（返回值），以及它做什么（函数体）。

    ```c
    /*
     * 返回类型  函数名(参数列表)
     * vvvvvv   vvv vvvvvvvvvv
     */
        int      sum (int a, int b) 
    { // 函数体开始
        int result = a + b;
        return result; // return 语句返回一个值
    } // 函数体结束
    ```

    >   - **`void` 返回类型**：如果函数不返回任何值（例如只是打印信息），使用 `void`。

  - **函数调用**：定义好后，就可以在 `main` 函数或其他函数中调用它。

    ```c
    int main() {
        int total = sum(10, 20); // 调用 sum 函数，用 10 和 20 作为实际参数
        printf("The sum is %d\n", total);
        return 0;
    }
    ```

  - **函数声明 (Prototype)**：C 语言编译器是自上而下读取的。如果你在 `main` 函数里调用了一个在它**下面**才被定义的函数，编译器会报错。

    >   - **解决方案**：在 `main` 函数之前，提供一个**函数声明（也叫函数原型）**。

    ```c
    #include <stdio.h>

    // 1. 函数声明 (Prototype)
    // 告诉编译器，后面会有一个长这样的函数，你先记一下
    int sum(int a, int b);

    // 2. 主函数
    int main() {
        int total = sum(10, 20); // 编译器认识 sum 了
        return 0;
    }

    // 3. 函数定义
    // 放在 main 后面也没关系了
    int sum(int a, int b) {
        return a + b;
    }
    ```

#### 3\. 变量的作用域

  - **局部变量 (Local Variables)**：在函数内部（包括参数）定义的变量。只在它所在的 `{}` 内部有效。
  - **全局变量 (Global Variables)**：在所有函数外部定义的变量。应**谨慎使用**，它会破坏函数的独立性（模块化）。

#### 4\. 多文件编程 (工程结构)

  - **定义**：当项目变大，我们会把不同功能的函数拆分到不同的文件中，这就是多文件编程。一个模块通常由 `.h` (接口) 和 `.c` (实现) 两个文件组成。
  - **`.h` 头文件 (Header File) - “公开的菜单”**
    1.  **作用**：告诉其他文件“我这里提供了什么功能”。
    2.  **包含内容**：**函数声明 (原型)**、宏定义、结构体定义。
    3.  **`#ifndef` 头文件保护**：一个标准模板，用于防止同一个头文件被重复包含。
        ```c
        // student.h
        #ifndef STUDENT_H   // If Not Defined
        #define STUDENT_H

        // ... 所有声明放这里 ...
        void print_student_info(const Student* s);

        #endif // STUDENT_H
        ```
  - **`.c` 源文件 (Source File) - “私有的厨房”**
    1.  **作用**：函数功能的**具体实现**。
    2.  **包含内容**：**函数定义 (实现)**。
    3.  **规则**：它必须 `#include` 自己的头文件，以便编译器检查“声明”和“定义”是否一致。
        ```c
        // student.c
        #include "student.h" // 包含自己的头文件

        void print_student_info(const Student* s) {
            // ... 具体实现代码 ...
        }
        ```
    4.  **`#include "..."` vs `#include <...>`**：`""` (双引号) 优先在**当前项目目录**下查找（用于包含自己的 `.h` 文件）；`<>` (尖括号) 只在**系统标准库目录**下查找（用于包含 `stdio.h` 等）。
  - **`main.c` (或调用方) - “顾客”**
    1.  **作用**：使用其他模块提供的功能。
    2.  **规则**：它只需要 `#include` 它想用的模块的 `.h` (菜单) 文件。
        ```c
        // main.c
        #include "student.h"  // 我要用学生模块

        int main() {
            // ...
            print_student_info(&alice);
            return 0;
        }
        ```

#### 5\. 目录结构 (扁平 vs 分层)

  - **扁平结构**：所有 `.c` 和 `.h` 都在一个文件夹。适合小型练习。
  - **分层结构 (推荐)**：使用 `src` 和 `include` 文件夹分离接口和实现，是专业项目的标准做法。
    ```
    my_project/
    ├── include/           <-- 存放所有 .h 文件
    ├── src/               <-- 存放所有 .c 文件
    └── Makefile           <-- (自动化编译脚本)
    ```

#### 6\. 编译、链接与 `Makefile`

  - **编译 (Compilation)**：`gcc -c` 命令。将 `.c` 源文件（代码）翻译成 `.o` 目标文件（机器码）。

  - **链接 (Linking)**：`gcc ... .o` 命令。将所有 `.o` 文件“粘合”在一起，生成最终的 `.exe` 可执行文件。

    >   - **链接错误 `(undefined reference to ...)`**：只编译 `main.c` 会 100% 导致此错误，因为链接器在 `.o` 文件中找不到 `sum` 等函数的具体实现。

  - **`Makefile` 自动化构建**：`make` 是一个自动化工具（“厨师”），`Makefile` 是它的“食谱”。

    >   - **核心优势**：**增量编译**。它只重新编译你修改过的文件，极大节省时间。

    ```makefile
    # Makefile (专业模板)

    # --- 1. 变量定义 ---
    CC = gcc
    # -Iinclude: 告诉 gcc 去 include 文件夹找头文件
    CFLAGS = -Wall -g -Iinclude
    TARGET = student_manager
    SRCS = $(wildcard src/*.c)
    OBJS = $(SRCS:src/%.c=%.o)

    # --- 2. 规则定义 ---

    # 默认规则
    all: $(TARGET)

    # 链接规则：(注意：命令前必须是 Tab 键!)
    $(TARGET): $(OBJS)
        $(CC) $(OBJS) -o $(TARGET)

    # 编译规则：(注意：命令前必须是 Tab 键!)
    # $< 代表依赖 (src/%.c), $@ 代表目标 (%.o)
    %.o: src/%.c
        $(CC) $(CFLAGS) -c $< -o $@

    # 清理规则
    .PHONY: clean
    clean:
        rm -f $(TARGET) *.o
    ```

  - **使用方法**：

    1.  `make`：自动（增量）编译项目。
    2.  `make clean`：删除所有生成的文件。

#### 7\. Windows 环境常见陷阱

  - **`make : 无法将“make”项识别为...`**
    1.  **原因**：PowerShell 终端找不到 `make.exe` 程序。
    2.  **解决方案**：找到 `gcc.exe` 所在 `bin` 文件夹里的 `mingw32-make.exe`，复制一份并重命名为 `make.exe`。
  - **中文乱码 (`Error 2`, 运行 `.exe` 乱码)**
    1.  **原因**：`gcc/make`、VS Code、Windows 终端三者编码不统一。
    2.  **推荐方案**：
          - (1) 保持所有文件为 **UTF-8** 编码。
          - (2) 在 `main.c` 开头加入 `#include <windows.h>` 和 `SetConsoleOutputCP(CP_UTF8);`。
          - (3) 运行 `.exe` 前，在终端执行 `chcp 65001`。
    3.  **备选 GBK 方案**：
          - (1) 将**所有**文件（包括 `Makefile`）都用 "通过编码保存" 存为 **GBK**。
          - (2) 在 `Makefile` 的 `CFLAGS` 中加入 `-finput-charset=GBK -fexec-charset=GBK`。
          - (3) 终端**什么都不要做**，保持默认 GBK 模式。

### 实例与练习

#### 练习题

#### 练习1：最大值函数

  - **题目**：编写一个名为 `max` 的函数，它接收两个 `int` 类型的参数，并返回其中较大的一个。在 `main` 函数中调用它并打印结果。

#### 练习2：阶乘函数

  - **题目**：编写一个名为 `factorial` 的函数，它接收一个 `int` 类型的参数 `n`，并返回 `n` 的阶乘 ($n! = 1 \times 2 \times \dots \times n$)。在 `main` 函数中调用它，计算并打印 5\! 的值。
  - **提示**：函数内部需要用到循环。

#### 练习3：质数判断函数

  - **题目**：编写一个名为 `isPrime` 的函数，它接收一个 `int` 类型的参数 `num`。如果 `num` 是质数，函数返回 `1`；否则返回 `0`。（质数是只能被 1 和它自身整除的大于 1 的自然数）。
  - **提示**：函数内部需要用循环从 2 遍历到 `sqrt(num)`（需要 `math.h`）来检查是否存在因子。


-----

### 第五章：数组 (Array)

程序需要处理大量的数据。本章我们学习如何使用数组（Array）这一结构，来批量存储和管理**相同类型**的数据，并进一步学习如何使用指针在“堆”上创建可变大小的动态数组。

#### 核心知识点

#### 1\. 数组的定义与初始化

  - **定义**：数组是内存中一片**连续**的、用来存放**多个同类型**数据的空间。
  - **声明**：`数据类型 数组名[数组大小];`
    >   - `数组大小` 必须是一个**常量表达式**（在 C99 标准之前，现在一些编译器支持变量，但不推荐）。
    ```c
    // 声明一个能存放 10 个 int 类型数据的数组
    int scores[10];
    ```
  - **初始化**：在声明的同时进行赋值。
    ```c
    // 完整初始化
    int a[5] = {1, 2, 3, 4, 5};

    // 部分初始化（推荐）
    // 只初始化前几个，其余元素会自动被编译器设置为 0
    int b[10] = {1, 2}; // b[0]=1, b[1]=2, b[2]~b[9] 均为 0

    // 自动计算大小
    // 编译器会根据你提供的元素个数自动设置数组大小（[3]）
    int c[] = {5, 6, 7};
    ```

#### 2\. 数组的访问 (索引)

  - **索引 (Index)**：通过索引（也叫“下标”）来访问数组中的特定元素。
  - **规则**：`数组名[索引]`
  - **重要**：数组的索引**从 0 开始**。
      - 对于一个大小为 `n` 的数组 `arr`：
          - 第一个元素是 `arr[0]`
          - 最后一个元素是 `arr[n-1]`
  - **数组与循环**：`for` 循环是访问数组的“天作之合”。
    ```c
    int arr[5] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        printf("索引 %d 的值是: %d\n", i, arr[i]);
    }
    ```
  - **数组越界**：访问 `arr[5]` 或 `arr[-1]` 是**非法**的。C 语言**不会**检查这个错误，但在运行时会导致程序崩溃或产生无法预料的后果（即“缓冲区溢出”），这是 C 最常见的 Bug 之一。

#### 3\. 数组作为函数参数

  - **关键概念**：当你把一个数组传递给一个函数时，你传递的**不是**整个数组的副本，而是数组的**起始地址**（即指向第一个元素的指针）。
  - **`sizeof` 陷阱**：
      - 正因为传递的是地址，在**函数内部**使用 `sizeof(arr)` 得到的是一个**指针的大小**（比如 4 或 8 字节），**而不是**整个数组的总大小！
      - **铁律**：因此，在将数组传递给函数时，**必须**额外传递一个 `int size` 参数来告知函数该数组的实际大小。
    <!-- end list -->
    ```c
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
    ```

#### 4\. 字符串 (C-style Strings) - 基础

  - **定义**：字符串在 C 语言中是一种特殊的数组，它是**以 `\0` (空字符) 结尾的 `char` 数组**。
  - **`\0` (Null Terminator)**：这是 C 语言字符串的“结束标记”。所有处理字符串的标准库函数（如 `printf("%s")`, `strlen`）都是靠这个标记来确定字符串在哪里结束的。
  - **初始化**：
    ```c
    char str1[] = "hello"; // 内存中为 {'h', 'e', 'l', 'l', 'o', '\0'}，大小为 6
    char str2[] = {'h', 'e', 'l', 'l', 'o', '\0'}; // 等价，但不推荐
    ```
  - **`sizeof` vs `strlen`**：
      - `sizeof(str1)`：获取数组在内存中占用的**总字节数**（包括 `\0`），结果是 6。
      - `strlen(str1)`：(需要 `#include <string.h>`) 获取字符串的**实际字符长度**（不包括 `\0`），结果是 5。
  - **安全输入 `fgets`**：
      - **永远不要**使用 `scanf("%s", ...)`，它不检查数组边界，极易导致缓冲区溢出。
      - **推荐使用** `fgets(char* str, int size, FILE* stream)`。
    <!-- end list -->
    ```c
    char name[15];
    printf("请输入你的名字 (最多14个字符): ");

    // 安全地读取一行，最多读取 15 个字节
    fgets(name, 15, stdin); 

    // fgets 会连换行符 '\n' 一起读入，通常需要手动移除
    name[strcspn(name, "\n")] = '\0'; // 移除换行符的技巧
    ```

#### 5\. 字符串 (C-style Strings) - 常用函数 (string.h)

  - **`strcpy(dest, src)`**：**复制**字符串（不安全）。

  - **`strncpy(dest, src, n)`**：**安全复制**，最多复制 `n` 个字符。

    >   - **注意**：如果 `src` 长度大于 `n`，`strncpy` **不会**自动添加 `\0`。必须手动添加：`dest[n-1] = '\0'` (如果 `dest` 大小为 `n`)。

  - **`strcat(dest, src)`**：**拼接**字符串（不安全）。

  - **`strncat(dest, src, n)`**：**安全拼接**，最多追加 `n` 个字符，并且**总会**添加 `\0`。

  - **`strcmp(s1, s2)`**：**比较**字符串。

    >   - **返回值**：`== 0` (相等), `< 0` (s1 \< s2), `> 0` (s1 \> s2)。
    >   - **注意**：绝不能用 `if (s1 == s2)` 来比较字符串内容。

  - **`strchr(str, c)`**：**查找字符** `c` 在 `str` 中**首次**出现的位置，返回指针或 `NULL`。

  - **`strrchr(str, c)`**：**查找字符** `c` 在 `str` 中**最后一次**出现的位置。

  - **`strstr(haystack, needle)`**：**查找子字符串** `needle` 在 `haystack` 中**首次**出现的位置。

  - **`strtok(str, delim)`**：**分割**字符串。

    >   - **注意**：这是一个特殊的函数，它会**修改**原字符串。第一次调用 `strtok(str, ",")`，后续调用 `strtok(NULL, ",")`。

#### 6\. 多维数组

  - **定义**：即“数组的数组”，最常见的是二维数组，可以用来模拟矩阵或表格。

  - **声明**：`数据类型 数组名[行数][列数];`

  - **内存布局 (重要)**：C 语言的多维数组在内存中**仍然是连续的**，按“**行主序 (Row-Major Order)**”存储。

    >   - `int m[2][3] = { {1, 2, 3}, {4, 5, 6} };`
    >   - 它在内存中的实际布局是：`| 1 | 2 | 3 | 4 | 5 | 6 |`
    >   - `m[0]` 是一个包含 `{1, 2, 3}` 的数组，`m[1]` 是一个包含 `{4, 5, 6}` 的数组。

  - **作为函数参数**：传递二维数组时，**必须**指定**除第一维（行数）之外**的所有维度的大小（例如 `列数`）。

    ```c
    // 列数 3 必须被指定
    void printMatrix(int m[][3], int rows) {
        // 编译器需要知道列数 3，这样当它计算 m[i] (即 m + i) 时，
        // 它才知道要跳过 i * (3 * sizeof(int)) 个字节。
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d ", m[i][j]);
            }
            printf("\n");
        }
    }
    ```

#### 7\. 进阶：动态数组 (stdlib.h)

  - **定义**：C 语言的普通数组 `int arr[10]` 大小在编译时固定。“动态数组”是我们利用指针，在\*\*“堆” (Heap)**（一块自由的内存池）上**手动申请**和**管理**内存，从而实现在运行时**可变大小\*\*的数组。
  - **核心函数 (`stdlib.h`)**：
    1.  **`void* malloc(size_t size)`**：**分配内存**。向系统申请 `size` **字节**的连续内存。

        >   - `size` 通常用 `数量 * sizeof(类型)` 来计算。
        >   - **用法**：`int* arr = (int*) malloc(10 * sizeof(int));`
        >   - 返回 `void*` 通用指针，需要**强制类型转换**（如 `(int*)`）。
        >   - 如果分配失败（内存不足），返回 `NULL`。**必须检查 `NULL`**。

    2.  **`void free(void* ptr)`**：**释放内存**。

        >   - `malloc` 申请的内存**必须**通过 `free` 手动归还给系统，否则会造成**内存泄漏 (Memory Leak)**。
        >   - **规则**：`free` 过的指针**不要**再次使用（悬垂指针）。

    3.  **`void* realloc(void* ptr, size_t new_size)`**：**重新分配内存**（实现“扩容”）。

        >   - 接收一个**之前 `malloc` 过的指针 `ptr`**，并尝试将其内存块调整为 `new_size`。
        >   - 它会自动处理数据的**复制**和旧内存的**释放**。
        >   - **用法**：`int* new_arr = (int*) realloc(arr, 20 * sizeof(int));`
        >   - **注意**：`realloc` 可能会返回一个**新的内存地址**，所以**必须**用一个新指针变量来接收，并更新旧指针。

### 实例与练习

#### 实例1：计算数组平均值

**题目**：编写一个函数，计算一个 `double` 数组中所有元素的平均值。

**代码**：

```c
#include <stdio.h>

double getAverage(double arr[], int size) {
    if (size <= 0) return 0.0;
    
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

int main() {
    double scores[] = {88.5, 92.0, 76.5, 95.0, 83.0};
    int count = sizeof(scores) / sizeof(scores[0]);
    double avg = getAverage(scores, count);
    printf("平均成绩是: %.2f\n", avg);
    return 0;
}
```

#### 实例2：字符串反转

**题目**：编写一个函数，接收一个字符串作为参数，并将该字符串原地反转。

**代码**：

```c
#include <stdio.h>
#include <string.h> // 需要 strlen

void reverseString(char str[]) {
    int len = strlen(str);
    int left = 0;
    int right = len - 1;
    
    while (left < right) {
        // 交换左右两边的字符
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

int main() {
    char myString[] = "hello";
    printf("原始字符串: %s\n", myString);
    reverseString(myString);
    printf("反转后字符串: %s\n", myString);
    return 0;
}
```

#### 实例3：动态数组实现（Append功能）

**题目**：使用 `malloc` 和 `realloc` 实现一个可以自动扩容的动态数组。

**代码**：

```c
#include <stdio.h>
#include <stdlib.h> // for malloc, realloc, free

// 为了方便管理，我们把动态数组的元数据打包成一个结构体
typedef struct {
    int* data;     // 指向堆内存的指针
    int size;      // 当前已用元素个数
    int capacity;  // 当前已申请的总容量
} DynamicArray;

// 初始化
void init_array(DynamicArray* arr, int initial_capacity) {
    arr->data = (int*) malloc(initial_capacity * sizeof(int));
    if (arr->data == NULL) exit(1); // 内存分配失败，退出
    arr->size = 0;
    arr->capacity = initial_capacity;
}

// 向数组末尾添加元素 (核心逻辑)
void append(DynamicArray* arr, int value) {
    // 检查是否已满，如果已满则扩容
    if (arr->size == arr->capacity) {
        int new_capacity = arr->capacity * 2; // 容量翻倍
        int* new_data = (int*) realloc(arr->data, new_capacity * sizeof(int));
        
        if (new_data == NULL) {
             printf("内存扩容失败！\n");
             return;
        }
        
        // 更新指针和容量
        arr->data = new_data;
        arr->capacity = new_capacity;
    }
    
    // 添加新元素
    arr->data[arr->size] = value;
    arr->size++;
}

// 释放内存
void free_array(DynamicArray* arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

int main() {
    DynamicArray my_arr;
    init_array(&my_arr, 2); // 初始容量为 2
    
    append(&my_arr, 10);
    append(&my_arr, 20);
    printf("当前大小: %d, 容量: %d\n", my_arr.size, my_arr.capacity);
    
    append(&my_arr, 30); // 此时会触发扩容
    printf("扩容后大小: %d, 容量: %d\n", my_arr.size, my_arr.capacity);
    
    printf("数组内容: ");
    for (int i = 0; i < my_arr.size; i++) {
        printf("%d ", my_arr.data[i]);
    }
    printf("\n");
    
    free_array(&my_arr); // 必须释放
    return 0;
}
```

#### 练习题

#### 练习1：查找数组中的最大值

  - **题目**：编写一个函数 `findMax`，接收一个 `int` 数组和它的大小，返回该数组中的最大值。在 `main` 函数中测试它。

#### 练习2：统计单词中的元音字母

  - **题目**：编写一个程序，让用户输入一个单词（字符串），程序统计并输出该单词中元音字母（a, e, i, o, u，不区分大小写）的个数。
  - **提示**：使用 `fgets` 安全读入。使用 `for` 循环遍历 `char` 数组，直到遇到 `\0`。使用 `if` 或 `switch` 检查每个字符。

#### 练习3：矩阵转置（选做）

  - **题目**：定义一个 3x4 的二维数组（矩阵）并初始化。编写一个函数，将这个 3x4 的矩阵转置为一个 4x3 的矩阵并打印出来。
  - **提示**：转置即将原矩阵的 `m[i][j]` 元素放到新矩阵的 `new_m[j][i]` 位置。

-----