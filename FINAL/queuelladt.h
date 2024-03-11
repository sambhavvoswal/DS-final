#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    void *dp;
    struct node *next;
} NODE;

typedef struct 
{
    NODE *front, *rear;
    int count;
} QUEUE;

QUEUE *createqueue() {
    QUEUE *q;
    q = (QUEUE *)malloc(sizeof(QUEUE));
    if (q) {
        q->front = NULL;
        q->rear = NULL;
        q->count = 0;
    }
    return (q);
}

bool qempty(QUEUE *q) {
    return (q->count == 0);
}

bool qfull(QUEUE *q) {
    NODE *n;
    n = (NODE *)malloc(sizeof(NODE));
    if (n) {
        free(n);
        return false;
    }
    return true;
}

bool enqueue(QUEUE *q, void *din) {
    NODE *pnode;
    if (qfull(q))
        return false;
    pnode = (NODE *)malloc(sizeof(NODE));
    if (!pnode)
        return false;
    pnode->dp = din;
    pnode->next = NULL;
    if (qempty(q))
        q->front = pnode;
    else
        q->rear->next = pnode;
    q->rear = pnode;
    q->count++;
    return (true);
}

void *dequeue(QUEUE *q) {
    NODE *dnode;
    void *ddata;
    if (qempty(q))
        return NULL;
    dnode = q->front;
    if (q->count == 1)
        q->rear = NULL;
    q->front = dnode->next;
    ddata = dnode->dp;
    q->count--;
    free(dnode);
    return (ddata);
}

void *retrivefront(QUEUE *q) {
    if (qempty(q))
        return NULL;
    return (q->front->dp);
}

void *retriverear(QUEUE *q) {
    if (qempty(q))
        return NULL;
    return (q->rear->dp);
}

int qcount(QUEUE *q) {
    return (q->count);
}

void qdisplay(QUEUE *q) {
    NODE *temp;
    if (qempty(q)) {
        printf("queue is empty\n");
        return;
    }
    printf("contents of queue are:\n");
    for (temp = q->front; temp != NULL; temp = temp->next) {
        printf("%f\n", *(float *)temp->dp);
    }
}

bool qdestroy(QUEUE *q) {
    NODE *t, *pn;
    void *d;
    if (!q)
        return false;
    for (t = q->front; t != NULL;) {
        pn = t;
        d = pn->dp;
        t = t->next;
        free(d);
        free(pn);
    }
    free(q);
    return true;
}

