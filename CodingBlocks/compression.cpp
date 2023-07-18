// #include <iostream>
// #include <vector>
// #include <cstring>
// using namespace std;
// void compression(char a[])
// {
//     int freq[26] = {0};
//     for (int i = 0; a[i] != '\0'; i++)
//     {
//         int indx = a[i] - 'a';
//         freq[indx]++;
//     }
//     int i = 0;
//     while (a[i] != 0)
//     {
//         char x = a[i];
//         if (freq[x - 'a'] <= 1)
//         {
//             cout << a[i];
//             i++;
//         }
//         else if (freq[x - 'a'] > 1)
//         {
//             cout << a[i] << freq[x - 'a'];
//             i += freq[x - 'a'];
//         }
//     }
// }
// int main()
// {
//     char a[1001];
//     cin.getline(a, 1001);
//     compression(a);
//     return 0;
// }
#include <iostream>
#include <vector>
using namespace std;
void compression(char a[])
{
    int count = 0;
    int i = 0, j = 0;
    while (a[i] != '\0')
    {
        if (a[i] == a[j])
        {
            count++;
            j++;
        }
        else
        {
            if (count == 1)
            {
                cout << a[i];
            }
            else
            {
                cout << a[i] << count;
            }
            i = j;
            count = 0;
        }
    }
}
int main()
{
    char a[1001];
    cin.getline(a, 1001);
    compression(a);
    return 0;
}