/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
    
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;
    char coffee1type, coffee2type, coffee3type;
    int coffee1bagweight, coffee2bagweight, coffee3bagweight;
    char coffee1_cream_or_not, coffee2_cream_or_not, coffee3_cream_or_not;
    char cust_coffeeStrength, cust_pref_coffeewithcream;
    int dailyServings;
        
    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee1type);
    printf("Bag weight (g): ");
    scanf(" %d", &coffee1bagweight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee1_cream_or_not);
    printf("\n");
    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee2type);
    printf("Bag weight (g): ");
    scanf(" %d", &coffee2bagweight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee2_cream_or_not);
    printf("\n");
    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee3type);
    printf("Bag weight (g): ");
    scanf(" %d", &coffee3bagweight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee3_cream_or_not);
    printf("\n");
    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (coffee1type == 'l' || coffee1type == 'L'), (coffee1type == 'm' || coffee1type == 'M'), (coffee1type == 'r' || coffee1type == 'R'), coffee1bagweight , coffee1bagweight / GRAMS_IN_LBS, (coffee1_cream_or_not == 'y' || coffee1_cream_or_not == 'Y'));
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (coffee2type == 'l' || coffee2type == 'L'), (coffee2type == 'm' || coffee2type == 'M'), (coffee2type == 'r' || coffee2type == 'R'), coffee2bagweight , coffee2bagweight / GRAMS_IN_LBS, (coffee2_cream_or_not == 'y' || coffee2_cream_or_not == 'Y'));
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n\n", (coffee3type == 'l' || coffee3type == 'L'), (coffee3type == 'm' || coffee3type == 'M'), (coffee3type == 'r' || coffee3type == 'R'), coffee3bagweight , coffee3bagweight / GRAMS_IN_LBS, (coffee3_cream_or_not == 'y' || coffee3_cream_or_not == 'Y'));
    printf("Enter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &cust_coffeeStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cust_pref_coffeewithcream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &dailyServings);
    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n",
           ((coffee1type =='l' || coffee1type == 'L') && (cust_coffeeStrength == 'l' || cust_coffeeStrength == 'L')) ||
           ((coffee1type =='r' || coffee1type == 'R') && (cust_coffeeStrength == 'r' || cust_coffeeStrength == 'R')) ||
           ((coffee1type =='m' || coffee1type == 'M') && (cust_coffeeStrength == 'm' || cust_coffeeStrength == 'M')),
           (coffee1bagweight == 250 && dailyServings >=1 && dailyServings <= 4) ||
           (coffee1bagweight == 500 && dailyServings >=5 && dailyServings <= 9) ||
           (coffee1bagweight == 1000 && dailyServings >=10),
           ((coffee1_cream_or_not == 'y' || coffee1_cream_or_not == 'Y') && (cust_pref_coffeewithcream == 'y' || cust_pref_coffeewithcream == 'Y')) ||
           ((coffee1_cream_or_not == 'n' || coffee1_cream_or_not == 'N') && (cust_pref_coffeewithcream == 'n' || cust_pref_coffeewithcream == 'N')));
    printf(" 2|       %d         |      %d      |   %d   |\n",
           ((coffee2type =='l' || coffee2type == 'L') && (cust_coffeeStrength == 'l' || cust_coffeeStrength == 'L')) ||
           ((coffee2type =='r' || coffee2type == 'R') && (cust_coffeeStrength == 'r' || cust_coffeeStrength == 'R')) ||
           ((coffee2type =='m' || coffee2type == 'M') && (cust_coffeeStrength == 'm' || cust_coffeeStrength == 'M')),
           (coffee2bagweight == 250 && dailyServings >=1 && dailyServings <= 4) ||
           (coffee2bagweight == 500 && dailyServings >=5 && dailyServings <= 9) ||
           (coffee2bagweight == 1000 && dailyServings >=10),
           ((coffee2_cream_or_not == 'y' || coffee2_cream_or_not == 'Y') && (cust_pref_coffeewithcream == 'y' || cust_pref_coffeewithcream == 'Y')) ||
           ((coffee2_cream_or_not == 'n' || coffee2_cream_or_not == 'N') && (cust_pref_coffeewithcream == 'n' || cust_pref_coffeewithcream == 'N')));
    printf(" 3|       %d         |      %d      |   %d   |\n\n",
           ((coffee3type =='l' || coffee3type == 'L') && (cust_coffeeStrength == 'l' || cust_coffeeStrength == 'L')) ||
           ((coffee3type =='r' || coffee3type == 'R') && (cust_coffeeStrength == 'r' || cust_coffeeStrength == 'R')) ||
           ((coffee3type =='m' || coffee3type == 'M') && (cust_coffeeStrength == 'm' || cust_coffeeStrength == 'M')),
           (coffee3bagweight == 250 && dailyServings >=1 && dailyServings <= 4) ||
           (coffee3bagweight == 500 && dailyServings >=5 && dailyServings <= 9) ||
           (coffee3bagweight == 1000 && dailyServings >=10),
           ((coffee3_cream_or_not == 'y' || coffee3_cream_or_not == 'Y') && (cust_pref_coffeewithcream == 'y' || cust_pref_coffeewithcream == 'Y')) ||
           ((coffee3_cream_or_not == 'n' || coffee3_cream_or_not == 'N') && (cust_pref_coffeewithcream == 'n' || cust_pref_coffeewithcream == 'N')));
    printf("Enter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &cust_coffeeStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &cust_pref_coffeewithcream);
    printf("Typical number of daily servings: ");
    scanf(" %d", &dailyServings);
    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n",
           ((coffee1type =='l' || coffee1type == 'L') && (cust_coffeeStrength == 'l' || cust_coffeeStrength == 'L')) ||
           ((coffee1type =='r' || coffee1type == 'R') && (cust_coffeeStrength == 'r' || cust_coffeeStrength == 'R')) ||
           ((coffee1type =='m' || coffee1type == 'M') && (cust_coffeeStrength == 'm' || cust_coffeeStrength == 'M')),
           (coffee1bagweight == 250 && dailyServings >=1 && dailyServings <= 4) ||
           (coffee1bagweight == 500 && dailyServings >=5 && dailyServings <= 9) ||
           (coffee1bagweight == 1000 && dailyServings >=10),
           ((coffee1_cream_or_not == 'y' || coffee1_cream_or_not == 'Y') && (cust_pref_coffeewithcream == 'y' || cust_pref_coffeewithcream == 'Y')) ||
           ((coffee1_cream_or_not == 'n' || coffee1_cream_or_not == 'N') && (cust_pref_coffeewithcream == 'n' || cust_pref_coffeewithcream == 'N')));
    printf(" 2|       %d         |      %d      |   %d   |\n",
           ((coffee2type =='l' || coffee2type == 'L') && (cust_coffeeStrength == 'l' || cust_coffeeStrength == 'L')) ||
           ((coffee2type =='r' || coffee2type == 'R') && (cust_coffeeStrength == 'r' || cust_coffeeStrength == 'R')) ||
           ((coffee2type =='m' || coffee2type == 'M') && (cust_coffeeStrength == 'm' || cust_coffeeStrength == 'M')),
           (coffee2bagweight == 250 && dailyServings >=1 && dailyServings <= 4) ||
           (coffee2bagweight == 500 && dailyServings >=5 && dailyServings <= 9) ||
           (coffee2bagweight == 1000 && dailyServings >=10),
           ((coffee2_cream_or_not == 'y' || coffee2_cream_or_not == 'Y') && (cust_pref_coffeewithcream == 'y' || cust_pref_coffeewithcream == 'Y')) ||
           ((coffee2_cream_or_not == 'n' || coffee2_cream_or_not == 'N') && (cust_pref_coffeewithcream == 'n' || cust_pref_coffeewithcream == 'N')));
    printf(" 3|       %d         |      %d      |   %d   |\n\n",
           ((coffee3type =='l' || coffee3type == 'L') && (cust_coffeeStrength == 'l' || cust_coffeeStrength == 'L')) ||
           ((coffee3type =='r' || coffee3type == 'R') && (cust_coffeeStrength == 'r' || cust_coffeeStrength == 'R')) ||
           ((coffee3type =='m' || coffee3type == 'M') && (cust_coffeeStrength == 'm' || cust_coffeeStrength == 'M')),
           (coffee3bagweight == 250 && dailyServings >=1 && dailyServings <= 4) ||
           (coffee3bagweight == 500 && dailyServings >=5 && dailyServings <= 9) ||
           (coffee3bagweight == 1000 && dailyServings >=10),
           ((coffee3_cream_or_not == 'y' || coffee3_cream_or_not == 'Y') && (cust_pref_coffeewithcream == 'y' || cust_pref_coffeewithcream == 'Y')) ||
           ((coffee3_cream_or_not == 'n' || coffee3_cream_or_not == 'N') && (cust_pref_coffeewithcream == 'n' || cust_pref_coffeewithcream == 'N')));
    printf("Hope you found a product that suits your likes!\n");
   
    return 0;
}
