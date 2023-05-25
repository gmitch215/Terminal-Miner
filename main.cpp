// Includes
#include <cctype>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <unistd.h>
#include<bits/stdc++.h>
using namespace std;
// Globals
int level;
int stone;
int coal;
int gold;
int ruby;
int quartz;
int diamond;
int emerald;
double balance;
string version = "v2.0.0";
string username;

int keypress() {
  system ("/bin/stty raw");
  int c;
  system("/bin/stty -echo");
  c = getc(stdin);
  system("/bin/stty echo");
  system ("/bin/stty cooked");
  return c;
}

// Start Game
void startGame() {
	bool gameStopped = false;
	while (gameStopped == false) {
	string command;
	cin >> command;
	// Commands
	if (command == "-help") {
		cout << "\n\x1b[4mCommand List\x1b[0m\n\n-help ——— Display this help message.\n-mine —— Mine ores.\n-sell ——— Sell generated ores!\n-balance ——— View your balance.\n-shop —— View the shop.\n";
	} else if (command == "-mine") {
		int max = level * 5;
		int min = max - ((rand() % 4) - (rand() % 4)) + 4;
		if (min > max) min = max - 4;
		int mine = (rand() % (max - min) + 1) + min;
		double stoneValue = mine / 3;
		double coalValue = mine / 16;
		double goldValue = mine / 32;
		double rubyValue = mine / 52;
		double quartzValue = mine / 76;
		double diamondValue = mine / 104;
		stone += stoneValue;
		coal += ceil(coalValue);
		gold += ceil(goldValue);
		ruby += ceil(rubyValue);
		quartz += ceil(quartzValue);
		diamond += ceil(diamondValue);
		cout << "\nTotal Mined: \n\x1b[32m" << stone << "x\x1b[0m Stones\n\x1b[32m" << coal << "x\x1b[0m Coal Pieces\n\x1b[32m" << gold << "x\x1b[0m Gold Pieces\n\x1b[32m" << ruby << "x\x1b[0m Rubies\n\x1b[32m" << quartz << "x\x1b[0m Quartz Pieces\n\x1b[32m" << diamond << "x\x1b[0m Diamond Pieces\n\x1b[32m" << emerald << "x\x1b[0m Emeralds\n";
	} else if (command == "-sell") {
		double stoneSell = stone * 3;
		double coalSell = coal * 9;
		double goldSell = gold * 34;
		double rubySell = ruby * 60;
		double quartzSell = quartz * 86;
		double diamondSell = diamond * 114;
		double emeraldSell = emerald * 227;
		balance += stoneSell;
		balance += coalSell;
		balance += goldSell;
		balance += rubySell;
		balance += quartzSell;
		balance += diamondSell;
		balance += emeraldSell;
		cout << "\n\x1b[4mItems Sold\n\x1b[0m\nSold " << stone << "x Stone —— \x1b[32m" << stoneSell << "$\x1b[0m\nSold " << coal << "x Coal —— \x1b[32m" << coalSell << "$\x1b[0m\nSold " << gold << "x Gold —— \x1b[32m" << goldSell << "$\n\x1b[0mSold "<< ruby << "x Rubies —— \x1b[32m" << rubySell << "$\x1b[0m\nSold " << quartz << "x Quartz —— \x1b[32m" << quartzSell << "$\x1b[0m\nSold " << diamond << "x Diamonds —— \x1b[32m" << diamondSell << "$\x1b[0m\nSold " << emerald << "x Emeralds —— \x1b[32m" << emeraldSell << "$\x1b[0m\n";
		stone = 0;
		coal = 0;
		gold = 0;
		ruby = 0;
		quartz = 0;
		diamond = 0;
	} else if (command == "-balance") {
		cout << "\nBalance for \x1b[31m" << username << "\x1b[0m is \x1b[32m$" << floor(balance) << "\x1b[0m.\n";
	} else if (command == "-shop") {
		cout << "\n\x1b[4mShop\x1b[0m\n-upgrade —— Buy an upgrade to increase your level.\n";
	} else if (command == "-upgrade") {
		int requiredCost = level * 50;
		if (balance < requiredCost) {
			cout << "\nYou need \x1b[31m" << (requiredCost - balance) << "$\x1b[0m more to buy an upgrade!\nYou have " << "\x1b[32m$" << balance << "\n\x1b[0m";
		} else {
			level++;
			balance -= requiredCost;
			cout << "\nUpgraded to level \x1b[32m" << level << "\x1b[0m!\nYou have \x1b[32m" << balance << "$\x1b[0m.\n";
		}
	} else if (command == "-load") {
		string filename;
		cout << "\nTo upload a save state, fork this project and upload your save state file. Then type the file name below this message.\n";
		cin >> filename;
		
	} else {
		cout << "\nInvalid Command. If you need a list, try \x1b[32m-help\x1b[0m.\n";
	}
	}
}
// Game Code
int main() {
	cout << "Version " << version << "\nWelcome to Terminal Miner!\nPlease enter your Name:\n";
	cin >> username;
	cout << "\nWelcome to Terminal Miner, \x1b[36m" << username << "\x1b[0m!\nHave you played with us before? (Y/N)\n";
	string hasPlayed;
	bool sucessfulYN = false;
		while (sucessfulYN == false) {
		cin >> hasPlayed;
    transform(hasPlayed.begin(), hasPlayed.end(), hasPlayed.begin(), ::tolower);
		if (hasPlayed == "y") {
			sucessfulYN = true;
			cout << "\n\x1b[33mWell then, start mining!\x1b[0m\n";
			level = 1;
		} else if (hasPlayed == "n") {
			string enterSpace;
			sucessfulYN = true;
			cout << "\nWelcome to Terminal Miner! The goal of this game is to grow rich, in a terminal!\n\x1b[34mEnter any key to Continue\x1b[0m\n";
      cin >> enterSpace;
			cout << "\nAll commands start with a \x1b[32mhash\x1b[0m (-). You will use these to play the game. You can see a list of commands with \x1b[32m-help\x1b[0m.\n\x1b[34mEnter any key to Continue\x1b[0m\n";
			cin >> enterSpace;
			cout << "\nMining is \x1b[4mnot automatic\x1b[0m. You will need to run a command, \x1b[32m-mine\x1b[0m. You will also need to sell these ores with \x1b[32m-sell\x1b[0m.\n\x1b[34mEnter any key to Continue\x1b[0m\n";
			cin >> enterSpace;
			cout << "\nSelling ores will get you \x1b[32mmoney\x1b[0m ($). You can use these to \x1b[32mupgrade\x1b[0m or \x1b[32mlevel up\x1b[0m.\n\x1b[34mEnter any key to Continue.\x1b[0m\n";
			cin >> enterSpace;
			cout << "\nWell then, that's all you basically need to know. You can explore the commands, or just focus on growing rich. Good Luck!\n\x1b[34mThe game has started. Remember your commands!\x1b[0m\n";
			level = 1;
		} else {
			cout << "Please enter Y or N:\n";
		}
		}
		startGame();
}