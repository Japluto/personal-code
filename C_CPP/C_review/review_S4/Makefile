# Makefile

# --- 变量定义 (Variables) ---
# 这样做的好处是，以后想换编译器或加编译选项，只改这里就行。

# 编译器
CC = gcc

# 编译选项 (Flags)
# -Wall = 打开所有警告 (Write All Warnings)
# -g = 添加调试信息 (用于GDB调试)
# -Iinc = 告诉编译器去 inc 文件夹找头文件
CFLAGS = -Wall -g -Iinc

# 最终可执行文件的名字
TARGET = student_manager

# 所有的源文件 (.c)
# $(wildcard ...) 是 make 的一个函数，意思是“帮我找到所有 src 目录下的 .c 文件”
SRCS = $(wildcard src/*.c)

# 所有的目标文件 (.o)
# 这行命令的意思是：把 SRCS 变量里的所有 "src/xxx.c" 替换成 "xxx.o"
OBJS = $(SRCS:src/%.c=%.o)


# --- 规则定义 (Rules) ---

# 第一个规则是“默认规则”。当你在命令行只敲 "make" 时，它就会执行第一个规则。
# 我们让它默认去生成最终的可执行文件。
all: $(TARGET)

# 规则：如何生成最终的可执行文件 (TARGET)
# 依赖：所有的 .o 目标文件
$(TARGET): $(OBJS)
	# (Tab)链接命令：把所有 .o 文件链接起来
	$(CC) $(OBJS) -o $(TARGET)
	@echo "链接完成，生成可执行文件 -> $(TARGET)"

# 规则：如何从 .c 生成 .o (这是一个“模式规则”)
# %.o: src/%.c 的意思是：对于任何一个 xxx.o 文件，它都依赖于 src/xxx.c
%.o: src/%.c
	# (Tab)编译命令：
	# $< 代表第一个依赖 (即 src/%.c)
	# $@ 代表目标 (即 %.o)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "编译完成 -> $@"

# 规则：“清理”规则
# 这是一个“伪目标”(Phony Target)，因为它不真的生成叫 "clean" 的文件
.PHONY: clean
clean:
	# (Tab)删除所有 .o 文件和可执行文件
	rm -f $(TARGET) *.o
	@echo "清理完成。"