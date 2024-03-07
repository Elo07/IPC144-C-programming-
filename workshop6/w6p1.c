/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  : Ehimwenma Larry Okuonghae
Student ID#: 145203238
Email      : elokuonghae@myseneca.ca
Section    : NGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define max_item 10

int main(void)
{
    double monthly_net_icome, totalcost = 0.0;
    int wish_list_items, i;
    const double min_net_income = 500.00, max_net_income = 400000.00, min_item_cost = 100.00;
    double itemCost[max_item];
    int itemPriority[max_item];
    char itemFinance[max_item];

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    do
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &monthly_net_icome);

        if (monthly_net_icome < min_net_income)
        {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", min_net_income);
        }
        if (monthly_net_icome > max_net_income)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", max_net_income);
        }
        printf("\n");

    } while (!(monthly_net_icome >= min_net_income && monthly_net_icome <= max_net_income));
        do
        {
          printf("How many wish list items do you want to forecast?: ");
          scanf("%d", &wish_list_items);

          if (!(wish_list_items > 0 && wish_list_items <= max_item))
          {
            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
          }
        
        } while (!(wish_list_items > 0 && wish_list_items <= max_item));

        printf("\n");

        for (i = 0 ; i < wish_list_items; i++)
        {
          printf("Item-%d Details:\n", i + 1);

          do
          {
            printf("   Item cost: $");
            scanf("%lf", &itemCost[i]);
            
            if (itemCost[i] < min_item_cost)
            {
              printf("      ERROR: Cost must be at least $%.2lf\n", min_item_cost);
            }  

          } while (itemCost[i] < min_item_cost);

          do
          {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &itemPriority[i]);

            if (itemPriority[i] < 1 || itemPriority[i] > 3)
            {
              printf("      ERROR: Value must be between 1 and 3\n");
            }
            
          } while (itemPriority[i] < 1 || itemPriority[i] > 3);

          do
          {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &itemFinance[i]);

            if (itemFinance[i] != 'y' && itemFinance[i] != 'n')
            {
              printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
            
          } while (itemFinance[i] != 'y' && itemFinance[i] != 'n');
          
            printf("\n");
            totalcost += itemCost[i];
             
        }

    printf("Item Priority Financed        Cost\n");
		printf("---- -------- -------- -----------\n");

    for (i = 0; i < wish_list_items; i++)
    {
      printf("%3d  %5d    %5c    %11.2lf\n", i + 1, itemPriority[i], itemFinance[i], itemCost[i]);
    }
        

    printf("---- -------- -------- -----------\n");
		printf("                      $%11.2lf\n\n", totalcost);
    printf("Best of luck in all your future endeavours!\n");


    return 0;
}

