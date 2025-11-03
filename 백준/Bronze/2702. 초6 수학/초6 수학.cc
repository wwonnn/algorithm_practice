#include <iostream> 
#include <algorithm> 
#include <vector> 

using namespace std; 

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() 
{ 
	ios::sync_with_stdio(0); 
	cin.tie(0); 

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int a, b;
        cin >> a >> b;

        cout << lcm(a, b) << ' ' << gcd(a, b) << "\n";
    }
}