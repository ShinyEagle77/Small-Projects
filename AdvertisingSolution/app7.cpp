#include <iostream>
#include <string>

using namespace std;

		 enum MonsterType
	{
		OGRE,
		GOBLIN,
		SKELETON,
		ORC,
		TROLL,
	};

	
	int main()
	{
		MonsterType monsterOne = GOBLIN;
		std::cout << monsterOne << std::endl;
		return 0;
	}

		 struct Advertising
		{
			int adShown;
			double adUsers;
			double adPayment;
		};

		void summingMoney (Advertising ad)
		{
			cout << "Ad been shown " << ad.adShown << " times" << endl;
			cout << "Users clicked on  " << ad.adUsers << endl;
			cout << "Payment after click is " << ad.adPayment << endl;

			cout << "Total payment is " << (ad.adShown * ad.adUsers / 100 * ad.adPayment) << " $$ " << endl;
		}

		int main ()
		{
			Advertising ad;

			cout << "How many views we got? ";
			cin >> ad.adShown;
			cout << "Percentage of user gotya? ";
			cin >> ad.adUsers;
			cout << "How much we make? ";
			cin >> ad.adPayment;

			summingMoney(ad);

			return 0;
		}

	