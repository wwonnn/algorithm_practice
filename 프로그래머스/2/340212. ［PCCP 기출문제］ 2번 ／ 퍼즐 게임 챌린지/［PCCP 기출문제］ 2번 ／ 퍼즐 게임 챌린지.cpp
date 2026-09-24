#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    long long max_level = diffs[0];
    for(auto d : diffs)
        if(max_level < d) max_level = d;
    
    long long st, end, mid;
    long long min = 1e9;
    
    st = 1;
    end = max_level;
    mid = max_level / 2;
    while(st <= end)
    {
        // 숙련도가 mid일 때 조건에 만족하는지 확인
        long long level = mid;
        long long time = times[0];
        for(int i = 1; i < diffs.size(); i++)
        {
            if(diffs[i] > level)
                time += ((diffs[i] - level) * (times[i] + times[i - 1]) + times[i]);
            else
                time += times[i];
        }
    
        if(time > limit)
        {
            st = mid + 1; 
        }
        else
        {
            min = level; 
            end = mid - 1;
        }

        mid = (end + st) / 2;
    }
    
    return min;
}