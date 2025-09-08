#include <iostream>
#include <algorithm>

using namespace std;

int state[20][20];
int result = 0;
int N;

bool IsRightWall(pair<int, int> front) {
    // 앞에 벽인지
    return front.second + 1 > N || state[front.first][front.second + 1];
}
bool IsDownWall(pair<int, int> front) {
    // 아래 벽인지
    return front.first + 1 > N || state[front.first + 1][front.second];
}
bool IsRightDownWall(pair<int, int> front) {
    // 대각선 벽인지
    return front.first + 1 > N || front.second + 1 > N || state[front.first + 1][front.second] || state[front.first][front.second + 1] || state[front.first + 1][front.second + 1];
}
// (x, y) -> 파이프 좌표
void func(pair<int, int> back, pair<int, int> front) {
    if (front.first == N && front.second == N) {
        result++;
        return;
    }

    if (front.first == back.first) {
        // 가로
        if(!IsRightWall(front))
            func(front, { front.first, front.second + 1 });
        if(!IsRightDownWall(front))
            func(front, { front.first + 1, front.second + 1 });
    }
    else if (front.second == back.second) {
        // 세로
        if(!IsDownWall(front))
            func(front, { front.first + 1, front.second });
        if (!IsRightDownWall(front))
            func(front, { front.first + 1, front.second + 1 });
    }
    else {
        // 대각선
        if (!IsRightWall(front))
            func(front, { front.first, front.second + 1 });
        if (!IsDownWall(front))
            func(front, { front.first + 1, front.second });
        if (!IsRightDownWall(front))
            func(front, { front.first + 1, front.second + 1 });
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> state[i][j];
        }
    }

    func({1, 1}, {1, 2});
    cout << result;
}