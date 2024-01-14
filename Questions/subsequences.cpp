#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int k =0;
void subs(string str, string ans,string arr[]){
    if(str.length() == 0){
        arr[k] = ans;
        k++;
        return;
    }
    subs(str.substr(1),ans,arr);
    subs(str.substr(1),ans + str[0],arr);
}
int main()
{
    string arr[100];
    int test;
    cin>>test;
    while(test--){
        string str,ans;
        cin>>str;
        subs(str,ans,arr);
        // sort(arr,arr+k);
        for(int i =0;i<k;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl<<k;
        k=0;
    }
    return 0;
}