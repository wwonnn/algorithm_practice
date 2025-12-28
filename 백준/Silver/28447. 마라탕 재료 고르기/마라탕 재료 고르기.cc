#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n, k;
int score[11][11];
vector<int> temp;
int max_score = -1e9;

void backtracking(int start, int count) {
	if (count >= k) {
		int sum = 0;
		for (int i = 0; i < k; i++) {
			for (int j = i + 1; j < k; j++) {
				sum += score[temp[i]][temp[j]];
			}
		}
		max_score = max(max_score, sum);
		return;
	}

	for (int i = start; i < n; i++) {
		temp.push_back(i);
		backtracking(i + 1, count + 1);
		temp.pop_back();
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> score[i][j];
		}
	}

	backtracking(0, 0);

	cout << max_score;
}