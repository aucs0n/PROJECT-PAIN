#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include "list.h"
#include "heapsort.h"
#define TRUE	1
#define FALSE	0

//Function Prototype
void displayMenu();


int main() {
	
	char ch;
	bool start = FALSE;
	
	LIST *L = (LIST*)malloc(sizeof(LIST));
	L->head=NULL;
	L->tail=NULL;
	
	for(;;){
		displayMenu();
		ch=getche();
		
		switch(ch){
		case '1':
			createList(L);
			printf("\n---LIST CREATED---");
			start = TRUE;
			break;
		case '2':
			if(start){
				displayList(L);	
			}else{
				printf("\nPlease create list first");
			}
			break;
		case '3':
			if(start){
				heapSort(L);
			}else{
				printf("\nPlease create list first");
			}
			break;
		case '4':
			if(start){
				destroyList(L);
			}
			exit(0);
			break;
		}
		getch();
		system("cls");
	}
	return 0;
}


void displayMenu(){
	printf("[1]- Create List \n");
	printf("[2]- Display List \n");
	printf("[3]- Heap Sort \n");
	printf("[4]- Exit \n");
}
