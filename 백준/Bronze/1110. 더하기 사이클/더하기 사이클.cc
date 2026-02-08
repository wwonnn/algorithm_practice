#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int temp = n;
	int count = 0;
	while (true) {
		if (temp < 10)
			temp = temp * 10 + (temp / 10 + temp % 10) % 10;
		else
			temp = (temp % 10 * 10) + (temp / 10 + temp % 10) % 10;

		count++;
		if (temp == n) break;
	}

	cout << count;

}