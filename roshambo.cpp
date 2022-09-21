// Alessandro Sisniegas
// 03-04-22

#include <iostream>
#include <cstdlib>      // for rand() funct.
#include <ctime>        // for unique sequence in seed
#include <cctype>       // for char use

using namespace std;

int main() {
    // all integer variables
    int seed = 0;
    int roundNum = 1;
    int gamesWon = 0;
    int gamesLost = 0;
    int gamesTied = 0;
    int compPlay;

    // all character varviables
    char userPlay;
    char rock = toupper('r');
    char paper = toupper('p');
    char scissor = toupper('s');
    char userQuit = toupper('q');

// Start of the Game -- user will decide the randomized sequence of the game
    cerr << "Weclome to RoShamBo!" << endl;
    cerr << "Please enter a non-zero number, or 0 for dynamic mode: ";

// Part 1 - Dynamic or Static Mode -- time(0) will manipulate the time as the seed for different seqeuences each time played
    cin >> seed;

    if (seed == 0) {
        srand(time(0));                      // the current time(0) is used so the program will get a unique sequence each time
    } else {
        srand(seed);                         // having srand with seed will have a pseudo-random which will yield the same sequences
    }

// Part 2 - Round(s)
    cerr << "Round " << roundNum << endl;
    cerr << "Enter your choice (R for Rock, P for Paper, S for Scissors, or Q for Quit): ";
    cin >> userPlay;
    userPlay = toupper(userPlay);            // user will choose between r p s or quit as their play and it will be capitalized 
// Part 3 - Gameplay
    while (userPlay != userQuit) {           // while loop iterates as long as user does not quit
        
        compPlay = rand() % 3;               // computer will choose a random # between 0-2 because of modulo operator "%" with 3

        if (userPlay == rock) {              // 0 is assigned to rock, 1 to paper, 2 for scissor
            if (compPlay == 2) {             // first if statement executes if user chooses 'r', second statement if 'p', third if 's'
                cerr << "You Win!" << endl;
                gamesWon += 1;
            } else if (compPlay == 1) {      // based on the # the computer randomly chose, it'll assign it to either rock (0) paper (1) or scissor (3)
                cerr << "You Lose." << endl; // based on the computer play (compPlay), the if statement with the correct assignment will iterate
                gamesLost += 1;              // the outcome between the userPlay and compPlay will result in either win - loss - tie and will update each time the statement iterates
            } else {                     
                cerr << "Tie." << endl; 
                gamesTied += 1;
            }                                // # of rounds played is updated each time iterated unless, user quits or invalid choice

            roundNum += 1;                   // all of the above goes the same for the other two statements in the while loop

        } else if (userPlay == paper) {      
            if (compPlay == 0) {
                cerr << "You Win!" << endl;
                gamesWon += 1;
            } else if (compPlay == 2) {      
                cerr << "You Lose." << endl;
                gamesLost += 1;
            } else {
                cerr << "Tie." << endl;       
                gamesTied += 1;
            }
            
            roundNum += 1;

        } else if (userPlay == scissor) {    
            if (compPlay == 1) {
                cerr << "You Win!" << endl;
                gamesWon += 1;                    
            } else if (compPlay == 0) {      
                cerr << "You Lose." << endl;
                gamesLost += 1;
            } else {
                cerr << "Tie." << endl;  
                gamesTied += 1;              
            }
            
            roundNum += 1;                   

        } else {                             
            cerr << "Invlalid choice. Try again." << endl;
        }
    
        cerr << endl;                       

        cerr << "Round " << roundNum << endl;
        cerr << "Enter your choice (R for Rock, P for Paper, S for Scissors, or Q for Quit): ";
        cin >> userPlay;                      
        userPlay = toupper(userPlay);
    }

// Part 4 - Endgame
    cerr << "Thank you for playing" << endl; // end of game give's user stats based off rounds played, wins, losses, and ties
    cout << "You played " << roundNum - 1 << " round(s)." << endl; 
    cout << "Your stats are: " << gamesWon << "-" << gamesLost << "-" << gamesTied << endl;

    return 0;
}