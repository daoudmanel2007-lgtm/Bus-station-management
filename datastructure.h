// Prevent multiple inclusions of this header file ( neccesary )

#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#endif  // End of header guard