#include <stdio.h>

// 创建结构体表示链表中的节点
typedef struct Node
{
    int val;           // 节点值
    struct Node *next; // 节点下一个节点
} Node;

// 创建链表结构体
typedef struct
{
    struct Node *head; // 定义链表头
    int size;          // 表示链表长度
} MyLinkedList;

// 初始化链表
MyLinkedList *myLinkedListCrate()
{
    // 动态分配空间
    MyLinkedList *obj = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    // 初始链表为空
    obj->head = NULL;
    // 链表长度为0
    obj->size = 0;
    return obj;
}

// 获取链表中与index匹配的值
int findOfList(MyLinkedList *obj, int index)
{
    // 如果index小于0 或者 大于链表的长度 则表示index输入有误
    if (index < 0 || index > obj->size)
    {
        return;
    }
    // 创建current获取链表头节点
    Node *current = obj->head;
    // 循环找到位置为index的链表节点
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->val;
}

// 在链表头插入数据
void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    // 创建一个新的node
    Node *newNode = (Node *)malloc(sizeof(Node *));
    newNode->val = val;
    obj->head = newNode;
    obj->size++;
}

// 在链表尾部插入数据
void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node *));
    newNode->val = val;

    newNode->next = NULL;
    // 获取头节点
    if (obj->size == 0)
    {
        obj->head = newNode;
    }
    else
    {
        Node *current = obj->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    obj->size++;
}

// 在链表index处插入数据
void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node *));
    newNode->val = val;

    if (index < 0 || index > obj->size)
    {
        return;
    }
    // 在链表头部插入数据
    if (index == 0)
    {
        myLinkedListAddAtHead(obj, val);
    }
    else if (index == obj->size)
    {
        // 在链表尾部插入数据
        myLinkedListAddAtTail(obj, val);
    }
    else
    {
        Node *current = obj->head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        obj->size++;
    }
}
struct ListNode *sortList(struct ListNode *head)
{
}

int main()
{

    return 0;
}