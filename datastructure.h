// Prevent multiple inclusions of this header file ( neccesary )

#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int hour;
    int minute;
} Time;

typedef struct {
    int number;
    char destination[50];
    Time departureTime;
    int busCapacity;
    int availableSeats;
    float tickprice;
    float revenue;
    int nbsold;

} Departure;

typedef struct list {
    Departure value;
    struct list* next;
} list;

int ReadInt(char message[]);
void ReadString(char message[], char str[], int size);

void AddDeparture(list **H);
void delet(list **H);
void ModifyDepartureTime(list *H);
void searchdest(list *H);
void Reserve(list *H);
void Cancel(list *H);
void DisplayDepartures(list *H);
void DisplayByTime(list *H);
void DisplayStat(list *H);
bool exist(list* H, int number);
void ext(list* L, bool* exit);


float GetDiscount(int category);
float CalculateTicketPrice(float basePrice, int category);
void PrintCategoryMenu(void);
int ReadCategory(void);
void PrintTicket(list* P, char name[], int category, float finalPrice);
void PrintRefund(float amount);
list* Search(list* H, int Num);



#endif  // End of header guard