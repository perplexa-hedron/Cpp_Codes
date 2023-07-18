#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n,st,sp;
    cin>>n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<sp;j++){
            cout<<" ";
            }
        for(int k = 0;k<st;k++){
                cout<<"*";
        }
        if(i>0 && i<n-1){
            for(int k =0;k<n-2;k++){
                cout<<" ";
            }
            cout<<"*";
        }
        if(i>0 && i<n-2){
            st=1;
        }
        else{
            st=n;
        }
        sp--;
        cout<<endl;
    }
    return 0;
}