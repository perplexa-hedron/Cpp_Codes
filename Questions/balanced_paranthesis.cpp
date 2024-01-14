#include <iostream>
#include <vector>
using namespace std;
void para(char *a, int n, int o, int c, int i)
{
    if (i == 2 * n)
    {
        a[i] = '\0';
        cout << a << endl;
        return;
    }
    if (o > c)
    {
        a[i] = '>';
        para(a, n, o, c + 1, i + 1);
    }
    if (o < n)
    {
        a[i] = '<';
        para(a, n, o + 1, c, i + 1);
    }
}
int main()
{
    int n;
    cin >> n;
    char a[(2 * n + 1)];
    para(a, n, 0, 0, 0);
    return 0;
}