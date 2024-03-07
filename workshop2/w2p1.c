/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
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
    const double TAX = 0.13;
    const char patSize = 'S';
    int numberSmall, subTotal, taxes, total;
    double Small, Medium, Large;
    
    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &Small);
    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &Medium);
    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &Large);
    printf("\n");
    printf("Shirt Store Price List\n");
    
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", Small);
    printf("MEDIUM : $%.2lf\n", Medium);
    printf("LARGE  : $%.2lf\n\n", Large);
    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numberSmall);
    printf("\n");
    printf("Patty's shopping cart...\n");
    printf("Contains : %d shirts\n", numberSmall);
    subTotal = (Small*100) * numberSmall;
    printf("Sub-total: $%8.4lf\n", (double)subTotal/100);
    taxes = subTotal * TAX + 0.5;
    printf("Taxes    : $%8.4lf\n", (double)taxes/100);
    total = subTotal + taxes;
    printf("Total    : $%8.4lf\n", (double)total/100);
    return 0;
    
    
}
