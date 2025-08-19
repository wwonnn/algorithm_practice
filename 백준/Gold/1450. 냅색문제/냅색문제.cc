#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void dfs(int idx, int n, long long sum, vector<int>& arr, vector<long long>& result) {
    if (idx == n) {
        result.push_back(sum);
        return;
    }
    // 현재 원소 포함 X
    dfs(idx + 1, n, sum, arr, result);
    // 현재 원소 포함 O
    dfs(idx + 1, n, sum + arr[idx], arr, result);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, C;
    cin >> N >> C;

    vector<int> weight;
    vector<long long> weight_left;
    vector<long long> weight_right;

    
    for (int i = 0; i < N; i++) {
        int w;
        cin >> w;
        weight.push_back(w);
    }

    int mid = weight.size() / 2;

    dfs(0, mid, 0, weight, weight_left);
    dfs(mid, N, 0, weight, weight_right);

    sort(weight_right.begin(), weight_right.end());

    long long count = 0;
    for (long long l : weight_left) {
        if(C - l >= 0)
            count += upper_bound(weight_right.begin(), weight_right.end(), C - l) - weight_right.begin();
    }

    cout << count;
}