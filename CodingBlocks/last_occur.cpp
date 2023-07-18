#include <iostream>
#include <vector>
using namespace std;
int lastocc(int *a, int n, int key, int i)
{
    if (i == n)
    {
        return -1;
    }
    if (a[i] == key)
    {
        int bi = lastocc(a, n, key, i+1);
        if (bi != -1)
        {
            return bi;
        }
        else
        {
            return i;
        }
    }
    else
    {
        int ans = lastocc(a, n, key, i + 1);
        return ans;
    }
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
    cout << lastocc(a, n, key, 0);
    return 0;
}