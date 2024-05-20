#include "queue.h"

int main()
{
    queueHead *queue = malloc(sizeof(queueHead));
    queue->count = 0;
    queue->front = queue->rear = NULL;
    char str[20];

    for (;;)
    {
        
        printf("============================================\n");
        printf("STRING: ");
        fflush(stdin);
        gets(str);
        if(str == NULL)
        {
            exit(0);
        }
        int len = strlen(str);
        for (int i = 0; i < len; i++)
        {
            printf("| %c ", str[i]);
            enqueue(queue, str[i]);
        }
        printf("|");

        printf("\nQUEUE FRONT: %c\n", front(queue));
        printf("QUEUE REAR: %c\n", rear(queue));
        printf("LENGTH OF STRING: %d\n", len);
        printf("============================================\n");

        for(int i = 0; i < len; i++)
        {
            dequeue(queue);
        }
       
    }

    return 0;
}