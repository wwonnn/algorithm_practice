#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> subs;
    
    string s;
    cin >> s;

    int index;
    while (s.find('-') != string::npos)
    {
        index = s.find('-');
        subs.push_back(s.substr(0, index));
        s.erase(0, index + 1);
    }
    subs.push_back(s);

    long long sum = 0;
    while (subs[0].find('+') != string::npos)
    {
        index = subs[0].find('+');
        sum += stoi(subs[0].substr(0, index));
        subs[0].erase(0, index + 1);
    }
    sum += stoi(subs[0]);

    for (int i = 1; i < subs.size(); i++) {
        while (subs[i].find('+') != string::npos)
        {
            index = subs[i].find('+');
            sum -= stoi(subs[i].substr(0, index));
            subs[i].erase(0, index + 1);
        }
        sum -= stoi(subs[i]);
    }

    cout << sum;
}