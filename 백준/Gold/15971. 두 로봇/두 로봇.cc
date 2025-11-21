#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

bool visit[100001] = { false };
int dist[100001];
int parent[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, p1, p2;
	cin >> N >> p1 >> p2;

	map<int, int> node[5001];	// 간선 길이
	vector<pair<int, int>> adj[5001];	// 인접 정점

	for (int i = 0; i < N - 1; i++) {
		int x, y, d;
		cin >> x >> y >> d;

		node[x][y] = d;
		node[y][x] = d;
		adj[x].push_back({ y, d });
		adj[y].push_back({ x, d });
	}

	// BFS
	queue<int> q;
	q.push(p1);
	visit[p1] = true;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (pair<int, int> next : adj[curr]) {
			if (!visit[next.first]) {
				visit[next.first] = true;
				dist[next.first] = dist[curr] + next.second;
				parent[next.first] = curr;
				q.push(next.first);
			}
		}
	}

	// 경로 복원
	vector<int> result;
	int curr = p2;
	result.push_back(curr);

	while (curr != p1) {
		result.push_back(parent[curr]);
		curr = parent[curr];
	}
	
	// 최단 경로 계산
	int max_dis = 0;
	for (int i = 0; i < result.size() - 1; i++) {
		if (node[result[i]][result[i + 1]] > max_dis)
			max_dis = node[result[i]][result[i + 1]];
	}

	cout << dist[p2] - max_dis;
}