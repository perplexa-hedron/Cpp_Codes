#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string arr[100];
int k = 0;
void code(string str, string ans)
{
    if (str.length() == 0)
    {
        arr[k] = ans;
        k++;
        return;
    }
    char a1 = str[0] - '0' + 'a' - 1;
    code(str.substr(1), ans + a1);
    if (str.length() >= 2)
    {
        string sub = str.substr(0, 2);
        char a2 = stoi(sub) + 'a' - 1;
        if (stoi(sub) < 27)
        {
            code(str.substr(2), ans + a2);
        }
    }
}

int main()
{
    // string arr[100];
    string str, ans;
    cin >> str;
    code(str, ans);
    cout << "[";
    for (int i = 0; i < k - 1; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << arr[k - 1] << "]" << endl;
    return 0;
}