/*
 * Напишите функцию sumTo(), которая принимает целочисленный параметр с именем value
 * и возвращает сумму всех чисел от 1 до значения value.
 */

#include <iostream>

int sumTo(int value)
{
	
	int total = 0;
	for (int count = 0; count <= value; ++count)
		total += count;

	return total;
}

int main()
{
	int value;
	std::cin >> value;
	int a = sumTo(value);
	std::cout << a << std::endl;

	return 0;
}