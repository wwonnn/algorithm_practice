#include <iostream> 
#include <algorithm> 
#include <vector> 

using namespace std; 

bool func(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() 
{ 
	ios::sync_with_stdio(0); 
	cin.tie(0); 
   
    int N;
    cin >> N;

    vector<pair<int, int>> p;
    int max_index = 0;
    int result = 0;

    for (int i = 0; i < N; i++) {
        int L, H;
        cin >> L >> H;
        p.push_back({ L, H });
    }
    sort(p.begin(), p.end(), func);

    for (int i = 0; i < N; i++) {
        if (p[i].second > p[max_index].second) max_index = i;
    }

    int index = 0;
    for (int i = 0; i <= max_index; i++) {
        if (p[i].second < p[index].second) continue;

        result += ((p[i].first - p[index].first) * p[index].second);
        index = i;
    }

    index = N - 1;
    for (int i = N - 1; i >= max_index; i--) {
        if (p[i].second < p[index].second) continue;

        result += ((p[index].first - p[i].first) * p[index].second);
        index = i;
    }

    cout << result + p[max_index].second;
    
   
}