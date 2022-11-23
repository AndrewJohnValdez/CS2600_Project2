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
    printf("Total Number of Days spent withour arrival and deperture days: ");
    scanf("%d", &numberOfDays);
    printf("Time of deperture on the first day (in military time without ':':");
    scanf("%d", &departure);
    printf("Time of arrival on the last day in military time without ':':");
    scanf("%d", &arrival);
    int tHours = totalHours(departure, arrival, numberOfDays);
    printf("Total hours spent on the Business Trip: %d Hours\n", tHours);
    return EXIT_SUCCESS;
}
