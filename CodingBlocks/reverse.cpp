#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    long long int n;
    long long int sum=0;
    cin>>n;
    //int i =0;
    while(n!=0){
        sum = sum*10 + n%10;
        n = n/10;
        //cout<<r;
    }
    if(sum > (2e31-1) || sum<(-2e32)){
        cout<<0;
        return 0;
    }

    else{cout<<sum<<endl;}
    return 0;
}