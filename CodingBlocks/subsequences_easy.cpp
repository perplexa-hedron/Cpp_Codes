#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int k = 0;
void subs(string *arr, string ans, string str)
{
    if (str.length() == 0)
    {
        arr[k] = ans;
        k++;
        return;
    }
    subs(arr, ans, str.substr(1));
    subs(arr, ans + str[0], str.substr(1));
}
int main()
{
    string arr[100], ans, str;
    cin >> str;
    subs(arr, ans, str);
    for (int i = 0; i < k; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << k;
    return 0;
}