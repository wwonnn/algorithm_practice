#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    
    // 모든 줄 순회
    for(int i = 0; i < park.size(); i++){
        int first = -1;
        int end = -1;
    
        for(int j = 0; j < park[i].size(); j++){
            // 비어있는 가로줄 길이 확인
            if(park[i][j] == "-1"){
                if(first == -1){
                    first = j;
                    end = j;
                }
                else{
                    end++;
                }
                
                // 비어있는 세로줄 확인
                if(find(mats.begin(), mats.end(), end - first + 1) != mats.end() && end - first + 1 <= park.size() - i){
                    int col_len = end - first + 1;
                    for(int k = first; k < end + 1; k++){
                        bool empty = true;
                        for(int t = i; t < i + col_len; t++){
                            if(park[t][k] != "-1"){
                                empty = false;
                                break;
                            }
                        }
                        if(!empty){
                            j = first;
                            first = -1;
                            end = -1;
                            break;
                        }
                    }
                    if(first != -1 && col_len > answer){
                        answer = col_len;
                    }     
                } 
            }
            else{
                first = -1;
                end = -1;
            }
        }
    }
    
    if(answer == 0){
        return -1;
    }

    return answer;
}