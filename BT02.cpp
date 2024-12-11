#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct Queue {
    int array[MAX];
    int front;
    int rear;
} Queue;

void initialQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(Queue* queue) {
    return queue->front == -1;
}

int isFull(Queue* queue) {
    return queue->rear >= MAX - 1;
}

void enqueue(Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Hang doi day\n");
        return; 
    }
    if (isEmpty(queue)) {
        queue->front = 0; 
    }
    queue->rear++;
    queue->array[queue->rear] = data; 
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong\n");
        return;
    }
    printf("Phan tu dau tien trong mang: %d\n", queue->array[queue->front]);
    queue->front++;
    if (queue->front > queue->rear) { 
        queue->front = -1;
        queue->rear = -1;
    }
}
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong\n");
        return;
    }
    printf("Cac phan tu trong hang doi: ");
    for (int i = queue->front; i <= queue->rear; i++) { 
        printf("%d ", queue->array[i]); 
    }
    printf("\n");
}
int main() {
    int choice, number;
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    initialQueue(queue);

    do {
        printf("\n----------MENU----------\n");
        printf("1. Them phan tu vao cuoi\n");
        printf("2. Xoa phan tu o dau\n");
        printf("3. In mang\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                printf("Nhap phan tu muon them: ");
                scanf("%d", &number);
                enqueue(queue, number);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                printQueue(queue);
                break;
            default: 
                printf("Lua chon khong hop le\n");
                break;
        }
    } while (1);

    return 0;
}

