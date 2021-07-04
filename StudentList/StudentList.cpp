/*
Определите структуру «Студент» со следующими полями: имя, фамилия, день, месяц и год рождения. Создайте вектор из таких структур, заполните его из входных данных и затем по запросам выведите нужные поля. Чтение и запись данных в этой задаче производится с использованием стандартных потоков.

Формат ввода

Первая строка содержит одно целое число N от 0 до 10000 — число студентов.

Далее идут N строк, каждая из которых содержит две строки длиной от 1 до 15 символов — имя и фамилию очередного студента, и три целых числа от 0 до 1000000000 — день, месяц и год рождения.

Следующая строка содержит одно целое число M от 0 до 10000 — число запросов.

Следующие M строк содержат строку длиной от 1 до 15 символов — запрос, и целое число от 1 до 1000000000 — номер студента (нумерация начинается с 1).

Формат вывода

Для запроса вида name K, где K от 1 до N, выведите через пробел имя и фамилию K-го студента.

Для запроса вида date K, где K от 1 до N, выведите через точку день, месяц и год рождения K-го студента.

Для остальных запросов выведите bad request.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student
{
	string name;
	string surname;
	int day;
	int month;
	int year;
};

int main()
{
	
	int n;
	cin >> n;
	vector<Student> students;

	

	for (int i = 0; i < n; ++i)
	{
		string name;
		string surname;
		int day;
		int month;
		int year;
		
		cin >> name >> surname >> day >> month >> year;
		students.push_back(Student{
		name,
		surname,
		day,
		month,
		year,
		});
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		string operation;
		int studentNumber;

		cin >> operation >> studentNumber;
		--studentNumber;
		
		if (operation == "name" && studentNumber < n && studentNumber >= 0)
		{

			cout << students[studentNumber].name << ' ' << students[studentNumber].surname << endl;
			
		}
		else if (operation == "date" && studentNumber < n && studentNumber >= 0)
		{

			cout << students[studentNumber].day << '.' << students[studentNumber].month << '.' << students[studentNumber].year << endl;

		}
		else
		{
			cout << "bad request" << endl;
		}
	}

	return 0;
	
}
