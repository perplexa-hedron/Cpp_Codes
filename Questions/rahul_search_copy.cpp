// Search an element in sorted and rotated
// array using single pass of Binary Search
#include <iostream>
using namespace std;

// Returns index of key in arr[l..h] if
// key is present, otherwise returns -1
int search(int arr[], int l, int h, int key)
{
	if (l > h)
		return -1;

	int mid = (l + h) / 2;
	if (arr[mid] == key)
		return mid;

	/* If arr[l...mid] is sorted */
	if (arr[l] <= arr[mid]) {
		/* As this subarray is sorted, we can quickly
		check if key lies in half or other half */
		if (key >= arr[l] && key <= arr[mid])
			return search(arr, l, mid - 1, key);
		/*If key not lies in first half subarray,
		Divide other half into two subarrays,
		such that we can quickly check if key lies
		in other half */
		return search(arr, mid + 1, h, key);
	}

	/* If arr[l..mid] first subarray is not sorted, then
	arr[mid... h] must be sorted subarray */
	if (key >= arr[mid] && key <= arr[h])
		return search(arr, mid + 1, h, key);

	return search(arr, l, mid - 1, key);
}

// Driver program
int main()
{
	int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;
	int i = search(arr, 0, n - 1, key);

	if (i != -1)
		cout << i << endl;
	else
		cout << -1;
}

// This code is contributed by Aditya Kumar (adityakumar129)
