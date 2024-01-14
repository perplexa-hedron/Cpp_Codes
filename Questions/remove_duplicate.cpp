#include <iostream>
#include <vector>
using namespace std;
void remove(char a[])
{
    int i = 0, j = 0;
    while (a[i] != '\0')
    {
        if (a[i] == a[j])
        {
            j++;
        }
        else
        {
            cout << a[i];
            i = j;
        }
    }
}
int main()
{
    char a[1001];
    cin.getline(a, 1001);
    remove(a);
    return 0;
}