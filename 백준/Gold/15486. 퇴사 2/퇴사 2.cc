#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int DP[1500005];
int info[1500005][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> info[i][0] >> info[i][1];
	}

	DP[1] = 0;
	DP[1 + info[1][0]] = info[1][1];
	for (int i = 2; i <= n; i++) {
		DP[i] = max(DP[i], DP[i - 1]);

		if (i + info[i][0] <= n + 1) {
			DP[i + info[i][0]] = max(DP[i + info[i][0]], DP[i] + info[i][1]);
		}
	}

	int result = -1;
	for (int i = 1; i <= n + 1; i++) {
		result = max(result, DP[i]);
	}

	cout << result;
}