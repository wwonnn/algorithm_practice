#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
string result;

void backtracking(int count) {
	if (count >= N) {
		cout << result;
		exit(0);
	}

	for (int i = 1; i <= 3; i++) {
		string temp = result;
		temp += to_string(i);

		// 연속된 부분수열 체크
		bool iscan = true;
		for (int j = 1; j <= (count + 1) / 2; j++) {
			for (int t = 0; t <= count + 1 - j * 2; t++) {
				if (temp.substr(t, j) == temp.substr(t + j, j)) {
					iscan = false;
				}
			}
		}

		if (iscan) {
			result += to_string(i);
			backtracking(count + 1);
			result.pop_back();
		}
		else {
			continue;
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	backtracking(0);
}