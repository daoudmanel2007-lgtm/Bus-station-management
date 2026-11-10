#include "datastructure.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
int ReadInt(const char message[]) {
    int x;
    printf("%s", message);
    scanf("%d", &x);
    while (getchar() != '\n');
    return x;
}

void ReadString(const char message[], char str[], int size) {
    printf("%s", message);
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}
/*---------------------------------------

    ADD A DEPARTURE

-----------------------------------------*/
void AddDeparture(list** H)
{
    list *Q;
    Departure D;

    do {
        D.number = ReadInt("Enter departure number: ");

        if (exist(*H, D.number) == true)
            printf("This departure number already exists! Enter another one.\n");

    } while (exist(*H, D.number) == true);
    
    ReadString("Enter destination: ", D.destination, sizeof(D.destination));
    



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


    //PRICE and FINANCE (added by Manel)
    do {
        printf("Enter ticket price: ");
        scanf("%f", &D.tickprice);
    } while (D.tickprice < 0);

    D.revenue = 0;
    D.nbsold = 0;



    Q = (list*)malloc(sizeof(list));
    if (Q == NULL) {
        printf("\t Memory allocation failed!\n");
        return;
    }
    Q->value = D;
    Q->next = *H;
    *H = Q;
    printf("\n \t Departure added successfully!\n");
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
        printf("\t The list is empty\n");
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
            printf("\n \t Departure time modified successfully\n");
        }
    }
}

/*------------------------------

    DELETE A DEPARATURE 

---------------------------------*/

void delet(list **H)
{
    int number;
    list *prev = NULL;
    list *cur = *H;

    if (*H == NULL) {
        printf("\t The list is empty.\n");
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
