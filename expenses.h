#include <stdio.h>
#include <stddef.h>

double milageCalc(double miles);
double parkingFeesCalc(double parking);
double lodgingCalc(double hotel);
double totalDaysCount(int days);
int totalDaysCalc(int deperture, int arrival);

int totalHours(int deperture, int arrival, int days)
{
    int totalHours;
    int depertureDayHours = 2400 - deperture;
    return (days * 24) + (depertureDayHours / 100) + (arrival / 100);
}

double parkingFeesCalc(double par)

{
}