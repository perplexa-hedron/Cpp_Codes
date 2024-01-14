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
void solution(int arr[], int am, int n)
{
    sort(arr, n);
    int i = 0, j = n - 1, k = 0;
    int *aux = new int[n];
    while (i < j)
    {
        int x = 0, y = n - 1;
        if (arr[i] + arr[j] > am)
        {
            j--;
        }
        else if (arr[i] + arr[j] < am)
        {
            i++;
        }
        else
        {
            if (n <= 2)
            {
                x = i;
                y = j;
                cout << "Deepak should buy roses whose prices are " << arr[x] << " and " << arr[y] << "." << endl;
            }
            if (i > x && j < y)
            {
                x = i;
                y = j;
                cout << "Deepak should buy roses whose prices are " << arr[x] << " and " << arr[y] << "." << endl;
            }
            // ans(aux,n);
            // cout << arr[x] << " and " << arr[y] << endl;
            i++;
        }
    }
    // cout << endl;
}
int main()
{
    long long int n, t;
    cin >> t;
    for (int i = 0; i <= t; i++)
    {
        int am;
        cin >> n;
        int *arr = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        cin >> am;

        solution(arr, am, n);
        // cout<<endl;
    }
    return 0;
}