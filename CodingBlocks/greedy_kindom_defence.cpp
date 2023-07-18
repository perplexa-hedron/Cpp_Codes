#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    int t, l=8, b=8, n;
    // cin >> t;
    int x[100000], y[10000];
    // while (t--)
    // {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i]>>y[i];
        }
        sort(x,x+n);
        sort(y,y+n);
        int dx =x[0];
        int dy = y[0]-1;
        for(int i =1;i<n;i++){
            dx = max(dx,x[i]-x[i-1]-1);
            dy = max(dy,y[i]-y[i-1]-1);
        }
        dx = max(dx,l-x[n-1]);
        dy = max(dy,b-y[n-1]);
        cout<<dx*dy<<endl;
    // }
    return 0;
}