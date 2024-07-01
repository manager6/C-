#include <stdio.h>

struct Student
{
    char name[50];
    int age;
    float height;
} student1, student2;

int main()
{
    struct Student student1 =
        {
            .name = "Tom",
            .age = 22,
            .height = 1.7};
    student2 = student1;
    printf("%s %d %f\n", student2.name, student1.age, student1.height);
    return 0;
}