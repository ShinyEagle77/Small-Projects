/*
* Напишите программу, которая просит пользователя ввести целое число, а затем сообщает, является ли его число чётным или нечётным. 
* Напишите функцию isEven(), которая возвращает true, если целое число является чётным. 
* Используйте оператор деления с остатком, чтобы определить чётность числа.
*/

#include <iostream>

using namespace std;

bool isEven(int x)
{
	return (x % 2 == 0);
}

int main()
{
	cout << "Enter a number ";
	int x;
	cin >> x;

	if (isEven(x))
		cout << x << " is even \n";
	else
		cout << x << " is not even \n";
	
	return(0);
}