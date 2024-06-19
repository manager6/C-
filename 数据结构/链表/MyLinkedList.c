#include <stdio.h>
#include <stdlib.h>

// 定义一个结构体表示链表中的节点
typedef struct Node
{
    int val;           // 节点存储数据值
    struct Node *next; // 表示指向下一个节点的指针

} Node;

// 创建链表结构体
typedef struct
{

    struct Node *heard; // 表示指向头节点的指针
    int size;           // 链表的长度

} MyLinkedList;

// 初始化链表
MyLinkedList *myLinkedListCreate()
{
    // 动态内存分配
    MyLinkedList *obj = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    // 使链表头为空，表示空链表
    obj->heard = NULL;
    // 初始化链表节点数量为0
    obj->size = 0;
    // 返回指向新创建的链表指针
    return obj;
}

// 获取链表中与index匹配的值
int myLinkedListGet(MyLinkedList *obj, int index)
{
}

void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
}

void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
}

void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
}

void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
}

void myLinkedListFree(MyLinkedList *obj)
{
}

int main()
{

    return 0;
}