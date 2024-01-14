#include <iostream>
#include <vector>
using namespace std;
void merge(int *a,int *b,int *c,int s,int e){
    int mid = (s+e)/2;
    int i=s, j=mid+1,k =s;

    while(i<=mid && j<=e){
        if(b[i] <=c[j]){
            a[k++] = b[i++];
        }
        else{
            a[k++] = c[j++];
        }
    }
    while(i<=mid){
        a[k++] = b[i++];
    }
    while(j<=e){
        a[k++] =  c[j++];
    }
}
void msort(int *a,int s, int e){
    if(s>=e){
        return;
    }
    int b[100], c[100];
    int m = (s+e)/2;
    for(int i =s;i<=m;i++){
        b[i] = a[i];
    }
    for(int i =m+1;i<=e;i++){
        c[i] = a[i];
    }
    msort(b,s,m);
    msort(c,m+1,e);
    merge(a,b,c,s,e);

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

    msort(a,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i]<<" ";
    }
    return 0;
}