#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int count = 0;
    
    while(true){
        if((bill.at(0) <= wallet.at(0) && bill.at(1) <= wallet.at(1)) || (bill.at(1) <= wallet.at(0) && bill.at(0) <= wallet.at(1))){
            // 지폐의 크기가 지갑보다 작을 때
            break;
        }
        else{
            // 지폐의 크기가 지갑보다 클 때
            bill.at(0) > bill.at(1) ? bill.at(0) = bill.at(0) / 2 : bill.at(1) = bill.at(1) / 2;
        }
        count++;
    }
    
    int answer = count;
    return answer;
}