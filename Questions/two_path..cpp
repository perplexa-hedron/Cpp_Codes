#include <iostream>
// #include <vector>
using namespace std;
int main()
{
    int t, n, m;
    cin >> t >> n >> m;
    int *a1 = new int[n], *a2 = new int[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a2[i];
    }
    int x = max(n, m);
    int *aux = new int[x];
    int i=0,sum=0;
    while(i<x){
        if(a1[0] + a1[1] >= a2[0]+a2[1]){
            aux[i]= a1[i];
        }
        else{
            aux[i]= a2[i];
        }
        if(a1[i] == a2[i]){
            if(a1[i+1] > a2[i+1]){
                aux[i]=a1[i];
            }
            else if(a2[i+1] >a1[i+1]){
                aux[i]=a2[i];
            }
            sum += aux[i];
            cout<<aux[i]<<endl;
            // sum +=aux[i];
            // cout<<aux[i]<<endl;
        }
        else{
            sum += aux[i];
            cout<<aux[i]<<endl;
        }
        i++;
    }
    //cout<<sum;
    return 0;
}