#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> num;
// int  = 0;
void subsum(int *arr, int k, int i)
{
    if (i >= 1)
    {
        for (int i = 0; i < num.size(); i++)
        {
            // for(int j = 0;j<num[i].size();j++){
            cout << num[i] << " ";
            // }
            cout << endl;
        }
        return;
    }
    int ans = k - arr[i];
    for (int a = i; a >= 1; a--)
    {
        for (int j = a - 1; j >= 0; j--)
        {
            if (ans - arr[j] >= 0)
            {
                ans -= arr[j];
                num.push_back(arr[j]);
            }
        }
        if (ans > 0)
        {
            num.clear();
        }
    }
    subsum(arr, k, i - 1);
}
int main()
{
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    subsum(arr, k, n - 1);
    // for (int i = 0; i < num.size(); i++)
    // {
    //     // for(int j = 0;j<num[i].size();j++){
    //     cout << num[i] << " ";
    //     // }
    //     cout << endl;
    // }
    return 0;
}