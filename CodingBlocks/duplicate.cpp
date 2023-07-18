#include <iostream>
#include <string>
using namespace std;
void duplicate(string s, int i, string str)
{
    if (i == s.length())
    {

        cout << str;
        return;
    }
    if (s[i] == s[i + 1])
    {
        str.append(1, s[i]);
        str.append(1, '*');
        duplicate(s, i + 1, str);
    }
    else
    {
        str.append(1, s[i]);
        duplicate(s, i + 1, str);
    }
}
int main()
{
    string s, str;
    cin >> s;
    duplicate(s, 0, str);
    return 0;
}