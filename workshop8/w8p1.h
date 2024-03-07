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

#define maximumProducts 3
#define no_of_grams 64

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    /* data */
    int SkuNumber;
    double productPrice;
    int calories;
    double weight;
};




// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *number);


// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *number);


// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numberOfProduct);


// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNumber);


// 5. Display the formatted table header
void displayCatFoodHeader(void);


// 6. Display a formatted record of cat food data
void displayCatFoodData(int SkuNumber, double *productPrice, double *weight, int calories);


// 7. Logic entry point
void start(void);

