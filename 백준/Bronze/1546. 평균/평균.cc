#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long sum = 0;
	int max_num = -1;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d;
		cin >> d;
		sum += d;
		if (d > max_num) max_num = d;
	}

	cout << (float)sum / n / max_num * 100;

}