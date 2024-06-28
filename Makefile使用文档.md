# Makefile使用文档

### 1. 简介

`Makefile` 是一种自动化构建工具，用于在软件开发过程中管理项目的编译和构建过程。它通过定义一系列规则和依赖关系，自动化地执行编译、链接等任务，从而减少手动操作，提高开发效率。

### 2. Makefile 的基本结构

一个简单的 `Makefile` 的基本结构如下：

```
target: dependencies
    command
```

- `target`：要生成的文件或目标。
- `dependencies`：生成目标所依赖的文件或目标。
- `command`：生成目标所需要执行的命令。注意，命令前需要一个制表符（Tab）。

### 3. 示例

假设我们有以下简单的 C 程序文件：

- `main.c`
- `functions.c`
- `functions.h`

#### 文件内容

`main.c`:

```
#include <stdio.h>
#include "functions.h"

int main() {
    printf("Result: %d\n", add(2, 3));
    return 0;
}
```

`functions.c`:

```
#include "functions.h"

int add(int a, int b) {
    return a + b;
}
```

`functions.h`:

```
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int add(int a, int b);

#endif
```

#### Makefile

我们可以为这个程序创建一个简单的 `Makefile`：

```
# 定义编译器
CC = gcc

# 定义编译器选项
CFLAGS = -Wall -g

# 定义目标文件
TARGET = main

# 定义源文件
SRCS = main.c functions.c

# 定义生成的目标文件
OBJS = $(SRCS:.c=.o)

# 生成可执行文件的规则
$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 生成 .o 文件的规则
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

# 清理生成的文件
.PHONY: clean
clean:
    rm -f $(OBJS) $(TARGET)
```

### 4. 使用 `Makefile`

#### 4.1 生成目标

在终端中运行 `make`，`Makefile` 会根据定义的规则自动编译和链接程序。

```
sh
$ make
```

#### 4.2 清理目标

运行 `make clean`，`Makefile` 会删除所有生成的目标文件和可执行文件。

```
sh
$ make clean
```

### 5. 解释 `Makefile`

- `CC = gcc`：定义编译器为 `gcc`。
- `CFLAGS = -Wall -g`：定义编译选项，`-Wall` 表示启用所有警告，`-g` 表示生成调试信息。
- `TARGET = main`：定义最终生成的可执行文件名称。
- `SRCS = main.c functions.c`：定义源文件列表。
- `OBJS = $(SRCS:.c=.o)`：将源文件列表中的 `.c` 文件替换为 `.o` 文件，生成目标文件列表。
- `$(TARGET): $(OBJS)`：定义生成可执行文件的规则，依赖于目标文件列表。
- `%.o: %.c`：定义生成目标文件的规则，使用通配符模式匹配。
- `.PHONY: clean`：定义伪目标 `clean`，用于清理生成的文件。
- `clean`：定义清理规则，删除所有目标文件和可执行文件。

### 6. 高级用法

#### 6.1 自动变量

- `$@`：表示规则中的目标。
- `$<`：表示规则中的第一个依赖文件。
- `$^`：表示规则中的所有依赖文件。

#### 6.2 示例

```
# 生成 .o 文件的规则
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@
```

#### 6.3 使用变量

可以使用变量来简化 `Makefile`，例如：

```
# 定义源文件
SRCS = main.c functions.c

# 定义生成的目标文件
OBJS = $(SRCS:.c=.o)
```

### 7. 依赖管理

为了管理复杂的依赖关系，可以使用自动生成的依赖文件。

```
# 生成依赖文件
.deps: $(SRCS)
    $(CC) -MM $^ > .deps

# 包含依赖文件
-include .deps
```

### 8. 总结

`Makefile` 是一个强大的工具，可以大大简化项目的构建过程。通过定义规则和依赖关系，可以自动化编译、链接和清理任务。熟练掌握 `Makefile` 的使用，可以提高开发效率和代码管理能力。

### 9. 示例项目

假设你有一个项目目录结构如下：

```
project/
├── main.c
├── functions.c
├── functions.h
└── Makefile
```

在 `project` 目录下，创建一个名为 `Makefile` 的文件，并将以下内容粘贴进去：

```
CC = gcc
CFLAGS = -Wall -g
TARGET = main
SRCS = main.c functions.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
    rm -f $(OBJS) $(TARGET)
```

然后在终端中运行 `make` 命令来编译和链接程序，生成可执行文件 `main`。运行 `make clean` 命令来清理生成的目标文件。
