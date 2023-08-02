//guessing game
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int minimum_number = 1;
    int maximum_number = 100;
    int attempts = 0;
    int points = 0;
    bool more_rounds = true;
    
    cout << "Hello, Welcome to Number Guessing Game!" << endl;
    
    while (more_rounds) {
        srand(static_cast<unsigned int>(time(0))); // unique set of random integers
        int true_target = rand() % (maximum_number - minimum_number + 1) + minimum_number;
        
        cout << "Guess the number between " << minimum_number << " and " << maximum_number << "." << endl;
        
        while (true) {
            int guess;
            cout << "Start: ";
            cin >> guess;
            
            attempts++;
            
            if (guess == true_target) {
                cout << "Correct guess, Congratulations!" << endl;
                points++;
                break;
            } else if (guess < true_target) {
                cout << "Low! Please try guessing a higher number." << endl;
            } else {
                cout << "High! Please try guessing a lower number." << endl;
            }
            
            if (attempts >= 10) {
                cout << "You have reached the maximum number of attempts." << endl;
                break;
            }
        }
        
        string play_again;
        cout << "Do you want to play again? (yes/no): ";
        cin >> play_again;
        
        // Convert the input to lowercase to handle various user inputs (Yes, YES, yes, y, etc.)
        for (char& c : play_again) {
            c = tolower(c);
        }
        
        // Check if the player wants to play again
        if (play_again == "no") {
            more_rounds = false;
        }
        else if (play_again != "yes") {
            cout << "Invalid input. Ending the game." << endl;
            more_rounds = false;
        }
        
        attempts = 0; // Reset attempts for the new round
    }
    
    cout << "Game over! Your points are " << points << "." << endl;
    
    return 0;
}
