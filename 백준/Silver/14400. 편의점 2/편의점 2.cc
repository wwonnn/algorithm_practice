#include <iostream> 
#include <algorithm> 
#include <vector> 

using namespace std; 

int main() 
{ 
	ios::sync_with_stdio(0); 
	cin.tie(0); 

	int N, x, y; 
	cin >> N;

	vector<int> xs;
	vector<int> ys;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		xs.push_back(x);
		ys.push_back(y);
	}
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());

	int p1, p2;
	if (N % 2 == 0) {
		p1 = xs[N / 2 - 1];
		p2 = ys[N / 2 - 1];
	}
	else {
		p1 = xs[(N - 1) / 2];
		p2 = ys[(N - 1) / 2];
	}
	
	long long sum_x = 0, sum_y = 0;
	for (int i = 0; i < N; i++) {
		if(xs[i] != p1)
			sum_x += abs(p1 - xs[i]);
		if (ys[i] != p2)
			sum_y += abs(p2 - ys[i]);
	}

	cout << sum_x + sum_y;
	
}