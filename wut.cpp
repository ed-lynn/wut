#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Print welcome messages to the terminal
    std::cout << std::endl;
    std::cout << "\nYou took like " << Difficulty;
    std::cout << " more hit(s) than you should have...\n";
    std::cout << "\nYou're too stoned to remember your phone passcode...\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    
    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    /*
    This is a
    multi line comment
    */

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product to the terminal
    std::cout << "\n^ There are 3 numbers in the passcode ^\n";
    std::cout << "^ The code adds up to: " << CodeSum;
    std::cout << "\n^ The code multiplies to: " << CodeProduct << std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if player guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n***You got it!***\n";
        std::cout << "***Now you can celebrate with a fat hit...***\n\n";
        return true;
    }
    else
    {
        std::cout << "\n***Nope!***\n";
        std::cout << "***Better take a hit to help you remember...***\n\n\n";
        return false;
    }
}

int main()
{
    srand(time(NULL)); // create new random sequence based on time of day
    
    int LevelDifficulty = 1;
    int const MaxDifficulty =  5;

    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }
    std::cout << "\n*****You did it. You won some shitty terminal game.*****\n";
    std::cout << "*****Now get the fuck out of here.*****\n";
    return 0;

}