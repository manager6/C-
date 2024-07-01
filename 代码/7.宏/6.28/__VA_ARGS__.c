#include <stdio.h>

#define PRINTF(format, ...) printf(format, __VA_ARGS__)

int main()
{
    PRINTF("Hello, %s!\n", "world");
    PRINTF("Number: %d, String: %s\n", 42, "example");
    return 0;
}
