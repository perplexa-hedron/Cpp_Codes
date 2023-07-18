#include <iostream>
#include <climits>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int min = INT_MIN;
    int max = INT_MAX;
    int count = 0;
    int i = 0, j = n - 1;
    while (i < n && j > i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            // cout << max << endl;
        }
        if (arr[j] < min)
        {
            min = arr[j];
            // cout << min << endl;
        }
        if (arr[i] != max)
        {
            swap(min, max);
            count++;
        }

        i++;
        j--;
    }
    cout << count;
    return 0;
}