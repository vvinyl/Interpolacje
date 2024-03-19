#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;
using matrix = double**;

void pamiecNew(matrix& b, const int& m_, const int& n_);
void pamiecDel(matrix& b, const int& m_, const int& n_);
int wyswietl(double* tab, const unsigned n);
double funodx(const int&, const int&);
double fun(const double&);
matrix interpol(matrix& mac, const unsigned n, const double* x);
matrix transpoz(matrix& macA, const unsigned& m, const unsigned& n);
double* mnozenie(matrix&, double*, const unsigned roz);

//f(x)=-4.9x^2+0.27x -1.4
int main()
{
    constexpr int n{ 3 };
    string wzor{ "f(x)=-4.9x^2+0.27x -1.4" };
    double tabx[2 * n + 1];
    double taby[2 * n + 1];
   
    for (unsigned i{ 0 }; i < 2 * n + 1; i++)
    {
        tabx[i] = funodx(i, n);
        taby[i] = fun(tabx[i]);
    }

    matrix spr;
    pamiecNew(spr, 2 * n + 1, 2 * n + 1);
    spr = interpol(spr, n, tabx);

    matrix spr2;
    pamiecNew(spr2, 2 * n + 1, 2 * n + 1);
    spr2 = transpoz(spr, 2 * n + 1, 2 * n + 1);

    cout << "Dla " << wzor << " wspolczynniki wynosza:" << endl;
    double* tabw = mnozenie(spr2, taby, n);
    wyswietl(tabw, 2 * n + 1);
   
    delete[]tabw;
    pamiecDel(spr, 2 * n + 1, 2 * n + 1);
    pamiecDel(spr2, 2 * n + 1, 2 * n + 1);
    
    return 0;
}


double funodx(const int& i, const int& n) {
    return (2 * i * M_PI) / (2 * n + 1);
}

double fun(const double& x) {
    return -4.9 * x * x + 0.27 * x -1.4;

}



matrix interpol(matrix& mac, const unsigned n, const double* x) {
    for (unsigned i{ 0 }; i < 2 * n + 1; i++) {
        mac[i][0] = 1 / sqrt(2);
        for (unsigned j{ 1 }; j <= n; j++) {
            mac[i][2 * j - 1] = sin(j * x[i]);
            mac[i][2 * j] = cos(j * x[i]);
        }
    }
    return mac;
}



void pamiecNew(matrix& b, const int& m_, const int& n_)
{
    b = new double* [m_];
    for (int i = 0; i < m_; ++i)
        b[i] = new double[n_];
}

void pamiecDel(matrix& b, const int& m_, const int& n_)
{
    for (int i = 0; i < m_; ++i)
        delete[]b[i];

    delete[]b;
}


int wyswietl(double* tab, const unsigned n) {
    for (int j = 0; j < n; ++j) {
        cout << setprecision(6) << "\t" << "a" << j << ": " << tab[j];
        cout << endl;
    }
}


matrix transpoz(matrix& macA, const unsigned& m, const unsigned& n) {

    matrix wyn;
    pamiecNew(wyn, n, m);

    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < m; j++) {
            wyn[i][j] = macA[j][i] * 2 / 7;
        }
    }
    return wyn;
}


double* mnozenie(matrix& mac, double* vec, const unsigned roz) {
    double* nowy = new double[2 * roz + 1];
    for (unsigned i{ 0 }; i < 2 * roz + 1; i++) {
        nowy[i] = 0;
    }


    for (unsigned i{ 0 }; i < 2 * roz + 1; i++) {
        for (unsigned j{ 0 }; j < 2 * roz + 1; j++) {
            nowy[i] += mac[i][j] * vec[j];
        }
    }
    return nowy;
}
