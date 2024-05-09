#include <cstdlib> 
#include <ctime> 
#include <iostream> 
using namespace std;

// Function to get the computer's move 
char getComputerMove() {
    int move;
    // Generate random number between 0 - 2 
    srand(time(NULL));
    move = rand() % 3;

    // Return move based on the random number generated 
    if (move == 0) {
        return 'p';
    }
    else if (move == 1) {
        return 's';
    }
    else {
        return 'r';
    }
}

// Function to return the result of the game 
int getResults(char pMove, char cMove) {
    // Conditions for draw 
    if (pMove == cMove) {
        return 0;
    }

    // Conditions for win and loss according to game rule 
    if ((pMove == 's' && cMove == 'p') ||
        (pMove == 'p' && cMove == 'r') ||
        (pMove == 'r' && cMove == 's')) {
        return 1;
    }
    else {
        return -1;
    }
}

// Main function 
int main() {
    int pScore = 0, cScore = 0;
    char pMove;

    cout << "\n\n\n\t\t\tWelcome to Rock-Paper-Scissors Game\n";

    // Game loop
    while (true) {
        cout << "\n\t\tEnter 'r' for ROCK, 'p' for PAPER, 's' for SCISSORS, or 'q' to quit: ";
        cin >> pMove;

        if (pMove == 'q') {
            break; // Exit the loop if the player chooses to quit
        }
        else if (pMove != 'p' && pMove != 'r' && pMove != 's') {
            cout << "\t\t\tInvalid Player Move!!! Please Try Again.\n";
            continue; // Skip the rest of the loop and ask for input again
        }

        // Computer move 
        char cMove = getComputerMove();

        // Get game result
        int result = getResults(pMove, cMove);

        // Print result
        if (result == 0) {
            cout << "\n\t\t\tGame Draw!\n";
        }
        else if (result == 1) {
            cout << "\n\t\t\tCongratulations! Player won the game!\n";
            pScore++;
        }
        else {
            cout << "\n\t\t\tOh! Computer won the game!\n";
            cScore++;
        }

        // Show both moves 
        cout << "\t\t\tYour Move: " << pMove << endl;
        cout << "\t\t\tComputer's Move: " << cMove << endl;

        // Show current score
        cout << "\n\t\tCurrent Score: Player " << pScore << " - " << cScore << " Computer\n";
    }

    cout << "\n\t\t\tThanks for playing! Final Score: Player " << pScore << " - " << cScore << " Computer\n";

    return 0;
}
