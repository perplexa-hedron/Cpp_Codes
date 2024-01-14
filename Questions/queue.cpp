#include <iostream>
#include <list>
#include <forward_list>
#include <queue>
using namespace std;
// class queue
// {
//     int cs;
//     list<int> l;

// public:
//     queue()
//     {
//         cs = 0;
//     }
//     bool empty()
//     {
//         return cs == 0;
//     }
//     void push(int data)
//     {
//         l.push_back(data);
//         cs++;
//     }
//     void pop()
//     {
//         if (!empty())
//         {
//             cs--;
//             l.pop_front();
//         }
//     }
//     int front(){
//         return l.front();
//     }
// };


// class queue
// {
//     int *arr;
//     int f, r, cs, ms;
// public:
//     queue(int ds = 5)
//     {
//         arr = new int[ds];
//         cs = 0;
//         ms = ds;
//         f = 0;
//         r = ms - 1;
//     }
//     bool full()
//     {
//         return cs == ms;
//     }
//     bool empty()
//     {
//         return cs == 0;
//     }
//     void push(int data)
//     {
//         if (!full())
//         {
//             r = (r + 1) % ms;
//             arr[r] = data;
//             cs++;
//         }
//     }
//     void pop()
//     {
//         if (!empty())
//         {
//             f = (f + 1) % ms;
//             cs--;
//         }
//     }
//     int front()
//     {
//         if (!empty())
//         {
//             return arr[f];
//         }
//         else
//         {
//             return -1;
//         }
//     }
//     ~queue()
//     {
//         if (arr != NULL)
//         {
//             delete[] arr;
//             arr = NULL;
//         }
//     }
// };


int main(){
    queue <int> q;
    for(int i =1;i<=10;i++){
        q.push(i*i);
    }
    q.pop();
    q.pop();
    while(!q.empty()){
        cout<<q.front()<<" "<<q.back()<<endl;
        q.pop();
    }
    return 0;
}