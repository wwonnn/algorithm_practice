#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool func(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		vector<pair<string, int>> v;

		for (int j = 0; j < N; j++) {
			string name;
			int count;
			cin >> name >> count;
			v.push_back({name, count});
		}

		sort(v.begin(), v.end(), func);
		cout << v[0].first << "\n";
	}

}
