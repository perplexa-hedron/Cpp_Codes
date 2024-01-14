#include <iostream>
#include <vector>
using namespace std;
void allocc(int *a, int n, int i, int key, bool pr)
{
    if (i == n)
    {
        if (pr != true)
        {
            cout << -1;
        }
        return;
    }
    if (a[i] == key)
    {
        pr = true;
        cout << i << " ";
    }
    allocc(a, n, i + 1, key, pr);
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int key;
    cin >> key;
    bool pr = false;
    allocc(a, n, 0, key, pr);

    return 0;
}