#include <iostream>
using namespace std;
int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }
    cout<<current<<endl;

    return current % 10;
}

int main() {
    int n;
    cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    cout << c << '\n';
    }