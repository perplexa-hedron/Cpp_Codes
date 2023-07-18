#include <iostream>
#include <deque>
using namespace std;
int main()
{
    int n, k;
    int arr[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    deque<int> q(k);
    int i = 0;
    for (; i < k; i++)
    {
        while (!q.empty() && arr[i] <0)
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    for (; i < n; i++)
    {
        cout << arr[q.front()] << " ";
        while (!q.empty() && q.front() <= i - k)
        {
            q.pop_back();
        }
        while (!q.empty() && arr[i] <0)
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    if(arr[q.front()]<0){
        cout<<arr[q.front()]<<endl;
    }
    else{
        cout<<0<<endl;
    }
    return 0;
}