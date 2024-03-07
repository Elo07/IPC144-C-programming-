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
    double monthly_net_income, totalcost = 0.0;
    int wish_list_items, i;
    const double min_net_income = 500.00, max_net_income = 400000.00, min_item_cost = 100.00;
    double itemCost[max_item];
    int itemPriority[max_item];
    char itemFinance[max_item];
    int choice, priorityFilter,loop = 1;
    int hasFinancing = 0;
    double priorityCost = 0;

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    do
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &monthly_net_income);

        if (monthly_net_income < min_net_income)
        {
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n", min_net_income);
        }
        if (monthly_net_income > max_net_income)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n", max_net_income);
        }
        printf("\n");

    } while (!(monthly_net_income >= min_net_income && monthly_net_income <= max_net_income));
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
    
    do
    {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &choice);
        printf("\n");

        if (choice == 0)
        {
          loop = 0;
          printf("Best of luck in all your future endeavours!\n");
          printf("\n");
        }

        else if (choice == 1)
        {
          printf("====================================================\n");
          printf("Filter:   All items\n");
          printf("Amount:   $%.2lf\n", totalcost);

          double months = (totalcost / monthly_net_income) + 0.5;
          double years = ((int) months) / 12;
          double remaining_months = (months - (years * 12)) + 0.5;

          printf("Forecast: %d years, %d months\n", (int)years, (int)remaining_months);

          for (i = 0; i < wish_list_items; i++)
          {
            if (itemFinance[i] == 'y')
            {
              hasFinancing += 1;
            }
          }
          if (hasFinancing != 0)
          {
            printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");
          }
          printf("====================================================\n");
          printf("\n");
        }

        else if (choice == 2)
        {
          do
          {
            printf("What priority do you want to filter by? [1-3]: ");
            scanf("%d", &priorityFilter);
            printf("\n");
            if (priorityFilter < 1 || priorityFilter > 3)
            {
              printf("ERROR: Value must be between 1 and 3.\n");
            }

          } while (priorityFilter < 1 || priorityFilter > 3);

          printf("====================================================\n");
          printf("Filter:   by priority (%d)\n", priorityFilter);

          priorityCost = 0;
          hasFinancing = 0;

          for (i = 0; i < wish_list_items; i++)
          {
            if (itemPriority[i] == priorityFilter)
            {
              priorityCost += itemCost[i];
            }
            if (itemFinance[i] == 'y' && itemPriority[i] == priorityFilter) 
            {
              hasFinancing += 1;
            }
          }

          printf("Amount:   $%1.2lf\n", priorityCost);

          double months = (priorityCost / monthly_net_income) + 0.5;
          double years = ((int) months) / 12;
          double remaining_months = (months - (years * 12)) + 0.5;

          printf("Forecast: %d years, %d months\n", (int)years, (int)remaining_months);

          if (hasFinancing != 0)
          {
            printf("NOTE: Financing options are available on some items.\n      You can likely reduce the estimated months.\n");
          }
          printf("====================================================\n");
          printf("\n");
          
        }
        else if (choice < 0 || choice > 2)
        {
          printf("ERROR: Invalid menu selection.\n");
          printf("\n");
        }     
  
    } while (loop == 1);

    return 0;
}

 
      
