#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int profit(int cap, int *wt, int *pr, int n, int inc, int exc)
{
    if (cap == 0 || n == 0)
    {
        return 0;
    }
    if (wt[n - 1] <= cap)
    {
        inc = pr[n - 1] + profit(cap - wt[n - 1], wt, pr, n - 1, inc, exc);
        // profit(cap-wt[n-1],wt,pr,n-1,inc,exc);
    }
    exc = profit(cap, wt, pr, n - 1, inc, exc);
    return max(inc,exc);
}
int main()
{
    int n;
    cin >> n;
    int wt[n];
    int pr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> pr[i];
    }
    int cap;
    cin >> cap;
    cout << profit(cap, wt, pr, n, 0, 0);
    return 0;
}