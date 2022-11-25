#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "travelFees.h"

//int getAmount(), function that gets user inputted int, for modifying code for unit testing
//double** getCost(int amount), function that gets user inputted doubles and turns it into array, for modifying code for unit testing
//modify existing code airfareAmount, taxiAmount, and carRental, to take in double arrays
//airfareAmount functon that asks user for amount of round-trip airfares made and its price and returns total cost of airfares 
double airfareAmount()
{
    double airfareTotalCost = 0;
    int airfareTotal = 1; //total round-trip air fares made
    int numberRead = 0; //int for number read, set to 0 initially so while loop can run 
    //ask user for amount of round-trip airfare
    do //do while loop for asking for number of round-trip air fares made, repeats question if a negative number or string/char is inputted
    {
        printf("Will there be any round-trip airfare? if so how many trips are planned?: \n");
        numberRead = scanf("%d", &airfareTotal); //get user input, save in number read  
        while (numberRead != 1) //while loop, if numberRead is invalid, ask for user input again 
        {
            printf("INVALID INPUT\n");
            scanf("%*[^\n]"); //catch strings and chars that may result in infinite loop or end program prematurely 
            printf("Will there be any round-trip airfare? if so how many trips are planned?: \n");
            numberRead = scanf("%d", &airfareTotal);
        }
        if(airfareTotal < 0) //check if airfareTotal is a negative, if so print invalid input
        {
            printf("INVALID INPUT\n");
        }
    } while (airfareTotal < 0);
    //use a loop to ask and add to a total to be returned as the total cost of airfare
    for(int i = 0; i < airfareTotal; i++) //for loop runs as many times as amount of airfare
    {
        double airfareCost = 1; //cost of current airfare
        double doubleRead = 0; //double for double read, set to 0 for while loop will run
        do //do while loop for getting cost of current airfare cost, repeats question if negative number or string/char is inputted
        {
            printf("Input the airfare cost of trip %d:\n", i+1);
            doubleRead = scanf("%lf", &airfareCost); //get user input double, save in double read
            while (doubleRead != 1)//while loop, if doubleRead invalid, ask for user input again
            {
                printf("INVALID INPUT\n");
                scanf("%*[^\n]"); //catch strings and chars that may result in infinite loop or end program prematurely
                printf("Input the airfare cost of trip %d:\n", i+1);
                doubleRead = scanf("%lf", &airfareCost);
            }
            if(airfareCost < 0)
            {
                printf("INVALID INPUT\n");
            }
        } while (airfareCost < 0);
        airfareTotalCost += airfareCost;
    }
    return airfareTotalCost;
}

//funcion that asks user for amount of days taxis are used and the cost of taxi use per day
//subtract the total cost of taxis by 10 * amount of days taxis are used to represent company allotted money
    //if the final total cost is less than or equal to 0, return 0 as it is assumed company has covered all costs of taxi fares
    //return final total cost of taxi fares of the trip
double taxiAmount() 
{
    double taxiTotalCost = 0;
    int taxiDays = 1; //total days where taxis were used
    int numberRead = 0; //int for number read, set to 0 initially so while loop can run 
    //ask user for amount of days taxis were used to determine company allowed amount
    do //do while loop for asking for number of days taxis were used, repeats question if a negative number or string/char is inputted
    {
        printf("Will taxi services be used? If so how many days are planned? (company covers $10 per day): \n");
        numberRead = scanf("%d", &taxiDays); //get user input, save in number read  
        while (numberRead != 1) //while loop, if numberRead is invalid, ask for user input again 
        {
            printf("INVALID INPUT\n");
            scanf("%*[^\n]"); //catch strings and chars that may result in infinite loop or end program prematurely 
            printf("Will taxi services be used? If so how many days are planned? (company covers $10 per day): \n");
            numberRead = scanf("%d", &taxiDays);
        }
        if(taxiDays < 0) //check if taxiDays is a negative, if so print invalid input
        {
            printf("INVALID INPUT\n");
        }
    } while (taxiDays < 0);
    //use a loop to ask and add to a total to be returned as total cost of taxi fare
    for(int i = 0; i < taxiDays; i++) //for loop runs as many times as amount of days taxis were used
    {
        double taxiCost = 1; //cost of current day of taxi use
        double doubleRead = 0; //double for double read, set to 0 for while loop will run
        do //do while loop for getting cost of current taxi use day, repeats question if negative number or string/char is inputted
        {
            printf("Input the total taxi cost of day %d:\n", i+1);
            doubleRead = scanf("%lf", &taxiCost); //get user input double, save in double read
            while (doubleRead != 1)//while loop, if doubleRead invalid, ask for user input again
            {
                printf("INVALID INPUT\n");
                scanf("%*[^\n]"); //catch strings and chars that may result in infinite loop or end program prematurely
                printf("Input the total taxi cost of day %d:\n", i+1);
                doubleRead = scanf("%lf", &taxiCost);
            }
            if(taxiCost < 0)
            {
                printf("INVALID INPUT\n");
            }
        } while (taxiCost < 0);
        taxiTotalCost += taxiCost;
    }
    //subtract total cost by 10*days to determine total cost of taxi fees in regards to the company allowed amount
    taxiTotalCost -= 10*taxiDays;
    if(taxiTotalCost <= 0) //if taxi total cost is negative or = 0, assumed company covered all taxi fees for the trip so return 0
    {
        return 0;
    }
    else
    {
        return taxiTotalCost;
    }
}
//carRental functon that asks user for amount of car rentals made and its price and returns total cost of car rentals
double carRental()
{
    double rentalTotalCost = 0;
    int carRentals = 1; //total car rentals made
    int numberRead = 0; //int for number read, set to 0 initially so while loop can run 
    //ask user amount of car rentals made
    do //do while loop for asking for number of car rentals made, repeats question if a negative number or string/char is inputted
    {
        printf("Will there be any car rentals made? If so how many rentals are planned?: \n");
        numberRead = scanf("%d", &carRentals); //get user input, save in number read  
        while (numberRead != 1) //while loop, if numberRead is invalid, ask for user input again 
        {
            printf("INVALID INPUT\n");
            scanf("%*[^\n]"); //catch strings and chars that may result in infinite loop or end program prematurely 
            printf("Will there be any car rentals made? If so how many rentals are planned?: \n");
            numberRead = scanf("%d", &carRentals);
        }
        if(carRentals < 0) //check if carRentals is a negative, if so print invalid input
        {
            printf("INVALID INPUT\n");
        }
    } while (carRentals < 0);
    //use a loop to ask and add to a total to be returned as total cost of car rentals
    for(int i = 0; i < carRentals; i++) //for loop runs as many times as amount of car rentals
    {
        double rentalCost = 1; //cost of current car rental
        double doubleRead = 0; //double for double read, set to 0 for while loop will run
        do //do while loop for getting cost of current car rental, repeats question if negative number or string/char is inputted
        {
            printf("Input the car rental cost of rental %d:\n", i+1);
            doubleRead = scanf("%lf", &rentalCost); //get user input double, save in double read
            while (doubleRead != 1)//while loop, if doubleRead invalid, ask for user input again
            {
                printf("INVALID INPUT\n");
                scanf("%*[^\n]"); //catch strings and chars that may result in infinite loop or end program prematurely
                printf("Input the car rental cost of rental %d:\n", i+1);
                doubleRead = scanf("%lf", &rentalCost);
            }
            if(rentalCost < 0)
            {
                printf("INVALID INPUT\n");
            }
        } while (rentalCost < 0);
        rentalTotalCost += rentalCost;
    }
    return rentalTotalCost;
}
    
    
