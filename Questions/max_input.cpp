#include <iostream>
#include <climits>
using namespace std;
int main()
{
    long long int n, max = INT_MIN;
    cin >> n;
    long long int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << max;
    return 0;
}