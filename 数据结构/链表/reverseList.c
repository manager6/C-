#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构
struct ListNode
{
    int val;
    struct ListNode *next;
};

// 创建新节点
struct ListNode *createNode(int val)
{
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (newNode)
    {
        newNode->val = val;
        newNode->next = NULL;
    }
    return newNode;
}

// 递归反转链表
struct ListNode *reverseListRecursive(struct ListNode *head)
{
    // 基本情况：如果链表为空或只有一个节点，直接返回头节点
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // 递归反转剩余部分
    struct ListNode *newHead = reverseListRecursive(head->next);

    // 将当前节点的下一个节点的next指针指向当前节点
    head->next->next = head;

    // 将当前节点的next指针设为NULL
    head->next = NULL;

    return newHead;
}

// 打印链表
void printList(struct ListNode *head)
{
    struct ListNode *temp = head;
    while (temp)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

// 释放链表
void freeList(struct ListNode *head)
{
    struct ListNode *temp;
    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    // 创建链表：1 -> 2 -> 3 -> 4 -> 5
    struct ListNode *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("原始链表：\n");
    printList(head);

    // 递归反转链表
    head = reverseListRecursive(head);

    printf("反转后的链表：\n");
    printList(head);

    // 释放链表内存
    freeList(head);

    return 0;
}
