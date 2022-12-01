/*
    This File is created by Andrew Valdez
*/

#include "../include/main.h"
#include <stdio.h>
#include <stdlib.h>

int main() //main should only hold values that must be inputted
{
    setTravelValues();
    setFareValues();
    displayResults();

    return EXIT_SUCCESS;
}

/*
    display totals:

    total days on trip
    departure time
    arrival time
    total expenses 
    total allowable expenses
    total reimbursement
    total amount saved
*/

void displayResults()
{
    printf("------------------------\n");
    printf("Total Days & Hours Spent\n");
    printf("------------------------\n");
    
    printf("Departure Time: %d\n", departure);
    printf("Arrival Time: %d\n", arrival);
    printf("Total Days spent on the Business Trip: %d\n", numberOfDays);
    printf("Total Hours spent on the Business Trip: %.02f Hours\n", hourTotal);
    convertDayAndHour(hourTotal);

    printf("\n\t============\n");
    printf("\tExpenses Summary\n");
    printf("\t============\n");
    printf("Airfare   : $ %.2lf\n", testAirfare);
    printf("Car Rental: $ %.2lf\n", testCarRental);
    printf("Taxi Fares: $ %.2lf\n", testTaxi);

    printf("Parking Fees:\n");
    printf("Miles Driven:\n");

    printf("Total Expenses: %.2lf\n", travelFeesTotal);
    printf("Total Allowable expenses for the trip:\n");
    printf("Excess that Must be Reimbursed:\n");
    printf("Amount Saved if expense were under the total allowed:\n");

/*
    Should display total expense incurred by the person
    total allowable expenses for the trip
    the excess that must be reimbursed by the businessperson if any
    the amount saved by the businessperson if the expenses were under the total allowed
*/
}

void setFareValues() {
    testAirfare = airfareAmount();
    testCarRental = carRental();
    testTaxi = taxiAmount();
}

void setTravelValues() {
    printf("\t==========================\n");
    printf("\tTRAVEL EXPENSE CALCULATION\n");
    printf("\t==========================\n");

    do {
        printf("\nTotal Number of Days spent excluding Deperture and Arrival Days: ");
        scanf("%d", &numberOfDays);
        if(numberOfDays < 1) {
            printf("Invalid Number of Days. Please Try Again.");
        }
    } while(numberOfDays < 1);

    do {
        printf("Time of Deperture-in military time & HHMM format: ");
        scanf("%d", &departure);
        
        printf("Time of Arrival-in military time & HHMM format  : ");
        scanf("%d", &arrival);
        if(arrival > 2400 || departure > 2400) {
            printf("Invalid Time Entry in Arrival or Deperture Time! Try Again!\n");
        }
    } while(arrival > 2400 || departure > 2400);

    hourTotal = totalHours(departure, arrival, numberOfDays);
}