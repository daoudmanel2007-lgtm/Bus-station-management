// Prevent multiple inclusions of this header file ( neccesary )

#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H


#include <stdio.h>
#include <stdlib.h>

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

#endif  // End of header guard