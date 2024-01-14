#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct circle
{
    int start;
    int end;
};
bool compare(circle a, circle b)
{
    if (a.end == b.end)
    {
        return a.start < b.start;
    }
    return a.end < b.end;
}
void count_circles(int *c, int *r, int n)
{
    circle diameter[n];
    for (int i = 0; i < n; i++)
    {
        diameter[i].start = c[i] - r[i];
        diameter[i].end = c[i] + r[i];
    }
    sort(diameter,diameter+n,compare);
    int cnt =0;
    int curr = diameter[0].end;
    for(int i =1;i<n;i++){
        if(diameter[i].start>curr){
            curr = diameter[i].end;
        }
        else{
            cnt++;
        }
    }
    cout<<cnt<<endl;
}
int main()
{
    int n;
    cin >> n;
    int c[n];
    int r[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i] >> r[i];
    }
    count_circles(c, r, n);

    return 0;
}