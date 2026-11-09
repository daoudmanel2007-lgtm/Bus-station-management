#include "datastructure.h"
 
float GetDiscount(int category)
{
    if (category == 2)
        return 0.2;
    if (category == 3)
        return 0.5;
    return 0;
}
 
float CalculateTicketPrice(float basePrice, int category)
{
    return basePrice - basePrice * GetDiscount(category);
}
 
void PrintCategoryMenu()
{
    printf("\n1. Adult (no discount)\n");
    printf("2. Student (20%% discount)\n");
    printf("3. Child (50%% discount)\n");
}
 
int ReadCategory()
{
    int category;
 
    do {
        PrintCategoryMenu();
        printf("Choose category: ");
        scanf("%d", &category);
        if (category < 1 || category > 3)
            printf("Invalid category!\n");
    } while (category < 1 || category > 3);
 
    return category;
}
 
void PrintTicket(list* P, char name[], int category, float finalPrice)
{
    printf("\n_________ BUS TICKET __________\n");
    printf("Passenger: %s\n", name);
    printf("Bus number: %d\n", P->value.number);
    printf("Destination: %s\n", P->value.destination);
    printf("Departure time: %02d:%02d\n", P->value.departureTime.hour,
                                          P->value.departureTime.minute);
    if (category == 1)
        printf("Category: Adult\n");
    else if (category == 2)
        printf("Category: Student\n");
    else
        printf("Category: Child\n");
    printf("Original price: %.2f DA\n", P->value.tickprice);
    printf("Final price: %.2f DA\n", finalPrice);
    printf("________________________________\n");
}
 
void PrintRefund(float amount)
{
    printf("Refund: %.2f DA\n", amount);
}
 //search for a departure by its number
list* Search(list* H, int Num)
{
    list *P;
 
    P = H;
    while (P != NULL && P->value.number != Num) {
        P = P->next;
    }
    return P;
}
 //reserve a seat and get your price and print the ticket
void Reserve(list* H)
{
    list *P;
    int Num, category;
    char name[30];
    float price;
 
    if (H == NULL) {
        printf("The list is empty\n");
    }
    else {
        printf("Enter departure number: ");
        scanf("%d", &Num);
        P = Search(H, Num);
 
        if (P == NULL) {
            printf("Departure not found\n");
        }
        else if (P->value.availableSeats == 0) {
            printf("This bus is full!\n");
        }
        else {
            printf("Enter passenger name: ");
            scanf("%s", name);
            category = ReadCategory();
            price = CalculateTicketPrice(P->value.tickprice, category);
 
            P->value.availableSeats--;
            P->value.nbsold++;
            P->value.revenue = P->value.revenue + price;
 
            printf("\nReservation successful!\n");
            PrintTicket(P, name, category, price);
        }
    }
}
 //cancelling the reservation+ and get refund
void Cancel(list* H)
{
    list *P;
    int Num, category;
    float price;
 
    if (H == NULL) {
        printf("The list is empty\n");
    }
    else {
        printf("Enter departure number: ");
        scanf("%d", &Num);
        P = Search(H, Num);
 
        if (P == NULL) {
            printf("Departure not found\n");
        }
        else if (P->value.nbsold == 0) {
            printf("No reservation to cancel for this departure\n");
        }
        else {
            category = ReadCategory();
            price = CalculateTicketPrice(P->value.tickprice, category);
 
            P->value.availableSeats++;
            P->value.nbsold--;
            P->value.revenue = P->value.revenue - price;
 
            printf("Reservation cancelled!\n");
            PrintRefund(price);
        }
    }
}   