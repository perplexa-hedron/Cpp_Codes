#include <iostream>
using namespace std;
int fact(int n){
    int f=1;
    for(int i=1;i<=n;i++){
        f*=i;
    }
    return f;
}
int main()
{
    int n,ptrn;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            ptrn=fact(i)/(fact(j)*fact(i-j));
            cout<<ptrn<<" ";
        }
        cout<<endl;
    }
}