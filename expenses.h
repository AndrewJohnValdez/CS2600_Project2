
#ifndef EXPENSES_H
#define EXPENSES_H

extern double milageCalc(double miles);
extern double parkingFeesCalc(double parking);
extern double lodgingCalc(double hotel);
extern double totalDaysCount(int days);
extern int totalDaysCalc(int deperture, int arrival);
extern int totalHours(int deperture, int arrival, int days);
extern double parkingFeesCalc(double par);

int totalHours(int deperture, int arrival, int days)
{
    int depertureDayHours = 2400 - deperture;
    return (days * 24) + (depertureDayHours / 100) + (arrival / 100);
}

#endif // EXPENSES_H