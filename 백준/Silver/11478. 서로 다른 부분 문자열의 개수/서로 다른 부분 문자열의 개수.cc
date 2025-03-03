#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	unordered_set<string> substr;
	cin >> str; 
	
	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < str.length() - i; j++) {
			substr.insert(str.substr(j, i + 1));
		}
	}
	cout << substr.size();

	return 0;
}