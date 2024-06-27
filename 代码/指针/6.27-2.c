#include <stdio.h>

int main()
{
    char *c_p_array[3] = {"hello", "world", "!"};

    for (int i = 0; i < sizeof(c_p_array) / sizeof(char *); i++)
    {
        printf("%s ", c_p_array[i]);
    }
    printf("\n");
    return 0;
}