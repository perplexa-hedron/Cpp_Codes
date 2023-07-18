
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

long long max_dot_product(vector<int> a, vector<int> b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	vector<long long> c;
	c.reserve(a.size());

	transform(a.begin(), a.end(), b.begin(), back_inserter(c),
				   multiplies<long long>());

	long long result = accumulate(c.begin(), c.end(), 0ll);

	return result;
}

int main() {
	size_t n;
	cin >> n;
	vector<int> a(n), b(n);
	for (size_t i = 0; i < n; i++) { cin >> a[i]; }
	for (size_t i = 0; i < n; i++) { cin >> b[i]; }
	cout << max_dot_product(a, b) << endl;
}