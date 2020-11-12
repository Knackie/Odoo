#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    for (int i = 1; i < 100; i++)
    {
        cout << i << " ";
        if (i % 3 == 0)
        {
            if (i % 7 == 0)
            {
                cout << "OpenSource \n";
            }
            else
                cout << "Open";

        }
        if (i % 7 == 0)
        {
            if (i % 3 == 0)
            {
                continue;
            }
            else
                cout << "Source";
        }
        cout << "\n";
   }

    return 0;
}