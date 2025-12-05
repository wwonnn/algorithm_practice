#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int A, B;
string C;
vector<char> nums;
bool visit[10];
int max_num = -1;


void backtracking(int count) {
	if (count >= nums.size()) {
		if (C[0] != '0' && C.length() > 0) {
			int result = stoi(C);
			if (result < B && result > max_num) max_num = result;
		}

		return;
	}

	for (int i = 0; i < nums.size(); i++) {
		if (!visit[i]) {
			visit[i] = true;
			C += nums[i];

			backtracking(count + 1);

			visit[i] = false;
			C.erase(C.length() - 1, 1);
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B;

	for (auto c : to_string(A)) {
		nums.push_back(c);
	}

	backtracking(0);

	cout << max_num;
}