#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int arr[9000];
    int n, i, val, diff;
    // while (1)
    // {
    int max_load = 0, load = 0;
    cin >> n;
    if (n == -1)
    {
        cout << -1;
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
        load += arr[i];
    }
    if (load % n != 0)
    {
        cout << -1 << endl;
        // continue;
    }
    load = load / n;
    diff = 0;
    for (int i = 0; i < n; i++)
    {
        diff += (arr[i] - load);
        int ans = max(diff, -diff);
        max_load = max(max_load, ans);
    }
    cout << max_load << endl;
    // }
    return 0;
}