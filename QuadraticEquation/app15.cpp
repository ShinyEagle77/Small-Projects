/*
 * На вход вашей программы в стандартном потоке ввода подаются действительные коэффициенты A, B и C уравнения Ax² + Bx + C = 0.
 * Выведите все его различные действительные корни в поток вывода в любом порядке, при этом разделяя корни пробелами.
 * Гарантируется, что хотя бы один из коэффициентов уравнения не равен нулю.
 */

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double a, b, c;
	cin >> a >> b >> c;

	double d;
	d = pow(b, 2) - 4 * a * c;

	if (a == 0 && b != 0 && c != 0)
	{
		double x = -1 * c / b;
		cout << x << endl;
	}
	else if (trunc(a) == 0 && trunc(b) == 0 && c != 0)
	{
		cout << " " << endl;
	}
	
	else
	{
		if (d > 0)
		{

			double x = (-1 * b + sqrt(d)) / (2 * a);
			double y = (-1 * b - sqrt(d)) / (2 * a);

			cout << x << " " << y << endl;

		}

		if (d < 0)
			cout << " " << endl;

		if (d == 0)
		{
			double x = -(b / (2 * a));

			cout << x << endl;
		
		}
	}
	
	return 0;
}