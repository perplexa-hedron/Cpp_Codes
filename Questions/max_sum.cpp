#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int n, max_sum = INT_MIN;
    cin >> n;
    int wi, wj;
    int arr[n], csum[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++)
    {
        csum[i] += csum[i - 1] + arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            sum = csum[j] - csum[i - 1];
            if (max_sum < sum)
            {
                max_sum = sum;
                wi = i;
                wj = j;
            }
        }
    }

    for (int i = wi; i <= wj; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << max_sum;
    return 0;
}