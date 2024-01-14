#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,j=0,l=0,m=1;
    cin>>n;
    for(int i = 0;i<=n;i++){
        for(int k = 0;k<i;k++){
            cout<<j<<"\t";
            j=l+m;
            m=l;
            l=j;
        }
        cout<<endl;
    }
    return 0;
}