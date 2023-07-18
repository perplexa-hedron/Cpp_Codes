// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//     int t, n;
//     cin >> t;
//     for (int i = 0; i < t; i++)
//     {
//         cin >> n;
//         long long int t[100001];
//         // int *t = new int[n];
//         for (int j = 0; j < n; j++)
//         {
//             cin >> t[i];
//         }
//         // cout<<t[0]-t[1]<<endl;
//         int sum = 0;
//         int diff;
//         for (int j = 0; j < n - 1; j++)
//         {
//             diff = t[j] - t[j - 1];
//             // cout<<diff;
//             {
//                 if (diff >= 0)
//                 {
//                     sum += diff;
//                     cout << sum << "__" << endl;
//                 }
//             }
//         }

//         // cout << sum << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        long long int t[100001];
        for (int j = 0; j < n; j++)
        {
            cin >> t[j];
        }
        int water = 0;
        int left_max = 0;
        int right_max = 0;
        int lo = 0;
        int hi = n - 1;

        while (lo <= hi)
        {

            if (t[lo] < t[hi])
            {

                if (t[lo] > left_max)
                {
                    left_max = t[lo];
                }
                else
                {

                    water += left_max - t[lo];
                }
                lo++;
            }
            else
            {

                if (t[hi] > right_max)
                {
                    right_max = t[hi];
                }
                else
                {
                    water += right_max - t[hi];
                }
                hi--;
            }
        }
        cout << water << endl;
    }
    return 0;
}