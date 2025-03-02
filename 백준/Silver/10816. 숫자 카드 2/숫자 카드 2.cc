#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	map<int, int> cards;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (cards.find(num) != cards.end()) {
			cards[num]++;
		}
		else {
			cards[num] = 1;
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		if (cards.find(num) != cards.end()) {
			cout << cards[num] << ' ';
		}
		else {
			cout << 0 << ' ';
		}
	}

	return 0;
}