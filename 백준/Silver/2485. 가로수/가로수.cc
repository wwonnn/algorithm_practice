#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v;
	vector<int> v_r;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	for (int i = 0; i < n - 1; i++) {
		int new_v = v[i + 1] - v[i];
		v_r.push_back(new_v);
	}

	int result = 0;
	for (int i = 0; i < v_r.size(); i++) {
		if (result == 0) {
			result = gcd(v_r[i], v_r[i + 1]);
		}
		else {
			result = gcd(v_r[i], result);
		}
		
	}

	// 최대공약수
	cout << (v.back() - v.front()) / result - (v.size() - 1);

	return 0;
}