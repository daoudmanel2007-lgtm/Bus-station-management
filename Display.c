#include "datastructure.h"
/*-------------------------------------------------

   DISPLAY BY TIME (Ascending and Descending order)

--------------------------------------------------*/

void DisplayByTime(list *H)
{
    list *Sorted = NULL, *P, *Q, *NewNode;
    Departure Temp;
    int choice1;

    if (H == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Choose sorting order:\n");
    printf("1. Ascending order\n");
    printf("2. Descending order\n");
    printf("Your choice: ");
    scanf("%d", &choice1);

    while (choice1 != 1 && choice1 != 2) {
        printf("Invalid choice! Enter 1 or 2: ");
        scanf("%d", &choice1);
    }

    /* Copy the original list */
    P = H;

    while (P != NULL) {
        NewNode = malloc(sizeof(list));

        if (NewNode == NULL) {
            printf("Memory allocation failed.\n");

            while (Sorted != NULL) {
                P = Sorted;
                Sorted = Sorted->next;
                free(P);
            }
            return;
        }

        NewNode->value = P->value;
        NewNode->next = NULL;

        if (Sorted == NULL) {
            Sorted = NewNode;
            Q = NewNode;
        }
        else {
            Q->next = NewNode;
            Q = NewNode;
        }

        P = P->next;
    }

    /* Sort the copied list */
    P = Sorted;

    while (P != NULL) {
        Q = P->next;

        while (Q != NULL) {

            if ((choice1 == 1 &&
                (P->value.departureTime.hour > Q->value.departureTime.hour ||
                (P->value.departureTime.hour == Q->value.departureTime.hour &&
                 P->value.departureTime.minute > Q->value.departureTime.minute)))

                ||

                (choice1 == 2 &&
                (P->value.departureTime.hour < Q->value.departureTime.hour ||
                (P->value.departureTime.hour == Q->value.departureTime.hour &&
                 P->value.departureTime.minute < Q->value.departureTime.minute))))
            {
                Temp = P->value;
                P->value = Q->value;
                Q->value = Temp;
            }

            Q = Q->next;
        }

        P = P->next;
    }

    /* Display the sorted list */
    printf("Sorted departures:\n");
    DisplayDepartures(Sorted);

    /* Free the copied list */
    while (Sorted != NULL) {
        P = Sorted;
        Sorted = Sorted->next;
        free(P);
    }
}

/*---------------------------------------

 DISPLAY ALL THE DEPARTURES (ONE FUNCTION)

-----------------------------------------*/

void DisplayDepartures(list *H)
{
    if (H == NULL) {
        printf("The list is empty.\n");
        return;
    }

    int choice;
    printf("\nChoose display order:\n");
    printf("1. Newest to Oldest\n");
    printf("2. Oldest to Newest\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Newest to Oldest: Normal traversal from Head
        list *P = H;
        while (P != NULL) {
            printf("\n-------------------------\n");
            printf("Departure number: %d\n", P->value.number);
            printf("Destination: %s\n", P->value.destination);
            printf("Departure time: %02d:%02d\n",
                   P->value.departureTime.hour,
                   P->value.departureTime.minute);
            printf("Bus capacity: %d\n", P->value.busCapacity);
            printf("Available seats: %d\n", P->value.availableSeats);
            P = P->next;
        }
    } 
    else if (choice == 2) {
        // Oldest to Newest: Count nodes and store pointers to print in reverse
        int count = 0;
        list *P = H;
        while (P != NULL) {
            count++;
            P = P->next;
        }

        list **arr = (list **)malloc(count * sizeof(list *));
        if (arr == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        P = H;
        for (int i = 0; i < count; i++) {
            arr[i] = P;
            P = P->next;
        }

        // Print backwards from last (oldest) to first (newest)
        for (int i = count - 1; i >= 0; i--) {
            printf("\n-------------------------\n");
            printf("Departure number: %d\n", arr[i]->value.number);
            printf("Destination: %s\n", arr[i]->value.destination);
            printf("Departure time: %02d:%02d\n",
                   arr[i]->value.departureTime.hour,
                   arr[i]->value.departureTime.minute);
            printf("Bus capacity: %d\n", arr[i]->value.busCapacity);
            printf("Available seats: %d\n", arr[i]->value.availableSeats);
        }

        free(arr);
    } 
    else {
        printf("Invalid choice!\n");
    }
}


void WriteDeparture(list *P)
{
    printf("\n------ DEPARTURE ------\n");
    printf("Number          : %d\n", P->value.number);
    printf("Destination     : %s\n", P->value.destination);
    printf("Time            : %02d:%02d\n", P->value.departureTime.hour,
                                            P->value.departureTime.minute);
    printf("Capacity        : %d\n", P->value.busCapacity);
    printf("Available seats : %d\n", P->value.availableSeats);
    printf("Ticket price    : %.2f DA\n", P->value.tickprice);
    printf("-----------------------\n");
}


void DisplayStat(list *H)
{
    list *P;
    int nbDep = 0, nbFull = 0, totalSold = 0, totalSeats = 0;
    float totalRevenue = 0;
 
    if (H == NULL) {
        printf("The list is empty.\n");
    }
    else {
        P = H;
        while (P != NULL) {
            nbDep++;
            totalSold    = totalSold + P->value.nbsold;
            totalSeats   = totalSeats + P->value.availableSeats;
            totalRevenue = totalRevenue + P->value.revenue;
            if (P->value.availableSeats == 0)
                nbFull++;
            P = P->next;
        }
 
        printf("\n~~~~~~~~ STATION STATISTICS ~~~~~~~~\n");
        printf("Total departures : %d\n", nbDep);
        printf("Full buses       : %d\n", nbFull);
        printf("Available seats  : %d\n", totalSeats);
        printf("Tickets sold     : %d\n", totalSold);
        printf("Total revenue    : %.2f DA\n", totalRevenue);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }
}
 