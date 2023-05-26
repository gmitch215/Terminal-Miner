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
#include <bits/stdc++.h>
#include <set>

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
  system("/bin/stty raw");
  int c;
  system("/bin/stty -echo");
  c = getc(stdin);
  system("/bin/stty echo");
  system("/bin/stty cooked");
  return c;
}

// Start Game
void startGame() {
	bool gameStopped = false;
	while (!gameStopped) {
        string command;
        std::cin >> command;
        // Commands
        if (command == "-help")
            std::cout << "\n\x1b[4mCommand List\x1b[0m\n\n-help ——— Display this help message.\n-mine —— Mine ores.\n-sell ——— Sell generated ores!\n-balance ——— View your balance.\n-shop —— View the shop.\n";
        else if (command == "-mine") {
            int max = level * 5;
            int min = max - ((rand() % 4) - (rand() % 4)) + 4;
            if (min > max) min = max - 4;
            int mine = (rand() % (max - min) + 1) + min;

            stone += ceil(mine / 3);
            coal += ceil(mine / 16);
            gold += ceil(mine / 32);
            ruby += ceil(mine / 52);
            quartz += ceil(mine / 76);
            diamond += ceil(mine / 104);
            std::cout << "\nTotal Mined: \n\x1b[32m" << stone << "x\x1b[0m Stones\n\x1b[32m" << coal << "x\x1b[0m Coal Pieces\n\x1b[32m" << gold << "x\x1b[0m Gold Pieces\n\x1b[32m" << ruby << "x\x1b[0m Rubies\n\x1b[32m" << quartz << "x\x1b[0m Quartz Pieces\n\x1b[32m" << diamond << "x\x1b[0m Diamond Pieces\n\x1b[32m" << emerald << "x\x1b[0m Emeralds\n";
        } else if (command == "-sell") {
            set<double> added;

            added.insert(stone * 3);
            added.insert(coal * 9);
            added.insert(gold * 34);
            added.insert(ruby * 60);
            added.insert(quartz * 86);
            added.insert(diamond * 114);
            added.insert(emerald * 227);

            for (auto& i : added) balance += i;

            std::cout 
            << "\n\x1b[4mItems Sold\n\x1b[0m\nSold " << stone << "x Stone —— \x1b[32m" << stone * 3
            << "$\x1b[0m\nSold " << coal << "x Coal —— \x1b[32m" << coal * 9
            << "$\x1b[0m\nSold " << gold << "x Gold —— \x1b[32m" << gold * 34
            << "$\n\x1b[0mSold "<< ruby << "x Rubies —— \x1b[32m" << ruby * 60
            << "$\x1b[0m\nSold " << quartz << "x Quartz —— \x1b[32m" << quartz * 86
            << "$\x1b[0m\nSold " << diamond << "x Diamonds —— \x1b[32m" << diamond * 114
            << "$\x1b[0m\nSold " << emerald << "x Emeralds —— \x1b[32m" << emerald * 227 
            << "$\x1b[0m\n";

            stone = coal = gold = ruby = quartz = diamond = 0;
        } else if (command == "-balance")
            std::cout << "\nBalance for \x1b[31m" << username << "\x1b[0m is \x1b[32m$" << floor(balance) << "\x1b[0m.\n";
        else if (command == "-shop")
            std::cout << "\n\x1b[4mShop\x1b[0m\n-upgrade —— Buy an upgrade to increase your level.\n";
        else if (command == "-upgrade") {
            int requiredCost = level * 50;
            if (balance < requiredCost) {
                std::cout << "\nYou need \x1b[31m" << (requiredCost - balance) << "$\x1b[0m more to buy an upgrade!\nYou have " << "\x1b[32m$" << balance << "\n\x1b[0m";
            } else {
                level++;
                balance -= requiredCost;
                std::cout << "\nUpgraded to level \x1b[32m" << level << "\x1b[0m!\nYou have \x1b[32m" << balance << "$\x1b[0m.\n";
            }
        } else if (command == "-load") {
            string filename;
            std::cout << "\nTo upload a save state, fork this project and upload your save state file. Then type the file name below this message.\n";
            std::cin >> filename;
        } else
            std::cout << "\nInvalid Command. If you need a list, try \x1b[32m-help\x1b[0m.\n";
	}
}
// Game Code
int main() {
	std::cout << "Version " << version << "\nWelcome to Terminal Miner!\nPlease enter your Name:\n";
	std::cin >> username;
	std::cout << "\nWelcome to Terminal Miner, \x1b[36m" << username << "\x1b[0m!\nHave you played with us before? (Y/N)\n";
	string hasPlayed;
	bool sucessfulYN = false;
    while (sucessfulYN == false) {
        std::cin >> hasPlayed;
        transform(hasPlayed.begin(), hasPlayed.end(), hasPlayed.begin(), ::tolower);
        if (hasPlayed == "y") {
            sucessfulYN = true;
            std::cout << "\n\x1b[33mWell then, start mining!\x1b[0m\n";
            level = 1;
        } else if (hasPlayed == "n") {
            string enterSpace;
            sucessfulYN = true;
            std::cout << "\nWelcome to Terminal Miner! The goal of this game is to grow rich, in a terminal!\n\x1b[34mEnter any key to Continue\x1b[0m\n";
            std::cin >> enterSpace;
            std::cout << "\nAll commands start with a \x1b[32mhash\x1b[0m (-). You will use these to play the game. You can see a list of commands with \x1b[32m-help\x1b[0m.\n\x1b[34mEnter any key to Continue\x1b[0m\n";
            std::cin >> enterSpace;
            std::cout << "\nMining is \x1b[4mnot automatic\x1b[0m. You will need to run a command, \x1b[32m-mine\x1b[0m. You will also need to sell these ores with \x1b[32m-sell\x1b[0m.\n\x1b[34mEnter any key to Continue\x1b[0m\n";
            std::cin >> enterSpace;
            std::cout << "\nSelling ores will get you \x1b[32mmoney\x1b[0m ($). You can use these to \x1b[32mupgrade\x1b[0m or \x1b[32mlevel up\x1b[0m.\n\x1b[34mEnter any key to Continue.\x1b[0m\n";
            std::cin >> enterSpace;
            std::cout << "\nWell then, that's all you basically need to know. You can explore the commands, or just focus on growing rich. Good Luck!\n\x1b[34mThe game has started. Remember your commands!\x1b[0m\n";
            level = 1;
        } else {
            std::cout << "Please enter Y or N:\n";
        }
    }
    startGame();
}