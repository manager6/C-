#include <stdio.h>

int myStrlen(char *str)
{
    int count = 0;
    while (str[count] != '\0')
    {
        count++;
    }
    return count;
}

// str1为复制后的数组  str2为复制数组
void myStrcpy(char *str1, char *str2)
{
    int count = 0;
    while (str2[count] != '\0')
    {
        str1[count] = str2[count];
        count++;
    }
    str1[count] = '\0';
}

int main()
{
    char str1[] = "abcd";
    char str2[5];
    int result = myStrlen(str1);
    printf("%d\n", result);
    myStrcpy(str2, str1);
    for (int i = 0; i < 4; i++)
    {
        printf("%c", str2[i]);
    }
    printf("\n");
    return 0;
}