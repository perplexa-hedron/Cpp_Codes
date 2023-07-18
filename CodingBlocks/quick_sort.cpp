#include <iostream>
#include <algorithm>
using namespace std;
int pivot(int *a, int s, int e)
{
    int i = s - 1;
    for (int j = s; j < e; j++)
    {
        if (a[j] <= a[e])
        {
            i++;
            swap(a[i], a[j]);
            // qsort(a,j,e);
        }
    }
    swap(a[i + 1], a[e]);
    return i + 1;
}
void quicksort(int *a, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int idx = pivot(a, s, e);
    quicksort(a, s, idx - 1);
    quicksort(a, idx + 1, e);
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

    quicksort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}