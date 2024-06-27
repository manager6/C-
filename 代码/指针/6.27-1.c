#include <stdio.h>
#include <ctype.h>
int count(char *argv[])
{
    int count1 = 0; // 大写字母个数
    int count2 = 0; // 小写字母个数
    int i = 1;

    while (argv[i] != NULL)
    {
        int j = 0;
        while (argv[i][j] != '\0')
        {
            if (isupper(argv[i][j]))
            {
                count1++;
            }
            else if (islower(argv[i][j]))
            {
                count2++;
            }
            j++;
        }
        i++;
    }

    printf("大写字母个数: %d\n", count1);
    printf("小写字母个数: %d\n", count2);
    return count1 + count2;
}

int main(int argc, char *argv[])
{
    int result = count(argv);
    printf("总共:%d\n", result);
    return 0;
}