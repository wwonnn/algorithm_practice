#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int count = 1;
    
    while(true){
        int a_p = 0;
     
        if(a % 2 == 0){
            a_p = a - 1;
        }
        else{
            a_p = a + 1;
        }
        
        if(a_p == b){
            return count;
        }
        
        count++;
        a = ceil(float(a) / 2);
        b = ceil(float(b) / 2);
       
    }

    //return answer;
}