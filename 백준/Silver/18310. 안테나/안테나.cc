#include <iostream> 
#include <algorithm> 
#include <vector> 

using namespace std; 

int main() 
{ 
	ios::sync_with_stdio(0); 
	cin.tie(0); 

	int N, d; 
	cin >> N;

	vector<int> house;

	for (int i = 0; i < N; i++) {
		cin >> d;
		house.push_back(d);
	}
	sort(house.begin(), house.end());

	if (N % 2 == 0) {
		cout << house[N / 2 - 1];
	}
	else {
		cout << house[(N - 1) / 2];
	}
}