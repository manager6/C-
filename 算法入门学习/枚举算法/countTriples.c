#include <stdio.h>
/*
一个 平方和三元组 (a,b,c) 指的是满足 a^2 + b^2 = c^2 的 整数 三元组 a，b 和 c 。
给你一个整数 n ，请你返回满足 1 <= a, b, c <= n 的 平方和三元组 的数目。

示例 1：
输入：n = 5
输出：2
解释：平方和三元组为 (3,4,5) 和 (4,3,5) 。

示例 2：
输入：n = 10
输出：4
解释：平方和三元组为 (3,4,5)，(4,3,5)，(6,8,10) 和 (8,6,10) 。
*/

int countTriples(int n)
{
    int count = 0;
    for (int a = 1; a < n; a++)
    {
        for (int b = 1; b < n; b++)
        {
            for (int c = 1; c < n; c++)
            {
                if (a * a + b * b == c * c)
                {
                    count++;
                }
            }
        }
    }
    return count;
}
int main()
{
    int result = countTriples(10);
    printf("%d\n", result);
    return 0;
}