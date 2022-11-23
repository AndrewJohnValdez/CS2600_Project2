
#ifndef EXPENSES_H
#define EXPENSES_H
#include <stdlib.h>
#include <stdio.h>

extern double milageCalc(double miles);
extern double parkingFeesCalc(double parking);
extern double lodgingCalc(double hotel);
extern double totalDaysCount(int days);
extern int totalDaysCalc(int deperture, int arrival);
extern int totalHours(int deperture, int arrival, int days);
extern double parkingFeesCalc(double par);

int totalHours(int deperture, int arrival, int days)
{
    printf("Days %d\n", days);
    return (days * 24) + (deperture / 100) + (arrival / 100);
}

#endif // EXPENSES_H