#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(int a, int b) {
	if (a > b) return true;
	else return false;
}

int main() {
	int n;
	vector<int> x, sort_x;
	map<int, int> dot;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int new_x;
		cin >> new_x;
		sort_x.push_back(new_x);
		x.push_back(new_x);
	}
	sort(sort_x.begin(), sort_x.end(), cmp);
	sort_x.erase(unique(sort_x.begin(), sort_x.end()), sort_x.end());

	for (int i = 0; i < sort_x.size(); i++) {
		dot[sort_x[i]] = sort_x.size() - i - 1;
	}

	for (int i = 0; i < x.size(); i++) {
		cout << dot[x[i]] << ' ';
	}
	return 0;
}