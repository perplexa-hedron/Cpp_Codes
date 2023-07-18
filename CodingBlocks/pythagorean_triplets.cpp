#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int a;
    cin >> a;
    int b, c;
    if (a <= 2)
    {
        cout<<-1;
    }
    else if (a % 2 == 0)
    {
        long long var = 1 * a * a / 4;
        cout << var - 1 << " " << var + 1;
    }
    else if (a % 2 != 0)
    {
        long long var = 1 * a * a + 1;
        cout << var / 2 - 1 << " " << var / 2;
    }
    else{
        cout<<-1;
    }
    return 0;
}