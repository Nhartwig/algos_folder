
// Anthony Bisulco, Nathaniel Hartwig
// Fundamentals of Algorithms
// Project 1 MASTER MIND 1b
// Implementation of the Mastermind Class
// Mastermind class performs the actions for playing the game and allowing IO
// Contains functionality to play game for ten turns, then tells the user if won or lost
// Also, the game will print the secret code at the end to highlight how close you were to the guess.
// This feedback allows the user to improve their guess each time.
// Contains implementations for constructor with no arguments, 
// constructor for arguments with code length and digits,
// humanGuess, getResponse, isSolved and playGame.
#include "Code.hpp"
#include "response.h"
#include "mastermind.h"
#include <iostream>
#include <vector>
#include <climits>



// One of two constructors for the mastermind class.
// Creates the mastermind object and intializes the
// code length and digit length to their values n and m.
// Their values are assumed to be within range, above 0 and
// are supposed to be integers, ensured using the bound check function
// at the bottom of main.cpp
mastermind::mastermind(int nA,int mA)
{
    n=nA;
    m=mA;
}


// Default constructor for the mastermind class.
// Creates the mastermind object, intializes the
// code length and digit range to their default values n=5 and m=10.
// Values are assumed to be within range, above 0, and
// are supposed to be integers, ensured using bound check function. 
mastermind::mastermind()
{
    n=5;
    m=10;
}

// printSecretCode uses the functionality
// developed in the last code class to print
// the secret code using cout. 
// no arguments, and nothing returned, so 
// return type is void. 
void mastermind::printSecretCode()
{
    gameCode.printCode();
}

// humanGuess function takes in no parameters.
// This function returns a code object 
// containing the guess code, which should
// be initialized by parameters (n,m and secret code).
// This function ensures correct user io through the game. 
Code mastermind::humanGuess()
{
    std::string prompt="Guess";		// tell users that they are about to guess
    std::vector<int> code;			// vector to hold the guess code
    int temp;						// Temporary variable used to hold user input
    int sucess = 0;					// success is a flag for all valid input 

    while (!sucess)					// repeat this until sucessful user input
		{
        code.clear();				// If an input number is invalid, guess code cleared from past iterations
        int numLen = 0;				// counter for number of digits

		// Prompt user for input
        std::cout << "Enter numbers for the " << prompt << " sequence between 0 and " << m-1 << " seperated by spaces" << std::endl;
		
        for( int i = 0; i < n; i++) // For loop through the input digits
        {
            std::cin >> temp;		// Gets the digit in cin buffer
            if (std::cin.fail())	// Checks if this is not an integer
            {						
                std::cout << "NOT A NUMBER!" << std::endl; // if so print not an number
                std::cin.ignore(INT_MAX,'\n');			   // ignores error
                std::cin.clear();						   // clears the buffer for cin
                fflush(stdin);							   // flushes buffer for cin
                continue;								   // repeats prompt sequence used for inccorect input
            }
            else
            {
                if (temp < m && temp > -1)
                {											// Checks if digits are less than m and greater than -1
                    code.push_back(temp);					// pushes element onto vector
                    sucess = 1;								// sets sucess vector to 1
                    numLen += 1;							// increases length vector
                }
                else
                {	// tell user they put input an incorrect number range										
                    std::cout << "Input Range of Numbers Invalid Please Start Again" << std::endl;
                    std::cin.ignore(INT_MAX,'\n');			// ignores error
                    std::cin.clear();						// clears the buffer for cin
                    fflush(stdin);							// flushes buffer for cin
                    sucess = 0;								// unsucessful input
                    break;									// breaks and restarts
                }
            }
        } // end for loop

		// if number length and n are not same, user needs to re-input numbers
        if (numLen != n)
        {
            sucess = 0;														// sets sucess to 0
            std::cin.clear();												// clears the buffer for cin
            std::cin.ignore(INT_MAX,'\n');									// ignores error
            fflush(stdin);													// flushes buffer for cin
            std::cout << "Input length of numbers start again" << std::endl;// restart number input
        }
    }	// end of the encompassing while loop
    
    Code ret(n,m);		// Creates a Code object to be returned with values of n and m
    ret.setCode(code);	// Sets the code to the code that is contained in vector
    return ret;			// Returns this code object to user
    
}

// getResponse is a function that gets a guessCode as
// an input and is called on a gameCode which compares
// the guessCode and gameCode to see if correct or not
// returns a responese object which contains the values
// of incorrect and correct which is then returned using
// this function, guess code is assumed to be initialized with
// a sequenece vector along with the gameCode
response mastermind::getResponse(Code *guessCode)
{
    
    int cor=gameCode.checkCorrect(guessCode);	 // gets the correct values for gameCode compared to guessCode
    int inCor=gameCode.checkIncorrect(guessCode);// gets the incorrect values for gameCode compared to guessCode 
    response retCode(inCor,cor);				 // creates response object with parameters correct and incorrect
    return retCode;								 // returns the response object containing the response for this code
}


// isSolved is a function that compares the user response object
// that contains the correct and incorrect value for a
// guessCode/gameCode pair and then sees if the correct value is equal to
// the number of total digits. Thus, the code is solved. 
// Otherwise, the code is not solved.
bool mastermind::isSolved(response user_response)
{
    if(n==user_response.getCorrect())	// check is number of code digits is equal to correct digits
	{	
        return true;					// true if above is true
    }
	else
	{
        return false;					// false if nonequal number of digits and correct digits
    }
}

// playGame is a function with no args. 
// It is assumed that the mastermind object calling has a
// value of n and m, and this function also returns nothing.
// This function then plays the game, which creates a secret code,
// prints a secret code, and has the user enter a guess.
// Then, it checks this guess against secret code using getResponse
// to see if the puzzle was solved. If not solved, it iterates until
// turn limit is reached, and then win/loss message is displayed.
void mastermind::playGame()
{
    Code secretCode(n,m);					   // Creates a secret code object with values
    
    std::vector<int> sec=secretCode.getCode(); // gets the current secret code
    const int MAX_TURNS=10;					   // defines max turns in the game
    int turns=0;							   // defines number of turns in game
    gameCode.setCode(sec);					   // sets secretCode to the game code
    printSecretCode();						   // prints the secret code for users to see
    int win=0;								   // winner flag used to determine if the user has won the game
    while(win==0||MAX_TURNS==turns)			   // win flag is checked and if the maxturns has passed
    {
        Code guessCode=humanGuess();		   // gets the user guess code from keyboard
        response one=getResponse(&guessCode);  // checks guessCode against secretCode
        std::cout<<one;						   // prints out correct and incorrect responses
        if(isSolved(one))					   // checks if the puzzle has been solved
		{
            win=1;							   // sets the winning flag to win
        }
        turns=turns+1;						   // increments turns counter
    }
    if(win==1)								   // win flag
	{
    std::cout<<"YOU WIN"<<std::endl;		   // highlights the user has won
    }
	else
	{
    std::cout<<"YOU LOSE"<<std::endl;		   // highlights the user has lost
    }
}
