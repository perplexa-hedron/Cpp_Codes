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
int celebrity(int arr[][100], int n)
{
    stack<int> s;
    int c;

    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (arr[a][b])
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    c = s.top();
    s.pop();
    for (int i = 0; i < n; i++)
    {
        if (i != c && (arr[c][i] || arr[i][c] == 0))
        {
            return -1;
        }
    }
    return c;
}
int main()
{
    int n;
    cin >> n;
    int arr[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << celebrity(arr, n);
    return 0;
}