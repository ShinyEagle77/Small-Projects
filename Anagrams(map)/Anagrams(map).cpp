/*
 * Слова называются анаграммами друг друга, если одно из них можно получить перестановкой букв в другом.
 * Например, слово «eat» можно получить перестановкой букв слова «tea», поэтому эти слова являются анаграммами друг друга.
 * Даны пары слов, проверьте для каждой из них, являются ли слова этой пары анаграммами друг друга.
 */

#include <map>
#include <iostream>

using namespace std;

map<char, int> BuildCharCounters(const string& word)
{
	map <char, int> counters;
	for (auto c : word)
	{
		++counters[c];
	}

	return counters;

}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string firstWord, secondWord;
		cin >> firstWord >> secondWord;

		if (BuildCharCounters(firstWord) == BuildCharCounters(secondWord))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
		
	}

	return 0;
}
