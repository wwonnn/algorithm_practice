#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	vector<pair<int, string>> people;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int age;
		string name;
		cin >> age >> name;

		people.push_back(make_pair(age, name));
	}
	stable_sort(people.begin(), people.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << people[i].first << ' ' << people[i].second << "\n";
	}
	
	return 0;
}