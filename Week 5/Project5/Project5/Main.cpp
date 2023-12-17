#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

// Enum player classes
enum class PlayerClass {
    WARRIOR,
    ROGUE,
    MAGE
};

// Player Stucture
struct Player {
    PlayerClass playerClass;
    std::string name;
    int health;
    int maxHealth;
    int baseDamage;
    int xp;
    int level;
    int mana;
    int maxMana;
    int abilityCost;
};

// Monster Types 
enum class MonsterType {
    GOBLIN,
    HAG,
    WRAITH,
    OCULTIST,
    GOLEM,
    GIANT,
    NECROMANCER,
    DRAGON
};

// Struct to represent a monster
struct Monster {
    MonsterType type;
    int health; 
    string name;
};

// Struct for spell
struct Spell {
    string name;
    int damage;
};

// Mage Ability
Spell getRandomSpell() {
    // Array of different spells
    Spell spells[] = {
        {"Fire Ball", 35},
        {"Thunder Wave", 25},
        {"Fost Bolt", 25},
        {"Mage Bolt", 15},
        {"Fire Ball", 35},
        {"Thunder Wave", 25},
        {"Fost Bolt", 25},
        {"Mage Bolt", 15},
        {"Fire Ball", 35},
        {"Thunder Wave", 25},
        {"Fost Bolt", 25},
        {"Mage Bolt", 15},
        {"Power Word Kill", 100},
    };

    // Calculate the number of spells in the array
    int numSpells = sizeof(spells) / sizeof(spells[0]);

    // Randomly select a spell
    int index = rand() % numSpells;

    return spells[index];
};

// Level up once xp thresholds are met 
void levelUpPlayer(Player& player, int& xpThreshold) {
    if (player.xp >= xpThreshold) {
        player.level++;
        cout << "Congratulations! You leveled up to level " << player.level << "!" << endl;

        // Increase thresholds and upgrade player
        xpThreshold *= 2;
        player.baseDamage += 2;
        player.maxHealth += 2;
        player.health = player.maxHealth; 
        player.mana = player.maxMana;

        cout << "Player healed and stats increased. New base damage: " << player.baseDamage << ", New max health: " << player.maxHealth << endl;
    }
}

// Calculates player basic attack
int getPlayerDamage(const Player& player, int roundsSurvived, bool isBlocking, bool isDodging) {
    int baseDamage = 0;
    switch (player.playerClass) {
    case PlayerClass::WARRIOR:
        baseDamage = rand() % 25 + 20; // Warrior's damage between 15 and 34
        break;
    case PlayerClass::ROGUE:
        baseDamage = rand() % 25 * 2 + 5; // Rogue's damage between 10 and 34
        break;
    case PlayerClass::MAGE:
        baseDamage = rand() % 15 + 15; // Mage's damage between 25 and 54
        break;
    default:
        baseDamage = 0;
        break;
    }

    int damageMultiplier = 1.5;
    if (roundsSurvived > 0 && roundsSurvived % 3 == 0) {
        damageMultiplier = roundsSurvived / 3;
    }

    return baseDamage * damageMultiplier;
}

// Monster Damage by type
int getMonsterDamage(MonsterType monsterType) {
    switch (monsterType) {
    case MonsterType::GOBLIN:
        return rand() % 5 + 5;
    case MonsterType::HAG:
        return rand() % 10 + 5;
    case MonsterType::WRAITH:
        return rand() % 15 + 10;
    case MonsterType::OCULTIST:
        return rand() % 20 + 10;
    case MonsterType::GOLEM:
        return rand() % 25 + 10;
    case MonsterType::GIANT:
        return rand() % 30 + 15;
    case MonsterType::NECROMANCER:
        return rand() % 35 + 25;
    case MonsterType::DRAGON:
        return rand() % 40 + 25;

        
    default:
        return 0;
    }
}

// Monster Health by type
int getMonsterHealth(MonsterType monsterType) {
    switch (monsterType) {
    case MonsterType::GOBLIN:
        return rand() % 20 + 5;
    case MonsterType::HAG:
        return rand() % 25 + 10;
    case MonsterType::WRAITH:
        return rand() % 25 + 20;
    case MonsterType::OCULTIST:
        return rand() % 25 + 25;
    case MonsterType::GOLEM:
        return rand() % 25 + 30;
    case MonsterType::GIANT:
        return rand() % 35 + 30;
    case MonsterType::NECROMANCER:
        return rand() % 35 + 30;
    case MonsterType::DRAGON:
        return rand() % 40 + 45;


    default:
        return 0;
    }
}

// Convert Monster Type into string for text
std::string getMonsterName(MonsterType monsterType) {
    switch (monsterType) {
    case MonsterType::GOBLIN:
        return "Goblin";
    case MonsterType::HAG:
        return "Hag";
    case MonsterType::WRAITH:
        return "Wraith";
    case MonsterType::OCULTIST:
        return "Ocultist";
    case MonsterType::GOLEM:
        return "Golem";
    case MonsterType::GIANT:
        return "Giant";
    case MonsterType::NECROMANCER:
        return "Necromancer";
    case MonsterType::DRAGON:
        return "Dragon";
        
    default:
        return "Unknown";
    }
}

// Get Random Monster and stats
Monster getRandomMonster() {
    MonsterType randomType = static_cast<MonsterType>(rand() % static_cast<int>(MonsterType::WRAITH) + 1);

    Monster randomMonster;
    randomMonster.type = randomType;
    randomMonster.health = getMonsterHealth(randomType);
    randomMonster.name = getMonsterName(randomType);

    return randomMonster;
}

// Heal the Player when they defeat a monster
void healPlayer(Player& player, int monsterHealth) {
    int healAmount = static_cast<int>(0.1 * monsterHealth); // Calculate 10% of the monster's health

    cout << "You recovered " << healAmount << " health by defeating the monster!" << endl;

    player.health += healAmount;

    // Ensure player's health doesn't exceed max health
    if (player.health > player.maxHealth) {
        player.health = player.maxHealth;
    }
}

// Player health and mana bar 
void displayBars(const Player& player) {
    

    const int barWidth = 30; // Width of health and mana bars

    cout << player.name << "'s Health: [";
    int remainingHealthWidth = static_cast<int>(barWidth * static_cast<double>(player.health) / player.maxHealth);
    int damageWidth = barWidth - remainingHealthWidth;

    for (int i = 0; i < remainingHealthWidth; ++i) {
        cout << "\033[1;32m="; // Green color for remaining health
    }

    for (int i = 0; i < damageWidth; ++i) {
        cout << "\033[1;31m="; // Red color for damage taken
    }

    cout << "\033[0m] " << player.health << "/" << player.maxHealth << endl;

    cout << player.name << "'s Mana:   [";
    int remainingManaWidth = static_cast<int>(barWidth * static_cast<double>(player.mana) / player.maxMana);
    int usedManaWidth = barWidth - remainingManaWidth;

    // Display remaining mana in blue
    for (int i = 0; i < remainingManaWidth; ++i) {
        cout << "\033[1;34m="; // Blue color for remaining mana
    }

    // Display used mana in red
    for (int i = 0; i < usedManaWidth; ++i) {
        cout << "\033[1;31m="; // Red color for used mana
    }

    cout << "\033[0m] " << player.mana << "/" << player.maxMana << endl;
}

// Monster health bar
void displayHealthBar(const string& name, int currentHealth, int maxHealth) {
    const int barWidth = 20; // Width of health bar

    cout << name << "'s Health: [";
    int remainingWidth = static_cast<int>(barWidth * static_cast<double>(currentHealth) / maxHealth);
    int damageWidth = barWidth - remainingWidth;

    for (int i = 0; i < remainingWidth; ++i) {
        cout << "\033[1;32m="; // Green color for remaining health
    }

    for (int i = 0; i < damageWidth; ++i) {
        cout << "\033[1;31m="; // Red color for damage taken
    }

    cout << "\033[0m] " << currentHealth << "/" << maxHealth << endl;
}

// Choose your class / stats
Player chooseClass() {
    Player player;

    std::cout << "Hello, Adventurer! What is your name?" << std::endl;

    // enter player name
    std::cin >> player.name;

    // greeting using stored player name
    std::cout << "Welcome " << player.name << " to Generic Battle Simulator" << std::endl;

    // choose a class 
    std::cout << "What type of Adventurer are you?" << std::endl;
    cout << "Please choose your class:" << endl;
    cout << "1. Warrior - Special Ability: Block " << endl;
    cout << "2. Rogue - Special Ability: Dodge" << endl;
    cout << "3. Mage - Special Ability: Magic Spell" << endl;

    int classChoice;
    cin >> classChoice;

    switch (classChoice) {
    case 1:
        player.playerClass = PlayerClass::WARRIOR;
        player.name;
        player.health = 120;
        player.maxHealth = 120;
        player.mana = 100;
        player.maxMana = 100;
        player.abilityCost = 10;
        player.baseDamage = 10;
        player.xp = 0;
        player.level = 1;
        break;
    case 2:
        player.playerClass = PlayerClass::ROGUE;
        player.name;
        player.health = 100;
        player.maxHealth = 100;
        player.mana = 100;
        player.maxMana = 100;
        player.abilityCost = 10;
        player.baseDamage = 15;
        player.xp = 0;
        player.level = 1;
        break;
    case 3:
        player.playerClass = PlayerClass::MAGE;
        player.name;
        player.health = 80;
        player.maxHealth = 80;
        player.mana = 100;
        player.maxMana = 100;
        player.abilityCost = 15;
        player.baseDamage = 7;
        player.xp = 0;
        player.level = 1;
        break;
    default:
        cout << "Invalid choice. Choosing Warrior as default." << endl;
        player.playerClass = PlayerClass::WARRIOR;
        player.health = 120;
        player.maxHealth = 120;
        player.baseDamage = 10;
        player.xp = 0;
        player.level = 1;
        break;
    }

    return player;
}

// Battle logic
void startBattle(Player& player, int& defeatedMonsters) {
    
    cout << "See how many rounds you can last and monsters you can defeat" << endl;
    cout << "You will earn XP after each slain monster, this will also heal you and restore your mana." << endl;
    cout << "The battale begins." << endl;
    int roundsSurvived = 0; 
    bool isBlocking = false; 
    bool isDodging = false; 
    int xpThreshold = 5;

    while (true) {
        ++roundsSurvived; 

        Monster currentMonster = getRandomMonster(); 
        int monsterHealth = currentMonster.health;

        cout << "Round " << roundsSurvived << ": You encountered a " << currentMonster.name << "!" << endl;

        do {
            displayBars(player);
            displayHealthBar(currentMonster.name, monsterHealth, currentMonster.health);

            int playerDamage = getPlayerDamage(player, roundsSurvived, isBlocking, isDodging); 
            
            int monsterDamage = rand() % 15 + 10;

            

            char choice;
            cout << "Choose your action:" << endl;
            cout << "1. Attack" << endl;
            cout << "2. Use Special Ability" << endl;
            cout << "3. Run" << endl;

            cin >> choice;

            switch (choice) {
            case '1':
                cout << "You attack the " << currentMonster.name << " and deal " << playerDamage << " damage!" << endl;
                monsterHealth -= playerDamage;

                if (monsterHealth <= 0) {
                    cout << "Congratulations! You defeated the " << currentMonster.name << "!" << endl;
                    player.xp += currentMonster.health * 0.1; 
                    cout << "You gained " << currentMonster.health * 0.1 << " XP!" << endl;

                    levelUpPlayer(player, xpThreshold);

                    healPlayer(player, currentMonster.health); 
                    ++defeatedMonsters;

                    break; // Exit the monster encounter loop
                }

                cout << "The " << currentMonster.name << " attacks you and deals " << monsterDamage << " damage!" << endl;
                player.health -= monsterDamage;

                if (player.health <= 0) {
                    cout << "Game over! You were defeated by the " << currentMonster.name << "!" << endl;
                    cout << "You survived " << roundsSurvived << " rounds and defeated " << defeatedMonsters << " monsters." << endl;
                    defeatedMonsters--; // Decrement defeatedMonsters if player is defeated
                    return;
                }
                break;
            case '2':
                if (player.playerClass == PlayerClass::WARRIOR) {
                    if (player.mana >= player.abilityCost) {
                        player.mana -= player.abilityCost;
                        isBlocking = true;
                        playerDamage = getPlayerDamage(player, roundsSurvived, isBlocking, isDodging);
                        monsterHealth -= playerDamage / 2;
                        cout << "You are now blocking! Incoming damage will be reduced, but you will deal less damage." << endl;
                        cout << "You attack the " << currentMonster.name << " and deal " << playerDamage / 2 << " damage! " << endl;
                        if (isBlocking && monsterHealth > 0) {
                            cout << "The " << currentMonster.name << " attacks you and deals " << monsterDamage / 2 << " damage!" << endl;
                            player.health -= monsterDamage / 2;

                            if (player.health <= 0) {
                                cout << "Game over! You were defeated by the " << currentMonster.name << "!" << endl;
                                cout << "You survived " << roundsSurvived << " rounds and defeated " << defeatedMonsters << " monsters." << endl;
                                defeatedMonsters--;
                                return;
                            }
                        }
                        if (monsterHealth <= 0) {
                            cout << "Congratulations! You defeated the " << currentMonster.name << "!" << endl;
                            player.xp += currentMonster.health * 0.1; 
                            cout << "You gained " << currentMonster.health * 0.1 << " XP!" << endl;

                            levelUpPlayer(player, xpThreshold);

                            healPlayer(player, currentMonster.health); 
                            ++defeatedMonsters;

                            break; // Exit the monster encounter loop
                        }
                    }
                    else {
                        cout << "Not enough mana to use the special ability!" << endl;
                    }
                }
                else if (player.playerClass == PlayerClass::ROGUE) {
                    if (player.mana >= player.abilityCost) {
                        player.mana -= player.abilityCost;
                        isDodging = true;
                        playerDamage = getPlayerDamage(player, roundsSurvived, isBlocking, isDodging);
                        monsterHealth -= playerDamage / 2;
                        cout << "You are now dodging! Incoming damage will be reduced, but you will deal less damage." << endl;
                        cout << "You attack the " << currentMonster.name << " and deal " << playerDamage / 2 << " damage! " << endl;

                        if (isDodging && monsterHealth > 0) {
                            cout << "The " << currentMonster.name << " attacks you and deals " << monsterDamage / 2 << " damage!" << endl;
                            player.health -= monsterDamage / 2;

                            if (player.health <= 0) {
                                cout << "Game over! You were defeated by the " << currentMonster.name << "!" << endl;
                                cout << "You survived " << roundsSurvived << " rounds and defeated " << defeatedMonsters << " monsters." << endl;
                                defeatedMonsters--;
                                return;
                            }
                        }
                        if (monsterHealth <= 0) {
                            cout << "Congratulations! You defeated the " << currentMonster.name << "!" << endl;
                            player.xp += currentMonster.health * 0.1; 
                            cout << "You gained " << currentMonster.health * 0.1 << " XP!" << endl;

                            levelUpPlayer(player, xpThreshold);

                            healPlayer(player, currentMonster.health); 
                            ++defeatedMonsters;

                            break; // Exit the monster encounter loop
                        }
                    }
                    else {
                        cout << "Not enough mana to use the special ability!" << endl;
                    }
                }
                else if (player.playerClass == PlayerClass::MAGE) {
                    if (player.mana >= player.abilityCost) {
                        player.mana -= player.abilityCost;
                        Spell mageSpell = getRandomSpell();
                        monsterHealth -= mageSpell.damage;
                        
                        cout << "You cast " << mageSpell.name << " at the " << currentMonster.name << " and deal " << mageSpell.damage << " damage! " << endl;
                        cout << "The " << currentMonster.name << " attacks you and deals " << monsterDamage << " damage!" << endl;
                        player.health -= monsterDamage;
                        if (monsterHealth <= 0) {
                            cout << "Congratulations! You defeated the " << currentMonster.name << "!" << endl;
                            player.xp += currentMonster.health * 0.1; // 
                            cout << "You gained " << currentMonster.health * 0.1 << " XP!" << endl;

                            levelUpPlayer(player, xpThreshold);

                            healPlayer(player, currentMonster.health); 
                            ++defeatedMonsters;

                            break; // Exit the monster encounter loop
                        }
                    }
                    else {
                        cout << "Not enough mana to use the special ability!" << endl;
                    }
                }


                if (player.health <= 0) {
                    cout << "Game over! You were defeated by the " << currentMonster.name << "!" << endl;
                    cout << "You survived " << roundsSurvived << " rounds and defeated " << defeatedMonsters << " monsters." << endl;
                    defeatedMonsters--; 
                    return;
                }
                break;
            case '3':
                cout << "You choose to run away. Bye!" << endl;
                cout << "You survived " << roundsSurvived << " rounds and defeated " << defeatedMonsters << " monsters." << endl;
                return;
            default:
                cout << "Invalid choice. Try again!" << endl;
                break;
            }

            isBlocking = false;
            isDodging = false;

        } while (monsterHealth > 0);

        char continueChoice;
        cout << "Do you want to continue? (Y/N): ";
        cin >> continueChoice;
        if (continueChoice != 'Y' && continueChoice != 'y') {
            cout << "You survived " << roundsSurvived << " rounds and defeated " << defeatedMonsters << " monsters." << endl;
            return;
        }
    }
}

// Main
int main() {
    srand(time(0)); 

    cout << "Welcome to Guy's Final Project A Text-Based Battle Simulator!" << endl;

    int defeatedMonsters = 0; 

    do {
        Player player = chooseClass();

        startBattle(player, defeatedMonsters);

        char playAgain;
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;
        if (playAgain != 'Y' && playAgain != 'y') {
            break;
        }
    } while (true);

    return 0;
}
