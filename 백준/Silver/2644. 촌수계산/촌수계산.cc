#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool visit[101] = { false };
int dist[101];

int BFS(vector<int> adj[], int start, int des) {
	queue<int> q;
	q.push(start);
	visit[start] = true;
	dist[start] = 0;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (auto a : adj[curr]) {
			if (!visit[a]) {
				visit[a] = true;
				dist[a] = dist[curr] + 1;
				q.push(a);
			}
				
		}
	}

	if (!visit[des])
		return -1;
	else
		return dist[des];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, p1, p2, M;
	cin >> N >> p1 >> p2 >> M;

	vector<int> adj[N + 1];

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	cout << BFS(adj, p1, p2);
}