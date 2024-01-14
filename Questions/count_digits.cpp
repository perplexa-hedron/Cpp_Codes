#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long int num;
    cin >> num;
    int n, t = 0;
    cin >> n;
    while (num != 0)
    {
        int r = num % 10;
        if (r == n)
        {
            t++;
        }
        num = num / 10;
    }
    cout << t;
    return 0;
}