#include <stdlib.h>
#include <stdio.h>

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
        scanf("%f", fees);

    }
    
    return fees;
}