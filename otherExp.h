/*
    This File is created by Christian Anderson
*/


#include <stdlib.h>
#include <stdio.h>

extern int conferenceFee();
extern void getMealFees(double &, double, double &, double &, double&, double);

int conferenceFee()
{
    char user_choice;
    double fees;
    printf("Any conference or seminar registration fees? (Y/N): ");
    scanf("%c", user_choice);
    printf("\n");
    
    
    if (user_choice == 'Y' || user_choice == 'y')
    {
        printf("Enter the total conference or seminar registration fees: ");
        scanf("%.2lf", fees);

    }
    
    return fees;
}

void getMealFees(double &total_expenses, double departure_time, double &total_allowable_expenses, double &total_reimbursement, double &total_amount_saved, double arrival_time)
{
    const double ALLOWABLE_BREAKFAST = 9.00, ALLOWABLE_LUNCH = 12.00, ALLOWABLE_DINNER = 16.00;
    char user_choice;
    double meal_fee;

    printf("Did you eat a meal upon depature flight? (Y/N): ");
    scanf("%c", user_choice);
    printf("\n");

    if (user_choice == 'Y' || user_choice == 'y')
    {
        printf("How much was your meal? ");
        scanf("%.2lf", meal_fee);

        total_expenses += meal_fee;

        if(departure_time < 700)
        {
            total_allowable_expenses += ALLOWABLE_BREAKFAST;

            if (meal_fee > ALLOWABLE_BREAKFAST) // 11 > 9 = 2.00
                total_reimbursement += (meal_fee - ALLOWABLE_BREAKFAST);

            else if (meal_fee <= ALLOWABLE_BREAKFAST)
                total_amount_saved += meal_fee; // 8 < 9 
            
        }

        else if (departure_time >= 700 && departure_time < 1200)
        {
            total_allowable_expenses += ALLOWABLE_LUNCH;

            if (meal_fee > ALLOWABLE_LUNCH) // 13 > 12 = $1.00
                total_reimbursement += (meal_fee - ALLOWABLE_LUNCH);

            else if (meal_fee <= ALLOWABLE_LUNCH) // 3.00 > 12 =
                total_amount_saved += meal_fee;

        }

        else if (departure_time >= 1200 && departure_time < 1800)
        {
            total_allowable_expenses += ALLOWABLE_DINNER;

            if (meal_fee > ALLOWABLE_DINNER)
                total_reimbursement += (meal_fee - ALLOWABLE_DINNER);

            else if (meal_fee <= ALLOWABLE_DINNER)
                total_amount_saved += meal_fee;
        }

        else if (departure_time >= 18)
            total_reimbursement += meal_fee;

    }

    printf("Did you eat a meal when upon arrival flight? ");
    scanf("%c", user_choice);
    printf("\n");

    if (user_choice == 'Y' || user_choice == 'y')
    {
        printf("How much was your meal? ");
        scanf("%.2lf", meal_fee);
        printf("\n");

        total_expenses += meal_fee;

        if(arrival_time <= 800)
            total_reimbursement += meal_fee;

        else if(arrival_time > 800 && arrival_time <= 1300)
        {
            total_allowable_expenses += ALLOWABLE_BREAKFAST;

            if (meal_fee > ALLOWABLE_BREAKFAST)
                total_reimbursement += (meal_fee - ALLOWABLE_BREAKFAST);

            else if (meal_fee <= ALLOWABLE_BREAKFAST)
                total_amount_saved += meal_fee;
        }

        else if (arrival_time > 1300 && arrival_time <= 1900)
        {
            total_allowable_expenses += ALLOWABLE_LUNCH;

            if (meal_fee > ALLOWABLE_LUNCH) // 13.00 > 12.00 == 1.00
                total_reimbursement += (meal_fee - ALLOWABLE_LUNCH);

            else if (meal_fee <= ALLOWABLE_LUNCH)
                total_amount_saved += meal_fee; // 12.00 < n;
        }

        else if (arrival_time > 1900)
        {
            total_allowable_expenses += ALLOWABLE_DINNER;

            if (meal_fee > ALLOWABLE_DINNER)
                total_reimbursement += (meal_fee - ALLOWABLE_DINNER);

            else if (meal_fee <= ALLOWABLE_DINNER)
                total_amount_saved += meal_fee;
        }
    }

}