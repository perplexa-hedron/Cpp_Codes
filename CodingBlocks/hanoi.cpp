#include <iostream>
#include <vector>
using namespace std;
int k = -1;
void hanoi(int n, string src, string hlp, string dst)
{
    if (n == 0)
    {
        k++;
        return;
    }
    hanoi(n - 1, src, dst, hlp);
    cout << "Move " << n << "th disc from " << src << " to " << dst << endl;
    hanoi(n - 1, hlp, src, dst);
}
int main()
{
    int n;
    cin >> n;
    // string T1,T2,T3;
    hanoi(n, "T1", "T3", "T2");
    cout << k;
    return 0;
}