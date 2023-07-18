#include <iostream>
#include <cstring>
using namespace std;
bool palindrome(char a[], int len)
{
    int i = 0;
    int j = len - 1;
    while (i < j)
    {
        if (a[i] != a[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}
int main()
{
    char a[1000];
    cin.getline(a, 1000);
    int len = strlen(a);
    if (palindrome(a, len) == 1)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}