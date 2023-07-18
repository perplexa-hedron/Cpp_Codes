#include <iostream>
#include <vector>
using namespace std;
long long int power(long long int n, long long int p){
    if(p == 0){
        return 1;
    }
    return n*power(n,p-1);
}
int main()
{
    long long int n,p;
    cin>>n>>p;
    cout<<power(n,p);
    return 0;
}