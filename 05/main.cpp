#include <iostream>
using namespace std;

void printOrd ( const double &a, const double &b, const double &c) {
    cout << "" << endl;
    cout << a << " " << b << " " << c << endl;
}

void printMinMax ( const double *pmn, double *pmx) {
    cout << "" << endl;
    cout << "MIN: " << *pmn << ", MAX: " << *pmx << endl;
}

int main() {
    double a, b, c;

    // deklaracja stałych niezmiennych co do typu double wskaźników - nie mozna zmienic wartosci a mozna zmienic wskazanie
    const double *pMin, *pMax;
    // *pMin = 5 // zabronione bo nie można przypisac warotisci stalemu znacznikowi
    // pMin = &a // zmiana wskazania punktu w pamieci - dozwolone
    //        ^ adres zmiennej a - w taki sposób robiąc *pMin moge zmienic wartosc a z poziomu wskaznika
    //          nie można zmienić na wartość np. pMin = &a i później *pMin = 5; ponieważ jest const

    a = 2; b = 1; c = 3;
    ord3(a, b, c);
    printOrd(&a, &b, &c);


}