#include <iostream>

using namespace std;

long long DP[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	DP[1] = DP[2] = 1;
	for (int i = 3; i <= 95; i++) {
		DP[i] = DP[i - 2] + DP[i - 1];
	}

	cout << DP[N];
}