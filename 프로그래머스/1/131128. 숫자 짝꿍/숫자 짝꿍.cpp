#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string X, string Y) {
    string num;
    vector<int> x_index;
    vector<int> y_index;
    vector<int> index;
    
//     for(long long i = 0; i < X.size(); i++){
//         for(long long j = 0; j < Y.size(); j++){
//             if(X[i] == Y[j]){
//                 num += X[i];
//                 index.push_back(j);
                
//                 Y.erase(j, 1); 
//                 break;
//             }        
//         }

//     }
    
    // x, y 0~9가 각각 들어있는 갯수 세기
    for(int i = 0; i <= 9; i++){
        int count = 0;
        for(int j = 0; j < X.size(); j++){
            if(X.at(j) - '0' == i){
                count++;
            }
        }
        x_index.push_back(count);
        count = 0;
        
        for(int j = 0; j < Y.size(); j++){
            if(Y.at(j) - '0' == i){
                count++;
            }
        }
        y_index.push_back(count);
    }
    //cout << x_index[0] << x_index[1] << x_index[2] << x_index[3] << x_index[4] << x_index[5] << x_index[6] << x_index[7] << x_index[8] << x_index[9] << endl;
    //cout << y_index[0] << y_index[1]<< y_index[2]<< y_index[3]<< y_index[4]<< y_index[5]<< y_index[6]<< y_index[7]<< y_index[8]<< y_index[9] << endl;
    
    // x, y 겹치는 숫자 갯수 확인
    for(int i = 0; i < x_index.size(); i++){
        if(x_index.at(i) >= y_index.at(i) && y_index.at(i) != 0){
            index.push_back(y_index.at(i));
        }
        else if(x_index.at(i) < y_index.at(i) && x_index.at(i) != 0){
            index.push_back(x_index.at(i));
        }
        else{
            index.push_back(0);
        }
    }
    //cout << index.at(0) << index.at(1) << endl;
    
    // 문자열 생성
    for(int i = index.size() - 1; i >= 0; i--){
        for(int j = 0; j < index.at(i); j++){
            num += to_string(i);
        }
    }
    
    //sort(num.rbegin(), num.rend());
    
    string answer = num;
    if(answer == ""){
        return "-1";
    }
    else if(answer[0] == '0'){
        return "0";
    }
    return answer;
}