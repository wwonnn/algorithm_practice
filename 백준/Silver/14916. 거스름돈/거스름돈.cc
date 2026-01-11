#include <iostream>

using namespace std;

long long DP[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	DP[2] = 1;
	DP[4] = 2;
	DP[5] = 1;
	for (int i = 6; i <= N; i++) {
		if (DP[i - 2] != 0 && DP[i - 5] != 0) {
			DP[i] = min(DP[i - 2], DP[i - 5]) + 1;
		}
		else if (DP[i - 2] != 0) {
			DP[i] = DP[i - 2] + 1;
		}
		else if (DP[i - 5] != 0) {
			DP[i] = DP[i - 5] + 1;
		}
	}

	if (DP[N] != 0) cout << DP[N];
	else cout << -1;
}