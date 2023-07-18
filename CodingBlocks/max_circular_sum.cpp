#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int t, n, max_sum;
    cin >> t >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    max_sum = INT_MIN;
    while (t > 0)
    {
        int sum = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            for (int i = 0; i <= j; i++)
            {
                sum += arr[i];
                cout<<arr[i]<<" ";
            }
            // cout<<endl;
            //cout<<sum<<endl;
            if (max_sum < sum)
            {
                max_sum = sum;
            }
        }
        t--;
    }

    //cout << max_sum;
    return 0;
}