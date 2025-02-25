#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define IEF 1e14 * 4

using namespace std;

bool parametric_search(long long time, int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t){
    long long sum_g = 0;
    long long sum_s = 0;
    long long sum_w = 0;
    
    for(int i = 0; i < g.size(); i++){
        long long cnt = 0;
        
        // 가능한 운반 횟수
        if(time / t[i] % 2) cnt = time / t[i] / 2 + 1;
        else cnt = time / t[i] / 2;
        
        // 모두 금 운반한 경우
        if(cnt * w[i] < g[i]) sum_g += cnt * w[i];
        else sum_g += g[i];
        
        // 모두 은 운반한 경우
        if(cnt * w[i] < s[i]) sum_s += cnt * w[i];
        else sum_s += s[i];
        
        // 금은 섞어서 운반한 경우
        if(cnt * w[i] < g[i] + s[i]) sum_w += cnt * w[i];
        else sum_w += g[i] + s[i];
    }
    
    if(sum_g >= a && sum_s >= b && sum_w >= a + b) return true;
    else return false;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    // parametric search
    long long left = 0;
    long long right = IEF; // 최악의 경우 걸리는 시간
    long long mid;
    
    long long answer = 0;
    // 이분탐색
    while(left <= right){
        mid = (left + right) / 2;
        if(parametric_search(mid, a, b, g, s, w, t)){
            answer = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    
    return answer;
}