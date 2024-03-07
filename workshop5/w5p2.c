/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
Full Name  :Ehimwenma Larry Okuonghae
Student ID#:145203238
Email      :elokuonghae@myseneca.ca
Section    :NGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define LOG_DAYS 3

int main(void)
{
    const int JAN = 1, DEC = 12;
    int loop = 1;
    int year, month, i;
    double morning_rating, evening_rating, morning_rating_sum = 0.0, evening_rating_sum = 0.0;
    
    printf("General Well-being Log\n");
    printf("======================\n");
    
    while (loop == 1)
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d",&year,&month);
        
        if (!(year >= MIN_YEAR && year <= MAX_YEAR))
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        
        if (!(month >= JAN && month <= DEC))
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        
        if ((year >= MIN_YEAR && year <= MAX_YEAR) && (month >= JAN && month <= DEC))
        {
            printf("\n");
            printf("*** Log date set! ***\n\n");
        
            for (i = 1; i <= LOG_DAYS; i++)
            {
                switch (month)
                {
                    case 1:
                        printf("%d-JAN-", year);
                        break;
                    case 2:
                        printf("%d-FEB-", year);
                        break;
                    case 3:
                        printf("%d-MAR-", year);
                        break;
                    case 4:
                        printf("%d-APR-", year);
                        break;
                    case 5:
                        printf("%d-MAY-", year);
                        break;
                    case 6:
                        printf("%d-JUN-", year);
                        break;
                    case 7:
                        printf("%d-JUL", year);
                        break;
                    case 8:
                        printf("%d-AUG-", year);
                        break;
                    case 9:
                        printf("%d-SEP-", year);
                        break;
                    case 10:
                        printf("%d-OCT-", year);
                        break;
                    case 11:
                        printf("%d-NOV-", year);
                        break;
                    case 12:
                        printf("%d-DEC-", year);
                        break;
                }
                if (i < 10)
                 {
                     printf("-0%d\n", i);
                 }
                 else
                 {
                     printf("-%d\n", i);
                 }
                
                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &morning_rating);
                
                              
                while (!(morning_rating >= 0.0 && morning_rating <= 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%lf", &morning_rating);
                }

                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &evening_rating);

                while (!(evening_rating >= 0.0 && evening_rating <= 5.0))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%lf", &evening_rating);
        
                    
                }
                morning_rating_sum += morning_rating;
                evening_rating_sum += evening_rating;
                printf("\n");

            }
            
            loop = 0;
        }
    }
    
    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating: %.3lf\n", morning_rating_sum);
    printf("Evening total rating:  %.3lf\n", evening_rating_sum);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n\n", morning_rating_sum + evening_rating_sum);
    printf("Average morning rating:  %.1lf\n", morning_rating_sum / LOG_DAYS);
    printf("Average evening rating:  %.1lf\n", evening_rating_sum / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating:  %.1lf\n", ((morning_rating_sum / LOG_DAYS) + (evening_rating_sum / LOG_DAYS))/2);

    return 0;
}


