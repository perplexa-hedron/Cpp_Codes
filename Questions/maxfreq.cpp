#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
int max(int freq[], int n)
{
    int indx = 0, max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (freq[i] > max)
        {
            indx = i;
            max = freq[i];
        }
    }
    // cout<<indx;
    return indx;
}
char maxfreq(char a[])
{
    int freq[26] = {0};
    for (int i = 0; a[i] != '\0'; i++)
    {
        char x = a[i];
        // cout<<freq[x - 'a'];
        int indx = x - 'a';
        freq[indx]++;
        // cout<<indx<<endl;
    }
    char x = 'a' + max(freq, 26);
    return x;
}
int main()
{
    char a[1000];
    cin.getline(a, 1000);
    cout << maxfreq(a);
    return 0;
}