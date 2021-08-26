#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	// perform Sieve of Eratosthenes (mark the prime numbers)
	const int MAX = (int) 1e7;
	vector<bool> prime(MAX + 1, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= MAX; i++) {
		if (prime[i]) {
			for (int j = i * i; j <= MAX; j+= i) {
				prime[j] = false;
			}
		}
	}
	// pre-count the prime numbers depending on where the number is
	int cnt = 0;
	vector<int> prefix_prime(MAX + 1);
	for (int i = 1; i <= MAX; i++) {
		if (prime[i]) {
			cnt++;
		}
		prefix_prime[i] = cnt;
	}
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		if (n == 2) {
			// edge case #1
			cout << 1;
		} else if (n == 3) {
			// edge case #2
			cout << 2;
		} else {
			// count the prime numbers that are greater than ('n' / 2)
			int extra = prefix_prime[n] - prefix_prime[n / 2];
			// add 1 to the answer since all the other numbers are in one (1) main group
			cout << 1 + extra;
		}
		cout << '\n';
	}
	return 0;
}
