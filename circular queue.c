#INCLUDE<STDIO.H>
typedef struct
{
int* queue;
int front;
int rear;
int size;
} MyCircularQueue;
bool myCircularQueueIsFull(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
MyCircularQueue* myCircularQueueCreate(int k)
{
MyCircularQueue* ans = malloc(sizeof(MyCircularQueue));
ans->queue = (int*)malloc((k+1) * sizeof(int));
ans->front = 0;
ans->rear = 0;
ans->size = k+1;
return ans;
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
if(myCircularQueueIsFull(obj))
return false;
else{
obj->queue[obj->rear] = value;
obj->rear = (obj->rear+1) % (obj->size);
return true;
}
}
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
if(myCircularQueueIsEmpty(obj))
return false;
else{
obj->front = (obj->front + 1)% obj->size;
return true;
}
}
int myCircularQueueFront(MyCircularQueue* obj)
{
if(myCircularQueueIsEmpty(obj))
return -1;
else
return obj->queue[obj->front];
}
int myCircularQueueRear(MyCircularQueue* obj)
{
if(myCircularQueueIsEmpty(obj))
return -1;
else
return obj->queue[(obj->rear-1+obj->size) % obj->size];
}
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
if((obj->front) == (obj->rear))
return true;
else
return false;
}
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
return ( (obj->rear + 1) % obj->size == obj->front);
}
void myCircularQueueFree(MyCircularQueue* obj)
{
free(obj->queue);
free(obj);
}
