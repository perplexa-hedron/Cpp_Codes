#include <iostream>
#include <cstring>
using namespace std;
void toggle(char a[])
{
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] >= 65 && a[i] <= 90)
        {
            a[i] = a[i] + 32;
        }
        else if (a[i] >= 97 && a[i] <= 122)
        {
            a[i] = a[i] - 32;
        }
    }
    cout << a;
}
int main()
{
    char a[1000];
    cin.getline(a, 1000);
    toggle(a);
    return 0;
}