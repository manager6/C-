#include <stdio.h>
#include <stdlib.h>

// 链表节点结构
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// 辅助函数：创建新节点
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 辅助函数：打印链表
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// TODO: 编写函数删除单链表中的重复节点
void removeDuplicates(struct Node *head)
{
    // 获取当前节点的值
    Node *current = head;

    while (current && current->next != NULL)
    {
        struct Node *runner = current;
        if (current->next->data == current->data)
        {
        }
    }
}

int main()
{
    // 创建链表 1 -> 2 -> 3 -> 2 -> 4 -> 3
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(3);

    printf("Original list: ");
    printList(head);

    // 调用删除重复节点的函数
    removeDuplicates(head);

    printf("List after removing duplicates: ");
    printList(head);

    return 0;
}
