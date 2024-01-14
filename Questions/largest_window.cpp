#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char arr[200];
    cin >> arr;
    int n = strlen(arr);
    int c_len = 1;
    int max_len = 1;
    int visited[200] = {-1};
    visited[arr[0]] = 0;
    for (int i = 0; i < n; i++)
    {
        int last_occ = visited[arr[i]];
        if (last_occ == -1 || i - c_len > last_occ)
        {
            c_len++;
        }
        else
        {
            if (c_len > max_len)
            {
                max_len = c_len;
            }
            c_len = i - last_occ;
        }
        visited[arr[i]] = i;
    }
    if (c_len > max_len)
    {
        max_len = c_len;
    }
    cout << max_len << endl;
    return 0;
}