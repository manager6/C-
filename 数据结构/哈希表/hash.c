#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int key;   // 键
    int value; // 值

} HashNode;

// 哈希表结构
typedef struct
{
    int size;         // 哈希表大小
    HashNode **table; // 指向哈希表的指针
} MyHashSet;

MyHashSet *myHashSetCreate()
{
}

void myHashSetAdd(MyHashSet *obj, int key)
{
}

void myHashSetRemove(MyHashSet *obj, int key)
{
}

bool myHashSetContains(MyHashSet *obj, int key)
{
}

void myHashSetFree(MyHashSet *obj)
{
}

int main()
{

    return 0;
}