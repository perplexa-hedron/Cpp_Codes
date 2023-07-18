#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
void replace(char *a, int i)
{
    if (a[i] == '\0' || a[i + 1] == '\0')
    {
        return;
    }
    if (a[i] == 'p' && a[i + 1] == 'i')
    {
        int j = i + 2;
        while (a[j] != '\0')
        {
            j++;
        }
        while (j >= i + 2)
        {
            a[j + 2] = a[j];
            j--;
        }
        a[i] = '3';
        a[i + 1] = '.';
        a[i + 2] = '1';
        a[i + 3] = '4';
        replace(a, i + 4);
    }
    replace(a, i + 1);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char str[1000];
        cin >> str;
        replace(str, 0);
        cout << str<<endl;
    }

    return 0;
}
