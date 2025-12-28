#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
vector<pair<int, int>> flavors;
vector<int> temp;
int min_score = 1e9;

void DFS(int index) {
	if (index >= n) {
		if (temp.size() >= 1) {
			int sum_a = 1;
			int sum_b = 0;
			for (auto i : temp) {
				sum_a *= flavors[i].first;
				sum_b += flavors[i].second;
			}

			min_score = min(min_score, abs(sum_a - sum_b));
		}

		return;
	}

	temp.push_back(index);
	DFS(index + 1);
	temp.pop_back();

	DFS(index + 1);

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		flavors.push_back({ a, b });
	}

	DFS(0);

	cout << min_score;
}