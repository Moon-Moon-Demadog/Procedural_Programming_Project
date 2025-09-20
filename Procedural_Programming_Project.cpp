
#include <iostream>
#include <random>

 using namespace std;

// Function prototypes - All prototypes are declared at the beginning.
void displayInstructions();
int getComputerChoice(); // Renamed and changed to return the choice.
int getPlayerChoice(); // Renamed and changed to return the choice.
void displayChoice(int choice); // New function to display a choice.
void updateScores(int playerChoice, int computerChoice, int& draws, int& playerWins, int& computerWins);
void displayFinalResults(int totalRounds, int draws, int playerWins, int computerWins);

int main()
{
    int playerChoice;
    int computerChoice;
    int totalRounds = 0;
    int draws = 0;
    int playerWins = 0;
    int computerWins = 0;
    char playAgain;

    // Display instructions once at the start
    displayInstructions();

    cout << "Would you like to play Rock, Paper, Scissors? (Y for Yes / N for No)" << endl;
    cin >> playAgain;

    // The main game loop
    while (playAgain == 'y' || playAgain == 'Y')
    {
        // Get choices from the player and the computer
        playerChoice = getPlayerChoice();
        computerChoice = getComputerChoice();

        cout << "Computer chose ";
        displayChoice(computerChoice);
        cout << "You chose ";
        displayChoice(playerChoice);

        // Update scores and display round result
        updateScores(playerChoice, computerChoice, draws, playerWins, computerWins);
        totalRounds++; // Increment the round counter

        cout << "\n----------------------------------------" << endl;
        cout << "Current Score: " << "Player Wins: " << playerWins << " | Computer Wins: " << computerWins << " | Draws: " << draws << endl;
        cout << "----------------------------------------" << endl;

        cout << "Would you like to play again? (Y for Yes / N for No)" << endl;
        cin >> playAgain;
    }

    // Display final results after the loop ends
    displayFinalResults(totalRounds, draws, playerWins, computerWins);

    cout << "Thank you for visiting. Goodbye!" << endl;

    return 0;
}

// Function to get a random choice for the computer
int getComputerChoice()
{
    random_device rd;
    mt19937 eng(rd());
    uniform_int_distribution<int> distrib(1, 3);
    return distrib(eng);
}

// Function to display the choices (Rock, Paper, Scissors)
void displayChoice(int choice)
{
    if (choice == 1)
        cout << "Rock" << endl;
    else if (choice == 2)
        cout << "Paper" << endl; // Paper should be 2 to win against rock (1) as per traditional rules
    else if (choice == 3)
        cout << "Scissors" << endl; // Scissors should be 3 to win against paper (2)
}

// Function to get a valid choice from the player
int getPlayerChoice()
{
    int playerInput;
    do
    {
        cout << "Please enter your choice:" << endl;
        cout << "1. Rock" << endl;
        cout << "2. Paper" << endl;
        cout << "3. Scissors" << endl;
        cin >> playerInput;

        if (playerInput < 1 || playerInput > 3)
        {
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
        }
    } while (playerInput < 1 || playerInput > 3);

    return playerInput;
}

// Function to update the scores and display the winner of the round
void updateScores(int playerChoice, int computerChoice, int& draws, int& playerWins, int& computerWins)
{
    if (playerChoice == computerChoice)
    {
        cout << "It's a draw!" << endl;
        draws++;
    }
    // Using simple logic: 1(Rock) > 3(Scissors), 2(Paper) > 1(Rock), 3(Scissors) > 2(Paper)
    else if ((playerChoice == 1 && computerChoice == 3) || (playerChoice == 2 && computerChoice == 1) || (playerChoice == 3 && computerChoice == 2))
    {
        cout << "You win this round!" << endl;
        playerWins++;
    }
    else
    {
        cout << "You lose this round!" << endl;
        computerWins++;
    }
}

// Function to display the final game results
void displayFinalResults(int totalRounds, int draws, int playerWins, int computerWins)
{
    cout << "\n****************************************" << endl;
    cout << "Final Results:" << endl;
    cout << "Total Rounds Played: " << totalRounds << endl;
    cout << "Draws: " << draws << endl;
    cout << "Player Wins: " << playerWins << endl;
    cout << "Computer Wins: " << computerWins << endl;

    if (playerWins > computerWins)
        cout << "You are the overall winner!" << endl;
    else if (computerWins > playerWins)
        cout << "The computer is the overall winner!" << endl;
    else
        cout << "It's an overall draw!" << endl;

    cout << "****************************************" << endl;
}

void displayInstructions()
{
    cout << "Welcome to Rock, Paper, Scissors!" << endl;
    cout << "The rules are simple:" << endl;
    cout << "Rock crushes Scissors" << endl;
    cout << "Scissors cuts Paper" << endl;
    cout << "Paper covers Rock" << endl;
    cout << "You will be playing against the computer." << endl;
    cout << "Good luck!" << endl;
    cout << "\n----------------------------------------" << endl;
}
