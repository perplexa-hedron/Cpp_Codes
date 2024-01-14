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
        cout << s.top() << endl;
        s.pop();
    }
}
ostream &operator<<(ostream &os, stack<int> s)
{
    print(s);
    return os;
}
void bottom_insert(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int data = s.top();
    s.pop();
    bottom_insert(s, x);
    s.push(data);
}
void recursive_reverse(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int x = s.top();
    s.pop();
    recursive_reverse(s);
    bottom_insert(s, x);
}

int main()
{
    long long int n;
	cin >> n;
	stack <int> s;
	for (long long int i = 0; i < n; i++)
	{
        int data;
        cin>>data;
        s.push(data);
	}
    recursive_reverse(s);
    cout<<s;
    return 0;
}