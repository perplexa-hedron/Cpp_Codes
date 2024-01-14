#include <bits/stdc++.h>
#include <climits>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n,0);
        for(int i =0;i<n;i++){
            string name;
            cin>>name;
            int rank;
            cin>>rank;
            arr[rank]++;
        }
        int actual_rank =1;
        int sum =0;
        for(int i=1;i<=n;i++){
            while(arr[i]){
                sum +=abs(actual_rank-i);
                arr[i]--;
                actual_rank++;
            }
        }
        cout<<sum;
    }   
    return 0;
}