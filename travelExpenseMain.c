#include <stdio.h>
#include <stdlib.h>
#include "expenses.h"
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
    // printf("testing and outputting functions:\n");
    double testAirfare = airfareAmount();
    double testCarRental = carRental();
    double testTaxi = taxiAmount();
    printf("\n\t============\n");
    printf("\tCost Summary\n");
    printf("\t============\n");
    printf("Airfare   : $ %.2lf\n", testAirfare);
    printf("Car Rental: $ %.2lf\n", testCarRental);
    printf("Taxi Fares: $ %.2lf\n", testTaxi);
    return EXIT_SUCCESS;
}
