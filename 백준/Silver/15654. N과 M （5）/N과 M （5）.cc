#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
int visit[10001];
vector<vector<int>> result;
vector<int> temp;

void backtracking(int count) {
	if (count <= 0) {
		result.push_back(temp);

		return;
	}

	for (auto d : nums) {
		if (!visit[d]) {
			visit[d] = 1;
			temp.push_back(d);
			backtracking(count - 1);
			temp.pop_back();
			visit[d] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int d;
		cin >> d;

		nums.push_back(d);
	}

	backtracking(M);

	sort(result.begin(), result.end());
	for (auto r : result) {
		for (auto d : r) {
			cout << d << ' ';
		}
		cout << "\n";
	}
}