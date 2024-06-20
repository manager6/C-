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
    Node *head; // 表示指向头节点的指针
    int size;   // 链表的长度

} MyLinkedList;

// 初始化链表
MyLinkedList *myLinkedListCreate()
{
    // 动态内存分配
    MyLinkedList *obj = (MyLinkedList *)malloc(sizeof(MyLinkedList));
    // 使链表头为空，表示空链表
    obj->head = NULL;
    // 初始化链表节点数量为0
    obj->size = 0;
    // 返回指向新创建的链表指针
    return obj;
}

// 获取链表中与index匹配的值
int myLinkedListGet(MyLinkedList *obj, int index)
{
    // 如果下标 小于0或者大于链表的最大值 直接返回-1
    if (index < 0 || index >= obj->size)
        return -1;
    // 将curr的值设为链表的头节点
    Node *curr = obj->head;
    // 遍历链表 直到i=index-1 代表找到了链表中为下标index的值
    for (int i = 0; i < index; i++)
    {
        curr = curr->next;
    }
    // 返回curr的值
    return curr->val;
}

// 向链表的头节点位置添加元素
void myLinkedListAddAtHead(MyLinkedList *obj, int val)
{
    // 动态分配内存
    Node *newNode = (Node *)malloc(sizeof(Node));
    // 将需要插入的数据赋值给新创建的链表节点
    newNode->val = val;
    // 将新链表的下一个节点赋值为原来链表的头节点
    newNode->next = obj->head;
    // 将链表的头节点 赋值为新的链表节点
    obj->head = newNode;
    // 将链表长度增加
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList *obj, int val)
{
    // 动态内存分配
    Node *newNode = (Node *)malloc(sizeof(Node));
    // 将需要插入的数据赋值给新创建的链表节点
    newNode->val = val;
    // 将需要新节点的尾部指向NULL 表示新节点为尾节点
    newNode->next = NULL;
    // 如果链表为NULL 将链表头节点指向新创建的链表节点
    if (obj->head == NULL)
    {
        obj->head = newNode;
    }
    else
    {
        // 如果不为空 遍历到链表尾部
        Node *curr = obj->head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        // 然后将链表尾部的下一个节点赋值为新节点
        curr->next = newNode;
    }
    // 增加链表长度
    obj->size++;
}

// 往链表index处插入数据
void myLinkedListAddAtIndex(MyLinkedList *obj, int index, int val)
{
    // 如果index小于0或者大于链表最大长度 直接返回
    if (index < 0 || index > obj->size)
    {
        return;
    }
    // 如果index要插入在头部
    if (index == 0)
    {
        // 调用myLinkedListAddAtHead在头部添加节点
        myLinkedListAddAtHead(obj, val);
    }
    else if (index == obj->size)
    {
        // 调用myLinkedListAddAtTail在尾部添加节点
        myLinkedListAddAtTail(obj, val);
    }
    else
    {
        //  动态内存分配
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->val = val;
        // 获取链表头
        Node *curr = obj->head;
        // 循环遍历获取与index前一个节点
        for (int i = 0; i < index - 1; i++)
        {
            curr = curr->next;
        }
        // 将前一个节点的下一个节点赋值给新节点的下一个节点
        newNode->next = curr->next;
        // 将前一个节点的下一个节点 换成新创建的节点
        curr->next = newNode;
        // 链表长度增加
        obj->size++;
    }
}

// 删除链表中位置为index的数据
void myLinkedListDeleteAtIndex(MyLinkedList *obj, int index)
{
    // 如果index小于0或者大于链表最大长度 直接返回
    if (index < 0 || index >= obj->size)
    {
        return;
    }
    Node *temp;
    // 如果需要删除头节点 那么将头节点的下一个节点赋值给temp 将链表头节点赋值给下一个节点
    if (index == 0)
    {
        temp = obj->head;
        obj->head = obj->head->next;
    }
    else if (index == index)
    {
        // 如果需要删除尾节点 那么将尾节点的前一个节点的下一个节点赋值尾NULL
        Node *curr = obj->head;
        for (int i = 0; i < index - 1; i++)
        {
            curr = curr->next;
        }
        temp = curr->next;
        curr->next = temp->next;
    }
    // 释放删除数据的空间
    free(temp);
    // 链表长度减少
    obj->size--;
}

void myLinkedListFree(MyLinkedList *obj)
{
    Node *curr = obj->head;
    while (curr != NULL)
    {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(obj);
}

int main()
{

    return 0;
}