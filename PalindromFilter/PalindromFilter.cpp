/*	Напишите функцию, которая

	называется PalindromFilter
	возвращает vector<string>
	принимает vector<string> words и int minLength и возвращает все строки из вектора words, которые являются палиндромами и имеют длину не меньше minLength
	Входной вектор содержит не более 100 строк, длина каждой строки не больше 100 символов.
 *
 *
 * 
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool IsPalindrom(string s)

{
	string temp;


	for (int i = s.size() - 1; i >= 0; --i)

	{
		temp += s[i];
	}


	if (s == temp) return true;

	else return false;
}

vector<string> PalindromFilter(vector<string> words, int minLength)

{
	vector<string> result;

	for (auto i : words)
	{
		if (i.size() >= minLength)

		{

			if (IsPalindrom(i))

				result.push_back(i);

		}

	}

	return result;

}

int main()

{

	vector<string> vec = { "abba", "samba", "tabbat" };
	vector<string> b;

	b = PalindromFilter(vec, 3);

	for (auto i : b)

	{

		cout << i << " ";

	}

	getchar();

	return 0;

}