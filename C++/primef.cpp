#include <iostream>
#include <math.h>
using namespace std;
bool isprime(int num){
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int n1,n2;
    cout<<"Enter the limits: ";
    cin>>n1>>n2;
    for(int i=n1;i<=n2;i++){
        if(isprime(i)){
            cout<<i<<endl;
        }
    }
    return 0;
}