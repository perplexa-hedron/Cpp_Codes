#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int m = 1000000007;
    long long int sum = 0;
    int *a = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int *temp = new int[n];

        for (int j = 0; j < n; j++)
        {
            temp[j] = 0;
        }

        int x;
        cin >> x;

        int sum = 0;
        if (x == 0)
        {
            for (int j = 0; j < n; j++)
            {
                temp[j] = (a[j] << 1) % m;
            }
        }

        else
        {
            temp[x] = (a[x] + a[0]) % m;
            int j = x - 1;
            while (j != x)
            {
                int index = j - x;
                if (index < 0)
                    index += n;
                temp[j] = (a[j] + a[index]) % m;
                j--;
                if (j < 0)
                {
                    j = n - 1;
                }
            }
        }
        a = temp;
    }

    for (int i = 0; i < n; i++)
    {
        sum = (sum + a[i]) % m;
    }

    cout << sum << endl;
    return 0;
}
