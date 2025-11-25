#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int k;
bool visit[10];
string func = "";
string s = "";
string max_num = "0000000000";
string min_num = "9999999999";

void backtracking(int count) {
	if (count > k) {
		for (int i = 0; i < func.length(); i++) {
			if (func[i] == '>') {
				if (s[i] > s[i + 1]) continue;
				else return;
			}
			else if (func[i] == '<') {
				if (s[i] < s[i + 1]) continue;
				else return;
			}
		}
		if (s > max_num) max_num = s;
		if (s < min_num) min_num = s;

		return;
	}

	for (int i = 0; i <= 9; i++) {
		if (!visit[i]) {
			s.append(to_string(i));
			visit[i] = true;
			backtracking(count + 1);
			visit[i] = false;
			s.erase(s.length() - 1, 1);
		}

	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;

	for (int i = 0; i < k; i++) {
		string c;
		cin >> c;

		func.append(c);
	}

	backtracking(0);

	cout << max_num << "\n" << min_num;

}