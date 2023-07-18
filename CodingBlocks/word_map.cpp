#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string arr[100];
int k = 0;
void mapping(string s, string ans)
{
    if (s.length() == 0)
    {
        arr[k] = ans;
        k++;
        return;
    }
    char a1 = s[0] - '0' + 'A' - 1;
    mapping(s.substr(1), ans + a1);
    if (s.length() >= 2)
    {
        string str = s.substr(0, 2);
        char a2 = stoi(str) + 'A' - 1;
        if (stoi(str) < 27)
        {
            mapping(s.substr(2), ans + a2);
        }
    }
}
int main()
{
    string s, ans;
    cin >> s;
    mapping(s, ans);
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}