#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, m;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> m;
        priority_queue<int> max_pq;
        priority_queue<int, vector<int>, greater<int>> min_pq;
        vector<int> result;

        int d;
        cin >> d;
        int temp = d;   // 현재 중앙값
        result.push_back(temp);
        for (int j = 1; j < m; j++) {
            cin >> d;
            if (d > temp) {
                min_pq.push(d);
            }
            else {
                max_pq.push(d);
            }

            if ((j + 1) % 2 != 0) {
                // 홀수 번째일 때
                while (min_pq.size() != max_pq.size()) {
                    if (min_pq.size() > max_pq.size()) {
                        max_pq.push(temp);
                        temp = min_pq.top();
                        min_pq.pop();
                    }
                    else {
                        min_pq.push(temp);
                        temp = max_pq.top();
                        max_pq.pop();
                    }
                }
                result.push_back(temp);
            }
        }
        cout << result.size();
        for (int k = 0; k < result.size(); k++) {
            if (k % 10 == 0) cout << "\n";
            cout << result[k] << ' ';
        }
    }
}