#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n1,n2,ans;
    cin>>n1;
    cin>>n2;
    int i = 1;
    int flag=0;
    while(flag<n1){
        ans = (3*i)+2;
        if((ans%n2) != 0){
            cout<<ans<<endl;
            flag++;
        }
        i++;

    }
    return 0;
}