/*
    This File is created by Andrew Valdez
*/

#include <stdio.h>
#include <stdlib.h>
#include "expenses.h"
#include "travelFees.h"
#include "milesDrivenLodgingParking.h"

void displayResults(void);
void setTravelValues(void);
void setFareValues(void);

int numberOfDays; 
int departure, arrival;
double hourTotal;
double testAirfare;
double testCarRental;
double testTaxi;
double travelFeesTotal;
double totalMiles;
double totalHotelExpense;
double totalParkingFees;
double grandTotal;
double hotelAllowance;
double parkingAllowance;
double totalMileDrivenAllowance;
double totalAllowance;

int main(void) //main should only hold values that must be inputted
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

void displayResults(void)
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
    printf("Total Milages Driven: $ %.2lf\n", totalMiles);
    printf("Total Lodging Fees: $ %.2lf\n", totalHotelExpense);
    printf("Taxi Parking Fees: $ %.2lf\n", totalParkingFees);
    printf("Grand Total Expense: %.2lf\n", grandTotal);

    printf("\n\t===============\n");
    printf("\tTotal Allowance\n");
    printf("\t===============\n");
    printf("TOTAL ALLOWANCE : $ %.2lf\n", totalAllowance);
    printf("\n\t==============\n");
    printf("\tREIMBURSEMENT\n");
    printf("\t==============\n");
    printf("TOTAL REIMBURSEMENT : $ %.2lf\n", (grandTotal- totalAllowance));
    printf("\t==============\n");

    

/*
    Should display total expense incurred by the person
    total allowable expenses for the trip
    the excess that must be reimbursed by the businessperson if any
    the amount saved by the businessperson if the expenses were under the total allowed
*/
}

void setFareValues(void) {
    testAirfare = airfareAmount();
    testCarRental = carRental();
    testTaxi = taxiAmount();
    totalMiles = milesDriven();
    totalHotelExpense = hotelExpense(numberOfDays);
    totalParkingFees = parkingFee(numberOfDays);
    grandTotal = testAirfare + testCarRental + testTaxi + totalMiles + totalHotelExpense + totalParkingFees;

    hotelAllowance = (double)numberOfDays * 90.00;
    parkingAllowance = (double)numberOfDays * 6.00;
    double totalMileDrivenAllowance = totalMiles;
    double totalAllowance = hotelAllowance + parkingAllowance + totalMileDrivenAllowance + testAirfare + testCarRental;
}

void setTravelValues(void) {
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