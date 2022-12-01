#include <stdlib.h>
#include <stdio.h>
#include "../include/main.h"

// get the parking fee
double parkingFee(int days)
{
    double totalParkingExpense;
    do
    {
        printf("------------------------\n");
        printf("Parking Expense(If Any) \n");
        printf("------------------------\n");
        printf("Enter the parking fee: ");
        scanf("%lf", &totalParkingExpense);
        if (totalParkingExpense < 0)
        {
            printf("Invalid Input!");
        }
    } while (totalParkingExpense < 0);
    //return totalParkingExpense - (6 * days);
    return totalParkingExpense;
}

// get the hotel expenses
double hotelExpense(int days)
{
    double hotelTotalExpense;
    do
    {
        printf("-------------\n");
        printf("Hotel Expense \n");
        printf("-------------\n");
        printf("Enter the total Hotel expense: ");
        scanf("%lf", &hotelTotalExpense);
        if (hotelTotalExpense < 0)
        {
            printf("Invalid Input!");
        }
    } while (hotelExpense < 0);
    //return hotelTotalExpense - (days * 90);
    return hotelTotalExpense;
}

// get the car rent , if own vehicle get the miles driven
double milesDriven()
{
    double miles;
    do
    {
        printf("--------------------\n");
        printf("Miles Driven (If Any) \n");
        printf("--------------------\n");
        printf("Enter the miles driven: ");
        scanf("%lf", &miles);
        if (miles < 0)
        {
            printf("Invalid Input!");
        }
    } while (miles < 0);

    return miles * 0.27;
}
