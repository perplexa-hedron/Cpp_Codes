#include <iostream>
#include <vector>
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
    for (int i = 0; i < n; i++)
    {
        int k = i + 1;
        int j = n - 1;
        int sum = t - arr[i];
        while (k < j)
        {
            if (arr[k] + arr[j] > sum)
            {
                j--;
            }
            else if (arr[k] + arr[j] < sum)
            {
                k++;
            }
            else
            {
                cout << arr[i] << ", " << arr[k] << " and " << arr[j] << endl;
                k++;
            }
        }
    }
}