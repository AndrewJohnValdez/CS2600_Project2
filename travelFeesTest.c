#include <stdlib.h>
#include <stdio.h>
#include "travelFees.h"
int main()
{
    printf("testing and outputting functions:\n");
    double airfareTest = airfareAmount();
    double carRentalTest = carRental();
    double taxiAmountTest = taxiAmount();
    printf("airfare: %lf\n", airfareTest);
    printf("car rental: %lf\n", carRentalTest);
    printf("taxi amount: %lf\n", taxiAmountTest);
    return 0;
}