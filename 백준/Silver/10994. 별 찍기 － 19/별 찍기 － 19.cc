#include <iostream>
#include <vector>
using namespace std;

vector<string> board;

void draw(int n, int x, int y) {
    if (n == 1) {
        board[x][y] = '*';
        return;
    }

    int size = 4 * n - 3;

    // 네 방향 테두리 그리기
    for (int i = 0; i < size; i++) {
        board[x][y + i] = '*';
        board[x + size - 1][y + i] = '*';
        board[x + i][y] = '*';
        board[x + i][y + size - 1] = '*';
    }

    // 안쪽 프레임 재귀
    draw(n - 1, x + 2, y + 2);
}

int main() {
    int n;
    cin >> n;

    int size = 4 * n - 3;
    board.assign(size, string(size, ' '));

    draw(n, 0, 0);

    for (auto &line : board) {
        cout << line << '\n';
    }

    return 0;
}
