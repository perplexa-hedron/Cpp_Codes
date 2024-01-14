#include <iostream>
#include <math.h>
using namespace std;
int trailing(int n){
    int ans =1,sum=0,i=1;
    while(ans !=0){
        int div = pow(5,i);
        ans = floor(n/div);
        sum +=ans;
        i++;
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    cout<<trailing(n);
    
    return 0;
}