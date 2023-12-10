#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <windows.h>

// Set console color 
void setConsoleColor(int colorCode) 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorCode);
}
// Resetet console color 
void resetConsoleColor() 
{
    setConsoleColor(7);
}
// Display the hangman when a guess is wrong and make it red 
void displayHangman(int incorrectGuesses) 
{
    // 12 is red 
    setConsoleColor(12);
    if (incorrectGuesses >= 1) std::cout << "  |---|" << std::endl;
    else std::cout << "  |    " << std::endl;

    if (incorrectGuesses >= 2) std::cout << "  |   O" << std::endl;
    else std::cout << "  |" << std::endl;

    if (incorrectGuesses >= 4) std::cout << "  |  /|\\ " << std::endl;
    else if (incorrectGuesses >= 3) std::cout << "  |  /|" << std::endl;
    else std::cout << "  |" << std::endl;

    if (incorrectGuesses >= 6) std::cout << "  |  / \\" << std::endl;
    else if (incorrectGuesses >= 5) std::cout << "  |   \\" << std::endl;
    else std::cout << "  |" << std::endl;

    std::cout << "__|__" << std::endl;
    resetConsoleColor();
}

// Check if the character is contained in the word
bool containsChar(const std::string& word, char guess) 
{
    for (char letter : word) 
    {
        if (letter == guess) 
        {
            return true;
        }
    }
    return false;
}
// Display the fill in the blank and the correct guessed letters in the fill in the blank
void updateWordDisplay(const std::string& word, const std::string& guessedLetters) 
{
    for (char letter : word) 
    {
        if (guessedLetters.find(letter) != std::string::npos) 
        {
            std::cout << letter << " ";
        }
        else 
        {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

// Promts to play hangman while you still have guesses remaining
void playHangman(const std::string& word, int* maxAttempts, int* incorrectGuesses, char* guessedLetters) 
{
    while (*incorrectGuesses < *maxAttempts) 
    {

        std::cout << "\nWord to guess: ";
        updateWordDisplay(word, guessedLetters);

        if (word.find_first_not_of(guessedLetters) == std::string::npos) 
        {
            std::cout << "\nCongratulations! You've guessed the word \"" << word << "\" correctly!" << std::endl;
            return;
        }

        std::cout << "Guessed letters: " << guessedLetters << std::endl;
        displayHangman(*incorrectGuesses);

        char guess;
        std::cout << "Enter a letter guess: ";
        std::cin >> guess;

        if (std::strchr(guessedLetters, guess) != nullptr) 
        {
            std::cout << "You've already guessed this letter. Try another one." << std::endl;
            continue;
        }

        guessedLetters[std::strlen(guessedLetters)] = guess;
        guessedLetters[std::strlen(guessedLetters) + 1] = '\0';

        if (!containsChar(word, guess)) 
        {
            std::cout << "Incorrect guess!" << std::endl;
            (*incorrectGuesses)++;
        }
    }

    std::cout << "\nSorry, you've run out of attempts. The word was \"" << word << "\"." << std::endl;
}
int main() 
{
    // Possible words that can be guessed stored in an array
    std::string words[] = { "game", "class", "pointer", "function", "variable" };
    std::string* wordPtr = words; 
    // For random number generator to choose a word to guess at random
    srand(static_cast<unsigned int>(time(nullptr)));

    std::string word = wordPtr[rand() % 5]; 
    // Pointers
    int maxAttempts = 7;
    int incorrectGuesses = 0;
    char guessedLetters[26] = { '\0' };

    std::cout << "Welcome to Hangman!" << std::endl;
    std::cout << "Try to guess the word. You have " << maxAttempts << " attempts." << std::endl;
    std::cout << "All words have to do with this CSC215. Good Luck! " << std::endl;

    playHangman(word, &maxAttempts, &incorrectGuesses, guessedLetters);

    return 0;
}