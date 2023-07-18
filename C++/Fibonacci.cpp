#include <iostream>
using namespace std;
void fibo(int n){
    int x=0,y=1,z;
    cout<<x<<endl<<y<<endl;
    for(int i=3;i<=n;i++){
        z=x+y;
        x=y;
        y=z;
        cout<<z<<endl;
    }

}
int main()
{
    int n;
    cout<<"Enter the limit:";
    cin>>n;
    fibo(n);
}