#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> costs;
vector<int> temp;
vector<pair<int, int>> sales[10];
bool visit[10] = { false };
int min_cost = 1e9;

void backtracking(int count, int total) {
	if (count <= 0) {
		min_cost = min(min_cost, total);
		return;
	}

	// 다음 물약 구매
	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			vector<int> temp2 = temp;

			// 할인 반영
			for (pair<int, int> p : sales[i]) {
				temp[p.first - 1] -= p.second;

				if (temp[p.first - 1] <= 0) {
					temp[p.first - 1] = 1;
				}
			}

			backtracking(count - 1, total + temp[i]);

			temp = temp2;
			visit[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 물약 정보
	cin >> N;

	for (int i = 0; i < N; i++) {
		int c;
		cin >> c;
		costs.push_back(c);
	}

	// 할인 정보 초기화
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;

		for (int j = 0; j < p; j++) {
			int a, d;
			cin >> a >> d;

			sales[i].push_back({ a, d });
		}
	}
	temp = costs;

	// 물약 순서 백트래킹
	backtracking(N, 0);

	cout << min_cost;
}