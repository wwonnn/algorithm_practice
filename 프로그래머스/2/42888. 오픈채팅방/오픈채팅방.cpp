#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
void manage_chat(string record);
vector<string> answer;
map<string, string> user; // [id, nickname] 중복 없는 유저 리스트
vector<string> log; //[id] // id 전체 로그

vector<string> solution(vector<string> record) {
    // record 한줄씩 처리
    for_each(record.begin(), record.end(), manage_chat);
    
    return answer;
}

// record 입력값을 처리하는 함수
void manage_chat(string record){
    string state, id, nickname;
    stringstream record_u(record);
    record_u >> state >> id >> nickname;
    
    if(state == "Enter"){
        // Enter일 때
        if(user.find(id) != user.end()){
            // 기존 유저가 닉네임 바꾸고 들어왔을 때
            
            // answer에 있는 닉네임 모두 변경
            for(int i = 0; i < answer.size(); i++){
                if(log[i] == id){
                    answer[i].replace(0, user[id].size(), nickname);
                }
            }
            user[id] = nickname;
            log.push_back(id);
            answer.push_back(nickname + "님이 들어왔습니다.");
        }
        else{
            // 새로운 유저일 때
            log.push_back(id);
            user.insert({id, nickname});
            answer.push_back(nickname + "님이 들어왔습니다.");
        }
    }
    else if(state == "Leave"){
        // Leave일 때
        log.push_back(id);
        answer.push_back(user[id] + "님이 나갔습니다.");
    }
    else{
        // Change일 때
        
        // answer에 있는 닉네임 모두 변경
        for(int i = 0; i < answer.size(); i++){
            if(log[i] == id){
                answer[i].replace(0, user[id].size(), nickname);
            }
        }
        user[id] = nickname;
    }

}