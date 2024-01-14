#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    stack<long long> ans;
    while (t--)
    {
        long long n, data;
        cin >> n;
        if (n == 1)
        {
            cout << ans.top() << endl;
            ans.pop();
        }
        // stack<long long> ans;
        if (n == 2)
        {
            cin >> data;
            ans.push(data);
        }
    }
    return 0;
}