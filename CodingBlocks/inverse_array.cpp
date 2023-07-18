#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n], aarr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int wi, wj;
    for (int i = 0; i < n; i++)
    {
        wj = arr[i];
        aarr[wj] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cout << aarr[i] << " ";
    }

    return 0;
}