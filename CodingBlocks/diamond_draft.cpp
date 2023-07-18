#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i =0;i<n;i++){
        if(i==0||i==n-1){
            for(int j = 0;j<n;j++){
                cout<<"* ";
            }
        }
        else if(i<=n/2){
            for(int j= i;j<(n/2)+1;j++){
                cout<<"* ";
            }
            for(int j= 0;j<(i/2)+1;j++){
                cout<<"  ";
            }
            for(int j =1;j<(i/2)+1;j++){
                cout<<"  ";
            }
            for(int j=i;j<(n/2)+1;j++){
                cout<<"* ";
            }
        }
        else{
            for(int j=(n/2);j>0;j--){
                cout<<"* ";
            }
            for(int j= (i/2)+1;j<i;j){
                cout<<"  ";
            }
            for(int j =(i/2)+1;j<i;j++){
                cout<<"  ";
            }
            for(int j=(n/2);j>0;j--){
                cout<<"* ";
            }

        }
        cout<<"\n";
    }
    return 0;
}