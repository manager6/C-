#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define PASSWORD 123
_Bool openBox(int password)
{
    if (password == PASSWORD)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int pw;
    scanf("%d", &pw);
    if (openBox(pw))
    {
        printf("密码正确！\n");
    }
    else
    {

        printf("密码错误！\n");
    }
    return 0;
}