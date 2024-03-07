/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

int main(void)
{
    char looptype;
    int number_of_interations, loop = 0;
    
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");
    
    while (loop == 0)
    {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &looptype, &number_of_interations);
        
        if ((looptype == 'D' || looptype == 'W' || looptype == 'F') && (number_of_interations < 3 || number_of_interations > 20))
        {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
        }
        
        else if (looptype == 'D' && (number_of_interations >=3 && number_of_interations <=20))
        {
            printf("DO-WHILE: ");
            do
            {
                printf("D");
                number_of_interations--;
            } while (number_of_interations > 0);
            
            printf("\n");
        }
        
        else if (looptype == 'W' && (number_of_interations >=3 && number_of_interations <=20))
        {
            printf("WHILE   : ");
            while (number_of_interations > 0)
            {
                printf("W");
                number_of_interations--;
            }
            printf("\n");
        }
        
        else if (looptype == 'F' && (number_of_interations >=3 && number_of_interations <=20))
        {
            printf("FOR     : ");
            for (number_of_interations = number_of_interations; number_of_interations > 0; number_of_interations--)
            {
                printf("F");
            }
            printf("\n");
        }
        else
        {
            if (looptype == 'Q')
            {
                if (number_of_interations == 0)
                {
                    loop--;
                }
                else
                {
                    printf("ERROR: To quit, the number of iterations should be 0!\n");
                }
            }
            else
            {
                printf("ERROR: Invalid entered value(s)!\n");
            }
        }
        printf("\n");
       
            
    }
    
    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");
    printf("\n");

    return 0;
}
