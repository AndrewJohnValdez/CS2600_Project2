/*
    This File is created by Christian Anderson
*/


#include <stdlib.h>
#include <stdio.h>

extern double registrationFee();
extern double getMealFees();
extern double mealTotal;
extern double totalAllowance;
extern double totalReimbursement;
extern double totalAmountSaved;

double registrationFee()
{
    double fees;

    printf("What is the Registration Fee: ");
    scanf("%d", &fees);
    while (fees < 0) {
        printf("Invalid Entry, Please Try Again\n");
        scanf("%d", &fees);
    }
    
    return fees;
}

double getMealFees(int numberOfDays,int departure_time, int arrival_time)
{
    const double ALLOWABLE_BREAKFAST = 9.00, ALLOWABLE_LUNCH = 12.00, ALLOWABLE_DINNER = 16.00;
    char user_choice;
    double meal_fee;
    int key = -1;

    mealTotal = 0;

    do {
    printf("Did you eat a meal upon depature flight? (Y/N): ");
    scanf("%c", user_choice);
    if (user_choice == 'Y' || user_choice == 'y' || user_choice == 'N' || user_choice == 'n')
    {
        key = 1;
    } else {
        printf("Invald Input, Try Again\n");
        scanf("%c", user_choice);
    }
    } while(key != 1);
    printf("\n");

    if (user_choice == 'Y' || user_choice == 'y')
    {
        printf("How much was your meal? ");
        scanf("%.2lf", meal_fee);

        mealTotal += meal_fee;

        if(departure_time < 700)
        {
            totalAllowance += ALLOWABLE_BREAKFAST;

            if (meal_fee > ALLOWABLE_BREAKFAST) // 11 > 9 = 2.00
                totalReimbursement += (meal_fee - ALLOWABLE_BREAKFAST);

            else if (meal_fee <= ALLOWABLE_BREAKFAST)
                totalAmountSaved += meal_fee; // 8 < 9 
            
        }

        else if (departure_time >= 700 && departure_time < 1200)
        {
            totalAllowance += ALLOWABLE_LUNCH;

            if (meal_fee > ALLOWABLE_LUNCH) // 13 > 12 = $1.00
                totalReimbursement += (meal_fee - ALLOWABLE_LUNCH);

            else if (meal_fee <= ALLOWABLE_LUNCH) // 3.00 > 12 =
                totalAmountSaved += meal_fee;

        }

        else if (departure_time >= 1200 && departure_time < 1800)
        {
            totalAllowance += ALLOWABLE_DINNER;

            if (meal_fee > ALLOWABLE_DINNER)
                totalReimbursement += (meal_fee - ALLOWABLE_DINNER);

            else if (meal_fee <= ALLOWABLE_DINNER)
                totalAmountSaved += meal_fee;
        }

        else if (departure_time >= 1800)
            totalReimbursement += meal_fee;

    }

    printf("Did you eat a meal when upon arrival flight? ");
    scanf("%c", user_choice);
    printf("\n");

    if (user_choice == 'Y' || user_choice == 'y')
    {
        printf("How much was your meal? ");
        scanf("%.2lf", meal_fee);
        printf("\n");

        mealTotal += meal_fee;

        if(arrival_time <= 800)
            totalReimbursement += meal_fee;

        else if(arrival_time > 800 && arrival_time <= 1300)
        {
            totalAllowance += ALLOWABLE_BREAKFAST;

            if (meal_fee > ALLOWABLE_BREAKFAST)
                totalReimbursement += (meal_fee - ALLOWABLE_BREAKFAST);

            else if (meal_fee <= ALLOWABLE_BREAKFAST)
                totalAmountSaved += meal_fee;
        }

        else if (arrival_time > 1300 && arrival_time <= 1900)
        {
            totalAllowance += ALLOWABLE_LUNCH;

            if (meal_fee > ALLOWABLE_LUNCH) // 13.00 > 12.00 == 1.00
                totalReimbursement += (meal_fee - ALLOWABLE_LUNCH);

            else if (meal_fee <= ALLOWABLE_LUNCH)
                totalAmountSaved += meal_fee; // 12.00 < n;
        }

        else if (arrival_time > 1900)
        {
            totalAllowance += ALLOWABLE_DINNER;

            if (meal_fee > ALLOWABLE_DINNER)
                totalReimbursement += (meal_fee - ALLOWABLE_DINNER);

            else if (meal_fee <= ALLOWABLE_DINNER)
                totalAmountSaved += meal_fee;
        }
    }

}