/*
    This File is created by Myo Muang
*/

#include "../include/main.h"
#include <stdlib.h>
#include <stdio.h>

double totalHours(int deperture, int arrival, int days)
{
    int depertureMinute;
    int depertureHour = (2400 - deperture) / 100;
    int convertMinute = deperture % 100;
    if (convertMinute == 0)
    {
        depertureMinute = 0;
    }
    else
    {
        depertureMinute = 60 - convertMinute;
    }

    double depertureDayHours = (double)(depertureHour + depertureMinute * 0.01);
    printf("Deperture Day's Work-Hours: %.2f Hours\n", depertureDayHours);
    int arrivalHour = arrival / 100;
    int arrivalMinute = arrival % 100;
    double arrivalDayHours = (double)(arrivalHour + arrivalMinute * 0.01);

    printf("Arrival Day's Work-Hours: %.2f Hours\n", arrivalDayHours);
    int totalHours = arrivalHour + depertureHour;
    if (totalHours >= 24)
    {
        days++;
        totalHours = totalHours - 24;
    }

    int totalMinute = arrivalMinute + depertureMinute;
    if (totalMinute >= 60)
    {
        totalHours++;
        totalMinute = totalMinute - 60;
    }

    double total = arrivalDayHours + depertureDayHours;

    return (days * 24.00) + totalHours + (totalMinute * 0.01);
}

void convertDayAndHour(double hours)
{
    int totalDays = (int)hours / 24;
    double totalHours = hours - (double)(totalDays * 24);

    printf("Which is converted into-\n");
    printf("Total Time Spent on Business Trip: %d Day(s) and %.2f Hour(s)\n", totalDays, totalHours);
}

void displayTotalTime(int deperture, int arrival, int numberOfDays) {

}
