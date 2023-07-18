#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    long long t;
    cin>>t;
    while(t--){
        long long int n,d;
        cin>>n>>d;
        int arr[n];
        for(int i =0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        long long cnt =0;
        for(int i =1;i<n;i++){
            if(abs(arr[i] - arr[i-1])<=d){
                cnt++;
            }
        }
        cout<<cnt;
    }
    return 0;
}