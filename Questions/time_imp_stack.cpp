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
int time_required(stack<int> call, int ideal[], int ctime)
{
    
    return ctime;
}
int main()
{
    int n;
    cin >> n;
    stack<int> call;
    int ideal[n];
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        call.push(data);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> ideal[i];
    }
    cout << time_required(call, ideal, 0);
    return 0;
}