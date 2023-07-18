#include <iostream>
#include <vector>
using namespace std;
int ways(int n){
    if(n ==1){
        return 1;
    }
    if(n<=0){
        return 1;
    }
    return ways(n-1)+(n-1)*ways(n-2);
}
int main()
{
    int n;
    cin>>n;
    cout<<ways(n);
    return 0;
}