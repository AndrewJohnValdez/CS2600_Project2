#include <stdlib.h>
#include <stdio.h>
#include "expenses.h"

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
    printf("Total hours spent on the Business Trip: %d Hours\n", totalHours(departure, arrival, numberOfDays));
    return EXIT_SUCCESS;
}
