#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L, R, X;
int levels[16];
int selects = 0;
int highest = 0;
int lowest = 1e9;
int cnt = 0;

void dfs(int index, int sum) {
	if (index >= N) {
		if (selects >= 2 && sum >= L && sum <= R && highest - lowest >= X) {
			cnt++;
		}
		return;
	}

	// 현재 문제 선택
	int temp1 = highest;
	int temp2 = lowest;
	highest = max(highest, levels[index]);
	lowest = min(lowest, levels[index]);
	selects++;
	dfs(index + 1, sum + levels[index]);

	// 현재 문제 선택x
	highest = temp1;
	lowest = temp2;
	selects--;
	dfs(index + 1, sum);

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L >> R >> X;

	for (int i = 0; i < N; i++) {
		cin >> levels[i];
	}

	dfs(0, 0);

	cout << cnt;
}