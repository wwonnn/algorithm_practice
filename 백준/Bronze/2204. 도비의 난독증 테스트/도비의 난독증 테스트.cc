#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool func(string s1, string s2) {
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] >= 'a' && s1[i] <= 'z') {
			s1[i] = toupper(s1[i]);
		}
	}
	for (int i = 0; i < s2.size(); i++) {
		if (s2[i] >= 'a' && s2[i] <= 'z') {
			s2[i] = toupper(s2[i]);
		}
	}
	return s1 < s2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;

		vector<string> v;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			v.push_back(s);
		}
		sort(v.begin(), v.end(), func);
		cout << v[0] << "\n";
	}
}