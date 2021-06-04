/*
 * На вход дано целое положительное число N. Выведите его в двоичной системе счисления без ведущих нулей.
 */

#include <iostream>
#include <vector>

using namespace std;

void getNumber (int n)
{
	vector<int> a;
	
	for (int i = 0; n >= 1; ++i)
	{
		int c = n%2;
		n = n/2;
		a.push_back(c);
	}
	for (int i = a.size()-1; i >= 0; --i)
	{
		cout << a[i];
	}

	cout << endl;
}

int main()
{
	int n;
	cin >> n;

	getNumber(n);

	return 0;
}