#include <iostream>
using namespace std;

int maxValue(int a, int b, int c) {
    if (a > b && a > c)
        return a;
    else if (b > a && b > c)
        return b;
    else
        return c;
}

int main() {
    unsigned int a, b, c;
    cin >> a >> b >> c;

    for (int i = maxValue(a, b, c); i > 0; i--) {
        if ( a == i) {
            cout << "*";
            a -= 1;
        }
        else
            cout << " ";
        if ( b == i) {
            cout << "*";
            b -= 1;
        }
        else
            cout << " ";
        if ( c == i) {
            cout << "*" << endl;
            c -= 1;
        }
        else
            cout << " " << endl;
    }
}