#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> Reversed(const vector<int>& v)
{
	vector <int> v_reversed;
	for (int i = v.size() - 1; i >= 0; --i)
	{
		v_reversed.push_back(v[i]);
	}

	return v_reversed;
}