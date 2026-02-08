#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	long long a, b, v;
	cin >> a >> b >> v;

	cout << (v - b - 1) / (a - b) + 1;
	
}