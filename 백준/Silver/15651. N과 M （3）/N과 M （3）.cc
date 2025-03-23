#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> used(10);
vector<int> result(10);

void func(int k) {
    if (k == m) {
        // m개를 다 채웠을 때
        for (int i = 0; i < m; i++) {
            cout << result[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (used[i] < m) {
            used[i]++;
            result[k] = i;
            func(k + 1);
            used[i]--;
        }
    }
    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func(0);
}