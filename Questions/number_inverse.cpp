#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    int j=0;
    vector<int> no;
    while(n>0){
        no.push_back(n%10);
        n=n/10;
        j++;
    }
    for(int i = 0;i<no.size();i++){
        int temp=no[i];
        no[i] = no[no.size()-i-1];
        no[no.size()-i-1] = temp;
    }
    for(int i = 0;i<no.size();i++){
        cout<<no[i];
    }
    return 0;
}