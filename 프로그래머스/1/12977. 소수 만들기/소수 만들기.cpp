#include <vector>
#include <iostream>

using namespace std;

bool check_decimal(int num);

int solution(vector<int> nums) {
    int answer = 0;
    
    for(int i = 0; i < nums.size() - 2; i++){
        for(int j = i + 1; j < nums.size() - 1; j++){
            for(int k = j + 1; k < nums.size(); k++){
                if(check_decimal(nums.at(i) + nums.at(j) + nums.at(k))){
                    answer++;
                }
            }
        }
    }

    return answer;
}

bool check_decimal(int num){
    // 소수인지 판별
    for(int i = 2; i < num; i++){
        // 2부터 num - 1까지 모두 나눠보기
        if(num % i == 0){
            return false;
        }     
    }
    return true;
}