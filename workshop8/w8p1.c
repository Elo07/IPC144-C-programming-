/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
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


// User Libraries
#include "w8p1.h"


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

	printf("Enter the details for %d dry food bags of product data for analysis.\n", maximumProducts);
	printf("NOTE: A 'serving' is %dg\n", no_of_grams);
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
		scanf("%d", &catFood.SkuNumber);
		if (catFood.SkuNumber <= 0)
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

// 7. Logic entry point
void start(void)
{
	int i;
	struct CatFoodInfo catFood[maximumProducts] = { {0} };
	openingMessage(maximumProducts);

	for ( i = 0; i < maximumProducts; i++)
	{
		catFood[i] = getCatFoodInfo(i);
	}

	displayCatFoodHeader();
	
	for ( i = 0; i < maximumProducts; i++)
	{
		displayCatFoodData(catFood[i].SkuNumber, &catFood[i].productPrice, &catFood[i].weight, catFood[i].calories);
	}
	
}