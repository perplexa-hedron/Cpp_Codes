#include <iostream>
#include <climits>
using namespace std;
// void selection(int arr[n])
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         int min = i;
//         for (int j = i; j < n; j++)
//         {
//             if (arr[j] < arr[min])
//             {
//                 min = j;
//             }
//         }
//         swap(arr[i], arr[min]);
//     }
// }
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // selection(arr[n]);
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

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}