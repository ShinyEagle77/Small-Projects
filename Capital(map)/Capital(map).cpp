/*
	Реализуйте справочник столиц стран.

	На вход программе поступают следующие запросы:

	CHANGE_CAPITAL country new_capital — изменение столицы страны country на new_capital, либо добавление такой страны с такой столицей, если раньше её не было.
	RENAME old_country_name new_country_name — переименование страны из old_country_name в new_country_name.
	ABOUT country — вывод столицы страны country.
	DUMP — вывод столиц всех стран.
 */

#include <iostream>
#include <map>

using namespace std;

int main()
{
	int q;
	cin >> q;

	map<string, string> countryCapital;

	for (int i = 0; i < q; ++i)
	{
		string operationName;
		cin >> operationName;

		if (operationName == "CHANGE_CAPITAL") 
		{

			string country, new_capital;
			cin >> country >> new_capital;
			if (countryCapital.count(country) == 0) 
			{
				cout << "Introduce new country " << country << " with capital " << new_capital << endl;
			}
			else 
			{
				const string& old_capital = countryCapital[country];
				if (old_capital == new_capital) 
				{
					cout << "Country " << country << " hasn't changed its capital" << endl;
				}
				else 
				{
					cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
				}
			}
			countryCapital[country] = new_capital;

		}

			
		else if (operationName == "RENAME")
		{
			string oldCountryName, newCountryName;
			cin >> oldCountryName >> newCountryName;

			if (oldCountryName == newCountryName || countryCapital.count(oldCountryName) == 0 || countryCapital.count(newCountryName) == 1)
			{
				cout << "Incorrect rename, skip" << endl;
			}
			else
			{
				cout << "Country " << oldCountryName << " with capital " << countryCapital[oldCountryName] <<
					" has been renamed to " << newCountryName << endl;
				countryCapital[newCountryName] = countryCapital[oldCountryName];
				countryCapital.erase(oldCountryName);
			}
		}
		else if (operationName == "ABOUT")
		{
			string country;
			cin >> country;

			if (countryCapital.count(country) == 0)
			{
				cout << "Country " << country << " doesn't exist" << endl;
			}
			else
			{
				cout << "Country " << country << " has capital " << countryCapital[country] << endl;
			}
		
		}
		else if (operationName == "DUMP")
		{
			if (countryCapital.empty())
			{
				cout << "There are no countries in the world" << endl;
			}
			else
			{
				for (const auto& s : countryCapital)
				{
					cout << s.first << "/" << s.second << " ";
				}
			}

			cout << endl;
		}
	}
	return 0;
}