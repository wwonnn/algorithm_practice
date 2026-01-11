#include <iostream>

using namespace std;

int DP[5005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	fill(DP, DP + 5000, 0);

	DP[3] = DP[5] = 1;
	for (int i = 6; i <= N; i++) {
		if (DP[i - 3] != 0) DP[i] = DP[i - 3] + 1;
		if (DP[i - 5] != 0) DP[i] = DP[i - 5] + 1;
	}

	if (DP[N] == 0) cout << -1;
	else cout << DP[N];
}