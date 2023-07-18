#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    long long int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long int key, i;
    cin >> key;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << i;
            break;
        }
    }
    if (i == n)
    {
        cout << -1;
    }

    return 0;
}