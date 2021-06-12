/*
 * Люди стоят в очереди, но никогда не уходят из её начала, зато могут приходить в конец и уходить оттуда.
 * Более того, иногда некоторые люди могут прекращать и начинать беспокоиться из-за того, что очередь не продвигается.
 * Будем считать, что люди в очереди нумеруются целыми числами, начиная с 0.
 * AVAILABLE COMMANDS : WORRY i, QUIET i, COME k, COME -k, WORRY_COUNT
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int numberOfOperations;
	cin >> numberOfOperations;

	vector<bool> peopleInQueue;

	for (int i = 0; i < numberOfOperations; ++i)
	{
		string operationName;
		cin >> operationName;

		if (operationName == "WORRY_COUNT")
		{
			auto worry_count = count(peopleInQueue.begin(), peopleInQueue.end(), true);
			cout << worry_count << endl;
		}
		
		else if (operationName == "COME")
		{
			int operationValue;
			cin >> operationValue;
			auto size = peopleInQueue.size() + operationValue;
			if (operationValue > 0)
			{
				peopleInQueue.resize(size, false);
				
				/*for (auto s : peopleInQueue)
				{
					cout << s;
				}
				cout << " people came" << endl;*/

			}
			else if (operationValue < 0)
			{
				if (size <= 0)
				{
					peopleInQueue.clear();
				}
				else
				{
					peopleInQueue.resize(size);
				}
				/*for (auto s : peopleInQueue)
				{
					cout << s;
				}
				cout << " people left" << endl;*/
			}

		}
	
		else if (operationName == "WORRY")
		{
			unsigned operationValue;
			cin >> operationValue;
			
			if (operationValue < peopleInQueue.size())
			{
				peopleInQueue[operationValue] = true;
			}
			
			/*for (auto s : peopleInQueue)
			{
				cout << s;
			}
			cout << " are worry" << endl;*/
			
		}
		else if (operationName == "QUIET")
		{
			unsigned operationValue;
			cin >> operationValue;

			if (operationValue < peopleInQueue.size())
			{
					peopleInQueue[operationValue] = false;
			}
		
			/*for (auto s : peopleInQueue)
			{
				cout << s;
			}
			cout << " are quiet" << endl;*/
			
		}
		
	}

	return 0;
	
}