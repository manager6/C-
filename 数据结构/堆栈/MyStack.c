#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 200
/*
初始化空栈：
创建一个空栈，定义栈的大小 size，以及栈顶元素指针top。

判断栈是否为空：
当堆栈为空时，返回True。当堆栈不为空时，返回False。一般只用于栈中删除操作和获取当前栈顶元素操作中。

判断栈是否已满：
当堆栈已满时，返回True，当堆栈未满时，返回False。一般只用于顺序栈中插入元素和获取当前栈顶元素操作中。

插入元素（进栈、入栈）：
相当于在线性表最后元素后面插入一个新的数据元素。并改变栈顶指针top 的指向位置。

删除元素（出栈、退栈）：
相当于在线性表最后元素后面删除最后一个数据元素。并改变栈顶指针top 的指向位置。

获取栈顶元素：
相当于获取线性表中最后一个数据元素。与插入元素、删除元素不同的是，该操作并不改变栈顶指针top 的指向位置。

*/

// 基于链表结构

// 创建栈节点数据
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 创建栈结构体
typedef struct MyStack
{
    Node *top;
    int size;
} MyStack;

// 初始化栈
MyStack *initStack()
{
    MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

// 判断栈是否为空
bool isEmpty(MyStack *stack)
{
    // 如果栈顶为-1 表示栈为空
    return stack->top == NULL;
}

// 插入元素（进栈、入栈）
void push(MyStack *stack, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

// 删除元素（出栈、退栈）
int pop(MyStack *stack)
{
    if (isEmpty(stack))
    {
        printf("栈已空 无法弹栈!");
        return -1;
    }
    Node *current = stack->top;
    int poppedData = current->data;
    stack->top = stack->top->next;
    free(current);
    stack->size--;
    return poppedData;
}

// 获取栈顶元素
int peek(MyStack *stack)
{
    if (isEmpty(stack))
    {
        printf("栈已空 无法获取栈顶元素!");
        return -1;
    }
    return stack->top->data;
}

/*
int isValid(char *s)
{
    int i = 0;
    Stack stack;
    initStack(&stack);

    while (s[i])
    {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
            push(&stack, s[i]);
        else if (s[i] == '}' || s[i] == ')' || s[i] == ']')
        {
            if (isEmpty(&stack))
                return 0;
            else if (!isMatchingPair(pop(&stack), s[i]))
                return 0;
        }
        i++;
    }

    return isEmpty(&stack);
}
*/

// 释放栈空间
void freeStack(MyStack *stack)
{
    while (isEmpty(stack))
    {
        pop(stack);
    }
    free(stack);
}

// 主函数
int main()
{
    MyStack *stack = initStack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("栈顶元素: %d\n", peek(stack)); // 输出 30
    printf("弹出元素: %d\n", pop(stack));  // 输出 30
    printf("弹出元素: %d\n", pop(stack));  // 输出 20
    printf("栈顶元素: %d\n", peek(stack)); // 输出 10

    freeStack(stack);
    return 0;
}