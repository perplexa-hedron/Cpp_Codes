#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long int fibo[n];
	if (n <=1)
	{
		cout << n << endl;
	}
	else
	{
		fibo[0] = 0;
		fibo[1] = 1;
		for (int i = 2; i <n; ++i)
		{
			fibo[i] = fibo[i-1] + fibo[i - 2];
			//cout<<fibo[i]<<endl;
		}
		cout << fibo[n-1] << endl;
	}
	
}