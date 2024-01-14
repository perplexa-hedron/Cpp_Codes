#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<pair<int,int>> s;
    s.insert(make_pair(10,1));
    s.insert(make_pair(20,5));
    s.insert(make_pair(30,15));
    s.insert(make_pair(50,10));
    s.insert(make_pair(40,25));
    s.insert(make_pair(60,25));
    s.insert(make_pair(70,10));
    s.insert(make_pair(80,35));
    s.insert(make_pair(90,20));
    for(auto p : s){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}