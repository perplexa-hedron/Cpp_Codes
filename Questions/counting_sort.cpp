#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
void csort(int *arr,int n){
    int maxm = INT_MIN;
    for(int i=0;i<n;i++){
        maxm = max(maxm,arr[i]);
    }
    int *freq = new int[maxm+1]{0};
    for(int i = 0;i<n;i++){
        freq[arr[i]]++;
    }
    int j =0;
    for(int i =0;i<=maxm;i++){
        while(freq[i] > 0){
            arr[j] = i;
            freq[i]--;
            j++;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    csort(arr,n);
    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}