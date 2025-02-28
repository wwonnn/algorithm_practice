#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n;
	vector<int> nums;
	cin >> n;

	for (int i = 0; i < 10; i++) {
		long long l1 = pow(10, i + 1);
		long long l2 = pow(10, i);

		if (n / l2 == 0) break;

		nums.push_back((n % l1) / l2);
	}
	sort(nums.begin(), nums.end(), cmp);

	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i];
	}
	
	return 0;
}