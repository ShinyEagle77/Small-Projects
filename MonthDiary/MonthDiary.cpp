#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<int> MONTH_LENGTHS = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MONTH_COUNT = MONTH_LENGTHS.size();

int main()
{
	int q;
	cin >> q;

	int month = 0;

	vector<vector<string>> days_concerns(MONTH_LENGTHS[month]);

	for (int i = 0; i < q; ++i)
	{
		string operationCode;
		cin >> operationCode;

		if (operationCode == "ADD")
		{
			int day;
			string concern;
			cin >> day >> concern;
			--day;
			days_concerns[day].push_back(concern);
			
		}
		else if (operationCode == "NEXT")
		{
			const int oldMonthLength = MONTH_LENGTHS[month];
			month = (month + 1) % MONTH_COUNT;

			const int newMonthLength = MONTH_LENGTHS[month];

			if (newMonthLength < oldMonthLength)
			{
				vector<string>& last_days_concerns = days_concerns[newMonthLength - 1];

				for (int day = newMonthLength; day < oldMonthLength; ++day)
				{
					last_days_concerns.insert(end(last_days_concerns), begin(days_concerns[day]), end(days_concerns[day]));
				}
			}
			days_concerns.resize(newMonthLength);
			
		}
		else if (operationCode == "DUMP")
		{
			int day;
			cin >> day;
			--day;

			cout << days_concerns.size() << " ";
			for (const string& concern : days_concerns[day])
			{
				cout << concern << " ";
			}
			cout << endl;
			
		}
	}
	return 0;
}