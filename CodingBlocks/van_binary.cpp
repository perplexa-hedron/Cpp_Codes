#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long num;
    for(int i = 0;i<n;i++){
        cin>>num;
        int j =0;
        int sum =0;
        while(num>0){
            int r = num%10;
            sum += r*pow(2,j);
            num = num/10;
            j++;
        }
        cout<<sum<<endl;
    }
    return 0;
}