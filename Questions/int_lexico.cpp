#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void lexico(int n, vector<string> str, int j)
{
    if (n < 0)
    {
        sort(str.begin(), str.end());
        for (int i = 0; i <= j; i++)
        {
            cout << str[i] << " ";
        }
        return;
    }

    string a = to_string(n);
    str.push_back(a);
    lexico(n - 1, str, j);
}
int main()
{
    int n;
    cin >> n;
    vector<string> str;
    // string str;
    // string num = to_string(n);
    lexico(n, str, n);
    return 0;
}