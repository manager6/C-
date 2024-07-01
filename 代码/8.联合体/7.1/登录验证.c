#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define USER_NAME "tom"
#define USER_PASSWORD 123456

struct user
{
    char username[10];
    int password;
};

// 判断账号密码是否错误(登录判断)
bool Login(struct user new_user);

// 键盘输入账号密码
struct user User_info();

bool Login(struct user new_user)
{
    if (!(strcmp(new_user.username, USER_NAME)) && new_user.password == USER_PASSWORD)

        return true;
    else
        return false;
}

struct user User_info()
{
    struct user user1;
    scanf("%s", user1.username);
    scanf("%d", &user1.password);

    return user1;
}

int main()
{
    struct user user1 = User_info();
    if (Login(user1) == true)
        printf("登陆成功\n");
    else
        printf("登陆失败\n");
    return 0;
}