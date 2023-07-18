#include <iostream>
#include <string>
using namespace std;
string ics[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
void int2str(long long int n){
    if(n==0){
        return;
    }
    long long int num = n%10;
    // cout<<ics[num]<<" ";
    int2str(n/10);
    cout<<ics[num]<<" ";
}
int main()
{
    long long int n;
    cin>>n;
    int2str(n);
    return 0;
}