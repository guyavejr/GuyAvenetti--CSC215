// Input output library
#include <iostream>
// String library 
#include <string>

// define player attributes
struct Player
{
	std::string name;
	int health;
	int xp;
	std::string inventory[5];
	int inventoryCount = 0;
	int playerClass;
};

int main() 
{
	std::cout << "*** Guy--Assignment1 ***" << std::endl;

	char playAgain;

	do {
		Player player;

		//resetting player info
		player.name = "";
		player.health = 0;
		player.xp = 0;
		player.inventoryCount = 0;
		for (int i = 0; i < 5; ++i) {
			player.inventory[i] = "";
		}
		
		std::cout << "Hello, Adventurer! What is your name?" << std::endl;

		// enter player name
		std::cin >> player.name;

		// greeting using stored player name
		std::cout << "Welcome " << player.name << " to ENTER ADVENTURE TITLE" << std::endl;

		// choose a class 
		std::cout << "What type of Adventurer are you?" << std::endl;
		std::cout << "1. Warrior" << std::endl;
		std::cout << "2. Rogue" << std::endl;
		std::cout << "3. Magician" << std::endl;
		std::cout << "Please decide... 1,2 or 3..." << std::endl;

		std::cin >> player.playerClass;
		// create cases to change player info based on what class was chosen
		switch (player.playerClass)
		{
		case 1:
			std::cout << player.name << " is a Warrior" << std::endl;
			// set player health and inventory based on class chosen and display
			player.health = 25;
			player.inventory[0] = "Sword";
			player.inventory[1] = "Shield";
			std::cout << "You are a skilled combatant. Heavily armored with a mighty sword and shield." << std::endl;
			std::cout << "Health = "<< player.health << std::endl;
			std::cout << "Sword = 1-8 damage" << std::endl;
			std::cout << "Shield = block 1-4 damage" << std::endl;
			// display what was added to the inventoy slots 
			player.inventoryCount = 2;
			for (int i = 0; i < player.inventoryCount; ++i) {
				std::cout << player.inventory[i] << ", ";
			}
			std::cout << std::endl;
			break;
		case 2:
			std::cout << player.name << " is a Rogue" << std::endl;
			// set player health and inventory based on class chosen and display
			player.health = 20;
			player.inventory[0] = "Dagger";
			player.inventory[1] = "Lockpick";
			std::cout << "You are agile and stealthy. Mediumly armored, with a dagger and lockpicking tools." << std::endl;
			std::cout << "Health = " << player.health << std::endl;
			std::cout << "Dagger = 1-6 x2 damage" << std::endl;
			std::cout << "Lockpicking = able to pick locks" << std::endl;
			// display what was added to the inventoy slots 
			player.inventoryCount = 2;
			for (int i = 0; i < player.inventoryCount; ++i) {
				std::cout << player.inventory[i] << ", ";
			}
			std::cout << std::endl;
			break;
		case 3:
			std::cout << player.name << " is a Magician" << std::endl;
			// set player health and inventory based on class chosen and display
			player.health = 20;
			player.inventory[0] = "Spellbook";
			player.inventory[1] = "Staff";
			std::cout << "You are a practitioner of the arcane. Lightly armored, with a Staff and Spellbook." << std::endl;
			std::cout << "Health = " << player.health << std::endl;
			std::cout << "Spellbook = Contains 4 spells cast at random" << std::endl;
			std::cout << "Staff = Just there to complete the look" << std::endl;
			// display what was added to the inventoy slots 
			player.inventoryCount = 2;
			for (int i = 0; i < player.inventoryCount; ++i) {
				std::cout << player.inventory[i] << ", ";
			}
			std::cout << std::endl;
			break;
		}

		// Create a variable to hold user input
		int userChoice1;

		// give player choices 
		std::cout << "Where will " << player.name << " go first?" << std::endl;
		std::cout << "1. Head for the woods" << std::endl;
		std::cout << "2. Head to the abandoned building on the outside of town" << std::endl;
		std::cout << "3. Go to the library" << std::endl;
		std::cout << "Please decide... 1,2 or 3..." << std::endl;

		// Get user Input 
		std::cin >> userChoice1;

		//evaluate input
		switch (userChoice1)
		{
		case 1:
			std::cout << player.name << " heads into the woods to begin their journey. After quite a bit of hiking you encounter a wolf" << std::endl;
			break;
		case 2:
			std::cout << player.name << " heads to the abandoned building just outside of town. You are met with a locked door. There is no obvious way in." << std::endl;
			break;
		case 3:
			std::cout << player.name << " heads to the local library. There are a bunch of books." << std::endl;
			break;
		}

		std::cout << "Do you want to play again? (Y/N): ";
		std::cin >> playAgain;

	} while (playAgain == 'Y' || playAgain == 'y');

		return 0;
}