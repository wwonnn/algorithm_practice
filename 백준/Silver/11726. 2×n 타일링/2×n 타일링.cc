#include <iostream>

using namespace std;

int DP[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int mod = 10007;
	DP[1] = 1;
	DP[2] = 2;
	for (int i = 3; i <= size(DP); i++){ 
		DP[i] = DP[i - 2] % mod + DP[i - 1] % mod;
	}

	int n;
	cin >> n;
	cout << DP[n] % mod;

}