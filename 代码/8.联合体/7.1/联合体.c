#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
    char name[50];
    int age;
    float height;
};

int main()
{
    struct student *s1 = (struct student *)malloc(sizeof(struct student));
    strcpy(s1->name, "tom");
    s1->age = 20;
    s1->height = 1.7;

    printf("name:\t%s\nage:\t%d\nheight:\t%f\n", s1->name, s1->age, s1->height);
    free(s1);
    return 0;
}