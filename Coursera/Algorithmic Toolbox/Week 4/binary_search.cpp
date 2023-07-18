#include <iostream>
#include <vector>

using namespace std;
int binary_search(const vector<int> &a, size_t left, size_t right, int x) {
	if (left < 0 || right > a.size() || left > right) return -1;
	size_t mid = left + (right - left) / 2;
	if (a.at(mid) == x) {
		return mid;
	} else if (a.at(mid) > x) {
		return binary_search(a, left, mid - 1, x);
	} else {
		return binary_search(a, mid + 1, right, x);
	}
}

int linear_search(const vector<int> &a, int x) {
	for (size_t i = 0; i < a.size(); ++i) {
		if (a[i] == x) return i;
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); i++) { cin >> a[i]; }
	int m;
	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; ++i) { cin >> b[i]; }
	for (int i = 0; i < m; ++i) {
		cout << binary_search(a, 0, a.size() - 1, b[i]) << ' ';
	}
}