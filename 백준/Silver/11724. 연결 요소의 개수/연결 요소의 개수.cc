#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int N, M;
    cin >> N >> M;

    vector<int> adj[1001];
    bool visit[1001] = { false };

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    stack<int> st;
    int count = 0;

    for (int i = 1; i <= N; i++) { 
        if (!visit[i]) { 
            st.push(i);
            while (!st.empty()) {
                int curr = st.top();
                st.pop();

                visit[curr] = true;

                for (auto p : adj[curr]) {
                    if (!visit[p]) st.push(p);
                }
            }

            count++; 
        }
    }

    cout << count;
}
