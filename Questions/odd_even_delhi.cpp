#include <iostream>
using namespace std;
void odd_even(int num)
{
    int sume = 0, sumo = 0,n;
    while (num != 0){
        n=num%10;
        if(n%2 == 0){
            sume += n;
        }
        else{
            sumo += n;
        }
        num = num/10;
    }
    if(sume %4==0 || sumo %3==0){
        cout<<"Yes"<<"\n";
    }
    else{
        cout<<"No"<<"\n";
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i<n ; i++)
    {
        int num;
        cin >> num;
        odd_even(num);
    }
    return 0;
}