#include <iostream>
#include<unordered_map>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int l;
        cin>>l;
        unordered_map<int,int> m;
        for(int i =0;i<l;i++){
            int data;
            cin>>data;
            m[data] = data;
        }
        int q;
        cin>>q;
        while(q--){
            int key;
            cin>>key;
            if(m.count(key)){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}