#include <iostream>
#include <cstring>
using namespace std;
int countsub(char a[], int len)
{
    int count = 1;
    int sum = len;
    while (count < len)
    {
        int i = 0;
        int j = count;
        while (i != j)
        {
            if (a[i] != a[j])
            {
                continue;
            }
            i++;
            j--;
        }
    }
}
int main()
{
    char a[1000];
    cin.getline(a, 1000);
    int len = strlen(a);
    cout << countsub(a, len);
    return 0;
}