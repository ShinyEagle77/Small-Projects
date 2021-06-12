/*
 * Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней.
 * Найдите номера дней (в нумерации с нуля) со значением температуры выше среднего арифметического за все N дней.
 * Гарантируется, что среднее арифметическое значений температуры является целым числом.
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> temp(n);
	int sum = 0;
	for (int& s : temp)
	{
		cin >> s;
		sum += s;
	}

	int average = sum / n;
	vector<int> result;
	for (int i = 0; i < n; ++i)
	{
		if (temp[i] > average)
		{
			result.push_back(i);
		}
	}

	cout << result.size() << endl;
	for (int& s : result)
	{
		cout << s << " ";
	}

	return 0;
}