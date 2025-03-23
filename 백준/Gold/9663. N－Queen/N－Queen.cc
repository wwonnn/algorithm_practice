#include <iostream>
#include <vector>

using namespace std;

int n;
int cnt = 0;
vector<vector<int>> used(14, vector<int>(14));

void func(int k) {
    if (k == n) {
        // n개를 다 채웠을 때
        cnt++;
        return;
    }
    
    // 체스 퀸은 직선과 대각선만 갈 수 있음
    for (int i = 0; i < n; i++) {
        bool b = true; // 퀸을 놓을 수 있는지 판단
        if (!used[k][i]) {
            for (int t = 1; t <= k; t++) {
                // 위 아래
                if (used[k - t][i]) {
                    b = false;
                    break;
                }

                // 대각선
                if (k - t >= 0 && i - t >= 0) {
                    if (used[k - t][i - t]) {
                        b = false;
                        break;
                    }
                }
                if (k - t >= 0 && i + t < n) {
                    if (used[k - t][i + t]) {
                        b = false;
                        break;
                    }
                }
            }
        }

        if (b) {
            used[k][i] = 1;
            func(k + 1);
            used[k][i] = 0;
        }
    }
    return;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    func(0);
    cout << cnt;
}