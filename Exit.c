#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include  "datastructure.h"


//last operation exit the app
void ext(list* L,bool* exit){
	//exit confirmation 
	int nb ;
	printf("\n Do you really want to exit the app \t 1:yes   2:no\n");
	scanf("%d",&nb);
	//handle choice inavaible
	while(nb!=1 && nb != 2){
	printf("\n This option does not exist choose \t 1:yes   2:no\n");
	scanf("%d",&nb);
	}
	
	
	if(nb==1){
		//sure exit 
		list* p;
		while(L!=NULL){
		p= (*L).next;
		free(L);
		L=p;
	    }
	L=NULL;
    *exit=true;
	}
	
}

