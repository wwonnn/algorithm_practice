#include <iostream> 
#include <algorithm> 
#include <vector> 
#include <queue> 
#include <memory.h> 

using namespace std; 

int time_sum[1001];
int build_time[1001]; 
vector<int> adj[1001]; 
int deg[1001]; 

int INF = 1e9; 
int N, K; 

void sort() 
{ 
	// 위상 정렬인데, 조건에 맞는 수 중에 가장 작은 순으로 정렬 
	queue<int> q; vector<int> node; 

	for (int i = 1; i <= N; i++) 
	{ 
		// 들어오는 간선이 0개인 수 저장 
		if (deg[i] == 0) 
		{ 
			node.push_back(i); 
			q.push(i);
		} 
	} 

	while (!q.empty()) 
	{ 
		int curr = q.front(); 
		q.pop(); 

		for (auto n : adj[curr]) 
		{ 
			if (time_sum[n] < time_sum[curr] + build_time[n]) {
				time_sum[n] = time_sum[curr] + build_time[n];
			}

			deg[n]--; 
			if (deg[n] == 0) 
			{ 
				q.push(n); 
			} 
		} 
	} 
} 

int main() 
{ 
	ios::sync_with_stdio(0); 
	cin.tie(0); 

	int T; 
	cin >> T; 

	for (int i = 0; i < T; i++) {
		memset(build_time, 0, sizeof(build_time));
		memset(adj, 0, sizeof(adj)); 
		memset(deg, 0, sizeof(deg));

		cin >> N >> K; 

		for (int j = 1; j <= N; j++) 
		{ 
			// 건설 시간 
			cin >> build_time[j];
			time_sum[j] = build_time[j];
		} 

		for (int j = 0; j < K; j++) 
		{ 
			// 인접 건물 
			int X, Y; 
			cin >> X >> Y; 
			adj[X].push_back(Y); 
			deg[Y]++; 
		} 
		sort(); 

		int W; 
		cin >> W; 
		
		cout << time_sum[W] << "\n"; 
	} 
}