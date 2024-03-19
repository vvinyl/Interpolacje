#include <iostream>

using namespace std;

void oblicz()
{
    const int n = 3;
    double x[n] = { (- 4.01),( - 1.37),( - 0.13)};
    double y[n] = { ( - 4.74),( - 0.81),(4.98)};
    double a[n];

    a[0] = (y[0] / ((x[0] - x[1]) * (x[0] - x[2]))) + (y[1] / ((x[1] - x[0]) * (x[1] - x[2]))) + (y[2] / ((x[2] - x[0]) * (x[2] - x[1])));
    a[1] = -((y[0] * (x[1] + x[2])) / ((x[0] - x[1]) * (x[0] - x[2]))) - ((y[1] * (x[0] + x[2])) / ((x[1] - x[0]) * (x[1] - x[2]))) - ((y[2] * (x[0] + x[1])) / ((x[2] - x[0]) * (x[2] - x[1])));
    a[2] = ((y[0] * x[1] * x[2]) / ((x[0] - x[1]) * (x[0] - x[2]))) + ((y[1] * x[0] * x[2]) / ((x[1] - x[0]) * (x[1] - x[2]))) + ((y[2] * x[0] * x[1]) / ((x[2] - x[0]) * (x[2] - x[1])));

    cout << a[0] << endl << a[1] << endl << a[2] << endl;

}

int main()
{
    const int n = 3;
    double x[n] = { (-4.01),(-1.37),(-0.13) };
    double y[n] = { (-4.74),(-0.81),(4.98) };
    double a[n];
    double b[n];
    double c[n];

    cout << "x0 = " << x[0] << endl;
    cout << "x1 = " << x[1] << endl;
    cout << "x2 = " << x[2] << endl;
    cout << "y0 = " << y[0] << endl;
    cout << "y1 = " << y[1] << endl;
    cout << "y2 = " << y[2] << endl;
    double suma = 0;

    double suma2 = 0;

    double suma3 = 0;

    oblicz();

    for (int k = 0; k < n; k++)
    {
        double mianownik = 1;
        for (int i = 0; i < n; i++)
        {
            if (k != i)
            {
                mianownik *= (x[k] - x[i]);
            }
        }
        a[k] = y[k] / mianownik;

    }

    for (int k = 0; k < n; k++)
    {
        double mianownik = 1;
        double licznik = 0;
        for (int i = 0; i < n; i++)
        {
            if (k != i)
            {
                mianownik *= (x[k] - x[i]);

                for (int c = 0; c < n; c++)
                {
                    if (k != c && i != c)
                    {
                        licznik = x[i] + x[c];
                    }
                }

            }

        }
        b[k] = y[k] * (licznik) / mianownik;

    }

    for (int k = 0; k < n; k++)
    {
        double mianownik = 1;
        double licznik = 0;
        for (int i = 0; i < n; i++)
        {
            if (k != i)
            {
                mianownik *= (x[k] - x[i]);

                for (int c = 0; c < n; c++)
                {
                    if (k != c && i != c)
                    {
                        licznik = x[i] * x[c];
                    }
                }

            }

        }
        c[k] = y[k] * (licznik) / mianownik;

    }



    for (int j = 0; j < n; j++)
        suma += a[j];

    cout << "a = " << suma << endl;

    for (int j = 0; j < n; j++)
        suma2 -= b[j];

    cout << "b = " << suma2 << endl;

    for (int j = 0; j < n; j++)
        suma3 += c[j];

    cout << "c = " << suma3 << endl;




    return 0;
}
