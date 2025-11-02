#include <iostream> 
#include <algorithm> 
#include <vector> 

using namespace std; 

int main() 
{ 
	ios::sync_with_stdio(0); 
	cin.tie(0); 

	int N, K; 
	cin >> N >> K;

	vector<vector<long long>> enemy(N, vector<long long>(3));

	for (int i = 0; i < N; i++) {
		cin >> enemy[i][0] >> enemy[i][1] >> enemy[i][2];
	}

	// 브루트 포스
	long long result = 2e10;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				long long A = enemy[i][0];
				long long B = enemy[j][1];
				long long C = enemy[k][2];

				int count = 0;
				for (int t = 0; t < N; t++) {
					if (enemy[t][0] <= A && enemy[t][1] <= B && enemy[t][2] <= C) count++;
				}

				if (count >= K) {
					result = min(result, A + B + C);
				}
			}
		}
	}
	cout << result;
	
}