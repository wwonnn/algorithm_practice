#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	int N; 
	cin >> N;

	if (N % 2 != 0) {
		int mid = (N + 1) / 2;
		cout << mid;
		for (int i = N; i > mid; i--) cout << ' ' << i << ' ' << i - mid;
	}
	else {
		int mid = N / 2;
		for (int i = N; i > mid; i--) cout << i - mid << ' ' << i << ' ';
	}


}