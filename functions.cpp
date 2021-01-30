#include "functions.h"
#include <iostream>
#include <ctime>
#include <limits>
#include <iomanip>

using std::cout;
using std::cin;

int getInteger(int &num, int MIN, int MAX)
{
    const char END_LINE = '\n';
    const unsigned long LARGE = std::numeric_limits<std::streamsize>::max();
    do {
        cout << "Enter a number between 10-20: ";
        cin >> num;
        if (cin.fail())
        {
            cout << "ERROR: integer values ONLY \n";
            cin.clear();
            cin.ignore(LARGE, END_LINE); //Note to self: add LARGE, END_LINE later
        }
    } while (num < MIN or MAX < num);
    return num;
}

void fillArray(int array[], int count)
{
    srand(time(nullptr));
    for (int i = 0; i < count; i++)
    {
        array[i] = rand() % 99 + 1;
    }
}

void insertionArray(int array[], int count)
{
    // My understanding of insertion algorithm
    /* [ 4 <-> 3, 6, 8, 1]
    /* [ 3, 4 <-> 6, 8, 1]
    /* [ 3 <-> 4, 6, 8, 1]
    /* [ 3, 4, 6 <-> 8, 1]
    /* [ 3, 4, 6, 8 <-> 1]
    /* [ 3, 4, 6 <-> 1, 8]
    /* [ 3, 4 <-> 1, 6, 8]
    /* [ 3 <-> 1, 4, 6, 8]
    /* [ 1, 3, 4, 6, 8]
     */
    int leftNumber, rightNumber;
    for (int i = 1; i < count; ++i) // iterate (count) many times
    {
        rightNumber = array[i];
        leftNumber = i - 1;
        while (leftNumber >= 0 and array[leftNumber] > rightNumber) // while leftNumber >= 0 and element is bigger than rightNumber
        {
            array[leftNumber + 1] = array[leftNumber]; // swap location of left number to [element + 1]
            leftNumber = leftNumber-1;
        }
        array[leftNumber+1] = rightNumber;
    }
}
void displayArray(int array[], int count)
{
    const int WIDTH = 4;

    for (int i = 0; i < count; ++i)
    {
        if ((i + 1) % 5 == 0) {
            cout << array[i] << std::setw(WIDTH) << '\n';

        } else {
            cout << array[i]<< std::setw(WIDTH) << " ";
        }
    }
    cout << '\n';
}
bool binSearch(int array[], int left, int right, int searchingForNumber)
{

    int middle = (left + right) / 2;

    while (right >= left) // until numbers != 0
    {

        if (array[middle] == searchingForNumber)
        {
            return true; // number matches
        }
        else if(array[middle] > searchingForNumber)
        {
            return binSearch(array, left, (middle - 1), searchingForNumber); //search left half of the array
        }
        else
            return binSearch(array, (middle + 1), right, searchingForNumber); //search right half fo the array
    }
    return false; // no number match
}
