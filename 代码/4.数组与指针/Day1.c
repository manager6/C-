#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TARGET 12

void showDate(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int findMax()
{
    srand(time(NULL));
    int arr[10];
    int arrSize = sizeof(arr) / sizeof(int);
    int max = 0;
    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = rand() % 100;
    }
    printf("数组:");
    showDate(arr, arrSize);
    printf("最大值为:");
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void sortArr()
{
    srand(time(NULL));
    int arr[10];
    int arrSize = sizeof(arr) / sizeof(int);
    int max = 0;
    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = rand() % 100;
    }
    printf("未排序数组:");
    showDate(arr, arrSize);
    int temp = 0;
    // 冒泡排序 将 比当前位置大的元素和当前位置交换 直到没有比当前位置大的元素出现为止
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = i + 1; j < arrSize; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("排序后数组:");
    showDate(arr, arrSize);
}
void findLetter(char *str, int strSize)
{
    int low = 0;
    int sup = 0;
    int other = 0;

    for (int i = 0; i < strSize; i++)
    {
        str[i] = getchar();
    }
    for (int i = 0; i < strSize; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            low++;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            sup++;
        }
        else
        {
            other++;
        }
    }
    printf("大写:%d\n小写:%d\n其他:%d\n", sup, low, other);
}
// 返回 数组中和为 target 的数组元素下标
void findIndex(int *arr, int target, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = i + 1; j < arrSize - 1; j++)
        {
            if (arr[i] + arr[j] == target)
                printf("%d %d\n", i, j);
        }
    }
}
void replaceSpace(char *str)
{
    int spaceCount = 0;
    int strLength = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            spaceCount++;
        }
        strLength++;
    }

    int newLength = strLength + spaceCount * 2;

    str[newLength] = '\0';
    for (int i = strLength - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            str[newLength - 1] = '0';
            str[newLength - 2] = '2';
            str[newLength - 3] = '%';
            newLength -= 3;
        }
        else
        {
            str[newLength - 1] = str[i];
            newLength -= 1;
        }
    }
}
int main()
{
    // 查找最大元素
    //  printf("%d", findMax());
    //  printf("\n");

    // 计算大小写字母个数
    //  char str[10];
    //  int strSize = sizeof(str) / sizeof(char);
    //  findLetter(str, strSize);

    // 数组排序
    // sortArr();

    // 返回目标数和下标
    //  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //  int size = sizeof(arr) / sizeof(int);
    //  findIndex(arr, TARGET, size);

    // 替换字符
    char str[30] = "We are happy";
    replaceSpace(str);
    printf("%s\n", str);

    return 0;
}