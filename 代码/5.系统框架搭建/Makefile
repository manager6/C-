# 编译器
CC = gcc

# 编译选项
CFLAGS = -Wall -Wextra -std=c11

# 目标文件
TARGET = my_program

# 源文件
SRCS = main.c example.c

# 目标
OBJS = $(SRCS:.c=.o)

# 规则：将目标文件与对象文件关联
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 规则：生成对象文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 规则：清理生成的文件
clean:
	rm -f $(TARGET) $(OBJS)

# 声明伪目标
.PHONY: clean

