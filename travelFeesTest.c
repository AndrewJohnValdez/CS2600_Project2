#include <stdlib.h>
#include <stdio.h>
#include "travelFees.h"
int main()
{
    printf("testing and outputting functions:\n");
    double testAirfare = airfareAmount();
    double testCarRental = carRental();
    double testTaxi = taxiAmount();
    printf("Airfare: %lf\n", testAirfare);
    printf("Car Rental: %lf\n", testCarRental);
    printf("Taxi Fares: %lf\n", testTaxi);
    return 0;
}