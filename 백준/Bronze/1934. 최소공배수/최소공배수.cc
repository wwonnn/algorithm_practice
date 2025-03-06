#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n; 
	
	vector<int> result;
	for (int i = 0; i < n; i++) {
		int a, b, num1, num2;
		cin >> a >> b;
		if (a > b) {
			num1 = a;
			num2 = b;
		}
		else {
			num1 = b;
			num2 = a;
		}
		int j = 1;
		while (true) {
			if ((num1 * j) % num2 == 0) {
				result.push_back(num1 * j);
				break;
			}
			else {
				j++;
			}
		}
	}

	for (auto r : result) {
		cout << r << "\n";
	}

	return 0;
}