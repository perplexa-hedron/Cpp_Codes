#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <stack>
using namespace std;
class mmstack
{
    vector<int> stack;
    vector<int> mins;
    vector<int> maxs;

public:
    void push(int data)
    {
        int cmin = data;
        int cmax = data;
        if (mins.size())
        {
            cmin = min(mins[mins.size() - 1], data);
            cmax = max(maxs[maxs.size() - 1], data);
        }
        mins.push_back(cmin);
        maxs.push_back(cmax);
        stack.push_back(data);
    }
    int get_min()
    {
        return mins[mins.size() - 1];
    }
    int get_max()
    {
        return maxs[maxs.size() - 1];
    }
    bool empty()
    {
        return (stack.size() == 0);
    }
    void pop()
    {
        mins.pop_back();
        maxs.pop_back();
        stack.pop_back();
    }
    int top()
    {
        return stack[stack.size() - 1];
    }
};
void nextgreater(int arr[], int n)
{
    stack<int> max;
    int i = 0;
    while (i < n - 1)
    {
        if (max.empty())
        {
            max.push(arr[i]);
            i++;
        }
        else
        {
            if (arr[i] > max.top())
            {
                cout << max.top() << "," << arr[i] << endl;
                max.push(arr[i]);
                i++;
            }
            else
            {
                cout << max.top() << "," << arr[i] << endl;
                i++;
            }
        }
    }
    cout << arr[n - 1] << "," << -1 << endl;
}
void transfer(stack<int> &s1, stack<int> &s2, int n)
{
    for (int i = 0; i < n; i++)
    {
        s2.push(s1.top());
        s1.pop();
    }
}
void reverse(stack<int> &s1)
{
    stack<int> s2;
    int n = s1.size();
    for (int i = 0; i < n; i++)
    {
        int x = s1.top();
        s1.pop();
        transfer(s1, s2, n - i - 1);
        s1.push(x);
        transfer(s2, s1, n - i - 1);
    }
}
void bottom_insert(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }
    int data = s.top();
    s.pop();
    bottom_insert(s, x);
    s.push(data);
}
void recursive_reverse(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int x = s.top();
    s.pop();
    recursive_reverse(s);
    bottom_insert(s, x);
}
bool isvalid(char *s)
{
    stack<char> st;
    for (int i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            if (st.empty() || st.top() != '(')
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}
void stock(int *prices, int n, int *span)
{
    stack<int> s;
    s.push(0);
    span[0] = 1;
    for (int i = 1; i <= n - 1; i++)
    {
        int cp = prices[i];
        while (!s.empty() && prices[s.top()] <= cp)
        {
            s.pop();
        }
        if (!s.empty())
        {
            int prev_high = s.top();
            span[i] = i - prev_high;
        }
        else
        {
            span[i] = i + 1;
        }
        s.push(i);
    }
}
int max_rectangle(vector<int> arr, int n)
{
    stack<int> s;
    int maxarea = 0;
    int tp;
    int area;
    int i = 0;
    while (i < n)
    {
        if (s.empty() || arr[s.top()] <= arr[i])
        {
            s.push(i);
            i++;
        }
        else
        {
            tp = s.top();
            s.pop();
            area = arr[tp] * (s.empty() ? i : i - s.top() - 1);
            if (area > maxarea)
                maxarea = area;
        }
    }
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area = arr[tp] * (s.empty() ? i : i - s.top() - 1);

        if (maxarea < area)
            maxarea = area;
    }
    return maxarea;
}
void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}

void cards(stack<int> a, int q, stack<int> &a1, stack<int> &b1)
{
    stack <int> prime;
    int i =1;
    while(i<=q){

    }
    // stack <int> a1;
    // stack <int> b1;
    while (!a.empty())
    {
        if (a.top() % prime.top() == 0)
        {
            b1.push(a.top());
            a.pop();
        }
        else
        {
            a1.push(a.top());
            a.pop();
        }
    }
}
ostream &operator<<(ostream &os, stack<int> s)
{
    print(s);
    return os;
}
int main()
{
    //cards
    // int n, q;
    // cin >> n >> q;
    // stack<int> a;
    // stack<int> a1;
    // stack<int> b1;
    // while (n--)
    // {
    //     int data;
    //     cin >> data;
    //     a.push(data);
    // }
    // cards(a, q, a1, b1);
    // cout << b1 << a1;


    // histogram
    // int n;
    // cin >> n;
    // vector <int> arr(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // cout << max_rectangle(arr, n);

    // stock span
    // int n;
    // cin >> n;
    // int prices[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> prices[i];
    // }
    // int span[n] = {0};
    // stock(prices, n, span);
    // for(auto it : span){
    //     cout<<it<<" ";
    // }
    // cout<<"END";

    // Balanced Parenthesis
    //  char s[int(10e5)] = "((a+b)+(c-d+f))";
    //  if(isvalid(s)){
    //      cout<<"Yes"<<endl;
    //  }
    //  else{
    //      cout<<"No"<<endl;
    //  }

    // reverse stack
    //  stack<int> s;
    //  for (int i = 1; i <= 5; i++)
    //  {
    //      s.push(i);
    //  }
    //  recursive_reverse(s);
    //  while (!s.empty())
    
    //  {
    //      cout << s.top() << endl;
    //      s.pop();
    //  }

//coding
    // int t;
    // cin >> t;
    // stack<int> ans;
    // while (t--)
    // {
    //     int n, data;
    //     cin >> n;
    //     if (n == 1)
    //     {
    //         cout << ans.top() << endl;
    //         ans.pop();
    //     }
    //     // stack<int> ans;
    //     if (n == 2)
    //     {
    //         cin >> data;
    //         ans.push(data);
    //     }
    // }
    return 0;
}