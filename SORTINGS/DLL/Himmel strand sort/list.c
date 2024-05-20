#include "list.h"


/*
 ==================================================================================
 FUNCTION        : displayList
 DESCRIPTION     : Displays the list containing the data.
 ARGUMENTS       : LIST *L - pointer to the LIST
 RETURNS         : void
 ==================================================================================
*/

void displayList(LIST *data)
{
    NODE *walker = data->head;

    if (walker == NULL)
    {
        printf("\n LIST IS EMPTY \n");
    }
    else
    {
        printf("\nLIST: [ ");
        while (walker)
        {
            printf("%d ", walker->x);
            walker = walker->n;
        }
        printf("]\n\n");
    }
}

/*
 ================================================================================
 FUNCTION        : createList
 DESCRIPTION     : Creates the list of data.
 ARGUMENTS       : 	LIST *L - pointer to the LIST
 					int ndata - the no. of data to be made in the LIST
 RETURNS         : void
 ================================================================================ 
*/

void createList(LIST *data, int Data)
{
    int i, n;

    if ((data->count) > 0)
    {
        destroyList(data);
    }

    srand((unsigned)time(NULL));

    for (i = 0; i < Data; i++)
    {
        n = rand() % 101;
        insertEnd(data, n);
    }
}

/*
 ================================================================================
 FUNCTION        : insertEnd
 DESCRIPTION     : Inserts a specific data at the end of the list.
 ARGUMENTS       : 	LIST *L - pointer to the LIST
 					int Data - the data to be added to the list
 RETURNS         : void
 ================================================================================ 
*/

void insertEnd(LIST *data, int Data)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->i = data->count;
    newNode->x = Data;
    newNode->n = NULL;
    newNode->p = NULL;

    if (data->count == 0)
    {
        data->head = newNode;
        data->tail = data->head;
    }
    else
    {
        data->tail->n = newNode;
        newNode->p = data->tail;
        data->tail = newNode;
    }
    (data->count)++;
}

/*
 ================================================================================
 FUNCTION        : destroyList
 DESCRIPTION     : Terminates the list.
 ARGUMENTS       : LIST *L - pointer to the LIST
 RETURNS         : void
 ================================================================================ 
*/

void destroyList(LIST *data)
{
    NODE *walker = data->tail;

    while (data->head != data->tail)
    {
        data->tail = data->tail->p;
        free(walker);
        walker = data->tail;
    }

    free(data->head);

    data->head = NULL;
    data->tail = NULL;
    data->count = 0;
}
