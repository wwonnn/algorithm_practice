#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	unordered_set<string> people;
	vector<string> result;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string person;
		cin >> person;
		people.insert(person);
	}

	for (int i = 0; i < m; i++) {
		string person;
		cin >> person;
		if (people.find(person) != people.end()) {
			result.push_back(person);
		}
	}
	sort(result.begin(), result.end());

	cout << result.size() << "\n";
	for (auto r : result) {
		cout << r << "\n";
	}

	return 0;
}