#include <bits/stdc++.h>
using namespace std;
int bintodec(int n){
    int a,x=1,y=0;
    while(n>0){
        a=n%10;
        y+=a*x;
        n/=10;
        x*=2;
    }
    return y;
}
int main()
{
    int n;
    cin>>n;
    cout<<bintodec(n);
}