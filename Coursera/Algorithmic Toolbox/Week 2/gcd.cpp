#include <iostream>
using namespace std;
/*long long gcd(int a, int b){
    int best = 0;
    for(int i = 2; i <= max(a,b); i++){
        if (a%i==0 && b%i==0){
            best = i;
        }
    }
    return best;
}
*/


long long gcd(int a, int b){
    if (b == 0){
        return a;
    }
    // else{
        // int a1= a%b;
        return gcd(b,a%b);
    // }
}
int main(){
    int a,b;
    cin>>a>>b;
    int hcf = gcd(a,b);
    cout<<hcf<<endl;
}