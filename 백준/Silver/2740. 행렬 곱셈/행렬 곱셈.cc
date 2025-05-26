#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<vector<int>> a;
    vector<vector<int>> b;
    vector<vector<int>> result;
    vector<int> temp;

    int n, m, k;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        temp.clear();
        for (int j = 0; j < m; j++) {
            int d;
            cin >> d;
            temp.push_back(d);
        }
        a.push_back(temp);
    }

    cin >> m >> k;

    for (int i = 0; i < m; i++) {
        temp.clear();
        for (int j = 0; j < k; j++) {
            int d;
            cin >> d;
            temp.push_back(d);
        }
        b.push_back(temp);
    }

    // a b 행렬곱
    for (int i = 0; i < n; i++) {
        temp.clear();
        for (int j = 0; j < k; j++) {
            int sum = 0;
            for (int t = 0; t < m; t++) {
                sum += (a[i][t] * b[t][j]);
            }
            temp.push_back(sum);
        }
        result.push_back(temp);
    }

    // 결과 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << result[i][j] << ' ';
        }
        cout << "\n";
    }
}