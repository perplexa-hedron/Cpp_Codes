#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <stack>
using namespace std;
long long int getMaxArea(vector<long long int> arr, long long int n)
{
	stack<long long int> s;

	long long int maxarea = 0;
	long long int tp;
	long long int area;
	long long int i = 0;
	while (i < n)
	{
		if (s.empty() || arr[s.top()] <= arr[i])
			s.push(i++);
		else
		{
			tp = s.top();
			s.pop();
			area = arr[tp] * (s.empty() ? i : i - s.top() - 1);
			if (maxarea < area)
				maxarea = area;
		}
	}
	while (s.empty() == false)
	{
		tp = s.top();
		s.pop();
		area = arr[tp] * (s.empty() ? i : i - s.top() - 1);

		if (maxarea < area)
			maxarea = area;
	}

	return maxarea;
}

int main()
{
	long long int n;
	cin >> n;
	vector<long long int> arr(n);
	for (long long int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << getMaxArea(arr, n);
	return 0;
}
