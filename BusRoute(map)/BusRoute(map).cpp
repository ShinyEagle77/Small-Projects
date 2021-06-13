/*
	 Реализуйте систему хранения автобусных маршрутов.Вам нужно обрабатывать следующие запросы :

	NEW_BUS bus stop_count stop1 stop2 ... — добавить маршрут автобуса с названием bus и stop_count остановками с названиями stop1, stop2, ...
	BUSES_FOR_STOP stop — вывести названия всех маршрутов автобуса, проходящих через остановку stop.
	STOPS_FOR_BUS bus — вывести названия всех остановок маршрута bus со списком автобусов, на которые можно пересесть на каждой из остановок.
	ALL_BUSES — вывести список всех маршрутов с остановками.
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

void BusesForStop (map<string, vector<string>>& StopsToBus, const string& stop)
{
	if (StopsToBus.count(stop) == 0)
	{
		cout << "No stop" << endl;
	}
	else
	{
		for (const string& routeName : StopsToBus[stop])
		{
			cout << routeName << " ";
		}
		cout << endl;
	}
}

void StopsForBus(map<string, vector<string>>& BusToStop, map<string, vector<string>>& StopToBus, const string& routeName)
{
	if (BusToStop.count(routeName) == 0)
	{
		cout << "No bus" << endl;
	}
	else
	{
		for (const string& stop : BusToStop[routeName])
		{
			cout << "Stop " << stop << ": ";
			if (StopToBus[stop].size() == 1)
			{
				cout << "no interchange";
			}
			else
			{
				for (const string& otherBus : StopToBus[stop])
				{
					if(routeName != otherBus)
					{
						cout << otherBus << " ";
					}
				}
			}
			
			cout << endl;
			
		}
	}
}

void AllBuses(const map<string, vector<string>>& BusToStops)
{
	if (BusToStops.empty())
	{
		cout << "No buses" << endl;
	}
	else
	{
		for (const auto& bus : BusToStops)
		{
			cout << "Bus " << bus.first << ": ";
			for (const string& stop : bus.second)
			{
				cout << stop << " ";
			}
			
			cout << endl;
		}
	}
}

int main()
{
	int q;
	cin >> q;

	map<string, vector<string>> BusToStops, StopsToBus;

	for (int i = 0; i < q; ++i)
	{
		string operationName;
		cin >> operationName;
		
		
		
		if (operationName == "NEW_BUS")
		{
			string routeName;
			int stopCount;
			
			cin >> routeName >> stopCount;

			vector<string>& stops = BusToStops[routeName];
			stops.resize(stopCount);

			for (string& stop : stops)
			{
				cin >> stop;
				StopsToBus[stop].push_back(routeName);
			}
		}

		else if (operationName == "BUSES_FOR_STOP")
		{
			string stop;
			cin >> stop;

			BusesForStop(StopsToBus, stop);
		}

		else if (operationName == "STOPS_FOR_BUS")
		{
			string routeName;
			cin >> routeName;
			StopsForBus(BusToStops, StopsToBus, routeName);
		}
		else if (operationName == "ALL_BUSES")
		{
			AllBuses(BusToStops);
		}
	}

	return 0;
}