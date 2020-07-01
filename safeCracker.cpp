#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Print welcome messages to terminal
    std::cout << "\n\nYour a master bank theive trying to secure level " << Difficulty;
    std::cout << " vault to crack...\nYour must enter the correct code to progess forward...\n\n";
}

bool PlayGame(int Difficulty)
{

    PrintIntroduction(Difficulty);

    // Declaring the numbers
    const int CodeA = rand() % Difficulty + Difficulty; 
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    // a = 7; assigning new values before sum or product changes results

    const int CodeSum = CodeA + CodeB + CodeC; //addition
    const int CodeProduct = CodeA * CodeB * CodeC;

    // b = 8; if variable below where it gets initizialed then wont take into account

    //Print out sum and product to terminal
    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add up to: " << CodeSum; 
    std::cout << "\n+ The codes multiply to give: " << CodeProduct <<std::endl;

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    
    

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //check if player is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Well done! You cracked one safe combination but there's another door inside! Keep going! ***";
        return true;
    }
    else
    {
        std::cout << "\n*** You entered the wrong combination! Be careful and Try again! ***";
        return false;
    }
}


int main() 
{
    srand(time(NULL)); // creates a random sequence based on time of day

    int LevelDifficulty = 1;
    int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels are completed 
    {
         bool bLevelComplete = PlayGame(LevelDifficulty);
         std::cin.clear(); //Clears any errrors
         std::cin.ignore(); //Discards the buffer

         if (bLevelComplete)
         {
             // Increase level difficulty
             ++LevelDifficulty;
         }
         
    }

    std::cout << "\n*** Great work breaking the safe! Now grab the jewels and get out of there! ***\n";
    return 0;
}
