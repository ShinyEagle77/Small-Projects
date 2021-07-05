#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

class Rational {
public:
    Rational() {
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator) {

        if (denominator == 0)
        {
            throw invalid_argument("Invalid argument");
        }

        if (denominator < 0) {
            if (numerator < 0) {
                denominator = abs(denominator);
                numerator = abs(numerator);
            }
            else {
                denominator = abs(denominator);
                numerator = numerator - 2 * numerator;
            }
        }

        if (numerator == 0)
        {
            denominator = 1;
        }

        int nod = Nod(abs(numerator), abs(denominator));
        num = numerator / nod;
        den = denominator / nod;


    }

    int Numerator() const {
        return num;
    }

    int Denominator() const {
        return den;
    }

private:
    int num;
    int den;

    static int Nod(int a, int b) {
        while (a > 0 && b > 0) {
            if (a > b) {
                a %= b;
            }
            else {
                b %= a;
            }
        }
        return a + b;
    }
};

Rational operator + (const Rational& a, const Rational& b)
{
    int p = (a.Numerator() * b.Denominator()) + (b.Numerator() * a.Denominator());
    int q = a.Denominator() * b.Denominator();
    return { p, q };
}

Rational operator - (const Rational& a, const Rational& b)
{
    int p = (a.Numerator() * b.Denominator()) - (b.Numerator() * a.Denominator());
    int q = a.Denominator() * b.Denominator();
    return { p, q };
}

bool operator == (const Rational& a, const Rational& b)
{
    if ((a.Numerator() == b.Numerator()) && (a.Denominator() == b.Denominator()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

Rational operator * (const Rational& a, const Rational& b)
{
    return { (a.Numerator() * b.Numerator()), (a.Denominator() * b.Denominator()) };
}

Rational operator / (const Rational& a, const Rational& b)
{
    if (b.Numerator() == 0)
    {
        throw domain_error("Division by zero");
    }
    return { (a.Numerator() * b.Denominator()),(a.Denominator() * b.Numerator()) };
}

istream& operator >> (istream& stream, Rational& r)
{
    int n, d;
    char c;
    if (stream)
    {
        stream >> n >> c >> d;
        if (stream)
        {
            if (c == '/')
            {
                r = { n, d };
            }
        }
        else
        {
            stream.setstate(ios_base::failbit);
        }
    }
    return stream;

}


ostream& operator << (ostream& stream, const Rational& r)
{
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}

bool operator < (const Rational& left, const Rational& right)
{
    return (((left - right).Numerator()) < 0);
}

int main()
{
    try
    {
        Rational a, b;
        char operation;
        cin >> a >> operation >> b;
    	if (operation == '+')
    	{
            cout << a + b << endl;
    	}
    	if (operation == '-')
    	{
            cout << a - b << endl;
    	}
		if (operation == '*')
		{
            cout << a * b << endl;
		}
    	if (operation == '/')
    	{
            cout << a / b << endl;
    	}
    } catch (exception& e)
    {
        cout << e.what() << endl;
	}
	
    return 0;
}