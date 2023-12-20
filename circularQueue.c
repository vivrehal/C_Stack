#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
    int cap;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->cap;
}
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->data = (int*)malloc(sizeof(int) * k);
    obj->front = -1;
    obj->rear = -1;
    obj->size = 0;
    obj->cap = k;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(myCircularQueueIsFull(obj))return false;
    if(myCircularQueueIsEmpty(obj))obj->front=0;

    obj->rear=(obj->rear+1)%obj->cap;
    obj->data[obj->rear]=value;
    obj->size++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))return false;
    if(obj->rear==obj->front)obj->rear=-1, obj->front=-1;

    else obj->front=(obj->front+1)%obj->cap;
    obj->size--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    return myCircularQueueIsEmpty(obj) ? -1 : obj->data[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    return myCircularQueueIsEmpty(obj) ? -1 : obj->data[obj->rear];
}



void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
}