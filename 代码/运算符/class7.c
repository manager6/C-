#include <stdio.h>
#include <stdbool.h>

_Bool judgmentYear(int year)
{
    if (year % 100 == 0 && year % 400 == 0)
    {
        printf("%d 是闰年\n", year);
        return true;
    }
    else if (year % 100 != 0 && year % 4 == 0)
    {
        printf("%d 是闰年\n", year);
        return true;
    }
    else
    {
        printf("%d 是平年\n", year);
        return false;
    }
}
int main()
{
    int year;
    scanf("%d", &year);
    char ch = judgmentYear(year);
    printf("%s\n", ch);
    return 0;
}