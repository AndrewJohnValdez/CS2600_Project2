/*
    This file is create by Allen Chiang
*/

#ifndef TRAVELFEES_H
#define TRAVELFEES_H
#include <stdlib.h>
#include <stdio.h>

extern int getAmount();                           // Allen's Function
extern double getTotal(double *cost, int length); // Allen's Function
extern double airfareAmount();                    // Allen's Function
extern double taxiAmount();                       // Allen's Function
extern double carRental();                        // Allen's Function

/* Allen's Implementation */

/* int getAmount(), function that gets user inputted trips or rentals planned as an int, for modifying code for unit testing and using in other functions */
int getAmount()
{
    double rentalTotalCost = 0;
    int amount = 1;                                                     // total rentals/trips made
    int numberRead = 0;                                                 // int for number read, set to 0 initially so while loop can run
    // ask user amount of rentals/trips made
    do                                                                  // do while loop for asking for number of trips/rentals planned, repeats question if a negative number or string/char is inputted
    {
        printf("Input the total amount of rentals/trips planned: ");
        numberRead = scanf("%d", &amount);                              // get user input, save in number read
        while (numberRead != 1)                                         // while loop, if numberRead is invalid, ask for user input again
        {
            printf("INVALID INPUT\n");
            scanf("%*[^\n]");                                           // catch strings and chars that may result in infinite loop or end program prematurely
            printf("Input the total amount of rentals/trips planned: ");
            numberRead = scanf("%d", &amount);
        }
        if (amount < 0)                                                 // check if amount is a negative, if so print invalid input
        {
            printf("INVALID INPUT\n");
        }
    } while (amount < 0);
    return amount;
}

/* getTotal function that adds up all the values in an array, for use in other functions and for unit testing */
double getTotal(double *cost, int length)
{
    double totalCost = 0;                                               // sum of all elements in an array to be returned later
    for (int i = 0; i < length; i++)
    {
        totalCost += cost[i];
    }
    return totalCost;
}

/* airfareAmount functon that asks user for amount of round-trip airfares made and its price and returns total cost of airfares */
double airfareAmount()
{
    printf("--------------------\n");
    printf("Round-Trip Airfares \n");
    printf("--------------------\n");
    double airfareTotalCost = 0;                                        // total cost of airfare trips to be returned later
    int airfareAmount = getAmount();                                    // get amount of airfare trips planned
    double totalCost[airfareAmount];                                    // create totalCost array of size airfareAmount for later calculations
    for (int i = 0; i < airfareAmount; i++)                             // for loop runs as many times as airfareAmount
    {
        double currentCost = 1;                                         // cost of current airfare
        double doubleRead = 0;                                          // double for double read, set to 0 for while loop will run
        do                                                              // do while loop for getting cost of current airfare cost, repeats question if negative number or string/char is inputted
        {
            printf("Input the cost of airfare trip %d: ", i + 1);
            doubleRead = scanf("%lf", &currentCost);                    // get user input double, save in double read
            while (doubleRead != 1)                                     // while loop, if doubleRead invalid, ask for user input again
            {
                printf("INVALID INPUT\n");
                scanf("%*[^\n]");                                       // catch strings and chars that may result in infinite loop or end program prematurely
                printf("Input the cost of airfare trip %d: ", i + 1);
                doubleRead = scanf("%lf", &currentCost);
            }
            if (currentCost < 0)
            {
                printf("INVALID INPUT\n");
            }
        } while (currentCost < 0);
        totalCost[i] = currentCost;                                     // adds current cost to totalCost array
    }
    airfareTotalCost += getTotal(totalCost, airfareAmount);             // adds elements of totalCost array into airfareTotalCost
    return airfareTotalCost;
}

// funcion that asks user for amount of days taxis are used and the cost of taxi use per day
// subtract the total cost of taxis by 10 * amount of days taxis are used to represent company allotted money
// if the final total cost is less than or equal to 0, return 0 as it is assumed company has covered all costs of taxi fares
// return final total cost of taxi fares of the trip
double taxiAmount()
{
    printf("----------\n");
    printf("Taxi Fares \n");
    printf("----------\n");
    double taxiTotalCost = 0;                                           // total cost of taxi fares to be returned later
    int taxiAmount = getAmount();                                       // get amount of taxi trip days planned
    double totalCost[taxiAmount];                                       // create totalCost array of size taxiAmount for later calculations
    for (int i = 0; i < taxiAmount; i++)                                // for loop runs as many times as taxiAmount
    {
        double currentCost = 1;                                         // cost of current day of taxi use
        double doubleRead = 0;                                          // double for double read, set to 0 for while loop will run
        do                                                              // do while loop for getting cost of current day of taxi use, repeats question if negative number or string/char is inputted
        {
            printf("Enter the cost of taxi fares of day %d (comapny covers $10.00 per day): ", i + 1);
            doubleRead = scanf("%lf", &currentCost);                    // get user input double, save in double read
            while (doubleRead != 1)                                     // while loop, if doubleRead invalid, ask for user input again
            {
                printf("INVALID INPUT\n");
                scanf("%*[^\n]");                                       // catch strings and chars that may result in infinite loop or end program prematurely
                printf("Input the cost of taxi fares of day %d (comapny covers $10.00 per day): ", i + 1);
                doubleRead = scanf("%lf", &currentCost);
            }
            if (currentCost < 0)                                        // checks if currentCost is negative, print invalid if so
            {
                printf("INVALID INPUT\n");
            }
        } while (currentCost < 0);
        totalCost[i] = currentCost;                                     // adds current cost to totalCost array
    }

    /* subtract total cost by 10*days to determine total cost of taxi fees in regards to the company allowed amount */
    taxiTotalCost = getTotal(totalCost, taxiAmount) - 10 * taxiAmount; // adds elements of totalCost array into TotalCost
    if (taxiTotalCost <= 0)                                            // if taxi total cost is negative or = 0, assumed company covered all taxi fees for the trip so return 0
    {
        return 0;
    }
    else
    {
        return taxiTotalCost;
    }
}

/*carRental functon that asks user for amount of car rentals made and its price and returns total cost of car rentals*/
double carRental()
{
    printf("------------\n");
    printf("Car Rentals \n");
    printf("------------\n");
    double carRentalTotalCost = 0;                                      // total cost of car rentals to be returned later
    int carRentalAmount = getAmount();                                  // get amount of car rentals planned
    double totalCost[carRentalAmount];                                  // create totalCost array of size carRentalAmount for later calculations
    for (int i = 0; i < carRentalAmount; i++)                           // for loop runs as many times as carRentalAmount
    {
        double currentCost = 1;                                         // cost of current car rental
        double doubleRead = 0;                                          // double for double read, set to 0 for while loop will run
        do                                                              // do while loop for getting cost of current car rental cost, repeats question if negative number or string/char is inputted
        {
            printf("Input the cost of car rental %d: ", i + 1);
            doubleRead = scanf("%lf", &currentCost);                    // get user input double, save in double read
            while (doubleRead != 1)                                     // while loop, if doubleRead invalid, ask for user input again
            {
                printf("INVALID INPUT\n");
                scanf("%*[^\n]");                                       // catch strings and chars that may result in infinite loop or end program prematurely
                printf("Input the cost of car rental %d: ", i + 1);
                doubleRead = scanf("%lf", &currentCost);
            }
            if (currentCost < 0)
            {
                printf("INVALID INPUT\n");
            }
        } while (currentCost < 0);
        totalCost[i] = currentCost;                                     // adds current cost to totalCost array
    }
    carRentalTotalCost += getTotal(totalCost, carRentalAmount);         // adds elements of totalCost array into TotalCost
    return carRentalTotalCost;
}

#endif // TRAVELFEES_H