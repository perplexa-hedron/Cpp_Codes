#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int cnt = 0;
vector<string> code = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};
void keypad(string n, string ans)
{
    if (n.length() == 0)
    {
        cout << ans << " ";
        cnt++;
        return;
    }
    string a = n.substr(0, 1);
    int num = stoi(a);
    for (int i = 0; i < code[num].length(); i++)
    {
        keypad(n.substr(1), ans + code[num][i]);
    }
}
int main()
{
    string n;
    cin >> n;
    keypad(n, "");
    cout << endl
         << cnt;
    return 0;
}