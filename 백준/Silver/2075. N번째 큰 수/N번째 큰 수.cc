#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int d;
            cin >> d;
            if (pq.size() < n) {
                pq.push(d);
            }
            else {
                if (d > pq.top()) {
                    pq.pop();
                    pq.push(d);
                }
            }
        }

    }
    cout << pq.top();

}