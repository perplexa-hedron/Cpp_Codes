#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
void print(stack<long long> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}
ostream &operator<<(ostream &os, stack<long long> s)
{
    print(s);
    return os;
}

void next_greater(long long arr[], long long n)
{
    stack<long long> max;
    vector<long long> ans(n, -1);
    for (int i = 0; i < 2 * n; i++)
    {
        while (!max.empty() && arr[max.top()] < arr[i % n])
        {
            ans[max.top()] = arr[i % n];
            max.pop();
        }
        if (i < n)
        {
            max.push(i);
        }
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
}
int main()
{
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    next_greater(arr, n);
    return 0;
}