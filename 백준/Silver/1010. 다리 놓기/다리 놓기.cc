#include <iostream>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	int DP[35][35];
	for (int i = 1; i <= 30; i++) {
		DP[1][i] = i;
		DP[i][i] = 1;
	}

	for (int i = 2; i <= 30; i++) {
		for (int j = i + 1; j <= 30; j++) {
			DP[i][j] = DP[i][j - 1] + DP[i - 1][j - 1];
		}
	}
	for (int i = 0; i < T; i++) {
		int k, n;
		cin >> k >> n;

		cout << DP[k][n] << "\n";
	}
}