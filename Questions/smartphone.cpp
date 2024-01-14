#include <iostream>
using namespace std;
int winner(int m, int n)
{
    int suma = 0, sumh = 0, i = 1;
    while (suma <= m || sumh <= n)
    {
        if (i % 2 == 0)
        {
            sumh += i;
        }
        else
        {
            suma += i;
        }
        i++;
    }
    if (suma > sumh)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int m, n;
        cin >> m >> n;
        if (winner(m, n) == 0)
        {
            cout << "Aayush"
                 << "\n";
        }
        else
        {
            cout << "Harshit"
                 << "\n";
        }
    }

    return 0;
}