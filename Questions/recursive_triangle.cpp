#include <iostream>
#include <vector>
using namespace std;
void tri(int n)
{
    if (n < 1)
    {
        return;
    }
    tri(n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << "* ";
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    tri(n);
    return 0;
}