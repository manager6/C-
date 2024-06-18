#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define PASSWORD "123"
_Bool openBox(char *password)
{
    if (strcmp(password, PASSWORD) == 0)
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
    char pw[1024];
    while (1)
    {
        scanf("%s", pw);
        if (openBox(pw))
        {
            printf("密码正确！\n");
            break;
        }
        else
        {
            printf("密码错误！\n");
        }
    }
    return 0;
}