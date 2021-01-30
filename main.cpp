#include <iostream>
#include "functions.h"

using std::cout;
using std::cin;

int main() {
    //instructions
        cout << "This game randomly generates numbers between (0-99).\n";
        cout << "You have the option of generating between (10-20) numbers to guess from \n";
        cout << "this program sorts through the numbers from smallest to largest using a recursive binary search \n";
        cout << "\n\n";

    const int MIN = 10;
    const int MAX = 20;
    int number, searchForNum, counter = 0;
    bool foundNum = false;
    //declare my Array[number]
    int myArray[number];
    int left = 0;
    int right = number - 1;
    int guesses = 0;
    int correctGuesses = 0;

    getInteger(number, MIN, MAX);
    fillArray(myArray, number);
    insertionArray(myArray, number);
    char yesOrNo;



        cout << "Would you like to see the set of numbers before guessing? (y/n): ";
        cin >> yesOrNo;
        if (isupper(yesOrNo)) yesOrNo=tolower(yesOrNo);
        if (yesOrNo == 'y')
            displayArray(myArray, number);
        cout << "very well, how many guesses would you like? ";
        cin >> guesses;

    do {
        cout << "Enter a number to search: ";
        cin >> searchForNum;
        foundNum = binSearch(myArray, left, right, searchForNum);
        if (foundNum) {
            cout << "We found your number \n";
            correctGuesses++;
        } else {
            cout << "We did not find this number \n";
        }
        counter++;
    } while (counter < guesses);
    cout << "Here are the set of numbers\n";
    displayArray(myArray, number);
    cout << "You guessed: " << correctGuesses << " out of " << guesses << " \n";

    return 0;
}



