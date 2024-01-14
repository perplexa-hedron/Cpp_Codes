#include <iostream>
#include <vector>
using namespace std;
int main()
{
    char a;
    cin>>a;
    if(int(a) >= 65 && int(a) <=90){
        cout<<"UPPERCASE";
    }
    else if(int(a) >= 97 && int(a) <=122){
        cout<<"lowercase";
    }
    else{
        cout<<"Invalid";
    }
    return 0;
}