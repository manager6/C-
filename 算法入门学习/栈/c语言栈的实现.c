#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100   // 定义栈的最大容量

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;  // 初始化栈顶指针为-1，表示初始为空栈
}

bool isEmpty(Stack *stack) {
    return stack->top == -1;  // 如果栈顶指针为-1，表示栈为空
}

bool isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;  // 如果栈顶指针等于最大容量减一，表示栈已满
}

void push(Stack *stack, int value) {
    if (!isFull(stack)) {
        stack->top++;
        stack->data[stack->top] = value;  // 将元素入栈
    } else {
        printf("栈已满，无法入栈\n");
    }
}

int pop(Stack *stack) {
    if (!isEmpty(stack)) {
        int value = stack->data[stack->top];  // 取出栈顶元素
        stack->top--;
        return value;
    } else {
        printf("栈为空，无法出栈\n");
        return -1;  // 如果栈为空，返回一个特定的值表示出错
    }
}

int top(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top];  // 返回栈顶元素的值，但不移除该元素
    } else {
        printf("栈为空，无栈顶元素\n");
        return -1;  // 如果栈为空，返回一个特定的值表示出错
    }
}

int main() {
    Stack stack;
    initialize(&stack);  // 初始化栈
    push(&stack, 5);  // 入栈
    push(&stack, 3);
    printf("%d\n", top(&stack));  // 输出栈顶元素的值
    printf("%d\n", pop(&stack));  // 出栈并输出出栈元素的值
    printf("%d\n", top(&stack));
    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));  // 尝试从空栈中出栈
    return 0;
}
