#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	vector<int> cards;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int card;
		cin >> card;
		cards.push_back(card);
	}
	sort(cards.begin(), cards.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int check_card;
		cin >> check_card;
		cout << binary_search(cards.begin(), cards.end(), check_card) << ' ';
	}
	
	return 0;
}