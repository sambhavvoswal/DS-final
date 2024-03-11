#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queuelladt.h"

void printdata(void *dp)
{
    printf("%f\n", *(float *)dp);
}

int main() {

    int ch;
    float *dp;
    QUEUE *q;

    q = createqueue();
    if (!q) {
        printf("queue is not created\n");
        return 0;
    } else {
        printf("queue of float type is created successfully\n");
    }

    while (1) {
        printf("enter your choice:\n 1 to enqueue\n 2 to dequeue\n 3 to retrieve front \n 4 to retrieve rear \n 5 to display queue contents\n 6 to queue empty\n 7 to queue full\n 8 to count queue \n 9 to exit\n");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            dp = (float *)malloc(sizeof(float));
            if (!dp) {
                printf("memory allocation failed\n");
                return 0;
            } else {
                printf("enter the element to be inserted onto the queue\n");
                scanf("%f", dp);
                if (enqueue(q, dp))
                    printf("element inserted successfully\n");
                else
                    printf("element is not inserted successfully\n");
            }
            break;

        case 2:
            dp = (float *)dequeue(q);
            if (dp) {
                printf("deleted element:%f\n", *dp);
                free(dp);
            } else
                printf("queue is empty\n");
            break;

        case 3:
            dp = retrivefront(q);
            if (dp)
                printf("the front element on the queue:%f\n", *dp);
            else
                printf("queue is empty\n");
            break;

        case 4:
            dp = (float *)retriverear(q);
            if (dp)
                printf("the rear element on the queue:%f\n", *dp);
            else
                printf("queue is empty\n");
            break;

        case 5:
            printf("the queue contents are\n");
            qdisplay(q);
            break;

        case 6:
            if (qempty(q))
                printf("the queue is empty\n");
            else
                printf("the queue is not empty\n");
            break;

        case 7:
            if (qfull(q))
                printf("the queue is full\n");
            else
                printf("the queue is not full\n");
            break;

        case 8:
            printf("number of queue elements=%d\n", qcount(q));
            break;

        case 9:
            if (qdestroy(q))
                printf("Exit....\n");
            else
                printf("unsuccessful\n");
            return 0;

        default:
            printf("invalid choice\n");
        }
    }

    return 0;
}
