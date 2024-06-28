#include <stdio.h>
#include <string.h>
/*
定义一个函数指针变量，指向一个函数返回值类型是void *,
形参类型有两个，一个是字符数组指针类型，一个是字符数组首元素指针类型
*/
/* void *fun(char (*str1)[], char *str2);
void *fun(char (*str1)[], char *str2)
{
} */

/*
定义一个函数指针变量，指向一个函数返回值类型是void *,
形参类型有两个，一个是整形数组指针类型，一个是整形数组首元素指针类型
*/
void *(*fun)(int (*str1)[], int *str2);

void *fun_p(int (*str1)[], int *str2)
{
    printf("1234 ");
}
int main()
{
    int arr[] = {1234};
    fun_p(&arr, arr);

    return 0;
}