#include <stdio.h>
#include <stdlib.h>
/*
初始化空队列：创建一个空队列，定义队列的大小size，以及队头元素指针front，队尾指针rear。

判断队列是否为空：
当队列为空时，返回 True。当队列不为空时，返回 False。一般只用于「出队操作」和「获取队头元素操作」中。

判断队列是否已满：
当队列已满时，返回 True，当队列未满时，返回 False。一般只用于顺序队列中插入元素操作中。

插入元素（入队）：
相当于在线性表最后一个数据元素后面插入一个新的数据元素。并改变队尾指针 rear 的指向位置。

删除元素（出队）：
相当于在线性表中删除第一个数据元素。并改变队头指针 front 的指向位置。

获取队头元素：
相当于获取线性表中第一个数据元素。与插入元素（入队）、删除元素（出队）不同的是，该操作并不改变队头指针 front 的指向位置。

获取队尾元素：
相当于获取线性表中最后一个数据元素。与插入元素（入队）、删除元素（出队）不同的是，该操作并不改变队尾指针 rear 的指向位置。

接下来我们来看一下队列的顺序存储与链式存储两种不同的实现方式。

*/
// 使用链表创建队列
typedef struct QNode
{
    int data;
    struct QNode *next;
} QNode;

// 创建队列结构
typedef struct Queue
{
    struct QNode *front, *rear;
    int size;
} Queue;

//  初始化队列
Queue *initQueue()
{
    Queue *newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->size = 0;

    return newQueue;
}

// 判断队列是否为空
int isEmpty(Queue *obj)
{
    // 判断队列长度是否为0 为0返回 1 不为0返回 0
    return (obj->size == 0);
}
// 插入元素（入队）
void push(Queue *obj, int data)
{
    QNode *newQNode = (QNode *)malloc(sizeof(QNode));
    newQNode->data = data; // 将需要插入的数据赋值给新创建的节点
    newQNode->next = NULL;
    // 如果队列为空
    if (isEmpty(obj))
    {
        obj->front = newQNode; // 这个队列的首和尾都是插入的元素
        obj->rear = newQNode;
    }
    else
    {
        // 如果队列不为空
        obj->rear->next = newQNode;
        obj->rear = newQNode;
    }
    obj->size++;
}

// 删除元素（出队）
void pop(Queue *obj)
{
    // 将队首元素删除
    if (isEmpty(obj)) // 判断队列是否为空
    {
        perror("pop...");
        return;
    }
    QNode *temp = obj->front;
    obj->front = obj->front->next;
    free(temp);
    obj->size--;
}
// 获取队首元素
int peekFirst(Queue *obj)
{
    if (isEmpty(obj))
    {
        perror("peekFirst...");
        return -1;
    }
    return obj->front->data;
}

// 获取队尾元素
int peekLast(Queue *obj)
{
    if (isEmpty(obj))
    {
        perror("peekLast...");
        return -1;
    }
    return obj->rear->data;
}

int main()
{
    Queue *queue = initQueue();

    push(queue, 10);
    push(queue, 20);
    push(queue, 30);

    printf("队首元素: %d\n", peekFirst(queue)); // 输出 10
    printf("队尾元素: %d\n", peekLast(queue));  // 输出 30

    pop(queue);
    printf("队首元素: %d\n", peekFirst(queue)); // 输出 20

    pop(queue);
    printf("队首元素: %d\n", peekFirst(queue)); // 输出 30

    pop(queue);
    printf("队首元素: %d\n", peekFirst(queue)); // 输出 -1 (队列为空)
    return 0;
}