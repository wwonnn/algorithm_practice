#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string a, b;
		cin >> a >> b;

		vector<char> v1, v2;
		for (char c : a) {
			v1.push_back(c);
		}
		for (char c : b) {
			v2.push_back(c);
		}

		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());

		if (v1 == v2) cout << a << " & " << b << " are anagrams.\n";
		else cout << a << " & " << b << " are NOT anagrams.\n";
	}

}