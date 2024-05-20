#ifndef SORT_H
#define SORT_H

#include "list.h"

void strandSort(LIST *data);
void printList(struct Node *node);
struct Node *strandSorter(struct Node *head);
struct Node *merge(struct Node **a, struct Node **b);

#endif  // SORT_H
