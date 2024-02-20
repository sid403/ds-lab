#define MAX_CALL 100 typedef struct { int *in; // Keep add new element into stack `in` int
*out; // While `out` is not empty the peek of the queue is the top of `out` int idx_in; //
Pointer points to the last element of array in int idx_out; // Pointer points to the last
element of array out
} MyQueue;
MyQueue* myQueueCreate() {
MyQueue *queue = (MyQueue *)malloc(sizeof(MyQueue)); if (queue ==
NULL) { return NULL;
}
queue->in = (int *)malloc(MAX_CALL * sizeof(int)); queue->out =
(int *)malloc(MAX_CALL * sizeof(int)); queue->idx_in = -1; queue-
>idx_out = -1; return queue;
}
void myQueuePush(MyQueue* obj, int x) { obj->in[++obj->idx_in] = x;
}
int myQueuePop(MyQueue* obj) { int front =
myQueuePeek(obj); if (front != -1) { obj-
>idx_out--;
}
return front;
}
int myQueuePeek(MyQueue* obj) { /* Find fill the out if it's
empty */ if (obj->idx_out < 0) { while (obj->idx_in >= 0) { obj-
>out[++obj->idx_out] = obj->in[obj->idx_in--];
}
}
return obj->idx_out < 0 ? -1 : obj->out[obj->idx_out];
}
bool myQueueEmpty(MyQueue* obj) { return obj->idx_in == -1 &&
obj->idx_out == -1;
}
void myQueueFree(MyQueue* obj) {
free(obj->in); free(obj->out);
free(obj);
}
