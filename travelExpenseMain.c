#include <stdio.h>
#include <stdlib.h>
#include "expenses.h"
#include "travelFees.h"
#include "milesDrivenLodgingParking.h"
/*
void test(int expected, int actual, const char* testName) {
    if(expected == actual) {
        printf("\n%s PASSED", testName);
    }
}
*/
int main(void)
{
    
    int numberOfDays;
    int departure, arrival;
    double hourTotal;
    do {
        printf("\t==========================\n");
        printf("\tTRAVEL EXPENSE CALCULATION\n");
        printf("\t==========================\n");
        printf("\nTotal Number of Days spent excluding Deperture and Arrival Days: ");
        scanf("%d", &numberOfDays);
        printf("Time of Deperture-in military time & HHMM format: ");
        scanf("%d", &departure);
        
        printf("Time of Arrival-in military time & HHMM format  : ");
        scanf("%d", &arrival);
        if(arrival > 2400 || departure > 2400) {
            printf("Invlid Time Entry in Arrival or Deperture Time! Try Again!\n");
        }
    } while(arrival > 2400 || departure > 2400);

    printf("------------------------\n");
    printf("Total Days & Hours Spent\n");
    printf("------------------------\n");
    hourTotal = totalHours(departure, arrival, numberOfDays);
    printf("Total Hours spent on the Business Trip: %.02f Hours\n", hourTotal);
    convertDayAndHour(hourTotal);

    /* Allen's Implementation */
    double testAirfare = airfareAmount();
    double testCarRental = carRental();
    double testTaxi = taxiAmount();
    double totalMiles = milesDriven();
    double totalHotelExpense = hotelExpense(numberOfDays);
    double totalParkingFees = parkingFee(numberOfDays);
    double grandTotal = testAirfare + testCarRental+ testTaxi + totalMiles + totalHotelExpense + totalParkingFees;
    printf("\n\t============\n");
    printf("\tCost Summary\n");
    printf("\t============\n");
    printf("Airfare             : $ %.2lf\n", testAirfare);
    printf("Car Rental          : $ %.2lf\n", testCarRental);
    printf("Taxi Fares          : $ %.2lf\n", testTaxi);
    printf("Total Milages Driven: $ %.2lf\n", totalMiles);
    printf("Total Lodging Fees  : $ %.2lf\n", totalHotelExpense);
    printf("Taxi Parking Fees   : $ %.2lf\n", totalParkingFees);
    printf("----------------------------\n");
    printf("GRAND TOTAL EXPENSE : $ %.2lf\n", grandTotal);
    
    double hotelAllowance = (double)numberOfDays * 90.00;
    double parkingAllowance = (double)numberOfDays * 6.00;
    double totalMileDrivenAllowance = totalMiles;
    double totalAllowance = hotelAllowance + parkingAllowance+ totalMileDrivenAllowance+ testAirfare + testCarRental;
    printf("\n\t============\n");
    printf("\tTotal Allowance\n");
    printf("\t==============\n");
    printf("TOTAL ALLOWANCE : $ %.2lf\n", totalAllowance);
    printf("\n\t============\n");
    printf("\tTREIMBURSEMENT\n");
    printf("\t==============\n");
    printf("TOTAL REIMBURSEMENT : $ %.2lf\n", (grandTotal- totalAllowance));
    printf("\t==============\n");
    return EXIT_SUCCESS;
}
