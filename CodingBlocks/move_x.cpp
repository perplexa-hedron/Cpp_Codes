#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int cnt = 0;
void move(string s, int i, string ans)
{
    if (i == s.length())
    {
        ans.append(cnt, 'x');
        cout << ans;
        return;
    }
    if (s[i] == 'x')
    {
        cnt++;
        move(s, i + 1, ans);
    }
    else
    {
        ans.push_back(s[i]);
        move(s, i + 1, ans);
    }
}
int main()
{
    string s, ans = "";
    cin >> s;
    move(s, 0, ans);
    return 0;
}