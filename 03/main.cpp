#include <iostream>
using namespace std;

int main() {
    int value = 1, lastValue = 0, longestSequance = 1, lastLongestSeq = 0, sequanceNum = 0;

    while (value != 0) {
        cin >> value;
        if (value == lastValue)
            longestSequance += 1;
        if (longestSequance > lastLongestSeq) {
            sequanceNum = value;
            lastLongestSeq = longestSequance;
        }
        lastValue = value;
    }
    cout << lastLongestSeq << " times " << sequanceNum << endl;
}