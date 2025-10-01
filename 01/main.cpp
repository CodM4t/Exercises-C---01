#include <iostream>
using namespace std;

int numSum(int i) {
    int sum = 0;
    while (i > 0) {
        sum += i % 10;
        i /= 10;
    }
    return sum;
}

int main() {
    unsigned int value, sum, maxSum = 0, maxSumValue;

    while (value != 0) {
        cin >> value;
        if (maxSum < numSum(value)) {
            maxSum = numSum(value);
            maxSumValue = value;
        }
    }
    cout << maxSumValue << " :: " << maxSum << endl;
}