#include <iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<int,int> m;
    for(int i =0;i<n;i++){
        int data;
        cin>>data;
        m[data]++;
    }
    int freq =0;
    for(auto it :m){
        if(freq < it.second){
            freq = it.second;
        }
    }
    for(auto it : m){
        if(it.second == freq){
            cout<<it.first<<endl;
        }
    }
}