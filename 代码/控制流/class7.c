#include <stdio.h>
#include <string.h>

#define PASSWORD 123

void openBox(int password)
{
    if (password == PASSWORD)
    {
        printf("输入成功！\n");
    }
    else
    {
        printf("密码错误或者账号错误！\n");
    }
}
int main()
{
    int password;
    scanf("%d", &password);

    openBox(password);
    return 0;
}