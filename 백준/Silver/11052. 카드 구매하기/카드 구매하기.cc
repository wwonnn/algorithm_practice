#include <iostream>

using namespace std;

int DP[1005];
int cards[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> cards[i];
	}

	DP[1] = cards[1];
	DP[2] = max(cards[1] * 2, cards[2]);
	for (int i = 3; i <= N; i++) {
		DP[i] = cards[i];
		for(int j = 1; j <= i; j++)
			DP[i] = max(DP[i], DP[j] + DP[i - j]);
	}
	cout << DP[N];

}