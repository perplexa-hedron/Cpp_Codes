#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int a,b,c;
    float r1,r2;
    cin>>a>>b>>c;
        r1=(-b + sqrt(b^2 - 4*a*c))/2*a;
        r2=(-b - sqrt(b^2 - 4*a*c))/2*a;
        if(r1!=r2){
            cout<<"Real and Distinctive"<<endl;
            cout<<r1<<r2<<endl;
        }
    return 0;
}