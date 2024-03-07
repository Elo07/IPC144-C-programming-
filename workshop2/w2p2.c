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
    const char patSize = 'S', salSize = 'M', tomSize = 'L';
    int subTotal, subSmall, subMedium, subLarge, taxes, taxSmall, taxMedium, taxLarge, total, totalSmall, totalMedium, totalLarge, totalshirts;
    double Small, Medium, Large;
    int numberSmall, numberMedium, numberLarge;
    int toonies,loonies,quarters,dimes,nickels,pennies,var1,var2,tooniesremain,looniesremain,quartersremain,dimesremain,nickelsremain,penniesremain;
     
    
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
    printf("Tommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");
    scanf("%d", &numberLarge);
    printf("\n");
    printf("Sally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &numberMedium);
    printf("\n");
    subSmall = (int)(Small*100) * numberSmall;
    subMedium = (int)(Medium*100) * numberMedium;
    subLarge = (int)(Large*100) * numberLarge;
    subTotal = subSmall + subMedium + subLarge;
    taxSmall = subSmall * TAX + 0.5;
    taxMedium = subMedium * TAX + 0.5;
    taxLarge = subLarge * TAX + 0.5;
    taxes = taxSmall + taxMedium + taxLarge;
    totalSmall = (int)subSmall + taxSmall;
    totalMedium = (int)subMedium + taxMedium;
    totalLarge = (int)subLarge + taxLarge;
    total = totalSmall + totalMedium + totalLarge;
    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize,Small,numberSmall,(double)subSmall/100,(double)taxSmall/100,(double)totalSmall/100);
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize,Medium,numberMedium,(double)subMedium/100,(double)taxMedium/100,(double)totalMedium/100);
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize,Large,numberLarge,(double)subLarge/100,(double)taxLarge/100,(double)totalLarge/100);
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n",(double)subTotal/100, (double)taxes/100, (double)total/100);
    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");
    var1 = subTotal;
    toonies = var1 / 200;
    tooniesremain = var1 % 200;
    loonies = tooniesremain / 100;
    looniesremain = tooniesremain % 100;
    quarters = looniesremain / 25;
    quartersremain = looniesremain % 25;
    dimes = quartersremain / 10;
    dimesremain = quartersremain % 10;
    nickels = dimesremain / 5;
    nickelsremain = dimesremain % 5;
    pennies = nickelsremain / 1;
    penniesremain = nickelsremain % 1;
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n",(double)subTotal/100);
    printf("Toonies  %3d %9.4lf\n",toonies,(double)tooniesremain/100);
    printf("Loonies  %3d %9.4lf\n",loonies,(double)looniesremain/100);
    printf("Quarters %3d %9.4lf\n",quarters,(double)quartersremain/100);
    printf("Dimes    %3d %9.4lf\n",dimes,(double)dimesremain/100);
    printf("Nickels  %3d %9.4lf\n",nickels,(double)nickelsremain/100);
    printf("Pennies  %3d %9.4lf\n\n",pennies,(double)penniesremain/100);
    totalshirts = numberSmall + numberMedium + numberLarge;
    printf("Average cost/shirt: $%.4lf\n\n",((double)subTotal/totalshirts)/100);
    var2 = total;
    toonies = var2 / 200;
    tooniesremain = var2 % 200;
    loonies = tooniesremain / 100;
    looniesremain = tooniesremain % 100;
    quarters = looniesremain / 25;
    quartersremain = looniesremain % 25;
    dimes = quartersremain / 10;
    dimesremain = quartersremain % 10;
    nickels = dimesremain / 5;
    nickelsremain = dimesremain % 5;
    pennies = nickelsremain / 1;
    penniesremain = nickelsremain % 1;
    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n",(double)total/100);
    printf("Toonies  %3d %9.4lf\n",toonies,(double)tooniesremain/100);
    printf("Loonies  %3d %9.4lf\n",loonies,(double)looniesremain/100);
    printf("Quarters %3d %9.4lf\n",quarters,(double)quartersremain/100);
    printf("Dimes    %3d %9.4lf\n",dimes,(double)dimesremain/100);
    printf("Nickels  %3d %9.4lf\n",nickels,(double)nickelsremain/100);
    printf("Pennies  %3d %9.4lf\n\n",pennies,(double)penniesremain/100);
    printf("Average cost/shirt: $%.4lf\n",((double)total/totalshirts)/100);
    return 0;
}


