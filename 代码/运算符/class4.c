#include <stdio.h>
#include <stdbool.h>
// 不使用逻辑运算符 判断字符为 大写或者小写
_Bool estimation(char ch)
{
    bool flag = true;

    if (ch >= 'A' ? (ch <= 'Z' ? true : false) : false == true) //三目运算符  表达式？结果1:结果2 表达式为真 输出结果1 为假 输出结果2
    {
        printf("%c为大写写字母\n", ch);
        return flag;
    }
    else if (ch >= 'a' ? (ch <= 'z' ? true : false) : false == true)
    {
        printf("%c为小写字母\n", ch);
        flag = false;
        return flag;
    }
}

int main()
{
    char ch;
    scanf("%c", &ch);
    estimation(ch);
    return 0;
}