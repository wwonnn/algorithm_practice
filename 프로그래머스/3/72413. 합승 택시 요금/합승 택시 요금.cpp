#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define x first
#define y second

// 우선순위 큐
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

vector<pair<int, int>> G[201];

void dijkstra(int st, int d[], vector<vector<int>> fares){
    q.push({0, st});
    d[st] = 0;
    while(!q.empty()){
        auto cur = q.top();
        q.pop();
        if(d[cur.y] != cur.x) continue;
        for(pair<int, int> nxt : G[cur.y]){
            // 더 비용이 작은 경로 선택
            if(d[cur.y] + nxt.y <= d[nxt.x]){
                d[nxt.x] = d[cur.y] + nxt.y;
                q.push({d[nxt.x], nxt.x}); 
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 우선순위 큐를 이용한 다익스트라 알고리즘 활용
    // s, a, b에서 모든 지점까지의 최소 경로를 구한 후, 세 개의 합이 최소인 지점 구하기
    // 거리를 업데이트 하는 배열 a, b, s
    int d_s[201];
    int d_a[201];
    int d_b[201];
    
    for(vector<int> nxt : fares){
        G[nxt[0]].push_back({nxt[1], nxt[2]});
        G[nxt[1]].push_back({nxt[0], nxt[2]});
    }
    
    const int INF = 1e9+10;
    fill(d_s, d_s + n + 1, INF);
    fill(d_a, d_a + n + 1, INF);
    fill(d_b, d_b + n + 1, INF);
    d_s[0] = -1;
    d_a[0] = -1;
    d_b[0] = -1;
    
    dijkstra(s, d_s, fares);
    dijkstra(a, d_a, fares);
    dijkstra(b, d_b, fares);
    
    // 세 출발점에서의 최소 합 지점 구하기
    int min_val = INF;
    for(int i = 1; i <= n; i++){
        if(d_s[i] < INF && d_a[i] < INF && d_b[i] < INF && d_s[i] + d_a[i] + d_b[i] < min_val){
            min_val = d_s[i] + d_a[i] + d_b[i];
        }
    }
    
    int answer = min_val;
    
    return answer;
}