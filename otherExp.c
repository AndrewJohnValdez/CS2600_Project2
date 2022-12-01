/*
    This File is created by Christian Anderson
*/


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 


extern double registrationFee();
extern double getMealFees();
extern double mealTotal;
extern double totalAllowance;
extern double totalReimbursement;
extern double totalAmountSaved;

/*
double mealTotal;
double totalAllowance;
double totalReimbursement;
double totalAmountSaved;
*/

double registrationFee()
{
    double fees = 3;

    printf("What is the Registration Fee: ");
    scanf("%lf", &fees);

    while (fees < 0) {
        printf("Invalid Entry, Please Try Again\n");
        scanf("%lf", &fees);
    }
    return fees;
}

double getMealFees(int departure_time, int arrival_time)
{
    const double ALLOWABLE_BREAKFAST = 9.00, ALLOWABLE_LUNCH = 12.00, ALLOWABLE_DINNER = 16.00;
    char user_choice, user_choice2;
    double meal_fee;

    mealTotal = 0;

    printf("departure time: %i\n", departure_time);
    printf("arrival time: %i\n", arrival_time);

    printf("Did you eat a meal upon depature flight? (Y/N): ");
    scanf(" %c", &user_choice);
    printf("\n");
    

    if (user_choice == 'Y' || user_choice == 'y')
    {
        printf("How much was your meal? :");
        scanf("%lf", &meal_fee);
        printf("\n");
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

    printf("Did you eat a meal when upon arrival flight? (Y|N): ");
    scanf(" %c", &user_choice2);
    printf("\n");

    printf("%c\n", user_choice2);
    if (user_choice2 == 'Y' || user_choice2 == 'y')
    {
        printf("How much was your meal? : ");
        scanf("%lf", &meal_fee);
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

/*
int main(){
    int dep = 600, arr = 1300;
    double fee;

    fee = registrationFee();
    printf("fee is: %.2lf\n", fee);
    getMealFees(dep, arr);
    printf("meal total: $%.2lf\n", mealTotal);
    printf("allowance total: $%.2lf\n", totalAllowance);
    printf("reimbursement total: $%.2lf\n", totalReimbursement);
    printf("amount saved: $%.2lf\n", totalAmountSaved);
    return 0;
}
*/