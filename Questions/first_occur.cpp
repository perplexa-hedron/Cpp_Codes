#include <iostream>
#include <vector>
using namespace std;
int first(int *a, int n, int key)
{
    if (n == 0)
    {
        return -1;
    }
    if (a[0] == key)
    {
        return 0;
    }
    if (first(a + 1, n - 1, key) == -1)
    {
        return -1;
    }
    return first(a + 1, n - 1, key) + 1;
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
    cout << first(a, n, key);
    return 0;
}