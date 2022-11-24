#include <stdlib.h>
#include <stdio.h>
#include "travelFees.h"
int main()
{
    printf("test\n");
    printf("airfare: %lf\n", airfareAmount());
    taxiAmount();
    carRental();
    return 0;
}