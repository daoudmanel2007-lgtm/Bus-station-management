//exist.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include  "data structure.h"

//this is a fuction to check if the elementr exist in the linked list 

bool exist(list* H, int number){
	
	//as the number of departement is unique we will check by using it 
	while(H!=NULL && (H->value.number)!=number){
		H=H->next;
	}
	if(H!=NULL){return true; 
	}
	return false;
	
}


