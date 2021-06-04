#include <iostream>

using namespace std;

int sequenceSum(int start, int end, int step)
{

	int sum = 0;
	int sumAfter = 0;

	if (start <= end)
	{
		for (; start <= end; start += step)
		{
			sum += start;
		}

		return sum;
		
	}
	else
		return 0;
}


int main()
{
	int start, end, step;
	cin >> start >> end >> step;

	cout << sequenceSum(start, end, step) << endl;

	return 0;
}