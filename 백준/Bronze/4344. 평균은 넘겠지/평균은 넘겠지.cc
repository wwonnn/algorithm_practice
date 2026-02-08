#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
	int C;
	cin >> C;

	for (int i = 0; i < C; i++) {
		int n;
		cin >> n;
		vector<int> score;
		long long sum = 0;
		for (int j = 0; j < n; j++) {
			int d;
			cin >> d;
			score.push_back(d);
			sum += d;
		}
		float r = (float)sum / score.size();
		int count = 0;
		for (int s : score) {
			if ((float)s > r) count++;
		}
		cout << (float)count / score.size() * 100 << "%\n";
	}
}