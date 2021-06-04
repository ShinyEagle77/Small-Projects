#include <iostream>
#include <string>

using namespace std;

int calculate(int x, int y, char op)
{
	switch (op)
	{
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '*':
		return x * y;
	case '/':
		return x / y;
	case '%':
		return x % y;
	default:
		cout << "Unknown" << endl;
		return 0;
	}
}

int main()
{
	cout << "Enter first int number ";
		int x;
	cin >> x;

	cout << "Enter second int number ";
	int y;
	cin >> y;

	cout << "Enter the operator ";
	char op;
	cin >> op;

	cout << x << " " << op << " " << y << " is " << calculate(x, y, op) << endl;
}