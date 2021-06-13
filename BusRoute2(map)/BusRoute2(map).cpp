/*
В этой задаче вам нужно присваивать номера автобусным маршрутам.
А именно, для каждого маршрута, заданного набором названий остановок, нужно либо выдать новый номер (первому маршруту — 1, второму — 2 и т. д.),
либо вернуть номер существующего маршрута, которому соответствует такой набор остановок.
Наборы остановок, полученные друг из друга перестановкой остановок, считаются различными (см. пример).
 */

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int q;
	cin >> q;

	map<vector<string>, int> StopsToRouteNumber;

	for (int i = 0; i < q; ++i)
	{
		int n;
		cin >> n;
		
		vector<string> stopNames;
		
		for (int j = 0; j < n; ++j)
		{
			string stop;
			cin >> stop;
			stopNames.push_back(stop);
		}
	
		if(StopsToRouteNumber.count(stopNames) == 1)
		{
			cout << "Already exists for " << StopsToRouteNumber[stopNames] << endl;
		}
		else
		{
			
		const unsigned int routeNumber = StopsToRouteNumber.size() + 1;
		StopsToRouteNumber[stopNames] = routeNumber;
		
		cout << "New bus " << routeNumber << endl;
		}
		
	}

	return 0;
}