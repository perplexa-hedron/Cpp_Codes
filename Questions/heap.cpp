#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class heap
{
    vector<int> v;
    bool minheap;
    bool compare(int a, int b)
    {
        if (minheap)
        {
            return a < b;
        }
        else
        {
            return a > b;
        }
    }
    void heapify(int idx)
    {
        int left = 2 * idx;
        int right = left + 1;
        int min_idx = idx;
        int last = v.size() - 1;
        if (left <= last && compare(v[left], v[idx]))
        {
            min_idx = left;
        }
        if (right <= last && compare(v[right], v[min_idx]))
        {
            min_idx = right;
        }
        if (min_idx != idx)
        {
            swap(v[idx], v[min_idx]);
            heapify(min_idx);
        }
    }

public:
    heap(int default_size = 10, bool type = true)
    {
        v.reserve(10);
        v.push_back(-1);
        minheap = type;
    }
    heap(bool type)
    {
        v.push_back(-1);
        minheap = type;
    }
    void push(int d)
    {
        v.push_back(d);
        int idx = v.size() - 1;
        int parent = idx / 2;
        while (idx > 1 && compare(v[idx], v[parent]))
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent /= 2;
        }
    }
    int top()
    {
        return v[1];
    }
    void pop()
    {
        int last = v.size() - 1;
        swap(v[1], v[last]);
        v.pop_back();
        heapify(1);
    }
    bool empty()
    {
        return v.size() == 1;
    }
};

void buildmax_heap(vector<int> &v)
{ // take int i =2 and idx >1 when -1 is in 0th index
    for (int i = 2; i < v.size(); i++)
    { // order nlogn
        int idx = i;
        int parent = i / 2;
        while (idx > 1 && v[idx] > v[parent])
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }
}

void buildmin_heap(vector<int> &v)
{ // take int i =2 and idx >1 when -1 is in 0th index
    for (int i = 2; i < v.size(); i++)
    { // order nlogn
        int idx = i;
        int parent = i / 2;
        while (idx > 1 && v[idx] < v[parent])
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }
}

bool compare(int a, int b, bool minheap)
{
    if (minheap)
    {
        return a < b;
    }
    else
    {
        return a > b;
    }
}

void heapify(vector<int> &v, int idx, bool minheap)
{
    int left = 2 * idx;
    int right = left + 1;

    int min_idx = idx;
    int last = v.size() - 1;

    if (left <= last && compare(v[left], v[idx], minheap))
    {
        min_idx = left;
    }

    if (right <= last && compare(v[right], v[min_idx], minheap))
    {
        min_idx = right;
    }

    if (min_idx != idx)
    {
        swap(v[idx], v[min_idx]);
        heapify(v, min_idx, minheap);
    }
}

void heapify2(vector<int> &v, int idx, bool minheap, int n)
{
    int left = 2 * idx;
    int right = left + 1;

    int min_idx = idx;
    int last = n - 1;

    if (left <= last && compare(v[left], v[idx], minheap))
    {
        min_idx = left;
    }

    if (right <= last && compare(v[right], v[min_idx], minheap))
    {
        min_idx = right;
    }

    if (min_idx != idx)
    {
        swap(v[idx], v[min_idx]);
        heapify2(v, min_idx, minheap, n);
    }
}

void print(vector<int> vec)
{
    for (int i = 1; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void buildheap(vector<int> &vec, bool minheap)
{
    for (int i = vec.size() - 1 / 2; i >= 1; i--)
    {
        heapify(vec, i, minheap);
    }
}

void heapsort(vector<int> &arr, bool minheap)
{
    buildmax_heap(arr);
    int n = arr.size();
    while (n > 1)
    {
        swap(arr[1], arr[n - 1]);
        n--;
        heapify2(arr, 1, minheap, n);
    }
}

class person
{
public:
    string name;
    int age;
    person()
    {
    }
    person(string n, int a)
    {
        name = n;
        age = a;
    }
};

class person_comparator
{
public:
    bool operator()(person a, person b)
    {
        return a.age < b.age;
    }
};

int join_ropes(int ropes[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq(ropes, ropes + n);
    int cost = 0;
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int new_rope = (a + b);
        cost += new_rope;
        pq.push(new_rope);
    }
    return cost;
}
// typedef pair<int,pair<int,int>> node;
vector<int> mergearrays(vector<vector<int>> arr)
{
    vector<int> result;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 0; i < arr.size(); i++)
    {
        pq.push({arr[i][0], {i, 0}});
    }
    while (!pq.empty())
    {
        pair<int, pair<int, int>> current = pq.top();
        pq.pop();
        int element = current.first;
        int x = current.second.first;
        int y = current.second.second;
        result.push_back(element);
        if (y + 1 < arr[x].size())
        {
            pq.push({arr[x][y + 1], {x, y + 1}});
        }
    }
    return result;
}

int main()
{
    // merging n number of arrays
    // int n, m;
    // cin >> n >> m;
    // vector<vector<int>> arr;
    // for (int i = 0; i < n; i++)
    // {
    //     vector<int> row;
    //     for (int j = 0; j < m; j++)
    //     {
    //         int c;
    //         cin >> c;
    //         row.push_back(c);
    //     }
    //     arr.push_back(row);
    // }
    // vector <int> ans = mergearrays(arr);
    // for(auto it :ans){
    //     cout<<it<<" ";
    // }

    // median of input numbers using priority_queue from queue stl
    //  priority_queue<int> leftheap;//minheap
    //  priority_queue<int,vector<int>,greater<int>> rightheap; //maxheap
    //  int d;
    //  cin>>d;
    //  leftheap.push(d);
    //  float med = d;
    //  cout<<med<<endl;
    //  cin>>d;
    //  while(d!=-1){
    //      if(leftheap.size()>rightheap.size()){
    //          if(d<med){
    //              rightheap.push(leftheap.top());
    //              leftheap.pop();
    //              leftheap.push(d);
    //          }
    //          else{
    //              rightheap.push(d);
    //          }
    //          med = (rightheap.top()+leftheap.top())/2.0;
    //      }
    //      else if(rightheap.size()==leftheap.size()){
    //          if(d<med){
    //              leftheap.push(d);
    //              med = leftheap.top();
    //          }
    //          else{
    //              rightheap.push(d);
    //              med = rightheap.top();
    //          }
    //      }
    //      else{
    //          if(d>med){
    //              leftheap.push(rightheap.top());
    //              rightheap.pop();
    //              rightheap.push(d);
    //          }
    //          else{
    //              leftheap.push(d);
    //          }
    //          med = (rightheap.top()+leftheap.top())/2.0;
    //      }
    //      cout<<med<<endl;
    //      cin>>d;
    //  }
    // joining rope question
    //  int ropes[] = {4,3,2,6};
    //  int n =4;
    //  cout<<join_ropes(ropes,n)<<endl;

    // using custom class
     int n;
     cin>>n;
     priority_queue<person,vector<person>,person_comparator> pq;
     for(int i =0;i<n;i++){
         string name;
         int age;
         cin>>name>>age;
         person p(name,age);
         pq.push(p);
     }
     int k;
     cin>>k;
     while(k--){
         person p = pq.top();
         cout<<p.name<<" "<<p.age<<endl;
         pq.pop();
     }

    // heapsort algorithm
    //  vector<int> v;
    //  v.push_back(-1);
    //  int n;
    //  cin>>n;
    //  int temp;
    //  for(int i =0;i<n;i++){
    //      cin>>temp;
    //      v.push_back(temp);
    //  }
    //  heapsort(v,false);
    //  print(v);

    // taking inpur an array and buildng head in N time complexity
    // vector<int> v{-1, 10, 20, 5, 6, 1, 8, 9, 4};
    // print(v);
    // buildheap(v,false);
    // print(v);

    // taking input an array and building heap in nlogn time complexity
    //  heap h(6);
    //  int n;
    //  cin>>n;
    //  vector<int> v{-1,10,20,5,6,1,8,9,4};
    //  print(v);
    //  buildmax_heap(v);
    //  print(v);
    //  buildmin_heap(v);
    //  print(v);

    // taking n input and forming heap
    //  for(int i =0;i<n;i++){
    //      int no;
    //      cin>>no;
    //      h.push(no);
    //  }
    //  while(!h.empty()){
    //      cout<<h.top()<<" ";
    //      h.pop();
    //  }
    return 0;
}