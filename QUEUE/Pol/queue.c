#include "queue.h"

void enqueue(queueHead *queue, char c)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->c = c;
    newNode->next = NULL;
    
    if(queue->front == NULL)
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->count++;
}
void dequeue(queueHead *queue)
{
    if(queue->front == NULL)
    {
        printf("There is no string inputted yet.\nError: Queue Underflow");
    }
    else
    {
        Node *temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
        queue->count--;
    }
}
char front(queueHead *queue)
{
    if(queue->front == NULL)
    {
        printf("There is no string inputted yet.\nError: Queue Underflow");
    }
    return queue->front->c;
}
char rear(queueHead *queue)
{
    if(queue->front == NULL)
    {
        printf("There is no string inputted yet.\nError: Queue Underflow");
    }
    return queue->rear->c;
}