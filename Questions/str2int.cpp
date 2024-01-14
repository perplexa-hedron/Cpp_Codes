#include <iostream>
#include <string>
using namespace std;
int s2i(string s, int n)
{
    if (n == 0)
    {
        return 0;
    }
    int dig = s[n - 1] - '0';
    return s2i(s, n - 1) * 10 + dig;
}
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    cout << s2i(s, n);
    return 0;
}