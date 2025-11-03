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
### 第六章：指针 (Pointers)

本章我们将学习 C 语言的“终极武器”——指针。指针使得 C 语言能够高效地操作内存、灵活地处理数据结构、在函数间传递复杂信息。理解指针是 C 语言从“入门”到“精通”的**分水岭**。

#### 核心知识点

#### 1\. 到底什么是“指针”？

  - **内存与地址**：
      - 想象一下，你电脑的内存是一条非常长的街道（比如几亿个房屋连在一起）。
      - 每个房屋（内存单元，通常是一个字节）都有一个**唯一的门牌号**，这个门牌号就是**内存地址 (Address)**。
  - **变量**：当你声明 `int a = 10;` 时，操作系统会在“街道”上找一块空地（比如 4 个连续的房屋），把 `10` 这个值存进去，并把这块地的起始门牌号（比如 `4000`）和变量名 `a` 关联起来。
  - **指针 (Pointer)**：
      - 指针**本身也是一个变量**。
      - 它的特殊之处在于，它里面**存储的不是普通的值**（像 `10` 或 `3.14`），而是**另一个变量的“门牌号”（内存地址）**。
  - **比喻**：
      - `int a = 10;` 是一个“**保险箱**”，里面装着“黄金”（值 `10`）。
      - `int* p;` 是一个“**小纸条**”，这个纸条被设计用来**专门存放**保险箱的“**地址**”。

#### 2\. 指针的声明与操作符

  - **(1) 声明指针变量**：

      - `数据类型* 指针名;`
      - `*` (星号) 在这里是一个**类型说明符**，表示“我是一个指针”。
      - `数据类型` 表示这个指针**指向**的是哪种类型的数据。

    <!-- end list -->

    ```c
    int* p_int;   // p_int 是一个指针，它被设计用来指向一个 int 类型的变量
    double* p_db; // p_db 是一个指针，它被设计用来指向一个 double 类型的变量
    char* p_char; // p_char 是一个指针，它被设计用来指向一个 char 类型的变量
    ```

  - **(2) 取地址运算符 `&` (Address-of)**

      - **作用**：获取一个普通变量的“门牌号”（内存地址）。
      - **用法**：`&变量名`

    <!-- end list -->

    ```c
    int a = 10;
    // &a 的结果就是变量 a 在内存中的起始地址 (比如 4000)
    ```

  - **(3) 解引用运算符 `*` (Dereference)**

      - **作用**：当你手里拿着一个“地址”（指针）时，使用 `*` 运算符可以**顺着这个地址**找到那个“保险箱”，并**取出/操作**里面的东西。
      - **用法**：`*指针名`
      - `*` (星号) 在这里是一个**操作符**，意思是“**访问...地址上的值**”。

#### 3\. 指针的完整使用周期

我们将上面三个概念串联起来：

```c
#include <stdio.h>

int main() {
    // 1. 定义一个普通变量 "保险箱"
    int a = 10;
    
    // 2. 定义一个指针变量 "小纸条"
    int* p;
    
    // 3. 将 a 的地址（门牌号）写入 "小纸条" p
    //    &a: 取出 a 的地址
    //    p = ...: 将这个地址存入 p 变量中
    p = &a;
    
    // 此时，我们说 "p 指向 a"
    
    // 4. 打印信息
    // %p 是专门用来打印地址（指针）的格式控制符
    printf("变量 a 的值是: %d\n", a);
    printf("变量 a 的地址是: %p\n", &a);
    printf("指针 p 里面存的值是: %p\n", p); // p 的值 和 &a 的值完全相同
    
    // 5. 使用解引用 * (最关键的一步)
    // *p: “访问 p 所存地址 (即 &a) 上的那个值”
    printf("通过指针 p 访问到的值是: %d\n", *p); // 输出 10
    
    // 6. 通过指针修改原变量的值
    *p = 25; // “将 25 放入 p 所存地址上的那个保险箱里”
             // 这等价于 a = 25;
             
    printf("修改后，变量 a 的值变成了: %d\n", a); // 输出 25
    
    return 0;
}
```

**输出示例 (地址值会变化)：**

```
变量 a 的值是: 10
变量 a 的地址是: 0x7ffee5d408ac
指针 p 里面存的值是: 0x7ffee5d408ac
通过指针 p 访问到的值是: 10
修改后，变量 a 的值变成了: 25
```

#### 4\. 指针与数组 (天生一对)

  - **核心规则**：在 C 语言中，当一个**数组名**（例如 `arr`）在大多数表达式中使用时，它会自动“退化”成一个**指向其第一个元素（`&arr[0]`）的指针**。
  - **这意味着**：
    ```c
    int arr[5] = {10, 20, 30, 40, 50};
    int* p;

    // 这两行代码是等价的：
    p = arr;
    p = &arr[0];

    // 因此，你可以像使用数组一样使用指针：
    printf("第二个元素是: %d\n", p[1]); // 输出 20

    // 你也可以像使用指针一样使用数组（指针算术）：
    // arr[1] 等价于 *(arr + 1)
    // p[1]   等价于 *(p + 1)
    printf("第三个元素是: %d\n", *(p + 2)); // 输出 30
    ```
  - **指针算术 (Pointer Arithmetic)**：
      - `p + 1` **不是**地址值简单加 1。
      - `p` 是一个 `int*` 指针，`p + 1` 的意思是“**跳过一个 `int` 的大小**”（比如跳过 4 字节），移动到**下一个元素**的地址。
      - 这就是为什么 `for` 循环可以通过 `p++` 来遍历数组。

#### 5\. 指针与函数 (重要应用)

我们终于可以真正理解为什么 `scanf` 需要 `&`，以及为什么数组传参那么奇怪了。

  - **(1) C 语言的“值传递”**
      - 默认情况下，C 语言函数参数都是**值传递 (Pass-by-Value)**。这意味着函数**复制**了你传入的参数，在函数内部修改这个副本，**不会**影响到 `main` 函数中的原始变量。
    <!-- end list -->
    ```c
    void tryToChange(int x) {
        x = 100; // 只修改了副本 x
    }
    int main() {
        int a = 10;
        tryToChange(a);
        // a 在这里仍然是 10！
    }
    ```
  - **(2) 利用指针实现“引用传递”**
      - 如果我们想让函数**能修改** `main` 函数中的变量，我们必须**把那个变量的地址 `&a`** 传递过去。
      - 这就是 `scanf` 的原理！
    <!-- end list -->
    ```c
    // 函数接收一个 "int 的地址" (即 int* 指针)
    void reallyChange(int* p) {
        *p = 100; // *p: 访问 p 所存地址上的那个值，并修改它
    }
    int main() {
        int a = 10;
        printf("a 的原始值: %d\n", a);
        
        reallyChange(&a); // 我们把 a 的“地址”传进去
        
        printf("a 修改后的值: %d\n", a); // a 真的变成了 100
    }
    ```
  - **(3) 数组参数的真相**
      - `void printArray(int arr[], int size)`
      - 在函数参数中，`int arr[]` 这种写法只是一个“语法糖”，编译器会自动将其理解为 `int* arr`。
      - 这就是为什么数组在函数内部 `sizeof` 会失效（因为它就是一个指针），也解释了为什么在函数内部修改 `arr[i]` 会**真的修改** `main` 函数中的原始数组（因为你操作的是同一个地址）。

#### 6\. `NULL` 指针

  - **定义**：一个特殊的指针常量，它代表“**不指向任何地方**”的地址（通常是地址 0）。
  - **用途**：
    1.  初始化指针：`int* p = NULL;` 是一个好习惯，防止“野指针”（指向随机内存）。
    2.  作为“哨兵”：`malloc` 或 `strstr` 这类函数在失败时会返回 `NULL`，我们可以通过检查 `if (p == NULL)` 来判断操作是否成功。

### 实例与练习

#### 实例1：交换两个变量的值

**题目**：编写一个 `swap` 函数，它能交换 `main` 函数中两个 `int` 变量的值。

**代码**：

```c
#include <stdio.h>

// 必须接收指针，否则无法修改 main 中的原变量
void swap(int* p_a, int* p_b) {
    int temp = *p_a;  // temp = a 的值
    *p_a = *p_b;      // a = b 的值
    *p_b = temp;      // b = temp 的值
}

int main() {
    int a = 10;
    int b = 20;
    
    printf("交换前: a = %d, b = %d\n", a, b);
    
    // 传递 a 和 b 的地址
    swap(&a, &b);
    
    printf("交换后: a = %d, b = %d\n", a, b);
    
    return 0;
}
```

#### 实例2：使用指针遍历数组

**题目**：使用指针算术（`p++` 和 `*p`）代替数组索引（`arr[i]`）来遍历并打印一个数组。

**代码**：

```c
#include <stdio.h>

int main() {
    int arr[] = {11, 22, 33, 44, 55};
    int count = sizeof(arr) / sizeof(arr[0]);
    
    int* p = arr; // p 指向 arr[0]
    
    printf("使用指针算术遍历: \n");
    
    // p < (arr + count) 的意思是：
    // p 指针是否还没有越过数组的末尾地址
    for (int i = 0; i < count; i++) {
        // *p: 访问当前 p 指向的值
        printf("%d ", *p);
        
        // p++: 将 p 移动到下一个 int 元素的地址
        p++;
    }
    printf("\n");
    
    return 0;
}
```

#### 练习题

#### 练习1：`strlen` 的指针实现

  - **题目**：我们知道 `string.h` 里的 `strlen(char* s)` 函数用于计算字符串长度（不含 `\0`）。请你模仿它，自己编写一个名为 `my_strlen` 的函数。
  - **要求**：**不**使用 `[]` 索引，全程使用指针 `*s` 和 `s++` 来实现。
  - **提示**：循环的条件应该是 `while (*s != '\0')`。

#### 练习2：使用指针查找

  - **题目**：编写一个函数 `findValue`，它接收一个 `int` 数组、数组大小和一个要查找的值 `target`。
  - **要求**：如果 `target` 存在于数组中，函数返回一个指向该元素在**原始数组中**位置的**指针**；如果未找到，返回 `NULL`。
  - **函数原型**：`int* findValue(int arr[], int size, int target);`

-----
### 第七章：结构体、联合与枚举

本章我们学习 C 语言提供的三种“自定义数据类型”工具：`struct`（结构体）、`union`（联合）和 `enum`（枚举）。它们让我们的代码能更直观地反映现实世界的数据模型。

#### 核心知识点

#### 1\. 结构体 (struct) - 数据的“包裹”

  - **定义**：结构体（Struct）是一种用户自定义的数据类型。它允许你将**多个不同类型**的变量组合（“打包”）成一个单一的逻辑单元。
  - **声明（创建模板）**：`struct` 关键字用于定义一个“模板”，它规定了这个“包裹”里都该有哪些东西。
    ```c
    // 定义一个“学生”的结构体模板
    struct Student {
        int id;
        char name[50];
        double gpa;
    };
    // 注意：这个定义以分号结尾，此时还没有创建任何变量，只是定义了“图纸”。
    ```
  - **创建变量（实例化）**：使用模板名来声明一个或多个变量。
    ```c
    int main() {
        // 声明一个名为 s1 的变量，它的类型是 "struct Student"
        struct Student s1;
        
        // 声明的同时进行初始化 (C99+ 推荐的“指定初始化”)
        struct Student s2 = {
            .id = 101,
            .name = "Alice",
            .gpa = 3.8
        };
        
        // 传统初始化 (必须按顺序)
        struct Student s3 = {102, "Bob", 3.5};
        
        return 0;
    }
    ```

#### 2\. 访问结构体成员

  - **(1) 成员访问运算符 `.` (点运算符)**

      - **作用**：当你有一个**结构体变量**时，使用“点”来访问它内部的成员。
      - **用法**：`变量名.成员名`

    <!-- end list -->

    ```c
    struct Student s1;

    // 对 s1 的成员进行赋值
    s1.id = 100;
    strcpy(s1.name, "Tom"); // 字符串赋值必须用 strcpy
    s1.gpa = 3.2;

    // 读取 s1 的成员
    printf("学生姓名: %s\n", s1.name);
    printf("学生 ID: %d\n", s1.id);
    ```

  - **(2) 指针访问运算符 `->` (箭头运算符)**

      - **作用**：当你只有一个**指向结构体的指针**时，使用“箭头”来访问它所指向的结构体的成员。
      - **背景**：`p_s` 是一个指针（地址），`*p_s` 是解引用（获取地址上的整个结构体），`(*p_s).id` 是访问其成员。这种写法太繁琐。
      - **等价**：`p_s->id` **完全等价于** `(*p_s).id`。
      - **用法**：`指针名->成员名`

    <!-- end list -->

    ```c
    struct Student s1 = {101, "Alice", 3.8};

    // 创建一个指向 s1 的指针
    struct Student* p_s = &s1;

    // 使用箭头运算符通过指针访问成员
    printf("ID (通过指针访问): %d\n", p_s->id);
    printf("姓名 (通过指针访问): %s\n", p_s->name);

    // 通过指针修改原变量
    p_s->gpa = 3.9;
    printf("修改后，s1.gpa 变为: %.1f\n", s1.gpa);
    ```

#### 3\. 结构体与函数

  - **(1) 传递结构体（值传递）**
      - `void printStudent(struct Student s)`
      - **行为**：函数会**完整地复制**你传入的整个结构体。`s` 是 `main` 函数中原变量的一个**副本**。
      - **缺点**：如果结构体很大（比如包含大数组），复制操作会非常**低效**。并且，函数内对 `s` 的修改**不会**影响 `main` 中的原变量。
  - **(2) 传递结构体指针（推荐）**
      - `void printStudent(struct Student* p_s)`
      - **行为**：函数只复制一个**指针**（地址，通常 4 或 8 字节），非常**高效**。
      - **优点**：函数可以通过指针（使用 `->`）**直接访问并修改** `main` 函数中的原始结构体。
      - **`const` 关键字**：如果函数只是读取数据而不修改，最佳实践是使用 `const` 关键字，告诉编译器这个指针不会被用来修改数据，更安全。
    <!-- end list -->
    ```c
    #include <stdio.h>

    struct Student { int id; double gpa; };

    // 高效且安全：通过 const 指针读取
    void printStudent(const struct Student* s) {
        // s->gpa = 4.0; // 这行会编译报错，因为 s 是 const
        printf("ID: %d, GPA: %.1f\n", s->id, s->gpa);
    }

    // 高效且可修改：通过指针修改
    void updateGpa(struct Student* s, double new_gpa) {
        s->gpa = new_gpa; // 直接修改了 main 中的原变量
    }

    int main() {
        struct Student s1 = {101, 3.5};
        
        printStudent(&s1);   // 传递地址
        updateGpa(&s1, 3.7); // 传递地址
        printStudent(&s1);   // 打印查看修改结果
        
        return 0;
    }
    ```

#### 4\. `typedef` - 创建类型别名

  - **作用**：`typedef` (Type Definition) 关键字用于为已有的数据类型创建一个**新的别名**。它**不**创造新类型，只是让类型名更简洁。
  - **背景**：每次都写 `struct Student s1;` 很繁琐。
  - **用法**：
    ```c
    // 原始定义
    struct Student {
        int id;
        char name[50];
    };

    // 使用 typedef
    typedef struct {
        int id;
        char name[50];
    } Student_t; // "Student_t" 现在是这个类型的别名

    int main() {
        struct Student s1; // 传统方式
        Student_t s2;      // 使用别名，更简洁
        
        s2.id = 102;
    }
    ```
    > 在 C++ 中，`typedef` 不是必需的，但在 C 语言中，它被广泛用于简化结构体、联合和指针的声明。

#### 5\. 联合 (union) - 内存的“共享”

  - **定义**：联合（Union）的声明语法与 `struct` 几乎一样，但它的**核心行为完全不同**。
  - **核心行为**：`union` 中的所有成员**共享同一块内存空间**。这块内存的大小由**最大的那个成员**决定。
  - **意义**：
    1.  **节省内存**：当你有一个数据单元，你知道它在**同一时间**只可能是 `int`、`float`、`char` 中的**一种**时，使用 `union` 可以节省大量内存。
    2.  **数据解析**：允许你用不同的数据类型“视角”去查看同一块内存（高级用法）。
  - **示例**：
    ```c
    typedef union {
        int i;
        float f;
        char c[4];
    } Data;

    int main() {
        Data d;
        printf("Data union 的大小是: %zu 字节\n", sizeof(Data)); // 通常是 4
        
        d.i = 10;
        printf("存入 int: d.i = %d\n", d.i);
        
        d.f = 3.14; // 写入 float
        printf("存入 float: d.f = %f\n", d.f);
        
        // 此时，d.i 的数据已经被 d.f 覆盖了！
        printf("此时 d.i 的值是: %d\n", d.i); // 输出一个奇怪的大数字
    }
    ```

#### 6\. 枚举 (enum) - 命名的整数常量

  - **作用**：当我们需要一组有意义的整数常量时（比如：错误码、状态、星期几），使用 `enum` (Enumeration) 可以让代码**可读性**大大提高。
  - **背景**：避免在代码中使用“魔术数字”(Magic Numbers)。
      - `if (status == 0)`（0 是什么意思？不明确）
      - `if (status == STATUS_OK)`（可读性强）
  - **定义**：
    ```c
    // 默认情况下，第一个成员是 0，后面依次递增
    enum Weekday {
        MON,    // 0
        TUE,    // 1
        WED,    // 2
        THU,    // 3
        FRI,    // 4
        SAT,    // 5
        SUN     // 6
    };

    // 也可以手动指定值
    enum Status {
        ERROR = -1,
        OK = 0,
        PENDING = 100
    };
    ```
  - **用法**：
    ```c
    enum Status current_status = OK;

    if (current_status == OK) {
        printf("操作成功！\n");
    }

    enum Weekday today = TUE;
    printf("今天是星期 (整数): %d\n", today); // 输出 1
    ```

### 实例与练习

#### 实例1：复数运算

**题目**：定义一个复数结构体，并实现复数的加法和打印。

**代码**：

```c
#include <stdio.h>

// 1. 使用 typedef 定义复数类型
typedef struct {
    double real; // 实部
    double imag; // 虚部
} Complex;

// 2. 打印函数 (使用 const 指针)
void print_complex(const Complex* c) {
    printf("(%.2f + %.2fi)\n", c->real, c->imag);
}

// 3. 加法函数 (传递副本，返回新副本)
Complex add_complex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

int main() {
    Complex a = {1.0, 2.0};
    Complex b = {3.0, 4.0};
    
    printf("A = ");
    print_complex(&a);
    
    printf("B = ");
    print_complex(&b);
    
    Complex sum = add_complex(a, b);
    
    printf("A + B = ");
    print_complex(&sum);
    
    return 0;
}
```

#### 实例2：嵌套结构体

**题目**：在我们的“学生”结构体中，使用一个“日期”结构体来存储生日。

**代码**：

```c
#include <stdio.h>

// 1. 先定义“零件”结构体
typedef struct {
    int year;
    int month;
    int day;
} Date;

// 2. 在“整体”结构体中使用它
typedef struct {
    int id;
    Date birthday; // 嵌套
} Student;

int main() {
    Student s1 = {
        .id = 101,
        .birthday = { .year = 2005, .month = 10, .day = 1 }
    };
    
    // 访问嵌套成员
    printf("学生 ID: %d\n", s1.id);
    printf("学生生日: %d 年 %d 月 %d 日\n",
           s1.birthday.year,
           s1.birthday.month,
           s1.birthday.day
    );
    
    return 0;
}
```

#### 练习题

#### 练习1：矩形面积

  - **题目**：定义一个 `struct Rectangle`，包含 `double width` 和 `double height` 两个成员。
  - **要求**：编写一个函数 `calculateArea`，它接收一个 `const struct Rectangle*`（指向矩形的**指针**），并返回该矩形的面积。

#### PRACTICE 2: 扑克牌

  - **题目**：使用 `enum` 定义扑克牌的“花色”（HEARTS, DIAMONDS, CLUBS, SPADES）和“点数”（TWO=2, THREE, ..., TEN, JACK, QUEEN, KING, ACE）。
  - **要求**：
    1.  定义一个 `struct Card`，它包含一个“花色”成员和一个“点数”成员。
    2.  编写一个函数 `print_card`，它接收一个 `const struct Card*`，并能打印出类似 "Card: KING of SPADES"（黑桃K）" 的信息。（提示：需要使用 `switch` 语句将 `enum` 值转换回字符串）。

#### 练习3：交通信号灯

  - **题目**：使用 `enum` 定义一个交通信号灯的状态（RED, YELLOW, GREEN）。
  - **要求**：编写一个函数 `next_state`，它接收当前的状态（`enum` 值），并返回下一个状态（RED -\> GREEN, GREEN -\> YELLOW, YELLOW -\> RED）。在 `main` 函数中测试它。

-----

### 第八章：文件输入与输出 (File I/O)

本章我们将学习 C 语言的标准 I/O 库 (`stdio.h`)，它提供了一套完整的函数，让我们能够打开、读取、写入和关闭文件。

#### 核心知识点

#### 1\. 什么是“文件指针” (`FILE*`)？

  - **流 (Stream)**：在 C 语言中，我们不直接操作文件，而是通过一个叫做“流”的抽象概念。你可以把“流”想象成一个连接你的程序和文件之间的“管道”。
  - **`FILE` 结构体**：C 语言在 `stdio.h` 中定义了一个名为 `FILE` 的**结构体**。这个结构体非常复杂，它内部“打包”了管理这个“流”所需的所有信息（比如，文件缓冲区、当前读取位置、是否出错等）。
  - **文件指针 (`FILE*`)**：我们从不直接创建 `FILE` 变量。我们要做的是调用一个函数（如 `fopen`），这个函数会为我们创建 `FILE` 结构体、打开文件并建立“管道”，然后**返回一个指向这个 `FILE` 结构体的指针**。
  - **结论**：在 C 语言中，我们**通过 `FILE*` 指针**来间接地操作文件。这个指针就是我们与文件沟通的唯一“句柄”。

#### 2\. 文件的打开与关闭

  - **`fopen(const char* filename, const char* mode)`**

      - **作用**：打开一个文件，并返回一个 `FILE*` 指针。
      - `filename`：要打开的文件名（例如 `"data.txt"` 或 `"C:\\temp\\log.txt"`）。
      - `mode`：**文件打开模式**，决定了你能对这个文件做什么。
          - `"r"` (Read)：**读**。文件必须存在，否则 `fopen` 失败返回 `NULL`。
          - `"w"` (Write)：**写**。如果文件不存在，则创建；如果文件**存在**，则**清空**其所有内容。
          - `"a"` (Append)：**追加**。如果文件不存在，则创建；如果文件存在，则在**文件末尾**开始写入（不清空原有内容）。
          - `"rb"`, `"wb"`, `"ab"`：`b` (Binary) 代表**二进制模式**。在 Windows 上读写非文本文件（如图片、结构体数据）时**必须**使用 `b`。
          - `"r+"`, `"w+"`, `"a+"`：`+` 代表“读和写”。
      - **错误处理（必须！）**：如果 `fopen` 失败（如文件不存在、权限不足），它会返回 `NULL`。**必须**检查这个返回值。

    <!-- end list -->

    ```c
    FILE* fp = fopen("scores.txt", "w");
    if (fp == NULL) {
        printf("错误：无法打开文件！\n");
        return 1; // 终止程序
    }
    ```

  - **`fclose(FILE* fp)`**

      - **作用**：关闭一个已打开的文件流。
      - **为什么必须关闭**：
        1.  你写入的数据可能还在“缓冲区”里，`fclose` 会将缓冲区剩余数据**刷入 (flush)** 硬盘。
        2.  释放操作系统为你打开文件所占用的资源。
      - **规则**：`fopen` 和 `fclose` **必须成对出现**。

#### 3\. 格式化文件 I/O (fprintf, fscanf)

  - **`fprintf(FILE* fp, const char* format, ...)`**

      - **作用**：与 `printf` 几乎一样，只是第一个参数变成了 `FILE*` 指针。它将**格式化的文本**（我们熟悉的 `%d`, `%s`, `%.2f`）**写入到文件**中。

    <!-- end list -->

    ```c
    struct Student s1 = {101, "Alice", 3.8};
    // 将 s1 的信息按格式写入 fp 指向的文件
    fprintf(fp, "ID: %d, 姓名: %s, 绩点: %.2f\n", s1.id, s1.name, s1.gpa);
    ```

  - **`fscanf(FILE* fp, const char* format, ...)`**

      - **作用**：与 `scanf` 几乎一样，只是第一个参数变成了 `FILE*` 指针。它从**文件中读取格式化的文本**。
      - **返回值（重要！）**：`fscanf` 返回成功读取并赋值的**项数**。如果读到文件末尾或出错，会返回 `EOF`（End Of File，一个特殊的负数常量）。

    <!-- end list -->

    ```c
    int id;
    char name[50];
    double gpa;

    // 尝试从 fp 指向的文件读取数据
    // 注意 name 为什么不需要 & （因为数组名已是指针）
    while (fscanf(fp, "%d %s %lf", &id, name, &gpa) == 3) {
        // 如果成功读到了 3 项
        printf("读取到: %d, %s, %.2f\n", id, name, gpa);
    }
    // 循环会在读到文件末尾时自动停止
    ```

#### 4\. 字符文件 I/O (fgetc, fputc)

  - **`int fputc(int c, FILE* fp)`**：将**单个字符** `c` 写入文件。
  - **`int fgetc(FILE* fp)`**：从文件中读取**单个字符**。
      - **返回值**：如果成功，返回该字符的 ASCII 码；如果读到文件末尾，返回 `EOF`。

#### 5\. 字符串文件 I/O (fgets, fputs)

  - **`fputs(const char* str, FILE* fp)`**：将一个**字符串** `str` 写入文件（**不**会自动添加换行符 `\n`）。
  - **`char* fgets(char* str, int size, FILE* fp)`**：从文件中读取**一行**字符串（最多 `size-1` 个字符），存入 `str` 中。
      - **行为**：它会连同换行符 `\n` 一起读入。
      - **返回值**：如果成功，返回 `str` 指针；如果读到文件末尾，返回 `NULL`。这是判断文件是否读完的标准方式。

#### 6\. 二进制 I/O (fread, fwrite) - 高效读写

  - **背景**：`fprintf` 和 `fscanf` 是**文本I/O**，它们需要把内存中的 `int` (如 `101`) 转换成文本 "101"。这种转换是**低效**的，且对于 `double` 还会**损失精度**。

  - **二进制 I/O**：**不**做任何转换，直接将内存中的数据（字节模式）**原封不动地**“拷贝”到文件中。

  - **`fwrite(const void* ptr, size_t size, size_t count, FILE* fp)`**

      - `ptr`：指向你要写入的数据（比如一个结构体变量的地址 `&s1`）。
      - `size`：**每个**数据块的大小（比如 `sizeof(struct Student)`）。
      - `count`：要写入多少**个**这样的数据块（比如 `1`）。
      - `fp`：文件指针。

  - **`fread(void* ptr, size_t size, size_t count, FILE* fp)`**

      - `ptr`：指向一块用于**接收**数据的内存（比如 `&s1`）。
      - `size`：**每个**数据块的大小。
      - `count`：要读取多少**个**这样的数据块。
      - `fp`：文件指针。
      - **返回值**：返回**实际成功读取**的数据块**个数**。如果它小于 `count`，通常意味着已到达文件末尾。

### 实例与练习

#### 实例1：写入和读取文本文件

**题目**：使用 `fprintf` 写入学生信息，再使用 `fgets` 逐行读回。

**代码**：

```c
#include <stdio.h>

int main() {
    FILE* fp = NULL;
    char buffer[100]; // 用于 fgets 的缓冲区

    // --- 写入阶段 (w 模式) ---
    fp = fopen("log.txt", "w");
    if (fp == NULL) return 1;

    printf("正在写入文件...\n");
    fprintf(fp, "ID: 101, Name: Alice\n");
    fprintf(fp, "ID: 102, Name: Bob\n");
    
    fclose(fp); // 必须关闭以保存写入

    // --- 读取阶段 (r 模式) ---
    fp = fopen("log.txt", "r");
    if (fp == NULL) return 1;

    printf("正在读取文件内容：\n");
    // 当 fgets 读到文件末尾时，会返回 NULL
    while (fgets(buffer, 100, fp) != NULL) {
        // buffer 中包含了换行符，所以 printf 不用加 \n
        printf("%s", buffer); 
    }
    
    fclose(fp);
    
    return 0;
}
```

#### 实例2：使用二进制 I/O 读写结构体

**题目**：将一个 `Student` 结构体变量以**二进制**形式写入文件，然后再读回。

**代码**：

```c
#include <stdio.h>

// 假设我们有这个结构体
typedef struct {
    int id;
    char name[50];
    double gpa;
} Student;

int main() {
    Student s_write = {101, "Alice", 3.85}; // 待写入的数据
    Student s_read;                         // 用于读回的数据
    FILE* fp = NULL;
    
    // --- 写入 (wb 模式) ---
    fp = fopen("students.dat", "wb"); // 'b' = 二进制
    if (fp == NULL) return 1;
    
    // 写入 1 块，每块大小为 sizeof(Student)
    fwrite(&s_write, sizeof(Student), 1, fp);
    
    fclose(fp);
    
    // --- 读取 (rb 模式) ---
    fp = fopen("students.dat", "rb");
    if (fp == NULL) return 1;
    
    // 读取 1 块，每块大小为 sizeof(Student)
    size_t read_count = fread(&s_read, sizeof(Student), 1, fp);
    
    fclose(fp);
    
    if (read_count == 1) {
        printf("二进制读取成功！\n");
        printf("ID: %d, Name: %s, GPA: %.2f\n", 
               s_read.id, s_read.name, s_read.gpa);
    } else {
        printf("读取失败！\n");
    }

    return 0;
}
```

#### 练习题

#### 练习1：文件复制

  - **题目**：编写一个程序，实现文件复制功能。
  - **要求**：
    1.  程序打开 `source.txt`（用 `"r"` 或 `"rb"` 模式）。
    2.  程序创建 `destination.txt`（用 `"w"` 或 `"wb"` 模式）。
    3.  使用 `fgetc` 和 `fputc` 循环，逐个字符地将 `source.txt` 的内容读取并写入到 `destination.txt`，直到 `fgetc` 返回 `EOF`。
    4.  关闭两个文件。

#### 练习2：简易日记本

  - **题目**：编写一个程序，让用户输入一行日记，程序将这行日记**追加**到 `diary.txt` 文件中。
  - **要求**：
    1.  使用 `fgets` 从键盘安全地读取用户输入的一行话。
    2.  使用 `"a"` (Append) 模式打开 `diary.txt`。
    3.  使用 `fputs` 将用户输入的字符串（`fgets` 已经包含了 `\n`）写入文件。
    4.  关闭文件。每次运行程序，都应在文件末尾添加新内容，而不是覆盖旧内容。

#### 练习3：学生数据持久化（挑战）

  - **题目**：结合上一章的结构体，编写一个程序，允许用户输入**多个**学生信息，将这些学生数据**以数组的形式**一次性用 `fwrite` 写入文件；然后再用 `fread` 一次性读回内存。
  - **提示**：
    1.  `Student student_array[3];`
    2.  `fwrite(student_array, sizeof(Student), 3, fp);`
    3.  `fread(student_array, sizeof(Student), 3, fp);`

-----

### 第九章：位运算 (Bitwise Operations)

本章我们深入到 C 语言的最底层——**比特位 (bit)**。C 语言提供了直接操作整数比特位的运算符，这使得它在与硬件交互、数据压缩和加密算法等领域具有无与伦比的效率。

#### 核心知识点

#### 1\. 什么是“位”？

  - **比特 (bit)**：计算机中最小的数据单元，只能是 `0` 或 `1`。
  - **字节 (Byte)**：8 个比特组成一个字节。
  - **二进制表示**：我们平时用的 `int` 类型（假设为 32 位），在内存中就是由 32 个 `0` 和 `1` 组成的。
      - 例如，十进制的 `9`，在 8 位的 `char` 中表示为：`0000 1001`

#### 2\. 位运算符

C 语言提供了 6 种位运算符，它们**只对整数类型**（`char`, `int`, `long` 等）起作用。

  - **(1) `&` (按位与 AND)**

      - **规则**：`1 & 1` 得 `1`，其他情况（`1&0`, `0&1`, `0&0`）都得 `0`。（**“全 1 才 1”**）
      - **示例**：`9 & 5`
        ```
          0000 1001  (十进制 9)
        & 0000 0101  (十进制 5)
        -----------
          0000 0001  (十进制 1)
        ```
      - **用途**：
        1.  **清零 (Masking)**：`x & 0` 可以将 `x` 对应位清零。
        2.  **取特定位**：`x & 0b1000` 可以只保留 `x` 的第 3 位（从0开始数）。

  - **(2) `|` (按位或 OR)**

      - **规则**：`0 | 0` 得 `0`，其他情况（`1|0`, `0|1`, `1|1`）都得 `1`。（**“有 1 就 1”**）
      - **示例**：`9 | 5`
        ```
          0000 1001  (十进制 9)
        | 0000 0101  (十进制 5)
        -----------
          0000 1101  (十进制 13)
        ```
      - **用途**：
        1.  **置 1 (Setting)**：`x | 1` 可以将 `x` 对应位置 1。

  - **(3) `^` (按位异或 XOR)**

      - **规则**：`1 ^ 0` 和 `0 ^ 1` 得 `1`；`0 ^ 0` 和 `1 ^ 1` 得 `0`。（**“相异为 1”**）
      - **示例**：`9 ^ 5`
        ```
          0000 1001  (十进制 9)
        ^ 0000 0101  (十进制 5)
        -----------
          0000 1100  (十进制 12)
        ```
      - **特性 (重要)**：
        1.  `x ^ 0 = x` (任何数异或 0 还是它自己)
        2.  `x ^ x = 0` (任何数异或它自己都等于 0)
        3.  `x ^ y = y ^ x` (交换律)
      - **用途**：
        1.  **翻转 (Flipping)**：`x ^ 1` 可以翻转 `x` 对应位（0变1, 1变0）。
        2.  **不使用临时变量交换 `a`, `b`** (经典面试题)：
            `a = a ^ b; b = a ^ b; a = a ^ b;`

  - **(4) `~` (按位取反 NOT)**

      - **规则**：单目运算符。`0` 变 `1`，`1` 变 `0`。
      - **示例**：`~9` (假设为 8 位)
        ```
        ~ 0000 1001  (十进制 9)
        -----------
          1111 0110  (这是一个负数，补码表示法)
        ```
      - **注意**：`~x` **不等于** `-x`。在补码表示法中，`~x` 等于 `-(x+1)`。

  - **(5) `<<` (左移)**

      - **规则**：`x << n` 将 `x` 的所有比特位向左移动 `n` 位，右侧空出的位用 `0` 补齐。
      - **示例**：`9 << 2`
        ```
        0000 1001 (9)  << 2
        -----------
        0010 0100 (十进制 36)
        ```
      - **数学意义**：`x << n` **在数值上**等价于 `x * (2^n)`（`9 * (2^2) = 9 * 4 = 36`）。在计算机中，移位运算比乘法**快得多**。

  - **(6) `>>` (右移)**

      - **规则**：`x >> n` 将 `x` 的所有比特位向右移动 `n` 位。
      - **示例**：`9 >> 2`
        ```
        0000 1001 (9)  >> 2
        -----------
        0000 0010 (十进制 2)
        ```
      - **数学意义**：`x >> n` **在数值上**等价于 `x / (2^n)`（整数除法 `9 / 4 = 2`）。
      - **重要区分 (算术右移 vs 逻辑右移)**：
        1.  **逻辑右移**：左侧空出的位**总是**用 `0` 补。
        2.  **算术右移**：左侧空出的位用\*\*“符号位”\*\*补（`0` 或 `1`）。
        <!-- end list -->
          - **规则**：对于**无符号数 (`unsigned`)**，C 语言保证是**逻辑右移**。对于**有符号数 (`signed`)**，是**算术右移**（大多数编译器如此），这样能保持负数的正负号。

#### 3\. 位运算的实战技巧：“掩码” (Mask)

  - **掩码 (Mask)**：一个精心构造的整数，用来和目标数进行 `&`、`|`、`^` 运算，以实现对特定位的**精确操作**。

  - **场景**：假设我们要操作一个 8 位的硬件寄存器 `reg`。

  - **(1) 将特定位置 1 (Set a bit)**

      - **需求**：将 `reg` 的第 3 位置 1（从 0 数起），其他位不变。
      - **掩码**：`0000 1000` (即 `1 << 3`)
      - **操作**：`reg = reg | (1 << 3);`
      - **原理**：`x | 0 = x` (不变)；`x | 1 = 1` (置1)。

  - **(2) 将特定位置 0 (Clear a bit)**

      - **需求**：将 `reg` 的第 3 位置 0，其他位不变。
      - **掩码**：`~(1 << 3)` (即 `1111 0111`)
      - **操作**：`reg = reg & ~(1 << 3);`
      - **原理**：`x & 1 = x` (不变)；`x & 0 = 0` (清0)。

  - **(3) 翻转特定位 (Toggle a bit)**

      - **需求**：翻转 `reg` 的第 3 位（0变1, 1变0）。
      - **掩码**：`1 << 3`
      - **操作**：`reg = reg ^ (1 << 3);`
      - **原理**：`x ^ 0 = x` (不变)；`x ^ 1 = (1-x)` (翻转)。

  - **(4) 检查特定位 (Check a bit)**

      - **需求**：检查 `reg` 的第 3 位是 `0` 还是 `1`。
      - **掩码**：`1 << 3`
      - **操作**：`if (reg & (1 << 3))`
      - **原理**：
          - 如果第 3 位是 `0`，`0000 x000 & 0000 1000` 结果是 `0` (False)。
          - 如果第 3 位是 `1`，`0000 1000 & 0000 1000` 结果是 `8` (非 0，True)。

### 实例与练习

#### 实例1：判断奇偶数 (位运算版)

**题目**：使用位运算判断一个整数是奇数还是偶数。

**代码**：

```c
#include <stdio.h>

int main() {
    int num = 101;
    
    // 思考：一个数的奇偶性由哪一位决定？
    // 答案：最低位（第 0 位）。偶数的第 0 位是 0，奇数的第 0 位是 1。
    // (num & 1) 的结果：如果 num 是偶数，则为 0；如果 num 是奇数，则为 1。
    
    if ((num & 1) == 0) {
        printf("%d 是偶数\n", num);
    } else {
        printf("%d 是奇数\n", num);
    }
    
    return 0;
}
```

#### 实例2：打印一个整数的二进制表示

**题目**：编写一个函数，打印出 `unsigned int` 类型的整数的二进制形式。

**代码**：

```c
#include <stdio.h>

// 打印一个 32 位无符号整数的二进制
void print_binary(unsigned int num) {
    // 我们需要一个 32 位的 int 来操作
    // sizeof(unsigned int) * 8 = 4 * 8 = 32
    int total_bits = sizeof(num) * 8;
    
    // 我们从最高位（第 31 位）开始检查
    for (int i = total_bits - 1; i >= 0; i--) {
        // 1. 创建一个只在第 i 位为 1 的掩码
        unsigned int mask = (1U << i); // 1U 表示 unsigned int 类型的 1
        
        // 2. 检查 num 的第 i 位
        if (num & mask) {
            printf("1");
        } else {
            printf("0");
        }
        
        // 为了可读性，每 8 位加个空格
        if (i % 8 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    print_binary(9);     // 00000000 ... 00001001
    print_binary(255);   // 00000000 ... 11111111
    return 0;
}
```

#### 练习题

#### 练习1：统计 1 的个数

  - **题目**：编写一个函数 `countSetBits(int n)`，它接收一个整数 `n`，返回 `n` 的二进制表示中 `1` 的个数。
  - **例如**：`n = 13`（二进制 `1101`），函数应返回 3。
  - **提示**：使用循环和 `n & 1` 来检查最后一位，然后使用 `n >> 1`（右移）来“砍掉”最后一位，直到 `n` 变为 0。

#### 练习2：不使用 `temp` 交换

  - **题目**：在 `main` 函数中定义 `int a = 10, b = 20;`。
  - **要求**：**不**允许使用**任何**临时变量（如 `int temp;`），只使用 `^` (按位异或) 运算符，实现 `a` 和 `b` 的值交换，并打印交换后的结果。

#### 练习3：开关灯（掩码实战）

  - **题目**：假设你用一个 `unsigned char`（8 位）变量 `lights` 来控制 8 盏灯（0-7号）。`1` 代表灯亮，`0` 代表灯灭。
  - **要求**：
    1.  初始化 `lights = 0;`（全灭）。
    2.  编写代码实现“打开 3 号灯和 5 号灯”。
    3.  编写代码实现“检查 4 号灯是否亮着”（此时应不亮）。
    4.  编写代码实现“关闭 3 号灯”。
    5.  编写代码实现“翻转 7 号灯的状态”。
  - **提示**：使用 `|`, `&`, `~`, `^` 和移位 `(1 << n)` 来创建你的掩码。
-----

### 第十章：预处理器 (Preprocessor)

本章我们学习 C 语言的预处理指令（所有以 `#` 开头的命令）。它们不是 C 语言的关键字，而是给“预处理器”这个工具下达的命令，用于在编译前“重塑”我们的代码。

#### 核心知识点

#### 1\. 什么是预处理器？

  - **定义**：预处理器是 C 编译流程的**第 0 步**。它是一个文本处理程序，它会扫描你的 `.c` 文件，找出所有的 `#` 指令，并根据指令修改代码的文本内容。
  - **流程**：
    `源文件.c` -\> **[预处理器]** -\> `"临时的、处理过的.c文件"` -\> **[编译器]** -\> `目标文件.o`
  - **用途**：包含文件、定义宏（常量和“函数”）、根据条件编译代码。

#### 2\. `#include` - 包含文件

  - **作用**：告诉预处理器“把指定文件的**全部内容**复制粘贴到这一行”。
  - **`#include <stdio.h>` (尖括号)**
      - **含义**：从**系统标准库目录**中查找文件。
      - **用途**：用于包含 `stdio.h`, `stdlib.h`, `string.h` 等系统自带的头文件。
  - **`#include "my_header.h"` (双引号)**
      - **含义**：**首先**从**当前项目目录**（或 `-I` 指定的目录）中查找，如果找不到，**再**去系统标准库目录中查找。
      - **用途**：用于包含我们自己编写的 `.h` 头文件（如 `student.h`）。

#### 3\. `#define` - 定义宏

  - **作用**：这是预处理器**最强大**的功能。它定义了一个“宏”，告诉预处理器在后续代码中，只要遇到这个“名字”，就把它**无脑地替换**成“内容”。

  - **(1) 对象式宏 (Object-like Macros) - “常量”**

      - **定义**：`#define 宏名 内容`
      - **用途**：定义常量、标志符。
      - **示例**：
        ```c
        #define PI 3.14159
        #define BUFFER_SIZE 1024

        int main() {
            double r = 10.0;
            double area = PI * r * r; // 预处理后，这行代码变成 area = 3.14159 * r * r;
            int buf[BUFFER_SIZE];     // 变成 int buf[1024];
        }
        ```
      - **`#define` vs `const`**：
          - `const int SIZE = 10;` 是一个**变量**，有类型、有地址，在**运行时**存在。
          - `#define SIZE 10` 只是一个**文本标记**，在**预处理时**就被替换掉了，没有类型，不占内存。

  - **(2) 函数式宏 (Function-like Macros) - “带参宏”**

      - **定义**：`#define 宏名(参数列表) 内容`

      - **示例**：

        ```c
        #define MAX(a, b) ((a) > (b) ? (a) : (b))

        int z = MAX(10, 20); // 预处理后：int z = ((10) > (20) ? (10) : (20));
        ```

      - **陷阱（极其重要！）**：

        1.  **括号，括号，还是括号！** 必须为**每个参数**和**整个表达式**都加上括号，否则会因“运算符优先级”导致灾难性错误。
        2.  **副作用**：宏只是文本替换。如果你调用 `MAX(x++, y++)`，`x++` 或 `y++` 可能会被**执行两次**！

      - **错误示例 (没有括号)**：

        ```c
        #define SQUARE(x) x * x

        // 致命错误
        int y = SQUARE(5 + 1);
        // 预处理后：int y = 5 + 1 * 5 + 1;  (结果是 11，而不是 36)

        // 正确写法：
        #define SQUARE(x) ((x) * (x))
        // 预处理后：int y = ((5 + 1) * (5 + 1)); (结果是 36)
        ```

  - **`#undef` - 取消定义**

      - **作用**：`#undef 宏名` 可以取消一个已经定义的宏。

#### 4\. 条件编译 (Conditional Compilation)

  - **作用**：告诉预处理器**根据某些条件**，决定代码中的哪些部分**参与**（或**不参与**）最终的编译。

  - **(1) `#if`, `#elif`, `#else`, `#endif`**

      - **用途**：基于一个**常量表达式**（必须在预处理时就能求值）来判断。
      - **示例**：
        ```c
        #define VERSION 2

        #if VERSION == 1
            printf("版本 1.0\n");
        #elif VERSION == 2
            printf("版本 2.0\n");
        #else
            printf("未知版本\n");
        #endif
        ```

  - **(2) `#ifdef` (If Defined) 和 `#ifndef` (If Not Defined)**

      - **用途**：检查一个**宏是否已经被定义**（`#define` 过）。
      - **`#ifdef` 示例 (调试开关)**：
        ```c
        // 可以在 Makefile 的 CFLAGS 里通过 -DDEBUG 来定义
        // #define DEBUG 

        #ifdef DEBUG
            printf("调试信息：x = %d\n", x);
        #endif
        // 如果 DEBUG 宏没有被定义，上面三行代码会彻底消失，不产生任何开销。
        ```
      - **`#ifndef` 示例 (头文件保护)**：
          - 这是我们多文件编程中的老朋友了。
            ```c
            // student.h
            #ifndef STUDENT_H   // “如果没有定义过 STUDENT_H 这个宏...”
            #define STUDENT_H   // “...那我们就立刻定义它！”

            // ... 头文件内容 ...

            #endif              // “结束条件块。”
            ```
          - **原理**：当 `main.c` 和 `database.c` 都 `#include "student.h"` 时：
            1.  `main.c` 编译，`#include "student.h"`。`STUDENT_H` 未定义，于是定义 `STUDENT_H`，内容被包含。
            2.  `database.c` 编译，`#include "student.h"`。`STUDENT_H` **已经**被定义了（在同一个编译单元内），`#ifndef` 条件为假，预处理器会**跳过**从 `#ifndef` 到 `#endif` 之间的所有内容。
            3.  完美避免了重定义错误。

#### 5\. 预定义宏

  - C 语言标准内置了一些有用的宏，你可以在代码中直接使用它们：
      - `__FILE__`：当前源文件的文件名（字符串）。
      - `__LINE__`：当前代码在源文件中的行号（整数）。
      - `__DATE__`：编译日期（字符串）。
      - `__TIME__`：编译时间（字符串）。
  - **用途**：主要用于打印日志和调试信息。
    ```c
    fprintf(stderr, "错误: 空指针！位于文件 %s 的第 %d 行。\n", __FILE__, __LINE__);
    ```

### 实例与练习

#### 实例1：调试宏

**题目**：创建一个 `LOG_DEBUG(msg)` 宏，当 `DEBUG` 宏被定义时，它打印调试信息；否则它什么也不做。

**代码**：

```c
#include <stdio.h>

// 1. 定义 DEBUG 开关。注释掉这行，程序就不会打印调试信息。
#define DEBUG

// 2. 定义我们的宏
#ifdef DEBUG
    // (##__VA_ARGS__ 是一个高级技巧，这里我们用简单版)
    // __FILE__ 和 __LINE__ 是预定义的宏
    #define LOG_DEBUG(msg) printf("[DEBUG] %s:%d: %s\n", __FILE__, __LINE__, msg)
#else
    // 如果 DEBUG 未定义，LOG_DEBUG 宏就替换成“什么都不做”
    #define LOG_DEBUG(msg) 
#endif

int main() {
    int x = 10;
    
    LOG_DEBUG("程序启动"); // 编译时会被替换
    
    if (x > 5) {
        LOG_DEBUG("x 大于 5");
    }
    
    return 0;
}
```

#### 实例2：宏的陷阱

**题目**：对比一个“安全”的宏和一个“危险”的宏。

**代码**：

```c
#include <stdio.h>

// 危险：没有括号
#define DANGEROUS_ADD(a, b) a + b

// 安全：所有参数和整体都有括号
#define SAFE_ADD(a, b) ((a) + (b))

int main() {
    // 看起来没问题
    printf("危险: %d\n", DANGEROUS_ADD(2, 3)); // 替换为 2 + 3 = 5
    printf("安全: %d\n", SAFE_ADD(2, 3));     // 替换为 ((2) + (3)) = 5
    
    // 灾难发生
    // 乘法优先级高于加法
    printf("危险 * 10: %d\n", DANGEROUS_ADD(2, 3) * 10); // 替换为 2 + 3 * 10 = 32
    printf("安全 * 10: %d\n", SAFE_ADD(2, 3) * 10);     // 替换为 ((2) + (3)) * 10 = 50
    
    return 0;
}
```

#### 练习题

#### 练习1：安全宏 `SQUARE`

  - **题目**：定义一个函数式宏 `SQUARE(x)`，它能**正确**计算 `x` 的平方。
  - **要求**：
    1.  你的宏必须能正确计算 `SQUARE(1 + 1)`（结果应为 4）。
    2.  你的宏必须能正确计算 `100 / SQUARE(10)`（结果应为 1）。
    3.  （提示：你需要几层括号？）

#### 练习2：跨平台编译

  - **题目**：C 语言的编译器会自动定义一些宏来标识操作系统，例如 `_WIN32` (Windows) 和 `__APPLE__` (macOS)。
  - **要求**：编写一个程序，它能在编译时根据不同的操作系统，打印出不同的欢迎信息。
    ```c
    int main() {
        // 在这里插入你的 #if, #elif, #else, #endif 指令
        
        printf("欢迎使用本程序！\n");
        
        // ...
        
        return 0;
    }
    ```
    （你可以在 Windows 上编译，看看它是否打印 Windows 的信息）
---

### 第十一章：链表 (Linked Lists)

本章我们学习 C 语言的终极数据结构——链表。数组（包括动态数组）在“插入”和“删除”操作上效率低下，而链表则完美地解决了这一问题。

#### 核心知识点

#### 1\. 为什么需要链表？(数组的局限)

  - **数组 (Array)**：

      - **优点**：内存连续，访问**快**（`O(1)`）。`arr[5]` 立即就能定位。
      - **缺点**：大小固定（静态数组）或扩容代价高（动态数组 `realloc`）。
      - **致命缺点**：在**中间**插入或删除元素**极其缓慢**（`O(n)`）。如果你想在 100 万个元素的数组中第 2 个位置插入一个数，你需要把后面 999,998 个元素全部向后移动一位。

  - **链表 (Linked List)**：

      - **优点**：内存**不**需要连续，可以“东一块西一块”。**插入**和**删除**元素**极其快速**（`O(1)`），只需要修改几个指针的指向。
      - **缺点**：访问**慢**（`O(n)`）。你**不能**直接访问第 5 个元素，必须从“头”开始，一个一个地“跳”过去，直到跳了 5 次。

#### 2\. 什么是链表？

  - **比喻**：想象一下“寻宝游戏”。
    1.  你手里有一张卡片（**头指针 `head`**），上面写着第一个宝藏（第一个节点）的“位置 A”。
    2.  你跑到“位置 A”，打开宝藏（**节点 A**）。
    3.  宝藏里有两样东西：(1) **数据**（比如 10 金币）；(2) **一张新卡片**，上面写着下一个宝藏（节点 B）的“位置 B”。
    4.  你跑到“位置 B”，打开宝藏（**节点 B**）。
    5.  宝藏里有：(1) **数据**（比如 20 金币）；(2) **一张新卡片**，写着“位置 C”。
    6.  ...
    7.  你跑到最后一个宝藏（**节点 Z**），宝藏里有：(1) **数据**（比如 50 金币）；(2) 一张卡片，上面写着 **`NULL` (结束)**。
  - **结论**：链表就是由一系列“节点”串联起来的，每个节点都包含\*\*“数据”**和**“指向下一个节点的指针”\*\*。

#### 3\. 链表的“节点” (Node) - `struct` 实现

  - **C 语言实现**：这个“节点”完美地对应了 C 语言的**结构体**。
  - **自引用结构体 (Self-referential Struct)**：这是一个结构体，它内部的一个成员是**指向同类型结构体**的指针。
    ```c
    // 定义一个“节点”的模板
    // 我们使用 typedef 简化类型名
    typedef struct Node {
        int data;            // 存放的数据 (宝藏)
        struct Node* next;   // 指向下一个节点的指针 (下一张卡片)
    } Node; // "Node" 现在是这个结构体类型的别名
    ```

#### 4\. 构建与遍历链表

  - **(1) `malloc` 创建节点**：

      - 链表的节点必须在**堆 (Heap)** 上创建，因此我们使用 `malloc` 来动态申请内存。

    <!-- end list -->

    ```c
    #include <stdlib.h>

    // 创建一个新节点
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        // 内存分配失败
        return 1; 
    }

    // 设置节点内容
    new_node->data = 10;
    new_node->next = NULL; // 默认它后面没有东西
    ```

  - **(2) `head` 指针 (头指针)**：

      - `head` 是链表的**入口**。它是一个 `Node*` 类型的指针，**永远**指向链表的**第一个节点**。
      - 如果你丢失了 `head` 指针，你就丢失了整个链表。
      - 一个空链表就是 `Node* head = NULL;`。

  - **(3) 遍历链表 (最经典的操作)**：

      - 遍历链表的**唯一**方法就是：从 `head` 出发，沿着 `next` 指针一路“跳”下去，直到 `next` 变为 `NULL`。

    <!-- end list -->

    ```c
    void print_list(const Node* head) {
        // 1. 创建一个“临时工”指针 p，从 head 开始
        const Node* p = head;
        
        // 2. 当 p 不为 NULL (即还没到终点) 时，继续循环
        while (p != NULL) {
            // 3. 打印当前节点的数据
            printf("%d -> ", p->data);
            
            // 4. (关键) p "跳"到下一个节点
            p = p->next;
        }
        
        // 5. 循环结束，p 此时是 NULL
        printf("NULL\n");
    }
    ```

#### 5\. 释放链表（必须！）

  - **风险**：链表是 `malloc` 出来的，如果不 `free`，会造成严重的**内存泄漏**。
  - **错误操作**：`free(p); p = p->next;`
      - `free(p)` 后，`p` 指向的内存已经“还给”系统了，你**不能**再访问 `p->next`，这会导致程序崩溃。
  - **正确操作**：必须使用**两个指针**（一个 `current`，一个 `temp`）来安全地释放。
    ```c
    void free_list(Node* head) {
        Node* current = head;
        Node* temp = NULL;
        
        while (current != NULL) {
            // 1. 用 temp 记住当前节点
            temp = current;
            
            // 2. current 先“安全地”跳到下一个节点
            current = current->next;
            
            // 3. 释放 temp (即上一个节点)
            free(temp);
        }
        
        // head = NULL; // 可以在调用方设置，表示链表已清空
    }
    ```

### 实例与练习

#### 实例1：创建、遍历、释放一个简单链表

**题目**：手动创建三个节点（10, 20, 30），将它们链接起来，打印，最后释放。

**代码**：

```c
#include <stdio.h>
#include <stdlib.h>

// (此处应包含上面定义的 Node 结构体)
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// (此处应包含上面定义的 print_list 和 free_list 函数)
void print_list(const Node* head) {
    const Node* p = head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void free_list(Node* head) {
    Node* current = head;
    Node* temp = NULL;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL; // 链表头指针
    
    // 1. 创建节点
    Node* n1 = (Node*) malloc(sizeof(Node));
    n1->data = 10;
    
    Node* n2 = (Node*) malloc(sizeof(Node));
    n2->data = 20;
    
    Node* n3 = (Node*) malloc(sizeof(Node));
    n3->data = 30;

    // 2. 链接它们
    head = n1;      // n1 是第一个
    n1->next = n2;  // n1 指向 n2
    n2->next = n3;  // n2 指向 n3
    n3->next = NULL; // n3 是最后一个

    // 3. 打印
    printf("我的链表: ");
    print_list(head);

    // 4. 释放
    free_list(head);
    head = NULL; // 养成好习惯

    return 0;
}
```

#### 实例2：在链表头部插入（最高效的插入）

**题目**：编写一个 `insert_at_head` 函数，它接收**当前的 head** 和一个新值，返回**新的 head**。

**代码**：

```c
// (假设 Node 已定义)

// 函数返回一个新的 Node*，因为 head 改变了
Node* insert_at_head(Node* old_head, int value) {
    // 1. 创建新节点
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = value;
    
    // 2. 新节点指向旧的 head
    new_node->next = old_head;
    
    // 3. 返回新节点，它现在是新的 head
    return new_node;
}

int main() {
    Node* head = NULL; // 初始为空链表
    
    // 插入 5。head = insert... 这一步至关重要
    head = insert_at_head(head, 5);  // head -> 5 -> NULL
    head = insert_at_head(head, 3);  // head -> 3 -> 5 -> NULL
    head = insert_at_head(head, 1);  // head -> 1 -> 3 -> 5 -> NULL
    
    printf("在头部插入后: ");
    print_list(head);
    
    free_list(head);
    return 0;
}
```

#### 练习题

#### 练习1：在链表尾部插入

  - **题目**：编写一个函数 `void insert_at_tail(Node* head, int value)`。
  - **要求**：它能找到链表的**最后一个**节点，并在其后附加一个新节点。
  - **提示**：你需要一个 `while (p->next != NULL)` 循环来找到最后一个节点 `p`。

#### 练习2：查找节点

  - **题目**：编写一个函数 `Node* find_node(Node* head, int value)`。
  - **要求**：遍历链表，如果找到了一个 `data` 与 `value` 相等的节点，就**返回指向该节点的指针**。如果遍历完也没找到，就返回 `NULL`。

#### 练习3：计算链表长度（挑战）

  - **题目**：编写一个函数 `int get_length(const Node* head)`。
  - **要求**：**不**使用 `[]`，只使用指针遍历，返回链表中节点的总个数。

-----

按照翁恺老师的课程体系，这 11 章已经涵盖了 C 语言**全部的核心知识**。我们已经完成了预定的复习计划！

最后一章，我们不讲新知识了，而是对我们走过的路进行一个**全面的总结**，并展望一下你的下一步。

---

### 第十二章：C 语言复习总结与后续之路

#### 一、我们的复习地图 (知识体系总览)

在这次复习中，我们系统性地重构了 C 语言的知识大厦，从地基到封顶：

  - **`Ch 1-3`: 地基 (程序的基本逻辑)**
    - **变量与计算**：`int`, `double`, `const`, 运算符。
    - **判断与循环**：`if-else`, `for`, `while`, `do-while`, `break`。

  - **`Ch 4`: 框架 (代码的组织能力)**
    - **函数**：`void func(int arg)`，封装、复用。
    - **工程结构**：多文件编程 (`.c` / `.h`)，`Makefile` 自动化构建。

  - **`Ch 5-7`: 蓝图 (数据的组织能力)**
    - **数组**：`int arr[]`，内存连续，随机访问。
    - **字符串**：`char s[]`，以 `\0` 结尾，`string.h` 函数库。
    - **结构体**：`struct`，打包不同类型的数据，`typedef` 别名。

  - **`Ch 6, 9`: 核心 (C 语言的灵魂)**
    - **指针**：`int* p = &a`，`*p` 解引用。C 语言一切灵活性的根源。
    - **位运算**：`&`, `|`, `^`, `~`, `<<`, `>>`，直达硬件的“手术刀”。

  - **`Ch 5, 8, 11`: 扩展 (动态处理数据)**
    - **动态内存**：`malloc`, `free`, `realloc`，构建动态数组。
    - **文件 I/O**：`FILE*`, `fopen`, `fprintf`, `fread`，数据持久化。
    - **链表**：`struct Node`，融合了结构体、指针、`malloc` 的终极数据结构。

  - **`Ch 10`: 辅助 (编译的魔法)**
    - **预处理器**：`#include`, `#define`, `#ifndef`，编译前的文本替换。

你已经把 C 语言遗忘的知识点重新串联起来了。你现在不仅“会用” C 语言，而且对**内存、编译、工程化**都有了更深的理解。

#### 二、下一步：从 C 走向 C++ 与机器人

我记得你的目标是 C++ 和机器人领域。这次 C 语言复习为你打下了**最坚实**的基础：

  - **(1) 奔向 C++**
    - 你之前提到翁恺老师的 C++ 课程，这是**完美的下一步**。
    - 你会发现 C++ 一开始就是 C 的“超集”。你学过的**所有 C 语法**（指针、`struct`、`for` 循环、`Makefile`）在 C++ 中**几乎完全通用**。
    - C++ 将带给你：
      - **类 (Class)**：`struct` 的终极进化，将“数据”（成员变量）和“操作”（成员函数）真正封装在一起。
      - **RAII (资源获取即初始化)**：`new`/`delete` 将取代 `malloc`/`free`，`string` 和 `vector` 将让你摆脱手动管理动态数组和字符串的痛苦。
      - **STL (标准模板库)**：更强大的“数据结构工具箱”，`std::vector` (动态数组), `std::list` (链表), `std::map` (字典) 等。

  - **(2) 深入机器人/无人机领域**
    - 你感兴趣的领域（机器人、无人机控制、强化学习）是 C++ 的“主场”。
    - **硬件层**：底层的飞控、嵌入式系统、传感器驱动，大量使用 C 语言（因为高效、直接）。你复习的**位运算 (Ch 9)** 和**指针 (Ch 6)** 在这里至关重要。
    - **算法与框架层**：
      - **ROS (机器人操作系统)**：几乎完全基于 C++。
      - **高效率算法**：SLAM（即时定位与地图构建）、运动规划、控制算法，为了追求实时性能，几乎全部用 C++ 实现。
      - **机器学习**：虽然你用 Python 训练模型，但 TensorFlow、PyTorch 这类框架的**核心计算引擎**，都是用 C++ 和 CUDA（类 C 语言）编写的。

#### 三、总结

祝贺你完成了 C 语言的系统性复习！这门语言古老而强大，它是你理解计算机“如何工作”的最佳钥匙。

你现在已经拿到了钥匙，并且明确了要去打开“C++”和“机器人”这两扇大门。接下来的路会更有挑战性，但你已经做好了万全的准备。

**记住，编程的唯一秘诀是“多写多练” (Practice)。**

继续加油！很高兴能陪你走完这段复C之旅。