#include <iostream>
#include <string>
using namespace std;
int cnt = 0;
void ascii(string str, string ans, int i)
{
    int asc;
    if (str[i] == '\0')
    {
        cnt++;
        cout << ans << " ";
        return;
    }
    ascii(str, ans, i + 1);
    ascii(str, ans + str[i], i + 1);
    asc = str[i];
    ascii(str, ans + to_string(asc), i + 1);
    return;
}
int main()
{
    string str, ans;
    cin >> str;
    ascii(str, ans, 0);
    cout << endl
         << cnt;
    return 0;
}