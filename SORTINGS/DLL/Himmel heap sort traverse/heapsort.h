/* ===============================================================================
 FILE     	 : heapsort.h
 AUTHORS     : himmel
 DESCRIPTION : Header files for heapsort.c
 COPYRIGHT   : 16 March 2021
 =============================================================================== */

#ifndef HEAP_SORT
#define HEAP_SORT

//Function prototypes
void heapSort(LIST *L);
void reheapUp(LIST *L, NODE *walker, int index);
void reheapDown(LIST *L, NODE *last);

#endif
