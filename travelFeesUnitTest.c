#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "expenses.h"
#include "travelFees.h"
int main()
{
    printf("Unit Test using different arrays to represent different user input:\n");
    double testArray1[3] = {2, 40, 2};
    int arrayLength1 = 3;
    double answer1 = 44;
    double Test1 = getTotal(testArray1, arrayLength1);
    assert(answer1 == Test1);
    printf("1: %.2lf\n", Test1);

    double testArray2[2] = {3.0,2.1};
    int arrayLength2 = 2;
    double answer2 = 5.100000;
    double Test2 = getTotal(testArray2, arrayLength2);
    assert(answer2 == Test2);
    printf("2: %.2lf\n", Test2);

    double testArray3[4] = {2.2, 2.4, 2.33, 4.55};
    int arrayLength3 = 4;
    double answer3 = 11.48;
    double Test3 = getTotal(testArray3, arrayLength3);
    assert(answer3 == Test3);
    printf("3: %.2lf\n", Test3);
    
    //FAILURE
    double testArray4[4] = {2.2, 2.4, 2.33, 4.55};
    int arrayLength4 = 5;
    double answer4 = 11.48;
    double Test4 = getTotal(testArray4, arrayLength4);
    assert(answer4 == Test4);
    printf("4: %.2lf\n", Test4);
    return 0;
}