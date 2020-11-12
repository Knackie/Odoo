#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <time.h>
#include "Source1.h"
#include <list>
using namespace std;

int sumOfList(vector<string> listOfString) {
    int sum = 0;
    for (int i = 0; i < listOfString.size(); i++)
    {
        string s = listOfString.at(i);
        if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) continue;

        sum += stoi(s);
    }
    return sum;
}
   

int main()
{
    vector<string> listOfString;
    listOfString.push_back("1");
    listOfString.push_back("1dzadaz");
    listOfString.push_back("5");
    int result = sumOfList(listOfString);
    cout << result;

    
}

