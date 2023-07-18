#include <iostream>
using namespace std;

int main()
{
    int number, i, j, k = 0;
    cin >> number;
    for (i = 1; i <= (number/2)+1; i++)
    {
        for (j = 0; j < (number - i)/2; j++)
        {
            cout << "*";
        }
        while (k < (2*i - 1))
        {
            if (k == 0 || k ==2*i-2)
                cout << "*";
            else
                cout << " ";
            k++;
        }
        for (j = 0; j < (number - i)/2; j++)
        {
            cout << "*";
        }
        k = 0;
        cout << endl;
    }
    /*number--;
    for (i = number; i >= 1; i--)
    {
        for (j = 0; j <= number - i; j++)
        {
            cout << "*";
        }
        k = 0;
        while (k > (2 * i - 1) || k < (2 * i - 1))
        {
            if (k == 0 || k >= 2 * i - 2)
                cout << "*";
            else
                cout << " ";
            k++;
        }
        for (j = 0; j <= number - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }*/
    return 0;
}