// Input output library
#include <iostream>
// String library 
#include <string>

#include <ctime>

#include <cstdlib>
// enum for player classes
enum PlayerClass {
	WARRIOR,
	ROGUE,
	MAGE
};
// define player attributes
struct Player
{
	std::string name;
	int health;
	int xp;
	std::string inventory[5];
	int inventoryCount = 0;
	PlayerClass playerClass;
};

// function for player attack
int playerAttack(PlayerClass playerClass) {
	switch (playerClass)
	{
		// TO DO : add - damage taken because of shield
	case WARRIOR:
		return rand() % 10 + 5; // Warrior's attack
		// TO DO : add dodge rate?
	case ROGUE:
		return (rand() % 6 + 2) * 2; // Rogue's attack
		// TO DO : possible staff attack or spell attack
	case MAGE:
		return rand() % 4 + 1;

	}
}
// function for wolf attack
int wolfAttack() {
	return rand() % 7 + 1;
}
//cast spell at random
void castSpell(int spellNumber, int& wolfHealth)
{
	switch (spellNumber)
	{
	case 1:
		std::cout << "You cast Fireball! It deals 20 damage to the wolf!\n";
		wolfHealth -= 10;
		break;
	case 2:
		std::cout << "You cast Frostbolt! It deals 15 damage to the wolf!\n";
		wolfHealth -= 10;
		break;
	case 3:
		std::cout << "You cast Thunder Shock! It deals 18 damage to the wolf!\n";
		wolfHealth -= 12;
		break;
	default:
		std::cout << "You cast a weak spell, dealing 5 damage to the wolf!\n";
		wolfHealth -= 5;
		break;
	}
}
//Combat
void startBattle(Player player) {
	int wolfHealth = 25;

	std::cout << "Your battle with the Wolf starts NOW!\n";

	int choice;
	do {
		int playerDamage = playerAttack(player.playerClass);
		int wolfDamage = wolfAttack();

		std::cout << "Your health: " << player.health << " Monster's health: " << wolfHealth << "\n";
		std::cout << "Choose your action:\n";
		std::cout << "1. Attack\n";
		std::cout << "2. Run\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			if (player.playerClass == MAGE) {
				int spellNumber = rand() % 4;
				castSpell(spellNumber, wolfHealth);
			}
			else {
				std::cout << "You attack the monster and deal " << playerDamage << " damage!\n";
				wolfHealth -= playerDamage;
			}
			if (wolfHealth <= 0) {
				std::cout << "Congratulations! You defeated the wolf!\n";
			}
			else {
				std::cout << "The wolf attacks you and deals " << wolfDamage << " damage!\n";
				player.health -= wolfDamage;

				if (player.health <= 0) {
					std::cout << "Game over! You were defeated by the wolf.\n";
					return;
				}
			}
			break;
		case 2:
			std::cout << "You choose to run away. Bye!\n";
			return;
		}
	} while (player.health > 0 && wolfHealth > 0);
}

// if you choose to go into the woods
void woodsChoice(Player player)
{
	int woodsChoice;
	std::cout << player.name << " heads into the woods to begin their journey. After quite a bit of hiking you encounter a wolf. It has not noticed you. What will you do?" << std::endl;
	std::cout << "1. Attack the wolf" << std::endl;
	std::cout << "2. Hide and wait for the wolf to go away" << std::endl;
	std::cout << "3. Go back to town. You didnt sign up for this" << std::endl;
	std::cout << "Please decide... 1,2 or 3..." << std::endl;
	std::cin >> woodsChoice;
	switch (woodsChoice)
	{
	case 1:
		startBattle(player);
		break;
	case 2:
		std::cout << "you hide from the wolf until you think you are safe." << std::endl;
		std::cout << "As you emerge from your hiding spot you hear something behind you." << std::endl;
		std::cout << "The wolf lunges at you" << std::endl;
		startBattle(player);
		break;

	case 3:
		//mainChoice(player);
		break;

	}
}
// if you choose to go to the abandoned building
void abandonedbuildingChoice(Player player)
{
	int abandonedbuildingChoice;
	std::cout << player.name << " heads to the abandoned building just outside of town. You are met with a locked door. There is no obvious way in." << std::endl;
	std::cout << "1. Try and find a way in?" << std::endl;
	std::cout << "2. Try and make a way in?" << std::endl;
	std::cout << "3. Return to town?" << std::endl;
	std::cin >> abandonedbuildingChoice;
	switch (abandonedbuildingChoice)
	{
	case 1:
		if (player.playerClass == ROGUE) {
			std::cout << "you find a door with an easily pickable lock" << std::endl;
		}
		else {
			std::cout << "there is no obvious way in. if only you were a rogue..." << std::endl;
			return;
		}
		break;
	case 2:
		if (player.playerClass == WARRIOR) {
			std::cout << "anything can be a door if you try hard enough" << std::endl;
			std::cout << "you make a door, and then enter the building" << std::endl;
		}
		else {
			std::cout << "do you think you are some kind of warrior?" << std::endl;
			return;
		}
		break;
	case 3:
		//mainChoice(player);
		return;
		break;
	}
}
// TO DO if you choose the library
void libraryChoice(Player player)
{
	std::cout << player.name << " heads to the local library. There are a bunch of books." << std::endl;
	std::cout << "this choice has not yet been implamented try back later" << std::endl;
}
void mainChoice(Player player)
{
	int userChoice2;

	std::cout << "Where will " << player.name << " go first?" << std::endl;
	std::cout << "1. Head for the woods" << std::endl;
	std::cout << "2. Head to the abandoned building on the outside of town" << std::endl;
	std::cout << "3. Go to the library" << std::endl;
	std::cout << "Please decide... 1,2 or 3..." << std::endl;

	// Get user Input 
	std::cin >> userChoice2;
	switch (userChoice2)
	{
	case 1:
		woodsChoice(player);
		break;
	case 2:
		abandonedbuildingChoice(player);
		break;
	case 3:
		libraryChoice(player);
		break;
	}


}

int main()
{
	std::cout << "*** Guy--Assignment2 ***" << std::endl;

	Player player;
	int classChoice;
	//resetting player info
	player.playerClass;
	player.name = "";
	player.health = 10;
	player.xp = 0;
	player.inventoryCount = 0;
	for (int i = 0; i < 5; ++i) {
		player.inventory[i] = "";
	}

	std::cout << "Hello, Adventurer! What is your name?" << std::endl;

	// enter player name
	std::cin >> player.name;

	// greeting using stored player name
	std::cout << "Welcome " << player.name << " to Generic Fantasy Adventure" << std::endl;

	// choose a class 
	std::cout << "What type of Adventurer are you?" << std::endl;
	std::cout << "1. Warrior" << std::endl;
	std::cout << "2. Rogue" << std::endl;
	std::cout << "3. Magician" << std::endl;
	std::cout << "Please decide... 1,2 or 3..." << std::endl;

	std::cin >> classChoice;
	// create cases to change player info based on what class was chosen
	switch (classChoice)
	{
	case 1:
		std::cout << player.name << " is a Warrior" << std::endl;
		// set player health and inventory based on class chosen and display
		player.playerClass = WARRIOR;
		player.health = player.health + 15;
		player.inventory[0] = "Sword";
		player.inventory[1] = "Shield";
		std::cout << "You are a skilled combatant. Heavily armored with a mighty sword and shield." << std::endl;
		std::cout << "Health = " << player.health << std::endl;
		std::cout << "Sword = 1-8 damage" << std::endl;
		//std::cout << "Shield = block 1-4 damage" << std::endl;
		// display what was added to the inventoy slots 
		player.inventoryCount = 2;
		for (int i = 0; i < player.inventoryCount; ++i) {
			std::cout << player.inventory[i] << ", ";
		}
		std::cout << std::endl;
		mainChoice(player);
		break;
	case 2:
		std::cout << player.name << " is a Rogue" << std::endl;
		// set player health and inventory based on class chosen and display
		player.playerClass = ROGUE;
		player.health = player.health + 10;
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
		mainChoice(player);
		break;
	case 3:
		std::cout << player.name << " is a Magician" << std::endl;
		// set player health and inventory based on class chosen and display
		player.playerClass = MAGE;
		player.health = player.health + 10;
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
		std::cout << std::endl;
		mainChoice(player);
		break;
	}

}