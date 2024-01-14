#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
template <typename T>
class queue
{
    stack<T> s1, s2;

public:
    void push(T data)
    {
        s1.push(data);
    }
    void pop()
    {
        if (s1.empty())
        {
            return;
        }
        else
        {
            while (s1.size() > 1)
            {
                s2.push(s1.top());
                s1.pop();
            }
            s1.pop();
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    T front()
    {
        while (s1.size() > 1)
        {
            s2.push(s1.top());
            s1.pop();
        }
        T ele = s1.top();
        s1.pop();
        s2.push(ele);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return ele;
    }
    int size()
    {
        return s1.size() + s2.size();
    }
    bool empty()
    {
        return size() == 0;
    }
};
int main()
{
    queue<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.empty())
    {
        cout << s.front() << " ";
        s.pop();
    }
    return 0;
}