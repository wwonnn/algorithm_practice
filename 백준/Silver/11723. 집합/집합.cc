#include <iostream> 
#include <algorithm> 
#include <vector> 

using namespace std; 

int state;

int main() 
{ 
	ios::sync_with_stdio(0); 
	cin.tie(0); 

	int M; 
	cin >> M;

	for (int i = 0; i < M; i++) {
		string s;
		int d;
		cin >> s;

		if (s == "add") {
			cin >> d;
			state |= (1 << (d - 1));
		}
		else if (s == "remove") {
			cin >> d;
			state &= (~(1 << (d - 1)));
		}
		else if (s == "check") {
			cin >> d;
			cout << ((state >> (d - 1)) & 1) << "\n";
		}
		else if (s == "toggle") {
			cin >> d;
			state ^= (1 << (d - 1));
		}
		else if (s == "all") {
			state = 0xfffff;
		}
		else if (s == "empty") {
			state = 0;
		}
	}
	
}