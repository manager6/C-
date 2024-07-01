#include <stdio.h>
#include <stdlib.h>

// 定义树节点结构
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 创建新节点
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 定义队列节点结构
typedef struct QueueNode {
    TreeNode* treeNode;
    struct QueueNode* next;
} QueueNode;

// 定义队列结构
typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
} Queue;

// 创建一个新的队列
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// 队列是否为空
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// 入队操作
void enqueue(Queue* queue, TreeNode* treeNode) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    if (queue->rear != NULL) {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    if (queue->front == NULL) {
        queue->front = newNode;
    }
}

// 出队操作
TreeNode* dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        return NULL;
    }
    QueueNode* temp = queue->front;
    TreeNode* treeNode = temp->treeNode;
    queue->front = temp->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return treeNode;
}

// BFS 遍历
void bfs(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    Queue* queue = createQueue();
    enqueue(queue, root);
    while (!isEmpty(queue)) {
        TreeNode* current = dequeue(queue);
        printf("%d ", current->data);
        if (current->left != NULL) {
            enqueue(queue, current->left);
        }
        if (current->right != NULL) {
            enqueue(queue, current->right);
        }
    }
    free(queue);
}

// 查找节点
TreeNode* search(TreeNode* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    TreeNode* result = search(root->left, key);
    if (result != NULL) {
        return result;
    }
    return search(root->right, key);
}

// 插入节点
void insert(TreeNode** root, int data) {
    TreeNode* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }
    Queue* queue = createQueue();
    enqueue(queue, *root);
    while (!isEmpty(queue)) {
        TreeNode* current = dequeue(queue);
        if (current->left == NULL) {
            current->left = newNode;
            break;
        } else {
            enqueue(queue, current->left);
        }
        if (current->right == NULL) {
            current->right = newNode;
            break;
        } else {
            enqueue(queue, current->right);
        }
    }
    free(queue);
}

// 删除最深节点
void deleteDeepest(TreeNode* root, TreeNode* delNode) {
    Queue* queue = createQueue();
    enqueue(queue, root);
    TreeNode* temp;
    while (!isEmpty(queue)) {
        temp = dequeue(queue);
        if (temp == delNode) {
            temp = NULL;
            free(delNode);
            return;
        }
        if (temp->right != NULL) {
            if (temp->right == delNode) {
                temp->right = NULL;
                free(delNode);
                return;
            } else {
                enqueue(queue, temp->right);
            }
        }
        if (temp->left != NULL) {
            if (temp->left == delNode) {
                temp->left = NULL;
                free(delNode);
                return;
            } else {
                enqueue(queue, temp->left);
            }
        }
    }
    free(queue);
}

// 删除节点
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) {
            free(root);
            return NULL;
        } else {
            return root;
        }
    }
    Queue* queue = createQueue();
    enqueue(queue, root);
    TreeNode* temp;
    TreeNode* keyNode = NULL;
    while (!isEmpty(queue)) {
        temp = dequeue(queue);
        if (temp->data == key) {
            keyNode = temp;
        }
        if (temp->left != NULL) {
            enqueue(queue, temp->left);
        }
        if (temp->right != NULL) {
            enqueue(queue, temp->right);
        }
    }
    if (keyNode != NULL) {
        int x = temp->data;
        deleteDeepest(root, temp);
        keyNode->data = x;
    }
    free(queue);
    return root;
}

// 修改节点
void modify(TreeNode* root, int oldValue, int newValue) {
    TreeNode* node = search(root, oldValue);
    if (node != NULL) {
        node->data = newValue;
    }
}

// 主函数
int main() {
    TreeNode* root = NULL;
    insert(&root, 1);
    insert(&root, 2);
    insert(&root, 3);
    insert(&root, 4);
    insert(&root, 5);
    insert(&root, 6);
    insert(&root, 7);

    printf("BFS traversal before deletion: ");
    bfs(root);
    printf("\n");

    root = deleteNode(root, 4);

    printf("BFS traversal after deletion: ");
    bfs(root);
    printf("\n");

    modify(root, 3, 10);

    printf("BFS traversal after modification: ");
    bfs(root);
    printf("\n");

    return 0;
}
