#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int max,min,step;
    cin>>min>>max>>step;
    int i = min;
    while(i <=max){
        int c = (5*(i-32))/9;
        cout<<i<<"\t"<<c<<endl;;
        i +=step;
    }
    return 0;
}