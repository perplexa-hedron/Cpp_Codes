#include <iostream>
using namespace std;
void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}
int main()
{
    int n, t;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> t;
    sort(arr, n);
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] > t)
        {
            j--;
        }
        else if (arr[i] + arr[j] < t)
        {
            i++;
        }
        else
        {
            cout << arr[i] << " and " << arr[j] << endl;
            i++;
        }
    }
    return 0;
}