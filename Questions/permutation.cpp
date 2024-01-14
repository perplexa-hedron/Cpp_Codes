#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
int k = 0;
void permute(string s, int i, set<string> &a)
{
    if (i == s.length())
    {
        k++;
        // cout << s << endl;
        string t(s);
        a.insert(t);
        return;
    }
    for (int j = i; j < s.length(); j++)
    {
        swap(s[i], s[j]);
        permute(s, i + 1, a);
        swap(s[j], s[i]);
    }
}
int main()
{
    string s;
    cin >> s;
    set<string> a;
    permute(s, 0, a);

    for (auto str : a)
    {
        //if(str>s)
        // if (str < s)
        // {
            cout << str << endl;
        // }
    }
    // cout << k;
    return 0;
}