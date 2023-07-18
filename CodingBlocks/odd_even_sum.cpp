#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long int n;
    int sum_odd=0,sum_even=0;
    cin>>n;
    bool pos = 0;
    while(n!=0){
        if(pos==0){
            sum_odd+=n%10;
            n=n/10;
            pos = 1;
        }
        else if(pos=1){
            sum_even += n%10;
            n=n/10;
            pos= 0;
        }
    }
    cout<<sum_odd<<endl<<sum_even;
    return 0;
}