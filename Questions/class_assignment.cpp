#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int number(int num)
{
    if (num == 0)
    {
        return 1;
    }
    if (num == 1)
    {
        return 2;
    }
    return (number(num - 1) + number(num - 2));
}
int main()
{
    int n;
    cin >> n;
    int num[n];
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    for (int i = 0; i < n; i++)
    {
        // int num;
        // cin >> num;
        cout << "#" << i+1 << " : " << number(num[i]) << endl;
    }
    return 0;
}