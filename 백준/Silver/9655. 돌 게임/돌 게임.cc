#include <iostream>

using namespace std;

int DP[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	// 0: SK 1: CY

	DP[1] = 0;
	DP[2] = 1;
	DP[3] = 0;
	for (int i = 4; i <= 1000; i++) {
		DP[i] = (DP[i - 1] + 1) % 2;
		//DP[i] = (DP[i - 3] + 1) % 2;
	}

	if (DP[N] == 0) {
		cout << "SK";
	}
	else cout << "CY";
}