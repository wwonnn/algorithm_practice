#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	map<string, int> pocketmon;
	vector<string> names;
	vector<string> result;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string name;
		cin >> name;
		pocketmon[name] = i + 1;
		names.push_back(name);
	}

	for (int i = 0; i < m; i++) {
		string temp;
		cin >> temp;
		if (temp[0] >= 65 && temp[0] <= 90) {
			result.push_back(to_string(pocketmon[temp]));
		}
		else {
			result.push_back(names[stoi(temp) - 1]);
		}
	}

	for (auto r : result) {
		cout << r << "\n";
	}

	return 0;
}