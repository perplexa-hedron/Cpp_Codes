#include <iostream>
#include <algorithm>
// #include <climits>
using namespace std;
int main()
{
    int t,m;
    int a[100001];
    // int ans[100001];
    for(int i =0;i<t;i++){
        cin>>m;
        int n;
        for(int j = 0;j<m;j++){
            cin>> n;
            a[j] = n;
        }
        reverse(a,a+m);
        for(int j=0;j<m;j++){
            cout<<a[j];
        }
    }
    return 0;
}