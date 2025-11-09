#include <iostream> 
#include <algorithm> 
#include <vector> 

using namespace std; 

int people[1000001];
int score[1000001];
int index[1000001];


int main() 
{ 
	ios::sync_with_stdio(0); 
	cin.tie(0); 
   
    int N;
    cin >> N;

	fill(index, index + 1000001, -1);

	for (int i = 0; i < N; i++) {
		cin >> people[i];
		index[people[i]] = i;
	}

	for (int i = 0; i < N; i++) {
		int x = people[i];
		for (int j = x * 2; j < 1000001; j += x) {
			if (index[j] != -1) {
				score[i]++;
				score[index[j]]--;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << score[i] << ' ';
	}

}