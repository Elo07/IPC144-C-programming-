/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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


// System Libraries
#include <stdio.h>


// User-Defined Libraries
#include "w8p2.h"


// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *number)
{
    int value;
    int flag = 1;

    do
    {
        scanf("%d", &value);
        if (value <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
        else
        {
            flag = 0;
        }
        
    } while (flag);

    if (number != NULL)
    {
        *number = value;
    }

    return value;
    
    
}


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *number)
{
    double value;
    int flag = 1;

    do
    {
        scanf("%lf", &value);
        if (value <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
        else
        {
            flag = 0;
        }
        
    } while (flag);
    if (number != NULL)
    {
        *number = value;
    }

    return value;
    
    
}


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numberOfProduct)
{
    printf("Cat Food Cost Analysis\n");
    printf("======================\n");
    printf("\n");

    printf("Enter the details for %d dry food bags of product data for analysis.\n", MAXIMUMPRODUCTS);
    printf("NOTE: A 'serving' is %dg\n", NO_OF_GRAMS);
    printf("\n");
}


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNumber)
{
    struct CatFoodInfo catFood;
    int flag = 1;
    printf("Cat Food Product #%d\n", sequenceNumber + 1);
    printf("--------------------\n");

    printf("SKU           : ");
    flag = 1;
    do
    {
        scanf("%d", &catFood.skuNumber);
        if (catFood.skuNumber <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
        else
        {
            flag = 0;
        }
        
    } while (flag);

    printf("PRICE         : $");
    flag = 1;
    do
    {
        scanf("%lf", &catFood.productPrice);
        if (catFood.productPrice <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
        else
        {
            flag = 0;
        }
        
    } while (flag);

    printf("WEIGHT (LBS)  : ");
    flag = 1;
    do
    {
        scanf("%lf", &catFood.weight);
        if (catFood.weight <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
        else
        {
            flag = 0;
        }
        
    } while (flag);

    printf("CALORIES/SERV.: ");
    flag = 1;
    do
    {
        scanf("%d", &catFood.calories);
        if (catFood.calories <= 0)
        {
            printf("ERROR: Enter a positive value: ");
        }
        else
        {
            flag = 0;
        }
        
    } while (flag);
    printf("\n");

    return catFood;

}


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
    printf("SKU         $Price    Bag-lbs Cal/Serv\n");
    printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int SkuNumber, double *productPrice, double *weight, int calories)
{
    printf("%07d %10.2lf %10.1lf %8d\n", SkuNumber, *productPrice, *weight, calories);

}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double *pounds, double *conversionResultToKg)
{
    double poundsToKg = (*pounds) / POUNDSTOKG;
    
    if (conversionResultToKg != NULL)
    {
        *conversionResultToKg = poundsToKg;
    }
    return poundsToKg;
}


// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double *pounds, int *conversionResultToG)
{
    int poundsToG = ((*pounds) / POUNDSTOKG) * 1000;
    
    if (conversionResultToG != NULL)
    {
        *conversionResultToG = poundsToG;
    }
    return poundsToG;
}


// 10. convert lbs: kg and g
void convertLbs(const double *pounds, double *conversionResultToKg, int *conversionResultToG)
{
    double poundsToKg = (*pounds) / POUNDSTOKG;
    int poundsToG = ((*pounds) / POUNDSTOKG) * 1000;
    
    if (conversionResultToKg != NULL && conversionResultToG != NULL)
    {
        *conversionResultToG = poundsToG;
        *conversionResultToKg = poundsToKg;
    }
}


// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSizeGrams, const int totalGrams, double *numberOfServings)
{
    double servings = ((double) totalGrams) / servingSizeGrams;
    
    if (numberOfServings != NULL)
    {
        *numberOfServings = servings;
    }
    return servings;
}


// 12. calculate: cost per serving
double calculateCostPerServing(const double *price, const double *numberOfServings, double *result)
{
    double CostPerServing = *price / *numberOfServings;
    
    if (result != NULL)
    {
        *result = CostPerServing;
    }
    return CostPerServing;
}


// 13. calculate: cost per calorie
double calculateCostPerCal(const double *price, const double *calories, double *result)
{
    double CostPerCal = *price / *calories;
    
    if (result != NULL)
    {
        *result = CostPerCal;
    }
    return CostPerCal;
}



// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(struct CatFoodInfo catFood)
{
    struct ReportData data;
    
    data.skuNumber = catFood.skuNumber;
    data.productPrice = catFood.productPrice;
    data.calories = catFood.calories;
    data.productWeightPounds = catFood.weight;
    
    data.productWeightKilos = convertLbsKg(&data.productWeightPounds, &data.productWeightKilos);
    data.productWeightGrams = convertLbsG(&data.productWeightPounds, &data.productWeightGrams);
    data.totalServings = calculateServings(NO_OF_GRAMS, data.productWeightGrams, &data.totalServings);
    data.costPerServing = calculateCostPerServing(&data.productPrice, &data.totalServings, &data.costPerServing);
    
    double totalCalories = data.calories * data.totalServings;
    
    data.costCaloriesPerServing = calculateCostPerCal(&data.productPrice, &totalCalories, &data.costCaloriesPerServing);
    
    return data;
    
}


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
    printf("Analysis Report (Note: Serving = %dg)\n", NO_OF_GRAMS);
    printf("---------------\n");
    printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
    printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData data, const int isCheapest)
{
    printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", data.skuNumber, data.productPrice, data.productWeightPounds, data.productWeightKilos, data.productWeightGrams, data.calories, data.totalServings, data.costPerServing, data.costCaloriesPerServing);
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catFood)
{
    printf("Final Analysis\n");
    printf("--------------\n");
    printf("Based on the comparison data, the PURRR-fect economical option is:\n");
    printf("SKU:%07d Price: $%5.2lf\n", catFood.skuNumber, catFood.productPrice);
    printf("\n");
    printf("Happy shopping!\n\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
    int i, cheapestProduct = 0;
    
    struct CatFoodInfo catFood[MAXIMUMPRODUCTS] = { {0} };
    struct ReportData data[MAXIMUMPRODUCTS] = { {0} };

    openingMessage(MAXIMUMPRODUCTS);

    for ( i = 0; i < MAXIMUMPRODUCTS; i++)
    {
        catFood[i] = getCatFoodInfo(i);
        data[i] = calculateReportData(catFood[i]);
    }

    displayCatFoodHeader();
        
    for ( i = 0; i < MAXIMUMPRODUCTS; i++)
    {
        displayCatFoodData(catFood[i].skuNumber, &catFood[i].productPrice, &catFood[i].weight, catFood[i].calories);
    }
    
    double cheapestProductPrice = data[0].costPerServing;
    for (i = 0; i < MAXIMUMPRODUCTS; i++)
    {
        if (data[i].costPerServing <= cheapestProductPrice)
        {
            cheapestProductPrice = data[i].costPerServing;
            cheapestProduct = i;
        }
    }
    printf("\n");

        
    displayReportHeader();

    for (i = 0; i < MAXIMUMPRODUCTS; i++)
    {
        displayReportData(data[i], cheapestProduct);

        if (cheapestProduct == i)
        {
            printf(" ***\n");
        }
        else
        {
            printf("\n");
        }
    }
    printf("\n");

    for (i = 0; i < MAXIMUMPRODUCTS; i++)
    {
        if (i == cheapestProduct)
        {
            displayFinalAnalysis(catFood[i]);
        }
    }

}
