#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int t, k;
    cin >> t >> k;
    priority_queue<int> pq;
    while (t--)
    {
        int option;
        cin >> option;
        if (option == 1)
        {
            int x, y;
            cin >> x >> y;
            pq.push((x * x + y * y));
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        else
        {
            cout << pq.top() << endl;
        }
    }
}