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
    printf("Total Number of Days spent excluding Deperture and Arrival Days: ");
    scanf("%d", &numberOfDays);
    printf("Time of Deperture-in military time & HH.MM format: ");
    scanf("%d", &departure);
    printf("Time of Arrival-in military time & HH.MM format: ");
    scanf("%d", &arrival);
    hourTotal = totalHours(departure, arrival, numberOfDays);
    printf("Total Hours spent on the Business Trip: %.02f Hours\n\n", hourTotal);
    convertDayAndHour(hourTotal);

    return EXIT_SUCCESS;
}
