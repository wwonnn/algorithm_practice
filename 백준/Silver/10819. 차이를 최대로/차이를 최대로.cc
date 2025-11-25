#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int nums[10];
bool visit[10];
long long max_result = 0;


void backtracking(int count, long long result, int before) {
	if (count <= 0) {
		max_result = max(max_result, result);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			backtracking(count - 1, result + abs(before - nums[i]), nums[i]);
			visit[i] = false;
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	for (int i = 0; i < N; i++) {
		visit[i] = true;
		backtracking(N - 1, 0, nums[i]);
		visit[i] = false;
	}
	

	cout << max_result;
}