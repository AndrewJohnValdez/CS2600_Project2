#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "travelFees.h"

double airfareAmount()
{
    double airfareTotalCost = 0;
    int airfareTrips;
    //ask user for amount of times of round trip airfare
    while(1)
    {
        printf("Will there be any round-trip airfare? if so how many trips are planned?: \n");
        scanf("%d", &airfareTrips); //get user input int
        getchar(); //catch unwanted characters
        if(airfareTrips > 0)
        {
            break;
        }
        else
        {
            printf("INVALID INPUT\n");
        }
    }
    //use a loop to ask and add to a total to be returned as the total cost of airfare
    for(int i = 0; i < airfareTrips; i++)
    {
        double airfareCost = 0.0;
        while(1)
        {
            printf("Input the airfare cost of trip %d:\n", i+1);
            scanf("%lf", &airfareCost); //get user input int
            getchar(); //catch unwanted characters
            if(airfareCost > 0)
            {
                break;
            }
            else
            {
                printf("INVALID INPUT\n");
            }
        }
        airfareTotalCost += airfareCost;
    }
    printf("test airfare\n");
    return airfareTotalCost; 
}

double taxiAmount()
{
    //ask user for amount of days to determine company allowed amount
    //use a loop to ask and add to a total to be retuned as total cost of taxi fees
    //subtract total cost by 10*days to determine total cost of taxi fees in regards to the company allowed amount
    printf("test taxi\n");
    return 0.0;
}
double carRental()
{
    //ask user amount of car rentals made
    //use a loop to ask and add to a total to be returned as toatal cost of car rentals
    printf("test car rental\n");
    return 0.0;
}
    
    
