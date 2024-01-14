#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool compare(string a, string b)
{
    if (a[0] == b[0])
    {
        for (int i = 0; i < min(a.length(), b.length()); i++)
        {
            while (a[i] != '\0' && b[i] != '\0')
            {
                if (a[i] == b[i])
                {
                    return a > b;
                }
                else{
                   return a<b;
                }
            }
        }
        // return a > b;
        // if(a.length() < b.length()){
        //     return a<b;
        // }
        // else{
        //     return a>b;
        }
    return a < b;
}
int main()
{
    int n;
    cin >> n;
    string a[1000];
    cin.get();
    for (int i = 0; i < n; i++)
    {
        getline(cin, a[i]);
    }
    // sort(a,a+n);
    sort(a, a + n, compare);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}