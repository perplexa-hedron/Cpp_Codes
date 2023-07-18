#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string largest_number(vector<string> a) {
	stringstream ret;
	sort(a.begin(), a.end(), [](const string& a, const string& b) {
		return (a + b) < (b + a);
	});
	reverse(a.begin(), a.end());

	for (auto&& i : a) { ret << i; }
	string result;
	ret >> result;
	return result;
}

int main() {
	int n;
	cin >> n;
	vector<string> a(n);
	for (size_t i = 0; i < a.size(); i++) { cin >> a[i]; }
	cout << largest_number(a);
}