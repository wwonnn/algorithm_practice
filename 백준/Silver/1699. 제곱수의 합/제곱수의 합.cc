#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DP[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i <= n; i++) {
		DP[i] = 1e9;
	}

	DP[0] = 0;
	DP[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j * j <= i; j++) {
			DP[i] = min(DP[i], DP[i - j * j] + 1);
		}
	}

	cout << DP[n];
}