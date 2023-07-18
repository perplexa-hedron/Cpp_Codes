#include <bits/stdc++.h>
using namespace std;
int dectobin(int n){
    int x=1,ans=0,z=0;
    while(x<=n){
        x*=2;
    }
    x/=2;
    while(x>0){
        z=n/x;
        n-=z*x;
        x/=2;
        ans=ans*10+z;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<dectobin(n);
}