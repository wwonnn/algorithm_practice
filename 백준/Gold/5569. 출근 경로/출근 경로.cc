#include <iostream>

using namespace std;

long long DP[105][105][2][2]; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int w, h;
	cin >> w >> h;

	// 초기화
	for (int i = 2; i <= w; i++) {
		DP[i][1][0][0] = 1;
	}
	for (int i = 2; i <= h; i++) {
		DP[1][i][1][0] = 1;
	}

	// 점화식
	long long mod = 100000;
	for (int i = 2; i <= w; i++) {
		for (int j = 2; j <= h; j++) {
			// 점 기준 -> 왼쪽에서 온 경우, 아래에서 온 경우
			// 1. 오 / 방향 꺾 x
			DP[i][j][0][0] += (DP[i - 1][j][0][0] % mod + DP[i - 1][j][0][1]) % mod;

			// 2. 오 / 방향 꺾 o
			DP[i][j][0][1] += DP[i - 1][j][1][0] % mod;

			// 3. 위 / 방향 꺾 x
			DP[i][j][1][0] += (DP[i][j - 1][1][0] % mod + DP[i][j - 1][1][1]) % mod;

			// 4. 위 / 방향 꺾 o
			DP[i][j][1][1] += DP[i][j - 1][0][0] % mod;
		}
	}

	cout << (DP[w][h][0][0] % mod + DP[w][h][0][1] % mod + DP[w][h][1][0] % mod + DP[w][h][1][1] % mod) % mod;
}