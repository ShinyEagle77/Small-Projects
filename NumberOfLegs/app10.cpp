/*
 * Определите перечисление (или класс enum) Animal, которое содержит следующих животных: pig, chicken, goat, cat, dog и ostrich.
 * Напишите функцию getAnimalName(), которая принимает параметр Animal и использует switch для возврата типа животного в качестве строки.
 * Напишите еще одну функцию — printNumberOfLegs(), которая использует switch для вывода количества лап соответствующего типа животного.
 * Убедитесь, что обе функции имеют кейс default, который выводит сообщение об ошибке. Вызовите printNumberOfLegs() в main(), используя в качестве параметров cat и chicken.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Animal
{
	pig,
	chicken,
	goat,
	cat,
	dog,
	ostrich,
};

string getAnimalName(Animal animal)
{
	switch (animal)
	{
	case Animal::pig:
		return "pig";
	case Animal::chicken:
		return "chicken";
	case Animal::goat:
		return "goat";
	case Animal::dog:
		return "dog";
	case Animal::ostrich:
		return "ostrich";
	case Animal::cat:
		return "cat";
	default:
		return "Unknown type";
	}
}

void pringAnimalLegs(Animal animal)
{
	cout << getAnimalName(animal) << " has ";

	switch (animal)
	{
	case Animal::chicken:
	case Animal::ostrich:
		cout << "2";
		break;

	case Animal::pig:
	case Animal::dog:
	case Animal::cat:
	case Animal::goat:
		cout << "4";
		break;

	default:
		cout << "Unknown legs";
	}

	cout << " legs \n";
}

int main()
{
	pringAnimalLegs(Animal::cat);
	pringAnimalLegs(Animal::chicken);
	return 0;
}