#include <iostream>
#include <climits>
using namespace std;
bool increasing(int n){
    bool ans = 0;
    int j=INT_MIN;
    for(int i = 0; i<n;i++){
        int num;
        cin>>num;
        if(num>j){
            ans = 1;
            j = num;
        }
        else{
            ans = 0;
        }
    }
    return ans;
}
bool decreasing(int n){
    int j = INT_MAX;
    bool ans = 0;
    for(int i = 0; i<n;i++){
        int num;
        cin>>num;
        if(num<j){
            ans = 1;
            j = num;
        }
        else{
            ans = 0;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    /*bool ans = 0;
    int j=INT_MIN;
    for(int i = 0; i<n;i++){
        int num;
        cin>>num;
        if(num>j){
            ans = 1;
            j = num;
        }
        else{
            ans = 0;
        }
    }
    if(ans == 1){
        cout<<"true";
    }
    else{
        cout<<"false";
    }*/
    /*int j = INT_MAX;
    bool ans = 0;
    for(int i = 0; i<n;i++){
        int num;
        cin>>num;
        if(num<j){
            ans = 1;
            j = num;
        }
        else{
            ans = 0;
        }
    }
    if(ans == 1){
        cout<<"true";
    }
    else{
        cout<<"false";
    }*/


    return 0;
}