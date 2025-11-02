#include <iostream> 
#include <algorithm> 
#include <vector> 

using namespace std; 

int state;

int main() 
{ 
	ios::sync_with_stdio(0); 
	cin.tie(0); 

    long long n;
    cin >> n;

    long long result = 0;
    long long power = 1;

    while (n > 0) {
        if (n & 1) { 
            result += power;
        }
        power *= 3;  
        n >>= 1;     
    }

    cout << result;
	
}