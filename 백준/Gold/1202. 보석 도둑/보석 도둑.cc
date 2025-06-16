#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct comp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
};

bool comp1(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

bool comp2(int a, int b) {
    return a < b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> jewel;
    vector<int> bag;
    
    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        jewel.push_back(make_pair(w, v));
    }
    for (int i = 0; i < k; i++) {
        int b;
        cin >> b;
        bag.push_back(b);
    }
    sort(jewel.begin(), jewel.end(), comp1);    // nlogn
    sort(bag.begin(), bag.end(), comp2);        // klogk

    long long total = 0;
    int index = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    for (int i = 0; i < k; i++) {
        for (int j = index; j < n; j++) {
            if (jewel[j].first <= bag[i]) {
                pq.push(jewel[j]);
                index++;
            }
            else break;
        }   // nlogn
        if (!pq.empty()) {
            total += pq.top().second;
            pq.pop();
        }
    }
    // 시간 복잡도 : (n+k)logn
    cout << total;
}