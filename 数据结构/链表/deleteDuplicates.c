/*
给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。
示例 1：

输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]
*/
#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    // 如果链表有一个值 那么没有重复元素 直接返回
    if (!head || !head->next)
    {
        return head;
    }
    // 创建虚拟头节点 创建的节点指向原来的头节点
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;

    struct ListNode *prev = dummy;
    struct ListNode *curr = head;
    // 定义临时的值存储 当前节点的值 用来判断是否含有重复元素
    int tempValue;
    while (curr && curr->next)
    {
        if (curr->val == curr->next->val)
        {
            tempValue = curr->val;
            // 从头开始遍历链表 有和tempValue相等的值说明有重复元素
            while (curr && curr->next == tempValue)
            {
                // 将curr的值赋给temp
                struct ListNode *temp = curr;
                // 将curr下一个的值赋给curr  达到删除的效果
                curr = curr->next;
                free(temp);
            }
            // 更新前一个节点的next指向
            prev->next = curr;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}
