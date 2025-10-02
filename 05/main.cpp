#include <iostream>
using namespace std;

// pobieram referencje
void getMinMax(const double &a, const double &b, const double &c,
                const double *& pMin, const double *& pMax) {
    if (a >= b && a >= c)
        pMax = &a;
    else if (b >= a && b >= c)
        pMax = &b;
    else
        pMax = &c;

    if (a <= b && a <= c)
        pMin = &a;
    else if (b <= a && b <= c)
        pMin = &b;
    else
        pMin = &c;
}

// pobieram wskaźniki
void getMinMax(const double *a, const double *b, const double *c,
                const double **pMin, const double **pMax) {
    if (*a >= *b && *a >= *c)
        *pMax = a;
    else if (*b >= *a && *b >= *c)
        *pMax = b;
    else
        *pMax = c;

    if (*a <= *b && *a <= *c)
        *pMin = a;
    else if (*b <= *a && *b <= *c)
        *pMin = b;
    else
        *pMin = c;
}

// dostarczamy referencje do oryginalnej zmiennej dzieki czemu to co zrobimy w funkcji zmienia zmienna
// &a - dostarczamy refernecje 'a' które mozemy zmienic w funkcji i oryginal sie zmieni na stałe
void ord3(double &a, double &b, double &c) {
    double tmp;
    for (int i = 2; i >= 0; i--) {
        if(a > b) {
            tmp = a;
            a = b;
            b = tmp;
        }
        if (b > c) {
            tmp = b;
            b = c;
            c = tmp;
        }
    }
}

// wrzucam wskaźnik adresu zmiennych do funkcji
void ord3(double *a, double *b, double *c) {
    double tmp;
    for (int i = 2; i >= 0; i--) {
        if(*a > *b) {
            // podmieniam wartosci które wskazuje wskaznik np *a <- wskaźnik do zmiennej 'a'
            // *a = *b <- podmienienie wartosci wskazanej przez wskaznik 'a' na wartosc z referencji 'b'
            tmp = *a;
            *a = *b;
            *b = tmp;
        }
        if (*b > *c) {
            tmp = *b;
            *b = *c;
            *c = tmp;
        }
    }
}

void printOrd ( const double *a, const double *b, const double *c) {
    cout << "" << endl;
    cout << *a << " " << *b << " " << *c;
}

void printMinMax ( const double *pmn, const double *pmx) {
    cout << "" << endl;
    cout << "MIN: " << *pmn << ", MAX: " << *pmx;
}

int main() {
    double a, b, c;

    // deklaracja stałych niezmiennych co do typu double wskaźników - nie mozna zmienic wartosci a mozna zmienic wskazanie
    const double *pMin, *pMax;
    // *pMin = 5 // zabronione bo nie można przypisac warotisci stalemu znacznikowi
    // pMin = &a // zmiana wskazania punktu w pamieci - dozwolone
    //        ^ adres zmiennej a - w taki sposób robiąc *pMin moge zmienic wartosc a z poziomu wskaznika
    //          nie można zmienić na wartość np. pMin = &a i później *pMin = 5; ponieważ jest const

    a = 1; b = 2; c = 3;
    ord3(a, b, c);
    printOrd(&a, &b, &c);

    a = 3; b = 2; c = 1;
    ord3(&a, &b, &c);
    printOrd(&a, &b, &c);

    a = -1; b = -1; c = 1;
    ord3(&a, &b, &c);
    printOrd(&a, &b, &c);

    a = 2; b = 3; c = 1;
    getMinMax(a, b, c, pMin, pMax);
    printMinMax(pMin, pMax);

    a = 3; b = 1; c = 2;
    getMinMax(&a, &b, &c, &pMin, &pMax);
    printMinMax(pMin, pMax);

    a = 3; b = 3; c = -1;
    getMinMax(&a, &b, &c, &pMin, &pMax);
    printMinMax(pMin, pMax);
}