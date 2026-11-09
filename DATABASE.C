#include "datastructure.h"

/*---------------------------------------

    ADD A DEPARTURE

-----------------------------------------*/

void AddDeparture(list** H)
{
    list *Q, *P;
    Departure D;
    int exists;

    /*--------------------------------------------------------------
    NOTE:WHEN KHADIDJA ADD THE EXIST FUNCTION I WILL CHANGE THIS PART 
    ---------------------------------------------------------------*/
    do {
        D.number = ReadInt("Enter departure number: ");
        P = *H;
        exists = 0;

        while (P != NULL) {
            if (P->value.number == D.number) {
                exists = 1;
                break;
            }
            P = P->next;
        }

        if (exists == 1)
            printf("This departure number already exists! Enter another one.\n");
    } while (exists == 1);

    ReadString("Enter destination: ", D.destination, sizeof(D.destination));
    /*  JUST HERE */



    do {
        D.departureTime.hour = ReadInt("Enter departure hour (0-23): ");
    } while (D.departureTime.hour < 0 || D.departureTime.hour > 23);

    do {
        D.departureTime.minute = ReadInt("Enter departure minute (0-59): ");
    } while (D.departureTime.minute < 0 || D.departureTime.minute > 59);

    do {
        D.busCapacity = ReadInt("Enter bus capacity: ");
    } while (D.busCapacity <= 0);

    do {
        D.availableSeats = ReadInt("Enter available seats: ");
    } while (D.availableSeats < 0 || D.availableSeats > D.busCapacity);

    Q = (list*)malloc(sizeof(list));
    if (Q == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    Q->value = D;
    Q->next = *H;
    *H = Q;
    printf("Departure added successfully!\n");
}

/*---------------------------------------

    MODIFY DEPARTURE TIME

-----------------------------------------*/

void ModifyDepartureTime(list* H)
{
    list *P;
    int Num;
    Time NewTime;

    if (H == NULL) {
        printf("The list is empty\n");
    }
    else {
        Num = ReadInt("Enter departure number: ");

        P = H;
        while (P != NULL && P->value.number != Num) {
            P = P->next;
        }

        if (P == NULL) {
            printf("Departure not found\n");
        }
        else {
            do {
                NewTime.hour = ReadInt("Enter new departure hour (0-23): ");
            } while (NewTime.hour < 0 || NewTime.hour > 23);

            do {
                NewTime.minute = ReadInt("Enter new departure minute (0-59): ");
            } while (NewTime.minute < 0 || NewTime.minute > 59);

            P->value.departureTime = NewTime;
            printf("Departure time modified successfully\n");
        }
    }
}


/* 2. Delete a departure */
void delet(list **H)
{
    int number;
    list *prev = NULL;
    list *cur = *H;

    if (*H == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Number of the departure to delete: ");
    scanf("%d", &number);

    /* look for the departure */
    while (cur != NULL && cur->value.number != number) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("Departure not found.\n");
        return;
    }

    /* delete it */
    if (prev == NULL) {
        *H = cur->next;               
    } else {
        prev->next = cur->next;          
    }
    free(cur);
    printf("Departure deleted.\n");
}
