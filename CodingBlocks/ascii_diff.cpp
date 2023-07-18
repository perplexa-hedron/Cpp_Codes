#include <iostream>
#include <cstring>
using namespace std;
void difference(char a[])
{
    int i = 0, j = 1;
    while (i <= j && a[j] != '\0')
    {
        int x = a[j] - a[i];
        cout << a[i] << x;
        i++;
        j++;
    }
    cout << a[i];
}
int main()
{
    char a[1000];
    cin.getline(a, 1000);
    difference(a);
    return 0;
}