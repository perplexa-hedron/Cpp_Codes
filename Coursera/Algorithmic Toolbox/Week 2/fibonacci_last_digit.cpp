#include <bits/stdc++.h>
#include <climits>
using namespace std;
int last_digit(int n)
{
	if (n<=1){
		return n;
	}

	int lfibo[n];
	lfibo[0]=0;
	lfibo[1]=1;
	for(int i =2; i<=n;i++)
	{
		lfibo[i] = lfibo[i-1]%10 + lfibo[i-2]%10;
	}
	return lfibo[n]%10;
}
int main()
{
	int n;
	cin>>n;
	cout<<last_digit(n)<<endl;
	return 0;
}