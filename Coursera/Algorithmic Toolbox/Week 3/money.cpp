#include <iostream>
using namespace std;
int change(int n,int arr[],int m)
{
    int r=n,num=0,i=m-1,sum=0;
    while(i>=0){
        if(r>=arr[i]){
            num=r/arr[i];
            r=r%arr[i];
            sum += num;
            //cout<<num<<" "<<arr[i]<<" "<<r<<" "<<sum<<"\n";
            i--;
        }
        else{
            i--;
        }
    }
    return sum;
}
int main()
{
    int n;
    //cout<<"Enter money: ";
    cin>>n;
    int arr[]={1,5,10};
    cout<<change(n,arr,3);
    return 0;
}