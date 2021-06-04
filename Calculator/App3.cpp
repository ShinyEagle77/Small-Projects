
// Программа калькулятор

#include <iostream>

double getDouble()
{
	std::cout << "Enter double value ";
	double x;
	std::cin >> x;
	return x;
}

char getOperator()
{
	std::cout << "Choose an operation ";
	char op;
	std::cin >> op;
		return op;
}
void printResult(double x, char op, double y)
{
	if (op == '+')
		std::cout << x << " + " << y << " = " << x + y << '\n';
	else if (op == '-')
		std::cout << x << " - " << y << " = " << x - y << '\n';
	else if (op == '*')
		std::cout << x << " * " << y << " = " << x * y << '\n';
	else if (op == '/')
		std::cout << x << " / " << y << " = " << x / y << '\n';
	else std::cout << "Symbol is wrong" << std::endl;
}



int main()
{
	double x = getDouble();
	double y = getDouble();

	char op = getOperator();

	printResult(x, op, y);
}