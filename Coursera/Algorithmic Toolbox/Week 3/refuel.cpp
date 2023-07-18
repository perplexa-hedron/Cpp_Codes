#include <iostream>
#include <vector>

using namespace std;

int compute_min_refills(int dist, int tank, vector<int> &stops)
{
	if (dist <= tank)
		return 0;
	int i = 0;
	int num_stops = 0;
	int current_stop = 0;
	int dist_covered = 0;
	bool flag = false;

	stops.push_back(dist);

	while (dist_covered < dist)
	{
		while (i < stops.size() && stops[i] - current_stop <= tank)
		{
			i++;
			flag = true;
		}
		if (flag)
		{
			if (i == stops.size())
				break;
			current_stop = stops[i - 1];
			dist_covered = current_stop;
			num_stops += 1;
		}
		else
		{
			return -1;
		}
		flag = false;
	}
	return num_stops;
}

int main()
{
	int d;
	cin >> d;
	int m;
	cin >> m;
	int n;
	cin >> n;

	vector<int> stops(n);
	for (size_t i = 0; i < n; ++i)
		cin >> stops.at(i);

	cout << compute_min_refills(d, m, stops) << "\n";

	return 0;
}