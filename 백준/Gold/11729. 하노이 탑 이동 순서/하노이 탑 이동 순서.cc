#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> result;

void hanoi(int n, int st, int des, int tmp) {
    if (n == 0) {
        return;
    }
    // st: 시작점 des: 목적지 tmp: 이외 지점
    hanoi(n - 1, st, tmp, des);
    result.push_back(make_pair(st, des));
    hanoi(n - 1, tmp, des, st);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v;


    for (int i = 0; i < n; i++) {
        // 원판 초기화
        v.push_back(i + 1);
    }
    hanoi(n - 1, 1, 2, 3);
    result.push_back(make_pair(1, 3));
    hanoi(n - 1, 2, 3, 1);

    cout << result.size() << "\n";
    for (auto r : result) {
        cout << r.first << ' ' << r.second << "\n";
    }

}