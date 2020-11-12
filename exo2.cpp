#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <time.h>
#include "Source1.h"

using namespace std;
int max;
int min;
int finalNum;

int verify(int guess) {

    if (guess == ::finalNum)
        return 0;
    if (guess < ::finalNum)
        return -1;
    if (guess > ::finalNum)
        return 1;
}

int main()
{
    
    srand(time(NULL));
    extern int finalNum;
    ::max = 1000000;
    ::min = 1;
    ::finalNum = rand() % (::max - ::min + 1) + ::min; // Generate a guess number. 
    int guess = rand() % (::max - ::min + 1) + ::min; // Generate a guess number. 
    for (int numberOfTry = 0; numberOfTry < 50; numberOfTry++)
    {
        int guess = rand() % (::max - ::min + 1) + ::min; // Generate a guess number. 
        //cout << verify(guess) << endl;
        if (verify(guess) == -1)
        {
            ::min = guess;
        }
        if (verify(guess) == 0)
        {
            cout << "Win, the number was : " << guess << endl;
            break;
        }
        if (verify(guess) == 1)
        {
            ::max = guess;
        }
       
    }
    cout << "Lose, the number was : " << ::finalNum << endl;
    

}

