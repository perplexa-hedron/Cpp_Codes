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
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<fact(n)<<endl;
}