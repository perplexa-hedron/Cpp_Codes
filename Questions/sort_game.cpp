#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool compare(pair<string, int> p1, pair<string, int> p2)
{
    if (p1.second == p2.second)
    {
        return p1.first < p2.first;
    }
    return p1.second > p2.second;
}
int main()
{
    int x, n;
    cin >> x;
    cin >> n;
    vector<pair<string, int>> p(n);
    for (int i = 0; i < n; i++)
    {
        string name;
        int sal;
        cin >> name >> sal;
        p[i] = make_pair(name, sal);
    }
    sort(p.begin(), p.end(), compare);

    for (auto i : p)
    {
        if (true)
        {
            cout << i.first << " " << i.second << endl;
        }
    }
    return 0;
}