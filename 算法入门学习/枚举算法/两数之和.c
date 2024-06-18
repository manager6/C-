#include <stdio.h>
#include <stdlib.h>
/*
1. 两数之和
提示
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。
示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1]
*/
int *sumOfTwoNumbers(int *nums, int numSize, int target)
{
    int *result = (int *)malloc(2 * sizeof(int));

    // 循环遍历数组 将和为目标值的下标返回
    for (int i = 0; i < numSize; i++)
    {
        for (int j = i + 1; j < numSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    free(result); // 释放空间
    return NULL;  // 没找到返回null
}
int main()
{
    int nums[4] = {2, 7, 11, 15};
    int target;
    int size = sizeof(nums) / sizeof(int);
    scanf("%d", &target);
    int *result = sumOfTwoNumbers(nums, size, target);
    if (result != NULL)
    {
        printf("[%d,%d]\n", result[0], result[1]);
        free(result); // 释放动态分配的内存
    }
    else
    {
        printf("not find!\n");
    }
    return 0;
}