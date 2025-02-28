#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	else return a.length() < b.length();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	vector<string> words;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;

		words.push_back(word);
	}
	sort(words.begin(), words.end(), cmp);
	words.erase(unique(words.begin(), words.end()), words.end());

	for (int i = 0; i < words.size(); i++) {
		cout << words[i] << "\n";
	}
	
	return 0;
}