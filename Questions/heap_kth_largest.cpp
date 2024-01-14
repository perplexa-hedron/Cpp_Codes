#include <iostream>
#include <queue>
using namespace  std;
int main(){
    int n,k;
    cin>>n>>k;
    priority_queue<int> pq;
    for(int i =0;i<n;i++){
        int data;
        cin>>data;
        pq.push(data);
    }
    while(k>1){
        pq.pop();
        k--;
    }
    cout<<pq.top();
    return 0;
}