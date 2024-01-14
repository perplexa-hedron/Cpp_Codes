#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}
ostream &operator<<(ostream &os, stack<int> s)
{
    print(s);
    return os;
}
void transfer(stack<int> &s1, stack<int> &s2, int n)
{
    for (int i = 0; i < n; i++)
    {
        s2.push(s1.top());
        s1.pop();
    }
}
void reverse(stack<int> &s1)
{
    stack<int> s2;
    int n = s1.size();
    for (int i = 0; i < n; i++)
    {
        int x = s1.top();
        s1.pop();
        transfer(s1, s2, n - i - 1);
        s1.push(x);
        transfer(s2, s1, n - i - 1);
    }
}
int main()
{
    int n;
    cin >> n;
    stack <int> s;
    for(int i =0;i<n;i++){
        s.push(i);
    }
    reverse(s);
    cout<<s;
    return 0;
}