#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n1, n2;
    int fact;
    cin >> n1 >> n2;
    for (int i = 2; i <= n1; i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            fact = i;
        }
    }
    int lcm = (n1 * n2) / fact;
    cout << lcm;
}