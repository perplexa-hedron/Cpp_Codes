#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[100000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    bool b = binary_search(a, a + n, m);
    if (b == true)
    {
        int *indx = find(a, a + n, m);
        cout << indx - a;
    }
    else
        cout << -1;
    return 0;
}