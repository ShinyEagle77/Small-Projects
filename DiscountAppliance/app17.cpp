/*
 * Написать программу вычисления стоимости покупки товара с учётом скидки.
 * Если исходная стоимость товара больше A рублей, то на неё устанавливается скидка в X процентов.
 * Если исходная стоимость товара больше B рублей, то на неё устанавливается скидка в Y процентов.
 * На вход программе даны пять вещественных чисел: N, A, B, X, Y (A < B) - где N - исходная стоимость товара.
 * Выведите стоимость покупки товара с учётом скидки.
 */

#include <iostream>

using namespace std;

int main()
{
	double n, a, b, x, y;
	cin >> n >> a >> b >> x >> y;

	if (a < b)
	{
		if (n > a && n < b)
		{
			double result = n - (n / 100.00 * x);
			cout << result << endl;
		}
		else if (n > a && n <= b)
		{
			double result = n - (n / 100.00 * x);
			cout << result << endl;
		}
		else if (n > b)
		{
			double result = n - (n / 100.00 * y);
			cout << result << endl;
		}
		else if (n < b && n < a)
			cout << n << endl;
		else if (n == a)
			cout << n << endl;
	}
	else
		cout << n << endl;
	
	return 0;
}