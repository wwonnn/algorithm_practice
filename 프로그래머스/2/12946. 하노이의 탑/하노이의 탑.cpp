#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> proc;

void hanoi(int n, int start, int end){
    if(n == 0){
        return;
    }
    
    int mid = 6 - start - end;
    hanoi(n-1, start, mid);
    proc.push_back({start, end});
    hanoi(n-1, mid, end);
    
}

vector<vector<int>> solution(int n) {
    // 원판이 n개일 때, n-1개를 도착지점과 출발지점이 아닌 곳에 옮긴다
    vector<vector<int>> answer;
    hanoi(n, 1, 3);
    // for(auto p : proc){
    //     answer.push_back(p);
    // }
    return proc;
}