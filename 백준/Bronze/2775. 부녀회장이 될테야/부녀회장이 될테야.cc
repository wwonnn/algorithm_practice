#include <iostream>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	int DP[15][15];
	for (int i = 1; i <= 14; i++) {
		DP[0][i] = i;
	}

	for (int i = 1; i <= 14; i++) {
		DP[i][1] = DP[i - 1][1];
		for (int j = 2; j <= 14; j++) {
			DP[i][j] = DP[i][j - 1] + DP[i - 1][j];
		}
	}
	for (int i = 0; i < T; i++) {
		int k, n;
		cin >> k >> n;

		cout << DP[k][n] << "\n";
	}
}