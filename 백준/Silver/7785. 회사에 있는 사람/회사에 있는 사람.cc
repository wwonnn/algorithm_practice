#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	map<string, string, greater<>> history;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		string name, state;
		cin >> name >> state;
		history[name] = state;
	}

	for (auto h : history) {
		if (h.second == "enter") {
			cout << h.first << "\n";
		}
	}

	return 0;
}