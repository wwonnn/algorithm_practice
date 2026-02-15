#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    int arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int day = 0;
    for (int i = 1; i < x; i++) {
        day += arr[i];
    }
    day += y;

    switch (day % 7)
    {
    case 0:
        cout << "SUN";
        break;
    case 1:
        cout << "MON";
        break;
    case 2:
        cout << "TUE";
        break;
    case 3:
        cout << "WED";
        break;
    case 4:
        cout << "THU";
        break;
    case 5:
        cout << "FRI";
        break;
    case 6:
        cout << "SAT";
        break;
    default:
        break;
    }

    return 0;
}