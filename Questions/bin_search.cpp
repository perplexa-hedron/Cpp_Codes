#include <iostream>
#include <vector>
using namespace std;
int bins(int *a,int s,int e,int key){
    if(s>e){
        return -1;
    }
    int m = (s+e)/2;
    if(a[m] == key){
        return m;
    }
    else if(a[m] > key){
        return bins(a,m+1,e,key);
    }
    else if(a[m]<key){
        return bins(a,s,m-1,key);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int key;
    cin>>key;
    cout<<bins(a,0,n-1,key);
    return 0;
}