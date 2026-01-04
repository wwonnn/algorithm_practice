#include <iostream>

using namespace std;

int DP[41][2]; // 0, 1출력 개수

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	DP[0][0] = 1;
	DP[1][1] = 1;
	for (int i = 2; i <= size(DP); i++) {
		DP[i][0] = DP[i - 1][0] + DP[i - 2][0];
		DP[i][1] = DP[i - 1][1] + DP[i - 2][1];
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int d;
		cin >> d;
		cout << DP[d][0] << ' ' << DP[d][1] << "\n";
	}
}