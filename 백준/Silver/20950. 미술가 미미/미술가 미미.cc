#include <iostream>

using namespace std;

int N;
int colors[30][3];
int color_r, color_g, color_b;
int cnt = 0;
int sum_r = 0, sum_g = 0, sum_b = 0;

int result = 1e9;

void backtracking(int index) {
	if (index >= N) {
		if (cnt > 1) {
			int temp = abs(color_r - sum_r / cnt) + abs(color_g - sum_g / cnt) + abs(color_b - sum_b / cnt);
			if (temp < result) result = temp;
		}

		return;
	}

	// 물감을 사용하는 경우
	if (cnt < 7) {
		cnt++;
		sum_r += colors[index][0];
		sum_g += colors[index][1];
		sum_b += colors[index][2];

		backtracking(index + 1);

		cnt--;
		sum_r -= colors[index][0];
		sum_g -= colors[index][1];
		sum_b -= colors[index][2];
	}

	// 사용하지 않는 경우
	backtracking(index + 1);

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
	}
	cin >> color_r >> color_g >> color_b;

	backtracking(0);

	cout << result;
}