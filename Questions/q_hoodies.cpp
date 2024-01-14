#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int q;
    cin >> q;
    queue<int> q1;
    queue<int> q2;
    queue<int> q3;
    queue<int> q4;
    queue<int> order;
    bool is1 = false, is2 = false, is3 = false, is4 = false;
    while (q--)
    {
        char ch;
        cin >> ch;
        if (ch == 'E')
        {
            int x, y;
            cin >> x>>y;
            if (x == 1)
            {
                q1.push(y);
                if (!is1)
                {
                    order.push(1);
                    is1 = true;
                }
            }
            else if (x == 2)
            {
                q2.push(y);
                if (!is2)
                {
                    order.push(2);
                    is2 = true;
                }
            }
            else if (x == 3)
            {
                q3.push(y);
                if (!is3)
                {
                    order.push(3);
                    is3 = true;
                }
            }
            else
            {
                q4.push(y);
                if (!is4)
                {
                    order.push(1);
                    is4 = true;
                }
            }
        }
        if (ch == 'D')
        {
            int front = order.front();
            if (front == 1)
            {
                if (!q1.empty())
                {
                    cout << "1"
                         << " " << q1.front() << endl;
                    q1.pop();
                }
                if (q1.empty())
                {
                    order.pop();
                    is1 = false;
                }
            }
            else if (front == 2)
            {
                if (!q2.empty())
                {
                    cout << "2"
                         << " " << q2.front() << endl;
                    q2.pop();
                }
                if (q2.empty())
                {
                    order.pop();
                    is2 = false;
                }
            }
            else if (front == 3)
            {
                if (!q3.empty())
                {
                    cout << "3"
                         << " " << q3.front() << endl;
                    q3.pop();
                }
                if (q3.empty())
                {
                    order.pop();
                    is3 = false;
                }
            }
            else
            {
                if (!q4.empty())
                {
                    cout << "4"
                         << " " << q4.front() << endl;
                    q4.pop();
                }
                if (q4.empty())
                {
                    order.pop();
                    is4 = false;
                }
            }
        }
    }
}