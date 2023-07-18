#include <iostream>
#include <vector>
using namespace std;
vector<int> mult2(vector<int> a,vector<int> b,int n,int al,int bl)
{
    vector<int> R(2*n-1);
    if(n=1){
        R[0] = a[al]*b[al];
        return R;
    }
    R = mult2(a,b,n/2,al,bl);
    R = mult2(a,b,n/2,al+n/2,bl+n/2);
    
}
/*vector<int> mult1(vector<int> a,vector<int> b,int n)
{
    vector<int> product(2*n-1);
    for(int i = 0;i<product.size();i++)
    {
        product[i] = 0;
    }
    for(int i =0 ; i<n;i++)
    {
        for(int j = 0; j<n;j++)
        {
            product[i+j] = product[i+j] + a[i] * b[j];
        }
    }
    return product;
}*/
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0; i<a.size();i++)
    {
        cin>>a[i];
    }
    for(int i = 0; i<b.size();i++)
    {
        cin>>b[i];
    }
    int al = a[0];
    int bl = b[0];
    /*vector<int> product = mult1(a,b,n);
    for(int i = 0; i<product.size();i++)
    {
        cout<<product[i]<<" ";
    }*/
    vector<int> product = mult2(a,b,n,al,bl);
    return 0;
}