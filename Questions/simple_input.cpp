#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,sum=0;
    while(sum>=0){
        cin>>n;
        sum=sum+n;
        if(n>=0){
            cout<<n<<endl;
        }
    }
    return 0;
}