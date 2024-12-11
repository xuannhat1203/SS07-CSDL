#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct Node {
    char data[100];
    int level;
} Node;

typedef struct Queue {
    Node array[MAX]; // M?ng ch?a các Node
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

void enqueue(Queue* queue, char data[100], int level) {
    if (isFull(queue)) {
        printf("Hang doi day\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear++;
    strcpy(queue->array[queue->rear].data, data);
    queue->array[queue->rear].level = level;
    for (int i = queue->rear; i > queue->front; i--) {
        if (queue->array[i].level < queue->array[i - 1].level) {
            Node temp = queue->array[i];
            queue->array[i] = queue->array[i - 1];
            queue->array[i - 1] = temp;
        }
    }
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong\n");
        return;
    }
    printf("Phan tu uu tien nhat: %s\n", queue->array[queue->front].data);
    queue->front++;
    if (queue->front > queue->rear) { 
        queue->front = -1;
        queue->rear = -1;
    }
}

void pickQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong\n");
        return;
    }
    printf("Phan tu dau tien: %s\n", queue->array[queue->front].data);
}

void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong\n");
        return;
    }
    printf("Cac phan tu trong hang doi: ");
    for (int i = queue->front; i <= queue->rear; i++) { 
        printf("%s (level: %d) ", queue->array[i].data, queue->array[i].level);
    }
    printf("\n");
}

int main() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    initialQueue(queue);

    char data[100];
    int level;
    int n;

    printf("Nhap kich thuoc hang doi: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap du lieu moi: ");
        scanf("%s", data);
        printf("Nhap do uu tien: ");
        scanf("%d", &level);
        enqueue(queue, data, level);
    }

    dequeue(queue);
    pickQueue(queue);
    printQueue(queue);

    free(queue);
    return 0;
}

