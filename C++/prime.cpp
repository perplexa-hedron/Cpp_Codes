#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    bool flag;
    cout<<"Enter the number: ";
    cin>>n;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            cout<<"Not prime";
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"Prime";
    }
}