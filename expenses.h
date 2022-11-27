#ifndef EXPENSES_H
#define EXPENSES_H
#include <stdlib.h>
#include <stdio.h>

extern double milageCalc(double);
extern double parkingFeesCalc(double);
extern double lodgingCalc(double);
extern double totalDaysCount(int);
extern int totalDaysCalc(int, int);
extern double totalHours(int, int, int);
extern double parkingFeesCalc(double);
extern void convertDayAndHour(double);

double totalHours(int deperture, int arrival, int days) 
{
    int depertureMinute;
    int depertureHour = (2400 - deperture) / 100;
    int convertMinute = deperture % 100;
    if(convertMinute == 0) {
        depertureMinute = 0;
    } else {
        depertureMinute = 60 - convertMinute;
    }
    
    printf("\nDepertureMinute: %d and DepertureHour %d\n", depertureMinute, depertureHour);
    double depertureDayHours = (double)(depertureHour + depertureMinute * 0.01);
    printf("deperture Day Hours: %.2f\n\n", depertureDayHours);
    int arrivalHour = arrival / 100;
    int arrivalMinute = arrival % 100;
    printf("arrivalMinute: %d and arrivalHour %d\n", arrivalMinute, arrivalHour);
    double arrivalDayHours = (double)(arrivalHour + arrivalMinute * 0.01);

    printf("Arrival Day Hours: %.2f\n\n", arrivalDayHours);
    int totalHours = arrivalHour + depertureHour;
    printf("Total Hours: %d\n", totalHours);
    if(totalHours >= 24) {
        days++;
        totalHours = totalHours - 24;
    }

    int totalMinute = arrivalMinute + depertureMinute;
    printf("Total Minutes: %d\n", totalMinute);
    if(totalMinute >= 60) {
       totalHours++; 
       totalMinute = totalMinute - 60;
    }

    double total = arrivalDayHours + depertureDayHours;
    
    printf("Arrival + Deperture = %.2f\n\n", total);
    return (days * 24.00) + totalHours + (totalMinute*0.01);
}

void convertDayAndHour(double hours)
{
    int totalDays = (int)hours / 24;
    double totalHours = hours - (double)(totalDays * 24);
    printf("Total Days: %d\nTotal Hours: %.2f\n", totalDays, totalHours);
}

#endif // EXPENSES_H