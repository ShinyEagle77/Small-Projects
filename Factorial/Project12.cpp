#include <iostream>

using namespace std;

int factorial(int n)
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
		cout << factorial(n) << endl;
	}
	else if (n < 0)
		cout << 1 << endl;
	
	return 0;
}