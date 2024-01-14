#include <bits/stdc++.h>
using namespace std;
int connection(vector<int> green,vector<int> black){
    if(black.size()==0){
        return 0;
    }
    int sum =0;
    for(int i =0;i<black.size();i++){
        sum += abs(black[i] - green[i]);
    }
    return sum;
}
int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> green(n),black(n);
        for(int i =0;i<n;i++){
            cin>>green[i];
        }
        for(int i =0;i<n;i++){
            cin>>black[i];
        }
        sort(green.begin(),green.end());
        sort(black.begin(),black.end());
        cout<<connection(green,black);
    }
    return 0;
}