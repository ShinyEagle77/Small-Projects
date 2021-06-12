/*
 *  Напишите функцию, которая
 *	называется Factorial
 *	возвращает int
 * 	принимает int и возвращает факториал своего аргумента. Гарантируется, что аргумент функции по модулю не превышает 10. Для отрицательных аргументов функция должна возвращать 1.
 */
#include <iostream>

using namespace std;

int Factorial(int n)
{
		int res = 1;
		for (int i = 1; i <= n; ++i)
		{
			res *= i;
		}
		return res;
}

int main()
{
	int n;
	cin >> n;

	if (n >= 0)
	{
		cout << Factorial(n) << endl;
	}
	else if (n < 0)
		cout << 1 << endl;
	
	return 0;
}