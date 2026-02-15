#include <iostream>
#include <string>
using namespace std;

int main() {
    string bin;
    cin >> bin;

    int mod = bin.size() % 3;
    if (mod == 1) bin = "00" + bin;
    else if (mod == 2) bin = "0" + bin;

    string result = "";

    for (int i = 0; i < bin.size(); i += 3) {
        int value = (bin[i] - '0') * 4 +
                    (bin[i+1] - '0') * 2 +
                    (bin[i+2] - '0');
        result += (value + '0');
    }

    if (result.size() > 1 && result[0] == '0')
        result.erase(result.begin());

    cout << result;
    return 0;
}
