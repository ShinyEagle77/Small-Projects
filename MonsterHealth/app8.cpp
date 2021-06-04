#include <iostream>
#include <string>

using namespace std;

enum class MonsterType
{
	OGRE,
	GOBLIN,
	SKELETON,
	ORC,
	TROLL,
};

struct Monster
{
	MonsterType type;
	string name;
	int health;
};

string getMonsterTypeInText (Monster monster)
{
	if (monster.type == MonsterType::OGRE)
		return "OGRE";
	if (monster.type == MonsterType::GOBLIN)
		return "GOBLIN";
	if (monster.type == MonsterType::SKELETON)
		return "SKELETON";
	if (monster.type == MonsterType::ORC)
		return "ORC";
	if (monster.type == MonsterType::TROLL)
		return "TROLL";

	return "Unknown monster";
}

void printMonsterInfo (Monster monster)
{
	cout << "Monster " << getMonsterTypeInText(monster) << " is named "
		<< monster.name << " and has " << monster.health << " health" << endl;
}

int main()
{
	Monster ogre = { MonsterType::OGRE, "Venom", 950 };
	Monster skeleton = { MonsterType::SKELETON, "CARNAGE" , 1050 };

	printMonsterInfo(ogre);
	printMonsterInfo(skeleton);

	return 0;
}