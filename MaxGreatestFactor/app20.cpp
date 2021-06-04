/*
 * В stdin даны два натуральных числа. Выведите в stdout их наибольший общий делитель.
 */

#include <iostream>

using namespace std;

int getMax(int a, int b)
{
    while (a > 0 && b > 0) 
    {

        if (a > b) 
        {

            a %= b;

        }
        else 
        {

            b %= a;
        }
    }

    return a + b;
}


int main()
{
	int a, b;
	cin >> a >> b;

    cout << getMax(a, b) << endl;
}