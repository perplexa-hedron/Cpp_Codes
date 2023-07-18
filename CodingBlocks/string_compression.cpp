#include <iostream>
#include <vector>
using namespace std;
void compression(char a[])
{
    int count = 0;
    int i = 0, j = 0;
    while (a[i] != '\0')
    {
        if (a[i] == a[j])
        {
            count++;
            j++;
        }
        else
        {
            {
                cout << a[i] << count;
            }
            i = j;
            count = 0;
        }
    }
}
int main()
{
    char a[1001];
    cin.getline(a, 1001);
    compression(a);
    return 0;
}