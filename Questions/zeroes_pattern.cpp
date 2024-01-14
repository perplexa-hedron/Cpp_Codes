#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,j=0;
    cin>>n;
    for(int i =0;i<=n;i++){
        for(int k = 0;k<i;k++){
            if(k==0 || k==i-1){
                cout<<j<<"\t";
            }
            else{
                cout<<0<<"\t";
            }
        }
        ++j;
        cout<<endl;
    }
    return 0;
}