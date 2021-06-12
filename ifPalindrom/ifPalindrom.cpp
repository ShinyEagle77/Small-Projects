/*
 *	�������� �������, �������
 *	���������� IsPalindrom
	���������� bool
	��������� �������� ���� string � ����������, �������� �� ���������� ������ �����������
	��������� - ��� ����� ��� �����, ������� ��������� �������� ����� ������� � ������ ������. ������ ������ �������� �����������.
 */


#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(string str)
{
	int strLength = str.length();
	for (int i = 0; i < strLength/2; ++i)
	{
		if (str[i] != str [strLength - i -1] )
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string str;
	cin >> str;

	cout << boolalpha;
	cout << IsPalindrom(str) << endl;

	return 0;
}