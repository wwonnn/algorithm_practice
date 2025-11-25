#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int times[16][2];
int curr = 0;
int max_profit = 0;

void backtracking(int day) {
	if (day == N + 1) {
		max_profit = max(max_profit, curr);
		return;
	}

	if (day > N + 1) return;
	 
	if (day + times[day][0] <= N + 1) {
		curr += times[day][1];
		backtracking(day + times[day][0]);
		curr -= times[day][1];
	}

	backtracking(day + 1);

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> times[i][0] >> times[i][1];
	}

	backtracking(1);

	cout << max_profit;
}