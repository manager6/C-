#include <stdio.h>
#include <stdlib.h>

// 定义链表节点的结构
struct Node
{
    int data;
    struct Node *next;
};

// 在链表末尾插入新节点
void appendNode(struct Node **headRef, int newData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *headRef;

    newNode->data = newData;
    newNode->next = NULL;

    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = newNode;
}

int main()
{
    struct Node *head = NULL;

    // 在链表末尾插入数据
    appendNode(&head, 6);
    appendNode(&head, 4);
    appendNode(&head, 8);

    // 打印链表中的数据
    struct Node *currentNode = head;
    printf("链表中的数据: ");
    while (currentNode != NULL)
    {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");

    return 0;
}
