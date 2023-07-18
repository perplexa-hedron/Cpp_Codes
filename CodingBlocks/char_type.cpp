#include <iostream>
#include <cstring>
using namespace std;
char char_type(char a[])
{
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] >= 65 && a[i] <= 90)
        {
            return 'U';
        }
        else if (a[i] >= 97 && a[i] <= 122)
        {
            return 'L';
        }
        else{
            return 'I';
        }
    }
    return 'I';
}
int main()
{
    char a[1000];
    cin.getline(a, 1000);
    cout<<char_type(a);
    return 0;
}