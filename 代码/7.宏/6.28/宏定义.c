#include <stdio.h>
#define OPEN 1

#ifdef OPEN
void printf_str();

void printf_str()
{
    printf("123\n");
}
#endif

int main()
{
    printf_str();
    return 0;
}