#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
void intersection(int a[],int n,int b[],int c[])
{
    int i,k=0;
    unordered_map<int,int> m;
    for(i=0;i<n;i++)
    {
        m[a[i]]=m[a[i]]+1;
    }
    for(i=0;i<n;i++)
    {
        if(m.count(b[i]))
        {
            if(m[b[i]]>0)
            {
            c[k]=b[i];
            k++;
            }
            m[b[i]]=m[b[i]]-1;
        }
    }

    sort(c,c+k);
    cout<<"[";
    for(int i=0;i<k;i++)
        {
        cout<<c[i];
        if(i!=k-1) cout<<", ";
        }
        cout<<"]";
}
int main ()
{
    int n,a[100000],b[100000],c[100000];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    intersection(a,n,b,c);
}
