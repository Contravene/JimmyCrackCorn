/*
Author: Darren Schroeder
Date: December 12, 2016
Description: Simple little program to determine the requirements needed to unlock spell tiers in Realm Grinder
*/

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

// A menu to display
void displayMenu() {
	cout << "Choose spell type" << endl;
	cout << "1) Call to Arms" << endl;
	cout << "2) Spiritual Surge" << endl;
	cout << "3) Vanilla Alignment(Holy Light, Blood Frenzy)" << endl;
	cout << "4) Neutral Alignment(Gen Grinder)" << endl;
	cout << "5) Vanilla Faction(Fairy Chanting, Moon Blessing, God's Hand, Goblin's Greed, Night Time, Hellfire Blast)" << endl;
	cout << "6) Neutral Faction(Lightning Strike, Grand Balance, Brainwave)" << endl;
	cout << "7) Prestige Faction(Diamond Pickaxe, Combo Strike)" << endl;
	cout << "8) Neutral Prestige Faction(Dragon's Breath)" << endl;
	cout << "9) Exit" << endl;
}

int main() {

	// Variable declarations.
	int n = 1; // Spell tier currently at, default is 1
	int r = 42; // Reincarnation level, default is 42
	double xCoin;
	double xFaction = 0;
	long timeResult;
	double coinResult;
	double factionResult;
	int days;
	int hours;
	int minutes;
	int seconds;
	int menuChoice;

	// Set double output to three deminal points
	cout << setprecision(4);

	// Get Reincarnation level from user
	cout << "Please enter current Reincarnation: ";
	cin >> r;

	// Get spell choice
	displayMenu();
	cout << "Selection: ";
	cin >> menuChoice;

	// Loop until user decides to quit
	while (menuChoice != 9) {

		// Get current spell tier from user
		cout << "Please enter current tier of spell you wish to calculate: ";
		cin >> n;

		// Switch cases based on manu choice
		switch (menuChoice) {
		case 1:
			xCoin = (5.1 * pow(10, 52));
			break;
		case 2:
			xCoin = (6.6 * pow(10, 67));
			xFaction = (1 * pow(10, 13));
			break;
		case 3:
			xCoin = (5.4 * pow(10, 55));
			xFaction = (1 * pow(10, 9));
			break;
		case 4:
			xCoin = (6 * pow(10, 61));
			xFaction = (5 * pow(10, 9));
			break;
		case 5:
			xCoin = (5.4 * pow(10, 55));
			xFaction = (1 * pow(10, 10));
			break;
		case 6:
			xCoin = (5.7 * pow(10, 58));
			xFaction = (5 * pow(10, 10));
			break;
		case 7:
			xCoin = (6.3 * pow(10, 64));
			xFaction = (1 * pow(10, 12));
			break;
		case 8:
			xCoin = (6.9 * pow(10, 70));
			xFaction = (1 * pow(10, 15));
			break;
		default:
			system("pause");
			return 0;
			break;
		}

		// Calculate time required in seconds
		timeResult = (43200 * (pow((n + 1), 2) - (n + 1)) * pow(0.98, (r - (n + 1)) - 42));

		// Calculate diamond coin cost
		coinResult = pow(xCoin, (1 + 0.25 * (n - 1)));

		// Calculate faction coin cost
		factionResult = pow(xFaction, (1 + 0.25 * (n - 1)));

		days = ((timeResult / 60) / 60) / 24;
		hours = ((timeResult / 60) / 60) % 24;
		minutes = (timeResult / 60) % 60;
		seconds = timeResult % 60;

		// Output the results
		cout << "\nTime Required: " << days << " days, " << hours << " hours, " << minutes << " minutes, " << seconds << " seconds" << endl;
		cout << "Diamond Coins: " << scientific << setprecision(3) << coinResult << endl;
		if (menuChoice != 1) {
			cout << "Faction coins: " << factionResult << endl;
		}
		cout << endl;

		// Get spell choice
		displayMenu();
		cout << "Selection: ";
		cin >> menuChoice;
	}

	system("pause");  // Pause the program for viewing
	return 0; // Return a successful operation
}