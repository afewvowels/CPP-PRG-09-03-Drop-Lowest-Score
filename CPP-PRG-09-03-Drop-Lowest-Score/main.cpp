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

void getNumberOfTestScores(int &);
double *getTestScores(int);
double *sortScores(double *, int);
void swap(double *, double *);
double averageTestScore(double *, int);
void showOutputMessage(double *, int, double);


int main()
{
    int intNumScores;
    
    double *dblTestScores = nullptr;
    double dblAverageScore;
    
    getNumberOfTestScores(intNumScores);
    
    dblTestScores = getTestScores(intNumScores);
    
    //    Debug
    //    for (int i = 0 ; i < intNumScores ; i++)
    //    {
    //        cout << *(dblTestScores + i) << endl;
    //    }
    
    cout << endl << endl;
    
    dblTestScores = sortScores(dblTestScores, intNumScores);
    
    //    Debug
    //    for (int i = 0 ; i < intNumScores ; i++)
    //    {
    //        cout << *(dblTestScores + i) << endl;
    //    }
    
    dblAverageScore = averageTestScore(dblTestScores, intNumScores);
    
    showOutputMessage(dblTestScores, intNumScores, dblAverageScore);
    
    return 0;
}

void getNumberOfTestScores(int &refNumScores)
{
    //    int intNumScores;
    
    cout << "How many test scores would you like to average?\n";
    cin >> refNumScores;
    while(!cin || refNumScores <= 0 || refNumScores > 10)
    {
        cout << "Please enter a number between 1 and 10.\n";
        cin.clear();
        cin.ignore();
        cin >> refNumScores;
    }
}

double *getTestScores(int intScores)
{
    double *dblArr = nullptr;
    
    dblArr = new double[intScores];
    
    //    unique_ptr<double[]> dblArr (new double[intScores]);
    
    for (int i = 0 ; i < intScores ; i++)
    {
        cout << "Please enter your #" << i + 1 << " test score.\n";
        cin >> dblArr[i];
        while(!dblArr[i] || dblArr[i] < 0 || dblArr[i] > 100)
        {
            cout << "Please enter a test score between 0 and 100.\n";
            cin.clear();
            cin.ignore();
            cin >> dblArr[i];
        }
    }
    
    return dblArr;
    
    //    HOW TO MAKE THIS WORK?!
    //    delete [] dblArr;
    //    dblArr = nullptr;
}

double *sortScores(double *dblScores, int INT_SCORES)
{
    int intMinIndex;
    int intStartScan;
    
    double *dblMinElement = nullptr;
    
    for(intStartScan = 0 ; intStartScan < (INT_SCORES - 1) ; intStartScan++)
    {
        intMinIndex = intStartScan;
        dblMinElement = &dblScores[intStartScan];
        
        for(int index = intStartScan + 1 ; index < INT_SCORES ; index++)
        {
            if(dblScores[index] < *dblMinElement)
            {
                dblMinElement = &dblScores[index];
                intMinIndex = index;
            }
        }
        swap(dblScores[intMinIndex], dblScores[intStartScan]);
    }
    
    return dblScores;
}

void swap(double *dblA, double *dblB)
{
    double *temp = nullptr;
    
    temp = dblA;
    dblA = dblB;
    dblB = temp;
}

double averageTestScore(double *dblScores, int INT_SCORES)
{
    double dblTotal = 0;
    double dblAverage;
    
    for(int i = 1 ; i < INT_SCORES ; i++)
    {
        dblTotal += *(dblScores + i);
    }
    
    dblAverage = dblTotal / (INT_SCORES - 1);
    
    return dblAverage;
}

void showOutputMessage(double *dblScores, int INT_SCORES, double dblAverage)
{
    cout << setprecision(1) << fixed << showpoint;
    cout << "Your test scores sorted in order are:\n";
    for(int i = 0 ; i < INT_SCORES ; i++)
    {
        cout << *(dblScores + i) << endl;
    }
    cout << "Your score of " << *(dblScores) << " was dropped.\n";
    cout << "Your new average score was " << dblAverage << endl;
}
