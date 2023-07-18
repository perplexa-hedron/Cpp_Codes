#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long sum;
    long long first = 0;
    long long sec = 1;
    for (int i = 0; i < n - 1; i++)
    {
        sum = first + sec;
        first = sec;
        sec = sum;
    }
    cout << sum;
    return 0;
}