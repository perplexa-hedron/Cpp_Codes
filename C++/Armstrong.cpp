#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,sum=0,m,x,i;
    cout<<"Enter the number: ";
    cin>>n;
    x=n;
    while(n>0){
        i=n%10;
        sum=sum+round(pow(i,3));
        n/=10;
    }
    cout<<sum<<endl;
    if(sum==x){
        cout<<"Given Number is Armstrong number ";
    }
    else{
        cout<<"Not Armstrong ";
    }
}