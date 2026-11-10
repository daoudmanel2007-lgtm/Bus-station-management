#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include  "datastructure.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
//project introduction	
printf("\t \t \t \t  In the name of Allah the most gracious and the most merciful");
printf("\n \n \t \t \t \t \t \t  BUS STATION MANNAGEMENT");
printf("\n\n\n\n \t \t \t \t  UNIVERSITY OF SCIENCE AND TECHNOLOGY HOUARI BOUMEDIENNE USTHB");
printf("\n\t \t \t MAJOR: COMPUTER SCIENCE \t DEGREE: STATE ENGENEER \t year:2026/2027");
printf("\n\n \t created by the 31st team");
printf("\n from PRACTTICAL WORK GROUP 2     section A    2nd year");
printf("\n MEMBERS:");
printf("\n\tKhadidja Lebdi     252531427503");
printf("\n\tManel    Daoud     252532491918");
printf("\n\tLamia Racha Maatki 252531788303");
printf("\n\tMaroua   Djenah    252531637911");
 //begining of the app
 //variable boolean for exiting test
 bool exit=false;
 list* H=NULL;// the header of list 
do
{
printf("\n\n \n  \t YOU ARE WELCOME!");
printf("\n \n \n \t \t  MENU \n \n ");
printf("\n 1:ADD DEPARTURE \t 2:DELETE DEPARTURE \t 3:MODIFY A DEPARTURE TIME \t 4:SEARCH BY DESTINATION \t 5:RESERVE A SEAT \n 6:CANCEL RESERVATION \t 7:DISPLAY DEPARTURES \t 8:DISPLAY DEPARTURES BY TIME \t 9:DISPLAY STATICS \t 10:EXIT THE APPLICATION \n");
//choose of operation by user 
int choice;
printf("\n enter your choice \t");
scanf("%d",&choice);
while (choice<1 || choice>10){
	printf("you tap a non-existant option ! \n choose again from menu ");
    scanf("%d",&choice);
}
//verify if the manager really want to continue this operation

if(choice!=10){

int a;
	printf("\n Are you sure you want to continue this operation \t 1:yes   2:no ");
	scanf("%d",&a);
	while(a!=1 && a!=2){
	printf("\n 	TAPPING ERROR you chose non-existant option reenter your option \t ");
	scanf("%d",&a);
	}
	if(a==2){continue;}

}
	//in case confirmation
switch (choice){
    case 1 : printf("\n\n \t \t \t ADD DEPARTURE \n \n \n  ");AddDeparture(&H);break;
	case 2 : printf("\n\n \t \t \t DELETE DEPARTURE \n\n\n ");delet(&H);break;
	case 3 : printf("\n\n \t \t \t MODIFY A DEPARTURE TIME \n \n \n  ");ModifyDepartureTime(H);break;
	case 4 : printf("\n\n \t \t \t SEACH BY DESTINATION \n\n\n ");searchdest(H);break;
	case 5 : printf("\n\n \t \t \t RESERVE A SEAT\n \n\n");Reserve(H);break;
	case 6 : printf("\n\n \t \t \t CANCEL RESERVATION \n \n \n");Cancel(H);break;
	case 7 : printf("\n\n \t \t \t DISPLAY DEPARTURES \n \n \n");DisplayDepartures(H);break;
	case 8 : printf("\n\n \t \t \t DISPLAY DEPARTURES BY TIME\n \n \n ");DisplayByTime(H);break;
	case 9 : printf("\n\n \t \t \t DISPLAY STATICS \n \n \n ");DisplayStat(H);break;
	case 10 : printf("\n\n \t \t \t EXIT \n \n \n");ext(H,&exit);break;
}


}while(exit==false);


printf("\n\n\n \t \t WELCOME BACK ANY TIME ");

	return 0;
}
