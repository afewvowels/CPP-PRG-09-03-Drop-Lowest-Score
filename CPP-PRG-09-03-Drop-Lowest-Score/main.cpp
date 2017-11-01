//
//  main.cpp
//  CPP-PRG-09-03-Drop-Lowest-Score
//
//  Created by Keith Smith on 10/29/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Modify program 2 above so the lowest test score is dropped. This score should not be
//  included in the calculation of the average.

#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
int *getNumberOfTestScores();
double *getTestScores(int *);
double *sortScores(double *, int *);
void swap(double *, double *);
double *averageTestScore(double *, int *);
void showOutputMessage(double *, int *, double *);


int main()
{
    // Create integer pointer and set to null for number
    // of test scores for use with getNumberOfTestScores()
    int *intNumScores = nullptr;
    
    // Create two double pointers to hold the array of
    // test scores and the average test score
    double *dblTestScores = nullptr;
    double *dblAverageScore = nullptr;
    
    // Get value for intNumScores
    intNumScores = getNumberOfTestScores();
    
    // Get values for test scores array
    dblTestScores = getTestScores(intNumScores);
    
    // For spacing between test score entry and displaying
    // the sorted array and average score.
    cout << endl << endl;
    
    // Sort the testScores array in descending order
    dblTestScores = sortScores(dblTestScores, intNumScores);
    
    // Calculate the average test score (order of sortScores and
    // averageTestScore can be swapped if necessary, arbitrary
    // decision to sort before calculating average)
    dblAverageScore = averageTestScore(dblTestScores, intNumScores);
    
    // Pass pointers through to display them in a formatted
    // output message(s)
    showOutputMessage(dblTestScores, intNumScores, dblAverageScore);
    
    // Exit
    return 0;
}

// This function gets an integer value from the user and performs
// rudimentary data validation on it until the user enters a number
// between 0 and 10 for the total number of test scores to sort
// and average.
int *getNumberOfTestScores()
{
    // Declare new pointer, set to null
    int *intNumScores = nullptr;
    
    // Set null pointer as a new int variable
    intNumScores = new int;
    
    // Get user input as pointer value and performs simple data validation
    cout << "How many test scores would you like to average?\n";
    cin >> *intNumScores;
    // Data validation
    while(!cin || *intNumScores <= 0 || *intNumScores > 10)
    {
        cout << "Please enter a number between 1 and 10.\n";
        cin.clear();
        cin.ignore();
        cin >> *intNumScores;
    }
    
    // Return the address of the number of tests the
    // array will hold
    return intNumScores;
}

// This function takes the user generated intNumScores from
// the last function and uses it to dynamically generate
// an array of that size and also gets user inputs (and
// performs data validation) to fill the array.
double *getTestScores(int *intScores)
{
    // Create new pointer, set to null
    double *dblArr = nullptr;
    
    // Describe null pointer as a new array with size intScores
    dblArr = new double[*intScores];
    
    // Loop through array one time and fill each element
    // with user input of tests scores
    for (int i = 0 ; i < *intScores ; i++)
    {
        // Show prompt displaying which element the user is
        // entering out of the total number of elements
        cout << "Please enter your #" << i + 1 << " test score.\n";
        cin >> dblArr[i];
        // Data validation
        while(!dblArr[i] || dblArr[i] < 0 || dblArr[i] > 100)
        {
            cout << "Please enter a test score between 0 and 100.\n";
            cin.clear();
            cin.ignore();
            cin >> dblArr[i];
        }
    }
    
    // Return the array address to main
    return dblArr;
    
    //    HOW TO MAKE THIS WORK?!
    //    delete [] dblArr;
    //    dblArr = nullptr;
}

// This function takes the values of the array of test scores
// and performs a selection sort on them
double *sortScores(double *dblScores, int *INT_SCORES)
{
    // Used to hold the smallest value (index of starting element
    // for each pass through the array)
    int intMinIndex;
    // Used to keep track of the beginning element of each sweep
    // through the array
    int intStartScan;
    
    // Declare pointer variable and set to null to hold array
    // value when swapping
    double *dblMinElement = nullptr;
    
    // Loop through the array one element at a time
    for(intStartScan = 0 ; intStartScan < (*INT_SCORES - 1) ; intStartScan++)
    {
        // Set min index (first element) in subscan to startscan
        intMinIndex = intStartScan;
        // Set the pointer equal to the memory location of that
        // array element
        dblMinElement = &dblScores[intStartScan];
        
        // Loop through all remaining array elements...
        for(int index = intStartScan + 1 ; index < *INT_SCORES ; index++)
        {
            // ...and look for the value of a smaller element...
            if(dblScores[index] < *dblMinElement)
            {
                // ...if found, set the holder pointer variable address
                // to the smallest found value
                dblMinElement = &dblScores[index];
                // and set the minimum value index to that array element
                intMinIndex = index;
            }
        }
        // And swap the beginning of the subloop through's element
        // with the found smallest element
        swap(dblScores[intMinIndex], dblScores[intStartScan]);
    }
    
    // Return the address of the sorted array
    return dblScores;
}

// Simple swap function
void swap(double *dblA, double *dblB)
{
    // Use pointers, create temp variable to
    // hold address of values to be swapped
    double *temp = nullptr;
    
    // Perform swap using addresses instead
    // of variables
    temp = dblA;
    dblA = dblB;
    dblB = temp;
}

// This function calculates the value of the average test score
double *averageTestScore(double *dblScores, int *INT_SCORES)
{
    // Create new pointer variables to hold the total score (for
    // calculating the average score) and the calculated average score
    double *dblTotal = nullptr;
    double *dblAverage = nullptr;
    
    // Define null pointers as new double variables
    dblTotal = new double;
    dblAverage = new double;
    
    // Set running total dblTotal counter to 0 to start
    *dblTotal = 0;
    
    // Because the array is sorted, we just skip the first
    // element [0] and start the counter at 1 instead of 0...
    for(int i = 1 ; i < *INT_SCORES ; i++)
    {
        *dblTotal += *(dblScores + i);
    }
    
    // ...then divide that total by the total number of scores less one
    *dblAverage = *dblTotal / (*INT_SCORES - 1);
    
    // Return the address of the calculated average score value
    return dblAverage;
}

// This function displays the calculated results and sorted array
// in a formatted fashion.
void showOutputMessage(double *dblScores, int *INT_SCORES, double *dblAverage)
{
    // Set precisions so that scores and average value only
    // have one decimal point visible
    cout << setprecision(1) << fixed << showpoint;
    cout << "Your test scores sorted in order are:\n";
    // Loop through array and output contents to console
    for(int i = 0 ; i < *INT_SCORES ; i++)
    {
        cout << *(dblScores + i) << endl;
    }
    // Output message declaring which score was dropped
    cout << "Your score of " << *(dblScores) << " was dropped.\n";
    // Output message and calculated average value to console
    cout << "Your new average score was " << *dblAverage << endl;
}
