#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    bool prime=0;
    int i =2;
    while(i<=sqrt(n)){
        if(n%i==0){
            prime=0;
            break;
        }
        else{
        prime=1;
        }
        i++;
    }
    if(prime==1){
        cout<<"Prime";
    }
    else{
        cout<<"Not Prime";
    }
    return 0;
}